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
#define IP_ADDR 0x0A01D49C // 10.1.212.156
#define BOARD_NUMBER 6
#define ARP 0x0A01D49C

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
        std::cout << "Usage: " << argv[0] << " <XCLBIN File> [<#Tx Pkt> <IP address in format: 10.1.212.121> <Port>]" << std::endl;
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

/////////////////////////////////// Allocate data for HBM and DDR ///////////////////////////////
    size_t HBM_embedding0_size =  HBM_BANK0_SIZE;
    size_t HBM_embedding1_size =  HBM_BANK1_SIZE;
    size_t HBM_embedding2_size =  HBM_BANK2_SIZE;
    size_t HBM_embedding3_size =  HBM_BANK3_SIZE;
    size_t HBM_embedding4_size =  HBM_BANK4_SIZE;
    size_t HBM_embedding5_size =  HBM_BANK5_SIZE;
    size_t HBM_embedding6_size =  HBM_BANK6_SIZE;
    size_t HBM_embedding7_size =  HBM_BANK7_SIZE;
    size_t HBM_embedding8_size =  HBM_BANK8_SIZE;
    size_t HBM_embedding9_size =  HBM_BANK9_SIZE;
    size_t HBM_embedding10_size =  HBM_BANK10_SIZE;
    size_t HBM_embedding11_size =  HBM_BANK11_SIZE;
    size_t HBM_embedding12_size =  HBM_BANK12_SIZE;
    size_t HBM_embedding13_size =  HBM_BANK13_SIZE;
    size_t HBM_embedding14_size =  HBM_BANK14_SIZE;
    size_t HBM_embedding15_size =  HBM_BANK15_SIZE;
    size_t HBM_embedding16_size =  HBM_BANK16_SIZE;
    size_t HBM_embedding17_size =  HBM_BANK17_SIZE;
    size_t HBM_embedding18_size =  HBM_BANK18_SIZE;
    size_t HBM_embedding19_size =  HBM_BANK19_SIZE;
    size_t HBM_embedding20_size =  HBM_BANK20_SIZE;
    size_t HBM_embedding21_size =  HBM_BANK21_SIZE;
    size_t HBM_embedding22_size =  HBM_BANK22_SIZE;
    size_t HBM_embedding23_size =  HBM_BANK23_SIZE;
    size_t HBM_embedding24_size =  HBM_BANK24_SIZE;
    size_t HBM_embedding25_size =  HBM_BANK25_SIZE;
    size_t HBM_embedding26_size =  HBM_BANK26_SIZE;
    size_t HBM_embedding27_size =  HBM_BANK27_SIZE;

    // allocate aligned 2D vectors
    std::vector<int, aligned_allocator<int>> HBM_embedding0(HBM_embedding0_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding1(HBM_embedding1_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding2(HBM_embedding2_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding3(HBM_embedding3_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding4(HBM_embedding4_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding5(HBM_embedding5_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding6(HBM_embedding6_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding7(HBM_embedding7_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding8(HBM_embedding8_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding9(HBM_embedding9_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding10(HBM_embedding10_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding11(HBM_embedding11_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding12(HBM_embedding12_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding13(HBM_embedding13_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding14(HBM_embedding14_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding15(HBM_embedding15_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding16(HBM_embedding16_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding17(HBM_embedding17_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding18(HBM_embedding18_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding19(HBM_embedding19_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding20(HBM_embedding20_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding21(HBM_embedding21_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding22(HBM_embedding22_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding23(HBM_embedding23_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding24(HBM_embedding24_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding25(HBM_embedding25_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding26(HBM_embedding26_size, 1);
    std::vector<int, aligned_allocator<int>> HBM_embedding27(HBM_embedding27_size, 1);

    // generate embedding table
    std::cout << "Generating table contents..." << std::endl;
    std::cout << "HBM Round 0..." << std::endl;

    // HBM, DDR random <--> PLRAM host device same generation pattern
    // Round 0
#define DEBUG
#ifdef DEBUG
    const int weights_init = 1;
#endif
    for (int i = 0 ; i < TABLE_SIZE_HBM_0 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_0; j++) {
#ifdef DEBUG
        HBM_embedding0[i * PADDED_SIZE_HBM_0 + j + ADDR_AXI_HBM_0] = weights_init;
#else
        HBM_embedding0[i * PADDED_SIZE_HBM_0 + j + ADDR_AXI_HBM_0] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_1 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_1; j++) {
#ifdef DEBUG
        HBM_embedding1[i * PADDED_SIZE_HBM_1 + j + ADDR_AXI_HBM_1] = weights_init;
#else
        HBM_embedding1[i * PADDED_SIZE_HBM_1 + j + ADDR_AXI_HBM_1] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_2 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_2; j++) {
#ifdef DEBUG
        HBM_embedding2[i * PADDED_SIZE_HBM_2 + j + ADDR_AXI_HBM_2] = weights_init;
#else
        HBM_embedding2[i * PADDED_SIZE_HBM_2 + j + ADDR_AXI_HBM_2] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_3 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_3; j++) {
#ifdef DEBUG
        HBM_embedding3[i * PADDED_SIZE_HBM_3 + j + ADDR_AXI_HBM_3] = weights_init;
#else
        HBM_embedding3[i * PADDED_SIZE_HBM_3 + j + ADDR_AXI_HBM_3] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_4 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_4; j++) {
#ifdef DEBUG
        HBM_embedding4[i * PADDED_SIZE_HBM_4 + j + ADDR_AXI_HBM_4] = weights_init;
#else
        HBM_embedding4[i * PADDED_SIZE_HBM_4 + j + ADDR_AXI_HBM_4] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_5 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_5; j++) {
#ifdef DEBUG
        HBM_embedding5[i * PADDED_SIZE_HBM_5 + j + ADDR_AXI_HBM_5] = weights_init;
#else
        HBM_embedding5[i * PADDED_SIZE_HBM_5 + j + ADDR_AXI_HBM_5] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_6 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_6; j++) {
#ifdef DEBUG
        HBM_embedding6[i * PADDED_SIZE_HBM_6 + j + ADDR_AXI_HBM_6] = weights_init;
#else
        HBM_embedding6[i * PADDED_SIZE_HBM_6 + j + ADDR_AXI_HBM_6] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_7 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_7; j++) {
#ifdef DEBUG
        HBM_embedding7[i * PADDED_SIZE_HBM_7 + j + ADDR_AXI_HBM_7] = weights_init;
#else
        HBM_embedding7[i * PADDED_SIZE_HBM_7 + j + ADDR_AXI_HBM_7] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_8 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_8; j++) {
#ifdef DEBUG
        HBM_embedding8[i * PADDED_SIZE_HBM_8 + j + ADDR_AXI_HBM_8] = weights_init;
#else
        HBM_embedding8[i * PADDED_SIZE_HBM_8 + j + ADDR_AXI_HBM_8] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_9 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_9; j++) {
#ifdef DEBUG
        HBM_embedding9[i * PADDED_SIZE_HBM_9 + j + ADDR_AXI_HBM_9] = weights_init;
#else
        HBM_embedding9[i * PADDED_SIZE_HBM_9 + j + ADDR_AXI_HBM_9] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_10 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_10; j++) {
#ifdef DEBUG
        HBM_embedding10[i * PADDED_SIZE_HBM_10 + j + ADDR_AXI_HBM_10] = weights_init;
#else
        HBM_embedding10[i * PADDED_SIZE_HBM_10 + j + ADDR_AXI_HBM_10] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_11 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_11; j++) {
#ifdef DEBUG
        HBM_embedding11[i * PADDED_SIZE_HBM_11 + j + ADDR_AXI_HBM_11] = weights_init;
#else
        HBM_embedding11[i * PADDED_SIZE_HBM_11 + j + ADDR_AXI_HBM_11] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_12 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_12; j++) {
#ifdef DEBUG
        HBM_embedding12[i * PADDED_SIZE_HBM_12 + j + ADDR_AXI_HBM_12] = weights_init;
#else
        HBM_embedding12[i * PADDED_SIZE_HBM_12 + j + ADDR_AXI_HBM_12] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_13 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_13; j++) {
#ifdef DEBUG
        HBM_embedding13[i * PADDED_SIZE_HBM_13 + j + ADDR_AXI_HBM_13] = weights_init;
#else
        HBM_embedding13[i * PADDED_SIZE_HBM_13 + j + ADDR_AXI_HBM_13] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_14 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_14; j++) {
#ifdef DEBUG
        HBM_embedding14[i * PADDED_SIZE_HBM_14 + j + ADDR_AXI_HBM_14] = weights_init;
#else
        HBM_embedding14[i * PADDED_SIZE_HBM_14 + j + ADDR_AXI_HBM_14] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_15 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_15; j++) {
#ifdef DEBUG
        HBM_embedding15[i * PADDED_SIZE_HBM_15 + j + ADDR_AXI_HBM_15] = weights_init;
#else
        HBM_embedding15[i * PADDED_SIZE_HBM_15 + j + ADDR_AXI_HBM_15] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_16 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_16; j++) {
#ifdef DEBUG
        HBM_embedding16[i * PADDED_SIZE_HBM_16 + j + ADDR_AXI_HBM_16] = weights_init;
#else
        HBM_embedding16[i * PADDED_SIZE_HBM_16 + j + ADDR_AXI_HBM_16] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_17 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_17; j++) {
#ifdef DEBUG
        HBM_embedding17[i * PADDED_SIZE_HBM_17 + j + ADDR_AXI_HBM_17] = weights_init;
#else
        HBM_embedding17[i * PADDED_SIZE_HBM_17 + j + ADDR_AXI_HBM_17] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_18 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_18; j++) {
#ifdef DEBUG
        HBM_embedding18[i * PADDED_SIZE_HBM_18 + j + ADDR_AXI_HBM_18] = weights_init;
#else
        HBM_embedding18[i * PADDED_SIZE_HBM_18 + j + ADDR_AXI_HBM_18] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_19 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_19; j++) {
#ifdef DEBUG
        HBM_embedding19[i * PADDED_SIZE_HBM_19 + j + ADDR_AXI_HBM_19] = weights_init;
#else
        HBM_embedding19[i * PADDED_SIZE_HBM_19 + j + ADDR_AXI_HBM_19] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_20 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_20; j++) {
#ifdef DEBUG
        HBM_embedding20[i * PADDED_SIZE_HBM_20 + j + ADDR_AXI_HBM_20] = weights_init;
#else
        HBM_embedding20[i * PADDED_SIZE_HBM_20 + j + ADDR_AXI_HBM_20] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_21 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_21; j++) {
#ifdef DEBUG
        HBM_embedding21[i * PADDED_SIZE_HBM_21 + j + ADDR_AXI_HBM_21] = weights_init;
#else
        HBM_embedding21[i * PADDED_SIZE_HBM_21 + j + ADDR_AXI_HBM_21] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_22 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_22; j++) {
#ifdef DEBUG
        HBM_embedding22[i * PADDED_SIZE_HBM_22 + j + ADDR_AXI_HBM_22] = weights_init;
#else
        HBM_embedding22[i * PADDED_SIZE_HBM_22 + j + ADDR_AXI_HBM_22] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_23 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_23; j++) {
#ifdef DEBUG
        HBM_embedding23[i * PADDED_SIZE_HBM_23 + j + ADDR_AXI_HBM_23] = weights_init;
#else
        HBM_embedding23[i * PADDED_SIZE_HBM_23 + j + ADDR_AXI_HBM_23] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_24 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_24; j++) {
#ifdef DEBUG
        HBM_embedding24[i * PADDED_SIZE_HBM_24 + j + ADDR_AXI_HBM_24] = weights_init;
#else
        HBM_embedding24[i * PADDED_SIZE_HBM_24 + j + ADDR_AXI_HBM_24] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_25 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_25; j++) {
#ifdef DEBUG
        HBM_embedding25[i * PADDED_SIZE_HBM_25 + j + ADDR_AXI_HBM_25] = weights_init;
#else
        HBM_embedding25[i * PADDED_SIZE_HBM_25 + j + ADDR_AXI_HBM_25] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_26 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_26; j++) {
#ifdef DEBUG
        HBM_embedding26[i * PADDED_SIZE_HBM_26 + j + ADDR_AXI_HBM_26] = weights_init;
#else
        HBM_embedding26[i * PADDED_SIZE_HBM_26 + j + ADDR_AXI_HBM_26] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_27 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_27; j++) {
#ifdef DEBUG
        HBM_embedding27[i * PADDED_SIZE_HBM_27 + j + ADDR_AXI_HBM_27] = weights_init;
#else
        HBM_embedding27[i * PADDED_SIZE_HBM_27 + j + ADDR_AXI_HBM_27] = rand() % 2;
#endif
        }
    }

    // Round 1
    for (int i = 0 ; i < TABLE_SIZE_HBM_32 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_32; j++) {
#ifdef DEBUG
        HBM_embedding0[i * PADDED_SIZE_HBM_32 + j + ADDR_AXI_HBM_32] = weights_init;
#else
        HBM_embedding0[i * PADDED_SIZE_HBM_32 + j + ADDR_AXI_HBM_32] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_33 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_33; j++) {
#ifdef DEBUG
        HBM_embedding1[i * PADDED_SIZE_HBM_33 + j + ADDR_AXI_HBM_33] = weights_init;
#else
        HBM_embedding1[i * PADDED_SIZE_HBM_33 + j + ADDR_AXI_HBM_33] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_34 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_34; j++) {
#ifdef DEBUG
        HBM_embedding2[i * PADDED_SIZE_HBM_34 + j + ADDR_AXI_HBM_34] = weights_init;
#else
        HBM_embedding2[i * PADDED_SIZE_HBM_34 + j + ADDR_AXI_HBM_34] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_35 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_35; j++) {
#ifdef DEBUG
        HBM_embedding3[i * PADDED_SIZE_HBM_35 + j + ADDR_AXI_HBM_35] = weights_init;
#else
        HBM_embedding3[i * PADDED_SIZE_HBM_35 + j + ADDR_AXI_HBM_35] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_36 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_36; j++) {
#ifdef DEBUG
        HBM_embedding4[i * PADDED_SIZE_HBM_36 + j + ADDR_AXI_HBM_36] = weights_init;
#else
        HBM_embedding4[i * PADDED_SIZE_HBM_36 + j + ADDR_AXI_HBM_36] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_37 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_37; j++) {
#ifdef DEBUG
        HBM_embedding5[i * PADDED_SIZE_HBM_37 + j + ADDR_AXI_HBM_37] = weights_init;
#else
        HBM_embedding5[i * PADDED_SIZE_HBM_37 + j + ADDR_AXI_HBM_37] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_38 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_38; j++) {
#ifdef DEBUG
        HBM_embedding6[i * PADDED_SIZE_HBM_38 + j + ADDR_AXI_HBM_38] = weights_init;
#else
        HBM_embedding6[i * PADDED_SIZE_HBM_38 + j + ADDR_AXI_HBM_38] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_39 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_39; j++) {
#ifdef DEBUG
        HBM_embedding7[i * PADDED_SIZE_HBM_39 + j + ADDR_AXI_HBM_39] = weights_init;
#else
        HBM_embedding7[i * PADDED_SIZE_HBM_39 + j + ADDR_AXI_HBM_39] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_40 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_40; j++) {
#ifdef DEBUG
        HBM_embedding8[i * PADDED_SIZE_HBM_40 + j + ADDR_AXI_HBM_40] = weights_init;
#else
        HBM_embedding8[i * PADDED_SIZE_HBM_40 + j + ADDR_AXI_HBM_40] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_41 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_41; j++) {
#ifdef DEBUG
        HBM_embedding9[i * PADDED_SIZE_HBM_41 + j + ADDR_AXI_HBM_41] = weights_init;
#else
        HBM_embedding9[i * PADDED_SIZE_HBM_41 + j + ADDR_AXI_HBM_41] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_42 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_42; j++) {
#ifdef DEBUG
        HBM_embedding10[i * PADDED_SIZE_HBM_42 + j + ADDR_AXI_HBM_42] = weights_init;
#else
        HBM_embedding10[i * PADDED_SIZE_HBM_42 + j + ADDR_AXI_HBM_42] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_43 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_43; j++) {
#ifdef DEBUG
        HBM_embedding11[i * PADDED_SIZE_HBM_43 + j + ADDR_AXI_HBM_43] = weights_init;
#else
        HBM_embedding11[i * PADDED_SIZE_HBM_43 + j + ADDR_AXI_HBM_43] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_44 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_44; j++) {
#ifdef DEBUG
        HBM_embedding12[i * PADDED_SIZE_HBM_44 + j + ADDR_AXI_HBM_44] = weights_init;
#else
        HBM_embedding12[i * PADDED_SIZE_HBM_44 + j + ADDR_AXI_HBM_44] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_45 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_45; j++) {
#ifdef DEBUG
        HBM_embedding13[i * PADDED_SIZE_HBM_45 + j + ADDR_AXI_HBM_45] = weights_init;
#else
        HBM_embedding13[i * PADDED_SIZE_HBM_45 + j + ADDR_AXI_HBM_45] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_46 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_46; j++) {
#ifdef DEBUG
        HBM_embedding14[i * PADDED_SIZE_HBM_46 + j + ADDR_AXI_HBM_46] = weights_init;
#else
        HBM_embedding14[i * PADDED_SIZE_HBM_46 + j + ADDR_AXI_HBM_46] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_47 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_47; j++) {
#ifdef DEBUG
        HBM_embedding15[i * PADDED_SIZE_HBM_47 + j + ADDR_AXI_HBM_47] = weights_init;
#else
        HBM_embedding15[i * PADDED_SIZE_HBM_47 + j + ADDR_AXI_HBM_47] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_48 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_48; j++) {
#ifdef DEBUG
        HBM_embedding16[i * PADDED_SIZE_HBM_48 + j + ADDR_AXI_HBM_48] = weights_init;
#else
        HBM_embedding16[i * PADDED_SIZE_HBM_48 + j + ADDR_AXI_HBM_48] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_49 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_49; j++) {
#ifdef DEBUG
        HBM_embedding17[i * PADDED_SIZE_HBM_49 + j + ADDR_AXI_HBM_49] = weights_init;
#else
        HBM_embedding17[i * PADDED_SIZE_HBM_49 + j + ADDR_AXI_HBM_49] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_50 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_50; j++) {
#ifdef DEBUG
        HBM_embedding18[i * PADDED_SIZE_HBM_50 + j + ADDR_AXI_HBM_50] = weights_init;
#else
        HBM_embedding18[i * PADDED_SIZE_HBM_50 + j + ADDR_AXI_HBM_50] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_51 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_51; j++) {
#ifdef DEBUG
        HBM_embedding19[i * PADDED_SIZE_HBM_51 + j + ADDR_AXI_HBM_51] = weights_init;
#else
        HBM_embedding19[i * PADDED_SIZE_HBM_51 + j + ADDR_AXI_HBM_51] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_52 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_52; j++) {
#ifdef DEBUG
        HBM_embedding20[i * PADDED_SIZE_HBM_52 + j + ADDR_AXI_HBM_52] = weights_init;
#else
        HBM_embedding20[i * PADDED_SIZE_HBM_52 + j + ADDR_AXI_HBM_52] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_53 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_53; j++) {
#ifdef DEBUG
        HBM_embedding21[i * PADDED_SIZE_HBM_53 + j + ADDR_AXI_HBM_53] = weights_init;
#else
        HBM_embedding21[i * PADDED_SIZE_HBM_53 + j + ADDR_AXI_HBM_53] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_54 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_54; j++) {
#ifdef DEBUG
        HBM_embedding22[i * PADDED_SIZE_HBM_54 + j + ADDR_AXI_HBM_54] = weights_init;
#else
        HBM_embedding22[i * PADDED_SIZE_HBM_54 + j + ADDR_AXI_HBM_54] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_55 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_55; j++) {
#ifdef DEBUG
        HBM_embedding23[i * PADDED_SIZE_HBM_55 + j + ADDR_AXI_HBM_55] = weights_init;
#else
        HBM_embedding23[i * PADDED_SIZE_HBM_55 + j + ADDR_AXI_HBM_55] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_56 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_56; j++) {
#ifdef DEBUG
        HBM_embedding24[i * PADDED_SIZE_HBM_56 + j + ADDR_AXI_HBM_56] = weights_init;
#else
        HBM_embedding24[i * PADDED_SIZE_HBM_56 + j + ADDR_AXI_HBM_56] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_57 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_57; j++) {
#ifdef DEBUG
        HBM_embedding25[i * PADDED_SIZE_HBM_57 + j + ADDR_AXI_HBM_57] = weights_init;
#else
        HBM_embedding25[i * PADDED_SIZE_HBM_57 + j + ADDR_AXI_HBM_57] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_58 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_58; j++) {
#ifdef DEBUG
        HBM_embedding26[i * PADDED_SIZE_HBM_58 + j + ADDR_AXI_HBM_58] = weights_init;
#else
        HBM_embedding26[i * PADDED_SIZE_HBM_58 + j + ADDR_AXI_HBM_58] = rand() % 2;
#endif
        }
    }
    for (int i = 0 ; i < TABLE_SIZE_HBM_59 ; i++) {
        for (int j = 0; j < DATA_SIZE_HBM_59; j++) {
#ifdef DEBUG
        HBM_embedding27[i * PADDED_SIZE_HBM_59 + j + ADDR_AXI_HBM_59] = weights_init;
#else
        HBM_embedding27[i * PADDED_SIZE_HBM_59 + j + ADDR_AXI_HBM_59] = rand() % 2;
#endif
        }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////

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
    
    std::cout << "IP address of current FPGA is: 10.1.212.156\n";
    //std::cout << "Board number: 2" << std::endl;
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
    uint32_t connection_recv = 1;
    uint32_t basePort_recv = 5003; 
    //uint32_t rxPkt = 32;
    
    // Set parameters for sending data
    uint32_t numPacketWord_send = 48;
    uint32_t connection_send = 2;
    // 1 for node 4, 2 for node 2
    uint32_t baseIpAddr_send_1 = 0x0A01D46E;//alveo0: 10.1.212.110
    uint32_t baseIpAddr_send_2 = 0x0A01D46E;//alveo0: 10.1.212.110
    // uint32_t baseIpAddr = 0x0A01D481; //alveo4b
    uint32_t basePort_send_1 = 5004; 
    uint32_t basePort_send_2 = 5004; 
    //uint32_t txPkt = 32;

    uint32_t rxPkt = BATCH_NUM * BATCH_SIZE * 32 / 16;
    uint32_t txPkt_1 = 1;
    uint32_t txPkt_2 = BATCH_NUM * BATCH_SIZE * 96 / 48;

    if(argc >= 3)
        basePort_recv = strtol(argv[2], NULL, 10);

    if (argc >= 4)
    {
        std::string s = argv[3];
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
        baseIpAddr_send_1 = ip[3] | (ip[2] << 8) | (ip[1] << 16) | (ip[0] << 24);
    }

    if (argc >= 5)
    {
        basePort_send_1 = strtol(argv[4], NULL, 10);
    }

    if (argc >= 6)
    {
        std::string s = argv[5];
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
        baseIpAddr_send_2 = ip[3] | (ip[2] << 8) | (ip[1] << 16) | (ip[0] << 24);
    }

    if (argc >= 7)
    {
        basePort_send_2 = strtol(argv[6], NULL, 10);
    }

    //printf("txPkt_1:%d, IP:%x, port:%d\n", txPkt_1, baseIpAddr, basePort);

    double durationUs = 0.0;

/////////////////////////////////////// Allocate Global Memory for User Kernel //////////////////////////////////
    cl_mem_ext_ptr_t HBM_embedding0Ext, HBM_embedding1Ext, HBM_embedding2Ext, HBM_embedding3Ext, 
        HBM_embedding4Ext, HBM_embedding5Ext, HBM_embedding6Ext, HBM_embedding7Ext, 
        HBM_embedding8Ext, HBM_embedding9Ext, HBM_embedding10Ext, HBM_embedding11Ext, 
        HBM_embedding12Ext, HBM_embedding13Ext, HBM_embedding14Ext, HBM_embedding15Ext, 
        HBM_embedding16Ext, HBM_embedding17Ext, HBM_embedding18Ext, HBM_embedding19Ext, 
        HBM_embedding20Ext, HBM_embedding21Ext, HBM_embedding22Ext, HBM_embedding23Ext, 
        HBM_embedding24Ext, HBM_embedding25Ext, HBM_embedding26Ext, HBM_embedding27Ext;

    HBM_embedding0Ext.obj = HBM_embedding0.data();
    HBM_embedding0Ext.param = 0;
    HBM_embedding0Ext.flags = bank[0];
    HBM_embedding1Ext.obj = HBM_embedding1.data();
    HBM_embedding1Ext.param = 0;
    HBM_embedding1Ext.flags = bank[1];
    HBM_embedding2Ext.obj = HBM_embedding2.data();
    HBM_embedding2Ext.param = 0;
    HBM_embedding2Ext.flags = bank[2];
    HBM_embedding3Ext.obj = HBM_embedding3.data();
    HBM_embedding3Ext.param = 0;
    HBM_embedding3Ext.flags = bank[3];
    HBM_embedding4Ext.obj = HBM_embedding4.data();
    HBM_embedding4Ext.param = 0;
    HBM_embedding4Ext.flags = bank[4];
    HBM_embedding5Ext.obj = HBM_embedding5.data();
    HBM_embedding5Ext.param = 0;
    HBM_embedding5Ext.flags = bank[5];
    HBM_embedding6Ext.obj = HBM_embedding6.data();
    HBM_embedding6Ext.param = 0;
    HBM_embedding6Ext.flags = bank[6];
    HBM_embedding7Ext.obj = HBM_embedding7.data();
    HBM_embedding7Ext.param = 0;
    HBM_embedding7Ext.flags = bank[7];
    HBM_embedding8Ext.obj = HBM_embedding8.data();
    HBM_embedding8Ext.param = 0;
    HBM_embedding8Ext.flags = bank[8];
    HBM_embedding9Ext.obj = HBM_embedding9.data();
    HBM_embedding9Ext.param = 0;
    HBM_embedding9Ext.flags = bank[9];
    HBM_embedding10Ext.obj = HBM_embedding10.data();
    HBM_embedding10Ext.param = 0;
    HBM_embedding10Ext.flags = bank[10];
    HBM_embedding11Ext.obj = HBM_embedding11.data();
    HBM_embedding11Ext.param = 0;
    HBM_embedding11Ext.flags = bank[11];
    HBM_embedding12Ext.obj = HBM_embedding12.data();
    HBM_embedding12Ext.param = 0;
    HBM_embedding12Ext.flags = bank[12];
    HBM_embedding13Ext.obj = HBM_embedding13.data();
    HBM_embedding13Ext.param = 0;
    HBM_embedding13Ext.flags = bank[13];
    HBM_embedding14Ext.obj = HBM_embedding14.data();
    HBM_embedding14Ext.param = 0;
    HBM_embedding14Ext.flags = bank[14];
    HBM_embedding15Ext.obj = HBM_embedding15.data();
    HBM_embedding15Ext.param = 0;
    HBM_embedding15Ext.flags = bank[15];
    HBM_embedding16Ext.obj = HBM_embedding16.data();
    HBM_embedding16Ext.param = 0;
    HBM_embedding16Ext.flags = bank[16];
    HBM_embedding17Ext.obj = HBM_embedding17.data();
    HBM_embedding17Ext.param = 0;
    HBM_embedding17Ext.flags = bank[17];
    HBM_embedding18Ext.obj = HBM_embedding18.data();
    HBM_embedding18Ext.param = 0;
    HBM_embedding18Ext.flags = bank[18];
    HBM_embedding19Ext.obj = HBM_embedding19.data();
    HBM_embedding19Ext.param = 0;
    HBM_embedding19Ext.flags = bank[19];
    HBM_embedding20Ext.obj = HBM_embedding20.data();
    HBM_embedding20Ext.param = 0;
    HBM_embedding20Ext.flags = bank[20];
    HBM_embedding21Ext.obj = HBM_embedding21.data();
    HBM_embedding21Ext.param = 0;
    HBM_embedding21Ext.flags = bank[21];
    HBM_embedding22Ext.obj = HBM_embedding22.data();
    HBM_embedding22Ext.param = 0;
    HBM_embedding22Ext.flags = bank[22];
    HBM_embedding23Ext.obj = HBM_embedding23.data();
    HBM_embedding23Ext.param = 0;
    HBM_embedding23Ext.flags = bank[23];
    HBM_embedding24Ext.obj = HBM_embedding24.data();
    HBM_embedding24Ext.param = 0;
    HBM_embedding24Ext.flags = bank[24];
    HBM_embedding25Ext.obj = HBM_embedding25.data();
    HBM_embedding25Ext.param = 0;
    HBM_embedding25Ext.flags = bank[25];
    HBM_embedding26Ext.obj = HBM_embedding26.data();
    HBM_embedding26Ext.param = 0;
    HBM_embedding26Ext.flags = bank[26];
    HBM_embedding27Ext.obj = HBM_embedding27.data();
    HBM_embedding27Ext.param = 0;
    HBM_embedding27Ext.flags = bank[27];

    //int size_results_out = HIDDEN_SIZE1_PARTIAL; 
    //std::vector<D_TYPE,aligned_allocator<D_TYPE>> source_hw_results(size_results_out);
    //cl_mem_ext_ptr_t sourcce_hw_resultsExt;
////
    //sourcce_hw_resultsExt.obj = source_hw_results.data();
    //sourcce_hw_resultsExt.param = 0;
    //sourcce_hw_resultsExt.flags = bank[34];

    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding0(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding0_size *sizeof(int), &HBM_embedding0Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding1(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding1_size *sizeof(int), &HBM_embedding1Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding2(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding2_size *sizeof(int), &HBM_embedding2Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding3(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding3_size *sizeof(int), &HBM_embedding3Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding4(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding4_size *sizeof(int), &HBM_embedding4Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding5(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding5_size *sizeof(int), &HBM_embedding5Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding6(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding6_size *sizeof(int), &HBM_embedding6Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding7(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding7_size *sizeof(int), &HBM_embedding7Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding8(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding8_size *sizeof(int), &HBM_embedding8Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding9(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding9_size *sizeof(int), &HBM_embedding9Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding10(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding10_size *sizeof(int), &HBM_embedding10Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding11(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding11_size *sizeof(int), &HBM_embedding11Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding12(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding12_size *sizeof(int), &HBM_embedding12Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding13(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding13_size *sizeof(int), &HBM_embedding13Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding14(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding14_size *sizeof(int), &HBM_embedding14Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding15(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding15_size *sizeof(int), &HBM_embedding15Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding16(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding16_size *sizeof(int), &HBM_embedding16Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding17(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding17_size *sizeof(int), &HBM_embedding17Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding18(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding18_size *sizeof(int), &HBM_embedding18Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding19(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding19_size *sizeof(int), &HBM_embedding19Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding20(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding20_size *sizeof(int), &HBM_embedding20Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding21(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding21_size *sizeof(int), &HBM_embedding21Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding22(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding22_size *sizeof(int), &HBM_embedding22Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding23(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding23_size *sizeof(int), &HBM_embedding23Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding24(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding24_size *sizeof(int), &HBM_embedding24Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding25(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding25_size *sizeof(int), &HBM_embedding25Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding26(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding26_size *sizeof(int), &HBM_embedding26Ext, &err));
    OCL_CHECK(err, cl::Buffer buffer_HBM_embedding27(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX, 
            HBM_embedding27_size *sizeof(int), &HBM_embedding27Ext, &err));

    //OCL_CHECK(err, cl::Buffer buffer_output(
    //    context, CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY | CL_MEM_EXT_PTR_XILINX, 
    //    size_results_out *sizeof(int), &sourcce_hw_resultsExt, &err));
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    //Set user Kernel Arguments
    //Set user Kernel Arguments
    //Set user Kernel Arguments for receiving data
    OCL_CHECK(err, err = user_kernel.setArg(16, connection_recv));
    OCL_CHECK(err, err = user_kernel.setArg(17, basePort_recv));
    OCL_CHECK(err, err = user_kernel.setArg(18, rxPkt));
    //Set user Kernel Arguments for sending data
    OCL_CHECK(err, err = user_kernel.setArg(19, connection_send));
    OCL_CHECK(err, err = user_kernel.setArg(20, numPacketWord_send));
    OCL_CHECK(err, err = user_kernel.setArg(21, basePort_send_1));
    OCL_CHECK(err, err = user_kernel.setArg(22, txPkt_1));
    OCL_CHECK(err, err = user_kernel.setArg(23, baseIpAddr_send_1));
    OCL_CHECK(err, err = user_kernel.setArg(24, basePort_send_2));
    OCL_CHECK(err, err = user_kernel.setArg(25, txPkt_2));
    OCL_CHECK(err, err = user_kernel.setArg(26, baseIpAddr_send_2));

//////////////////////////////////////////////// Set Arguments for Memory ///////////////////////////////////////

    OCL_CHECK(err, err = user_kernel.setArg(27, buffer_HBM_embedding0));
    OCL_CHECK(err, err = user_kernel.setArg(28, buffer_HBM_embedding1));
    OCL_CHECK(err, err = user_kernel.setArg(29, buffer_HBM_embedding2));
    OCL_CHECK(err, err = user_kernel.setArg(30, buffer_HBM_embedding3));
    OCL_CHECK(err, err = user_kernel.setArg(31, buffer_HBM_embedding4));
    OCL_CHECK(err, err = user_kernel.setArg(32, buffer_HBM_embedding5));
    OCL_CHECK(err, err = user_kernel.setArg(33, buffer_HBM_embedding6));
    OCL_CHECK(err, err = user_kernel.setArg(34, buffer_HBM_embedding7));
    OCL_CHECK(err, err = user_kernel.setArg(35, buffer_HBM_embedding8));
    OCL_CHECK(err, err = user_kernel.setArg(36, buffer_HBM_embedding9));
    OCL_CHECK(err, err = user_kernel.setArg(37, buffer_HBM_embedding10));
    OCL_CHECK(err, err = user_kernel.setArg(38, buffer_HBM_embedding11));
    OCL_CHECK(err, err = user_kernel.setArg(39, buffer_HBM_embedding12));
    OCL_CHECK(err, err = user_kernel.setArg(40, buffer_HBM_embedding13));
    OCL_CHECK(err, err = user_kernel.setArg(41, buffer_HBM_embedding14));
    OCL_CHECK(err, err = user_kernel.setArg(42, buffer_HBM_embedding15));
    OCL_CHECK(err, err = user_kernel.setArg(43, buffer_HBM_embedding16));
    OCL_CHECK(err, err = user_kernel.setArg(44, buffer_HBM_embedding17));
    OCL_CHECK(err, err = user_kernel.setArg(45, buffer_HBM_embedding18));
    OCL_CHECK(err, err = user_kernel.setArg(46, buffer_HBM_embedding19));
    OCL_CHECK(err, err = user_kernel.setArg(47, buffer_HBM_embedding20));
    OCL_CHECK(err, err = user_kernel.setArg(48, buffer_HBM_embedding21));
    OCL_CHECK(err, err = user_kernel.setArg(49, buffer_HBM_embedding22));
    OCL_CHECK(err, err = user_kernel.setArg(50, buffer_HBM_embedding23));
    OCL_CHECK(err, err = user_kernel.setArg(51, buffer_HBM_embedding24));
    OCL_CHECK(err, err = user_kernel.setArg(52, buffer_HBM_embedding25));
    OCL_CHECK(err, err = user_kernel.setArg(53, buffer_HBM_embedding26));
    OCL_CHECK(err, err = user_kernel.setArg(54, buffer_HBM_embedding27));

    //OCL_CHECK(err, err = user_kernel.setArg(49, buffer_output));

    OCL_CHECK(
        err, err = q.enqueueMigrateMemObjects({
        buffer_HBM_embedding0, buffer_HBM_embedding1, buffer_HBM_embedding2, buffer_HBM_embedding3, 
        buffer_HBM_embedding4, buffer_HBM_embedding5, buffer_HBM_embedding6, buffer_HBM_embedding7, 
        buffer_HBM_embedding8, buffer_HBM_embedding9, buffer_HBM_embedding10, buffer_HBM_embedding11, 
        buffer_HBM_embedding12, buffer_HBM_embedding13, buffer_HBM_embedding14, buffer_HBM_embedding15, 
        buffer_HBM_embedding16, buffer_HBM_embedding17, buffer_HBM_embedding18, buffer_HBM_embedding19, 
        buffer_HBM_embedding20, buffer_HBM_embedding21, buffer_HBM_embedding22, buffer_HBM_embedding23, 
        buffer_HBM_embedding24, buffer_HBM_embedding25, buffer_HBM_embedding26, buffer_HBM_embedding27}, 0/* 0 means from host*/));	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Launch the Kernel
    auto start = std::chrono::high_resolution_clock::now();
    printf("enqueue user kernel...\n");
    OCL_CHECK(err, err = q.enqueueTask(user_kernel));


    //OCL_CHECK(err, err = q.enqueueMigrateMemObjects({buffer_output},CL_MIGRATE_MEM_OBJECT_HOST));


    OCL_CHECK(err, err = q.finish());


    //for (int i = 0 ; i < HIDDEN_SIZE1_PARTIAL; i++) {
    //    std::cout << "i = " << i << " Device result = " << source_hw_results[i] << std::endl;
    //}

    auto end = std::chrono::high_resolution_clock::now();
    durationUs = (std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count() / 1000.0);
    printf("durationUs:%f\n",durationUs);
    //OPENCL HOST CODE AREA END    

    std::cout << "EXIT recorded" << std::endl;
}
