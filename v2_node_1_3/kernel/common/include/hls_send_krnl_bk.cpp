
#include "ap_axi_sdata.h"
#include <ap_fixed.h>
#include "ap_int.h" 
#include "../../../../common/include/communication.hpp"
#include "../../../../common/include/compute_4.hpp"
#include "hls_stream.h"

extern "C" {
void hls_send_krnl(
               // Internal Stream
               hls::stream<pkt512>& s_axis_udp_rx, 
               hls::stream<pkt512>& m_axis_udp_tx, 
               hls::stream<pkt256>& s_axis_udp_rx_meta, 
               hls::stream<pkt256>& m_axis_udp_tx_meta, 
               
               hls::stream<pkt16>& m_axis_tcp_listen_port, 
               hls::stream<pkt8>& s_axis_tcp_port_status, 
               hls::stream<pkt64>& m_axis_tcp_open_connection, 
               hls::stream<pkt32>& s_axis_tcp_open_status, 
               hls::stream<pkt16>& m_axis_tcp_close_connection, 
               hls::stream<pkt128>& s_axis_tcp_notification, 
               hls::stream<pkt32>& m_axis_tcp_read_pkg, 
               hls::stream<pkt16>& s_axis_tcp_rx_meta, 
               hls::stream<pkt512>& s_axis_tcp_rx_data, 
               hls::stream<pkt32>& m_axis_tcp_tx_meta, 
               hls::stream<pkt512>& m_axis_tcp_tx_data, 
               hls::stream<pkt64>& s_axis_tcp_tx_status,

               int useConn, 
               int pkgWordCount, 
               int basePort, 
               int expectedTxPkgCnt, 
               int baseIpAddress,

               const t_axi* table_HBM0, const t_axi* table_HBM1, 
               const t_axi* table_HBM2, const t_axi* table_HBM3, 
               const t_axi* table_HBM4, const t_axi* table_HBM5, 
               const t_axi* table_HBM6, const t_axi* table_HBM7, 
               const t_axi* table_HBM8, const t_axi* table_HBM9, 
               const t_axi* table_HBM10, const t_axi* table_HBM11, 
               const t_axi* table_HBM12, const t_axi* table_HBM13, 
               const t_axi* table_HBM14, const t_axi* table_HBM15, 
               const t_axi* table_HBM16, const t_axi* table_HBM17, 
               const t_axi* table_HBM18, const t_axi* table_HBM19, 
               const t_axi* table_HBM20, const t_axi* table_HBM21, 
               const t_axi* table_HBM22, const t_axi* table_HBM23, 
               const t_axi* table_HBM24, const t_axi* table_HBM25, 
               const t_axi* table_HBM26, const t_axi* table_HBM27
               //D_TYPE* out_PLRAM
                      ) {

#pragma HLS INTERFACE axis port = s_axis_udp_rx
#pragma HLS INTERFACE axis port = m_axis_udp_tx
#pragma HLS INTERFACE axis port = s_axis_udp_rx_meta
#pragma HLS INTERFACE axis port = m_axis_udp_tx_meta
#pragma HLS INTERFACE axis port = m_axis_tcp_listen_port
#pragma HLS INTERFACE axis port = s_axis_tcp_port_status
#pragma HLS INTERFACE axis port = m_axis_tcp_open_connection
#pragma HLS INTERFACE axis port = s_axis_tcp_open_status
#pragma HLS INTERFACE axis port = m_axis_tcp_close_connection
#pragma HLS INTERFACE axis port = s_axis_tcp_notification
#pragma HLS INTERFACE axis port = m_axis_tcp_read_pkg
#pragma HLS INTERFACE axis port = s_axis_tcp_rx_meta
#pragma HLS INTERFACE axis port = s_axis_tcp_rx_data
#pragma HLS INTERFACE axis port = m_axis_tcp_tx_meta
#pragma HLS INTERFACE axis port = m_axis_tcp_tx_data
#pragma HLS INTERFACE axis port = s_axis_tcp_tx_status

#pragma HLS INTERFACE s_axilite port=useConn bundle = control
#pragma HLS INTERFACE s_axilite port=pkgWordCount bundle = control
#pragma HLS INTERFACE s_axilite port=basePort bundle = control
#pragma HLS INTERFACE s_axilite port=expectedTxPkgCnt bundle = control
#pragma HLS INTERFACE s_axilite port=baseIpAddress bundle=control

#pragma HLS INTERFACE m_axi port=table_HBM0  offset=slave bundle=gmem0
#pragma HLS INTERFACE m_axi port=table_HBM1  offset=slave bundle=gmem1
#pragma HLS INTERFACE m_axi port=table_HBM2  offset=slave bundle=gmem2
#pragma HLS INTERFACE m_axi port=table_HBM3  offset=slave bundle=gmem3
#pragma HLS INTERFACE m_axi port=table_HBM4  offset=slave bundle=gmem4
#pragma HLS INTERFACE m_axi port=table_HBM5  offset=slave bundle=gmem5
#pragma HLS INTERFACE m_axi port=table_HBM6  offset=slave bundle=gmem6
#pragma HLS INTERFACE m_axi port=table_HBM7  offset=slave bundle=gmem7
#pragma HLS INTERFACE m_axi port=table_HBM8  offset=slave bundle=gmem8
#pragma HLS INTERFACE m_axi port=table_HBM9  offset=slave bundle=gmem9
#pragma HLS INTERFACE m_axi port=table_HBM10  offset=slave bundle=gmem10
#pragma HLS INTERFACE m_axi port=table_HBM11  offset=slave bundle=gmem11
#pragma HLS INTERFACE m_axi port=table_HBM12  offset=slave bundle=gmem12
#pragma HLS INTERFACE m_axi port=table_HBM13  offset=slave bundle=gmem13
#pragma HLS INTERFACE m_axi port=table_HBM14  offset=slave bundle=gmem14
#pragma HLS INTERFACE m_axi port=table_HBM15  offset=slave bundle=gmem15
#pragma HLS INTERFACE m_axi port=table_HBM16  offset=slave bundle=gmem16
#pragma HLS INTERFACE m_axi port=table_HBM17  offset=slave bundle=gmem17
#pragma HLS INTERFACE m_axi port=table_HBM18  offset=slave bundle=gmem18
#pragma HLS INTERFACE m_axi port=table_HBM19  offset=slave bundle=gmem19
#pragma HLS INTERFACE m_axi port=table_HBM20  offset=slave bundle=gmem20
#pragma HLS INTERFACE m_axi port=table_HBM21  offset=slave bundle=gmem21
#pragma HLS INTERFACE m_axi port=table_HBM22  offset=slave bundle=gmem22
#pragma HLS INTERFACE m_axi port=table_HBM23  offset=slave bundle=gmem23
#pragma HLS INTERFACE m_axi port=table_HBM24  offset=slave bundle=gmem24
#pragma HLS INTERFACE m_axi port=table_HBM25  offset=slave bundle=gmem25
#pragma HLS INTERFACE m_axi port=table_HBM26  offset=slave bundle=gmem26
#pragma HLS INTERFACE m_axi port=table_HBM27  offset=slave bundle=gmem27
//#pragma HLS INTERFACE m_axi port=out_PLRAM offset=slave bundle=gmem34

#pragma HLS INTERFACE s_axilite port=table_HBM0  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM1  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM2  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM3  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM4  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM5  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM6  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM7  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM8  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM9  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM10  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM11  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM12  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM13  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM14  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM15  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM16  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM17  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM18  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM19  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM20  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM21  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM22  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM23  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM24  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM25  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM26  bundle=control
#pragma HLS INTERFACE s_axilite port=table_HBM27  bundle=control
//#pragma HLS INTERFACE s_axilite port=out_PLRAM bundle=control


#pragma HLS INTERFACE s_axilite port = return bundle = control

    hls::stream<t_axi> s_embedding_buffer_HBM0;
    hls::stream<t_axi> s_embedding_buffer_HBM1;
    hls::stream<t_axi> s_embedding_buffer_HBM2;
    hls::stream<t_axi> s_embedding_buffer_HBM3;
    hls::stream<t_axi> s_embedding_buffer_HBM4;
    hls::stream<t_axi> s_embedding_buffer_HBM5;
    hls::stream<t_axi> s_embedding_buffer_HBM6;
    hls::stream<t_axi> s_embedding_buffer_HBM7;
    hls::stream<t_axi> s_embedding_buffer_HBM8;
    hls::stream<t_axi> s_embedding_buffer_HBM9;
    hls::stream<t_axi> s_embedding_buffer_HBM10;
    hls::stream<t_axi> s_embedding_buffer_HBM11;
    hls::stream<t_axi> s_embedding_buffer_HBM12;
    hls::stream<t_axi> s_embedding_buffer_HBM13;
    hls::stream<t_axi> s_embedding_buffer_HBM14;
    hls::stream<t_axi> s_embedding_buffer_HBM15;
    hls::stream<t_axi> s_embedding_buffer_HBM16;
    hls::stream<t_axi> s_embedding_buffer_HBM17;
    hls::stream<t_axi> s_embedding_buffer_HBM18;
    hls::stream<t_axi> s_embedding_buffer_HBM19;
    hls::stream<t_axi> s_embedding_buffer_HBM20;
    hls::stream<t_axi> s_embedding_buffer_HBM21;
    hls::stream<t_axi> s_embedding_buffer_HBM22;
    hls::stream<t_axi> s_embedding_buffer_HBM23;
    hls::stream<t_axi> s_embedding_buffer_HBM24;
    hls::stream<t_axi> s_embedding_buffer_HBM25;
    hls::stream<t_axi> s_embedding_buffer_HBM26;
    hls::stream<t_axi> s_embedding_buffer_HBM27;
#pragma HLS stream variable=s_embedding_buffer_HBM0 depth=depth_s_embedding_buffer_HBM0
#pragma HLS stream variable=s_embedding_buffer_HBM1 depth=depth_s_embedding_buffer_HBM1
#pragma HLS stream variable=s_embedding_buffer_HBM2 depth=depth_s_embedding_buffer_HBM2
#pragma HLS stream variable=s_embedding_buffer_HBM3 depth=depth_s_embedding_buffer_HBM3
#pragma HLS stream variable=s_embedding_buffer_HBM4 depth=depth_s_embedding_buffer_HBM4
#pragma HLS stream variable=s_embedding_buffer_HBM5 depth=depth_s_embedding_buffer_HBM5
#pragma HLS stream variable=s_embedding_buffer_HBM6 depth=depth_s_embedding_buffer_HBM6
#pragma HLS stream variable=s_embedding_buffer_HBM7 depth=depth_s_embedding_buffer_HBM7
#pragma HLS stream variable=s_embedding_buffer_HBM8 depth=depth_s_embedding_buffer_HBM8
#pragma HLS stream variable=s_embedding_buffer_HBM9 depth=depth_s_embedding_buffer_HBM9
#pragma HLS stream variable=s_embedding_buffer_HBM10 depth=depth_s_embedding_buffer_HBM10
#pragma HLS stream variable=s_embedding_buffer_HBM11 depth=depth_s_embedding_buffer_HBM11
#pragma HLS stream variable=s_embedding_buffer_HBM12 depth=depth_s_embedding_buffer_HBM12
#pragma HLS stream variable=s_embedding_buffer_HBM13 depth=depth_s_embedding_buffer_HBM13
#pragma HLS stream variable=s_embedding_buffer_HBM14 depth=depth_s_embedding_buffer_HBM14
#pragma HLS stream variable=s_embedding_buffer_HBM15 depth=depth_s_embedding_buffer_HBM15
#pragma HLS stream variable=s_embedding_buffer_HBM16 depth=depth_s_embedding_buffer_HBM16
#pragma HLS stream variable=s_embedding_buffer_HBM17 depth=depth_s_embedding_buffer_HBM17
#pragma HLS stream variable=s_embedding_buffer_HBM18 depth=depth_s_embedding_buffer_HBM18
#pragma HLS stream variable=s_embedding_buffer_HBM19 depth=depth_s_embedding_buffer_HBM19
#pragma HLS stream variable=s_embedding_buffer_HBM20 depth=depth_s_embedding_buffer_HBM20
#pragma HLS stream variable=s_embedding_buffer_HBM21 depth=depth_s_embedding_buffer_HBM21
#pragma HLS stream variable=s_embedding_buffer_HBM22 depth=depth_s_embedding_buffer_HBM22
#pragma HLS stream variable=s_embedding_buffer_HBM23 depth=depth_s_embedding_buffer_HBM23
#pragma HLS stream variable=s_embedding_buffer_HBM24 depth=depth_s_embedding_buffer_HBM24
#pragma HLS stream variable=s_embedding_buffer_HBM25 depth=depth_s_embedding_buffer_HBM25
#pragma HLS stream variable=s_embedding_buffer_HBM26 depth=depth_s_embedding_buffer_HBM26
#pragma HLS stream variable=s_embedding_buffer_HBM27 depth=depth_s_embedding_buffer_HBM27
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM0;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM1;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM2;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM3;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM4;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM5;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM6;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM7;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM8;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM9;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM10;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM11;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM12;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM13;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM14;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM15;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM16;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM17;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM18;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM19;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM20;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM21;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM22;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM23;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM24;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM25;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM26;
    hls::stream<W_TYPE> s_embedding_buffer_wide_HBM27;
#pragma HLS stream variable=s_embedding_buffer_wide_HBM0 depth=depth_s_embedding_buffer_wide_HBM0
#pragma HLS stream variable=s_embedding_buffer_wide_HBM1 depth=depth_s_embedding_buffer_wide_HBM1
#pragma HLS stream variable=s_embedding_buffer_wide_HBM2 depth=depth_s_embedding_buffer_wide_HBM2
#pragma HLS stream variable=s_embedding_buffer_wide_HBM3 depth=depth_s_embedding_buffer_wide_HBM3
#pragma HLS stream variable=s_embedding_buffer_wide_HBM4 depth=depth_s_embedding_buffer_wide_HBM4
#pragma HLS stream variable=s_embedding_buffer_wide_HBM5 depth=depth_s_embedding_buffer_wide_HBM5
#pragma HLS stream variable=s_embedding_buffer_wide_HBM6 depth=depth_s_embedding_buffer_wide_HBM6
#pragma HLS stream variable=s_embedding_buffer_wide_HBM7 depth=depth_s_embedding_buffer_wide_HBM7
#pragma HLS stream variable=s_embedding_buffer_wide_HBM8 depth=depth_s_embedding_buffer_wide_HBM8
#pragma HLS stream variable=s_embedding_buffer_wide_HBM9 depth=depth_s_embedding_buffer_wide_HBM9
#pragma HLS stream variable=s_embedding_buffer_wide_HBM10 depth=depth_s_embedding_buffer_wide_HBM10
#pragma HLS stream variable=s_embedding_buffer_wide_HBM11 depth=depth_s_embedding_buffer_wide_HBM11
#pragma HLS stream variable=s_embedding_buffer_wide_HBM12 depth=depth_s_embedding_buffer_wide_HBM12
#pragma HLS stream variable=s_embedding_buffer_wide_HBM13 depth=depth_s_embedding_buffer_wide_HBM13
#pragma HLS stream variable=s_embedding_buffer_wide_HBM14 depth=depth_s_embedding_buffer_wide_HBM14
#pragma HLS stream variable=s_embedding_buffer_wide_HBM15 depth=depth_s_embedding_buffer_wide_HBM15
#pragma HLS stream variable=s_embedding_buffer_wide_HBM16 depth=depth_s_embedding_buffer_wide_HBM16
#pragma HLS stream variable=s_embedding_buffer_wide_HBM17 depth=depth_s_embedding_buffer_wide_HBM17
#pragma HLS stream variable=s_embedding_buffer_wide_HBM18 depth=depth_s_embedding_buffer_wide_HBM18
#pragma HLS stream variable=s_embedding_buffer_wide_HBM19 depth=depth_s_embedding_buffer_wide_HBM19
#pragma HLS stream variable=s_embedding_buffer_wide_HBM20 depth=depth_s_embedding_buffer_wide_HBM20
#pragma HLS stream variable=s_embedding_buffer_wide_HBM21 depth=depth_s_embedding_buffer_wide_HBM21
#pragma HLS stream variable=s_embedding_buffer_wide_HBM22 depth=depth_s_embedding_buffer_wide_HBM22
#pragma HLS stream variable=s_embedding_buffer_wide_HBM23 depth=depth_s_embedding_buffer_wide_HBM23
#pragma HLS stream variable=s_embedding_buffer_wide_HBM24 depth=depth_s_embedding_buffer_wide_HBM24
#pragma HLS stream variable=s_embedding_buffer_wide_HBM25 depth=depth_s_embedding_buffer_wide_HBM25
#pragma HLS stream variable=s_embedding_buffer_wide_HBM26 depth=depth_s_embedding_buffer_wide_HBM26
#pragma HLS stream variable=s_embedding_buffer_wide_HBM27 depth=depth_s_embedding_buffer_wide_HBM27

    hls::stream<int> s_idx_buffer_HBM0;
    hls::stream<int> s_idx_buffer_HBM1;
    hls::stream<int> s_idx_buffer_HBM2;
    hls::stream<int> s_idx_buffer_HBM3;
    hls::stream<int> s_idx_buffer_HBM4;
    hls::stream<int> s_idx_buffer_HBM5;
    hls::stream<int> s_idx_buffer_HBM6;
    hls::stream<int> s_idx_buffer_HBM7;
    hls::stream<int> s_idx_buffer_HBM8;
    hls::stream<int> s_idx_buffer_HBM9;
    hls::stream<int> s_idx_buffer_HBM10;
    hls::stream<int> s_idx_buffer_HBM11;
    hls::stream<int> s_idx_buffer_HBM12;
    hls::stream<int> s_idx_buffer_HBM13;
    hls::stream<int> s_idx_buffer_HBM14;
    hls::stream<int> s_idx_buffer_HBM15;
    hls::stream<int> s_idx_buffer_HBM16;
    hls::stream<int> s_idx_buffer_HBM17;
    hls::stream<int> s_idx_buffer_HBM18;
    hls::stream<int> s_idx_buffer_HBM19;
    hls::stream<int> s_idx_buffer_HBM20;
    hls::stream<int> s_idx_buffer_HBM21;
    hls::stream<int> s_idx_buffer_HBM22;
    hls::stream<int> s_idx_buffer_HBM23;
    hls::stream<int> s_idx_buffer_HBM24;
    hls::stream<int> s_idx_buffer_HBM25;
    hls::stream<int> s_idx_buffer_HBM26;
    hls::stream<int> s_idx_buffer_HBM27;
#pragma HLS stream variable=s_idx_buffer_HBM0 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM1 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM2 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM3 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM4 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM5 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM6 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM7 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM8 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM9 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM10 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM11 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM12 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM13 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM14 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM15 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM16 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM17 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM18 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM19 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM20 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM21 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM22 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM23 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM24 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM25 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM26 depth=fifo_batch_size
#pragma HLS stream variable=s_idx_buffer_HBM27 depth=fifo_batch_size

    hls::stream<W_TYPE> s_feature_in;
#pragma HLS stream variable=s_feature_in depth=128

    hls::stream<W_TYPE> s_feature1_PE0;
    hls::stream<D_TYPE> s_result1_PE0;
#pragma HLS stream variable=s_feature1_PE0 depth=2
#pragma HLS stream variable=s_result1_PE0 depth=2
    hls::stream<W_TYPE> s_feature1_PE1;
    hls::stream<D_TYPE> s_result1_PE1;
#pragma HLS stream variable=s_feature1_PE1 depth=2
#pragma HLS stream variable=s_result1_PE1 depth=2
    hls::stream<W_TYPE> s_feature1_PE2;
    hls::stream<D_TYPE> s_result1_PE2;
#pragma HLS stream variable=s_feature1_PE2 depth=2
#pragma HLS stream variable=s_result1_PE2 depth=2
    hls::stream<W_TYPE> s_feature1_PE3;
    hls::stream<D_TYPE> s_result1_PE3;
#pragma HLS stream variable=s_feature1_PE3 depth=2
#pragma HLS stream variable=s_result1_PE3 depth=2
    hls::stream<W_TYPE> s_feature1_PE4;
    hls::stream<D_TYPE> s_result1_PE4;
#pragma HLS stream variable=s_feature1_PE4 depth=2
#pragma HLS stream variable=s_result1_PE4 depth=2
    hls::stream<W_TYPE> s_feature1_PE5;
    hls::stream<D_TYPE> s_result1_PE5;
#pragma HLS stream variable=s_feature1_PE5 depth=2
#pragma HLS stream variable=s_result1_PE5 depth=2
    hls::stream<W_TYPE> s_feature1_PE6;
    hls::stream<D_TYPE> s_result1_PE6;
#pragma HLS stream variable=s_feature1_PE6 depth=2
#pragma HLS stream variable=s_result1_PE6 depth=2
    hls::stream<W_TYPE> s_feature1_PE7;
    hls::stream<D_TYPE> s_result1_PE7;
#pragma HLS stream variable=s_feature1_PE7 depth=2
#pragma HLS stream variable=s_result1_PE7 depth=2
    hls::stream<W_TYPE> s_feature1_PE8;
    hls::stream<D_TYPE> s_result1_PE8;
#pragma HLS stream variable=s_feature1_PE8 depth=2
#pragma HLS stream variable=s_result1_PE8 depth=2
    hls::stream<W_TYPE> s_feature1_PE9;
    hls::stream<D_TYPE> s_result1_PE9;
#pragma HLS stream variable=s_feature1_PE9 depth=2
#pragma HLS stream variable=s_result1_PE9 depth=2
    hls::stream<W_TYPE> s_feature1_PE10;
    hls::stream<D_TYPE> s_result1_PE10;
#pragma HLS stream variable=s_feature1_PE10 depth=2
#pragma HLS stream variable=s_result1_PE10 depth=2
    hls::stream<W_TYPE> s_feature1_PE11;
    hls::stream<D_TYPE> s_result1_PE11;
#pragma HLS stream variable=s_feature1_PE11 depth=2
#pragma HLS stream variable=s_result1_PE11 depth=2
    hls::stream<W_TYPE> s_feature1_PE12;
    hls::stream<D_TYPE> s_result1_PE12;
#pragma HLS stream variable=s_feature1_PE12 depth=2
#pragma HLS stream variable=s_result1_PE12 depth=2
    hls::stream<W_TYPE> s_feature1_PE13;
    hls::stream<D_TYPE> s_result1_PE13;
#pragma HLS stream variable=s_feature1_PE13 depth=2
#pragma HLS stream variable=s_result1_PE13 depth=2
    hls::stream<W_TYPE> s_feature1_PE14;
    hls::stream<D_TYPE> s_result1_PE14;
#pragma HLS stream variable=s_feature1_PE14 depth=2
#pragma HLS stream variable=s_result1_PE14 depth=2
    hls::stream<W_TYPE> s_feature1_PE15;
    hls::stream<D_TYPE> s_result1_PE15;
#pragma HLS stream variable=s_feature1_PE15 depth=2
#pragma HLS stream variable=s_result1_PE15 depth=2
    hls::stream<W_TYPE> s_feature1_PE16;
    hls::stream<D_TYPE> s_result1_PE16;
#pragma HLS stream variable=s_feature1_PE16 depth=2
#pragma HLS stream variable=s_result1_PE16 depth=2
    hls::stream<W_TYPE> s_feature1_PE17;
    hls::stream<D_TYPE> s_result1_PE17;
#pragma HLS stream variable=s_feature1_PE17 depth=2
#pragma HLS stream variable=s_result1_PE17 depth=2
    hls::stream<W_TYPE> s_feature1_PE18;
    hls::stream<D_TYPE> s_result1_PE18;
#pragma HLS stream variable=s_feature1_PE18 depth=2
#pragma HLS stream variable=s_result1_PE18 depth=2
    hls::stream<W_TYPE> s_feature1_PE19;
    hls::stream<D_TYPE> s_result1_PE19;
#pragma HLS stream variable=s_feature1_PE19 depth=2
#pragma HLS stream variable=s_result1_PE19 depth=2
    hls::stream<W_TYPE> s_feature1_PE20;
    hls::stream<D_TYPE> s_result1_PE20;
#pragma HLS stream variable=s_feature1_PE20 depth=2
#pragma HLS stream variable=s_result1_PE20 depth=2
    hls::stream<W_TYPE> s_feature1_PE21;
    hls::stream<D_TYPE> s_result1_PE21;
#pragma HLS stream variable=s_feature1_PE21 depth=2
#pragma HLS stream variable=s_result1_PE21 depth=2
    hls::stream<W_TYPE> s_feature1_PE22;
    hls::stream<D_TYPE> s_result1_PE22;
#pragma HLS stream variable=s_feature1_PE22 depth=2
#pragma HLS stream variable=s_result1_PE22 depth=2
    hls::stream<W_TYPE> s_feature1_PE23;
    hls::stream<D_TYPE> s_result1_PE23;
#pragma HLS stream variable=s_feature1_PE23 depth=2
#pragma HLS stream variable=s_result1_PE23 depth=2
    hls::stream<W_TYPE> s_feature1_PE24;
    hls::stream<D_TYPE> s_result1_PE24;
#pragma HLS stream variable=s_feature1_PE24 depth=2
#pragma HLS stream variable=s_result1_PE24 depth=2
    hls::stream<W_TYPE> s_feature1_PE25;
    hls::stream<D_TYPE> s_result1_PE25;
#pragma HLS stream variable=s_feature1_PE25 depth=2
#pragma HLS stream variable=s_result1_PE25 depth=2
    hls::stream<W_TYPE> s_feature1_PE26;
    hls::stream<D_TYPE> s_result1_PE26;
#pragma HLS stream variable=s_feature1_PE26 depth=2
#pragma HLS stream variable=s_result1_PE26 depth=2
    hls::stream<W_TYPE> s_feature1_PE27;
    hls::stream<D_TYPE> s_result1_PE27;
#pragma HLS stream variable=s_feature1_PE27 depth=2
#pragma HLS stream variable=s_result1_PE27 depth=2
    hls::stream<W_TYPE> s_feature1_PE28;
    hls::stream<D_TYPE> s_result1_PE28;
#pragma HLS stream variable=s_feature1_PE28 depth=2
#pragma HLS stream variable=s_result1_PE28 depth=2
    hls::stream<W_TYPE> s_feature1_PE29;
    hls::stream<D_TYPE> s_result1_PE29;
#pragma HLS stream variable=s_feature1_PE29 depth=2
#pragma HLS stream variable=s_result1_PE29 depth=2
    hls::stream<W_TYPE> s_feature1_PE30;
    hls::stream<D_TYPE> s_result1_PE30;
#pragma HLS stream variable=s_feature1_PE30 depth=2
#pragma HLS stream variable=s_result1_PE30 depth=2
    hls::stream<W_TYPE> s_feature1_PE31;
    hls::stream<D_TYPE> s_result1_PE31;
#pragma HLS stream variable=s_feature1_PE31 depth=2
#pragma HLS stream variable=s_result1_PE31 depth=2
    hls::stream<W_TYPE> s_feature1_PE32;
    hls::stream<D_TYPE> s_result1_PE32;
#pragma HLS stream variable=s_feature1_PE32 depth=2
#pragma HLS stream variable=s_result1_PE32 depth=2
    hls::stream<W_TYPE> s_feature1_PE33;
    hls::stream<D_TYPE> s_result1_PE33;
#pragma HLS stream variable=s_feature1_PE33 depth=2
#pragma HLS stream variable=s_result1_PE33 depth=2
    hls::stream<W_TYPE> s_feature1_PE34;
    hls::stream<D_TYPE> s_result1_PE34;
#pragma HLS stream variable=s_feature1_PE34 depth=2
#pragma HLS stream variable=s_result1_PE34 depth=2
    hls::stream<W_TYPE> s_feature1_PE35;
    hls::stream<D_TYPE> s_result1_PE35;
#pragma HLS stream variable=s_feature1_PE35 depth=2
#pragma HLS stream variable=s_result1_PE35 depth=2
    hls::stream<W_TYPE> s_feature1_PE36;
    hls::stream<D_TYPE> s_result1_PE36;
#pragma HLS stream variable=s_feature1_PE36 depth=2
#pragma HLS stream variable=s_result1_PE36 depth=2
    hls::stream<W_TYPE> s_feature1_PE37;
    hls::stream<D_TYPE> s_result1_PE37;
#pragma HLS stream variable=s_feature1_PE37 depth=2
#pragma HLS stream variable=s_result1_PE37 depth=2
    hls::stream<W_TYPE> s_feature1_PE38;
    hls::stream<D_TYPE> s_result1_PE38;
#pragma HLS stream variable=s_feature1_PE38 depth=2
#pragma HLS stream variable=s_result1_PE38 depth=2
    hls::stream<W_TYPE> s_feature1_PE39;
    hls::stream<D_TYPE> s_result1_PE39;
#pragma HLS stream variable=s_feature1_PE39 depth=2
#pragma HLS stream variable=s_result1_PE39 depth=2
    hls::stream<W_TYPE> s_feature1_PE40;
    hls::stream<D_TYPE> s_result1_PE40;
#pragma HLS stream variable=s_feature1_PE40 depth=2
#pragma HLS stream variable=s_result1_PE40 depth=2
    hls::stream<W_TYPE> s_feature1_PE41;
    hls::stream<D_TYPE> s_result1_PE41;
#pragma HLS stream variable=s_feature1_PE41 depth=2
#pragma HLS stream variable=s_result1_PE41 depth=2
    hls::stream<W_TYPE> s_feature1_PE42;
    hls::stream<D_TYPE> s_result1_PE42;
#pragma HLS stream variable=s_feature1_PE42 depth=2
#pragma HLS stream variable=s_result1_PE42 depth=2
    hls::stream<W_TYPE> s_feature1_PE43;
    hls::stream<D_TYPE> s_result1_PE43;
#pragma HLS stream variable=s_feature1_PE43 depth=2
#pragma HLS stream variable=s_result1_PE43 depth=2
    hls::stream<W_TYPE> s_feature1_PE44;
    hls::stream<D_TYPE> s_result1_PE44;
#pragma HLS stream variable=s_feature1_PE44 depth=2
#pragma HLS stream variable=s_result1_PE44 depth=2
    hls::stream<W_TYPE> s_feature1_PE45;
    hls::stream<D_TYPE> s_result1_PE45;
#pragma HLS stream variable=s_feature1_PE45 depth=2
#pragma HLS stream variable=s_result1_PE45 depth=2
    hls::stream<W_TYPE> s_feature1_PE46;
    hls::stream<D_TYPE> s_result1_PE46;
#pragma HLS stream variable=s_feature1_PE46 depth=2
#pragma HLS stream variable=s_result1_PE46 depth=2
    hls::stream<W_TYPE> s_feature1_PE47;
    hls::stream<D_TYPE> s_result1_PE47;
#pragma HLS stream variable=s_feature1_PE47 depth=2
#pragma HLS stream variable=s_result1_PE47 depth=2
    hls::stream<W_TYPE> s_feature1_PE48;
    hls::stream<D_TYPE> s_result1_PE48;
#pragma HLS stream variable=s_feature1_PE48 depth=2
#pragma HLS stream variable=s_result1_PE48 depth=2
    hls::stream<W_TYPE> s_feature1_PE49;
    hls::stream<D_TYPE> s_result1_PE49;
#pragma HLS stream variable=s_feature1_PE49 depth=2
#pragma HLS stream variable=s_result1_PE49 depth=2
    hls::stream<W_TYPE> s_feature1_PE50;
    hls::stream<D_TYPE> s_result1_PE50;
#pragma HLS stream variable=s_feature1_PE50 depth=2
#pragma HLS stream variable=s_result1_PE50 depth=2
    hls::stream<W_TYPE> s_feature1_PE51;
    hls::stream<D_TYPE> s_result1_PE51;
#pragma HLS stream variable=s_feature1_PE51 depth=2
#pragma HLS stream variable=s_result1_PE51 depth=2
    hls::stream<W_TYPE> s_feature1_PE52;
    hls::stream<D_TYPE> s_result1_PE52;
#pragma HLS stream variable=s_feature1_PE52 depth=2
#pragma HLS stream variable=s_result1_PE52 depth=2
    hls::stream<W_TYPE> s_feature1_PE53;
    hls::stream<D_TYPE> s_result1_PE53;
#pragma HLS stream variable=s_feature1_PE53 depth=2
#pragma HLS stream variable=s_result1_PE53 depth=2
    hls::stream<W_TYPE> s_feature1_PE54;
    hls::stream<D_TYPE> s_result1_PE54;
#pragma HLS stream variable=s_feature1_PE54 depth=2
#pragma HLS stream variable=s_result1_PE54 depth=2
    hls::stream<W_TYPE> s_feature1_PE55;
    hls::stream<D_TYPE> s_result1_PE55;
#pragma HLS stream variable=s_feature1_PE55 depth=2
#pragma HLS stream variable=s_result1_PE55 depth=2
    hls::stream<W_TYPE> s_feature1_PE56;
    hls::stream<D_TYPE> s_result1_PE56;
#pragma HLS stream variable=s_feature1_PE56 depth=2
#pragma HLS stream variable=s_result1_PE56 depth=2
    hls::stream<W_TYPE> s_feature1_PE57;
    hls::stream<D_TYPE> s_result1_PE57;
#pragma HLS stream variable=s_feature1_PE57 depth=2
#pragma HLS stream variable=s_result1_PE57 depth=2
    hls::stream<W_TYPE> s_feature1_PE58;
    hls::stream<D_TYPE> s_result1_PE58;
#pragma HLS stream variable=s_feature1_PE58 depth=2
#pragma HLS stream variable=s_result1_PE58 depth=2
    hls::stream<W_TYPE> s_feature1_PE59;
    hls::stream<D_TYPE> s_result1_PE59;
#pragma HLS stream variable=s_feature1_PE59 depth=2
#pragma HLS stream variable=s_result1_PE59 depth=2
    hls::stream<W_TYPE> s_feature1_PE60;
    hls::stream<D_TYPE> s_result1_PE60;
#pragma HLS stream variable=s_feature1_PE60 depth=2
#pragma HLS stream variable=s_result1_PE60 depth=2
    hls::stream<W_TYPE> s_feature1_PE61;
    hls::stream<D_TYPE> s_result1_PE61;
#pragma HLS stream variable=s_feature1_PE61 depth=2
#pragma HLS stream variable=s_result1_PE61 depth=2
    hls::stream<W_TYPE> s_feature1_PE62;
    hls::stream<D_TYPE> s_result1_PE62;
#pragma HLS stream variable=s_feature1_PE62 depth=2
#pragma HLS stream variable=s_result1_PE62 depth=2
    hls::stream<W_TYPE> s_feature1_PE63;
    hls::stream<D_TYPE> s_result1_PE63;
#pragma HLS stream variable=s_feature1_PE63 depth=2
#pragma HLS stream variable=s_result1_PE63 depth=2
    hls::stream<W_TYPE> s_feature1_PE64;
    hls::stream<D_TYPE> s_result1_PE64;
#pragma HLS stream variable=s_feature1_PE64 depth=2
#pragma HLS stream variable=s_result1_PE64 depth=2
    hls::stream<W_TYPE> s_feature1_PE65;
    hls::stream<D_TYPE> s_result1_PE65;
#pragma HLS stream variable=s_feature1_PE65 depth=2
#pragma HLS stream variable=s_result1_PE65 depth=2
    hls::stream<W_TYPE> s_feature1_PE66;
    hls::stream<D_TYPE> s_result1_PE66;
#pragma HLS stream variable=s_feature1_PE66 depth=2
#pragma HLS stream variable=s_result1_PE66 depth=2
    hls::stream<W_TYPE> s_feature1_PE67;
    hls::stream<D_TYPE> s_result1_PE67;
#pragma HLS stream variable=s_feature1_PE67 depth=2
#pragma HLS stream variable=s_result1_PE67 depth=2
    hls::stream<W_TYPE> s_feature1_PE68;
    hls::stream<D_TYPE> s_result1_PE68;
#pragma HLS stream variable=s_feature1_PE68 depth=2
#pragma HLS stream variable=s_result1_PE68 depth=2
    hls::stream<W_TYPE> s_feature1_PE69;
    hls::stream<D_TYPE> s_result1_PE69;
#pragma HLS stream variable=s_feature1_PE69 depth=2
#pragma HLS stream variable=s_result1_PE69 depth=2
    hls::stream<W_TYPE> s_feature1_PE70;
    hls::stream<D_TYPE> s_result1_PE70;
#pragma HLS stream variable=s_feature1_PE70 depth=2
#pragma HLS stream variable=s_result1_PE70 depth=2
    hls::stream<W_TYPE> s_feature1_PE71;
    hls::stream<D_TYPE> s_result1_PE71;
#pragma HLS stream variable=s_feature1_PE71 depth=2
#pragma HLS stream variable=s_result1_PE71 depth=2
    hls::stream<W_TYPE> s_feature1_PE72;
    hls::stream<D_TYPE> s_result1_PE72;
#pragma HLS stream variable=s_feature1_PE72 depth=2
#pragma HLS stream variable=s_result1_PE72 depth=2
    hls::stream<W_TYPE> s_feature1_PE73;
    hls::stream<D_TYPE> s_result1_PE73;
#pragma HLS stream variable=s_feature1_PE73 depth=2
#pragma HLS stream variable=s_result1_PE73 depth=2
    hls::stream<W_TYPE> s_feature1_PE74;
    hls::stream<D_TYPE> s_result1_PE74;
#pragma HLS stream variable=s_feature1_PE74 depth=2
#pragma HLS stream variable=s_result1_PE74 depth=2
    hls::stream<W_TYPE> s_feature1_PE75;
    hls::stream<D_TYPE> s_result1_PE75;
#pragma HLS stream variable=s_feature1_PE75 depth=2
#pragma HLS stream variable=s_result1_PE75 depth=2
    hls::stream<W_TYPE> s_feature1_PE76;
    hls::stream<D_TYPE> s_result1_PE76;
#pragma HLS stream variable=s_feature1_PE76 depth=2
#pragma HLS stream variable=s_result1_PE76 depth=2
    hls::stream<W_TYPE> s_feature1_PE77;
    hls::stream<D_TYPE> s_result1_PE77;
#pragma HLS stream variable=s_feature1_PE77 depth=2
#pragma HLS stream variable=s_result1_PE77 depth=2
    hls::stream<W_TYPE> s_feature1_PE78;
    hls::stream<D_TYPE> s_result1_PE78;
#pragma HLS stream variable=s_feature1_PE78 depth=2
#pragma HLS stream variable=s_result1_PE78 depth=2
    hls::stream<W_TYPE> s_feature1_PE79;
    hls::stream<D_TYPE> s_result1_PE79;
#pragma HLS stream variable=s_feature1_PE79 depth=2
#pragma HLS stream variable=s_result1_PE79 depth=2
    hls::stream<W_TYPE> s_feature1_PE80;
    hls::stream<D_TYPE> s_result1_PE80;
#pragma HLS stream variable=s_feature1_PE80 depth=2
#pragma HLS stream variable=s_result1_PE80 depth=2
    hls::stream<W_TYPE> s_feature1_PE81;
    hls::stream<D_TYPE> s_result1_PE81;
#pragma HLS stream variable=s_feature1_PE81 depth=2
#pragma HLS stream variable=s_result1_PE81 depth=2
    hls::stream<W_TYPE> s_feature1_PE82;
    hls::stream<D_TYPE> s_result1_PE82;
#pragma HLS stream variable=s_feature1_PE82 depth=2
#pragma HLS stream variable=s_result1_PE82 depth=2
    hls::stream<W_TYPE> s_feature1_PE83;
    hls::stream<D_TYPE> s_result1_PE83;
#pragma HLS stream variable=s_feature1_PE83 depth=2
#pragma HLS stream variable=s_result1_PE83 depth=2
    hls::stream<W_TYPE> s_feature1_PE84;
    hls::stream<D_TYPE> s_result1_PE84;
#pragma HLS stream variable=s_feature1_PE84 depth=2
#pragma HLS stream variable=s_result1_PE84 depth=2
    hls::stream<W_TYPE> s_feature1_PE85;
    hls::stream<D_TYPE> s_result1_PE85;
#pragma HLS stream variable=s_feature1_PE85 depth=2
#pragma HLS stream variable=s_result1_PE85 depth=2
    hls::stream<W_TYPE> s_feature1_PE86;
    hls::stream<D_TYPE> s_result1_PE86;
#pragma HLS stream variable=s_feature1_PE86 depth=2
#pragma HLS stream variable=s_result1_PE86 depth=2
    hls::stream<W_TYPE> s_feature1_PE87;
    hls::stream<D_TYPE> s_result1_PE87;
#pragma HLS stream variable=s_feature1_PE87 depth=2
#pragma HLS stream variable=s_result1_PE87 depth=2
    hls::stream<W_TYPE> s_feature1_PE88;
    hls::stream<D_TYPE> s_result1_PE88;
#pragma HLS stream variable=s_feature1_PE88 depth=2
#pragma HLS stream variable=s_result1_PE88 depth=2
    hls::stream<W_TYPE> s_feature1_PE89;
    hls::stream<D_TYPE> s_result1_PE89;
#pragma HLS stream variable=s_feature1_PE89 depth=2
#pragma HLS stream variable=s_result1_PE89 depth=2
    hls::stream<W_TYPE> s_feature1_PE90;
    hls::stream<D_TYPE> s_result1_PE90;
#pragma HLS stream variable=s_feature1_PE90 depth=2
#pragma HLS stream variable=s_result1_PE90 depth=2
    hls::stream<W_TYPE> s_feature1_PE91;
    hls::stream<D_TYPE> s_result1_PE91;
#pragma HLS stream variable=s_feature1_PE91 depth=2
#pragma HLS stream variable=s_result1_PE91 depth=2
    hls::stream<W_TYPE> s_feature1_PE92;
    hls::stream<D_TYPE> s_result1_PE92;
#pragma HLS stream variable=s_feature1_PE92 depth=2
#pragma HLS stream variable=s_result1_PE92 depth=2
    hls::stream<W_TYPE> s_feature1_PE93;
    hls::stream<D_TYPE> s_result1_PE93;
#pragma HLS stream variable=s_feature1_PE93 depth=2
#pragma HLS stream variable=s_result1_PE93 depth=2
    hls::stream<W_TYPE> s_feature1_PE94;
    hls::stream<D_TYPE> s_result1_PE94;
#pragma HLS stream variable=s_feature1_PE94 depth=2
#pragma HLS stream variable=s_result1_PE94 depth=2
    hls::stream<W_TYPE> s_feature1_PE95;
    hls::stream<D_TYPE> s_result1_PE95;
#pragma HLS stream variable=s_feature1_PE95 depth=2
#pragma HLS stream variable=s_result1_PE95 depth=2
    hls::stream<W_TYPE> s_feature1_PE96;
    hls::stream<D_TYPE> s_result1_PE96;
#pragma HLS stream variable=s_feature1_PE96 depth=2
#pragma HLS stream variable=s_result1_PE96 depth=2
    hls::stream<W_TYPE> s_feature1_PE97;
    hls::stream<D_TYPE> s_result1_PE97;
#pragma HLS stream variable=s_feature1_PE97 depth=2
#pragma HLS stream variable=s_result1_PE97 depth=2
    hls::stream<W_TYPE> s_feature1_PE98;
    hls::stream<D_TYPE> s_result1_PE98;
#pragma HLS stream variable=s_feature1_PE98 depth=2
#pragma HLS stream variable=s_result1_PE98 depth=2
    hls::stream<W_TYPE> s_feature1_PE99;
    hls::stream<D_TYPE> s_result1_PE99;
#pragma HLS stream variable=s_feature1_PE99 depth=2
#pragma HLS stream variable=s_result1_PE99 depth=2
    hls::stream<W_TYPE> s_feature1_PE100;
    hls::stream<D_TYPE> s_result1_PE100;
#pragma HLS stream variable=s_feature1_PE100 depth=2
#pragma HLS stream variable=s_result1_PE100 depth=2
    hls::stream<W_TYPE> s_feature1_PE101;
    hls::stream<D_TYPE> s_result1_PE101;
#pragma HLS stream variable=s_feature1_PE101 depth=2
#pragma HLS stream variable=s_result1_PE101 depth=2
    hls::stream<W_TYPE> s_feature1_PE102;
    hls::stream<D_TYPE> s_result1_PE102;
#pragma HLS stream variable=s_feature1_PE102 depth=2
#pragma HLS stream variable=s_result1_PE102 depth=2
    hls::stream<W_TYPE> s_feature1_PE103;
    hls::stream<D_TYPE> s_result1_PE103;
#pragma HLS stream variable=s_feature1_PE103 depth=2
#pragma HLS stream variable=s_result1_PE103 depth=2
    hls::stream<W_TYPE> s_feature1_PE104;
    hls::stream<D_TYPE> s_result1_PE104;
#pragma HLS stream variable=s_feature1_PE104 depth=2
#pragma HLS stream variable=s_result1_PE104 depth=2
    hls::stream<W_TYPE> s_feature1_PE105;
    hls::stream<D_TYPE> s_result1_PE105;
#pragma HLS stream variable=s_feature1_PE105 depth=2
#pragma HLS stream variable=s_result1_PE105 depth=2
    hls::stream<W_TYPE> s_feature1_PE106;
    hls::stream<D_TYPE> s_result1_PE106;
#pragma HLS stream variable=s_feature1_PE106 depth=2
#pragma HLS stream variable=s_result1_PE106 depth=2
    hls::stream<W_TYPE> s_feature1_PE107;
    hls::stream<D_TYPE> s_result1_PE107;
#pragma HLS stream variable=s_feature1_PE107 depth=2
#pragma HLS stream variable=s_result1_PE107 depth=2
    hls::stream<W_TYPE> s_feature1_PE108;
    hls::stream<D_TYPE> s_result1_PE108;
#pragma HLS stream variable=s_feature1_PE108 depth=2
#pragma HLS stream variable=s_result1_PE108 depth=2
    hls::stream<W_TYPE> s_feature1_PE109;
    hls::stream<D_TYPE> s_result1_PE109;
#pragma HLS stream variable=s_feature1_PE109 depth=2
#pragma HLS stream variable=s_result1_PE109 depth=2
    hls::stream<W_TYPE> s_feature1_PE110;
    hls::stream<D_TYPE> s_result1_PE110;
#pragma HLS stream variable=s_feature1_PE110 depth=2
#pragma HLS stream variable=s_result1_PE110 depth=2
    hls::stream<W_TYPE> s_feature1_PE111;
    hls::stream<D_TYPE> s_result1_PE111;
#pragma HLS stream variable=s_feature1_PE111 depth=2
#pragma HLS stream variable=s_result1_PE111 depth=2
    hls::stream<W_TYPE> s_feature1_PE112;
    hls::stream<D_TYPE> s_result1_PE112;
#pragma HLS stream variable=s_feature1_PE112 depth=2
#pragma HLS stream variable=s_result1_PE112 depth=2
    hls::stream<W_TYPE> s_feature1_PE113;
    hls::stream<D_TYPE> s_result1_PE113;
#pragma HLS stream variable=s_feature1_PE113 depth=2
#pragma HLS stream variable=s_result1_PE113 depth=2
    hls::stream<W_TYPE> s_feature1_PE114;
    hls::stream<D_TYPE> s_result1_PE114;
#pragma HLS stream variable=s_feature1_PE114 depth=2
#pragma HLS stream variable=s_result1_PE114 depth=2
    hls::stream<W_TYPE> s_feature1_PE115;
    hls::stream<D_TYPE> s_result1_PE115;
#pragma HLS stream variable=s_feature1_PE115 depth=2
#pragma HLS stream variable=s_result1_PE115 depth=2
    hls::stream<W_TYPE> s_feature1_PE116;
    hls::stream<D_TYPE> s_result1_PE116;
#pragma HLS stream variable=s_feature1_PE116 depth=2
#pragma HLS stream variable=s_result1_PE116 depth=2
    hls::stream<W_TYPE> s_feature1_PE117;
    hls::stream<D_TYPE> s_result1_PE117;
#pragma HLS stream variable=s_feature1_PE117 depth=2
#pragma HLS stream variable=s_result1_PE117 depth=2
    hls::stream<W_TYPE> s_feature1_PE118;
    hls::stream<D_TYPE> s_result1_PE118;
#pragma HLS stream variable=s_feature1_PE118 depth=2
#pragma HLS stream variable=s_result1_PE118 depth=2
    hls::stream<W_TYPE> s_feature1_PE119;
    hls::stream<D_TYPE> s_result1_PE119;
#pragma HLS stream variable=s_feature1_PE119 depth=2
#pragma HLS stream variable=s_result1_PE119 depth=2
    hls::stream<W_TYPE> s_feature1_PE120;
    hls::stream<D_TYPE> s_result1_PE120;
#pragma HLS stream variable=s_feature1_PE120 depth=2
#pragma HLS stream variable=s_result1_PE120 depth=2
    hls::stream<W_TYPE> s_feature1_PE121;
    hls::stream<D_TYPE> s_result1_PE121;
#pragma HLS stream variable=s_feature1_PE121 depth=2
#pragma HLS stream variable=s_result1_PE121 depth=2
    hls::stream<W_TYPE> s_feature1_PE122;
    hls::stream<D_TYPE> s_result1_PE122;
#pragma HLS stream variable=s_feature1_PE122 depth=2
#pragma HLS stream variable=s_result1_PE122 depth=2
    hls::stream<W_TYPE> s_feature1_PE123;
    hls::stream<D_TYPE> s_result1_PE123;
#pragma HLS stream variable=s_feature1_PE123 depth=2
#pragma HLS stream variable=s_result1_PE123 depth=2
    hls::stream<W_TYPE> s_feature1_PE124;
    hls::stream<D_TYPE> s_result1_PE124;
#pragma HLS stream variable=s_feature1_PE124 depth=2
#pragma HLS stream variable=s_result1_PE124 depth=2
    hls::stream<W_TYPE> s_feature1_PE125;
    hls::stream<D_TYPE> s_result1_PE125;
#pragma HLS stream variable=s_feature1_PE125 depth=2
#pragma HLS stream variable=s_result1_PE125 depth=2
    hls::stream<W_TYPE> s_feature1_PE126;
    hls::stream<D_TYPE> s_result1_PE126;
#pragma HLS stream variable=s_feature1_PE126 depth=2
#pragma HLS stream variable=s_result1_PE126 depth=2
    hls::stream<W_TYPE> s_feature1_PE127;
    hls::stream<D_TYPE> s_result1_PE127;
#pragma HLS stream variable=s_feature1_PE127 depth=2
#pragma HLS stream variable=s_result1_PE127 depth=2
    hls::stream<W_TYPE> s_feature1_PE128;
    hls::stream<D_TYPE> s_result1_PE128;
#pragma HLS stream variable=s_feature1_PE128 depth=2
#pragma HLS stream variable=s_result1_PE128 depth=2
    hls::stream<W_TYPE> s_feature1_PE129;
    hls::stream<D_TYPE> s_result1_PE129;
#pragma HLS stream variable=s_feature1_PE129 depth=2
#pragma HLS stream variable=s_result1_PE129 depth=2
    hls::stream<W_TYPE> s_feature1_PE130;
    hls::stream<D_TYPE> s_result1_PE130;
#pragma HLS stream variable=s_feature1_PE130 depth=2
#pragma HLS stream variable=s_result1_PE130 depth=2
    hls::stream<W_TYPE> s_feature1_PE131;
    hls::stream<D_TYPE> s_result1_PE131;
#pragma HLS stream variable=s_feature1_PE131 depth=2
#pragma HLS stream variable=s_result1_PE131 depth=2
    hls::stream<W_TYPE> s_feature1_PE132;
    hls::stream<D_TYPE> s_result1_PE132;
#pragma HLS stream variable=s_feature1_PE132 depth=2
#pragma HLS stream variable=s_result1_PE132 depth=2
    hls::stream<W_TYPE> s_feature1_PE133;
    hls::stream<D_TYPE> s_result1_PE133;
#pragma HLS stream variable=s_feature1_PE133 depth=2
#pragma HLS stream variable=s_result1_PE133 depth=2
    hls::stream<W_TYPE> s_feature1_PE134;
    hls::stream<D_TYPE> s_result1_PE134;
#pragma HLS stream variable=s_feature1_PE134 depth=2
#pragma HLS stream variable=s_result1_PE134 depth=2
    hls::stream<W_TYPE> s_feature1_PE135;
    hls::stream<D_TYPE> s_result1_PE135;
#pragma HLS stream variable=s_feature1_PE135 depth=2
#pragma HLS stream variable=s_result1_PE135 depth=2
    hls::stream<W_TYPE> s_feature1_PE136;
    hls::stream<D_TYPE> s_result1_PE136;
#pragma HLS stream variable=s_feature1_PE136 depth=2
#pragma HLS stream variable=s_result1_PE136 depth=2
    hls::stream<W_TYPE> s_feature1_PE137;
    hls::stream<D_TYPE> s_result1_PE137;
#pragma HLS stream variable=s_feature1_PE137 depth=2
#pragma HLS stream variable=s_result1_PE137 depth=2
    hls::stream<W_TYPE> s_feature1_PE138;
    hls::stream<D_TYPE> s_result1_PE138;
#pragma HLS stream variable=s_feature1_PE138 depth=2
#pragma HLS stream variable=s_result1_PE138 depth=2
    hls::stream<W_TYPE> s_feature1_PE139;
    hls::stream<D_TYPE> s_result1_PE139;
#pragma HLS stream variable=s_feature1_PE139 depth=2
#pragma HLS stream variable=s_result1_PE139 depth=2
    hls::stream<W_TYPE> s_feature1_PE140;
    hls::stream<D_TYPE> s_result1_PE140;
#pragma HLS stream variable=s_feature1_PE140 depth=2
#pragma HLS stream variable=s_result1_PE140 depth=2
    hls::stream<W_TYPE> s_feature1_PE141;
    hls::stream<D_TYPE> s_result1_PE141;
#pragma HLS stream variable=s_feature1_PE141 depth=2
#pragma HLS stream variable=s_result1_PE141 depth=2
    hls::stream<W_TYPE> s_feature1_PE142;
    hls::stream<D_TYPE> s_result1_PE142;
#pragma HLS stream variable=s_feature1_PE142 depth=2
#pragma HLS stream variable=s_result1_PE142 depth=2
    hls::stream<W_TYPE> s_feature1_PE143;
    hls::stream<D_TYPE> s_result1_PE143;
#pragma HLS stream variable=s_feature1_PE143 depth=2
#pragma HLS stream variable=s_result1_PE143 depth=2
    hls::stream<W_TYPE> s_feature1_PE144;
    hls::stream<D_TYPE> s_result1_PE144;
#pragma HLS stream variable=s_feature1_PE144 depth=2
#pragma HLS stream variable=s_result1_PE144 depth=2
    hls::stream<W_TYPE> s_feature1_PE145;
    hls::stream<D_TYPE> s_result1_PE145;
#pragma HLS stream variable=s_feature1_PE145 depth=2
#pragma HLS stream variable=s_result1_PE145 depth=2
    hls::stream<W_TYPE> s_feature1_PE146;
    hls::stream<D_TYPE> s_result1_PE146;
#pragma HLS stream variable=s_feature1_PE146 depth=2
#pragma HLS stream variable=s_result1_PE146 depth=2
    hls::stream<W_TYPE> s_feature1_PE147;
    hls::stream<D_TYPE> s_result1_PE147;
#pragma HLS stream variable=s_feature1_PE147 depth=2
#pragma HLS stream variable=s_result1_PE147 depth=2
    hls::stream<W_TYPE> s_feature1_PE148;
    hls::stream<D_TYPE> s_result1_PE148;
#pragma HLS stream variable=s_feature1_PE148 depth=2
#pragma HLS stream variable=s_result1_PE148 depth=2
    hls::stream<W_TYPE> s_feature1_PE149;
    hls::stream<D_TYPE> s_result1_PE149;
#pragma HLS stream variable=s_feature1_PE149 depth=2
#pragma HLS stream variable=s_result1_PE149 depth=2
    hls::stream<W_TYPE> s_feature1_PE150;
    hls::stream<D_TYPE> s_result1_PE150;
#pragma HLS stream variable=s_feature1_PE150 depth=2
#pragma HLS stream variable=s_result1_PE150 depth=2
    hls::stream<W_TYPE> s_feature1_PE151;
    hls::stream<D_TYPE> s_result1_PE151;
#pragma HLS stream variable=s_feature1_PE151 depth=2
#pragma HLS stream variable=s_result1_PE151 depth=2
    hls::stream<W_TYPE> s_feature1_PE152;
    hls::stream<D_TYPE> s_result1_PE152;
#pragma HLS stream variable=s_feature1_PE152 depth=2
#pragma HLS stream variable=s_result1_PE152 depth=2
    hls::stream<W_TYPE> s_feature1_PE153;
    hls::stream<D_TYPE> s_result1_PE153;
#pragma HLS stream variable=s_feature1_PE153 depth=2
#pragma HLS stream variable=s_result1_PE153 depth=2
    hls::stream<W_TYPE> s_feature1_PE154;
    hls::stream<D_TYPE> s_result1_PE154;
#pragma HLS stream variable=s_feature1_PE154 depth=2
#pragma HLS stream variable=s_result1_PE154 depth=2
    hls::stream<W_TYPE> s_feature1_PE155;
    hls::stream<D_TYPE> s_result1_PE155;
#pragma HLS stream variable=s_feature1_PE155 depth=2
#pragma HLS stream variable=s_result1_PE155 depth=2
    hls::stream<W_TYPE> s_feature1_PE156;
    hls::stream<D_TYPE> s_result1_PE156;
#pragma HLS stream variable=s_feature1_PE156 depth=2
#pragma HLS stream variable=s_result1_PE156 depth=2
    hls::stream<W_TYPE> s_feature1_PE157;
    hls::stream<D_TYPE> s_result1_PE157;
#pragma HLS stream variable=s_feature1_PE157 depth=2
#pragma HLS stream variable=s_result1_PE157 depth=2
    hls::stream<W_TYPE> s_feature1_PE158;
    hls::stream<D_TYPE> s_result1_PE158;
#pragma HLS stream variable=s_feature1_PE158 depth=2
#pragma HLS stream variable=s_result1_PE158 depth=2
    hls::stream<W_TYPE> s_feature1_PE159;
    hls::stream<D_TYPE> s_result1_PE159;
#pragma HLS stream variable=s_feature1_PE159 depth=2
#pragma HLS stream variable=s_result1_PE159 depth=2
    hls::stream<W_TYPE> s_feature1_PE160;
    hls::stream<D_TYPE> s_result1_PE160;
#pragma HLS stream variable=s_feature1_PE160 depth=2
#pragma HLS stream variable=s_result1_PE160 depth=2
    hls::stream<W_TYPE> s_feature1_PE161;
    hls::stream<D_TYPE> s_result1_PE161;
#pragma HLS stream variable=s_feature1_PE161 depth=2
#pragma HLS stream variable=s_result1_PE161 depth=2
    hls::stream<W_TYPE> s_feature1_PE162;
    hls::stream<D_TYPE> s_result1_PE162;
#pragma HLS stream variable=s_feature1_PE162 depth=2
#pragma HLS stream variable=s_result1_PE162 depth=2
    hls::stream<W_TYPE> s_feature1_PE163;
    hls::stream<D_TYPE> s_result1_PE163;
#pragma HLS stream variable=s_feature1_PE163 depth=2
#pragma HLS stream variable=s_result1_PE163 depth=2
    hls::stream<W_TYPE> s_feature1_PE164;
    hls::stream<D_TYPE> s_result1_PE164;
#pragma HLS stream variable=s_feature1_PE164 depth=2
#pragma HLS stream variable=s_result1_PE164 depth=2
    hls::stream<W_TYPE> s_feature1_PE165;
    hls::stream<D_TYPE> s_result1_PE165;
#pragma HLS stream variable=s_feature1_PE165 depth=2
#pragma HLS stream variable=s_result1_PE165 depth=2
    hls::stream<W_TYPE> s_feature1_PE166;
    hls::stream<D_TYPE> s_result1_PE166;
#pragma HLS stream variable=s_feature1_PE166 depth=2
#pragma HLS stream variable=s_result1_PE166 depth=2
    hls::stream<W_TYPE> s_feature1_PE167;
    hls::stream<D_TYPE> s_result1_PE167;
#pragma HLS stream variable=s_feature1_PE167 depth=2
#pragma HLS stream variable=s_result1_PE167 depth=2
    hls::stream<W_TYPE> s_feature1_PE168;
    hls::stream<D_TYPE> s_result1_PE168;
#pragma HLS stream variable=s_feature1_PE168 depth=2
#pragma HLS stream variable=s_result1_PE168 depth=2
    hls::stream<W_TYPE> s_feature1_PE169;
    hls::stream<D_TYPE> s_result1_PE169;
#pragma HLS stream variable=s_feature1_PE169 depth=2
#pragma HLS stream variable=s_result1_PE169 depth=2
    hls::stream<W_TYPE> s_feature1_PE170;
    hls::stream<D_TYPE> s_result1_PE170;
#pragma HLS stream variable=s_feature1_PE170 depth=2
#pragma HLS stream variable=s_result1_PE170 depth=2
    hls::stream<W_TYPE> s_feature1_PE171;
    hls::stream<D_TYPE> s_result1_PE171;
#pragma HLS stream variable=s_feature1_PE171 depth=2
#pragma HLS stream variable=s_result1_PE171 depth=2
    hls::stream<W_TYPE> s_feature1_PE172;
    hls::stream<D_TYPE> s_result1_PE172;
#pragma HLS stream variable=s_feature1_PE172 depth=2
#pragma HLS stream variable=s_result1_PE172 depth=2
    hls::stream<W_TYPE> s_feature1_PE173;
    hls::stream<D_TYPE> s_result1_PE173;
#pragma HLS stream variable=s_feature1_PE173 depth=2
#pragma HLS stream variable=s_result1_PE173 depth=2
    hls::stream<W_TYPE> s_feature1_PE174;
    hls::stream<D_TYPE> s_result1_PE174;
#pragma HLS stream variable=s_feature1_PE174 depth=2
#pragma HLS stream variable=s_result1_PE174 depth=2
    hls::stream<W_TYPE> s_feature1_PE175;
    hls::stream<D_TYPE> s_result1_PE175;
#pragma HLS stream variable=s_feature1_PE175 depth=2
#pragma HLS stream variable=s_result1_PE175 depth=2
    hls::stream<W_TYPE> s_feature1_PE176;
    hls::stream<D_TYPE> s_result1_PE176;
#pragma HLS stream variable=s_feature1_PE176 depth=2
#pragma HLS stream variable=s_result1_PE176 depth=2
    hls::stream<W_TYPE> s_feature1_PE177;
    hls::stream<D_TYPE> s_result1_PE177;
#pragma HLS stream variable=s_feature1_PE177 depth=2
#pragma HLS stream variable=s_result1_PE177 depth=2
    hls::stream<W_TYPE> s_feature1_PE178;
    hls::stream<D_TYPE> s_result1_PE178;
#pragma HLS stream variable=s_feature1_PE178 depth=2
#pragma HLS stream variable=s_result1_PE178 depth=2
    hls::stream<W_TYPE> s_feature1_PE179;
    hls::stream<D_TYPE> s_result1_PE179;
#pragma HLS stream variable=s_feature1_PE179 depth=2
#pragma HLS stream variable=s_result1_PE179 depth=2
    hls::stream<W_TYPE> s_feature1_PE180;
    hls::stream<D_TYPE> s_result1_PE180;
#pragma HLS stream variable=s_feature1_PE180 depth=2
#pragma HLS stream variable=s_result1_PE180 depth=2
    hls::stream<W_TYPE> s_feature1_PE181;
    hls::stream<D_TYPE> s_result1_PE181;
#pragma HLS stream variable=s_feature1_PE181 depth=2
#pragma HLS stream variable=s_result1_PE181 depth=2
    hls::stream<W_TYPE> s_feature1_PE182;
    hls::stream<D_TYPE> s_result1_PE182;
#pragma HLS stream variable=s_feature1_PE182 depth=2
#pragma HLS stream variable=s_result1_PE182 depth=2
    hls::stream<W_TYPE> s_feature1_PE183;
    hls::stream<D_TYPE> s_result1_PE183;
#pragma HLS stream variable=s_feature1_PE183 depth=2
#pragma HLS stream variable=s_result1_PE183 depth=2
    hls::stream<W_TYPE> s_feature1_PE184;
    hls::stream<D_TYPE> s_result1_PE184;
#pragma HLS stream variable=s_feature1_PE184 depth=2
#pragma HLS stream variable=s_result1_PE184 depth=2
    hls::stream<W_TYPE> s_feature1_PE185;
    hls::stream<D_TYPE> s_result1_PE185;
#pragma HLS stream variable=s_feature1_PE185 depth=2
#pragma HLS stream variable=s_result1_PE185 depth=2
    hls::stream<W_TYPE> s_feature1_PE186;
    hls::stream<D_TYPE> s_result1_PE186;
#pragma HLS stream variable=s_feature1_PE186 depth=2
#pragma HLS stream variable=s_result1_PE186 depth=2
    hls::stream<W_TYPE> s_feature1_PE187;
    hls::stream<D_TYPE> s_result1_PE187;
#pragma HLS stream variable=s_feature1_PE187 depth=2
#pragma HLS stream variable=s_result1_PE187 depth=2
    hls::stream<W_TYPE> s_feature1_PE188;
    hls::stream<D_TYPE> s_result1_PE188;
#pragma HLS stream variable=s_feature1_PE188 depth=2
#pragma HLS stream variable=s_result1_PE188 depth=2
    hls::stream<W_TYPE> s_feature1_PE189;
    hls::stream<D_TYPE> s_result1_PE189;
#pragma HLS stream variable=s_feature1_PE189 depth=2
#pragma HLS stream variable=s_result1_PE189 depth=2
    hls::stream<W_TYPE> s_feature1_PE190;
    hls::stream<D_TYPE> s_result1_PE190;
#pragma HLS stream variable=s_feature1_PE190 depth=2
#pragma HLS stream variable=s_result1_PE190 depth=2
    hls::stream<W_TYPE> s_feature1_PE191;
    hls::stream<D_TYPE> s_result1_PE191;
#pragma HLS stream variable=s_feature1_PE191 depth=2
#pragma HLS stream variable=s_result1_PE191 depth=2
    hls::stream<W_TYPE> s_feature1_PE192;
    hls::stream<D_TYPE> s_result1_PE192;
#pragma HLS stream variable=s_feature1_PE192 depth=2
#pragma HLS stream variable=s_result1_PE192 depth=2
    hls::stream<W_TYPE> s_feature1_PE193;
    hls::stream<D_TYPE> s_result1_PE193;
#pragma HLS stream variable=s_feature1_PE193 depth=2
#pragma HLS stream variable=s_result1_PE193 depth=2
    hls::stream<W_TYPE> s_feature1_PE194;
    hls::stream<D_TYPE> s_result1_PE194;
#pragma HLS stream variable=s_feature1_PE194 depth=2
#pragma HLS stream variable=s_result1_PE194 depth=2
    hls::stream<W_TYPE> s_feature1_PE195;
    hls::stream<D_TYPE> s_result1_PE195;
#pragma HLS stream variable=s_feature1_PE195 depth=2
#pragma HLS stream variable=s_result1_PE195 depth=2
    hls::stream<W_TYPE> s_feature1_PE196;
    hls::stream<D_TYPE> s_result1_PE196;
#pragma HLS stream variable=s_feature1_PE196 depth=2
#pragma HLS stream variable=s_result1_PE196 depth=2
    hls::stream<W_TYPE> s_feature1_PE197;
    hls::stream<D_TYPE> s_result1_PE197;
#pragma HLS stream variable=s_feature1_PE197 depth=2
#pragma HLS stream variable=s_result1_PE197 depth=2
    hls::stream<W_TYPE> s_feature1_PE198;
    hls::stream<D_TYPE> s_result1_PE198;
#pragma HLS stream variable=s_feature1_PE198 depth=2
#pragma HLS stream variable=s_result1_PE198 depth=2
    hls::stream<W_TYPE> s_feature1_PE199;
    hls::stream<D_TYPE> s_result1_PE199;
#pragma HLS stream variable=s_feature1_PE199 depth=2
#pragma HLS stream variable=s_result1_PE199 depth=2

    hls::stream<W_TYPE> s_result1_partial;
#pragma HLS stream variable=s_result1_partial depth=128
////////////////////////////////////////////////////////////////////////////////////////////////
// s_embedding_table store the data of embedding table
static hls::stream<W_TYPE>    s_embedding_table;
#pragma HLS STREAM variable=s_embedding_table depth=128
// s_data_in store the data of partial result of layer 1
static hls::stream<ap_uint<512> >    s_data_in;
#pragma HLS STREAM variable=s_data_in depth=256

     ap_uint<16> sessionID [128];
          
     openConnections( useConn, baseIpAddress, basePort, m_axis_tcp_open_connection, s_axis_tcp_open_status, sessionID);

#pragma HLS dataflow

/////////////////////////////////////// Compute ////////////////////////////////////////
     load_access_idx(
        s_idx_buffer_HBM0, s_idx_buffer_HBM1, s_idx_buffer_HBM2, s_idx_buffer_HBM3, 
        s_idx_buffer_HBM4, s_idx_buffer_HBM5, s_idx_buffer_HBM6, s_idx_buffer_HBM7, 
        s_idx_buffer_HBM8, s_idx_buffer_HBM9, s_idx_buffer_HBM10, s_idx_buffer_HBM11, 
        s_idx_buffer_HBM12, s_idx_buffer_HBM13, s_idx_buffer_HBM14, s_idx_buffer_HBM15, 
        s_idx_buffer_HBM16, s_idx_buffer_HBM17, s_idx_buffer_HBM18, s_idx_buffer_HBM19, 
        s_idx_buffer_HBM20, s_idx_buffer_HBM21, s_idx_buffer_HBM22, s_idx_buffer_HBM23, 
        s_idx_buffer_HBM24, s_idx_buffer_HBM25, s_idx_buffer_HBM26, s_idx_buffer_HBM27);

     load_single_embedding_2_tables<ADDR_AXI_HBM_0, AXI_PADDED_SIZE_HBM_0, ADDR_AXI_HBM_32, AXI_PADDED_SIZE_HBM_32>(
         s_idx_buffer_HBM0, table_HBM0, s_embedding_buffer_HBM0);
     load_single_embedding_2_tables<ADDR_AXI_HBM_1, AXI_PADDED_SIZE_HBM_1, ADDR_AXI_HBM_33, AXI_PADDED_SIZE_HBM_33>(
         s_idx_buffer_HBM1, table_HBM1, s_embedding_buffer_HBM1);
     load_single_embedding_2_tables<ADDR_AXI_HBM_2, AXI_PADDED_SIZE_HBM_2, ADDR_AXI_HBM_34, AXI_PADDED_SIZE_HBM_34>(
         s_idx_buffer_HBM2, table_HBM2, s_embedding_buffer_HBM2);
     load_single_embedding_2_tables<ADDR_AXI_HBM_3, AXI_PADDED_SIZE_HBM_3, ADDR_AXI_HBM_35, AXI_PADDED_SIZE_HBM_35>(
         s_idx_buffer_HBM3, table_HBM3, s_embedding_buffer_HBM3);
     load_single_embedding_2_tables<ADDR_AXI_HBM_4, AXI_PADDED_SIZE_HBM_4, ADDR_AXI_HBM_36, AXI_PADDED_SIZE_HBM_36>(
         s_idx_buffer_HBM4, table_HBM4, s_embedding_buffer_HBM4);
     load_single_embedding_2_tables<ADDR_AXI_HBM_5, AXI_PADDED_SIZE_HBM_5, ADDR_AXI_HBM_37, AXI_PADDED_SIZE_HBM_37>(
         s_idx_buffer_HBM5, table_HBM5, s_embedding_buffer_HBM5);
     load_single_embedding_2_tables<ADDR_AXI_HBM_6, AXI_PADDED_SIZE_HBM_6, ADDR_AXI_HBM_38, AXI_PADDED_SIZE_HBM_38>(
         s_idx_buffer_HBM6, table_HBM6, s_embedding_buffer_HBM6);
     load_single_embedding_2_tables<ADDR_AXI_HBM_7, AXI_PADDED_SIZE_HBM_7, ADDR_AXI_HBM_39, AXI_PADDED_SIZE_HBM_39>(
         s_idx_buffer_HBM7, table_HBM7, s_embedding_buffer_HBM7);
     load_single_embedding_2_tables<ADDR_AXI_HBM_8, AXI_PADDED_SIZE_HBM_8, ADDR_AXI_HBM_40, AXI_PADDED_SIZE_HBM_40>(
         s_idx_buffer_HBM8, table_HBM8, s_embedding_buffer_HBM8);
     load_single_embedding_2_tables<ADDR_AXI_HBM_9, AXI_PADDED_SIZE_HBM_9, ADDR_AXI_HBM_41, AXI_PADDED_SIZE_HBM_41>(
         s_idx_buffer_HBM9, table_HBM9, s_embedding_buffer_HBM9);
     load_single_embedding_2_tables<ADDR_AXI_HBM_10, AXI_PADDED_SIZE_HBM_10, ADDR_AXI_HBM_42, AXI_PADDED_SIZE_HBM_42>(
         s_idx_buffer_HBM10, table_HBM10, s_embedding_buffer_HBM10);
     load_single_embedding_2_tables<ADDR_AXI_HBM_11, AXI_PADDED_SIZE_HBM_11, ADDR_AXI_HBM_43, AXI_PADDED_SIZE_HBM_43>(
         s_idx_buffer_HBM11, table_HBM11, s_embedding_buffer_HBM11);
     load_single_embedding_2_tables<ADDR_AXI_HBM_12, AXI_PADDED_SIZE_HBM_12, ADDR_AXI_HBM_44, AXI_PADDED_SIZE_HBM_44>(
         s_idx_buffer_HBM12, table_HBM12, s_embedding_buffer_HBM12);
     load_single_embedding_2_tables<ADDR_AXI_HBM_13, AXI_PADDED_SIZE_HBM_13, ADDR_AXI_HBM_45, AXI_PADDED_SIZE_HBM_45>(
         s_idx_buffer_HBM13, table_HBM13, s_embedding_buffer_HBM13);
     load_single_embedding_2_tables<ADDR_AXI_HBM_14, AXI_PADDED_SIZE_HBM_14, ADDR_AXI_HBM_46, AXI_PADDED_SIZE_HBM_46>(
         s_idx_buffer_HBM14, table_HBM14, s_embedding_buffer_HBM14);
     load_single_embedding_2_tables<ADDR_AXI_HBM_15, AXI_PADDED_SIZE_HBM_15, ADDR_AXI_HBM_47, AXI_PADDED_SIZE_HBM_47>(
         s_idx_buffer_HBM15, table_HBM15, s_embedding_buffer_HBM15);
     load_single_embedding_2_tables<ADDR_AXI_HBM_16, AXI_PADDED_SIZE_HBM_16, ADDR_AXI_HBM_48, AXI_PADDED_SIZE_HBM_48>(
         s_idx_buffer_HBM16, table_HBM16, s_embedding_buffer_HBM16);
     load_single_embedding_2_tables<ADDR_AXI_HBM_17, AXI_PADDED_SIZE_HBM_17, ADDR_AXI_HBM_49, AXI_PADDED_SIZE_HBM_49>(
         s_idx_buffer_HBM17, table_HBM17, s_embedding_buffer_HBM17);
     load_single_embedding_2_tables<ADDR_AXI_HBM_18, AXI_PADDED_SIZE_HBM_18, ADDR_AXI_HBM_50, AXI_PADDED_SIZE_HBM_50>(
         s_idx_buffer_HBM18, table_HBM18, s_embedding_buffer_HBM18);
     load_single_embedding_2_tables<ADDR_AXI_HBM_19, AXI_PADDED_SIZE_HBM_19, ADDR_AXI_HBM_51, AXI_PADDED_SIZE_HBM_51>(
         s_idx_buffer_HBM19, table_HBM19, s_embedding_buffer_HBM19);
     load_single_embedding_2_tables<ADDR_AXI_HBM_20, AXI_PADDED_SIZE_HBM_20, ADDR_AXI_HBM_52, AXI_PADDED_SIZE_HBM_52>(
         s_idx_buffer_HBM20, table_HBM20, s_embedding_buffer_HBM20);
     load_single_embedding_2_tables<ADDR_AXI_HBM_21, AXI_PADDED_SIZE_HBM_21, ADDR_AXI_HBM_53, AXI_PADDED_SIZE_HBM_53>(
         s_idx_buffer_HBM21, table_HBM21, s_embedding_buffer_HBM21);
     load_single_embedding_2_tables<ADDR_AXI_HBM_22, AXI_PADDED_SIZE_HBM_22, ADDR_AXI_HBM_54, AXI_PADDED_SIZE_HBM_54>(
         s_idx_buffer_HBM22, table_HBM22, s_embedding_buffer_HBM22);
     load_single_embedding_2_tables<ADDR_AXI_HBM_23, AXI_PADDED_SIZE_HBM_23, ADDR_AXI_HBM_55, AXI_PADDED_SIZE_HBM_55>(
         s_idx_buffer_HBM23, table_HBM23, s_embedding_buffer_HBM23);
     load_single_embedding_2_tables<ADDR_AXI_HBM_24, AXI_PADDED_SIZE_HBM_24, ADDR_AXI_HBM_56, AXI_PADDED_SIZE_HBM_56>(
         s_idx_buffer_HBM24, table_HBM24, s_embedding_buffer_HBM24);
     load_single_embedding_2_tables<ADDR_AXI_HBM_25, AXI_PADDED_SIZE_HBM_25, ADDR_AXI_HBM_57, AXI_PADDED_SIZE_HBM_57>(
         s_idx_buffer_HBM25, table_HBM25, s_embedding_buffer_HBM25);
     load_single_embedding_2_tables<ADDR_AXI_HBM_26, AXI_PADDED_SIZE_HBM_26, ADDR_AXI_HBM_58, AXI_PADDED_SIZE_HBM_58>(
         s_idx_buffer_HBM26, table_HBM26, s_embedding_buffer_HBM26);
     load_single_embedding_2_tables<ADDR_AXI_HBM_27, AXI_PADDED_SIZE_HBM_27, ADDR_AXI_HBM_59, AXI_PADDED_SIZE_HBM_59>(
         s_idx_buffer_HBM27, table_HBM27, s_embedding_buffer_HBM27);

    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_0>(s_embedding_buffer_HBM0, s_embedding_buffer_wide_HBM0);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_1>(s_embedding_buffer_HBM1, s_embedding_buffer_wide_HBM1);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_2>(s_embedding_buffer_HBM2, s_embedding_buffer_wide_HBM2);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_3>(s_embedding_buffer_HBM3, s_embedding_buffer_wide_HBM3);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_4>(s_embedding_buffer_HBM4, s_embedding_buffer_wide_HBM4);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_5>(s_embedding_buffer_HBM5, s_embedding_buffer_wide_HBM5);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_6>(s_embedding_buffer_HBM6, s_embedding_buffer_wide_HBM6);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_7>(s_embedding_buffer_HBM7, s_embedding_buffer_wide_HBM7);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_8>(s_embedding_buffer_HBM8, s_embedding_buffer_wide_HBM8);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_9>(s_embedding_buffer_HBM9, s_embedding_buffer_wide_HBM9);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_10>(s_embedding_buffer_HBM10, s_embedding_buffer_wide_HBM10);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_11>(s_embedding_buffer_HBM11, s_embedding_buffer_wide_HBM11);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_12>(s_embedding_buffer_HBM12, s_embedding_buffer_wide_HBM12);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_13>(s_embedding_buffer_HBM13, s_embedding_buffer_wide_HBM13);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_14>(s_embedding_buffer_HBM14, s_embedding_buffer_wide_HBM14);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_15>(s_embedding_buffer_HBM15, s_embedding_buffer_wide_HBM15);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_16>(s_embedding_buffer_HBM16, s_embedding_buffer_wide_HBM16);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_17>(s_embedding_buffer_HBM17, s_embedding_buffer_wide_HBM17);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_18>(s_embedding_buffer_HBM18, s_embedding_buffer_wide_HBM18);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_19>(s_embedding_buffer_HBM19, s_embedding_buffer_wide_HBM19);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_20>(s_embedding_buffer_HBM20, s_embedding_buffer_wide_HBM20);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_21>(s_embedding_buffer_HBM21, s_embedding_buffer_wide_HBM21);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_22>(s_embedding_buffer_HBM22, s_embedding_buffer_wide_HBM22);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_23>(s_embedding_buffer_HBM23, s_embedding_buffer_wide_HBM23);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_24>(s_embedding_buffer_HBM24, s_embedding_buffer_wide_HBM24);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_25>(s_embedding_buffer_HBM25, s_embedding_buffer_wide_HBM25);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_26>(s_embedding_buffer_HBM26, s_embedding_buffer_wide_HBM26);
    int_to_wide<t_axi, VECTOR_SIZE_HBM_BANK_27>(s_embedding_buffer_HBM27, s_embedding_buffer_wide_HBM27);

    gather_embeddings(
        s_embedding_buffer_wide_HBM0, s_embedding_buffer_wide_HBM1, 
        s_embedding_buffer_wide_HBM2, s_embedding_buffer_wide_HBM3, 
        s_embedding_buffer_wide_HBM4, s_embedding_buffer_wide_HBM5, 
        s_embedding_buffer_wide_HBM6, s_embedding_buffer_wide_HBM7, 
        s_embedding_buffer_wide_HBM8, s_embedding_buffer_wide_HBM9, 
        s_embedding_buffer_wide_HBM10, s_embedding_buffer_wide_HBM11, 
        s_embedding_buffer_wide_HBM12, s_embedding_buffer_wide_HBM13, 
        s_embedding_buffer_wide_HBM14, s_embedding_buffer_wide_HBM15, 
        s_embedding_buffer_wide_HBM16, s_embedding_buffer_wide_HBM17, 
        s_embedding_buffer_wide_HBM18, s_embedding_buffer_wide_HBM19, 
        s_embedding_buffer_wide_HBM20, s_embedding_buffer_wide_HBM21, 
        s_embedding_buffer_wide_HBM22, s_embedding_buffer_wide_HBM23, 
        s_embedding_buffer_wide_HBM24, s_embedding_buffer_wide_HBM25, 
        s_embedding_buffer_wide_HBM26, s_embedding_buffer_wide_HBM27, 
        s_feature_in);

    replicate_feature_512PEs_200PE<INPUT_SIZE>(
        s_feature_in, 
        s_embedding_table,
        s_feature1_PE0, s_feature1_PE1, s_feature1_PE2, s_feature1_PE3, 
        s_feature1_PE4, s_feature1_PE5, s_feature1_PE6, s_feature1_PE7, 
        s_feature1_PE8, s_feature1_PE9, s_feature1_PE10, s_feature1_PE11, 
        s_feature1_PE12, s_feature1_PE13, s_feature1_PE14, s_feature1_PE15, 
        s_feature1_PE16, s_feature1_PE17, s_feature1_PE18, s_feature1_PE19, 
        s_feature1_PE20, s_feature1_PE21, s_feature1_PE22, s_feature1_PE23, 
        s_feature1_PE24, s_feature1_PE25, s_feature1_PE26, s_feature1_PE27, 
        s_feature1_PE28, s_feature1_PE29, s_feature1_PE30, s_feature1_PE31, 
        s_feature1_PE32, s_feature1_PE33, s_feature1_PE34, s_feature1_PE35, 
        s_feature1_PE36, s_feature1_PE37, s_feature1_PE38, s_feature1_PE39, 
        s_feature1_PE40, s_feature1_PE41, s_feature1_PE42, s_feature1_PE43, 
        s_feature1_PE44, s_feature1_PE45, s_feature1_PE46, s_feature1_PE47, 
        s_feature1_PE48, s_feature1_PE49, s_feature1_PE50, s_feature1_PE51, 
        s_feature1_PE52, s_feature1_PE53, s_feature1_PE54, s_feature1_PE55, 
        s_feature1_PE56, s_feature1_PE57, s_feature1_PE58, s_feature1_PE59, 
        s_feature1_PE60, s_feature1_PE61, s_feature1_PE62, s_feature1_PE63, 
        s_feature1_PE64, s_feature1_PE65, s_feature1_PE66, s_feature1_PE67, 
        s_feature1_PE68, s_feature1_PE69, s_feature1_PE70, s_feature1_PE71, 
        s_feature1_PE72, s_feature1_PE73, s_feature1_PE74, s_feature1_PE75, 
        s_feature1_PE76, s_feature1_PE77, s_feature1_PE78, s_feature1_PE79, 
        s_feature1_PE80, s_feature1_PE81, s_feature1_PE82, s_feature1_PE83, 
        s_feature1_PE84, s_feature1_PE85, s_feature1_PE86, s_feature1_PE87, 
        s_feature1_PE88, s_feature1_PE89, s_feature1_PE90, s_feature1_PE91, 
        s_feature1_PE92, s_feature1_PE93, s_feature1_PE94, s_feature1_PE95, 
        s_feature1_PE96, s_feature1_PE97, s_feature1_PE98, s_feature1_PE99, 
        s_feature1_PE100, s_feature1_PE101, s_feature1_PE102, s_feature1_PE103, 
        s_feature1_PE104, s_feature1_PE105, s_feature1_PE106, s_feature1_PE107, 
        s_feature1_PE108, s_feature1_PE109, s_feature1_PE110, s_feature1_PE111, 
        s_feature1_PE112, s_feature1_PE113, s_feature1_PE114, s_feature1_PE115, 
        s_feature1_PE116, s_feature1_PE117, s_feature1_PE118, s_feature1_PE119, 
        s_feature1_PE120, s_feature1_PE121, s_feature1_PE122, s_feature1_PE123, 
        s_feature1_PE124, s_feature1_PE125, s_feature1_PE126, s_feature1_PE127,
        s_feature1_PE128, s_feature1_PE129, s_feature1_PE130, s_feature1_PE131,
        s_feature1_PE132, s_feature1_PE133, s_feature1_PE134, s_feature1_PE135,
        s_feature1_PE136, s_feature1_PE137, s_feature1_PE138, s_feature1_PE139,
        s_feature1_PE140, s_feature1_PE141, s_feature1_PE142, s_feature1_PE143,
        s_feature1_PE144, s_feature1_PE145, s_feature1_PE146, s_feature1_PE147,
        s_feature1_PE148, s_feature1_PE149, s_feature1_PE150, s_feature1_PE151,
        s_feature1_PE152, s_feature1_PE153, s_feature1_PE154, s_feature1_PE155,
        s_feature1_PE156, s_feature1_PE157, s_feature1_PE158, s_feature1_PE159,
        s_feature1_PE160, s_feature1_PE161, s_feature1_PE162, s_feature1_PE163,
        s_feature1_PE164, s_feature1_PE165, s_feature1_PE166, s_feature1_PE167,
        s_feature1_PE168, s_feature1_PE169, s_feature1_PE170, s_feature1_PE171,
        s_feature1_PE172, s_feature1_PE173, s_feature1_PE174, s_feature1_PE175,
        s_feature1_PE176, s_feature1_PE177, s_feature1_PE178, s_feature1_PE179,
        s_feature1_PE180, s_feature1_PE181, s_feature1_PE182, s_feature1_PE183,
        s_feature1_PE184, s_feature1_PE185, s_feature1_PE186, s_feature1_PE187,
        s_feature1_PE188, s_feature1_PE189, s_feature1_PE190, s_feature1_PE191,
        s_feature1_PE192, s_feature1_PE193, s_feature1_PE194, s_feature1_PE195,
        s_feature1_PE196, s_feature1_PE197, s_feature1_PE198, s_feature1_PE199);

    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE0, s_result1_PE0);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE1, s_result1_PE1);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE2, s_result1_PE2);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE3, s_result1_PE3);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE4, s_result1_PE4);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE5, s_result1_PE5);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE6, s_result1_PE6);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE7, s_result1_PE7);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE8, s_result1_PE8);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE9, s_result1_PE9);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE10, s_result1_PE10);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE11, s_result1_PE11);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE12, s_result1_PE12);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE13, s_result1_PE13);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE14, s_result1_PE14);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE15, s_result1_PE15);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE16, s_result1_PE16);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE17, s_result1_PE17);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE18, s_result1_PE18);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE19, s_result1_PE19);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE20, s_result1_PE20);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE21, s_result1_PE21);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE22, s_result1_PE22);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE23, s_result1_PE23);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE24, s_result1_PE24);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE25, s_result1_PE25);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE26, s_result1_PE26);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE27, s_result1_PE27);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE28, s_result1_PE28);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE29, s_result1_PE29);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE30, s_result1_PE30);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE31, s_result1_PE31);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE32, s_result1_PE32);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE33, s_result1_PE33);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE34, s_result1_PE34);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE35, s_result1_PE35);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE36, s_result1_PE36);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE37, s_result1_PE37);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE38, s_result1_PE38);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE39, s_result1_PE39);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE40, s_result1_PE40);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE41, s_result1_PE41);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE42, s_result1_PE42);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE43, s_result1_PE43);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE44, s_result1_PE44);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE45, s_result1_PE45);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE46, s_result1_PE46);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE47, s_result1_PE47);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE48, s_result1_PE48);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE49, s_result1_PE49);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE50, s_result1_PE50);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE51, s_result1_PE51);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE52, s_result1_PE52);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE53, s_result1_PE53);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE54, s_result1_PE54);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE55, s_result1_PE55);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE56, s_result1_PE56);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE57, s_result1_PE57);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE58, s_result1_PE58);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE59, s_result1_PE59);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE60, s_result1_PE60);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE61, s_result1_PE61);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE62, s_result1_PE62);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE63, s_result1_PE63);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE64, s_result1_PE64);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE65, s_result1_PE65);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE66, s_result1_PE66);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE67, s_result1_PE67);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE68, s_result1_PE68);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE69, s_result1_PE69);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE70, s_result1_PE70);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE71, s_result1_PE71);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE72, s_result1_PE72);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE73, s_result1_PE73);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE74, s_result1_PE74);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE75, s_result1_PE75);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE76, s_result1_PE76);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE77, s_result1_PE77);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE78, s_result1_PE78);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE79, s_result1_PE79);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE80, s_result1_PE80);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE81, s_result1_PE81);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE82, s_result1_PE82);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE83, s_result1_PE83);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE84, s_result1_PE84);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE85, s_result1_PE85);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE86, s_result1_PE86);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE87, s_result1_PE87);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE88, s_result1_PE88);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE89, s_result1_PE89);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE90, s_result1_PE90);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE91, s_result1_PE91);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE92, s_result1_PE92);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE93, s_result1_PE93);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE94, s_result1_PE94);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE95, s_result1_PE95);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE96, s_result1_PE96);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE97, s_result1_PE97);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE98, s_result1_PE98);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE99, s_result1_PE99);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE100, s_result1_PE100);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE101, s_result1_PE101);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE102, s_result1_PE102);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE103, s_result1_PE103);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE104, s_result1_PE104);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE105, s_result1_PE105);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE106, s_result1_PE106);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE107, s_result1_PE107);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE108, s_result1_PE108);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE109, s_result1_PE109);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE110, s_result1_PE110);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE111, s_result1_PE111);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE112, s_result1_PE112);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE113, s_result1_PE113);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE114, s_result1_PE114);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE115, s_result1_PE115);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE116, s_result1_PE116);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE117, s_result1_PE117);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE118, s_result1_PE118);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE119, s_result1_PE119);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE120, s_result1_PE120);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE121, s_result1_PE121);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE122, s_result1_PE122);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE123, s_result1_PE123);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE124, s_result1_PE124);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE125, s_result1_PE125);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE126, s_result1_PE126);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE127, s_result1_PE127);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE128, s_result1_PE128);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE129, s_result1_PE129);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE130, s_result1_PE130);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE131, s_result1_PE131);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE132, s_result1_PE132);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE133, s_result1_PE133);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE134, s_result1_PE134);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE135, s_result1_PE135);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE136, s_result1_PE136);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE137, s_result1_PE137);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE138, s_result1_PE138);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE139, s_result1_PE139);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE140, s_result1_PE140);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE141, s_result1_PE141);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE142, s_result1_PE142);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE143, s_result1_PE143);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE144, s_result1_PE144);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE145, s_result1_PE145);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE146, s_result1_PE146);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE147, s_result1_PE147);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE148, s_result1_PE148);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE149, s_result1_PE149);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE150, s_result1_PE150);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE151, s_result1_PE151);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE152, s_result1_PE152);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE153, s_result1_PE153);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE154, s_result1_PE154);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE155, s_result1_PE155);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE156, s_result1_PE156);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE157, s_result1_PE157);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE158, s_result1_PE158);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE159, s_result1_PE159);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE160, s_result1_PE160);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE161, s_result1_PE161);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE162, s_result1_PE162);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE163, s_result1_PE163);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE164, s_result1_PE164);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE165, s_result1_PE165);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE166, s_result1_PE166);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE167, s_result1_PE167);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE168, s_result1_PE168);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE169, s_result1_PE169);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE170, s_result1_PE170);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE171, s_result1_PE171);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE172, s_result1_PE172);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE173, s_result1_PE173);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE174, s_result1_PE174);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE175, s_result1_PE175);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE176, s_result1_PE176);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE177, s_result1_PE177);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE178, s_result1_PE178);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE179, s_result1_PE179);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE180, s_result1_PE180);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE181, s_result1_PE181);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE182, s_result1_PE182);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE183, s_result1_PE183);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE184, s_result1_PE184);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE185, s_result1_PE185);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE186, s_result1_PE186);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE187, s_result1_PE187);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE188, s_result1_PE188);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE189, s_result1_PE189);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE190, s_result1_PE190);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE191, s_result1_PE191);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE192, s_result1_PE192);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE193, s_result1_PE193);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE194, s_result1_PE194);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE195, s_result1_PE195);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE196, s_result1_PE196);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE197, s_result1_PE197);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE198, s_result1_PE198);
    matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1>(s_feature1_PE199, s_result1_PE199);

    gather_results_512PEs_200PE<ROW_PER_PE1>(
        s_result1_PE0, s_result1_PE1, s_result1_PE2, s_result1_PE3, 
        s_result1_PE4, s_result1_PE5, s_result1_PE6, s_result1_PE7, 
        s_result1_PE8, s_result1_PE9, s_result1_PE10, s_result1_PE11, 
        s_result1_PE12, s_result1_PE13, s_result1_PE14, s_result1_PE15, 
        s_result1_PE16, s_result1_PE17, s_result1_PE18, s_result1_PE19, 
        s_result1_PE20, s_result1_PE21, s_result1_PE22, s_result1_PE23, 
        s_result1_PE24, s_result1_PE25, s_result1_PE26, s_result1_PE27, 
        s_result1_PE28, s_result1_PE29, s_result1_PE30, s_result1_PE31, 
        s_result1_PE32, s_result1_PE33, s_result1_PE34, s_result1_PE35, 
        s_result1_PE36, s_result1_PE37, s_result1_PE38, s_result1_PE39, 
        s_result1_PE40, s_result1_PE41, s_result1_PE42, s_result1_PE43, 
        s_result1_PE44, s_result1_PE45, s_result1_PE46, s_result1_PE47, 
        s_result1_PE48, s_result1_PE49, s_result1_PE50, s_result1_PE51, 
        s_result1_PE52, s_result1_PE53, s_result1_PE54, s_result1_PE55, 
        s_result1_PE56, s_result1_PE57, s_result1_PE58, s_result1_PE59, 
        s_result1_PE60, s_result1_PE61, s_result1_PE62, s_result1_PE63, 
        s_result1_PE64, s_result1_PE65, s_result1_PE66, s_result1_PE67, 
        s_result1_PE68, s_result1_PE69, s_result1_PE70, s_result1_PE71, 
        s_result1_PE72, s_result1_PE73, s_result1_PE74, s_result1_PE75, 
        s_result1_PE76, s_result1_PE77, s_result1_PE78, s_result1_PE79, 
        s_result1_PE80, s_result1_PE81, s_result1_PE82, s_result1_PE83, 
        s_result1_PE84, s_result1_PE85, s_result1_PE86, s_result1_PE87, 
        s_result1_PE88, s_result1_PE89, s_result1_PE90, s_result1_PE91, 
        s_result1_PE92, s_result1_PE93, s_result1_PE94, s_result1_PE95, 
        s_result1_PE96, s_result1_PE97, s_result1_PE98, s_result1_PE99, 
        s_result1_PE100, s_result1_PE101, s_result1_PE102, s_result1_PE103, 
        s_result1_PE104, s_result1_PE105, s_result1_PE106, s_result1_PE107, 
        s_result1_PE108, s_result1_PE109, s_result1_PE110, s_result1_PE111, 
        s_result1_PE112, s_result1_PE113, s_result1_PE114, s_result1_PE115, 
        s_result1_PE116, s_result1_PE117, s_result1_PE118, s_result1_PE119, 
        s_result1_PE120, s_result1_PE121, s_result1_PE122, s_result1_PE123, 
        s_result1_PE124, s_result1_PE125, s_result1_PE126, s_result1_PE127,
        s_result1_PE128, s_result1_PE129, s_result1_PE130, s_result1_PE131,
        s_result1_PE132, s_result1_PE133, s_result1_PE134, s_result1_PE135,
        s_result1_PE136, s_result1_PE137, s_result1_PE138, s_result1_PE139,
        s_result1_PE140, s_result1_PE141, s_result1_PE142, s_result1_PE143,
        s_result1_PE144, s_result1_PE145, s_result1_PE146, s_result1_PE147,
        s_result1_PE148, s_result1_PE149, s_result1_PE150, s_result1_PE151,
        s_result1_PE152, s_result1_PE153, s_result1_PE154, s_result1_PE155,
        s_result1_PE156, s_result1_PE157, s_result1_PE158, s_result1_PE159,
        s_result1_PE160, s_result1_PE161, s_result1_PE162, s_result1_PE163,
        s_result1_PE164, s_result1_PE165, s_result1_PE166, s_result1_PE167,
        s_result1_PE168, s_result1_PE169, s_result1_PE170, s_result1_PE171,
        s_result1_PE172, s_result1_PE173, s_result1_PE174, s_result1_PE175,
        s_result1_PE176, s_result1_PE177, s_result1_PE178, s_result1_PE179,
        s_result1_PE180, s_result1_PE181, s_result1_PE182, s_result1_PE183,
        s_result1_PE184, s_result1_PE185, s_result1_PE186, s_result1_PE187,
        s_result1_PE188, s_result1_PE189, s_result1_PE190, s_result1_PE191,
        s_result1_PE192, s_result1_PE193, s_result1_PE194, s_result1_PE195,
        s_result1_PE196, s_result1_PE197, s_result1_PE198, s_result1_PE199,
        s_result1_partial);

    //dataTransform(s_result1_partial, s_data_in);
    //dataTransform_writeResult(s_result1_partial, s_data_in, out_PLRAM);
    //dataTransform_writeResult(s_embedding_table, s_result1_partial, s_data_in, out_PLRAM);
    dataTransform(s_embedding_table, s_result1_partial, s_data_in);
////////////////////////////////////////////////////////////////////////////////////////

    sendData( m_axis_tcp_tx_meta, m_axis_tcp_tx_data, s_axis_tcp_tx_status,sessionID, s_data_in, useConn, expectedTxPkgCnt, pkgWordCount);
         

    tie_off_udp(s_axis_udp_rx, 
              m_axis_udp_tx, 
              s_axis_udp_rx_meta, 
              m_axis_udp_tx_meta);


    tie_off_tcp_listen_port( m_axis_tcp_listen_port, 
              s_axis_tcp_port_status);

         
    tie_off_tcp_rx(s_axis_tcp_notification, 
              m_axis_tcp_read_pkg, 
              s_axis_tcp_rx_meta, 
              s_axis_tcp_rx_data);

    tie_off_tcp_close_con(m_axis_tcp_close_connection);

    }
}