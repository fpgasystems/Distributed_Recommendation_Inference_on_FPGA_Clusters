/**********
Copyright (c) 2019, Xilinx, Inc.
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software
without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**********/
#include "xcl2.hpp"
#include <vector>
#include <chrono>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../kernel/common/include/constants.hpp"

#define DATA_SIZE 62500000

//Set IP address of FPGA
#define IP_ADDR 0x0A01D49F // 10.1.212.159
#define BOARD_NUMBER 9
#define ARP 0x0A01D49F

#define BANK_NAME(n) n | XCL_MEM_TOPOLOGY
/* for U280 specifically */
const int bank[40] = {
    /* 0 ~ 31 HBM */
    BANK_NAME(0),  BANK_NAME(1),  BANK_NAME(2),  BANK_NAME(3),  BANK_NAME(4),
    BANK_NAME(5),  BANK_NAME(6),  BANK_NAME(7),  BANK_NAME(8),  BANK_NAME(9),
    BANK_NAME(10), BANK_NAME(11), BANK_NAME(12), BANK_NAME(13), BANK_NAME(14),
    BANK_NAME(15), BANK_NAME(16), BANK_NAME(17), BANK_NAME(18), BANK_NAME(19),
    BANK_NAME(20), BANK_NAME(21), BANK_NAME(22), BANK_NAME(23), BANK_NAME(24),
    BANK_NAME(25), BANK_NAME(26), BANK_NAME(27), BANK_NAME(28), BANK_NAME(29),
    BANK_NAME(30), BANK_NAME(31), 
    /* 32, 33 DDR */ 
    BANK_NAME(32), BANK_NAME(33), 
    /* 34 ~ 39 PLRAM */ 
    BANK_NAME(34), BANK_NAME(35), BANK_NAME(36), BANK_NAME(37), 
    BANK_NAME(38), BANK_NAME(39)};

void wait_for_enter(const std::string &msg) {
    std::cout << msg << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <XCLBIN File> [<#RxByte> <Port>]" << std::endl;
        return EXIT_FAILURE;
    }

    std::string binaryFile = argv[1];

    cl_int err;
    cl::CommandQueue q;
    cl::Context context;

    cl::Kernel user_kernel;
    cl::Kernel network_kernel;

    auto size = DATA_SIZE;
    
    //Allocate Memory in Host Memory
    auto vector_size_bytes = sizeof(int) * size;
    std::vector<int, aligned_allocator<int>> network_ptr0(size);
    std::vector<int, aligned_allocator<int>> network_ptr1(size);


    //OPENCL HOST CODE AREA START
    //Create Program and Kernel
    auto devices = xcl::get_xil_devices();

    // read_binary_file() is a utility API which will load the binaryFile
    // and will return the pointer to file buffer.
    auto fileBuf = xcl::read_binary_file(binaryFile);
    cl::Program::Binaries bins{{fileBuf.data(), fileBuf.size()}};
    int valid_device = 0;
    for (unsigned int i = 0; i < devices.size(); i++) {
        auto device = devices[i];
        // Creating Context and Command Queue for selected Device
        OCL_CHECK(err, context = cl::Context({device}, NULL, NULL, NULL, &err));
        OCL_CHECK(err,
                  q = cl::CommandQueue(
                      context, {device}, CL_QUEUE_PROFILING_ENABLE, &err));

        std::cout << "Trying to program device[" << i
                  << "]: " << device.getInfo<CL_DEVICE_NAME>() << std::endl;
                  cl::Program program(context, {device}, bins, NULL, &err);
        if (err != CL_SUCCESS) {
            std::cout << "Failed to program device[" << i
                      << "] with xclbin file!\n";
        } else {
            std::cout << "Device[" << i << "]: program successful!\n";
            OCL_CHECK(err,
                      network_kernel = cl::Kernel(program, "network_krnl", &err));
            OCL_CHECK(err,
                      user_kernel = cl::Kernel(program, "hls_bil_krnl", &err));
            valid_device++;
            break; // we break because we found a valid device
        }
    }
    if (valid_device == 0) {
        std::cout << "Failed to program any device found, exit!\n";
        exit(EXIT_FAILURE);
    }
    
    std::cout << "IP Address is 10.1.212.159" << std::endl;
    //std::cout << "Board number: 1" << std::endl;
    wait_for_enter("\nPress ENTER to continue after setting up ILA trigger...");


    // Set network kernel arguments
    OCL_CHECK(err, err = network_kernel.setArg(0, IP_ADDR)); // Default IP address
    OCL_CHECK(err, err = network_kernel.setArg(1, BOARD_NUMBER)); // Board number
    OCL_CHECK(err, err = network_kernel.setArg(2, ARP)); // ARP lookup

    OCL_CHECK(err,
              cl::Buffer buffer_r1(context,
                                   CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE,
                                   vector_size_bytes,
                                   network_ptr0.data(),
                                   &err));
    OCL_CHECK(err,
            cl::Buffer buffer_r2(context,
                                CL_MEM_USE_HOST_PTR | CL_MEM_READ_WRITE,
                                vector_size_bytes,
                                network_ptr1.data(),
                                &err));

    OCL_CHECK(err, err = network_kernel.setArg(3, buffer_r1));
    OCL_CHECK(err, err = network_kernel.setArg(4, buffer_r2));

    printf("enqueue network kernel...\n");
    OCL_CHECK(err, err = q.enqueueTask(network_kernel));
    OCL_CHECK(err, err = q.finish());
    
    // Set parameters for receiving data
    uint32_t connection_recv = 2;
    uint32_t basePort_recv_1 = 5003; 
    uint32_t basePort_recv_2 = 5004; 
    //uint32_t rxPkt = 32;
    
    // Set parameters for sending data
    uint32_t numPacketWord_send = 16;
    uint32_t connection_send = 1;
    uint32_t baseIpAddr_send = 0x0A01D46E;//node_1: 10.1.212.110
    // uint32_t baseIpAddr = 0x0A01D481; //alveo4b
    uint32_t basePort_send = 5004; 
    //uint32_t txPkt = 32;

    //uint32_t rxPkt = BATCH_NUM * BATCH_SIZE * 5;
    // 1 from node bil_1, 2 from node bil_3
    uint32_t rxPkt_1 = 3;
    uint32_t rxPkt_2 = BATCH_NUM * BATCH_SIZE * 32 / 16;
    // I want to send 2 times packets to help determine the latency of each packet
    uint32_t txPkt = BATCH_NUM * BATCH_SIZE * 32 / 16;
    uint32_t index = 0;


    if(argc >= 3)
        basePort_recv_1 = strtol(argv[2], NULL, 10);

    if(argc >= 4)
        basePort_recv_2 = strtol(argv[3], NULL, 10);

    if (argc >= 5)
    {
        std::string s = argv[4];
        std::string delimiter = ".";
        int ip [4];
        size_t pos = 0;
        std::string token;
        int i = 0;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            ip [i] = stoi(token);
            s.erase(0, pos + delimiter.length());
            i++;
        }
        ip[i] = stoi(s); 
        baseIpAddr_send = ip[3] | (ip[2] << 8) | (ip[1] << 16) | (ip[0] << 24);
    }

    if (argc >= 6)
    {
        basePort_send = strtol(argv[5], NULL, 10);
    }

     if (argc >= 7)
    {
        index = strtol(argv[6], NULL, 10);
    }

    double durationUs = 0.0;

