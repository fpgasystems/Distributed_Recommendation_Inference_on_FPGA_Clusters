
#include "ap_axi_sdata.h"
#include <ap_fixed.h>
#include "ap_int.h" 
#include "../../../../common/include/communication.hpp"
#include "hls_stream.h"

extern "C" {
void hls_bil_krnl(
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
               // parameters for receiving data
               int useConn_recv, 
               int basePort_recv, 
               int expectedRxByteCnt
               // parameters for sending data
               int useConn_send, 
               int pkgWordCount_send, 
               int basePort_send, 
               int expectedTxPkgCnt, 
               int baseIpAddress_send
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
// Receiving data
#pragma HLS INTERFACE s_axilite port=useConn_recv bundle = control
#pragma HLS INTERFACE s_axilite port=basePort_recv bundle = control
#pragma HLS INTERFACE s_axilite port=expectedRxByteCnt bundle = control
// Sending data
#pragma HLS INTERFACE s_axilite port=useConn_send bundle = control
#pragma HLS INTERFACE s_axilite port=pkgWordCount_send bundle = control
#pragma HLS INTERFACE s_axilite port=basePort_send bundle = control
#pragma HLS INTERFACE s_axilite port=expectedTxPkgCnt bundle = control
#pragma HLS INTERFACE s_axilite port=baseIpAddress_send bundle=control

#pragma HLS INTERFACE s_axilite port = return bundle = control

// store data temporarily
static hls::stream<ap_uint<512> >    s_data_in;
#pragma HLS STREAM variable=s_data_in depth=512

          ap_uint<16> sessionID [128];
          
          openConnections( useConn_send, baseIpAddress_send, basePort_send, m_axis_tcp_open_connection, s_axis_tcp_open_status, sessionID);

// set a intermediate result to store data that received
// then send data

#pragma HLS dataflow

          listenPorts (basePort_recv, useConn_recv, m_axis_tcp_listen_port, 
               s_axis_tcp_port_status);

          recvDataBilateral(expectedRxByteCnt, 
               s_axis_tcp_notification, 
               m_axis_tcp_read_pkg, 
               s_axis_tcp_rx_meta, 
               s_axis_tcp_rx_data,
               s_data_in);
     
          sendData( m_axis_tcp_tx_meta, m_axis_tcp_tx_data, s_axis_tcp_tx_status,sessionID, s_data_in, useConn, expectedTxPkgCnt, pkgWordCount);
//          tie_off_tcp_open_connection//(m_axis_tcp_open_connection, 
//               s_axis_tcp_open_status);
//
//
//          tie_off_tcp_tx(m_axis_tcp_tx_meta, 
//                         m_axis_tcp_tx_data, 
//                         s_axis_tcp_tx_status);
//
          tie_off_udp(s_axis_udp_rx, 
               m_axis_udp_tx, 
               s_axis_udp_rx_meta, 
               m_axis_udp_tx_meta);
    
          tie_off_tcp_close_con(m_axis_tcp_close_connection);

     }
}