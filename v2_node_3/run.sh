#!/bin/bash
prlimit --pid=$PPID --nproc=1024
make cleanall
time make all TARGET=hw DEVICE=/opt/xilinx/platforms/xilinx_u280_xdma_201920_3/xilinx_u280_xdma_201920_3.xpfm USER_KRNL=hls_bil_krnl USER_KRNL_MODE=hls NETH=4 > hw