////////////////////////////////////////////////////////////////////////////////////
// Write results back to host 
    //int size_results_out = BATCH_SIZE * OUTPUT_SIZE; 
    //std::vector<D_TYPE,aligned_allocator<D_TYPE>> source_hw_results(size_results_out);
    //cl_mem_ext_ptr_t sourcce_hw_resultsExt;
/////
    //sourcce_hw_resultsExt.obj = source_hw_results.data();
    //sourcce_hw_resultsExt.param = 0;
    //sourcce_hw_resultsExt.flags = bank[34];
/////
    //OCL_CHECK(err, cl::Buffer buffer_output(
    //    context, CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY | CL_MEM_EXT_PTR_XILINX, 
    //    size_results_out *sizeof(int), &sourcce_hw_resultsExt, &err));
////////////////////////////////////////////////////////////////////////////////////

    //Set user Kernel Arguments
    //Set user Kernel Arguments
    //Set user Kernel Arguments for receiving data
    OCL_CHECK(err, err = user_kernel.setArg(16, connection_recv));
    OCL_CHECK(err, err = user_kernel.setArg(17, basePort_recv_1));
    OCL_CHECK(err, err = user_kernel.setArg(18, rxPkt_1));
    OCL_CHECK(err, err = user_kernel.setArg(19, basePort_recv_2));
    OCL_CHECK(err, err = user_kernel.setArg(20, rxPkt_2));
    //Set user Kernel Arguments for sending data
    OCL_CHECK(err, err = user_kernel.setArg(21, connection_send));
    OCL_CHECK(err, err = user_kernel.setArg(22, numPacketWord_send));
    OCL_CHECK(err, err = user_kernel.setArg(23, basePort_send));
    OCL_CHECK(err, err = user_kernel.setArg(24, txPkt));
    OCL_CHECK(err, err = user_kernel.setArg(25, baseIpAddr_send));

    OCL_CHECK(err, err = user_kernel.setArg(26, index));
    //OCL_CHECK(err, err = user_kernel.setArg(19, buffer_output));

/////////////////////////////////////////////////////////////////////

   // OCL_CHECK(err, err = user_kernel.setArg(19, buffer_output));

/////////////////////////////////////////////////////////////////////

    //Launch the Kernel
    auto start = std::chrono::high_resolution_clock::now();
    printf("enqueue user kernel...\n");
    OCL_CHECK(err, err = q.enqueueTask(user_kernel));

/////////////////////////////////////////////////////////////////////

    //OCL_CHECK(err, err = q.enqueueMigrateMemObjects({buffer_output},CL_MIGRATE_MEM_OBJECT_HOST));

/////////////////////////////////////////////////////////////////////

    OCL_CHECK(err, err = q.finish());

/////////////////////////////////////////////////////////////////////
// print results

   //for (int i = 0 ; i < OUTPUT_SIZE * BATCH_SIZE; i++) {
////
   //    std::cout << "i = " << i << " Device result = " << source_hw_results[i] << std::endl;
   //}


/////////////////////////////////////////////////////////////////////

    auto end = std::chrono::high_resolution_clock::now();
    durationUs = (std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count() / 1000.0);
    printf("durationUs:%f\n",durationUs);
    //OPENCL HOST CODE AREA END    

    std::cout << "EXIT recorded" << std::endl;
}
