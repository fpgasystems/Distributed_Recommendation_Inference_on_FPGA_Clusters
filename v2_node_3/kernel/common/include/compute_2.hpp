#include <hls_stream.h>
#include "constants.hpp"

void recvDataTransform(hls::stream<ap_uint<512> > & s_data_in, hls::stream<ap_uint<512> > & s_feature_in, hls::stream<ap_uint<512> > & s_result1_partial);

void recvDataTransform_1(hls::stream<ap_uint<512> > & s_data_in, hls::stream<ap_uint<512> > & s_feature_in_1, hls::stream<ap_uint<512> > & s_result1_all);

void recvDataTransform_4(hls::stream<ap_uint<512> > & s_data_in, hls::stream<ap_uint<512> > & s_feature_in_0, hls::stream<ap_uint<512> > & s_feature_in_1, hls::stream<ap_uint<512> > & s_feature_in_2, hls::stream<ap_uint<512> > & s_feature_in_3, hls::stream<ap_uint<512> > & s_result1_all);

void recvDataTransform_8(
    hls::stream<ap_uint<512> > & s_data_in, 
    hls::stream<ap_uint<512> > & s_feature_in_0, hls::stream<ap_uint<512> > & s_feature_in_1, 
    hls::stream<ap_uint<512> > & s_feature_in_2, hls::stream<ap_uint<512> > & s_feature_in_3, 
    hls::stream<ap_uint<512> > & s_feature_in_4, hls::stream<ap_uint<512> > & s_feature_in_5, 
    hls::stream<ap_uint<512> > & s_feature_in_6, hls::stream<ap_uint<512> > & s_feature_in_7, 
    hls::stream<ap_uint<512> > & s_result1_all);

void recvDataTransform_10(
    hls::stream<ap_uint<512> > & s_data_in, 
    hls::stream<ap_uint<512> > & s_feature_in_0, hls::stream<ap_uint<512> > & s_feature_in_1, 
    hls::stream<ap_uint<512> > & s_feature_in_2, hls::stream<ap_uint<512> > & s_feature_in_3, 
    hls::stream<ap_uint<512> > & s_feature_in_4, hls::stream<ap_uint<512> > & s_feature_in_5, 
    hls::stream<ap_uint<512> > & s_feature_in_6, hls::stream<ap_uint<512> > & s_feature_in_7, 
    hls::stream<ap_uint<512> > & s_feature_in_8, hls::stream<ap_uint<512> > & s_feature_in_9, 
    hls::stream<ap_uint<512> > & s_result1_all);

void replicate_feature_in_6(
    hls::stream<ap_uint<512> > & s_feature_in, 
    hls::stream<ap_uint<512> > & s_feature_in_0, hls::stream<ap_uint<512> > & s_feature_in_1, 
    hls::stream<ap_uint<512> > & s_feature_in_2, hls::stream<ap_uint<512> > & s_feature_in_3, 
    hls::stream<ap_uint<512> > & s_feature_in_4, hls::stream<ap_uint<512> > & s_feature_in_5);

void replicate_feature_in_7(
    hls::stream<ap_uint<512> > & s_feature_in, 
    hls::stream<ap_uint<512> > & s_feature_in_0, hls::stream<ap_uint<512> > & s_feature_in_1, 
    hls::stream<ap_uint<512> > & s_feature_in_2, hls::stream<ap_uint<512> > & s_feature_in_3, 
    hls::stream<ap_uint<512> > & s_feature_in_4, hls::stream<ap_uint<512> > & s_feature_in_5,
    hls::stream<ap_uint<512> > & s_feature_in_6);

void replicate_feature_in_16(
    hls::stream<ap_uint<512> > & s_feature_in, 
    hls::stream<ap_uint<512> > & s_feature_in_0, hls::stream<ap_uint<512> > & s_feature_in_1, 
    hls::stream<ap_uint<512> > & s_feature_in_2, hls::stream<ap_uint<512> > & s_feature_in_3, 
    hls::stream<ap_uint<512> > & s_feature_in_4, hls::stream<ap_uint<512> > & s_feature_in_5, 
    hls::stream<ap_uint<512> > & s_feature_in_6, hls::stream<ap_uint<512> > & s_feature_in_7, 
    hls::stream<ap_uint<512> > & s_feature_in_8, hls::stream<ap_uint<512> > & s_feature_in_9, 
    hls::stream<ap_uint<512> > & s_feature_in_10, hls::stream<ap_uint<512> > & s_feature_in_11, 
    hls::stream<ap_uint<512> > & s_feature_in_12, hls::stream<ap_uint<512> > & s_feature_in_13, 
    hls::stream<ap_uint<512> > & s_feature_in_14, hls::stream<ap_uint<512> > & s_feature_in_15);

template<const int FEATURE_SIZE, const int INDEX_ROW>
void matmul_PE_UNROLL8_layer1(
    hls::stream<W_TYPE>& s_feature_PE_0,
    hls::stream<W_TYPE>& s_feature_PE_1,
    hls::stream<D_TYPE>& s_result_PE);

template<const int FEATURE_SIZE, const int INDEX_ROW>
void matmul_PE_UNROLL8_layer2(
    hls::stream<W_TYPE>& s_feature_PE_0,
    hls::stream<W_TYPE>& s_feature_PE_1,
    hls::stream<D_TYPE>& s_result_PE);

template<const int FEATURE_SIZE, const int INDEX_ROW>
void init_weights(W_TYPE* weights_transpose); 

template<>
void init_weights<INPUT_SIZE, INDEX_EVEN>(W_TYPE* weights_transpose_local);

template<>
void init_weights<INPUT_SIZE, INDEX_ODD>(W_TYPE* weights_transpose_local);

template<>
void init_weights<HIDDEN_SIZE1, INDEX_EVEN>(W_TYPE* weights_transpose_local);

template<>
void init_weights<HIDDEN_SIZE1, INDEX_ODD>(W_TYPE* weights_transpose_local);

template<const int FEATURE_SIZE>
void replicate_feature_512PEs_320PE(
    hls::stream<ap_uint<512> >& s_feature_in, 
    hls::stream<W_TYPE>& s_feature_PE0_0, hls::stream<W_TYPE>& s_feature_PE0_1,
    hls::stream<W_TYPE>& s_feature_PE0_2, hls::stream<W_TYPE>& s_feature_PE0_3,
    hls::stream<W_TYPE>& s_feature_PE1_0, hls::stream<W_TYPE>& s_feature_PE1_1,
    hls::stream<W_TYPE>& s_feature_PE1_2, hls::stream<W_TYPE>& s_feature_PE1_3,
    hls::stream<W_TYPE>& s_feature_PE2_0, hls::stream<W_TYPE>& s_feature_PE2_1,
    hls::stream<W_TYPE>& s_feature_PE2_2, hls::stream<W_TYPE>& s_feature_PE2_3,
    hls::stream<W_TYPE>& s_feature_PE3_0, hls::stream<W_TYPE>& s_feature_PE3_1,
    hls::stream<W_TYPE>& s_feature_PE3_2, hls::stream<W_TYPE>& s_feature_PE3_3,
    hls::stream<W_TYPE>& s_feature_PE4_0, hls::stream<W_TYPE>& s_feature_PE4_1,
    hls::stream<W_TYPE>& s_feature_PE4_2, hls::stream<W_TYPE>& s_feature_PE4_3,
    hls::stream<W_TYPE>& s_feature_PE5_0, hls::stream<W_TYPE>& s_feature_PE5_1,
    hls::stream<W_TYPE>& s_feature_PE5_2, hls::stream<W_TYPE>& s_feature_PE5_3,
    hls::stream<W_TYPE>& s_feature_PE6_0, hls::stream<W_TYPE>& s_feature_PE6_1,
    hls::stream<W_TYPE>& s_feature_PE6_2, hls::stream<W_TYPE>& s_feature_PE6_3,
    hls::stream<W_TYPE>& s_feature_PE7_0, hls::stream<W_TYPE>& s_feature_PE7_1,
    hls::stream<W_TYPE>& s_feature_PE7_2, hls::stream<W_TYPE>& s_feature_PE7_3,
    hls::stream<W_TYPE>& s_feature_PE8_0, hls::stream<W_TYPE>& s_feature_PE8_1,
    hls::stream<W_TYPE>& s_feature_PE8_2, hls::stream<W_TYPE>& s_feature_PE8_3,
    hls::stream<W_TYPE>& s_feature_PE9_0, hls::stream<W_TYPE>& s_feature_PE9_1,
    hls::stream<W_TYPE>& s_feature_PE9_2, hls::stream<W_TYPE>& s_feature_PE9_3,
    hls::stream<W_TYPE>& s_feature_PE10_0, hls::stream<W_TYPE>& s_feature_PE10_1,
    hls::stream<W_TYPE>& s_feature_PE10_2, hls::stream<W_TYPE>& s_feature_PE10_3,
    hls::stream<W_TYPE>& s_feature_PE11_0, hls::stream<W_TYPE>& s_feature_PE11_1,
    hls::stream<W_TYPE>& s_feature_PE11_2, hls::stream<W_TYPE>& s_feature_PE11_3,
    hls::stream<W_TYPE>& s_feature_PE12_0, hls::stream<W_TYPE>& s_feature_PE12_1,
    hls::stream<W_TYPE>& s_feature_PE12_2, hls::stream<W_TYPE>& s_feature_PE12_3,
    hls::stream<W_TYPE>& s_feature_PE13_0, hls::stream<W_TYPE>& s_feature_PE13_1,
    hls::stream<W_TYPE>& s_feature_PE13_2, hls::stream<W_TYPE>& s_feature_PE13_3,
    hls::stream<W_TYPE>& s_feature_PE14_0, hls::stream<W_TYPE>& s_feature_PE14_1,
    hls::stream<W_TYPE>& s_feature_PE14_2, hls::stream<W_TYPE>& s_feature_PE14_3,
    hls::stream<W_TYPE>& s_feature_PE15_0, hls::stream<W_TYPE>& s_feature_PE15_1,
    hls::stream<W_TYPE>& s_feature_PE15_2, hls::stream<W_TYPE>& s_feature_PE15_3,
    hls::stream<W_TYPE>& s_feature_PE16_0, hls::stream<W_TYPE>& s_feature_PE16_1,
    hls::stream<W_TYPE>& s_feature_PE16_2, hls::stream<W_TYPE>& s_feature_PE16_3,
    hls::stream<W_TYPE>& s_feature_PE17_0, hls::stream<W_TYPE>& s_feature_PE17_1,
    hls::stream<W_TYPE>& s_feature_PE17_2, hls::stream<W_TYPE>& s_feature_PE17_3,
    hls::stream<W_TYPE>& s_feature_PE18_0, hls::stream<W_TYPE>& s_feature_PE18_1,
    hls::stream<W_TYPE>& s_feature_PE18_2, hls::stream<W_TYPE>& s_feature_PE18_3,
    hls::stream<W_TYPE>& s_feature_PE19_0, hls::stream<W_TYPE>& s_feature_PE19_1,
    hls::stream<W_TYPE>& s_feature_PE19_2, hls::stream<W_TYPE>& s_feature_PE19_3,
    hls::stream<W_TYPE>& s_feature_PE20_0, hls::stream<W_TYPE>& s_feature_PE20_1,
    hls::stream<W_TYPE>& s_feature_PE20_2, hls::stream<W_TYPE>& s_feature_PE20_3,
    hls::stream<W_TYPE>& s_feature_PE21_0, hls::stream<W_TYPE>& s_feature_PE21_1,
    hls::stream<W_TYPE>& s_feature_PE21_2, hls::stream<W_TYPE>& s_feature_PE21_3,
    hls::stream<W_TYPE>& s_feature_PE22_0, hls::stream<W_TYPE>& s_feature_PE22_1,
    hls::stream<W_TYPE>& s_feature_PE22_2, hls::stream<W_TYPE>& s_feature_PE22_3,
    hls::stream<W_TYPE>& s_feature_PE23_0, hls::stream<W_TYPE>& s_feature_PE23_1,
    hls::stream<W_TYPE>& s_feature_PE23_2, hls::stream<W_TYPE>& s_feature_PE23_3,
    hls::stream<W_TYPE>& s_feature_PE24_0, hls::stream<W_TYPE>& s_feature_PE24_1,
    hls::stream<W_TYPE>& s_feature_PE24_2, hls::stream<W_TYPE>& s_feature_PE24_3,
    hls::stream<W_TYPE>& s_feature_PE25_0, hls::stream<W_TYPE>& s_feature_PE25_1,
    hls::stream<W_TYPE>& s_feature_PE25_2, hls::stream<W_TYPE>& s_feature_PE25_3,
    hls::stream<W_TYPE>& s_feature_PE26_0, hls::stream<W_TYPE>& s_feature_PE26_1,
    hls::stream<W_TYPE>& s_feature_PE26_2, hls::stream<W_TYPE>& s_feature_PE26_3,
    hls::stream<W_TYPE>& s_feature_PE27_0, hls::stream<W_TYPE>& s_feature_PE27_1,
    hls::stream<W_TYPE>& s_feature_PE27_2, hls::stream<W_TYPE>& s_feature_PE27_3,
    hls::stream<W_TYPE>& s_feature_PE28_0, hls::stream<W_TYPE>& s_feature_PE28_1,
    hls::stream<W_TYPE>& s_feature_PE28_2, hls::stream<W_TYPE>& s_feature_PE28_3,
    hls::stream<W_TYPE>& s_feature_PE29_0, hls::stream<W_TYPE>& s_feature_PE29_1,
    hls::stream<W_TYPE>& s_feature_PE29_2, hls::stream<W_TYPE>& s_feature_PE29_3,
    hls::stream<W_TYPE>& s_feature_PE30_0, hls::stream<W_TYPE>& s_feature_PE30_1,
    hls::stream<W_TYPE>& s_feature_PE30_2, hls::stream<W_TYPE>& s_feature_PE30_3,
    hls::stream<W_TYPE>& s_feature_PE31_0, hls::stream<W_TYPE>& s_feature_PE31_1,
    hls::stream<W_TYPE>& s_feature_PE31_2, hls::stream<W_TYPE>& s_feature_PE31_3,
    hls::stream<W_TYPE>& s_feature_PE32_0, hls::stream<W_TYPE>& s_feature_PE32_1,
    hls::stream<W_TYPE>& s_feature_PE32_2, hls::stream<W_TYPE>& s_feature_PE32_3,
    hls::stream<W_TYPE>& s_feature_PE33_0, hls::stream<W_TYPE>& s_feature_PE33_1,
    hls::stream<W_TYPE>& s_feature_PE33_2, hls::stream<W_TYPE>& s_feature_PE33_3,
    hls::stream<W_TYPE>& s_feature_PE34_0, hls::stream<W_TYPE>& s_feature_PE34_1,
    hls::stream<W_TYPE>& s_feature_PE34_2, hls::stream<W_TYPE>& s_feature_PE34_3,
    hls::stream<W_TYPE>& s_feature_PE35_0, hls::stream<W_TYPE>& s_feature_PE35_1,
    hls::stream<W_TYPE>& s_feature_PE35_2, hls::stream<W_TYPE>& s_feature_PE35_3,
    hls::stream<W_TYPE>& s_feature_PE36_0, hls::stream<W_TYPE>& s_feature_PE36_1,
    hls::stream<W_TYPE>& s_feature_PE36_2, hls::stream<W_TYPE>& s_feature_PE36_3,
    hls::stream<W_TYPE>& s_feature_PE37_0, hls::stream<W_TYPE>& s_feature_PE37_1,
    hls::stream<W_TYPE>& s_feature_PE37_2, hls::stream<W_TYPE>& s_feature_PE37_3,
    hls::stream<W_TYPE>& s_feature_PE38_0, hls::stream<W_TYPE>& s_feature_PE38_1,
    hls::stream<W_TYPE>& s_feature_PE38_2, hls::stream<W_TYPE>& s_feature_PE38_3,
    hls::stream<W_TYPE>& s_feature_PE39_0, hls::stream<W_TYPE>& s_feature_PE39_1,
    hls::stream<W_TYPE>& s_feature_PE39_2, hls::stream<W_TYPE>& s_feature_PE39_3,
    hls::stream<W_TYPE>& s_feature_PE40_0, hls::stream<W_TYPE>& s_feature_PE40_1,
    hls::stream<W_TYPE>& s_feature_PE40_2, hls::stream<W_TYPE>& s_feature_PE40_3,
    hls::stream<W_TYPE>& s_feature_PE41_0, hls::stream<W_TYPE>& s_feature_PE41_1,
    hls::stream<W_TYPE>& s_feature_PE41_2, hls::stream<W_TYPE>& s_feature_PE41_3,
    hls::stream<W_TYPE>& s_feature_PE42_0, hls::stream<W_TYPE>& s_feature_PE42_1,
    hls::stream<W_TYPE>& s_feature_PE42_2, hls::stream<W_TYPE>& s_feature_PE42_3,
    hls::stream<W_TYPE>& s_feature_PE43_0, hls::stream<W_TYPE>& s_feature_PE43_1,
    hls::stream<W_TYPE>& s_feature_PE43_2, hls::stream<W_TYPE>& s_feature_PE43_3,
    hls::stream<W_TYPE>& s_feature_PE44_0, hls::stream<W_TYPE>& s_feature_PE44_1,
    hls::stream<W_TYPE>& s_feature_PE44_2, hls::stream<W_TYPE>& s_feature_PE44_3,
    hls::stream<W_TYPE>& s_feature_PE45_0, hls::stream<W_TYPE>& s_feature_PE45_1,
    hls::stream<W_TYPE>& s_feature_PE45_2, hls::stream<W_TYPE>& s_feature_PE45_3,
    hls::stream<W_TYPE>& s_feature_PE46_0, hls::stream<W_TYPE>& s_feature_PE46_1,
    hls::stream<W_TYPE>& s_feature_PE46_2, hls::stream<W_TYPE>& s_feature_PE46_3,
    hls::stream<W_TYPE>& s_feature_PE47_0, hls::stream<W_TYPE>& s_feature_PE47_1,
    hls::stream<W_TYPE>& s_feature_PE47_2, hls::stream<W_TYPE>& s_feature_PE47_3,
    hls::stream<W_TYPE>& s_feature_PE48_0, hls::stream<W_TYPE>& s_feature_PE48_1,
    hls::stream<W_TYPE>& s_feature_PE48_2, hls::stream<W_TYPE>& s_feature_PE48_3,
    hls::stream<W_TYPE>& s_feature_PE49_0, hls::stream<W_TYPE>& s_feature_PE49_1,
    hls::stream<W_TYPE>& s_feature_PE49_2, hls::stream<W_TYPE>& s_feature_PE49_3,
    hls::stream<W_TYPE>& s_feature_PE50_0, hls::stream<W_TYPE>& s_feature_PE50_1,
    hls::stream<W_TYPE>& s_feature_PE50_2, hls::stream<W_TYPE>& s_feature_PE50_3,
    hls::stream<W_TYPE>& s_feature_PE51_0, hls::stream<W_TYPE>& s_feature_PE51_1,
    hls::stream<W_TYPE>& s_feature_PE51_2, hls::stream<W_TYPE>& s_feature_PE51_3,
    hls::stream<W_TYPE>& s_feature_PE52_0, hls::stream<W_TYPE>& s_feature_PE52_1,
    hls::stream<W_TYPE>& s_feature_PE52_2, hls::stream<W_TYPE>& s_feature_PE52_3,
    hls::stream<W_TYPE>& s_feature_PE53_0, hls::stream<W_TYPE>& s_feature_PE53_1,
    hls::stream<W_TYPE>& s_feature_PE53_2, hls::stream<W_TYPE>& s_feature_PE53_3,
    hls::stream<W_TYPE>& s_feature_PE54_0, hls::stream<W_TYPE>& s_feature_PE54_1,
    hls::stream<W_TYPE>& s_feature_PE54_2, hls::stream<W_TYPE>& s_feature_PE54_3,
    hls::stream<W_TYPE>& s_feature_PE55_0, hls::stream<W_TYPE>& s_feature_PE55_1,
    hls::stream<W_TYPE>& s_feature_PE55_2, hls::stream<W_TYPE>& s_feature_PE55_3,
    hls::stream<W_TYPE>& s_feature_PE56_0, hls::stream<W_TYPE>& s_feature_PE56_1,
    hls::stream<W_TYPE>& s_feature_PE56_2, hls::stream<W_TYPE>& s_feature_PE56_3,
    hls::stream<W_TYPE>& s_feature_PE57_0, hls::stream<W_TYPE>& s_feature_PE57_1,
    hls::stream<W_TYPE>& s_feature_PE57_2, hls::stream<W_TYPE>& s_feature_PE57_3,
    hls::stream<W_TYPE>& s_feature_PE58_0, hls::stream<W_TYPE>& s_feature_PE58_1,
    hls::stream<W_TYPE>& s_feature_PE58_2, hls::stream<W_TYPE>& s_feature_PE58_3,
    hls::stream<W_TYPE>& s_feature_PE59_0, hls::stream<W_TYPE>& s_feature_PE59_1,
    hls::stream<W_TYPE>& s_feature_PE59_2, hls::stream<W_TYPE>& s_feature_PE59_3,
    hls::stream<W_TYPE>& s_feature_PE60_0, hls::stream<W_TYPE>& s_feature_PE60_1,
    hls::stream<W_TYPE>& s_feature_PE60_2, hls::stream<W_TYPE>& s_feature_PE60_3,
    hls::stream<W_TYPE>& s_feature_PE61_0, hls::stream<W_TYPE>& s_feature_PE61_1,
    hls::stream<W_TYPE>& s_feature_PE61_2, hls::stream<W_TYPE>& s_feature_PE61_3,
    hls::stream<W_TYPE>& s_feature_PE62_0, hls::stream<W_TYPE>& s_feature_PE62_1,
    hls::stream<W_TYPE>& s_feature_PE62_2, hls::stream<W_TYPE>& s_feature_PE62_3,
    hls::stream<W_TYPE>& s_feature_PE63_0, hls::stream<W_TYPE>& s_feature_PE63_1,
    hls::stream<W_TYPE>& s_feature_PE63_2, hls::stream<W_TYPE>& s_feature_PE63_3,
    hls::stream<W_TYPE>& s_feature_PE64_0, hls::stream<W_TYPE>& s_feature_PE64_1,
    hls::stream<W_TYPE>& s_feature_PE64_2, hls::stream<W_TYPE>& s_feature_PE64_3,
    hls::stream<W_TYPE>& s_feature_PE65_0, hls::stream<W_TYPE>& s_feature_PE65_1,
    hls::stream<W_TYPE>& s_feature_PE65_2, hls::stream<W_TYPE>& s_feature_PE65_3,
    hls::stream<W_TYPE>& s_feature_PE66_0, hls::stream<W_TYPE>& s_feature_PE66_1,
    hls::stream<W_TYPE>& s_feature_PE66_2, hls::stream<W_TYPE>& s_feature_PE66_3,
    hls::stream<W_TYPE>& s_feature_PE67_0, hls::stream<W_TYPE>& s_feature_PE67_1,
    hls::stream<W_TYPE>& s_feature_PE67_2, hls::stream<W_TYPE>& s_feature_PE67_3,
    hls::stream<W_TYPE>& s_feature_PE68_0, hls::stream<W_TYPE>& s_feature_PE68_1,
    hls::stream<W_TYPE>& s_feature_PE68_2, hls::stream<W_TYPE>& s_feature_PE68_3,
    hls::stream<W_TYPE>& s_feature_PE69_0, hls::stream<W_TYPE>& s_feature_PE69_1,
    hls::stream<W_TYPE>& s_feature_PE69_2, hls::stream<W_TYPE>& s_feature_PE69_3,
    hls::stream<W_TYPE>& s_feature_PE70_0, hls::stream<W_TYPE>& s_feature_PE70_1,
    hls::stream<W_TYPE>& s_feature_PE70_2, hls::stream<W_TYPE>& s_feature_PE70_3,
    hls::stream<W_TYPE>& s_feature_PE71_0, hls::stream<W_TYPE>& s_feature_PE71_1,
    hls::stream<W_TYPE>& s_feature_PE71_2, hls::stream<W_TYPE>& s_feature_PE71_3,
    hls::stream<W_TYPE>& s_feature_PE72_0, hls::stream<W_TYPE>& s_feature_PE72_1,
    hls::stream<W_TYPE>& s_feature_PE72_2, hls::stream<W_TYPE>& s_feature_PE72_3,
    hls::stream<W_TYPE>& s_feature_PE73_0, hls::stream<W_TYPE>& s_feature_PE73_1,
    hls::stream<W_TYPE>& s_feature_PE73_2, hls::stream<W_TYPE>& s_feature_PE73_3,
    hls::stream<W_TYPE>& s_feature_PE74_0, hls::stream<W_TYPE>& s_feature_PE74_1,
    hls::stream<W_TYPE>& s_feature_PE74_2, hls::stream<W_TYPE>& s_feature_PE74_3,
    hls::stream<W_TYPE>& s_feature_PE75_0, hls::stream<W_TYPE>& s_feature_PE75_1,
    hls::stream<W_TYPE>& s_feature_PE75_2, hls::stream<W_TYPE>& s_feature_PE75_3,
    hls::stream<W_TYPE>& s_feature_PE76_0, hls::stream<W_TYPE>& s_feature_PE76_1,
    hls::stream<W_TYPE>& s_feature_PE76_2, hls::stream<W_TYPE>& s_feature_PE76_3,
    hls::stream<W_TYPE>& s_feature_PE77_0, hls::stream<W_TYPE>& s_feature_PE77_1,
    hls::stream<W_TYPE>& s_feature_PE77_2, hls::stream<W_TYPE>& s_feature_PE77_3,
    hls::stream<W_TYPE>& s_feature_PE78_0, hls::stream<W_TYPE>& s_feature_PE78_1,
    hls::stream<W_TYPE>& s_feature_PE78_2, hls::stream<W_TYPE>& s_feature_PE78_3,
    hls::stream<W_TYPE>& s_feature_PE79_0, hls::stream<W_TYPE>& s_feature_PE79_1,
    hls::stream<W_TYPE>& s_feature_PE79_2, hls::stream<W_TYPE>& s_feature_PE79_3,
    hls::stream<W_TYPE>& s_feature_PE80_0, hls::stream<W_TYPE>& s_feature_PE80_1,
    hls::stream<W_TYPE>& s_feature_PE80_2, hls::stream<W_TYPE>& s_feature_PE80_3,
    hls::stream<W_TYPE>& s_feature_PE81_0, hls::stream<W_TYPE>& s_feature_PE81_1,
    hls::stream<W_TYPE>& s_feature_PE81_2, hls::stream<W_TYPE>& s_feature_PE81_3,
    hls::stream<W_TYPE>& s_feature_PE82_0, hls::stream<W_TYPE>& s_feature_PE82_1,
    hls::stream<W_TYPE>& s_feature_PE82_2, hls::stream<W_TYPE>& s_feature_PE82_3,
    hls::stream<W_TYPE>& s_feature_PE83_0, hls::stream<W_TYPE>& s_feature_PE83_1,
    hls::stream<W_TYPE>& s_feature_PE83_2, hls::stream<W_TYPE>& s_feature_PE83_3,
    hls::stream<W_TYPE>& s_feature_PE84_0, hls::stream<W_TYPE>& s_feature_PE84_1,
    hls::stream<W_TYPE>& s_feature_PE84_2, hls::stream<W_TYPE>& s_feature_PE84_3,
    hls::stream<W_TYPE>& s_feature_PE85_0, hls::stream<W_TYPE>& s_feature_PE85_1,
    hls::stream<W_TYPE>& s_feature_PE85_2, hls::stream<W_TYPE>& s_feature_PE85_3,
    hls::stream<W_TYPE>& s_feature_PE86_0, hls::stream<W_TYPE>& s_feature_PE86_1,
    hls::stream<W_TYPE>& s_feature_PE86_2, hls::stream<W_TYPE>& s_feature_PE86_3,
    hls::stream<W_TYPE>& s_feature_PE87_0, hls::stream<W_TYPE>& s_feature_PE87_1,
    hls::stream<W_TYPE>& s_feature_PE87_2, hls::stream<W_TYPE>& s_feature_PE87_3,
    hls::stream<W_TYPE>& s_feature_PE88_0, hls::stream<W_TYPE>& s_feature_PE88_1,
    hls::stream<W_TYPE>& s_feature_PE88_2, hls::stream<W_TYPE>& s_feature_PE88_3,
    hls::stream<W_TYPE>& s_feature_PE89_0, hls::stream<W_TYPE>& s_feature_PE89_1,
    hls::stream<W_TYPE>& s_feature_PE89_2, hls::stream<W_TYPE>& s_feature_PE89_3,
    hls::stream<W_TYPE>& s_feature_PE90_0, hls::stream<W_TYPE>& s_feature_PE90_1,
    hls::stream<W_TYPE>& s_feature_PE90_2, hls::stream<W_TYPE>& s_feature_PE90_3,
    hls::stream<W_TYPE>& s_feature_PE91_0, hls::stream<W_TYPE>& s_feature_PE91_1,
    hls::stream<W_TYPE>& s_feature_PE91_2, hls::stream<W_TYPE>& s_feature_PE91_3,
    hls::stream<W_TYPE>& s_feature_PE92_0, hls::stream<W_TYPE>& s_feature_PE92_1,
    hls::stream<W_TYPE>& s_feature_PE92_2, hls::stream<W_TYPE>& s_feature_PE92_3,
    hls::stream<W_TYPE>& s_feature_PE93_0, hls::stream<W_TYPE>& s_feature_PE93_1,
    hls::stream<W_TYPE>& s_feature_PE93_2, hls::stream<W_TYPE>& s_feature_PE93_3,
    hls::stream<W_TYPE>& s_feature_PE94_0, hls::stream<W_TYPE>& s_feature_PE94_1,
    hls::stream<W_TYPE>& s_feature_PE94_2, hls::stream<W_TYPE>& s_feature_PE94_3,
    hls::stream<W_TYPE>& s_feature_PE95_0, hls::stream<W_TYPE>& s_feature_PE95_1,
    hls::stream<W_TYPE>& s_feature_PE95_2, hls::stream<W_TYPE>& s_feature_PE95_3,
    hls::stream<W_TYPE>& s_feature_PE96_0, hls::stream<W_TYPE>& s_feature_PE96_1,
    hls::stream<W_TYPE>& s_feature_PE96_2, hls::stream<W_TYPE>& s_feature_PE96_3,
    hls::stream<W_TYPE>& s_feature_PE97_0, hls::stream<W_TYPE>& s_feature_PE97_1,
    hls::stream<W_TYPE>& s_feature_PE97_2, hls::stream<W_TYPE>& s_feature_PE97_3,
    hls::stream<W_TYPE>& s_feature_PE98_0, hls::stream<W_TYPE>& s_feature_PE98_1,
    hls::stream<W_TYPE>& s_feature_PE98_2, hls::stream<W_TYPE>& s_feature_PE98_3,
    hls::stream<W_TYPE>& s_feature_PE99_0, hls::stream<W_TYPE>& s_feature_PE99_1,
    hls::stream<W_TYPE>& s_feature_PE99_2, hls::stream<W_TYPE>& s_feature_PE99_3,
    hls::stream<W_TYPE>& s_feature_PE100_0, hls::stream<W_TYPE>& s_feature_PE100_1,
    hls::stream<W_TYPE>& s_feature_PE100_2, hls::stream<W_TYPE>& s_feature_PE100_3,
    hls::stream<W_TYPE>& s_feature_PE101_0, hls::stream<W_TYPE>& s_feature_PE101_1,
    hls::stream<W_TYPE>& s_feature_PE101_2, hls::stream<W_TYPE>& s_feature_PE101_3,
    hls::stream<W_TYPE>& s_feature_PE102_0, hls::stream<W_TYPE>& s_feature_PE102_1,
    hls::stream<W_TYPE>& s_feature_PE102_2, hls::stream<W_TYPE>& s_feature_PE102_3,
    hls::stream<W_TYPE>& s_feature_PE103_0, hls::stream<W_TYPE>& s_feature_PE103_1,
    hls::stream<W_TYPE>& s_feature_PE103_2, hls::stream<W_TYPE>& s_feature_PE103_3,
    hls::stream<W_TYPE>& s_feature_PE104_0, hls::stream<W_TYPE>& s_feature_PE104_1,
    hls::stream<W_TYPE>& s_feature_PE104_2, hls::stream<W_TYPE>& s_feature_PE104_3,
    hls::stream<W_TYPE>& s_feature_PE105_0, hls::stream<W_TYPE>& s_feature_PE105_1,
    hls::stream<W_TYPE>& s_feature_PE105_2, hls::stream<W_TYPE>& s_feature_PE105_3,
    hls::stream<W_TYPE>& s_feature_PE106_0, hls::stream<W_TYPE>& s_feature_PE106_1,
    hls::stream<W_TYPE>& s_feature_PE106_2, hls::stream<W_TYPE>& s_feature_PE106_3,
    hls::stream<W_TYPE>& s_feature_PE107_0, hls::stream<W_TYPE>& s_feature_PE107_1,
    hls::stream<W_TYPE>& s_feature_PE107_2, hls::stream<W_TYPE>& s_feature_PE107_3,
    hls::stream<W_TYPE>& s_feature_PE108_0, hls::stream<W_TYPE>& s_feature_PE108_1,
    hls::stream<W_TYPE>& s_feature_PE108_2, hls::stream<W_TYPE>& s_feature_PE108_3,
    hls::stream<W_TYPE>& s_feature_PE109_0, hls::stream<W_TYPE>& s_feature_PE109_1,
    hls::stream<W_TYPE>& s_feature_PE109_2, hls::stream<W_TYPE>& s_feature_PE109_3,
    hls::stream<W_TYPE>& s_feature_PE110_0, hls::stream<W_TYPE>& s_feature_PE110_1,
    hls::stream<W_TYPE>& s_feature_PE110_2, hls::stream<W_TYPE>& s_feature_PE110_3,
    hls::stream<W_TYPE>& s_feature_PE111_0, hls::stream<W_TYPE>& s_feature_PE111_1,
    hls::stream<W_TYPE>& s_feature_PE111_2, hls::stream<W_TYPE>& s_feature_PE111_3,
    hls::stream<W_TYPE>& s_feature_PE112_0, hls::stream<W_TYPE>& s_feature_PE112_1,
    hls::stream<W_TYPE>& s_feature_PE112_2, hls::stream<W_TYPE>& s_feature_PE112_3,
    hls::stream<W_TYPE>& s_feature_PE113_0, hls::stream<W_TYPE>& s_feature_PE113_1,
    hls::stream<W_TYPE>& s_feature_PE113_2, hls::stream<W_TYPE>& s_feature_PE113_3,
    hls::stream<W_TYPE>& s_feature_PE114_0, hls::stream<W_TYPE>& s_feature_PE114_1,
    hls::stream<W_TYPE>& s_feature_PE114_2, hls::stream<W_TYPE>& s_feature_PE114_3,
    hls::stream<W_TYPE>& s_feature_PE115_0, hls::stream<W_TYPE>& s_feature_PE115_1,
    hls::stream<W_TYPE>& s_feature_PE115_2, hls::stream<W_TYPE>& s_feature_PE115_3,
    hls::stream<W_TYPE>& s_feature_PE116_0, hls::stream<W_TYPE>& s_feature_PE116_1,
    hls::stream<W_TYPE>& s_feature_PE116_2, hls::stream<W_TYPE>& s_feature_PE116_3,
    hls::stream<W_TYPE>& s_feature_PE117_0, hls::stream<W_TYPE>& s_feature_PE117_1,
    hls::stream<W_TYPE>& s_feature_PE117_2, hls::stream<W_TYPE>& s_feature_PE117_3,
    hls::stream<W_TYPE>& s_feature_PE118_0, hls::stream<W_TYPE>& s_feature_PE118_1,
    hls::stream<W_TYPE>& s_feature_PE118_2, hls::stream<W_TYPE>& s_feature_PE118_3,
    hls::stream<W_TYPE>& s_feature_PE119_0, hls::stream<W_TYPE>& s_feature_PE119_1,
    hls::stream<W_TYPE>& s_feature_PE119_2, hls::stream<W_TYPE>& s_feature_PE119_3,
    hls::stream<W_TYPE>& s_feature_PE120_0, hls::stream<W_TYPE>& s_feature_PE120_1,
    hls::stream<W_TYPE>& s_feature_PE120_2, hls::stream<W_TYPE>& s_feature_PE120_3,
    hls::stream<W_TYPE>& s_feature_PE121_0, hls::stream<W_TYPE>& s_feature_PE121_1,
    hls::stream<W_TYPE>& s_feature_PE121_2, hls::stream<W_TYPE>& s_feature_PE121_3,
    hls::stream<W_TYPE>& s_feature_PE122_0, hls::stream<W_TYPE>& s_feature_PE122_1,
    hls::stream<W_TYPE>& s_feature_PE122_2, hls::stream<W_TYPE>& s_feature_PE122_3,
    hls::stream<W_TYPE>& s_feature_PE123_0, hls::stream<W_TYPE>& s_feature_PE123_1,
    hls::stream<W_TYPE>& s_feature_PE123_2, hls::stream<W_TYPE>& s_feature_PE123_3,
    hls::stream<W_TYPE>& s_feature_PE124_0, hls::stream<W_TYPE>& s_feature_PE124_1,
    hls::stream<W_TYPE>& s_feature_PE124_2, hls::stream<W_TYPE>& s_feature_PE124_3,
    hls::stream<W_TYPE>& s_feature_PE125_0, hls::stream<W_TYPE>& s_feature_PE125_1,
    hls::stream<W_TYPE>& s_feature_PE125_2, hls::stream<W_TYPE>& s_feature_PE125_3,
    hls::stream<W_TYPE>& s_feature_PE126_0, hls::stream<W_TYPE>& s_feature_PE126_1,
    hls::stream<W_TYPE>& s_feature_PE126_2, hls::stream<W_TYPE>& s_feature_PE126_3,
    hls::stream<W_TYPE>& s_feature_PE127_0, hls::stream<W_TYPE>& s_feature_PE127_1,
    hls::stream<W_TYPE>& s_feature_PE127_2, hls::stream<W_TYPE>& s_feature_PE127_3,
    hls::stream<W_TYPE>& s_feature_PE128_0, hls::stream<W_TYPE>& s_feature_PE128_1,
    hls::stream<W_TYPE>& s_feature_PE128_2, hls::stream<W_TYPE>& s_feature_PE128_3,
    hls::stream<W_TYPE>& s_feature_PE129_0, hls::stream<W_TYPE>& s_feature_PE129_1,
    hls::stream<W_TYPE>& s_feature_PE129_2, hls::stream<W_TYPE>& s_feature_PE129_3,
    hls::stream<W_TYPE>& s_feature_PE130_0, hls::stream<W_TYPE>& s_feature_PE130_1,
    hls::stream<W_TYPE>& s_feature_PE130_2, hls::stream<W_TYPE>& s_feature_PE130_3,
    hls::stream<W_TYPE>& s_feature_PE131_0, hls::stream<W_TYPE>& s_feature_PE131_1,
    hls::stream<W_TYPE>& s_feature_PE131_2, hls::stream<W_TYPE>& s_feature_PE131_3,
    hls::stream<W_TYPE>& s_feature_PE132_0, hls::stream<W_TYPE>& s_feature_PE132_1,
    hls::stream<W_TYPE>& s_feature_PE132_2, hls::stream<W_TYPE>& s_feature_PE132_3,
    hls::stream<W_TYPE>& s_feature_PE133_0, hls::stream<W_TYPE>& s_feature_PE133_1,
    hls::stream<W_TYPE>& s_feature_PE133_2, hls::stream<W_TYPE>& s_feature_PE133_3,
    hls::stream<W_TYPE>& s_feature_PE134_0, hls::stream<W_TYPE>& s_feature_PE134_1,
    hls::stream<W_TYPE>& s_feature_PE134_2, hls::stream<W_TYPE>& s_feature_PE134_3,
    hls::stream<W_TYPE>& s_feature_PE135_0, hls::stream<W_TYPE>& s_feature_PE135_1,
    hls::stream<W_TYPE>& s_feature_PE135_2, hls::stream<W_TYPE>& s_feature_PE135_3,
    hls::stream<W_TYPE>& s_feature_PE136_0, hls::stream<W_TYPE>& s_feature_PE136_1,
    hls::stream<W_TYPE>& s_feature_PE136_2, hls::stream<W_TYPE>& s_feature_PE136_3,
    hls::stream<W_TYPE>& s_feature_PE137_0, hls::stream<W_TYPE>& s_feature_PE137_1,
    hls::stream<W_TYPE>& s_feature_PE137_2, hls::stream<W_TYPE>& s_feature_PE137_3,
    hls::stream<W_TYPE>& s_feature_PE138_0, hls::stream<W_TYPE>& s_feature_PE138_1,
    hls::stream<W_TYPE>& s_feature_PE138_2, hls::stream<W_TYPE>& s_feature_PE138_3,
    hls::stream<W_TYPE>& s_feature_PE139_0, hls::stream<W_TYPE>& s_feature_PE139_1,
    hls::stream<W_TYPE>& s_feature_PE139_2, hls::stream<W_TYPE>& s_feature_PE139_3,
    hls::stream<W_TYPE>& s_feature_PE140_0, hls::stream<W_TYPE>& s_feature_PE140_1,
    hls::stream<W_TYPE>& s_feature_PE140_2, hls::stream<W_TYPE>& s_feature_PE140_3,
    hls::stream<W_TYPE>& s_feature_PE141_0, hls::stream<W_TYPE>& s_feature_PE141_1,
    hls::stream<W_TYPE>& s_feature_PE141_2, hls::stream<W_TYPE>& s_feature_PE141_3,
    hls::stream<W_TYPE>& s_feature_PE142_0, hls::stream<W_TYPE>& s_feature_PE142_1,
    hls::stream<W_TYPE>& s_feature_PE142_2, hls::stream<W_TYPE>& s_feature_PE142_3,
    hls::stream<W_TYPE>& s_feature_PE143_0, hls::stream<W_TYPE>& s_feature_PE143_1,
    hls::stream<W_TYPE>& s_feature_PE143_2, hls::stream<W_TYPE>& s_feature_PE143_3,
    hls::stream<W_TYPE>& s_feature_PE144_0, hls::stream<W_TYPE>& s_feature_PE144_1,
    hls::stream<W_TYPE>& s_feature_PE144_2, hls::stream<W_TYPE>& s_feature_PE144_3,
    hls::stream<W_TYPE>& s_feature_PE145_0, hls::stream<W_TYPE>& s_feature_PE145_1,
    hls::stream<W_TYPE>& s_feature_PE145_2, hls::stream<W_TYPE>& s_feature_PE145_3,
    hls::stream<W_TYPE>& s_feature_PE146_0, hls::stream<W_TYPE>& s_feature_PE146_1,
    hls::stream<W_TYPE>& s_feature_PE146_2, hls::stream<W_TYPE>& s_feature_PE146_3,
    hls::stream<W_TYPE>& s_feature_PE147_0, hls::stream<W_TYPE>& s_feature_PE147_1,
    hls::stream<W_TYPE>& s_feature_PE147_2, hls::stream<W_TYPE>& s_feature_PE147_3,
    hls::stream<W_TYPE>& s_feature_PE148_0, hls::stream<W_TYPE>& s_feature_PE148_1,
    hls::stream<W_TYPE>& s_feature_PE148_2, hls::stream<W_TYPE>& s_feature_PE148_3,
    hls::stream<W_TYPE>& s_feature_PE149_0, hls::stream<W_TYPE>& s_feature_PE149_1,
    hls::stream<W_TYPE>& s_feature_PE149_2, hls::stream<W_TYPE>& s_feature_PE149_3,
    hls::stream<W_TYPE>& s_feature_PE150_0, hls::stream<W_TYPE>& s_feature_PE150_1,
    hls::stream<W_TYPE>& s_feature_PE150_2, hls::stream<W_TYPE>& s_feature_PE150_3,
    hls::stream<W_TYPE>& s_feature_PE151_0, hls::stream<W_TYPE>& s_feature_PE151_1,
    hls::stream<W_TYPE>& s_feature_PE151_2, hls::stream<W_TYPE>& s_feature_PE151_3,
    hls::stream<W_TYPE>& s_feature_PE152_0, hls::stream<W_TYPE>& s_feature_PE152_1,
    hls::stream<W_TYPE>& s_feature_PE152_2, hls::stream<W_TYPE>& s_feature_PE152_3,
    hls::stream<W_TYPE>& s_feature_PE153_0, hls::stream<W_TYPE>& s_feature_PE153_1,
    hls::stream<W_TYPE>& s_feature_PE153_2, hls::stream<W_TYPE>& s_feature_PE153_3,
    hls::stream<W_TYPE>& s_feature_PE154_0, hls::stream<W_TYPE>& s_feature_PE154_1,
    hls::stream<W_TYPE>& s_feature_PE154_2, hls::stream<W_TYPE>& s_feature_PE154_3,
    hls::stream<W_TYPE>& s_feature_PE155_0, hls::stream<W_TYPE>& s_feature_PE155_1,
    hls::stream<W_TYPE>& s_feature_PE155_2, hls::stream<W_TYPE>& s_feature_PE155_3,
    hls::stream<W_TYPE>& s_feature_PE156_0, hls::stream<W_TYPE>& s_feature_PE156_1,
    hls::stream<W_TYPE>& s_feature_PE156_2, hls::stream<W_TYPE>& s_feature_PE156_3,
    hls::stream<W_TYPE>& s_feature_PE157_0, hls::stream<W_TYPE>& s_feature_PE157_1,
    hls::stream<W_TYPE>& s_feature_PE157_2, hls::stream<W_TYPE>& s_feature_PE157_3,
    hls::stream<W_TYPE>& s_feature_PE158_0, hls::stream<W_TYPE>& s_feature_PE158_1,
    hls::stream<W_TYPE>& s_feature_PE158_2, hls::stream<W_TYPE>& s_feature_PE158_3,
    hls::stream<W_TYPE>& s_feature_PE159_0, hls::stream<W_TYPE>& s_feature_PE159_1,
    hls::stream<W_TYPE>& s_feature_PE159_2, hls::stream<W_TYPE>& s_feature_PE159_3,
    hls::stream<W_TYPE>& s_feature_PE160_0, hls::stream<W_TYPE>& s_feature_PE160_1,
    hls::stream<W_TYPE>& s_feature_PE160_2, hls::stream<W_TYPE>& s_feature_PE160_3,
    hls::stream<W_TYPE>& s_feature_PE161_0, hls::stream<W_TYPE>& s_feature_PE161_1,
    hls::stream<W_TYPE>& s_feature_PE161_2, hls::stream<W_TYPE>& s_feature_PE161_3,
    hls::stream<W_TYPE>& s_feature_PE162_0, hls::stream<W_TYPE>& s_feature_PE162_1,
    hls::stream<W_TYPE>& s_feature_PE162_2, hls::stream<W_TYPE>& s_feature_PE162_3,
    hls::stream<W_TYPE>& s_feature_PE163_0, hls::stream<W_TYPE>& s_feature_PE163_1,
    hls::stream<W_TYPE>& s_feature_PE163_2, hls::stream<W_TYPE>& s_feature_PE163_3,
    hls::stream<W_TYPE>& s_feature_PE164_0, hls::stream<W_TYPE>& s_feature_PE164_1,
    hls::stream<W_TYPE>& s_feature_PE164_2, hls::stream<W_TYPE>& s_feature_PE164_3,
    hls::stream<W_TYPE>& s_feature_PE165_0, hls::stream<W_TYPE>& s_feature_PE165_1,
    hls::stream<W_TYPE>& s_feature_PE165_2, hls::stream<W_TYPE>& s_feature_PE165_3,
    hls::stream<W_TYPE>& s_feature_PE166_0, hls::stream<W_TYPE>& s_feature_PE166_1,
    hls::stream<W_TYPE>& s_feature_PE166_2, hls::stream<W_TYPE>& s_feature_PE166_3,
    hls::stream<W_TYPE>& s_feature_PE167_0, hls::stream<W_TYPE>& s_feature_PE167_1,
    hls::stream<W_TYPE>& s_feature_PE167_2, hls::stream<W_TYPE>& s_feature_PE167_3,
    hls::stream<W_TYPE>& s_feature_PE168_0, hls::stream<W_TYPE>& s_feature_PE168_1,
    hls::stream<W_TYPE>& s_feature_PE168_2, hls::stream<W_TYPE>& s_feature_PE168_3,
    hls::stream<W_TYPE>& s_feature_PE169_0, hls::stream<W_TYPE>& s_feature_PE169_1,
    hls::stream<W_TYPE>& s_feature_PE169_2, hls::stream<W_TYPE>& s_feature_PE169_3,
    hls::stream<W_TYPE>& s_feature_PE170_0, hls::stream<W_TYPE>& s_feature_PE170_1,
    hls::stream<W_TYPE>& s_feature_PE170_2, hls::stream<W_TYPE>& s_feature_PE170_3,
    hls::stream<W_TYPE>& s_feature_PE171_0, hls::stream<W_TYPE>& s_feature_PE171_1,
    hls::stream<W_TYPE>& s_feature_PE171_2, hls::stream<W_TYPE>& s_feature_PE171_3,
    hls::stream<W_TYPE>& s_feature_PE172_0, hls::stream<W_TYPE>& s_feature_PE172_1,
    hls::stream<W_TYPE>& s_feature_PE172_2, hls::stream<W_TYPE>& s_feature_PE172_3,
    hls::stream<W_TYPE>& s_feature_PE173_0, hls::stream<W_TYPE>& s_feature_PE173_1,
    hls::stream<W_TYPE>& s_feature_PE173_2, hls::stream<W_TYPE>& s_feature_PE173_3,
    hls::stream<W_TYPE>& s_feature_PE174_0, hls::stream<W_TYPE>& s_feature_PE174_1,
    hls::stream<W_TYPE>& s_feature_PE174_2, hls::stream<W_TYPE>& s_feature_PE174_3,
    hls::stream<W_TYPE>& s_feature_PE175_0, hls::stream<W_TYPE>& s_feature_PE175_1,
    hls::stream<W_TYPE>& s_feature_PE175_2, hls::stream<W_TYPE>& s_feature_PE175_3,
    hls::stream<W_TYPE>& s_feature_PE176_0, hls::stream<W_TYPE>& s_feature_PE176_1,
    hls::stream<W_TYPE>& s_feature_PE176_2, hls::stream<W_TYPE>& s_feature_PE176_3,
    hls::stream<W_TYPE>& s_feature_PE177_0, hls::stream<W_TYPE>& s_feature_PE177_1,
    hls::stream<W_TYPE>& s_feature_PE177_2, hls::stream<W_TYPE>& s_feature_PE177_3,
    hls::stream<W_TYPE>& s_feature_PE178_0, hls::stream<W_TYPE>& s_feature_PE178_1,
    hls::stream<W_TYPE>& s_feature_PE178_2, hls::stream<W_TYPE>& s_feature_PE178_3,
    hls::stream<W_TYPE>& s_feature_PE179_0, hls::stream<W_TYPE>& s_feature_PE179_1,
    hls::stream<W_TYPE>& s_feature_PE179_2, hls::stream<W_TYPE>& s_feature_PE179_3,
    hls::stream<W_TYPE>& s_feature_PE180_0, hls::stream<W_TYPE>& s_feature_PE180_1,
    hls::stream<W_TYPE>& s_feature_PE180_2, hls::stream<W_TYPE>& s_feature_PE180_3,
    hls::stream<W_TYPE>& s_feature_PE181_0, hls::stream<W_TYPE>& s_feature_PE181_1,
    hls::stream<W_TYPE>& s_feature_PE181_2, hls::stream<W_TYPE>& s_feature_PE181_3,
    hls::stream<W_TYPE>& s_feature_PE182_0, hls::stream<W_TYPE>& s_feature_PE182_1,
    hls::stream<W_TYPE>& s_feature_PE182_2, hls::stream<W_TYPE>& s_feature_PE182_3,
    hls::stream<W_TYPE>& s_feature_PE183_0, hls::stream<W_TYPE>& s_feature_PE183_1,
    hls::stream<W_TYPE>& s_feature_PE183_2, hls::stream<W_TYPE>& s_feature_PE183_3,
    hls::stream<W_TYPE>& s_feature_PE184_0, hls::stream<W_TYPE>& s_feature_PE184_1,
    hls::stream<W_TYPE>& s_feature_PE184_2, hls::stream<W_TYPE>& s_feature_PE184_3,
    hls::stream<W_TYPE>& s_feature_PE185_0, hls::stream<W_TYPE>& s_feature_PE185_1,
    hls::stream<W_TYPE>& s_feature_PE185_2, hls::stream<W_TYPE>& s_feature_PE185_3,
    hls::stream<W_TYPE>& s_feature_PE186_0, hls::stream<W_TYPE>& s_feature_PE186_1,
    hls::stream<W_TYPE>& s_feature_PE186_2, hls::stream<W_TYPE>& s_feature_PE186_3,
    hls::stream<W_TYPE>& s_feature_PE187_0, hls::stream<W_TYPE>& s_feature_PE187_1,
    hls::stream<W_TYPE>& s_feature_PE187_2, hls::stream<W_TYPE>& s_feature_PE187_3,
    hls::stream<W_TYPE>& s_feature_PE188_0, hls::stream<W_TYPE>& s_feature_PE188_1,
    hls::stream<W_TYPE>& s_feature_PE188_2, hls::stream<W_TYPE>& s_feature_PE188_3,
    hls::stream<W_TYPE>& s_feature_PE189_0, hls::stream<W_TYPE>& s_feature_PE189_1,
    hls::stream<W_TYPE>& s_feature_PE189_2, hls::stream<W_TYPE>& s_feature_PE189_3,
    hls::stream<W_TYPE>& s_feature_PE190_0, hls::stream<W_TYPE>& s_feature_PE190_1,
    hls::stream<W_TYPE>& s_feature_PE190_2, hls::stream<W_TYPE>& s_feature_PE190_3,
    hls::stream<W_TYPE>& s_feature_PE191_0, hls::stream<W_TYPE>& s_feature_PE191_1,
    hls::stream<W_TYPE>& s_feature_PE191_2, hls::stream<W_TYPE>& s_feature_PE191_3,
    hls::stream<W_TYPE>& s_feature_PE192_0, hls::stream<W_TYPE>& s_feature_PE192_1,
    hls::stream<W_TYPE>& s_feature_PE192_2, hls::stream<W_TYPE>& s_feature_PE192_3,
    hls::stream<W_TYPE>& s_feature_PE193_0, hls::stream<W_TYPE>& s_feature_PE193_1,
    hls::stream<W_TYPE>& s_feature_PE193_2, hls::stream<W_TYPE>& s_feature_PE193_3,
    hls::stream<W_TYPE>& s_feature_PE194_0, hls::stream<W_TYPE>& s_feature_PE194_1,
    hls::stream<W_TYPE>& s_feature_PE194_2, hls::stream<W_TYPE>& s_feature_PE194_3,
    hls::stream<W_TYPE>& s_feature_PE195_0, hls::stream<W_TYPE>& s_feature_PE195_1,
    hls::stream<W_TYPE>& s_feature_PE195_2, hls::stream<W_TYPE>& s_feature_PE195_3,
    hls::stream<W_TYPE>& s_feature_PE196_0, hls::stream<W_TYPE>& s_feature_PE196_1,
    hls::stream<W_TYPE>& s_feature_PE196_2, hls::stream<W_TYPE>& s_feature_PE196_3,
    hls::stream<W_TYPE>& s_feature_PE197_0, hls::stream<W_TYPE>& s_feature_PE197_1,
    hls::stream<W_TYPE>& s_feature_PE197_2, hls::stream<W_TYPE>& s_feature_PE197_3,
    hls::stream<W_TYPE>& s_feature_PE198_0, hls::stream<W_TYPE>& s_feature_PE198_1,
    hls::stream<W_TYPE>& s_feature_PE198_2, hls::stream<W_TYPE>& s_feature_PE198_3,
    hls::stream<W_TYPE>& s_feature_PE199_0, hls::stream<W_TYPE>& s_feature_PE199_1,
    hls::stream<W_TYPE>& s_feature_PE199_2, hls::stream<W_TYPE>& s_feature_PE199_3,
    hls::stream<W_TYPE>& s_feature_PE200_0, hls::stream<W_TYPE>& s_feature_PE200_1,
    hls::stream<W_TYPE>& s_feature_PE200_2, hls::stream<W_TYPE>& s_feature_PE200_3,
    hls::stream<W_TYPE>& s_feature_PE201_0, hls::stream<W_TYPE>& s_feature_PE201_1,
    hls::stream<W_TYPE>& s_feature_PE201_2, hls::stream<W_TYPE>& s_feature_PE201_3,
    hls::stream<W_TYPE>& s_feature_PE202_0, hls::stream<W_TYPE>& s_feature_PE202_1,
    hls::stream<W_TYPE>& s_feature_PE202_2, hls::stream<W_TYPE>& s_feature_PE202_3,
    hls::stream<W_TYPE>& s_feature_PE203_0, hls::stream<W_TYPE>& s_feature_PE203_1,
    hls::stream<W_TYPE>& s_feature_PE203_2, hls::stream<W_TYPE>& s_feature_PE203_3,
    hls::stream<W_TYPE>& s_feature_PE204_0, hls::stream<W_TYPE>& s_feature_PE204_1,
    hls::stream<W_TYPE>& s_feature_PE204_2, hls::stream<W_TYPE>& s_feature_PE204_3,
    hls::stream<W_TYPE>& s_feature_PE205_0, hls::stream<W_TYPE>& s_feature_PE205_1,
    hls::stream<W_TYPE>& s_feature_PE205_2, hls::stream<W_TYPE>& s_feature_PE205_3,
    hls::stream<W_TYPE>& s_feature_PE206_0, hls::stream<W_TYPE>& s_feature_PE206_1,
    hls::stream<W_TYPE>& s_feature_PE206_2, hls::stream<W_TYPE>& s_feature_PE206_3,
    hls::stream<W_TYPE>& s_feature_PE207_0, hls::stream<W_TYPE>& s_feature_PE207_1,
    hls::stream<W_TYPE>& s_feature_PE207_2, hls::stream<W_TYPE>& s_feature_PE207_3,
    hls::stream<W_TYPE>& s_feature_PE208_0, hls::stream<W_TYPE>& s_feature_PE208_1,
    hls::stream<W_TYPE>& s_feature_PE208_2, hls::stream<W_TYPE>& s_feature_PE208_3,
    hls::stream<W_TYPE>& s_feature_PE209_0, hls::stream<W_TYPE>& s_feature_PE209_1,
    hls::stream<W_TYPE>& s_feature_PE209_2, hls::stream<W_TYPE>& s_feature_PE209_3,
    hls::stream<W_TYPE>& s_feature_PE210_0, hls::stream<W_TYPE>& s_feature_PE210_1,
    hls::stream<W_TYPE>& s_feature_PE210_2, hls::stream<W_TYPE>& s_feature_PE210_3,
    hls::stream<W_TYPE>& s_feature_PE211_0, hls::stream<W_TYPE>& s_feature_PE211_1,
    hls::stream<W_TYPE>& s_feature_PE211_2, hls::stream<W_TYPE>& s_feature_PE211_3,
    hls::stream<W_TYPE>& s_feature_PE212_0, hls::stream<W_TYPE>& s_feature_PE212_1,
    hls::stream<W_TYPE>& s_feature_PE212_2, hls::stream<W_TYPE>& s_feature_PE212_3,
    hls::stream<W_TYPE>& s_feature_PE213_0, hls::stream<W_TYPE>& s_feature_PE213_1,
    hls::stream<W_TYPE>& s_feature_PE213_2, hls::stream<W_TYPE>& s_feature_PE213_3,
    hls::stream<W_TYPE>& s_feature_PE214_0, hls::stream<W_TYPE>& s_feature_PE214_1,
    hls::stream<W_TYPE>& s_feature_PE214_2, hls::stream<W_TYPE>& s_feature_PE214_3,
    hls::stream<W_TYPE>& s_feature_PE215_0, hls::stream<W_TYPE>& s_feature_PE215_1,
    hls::stream<W_TYPE>& s_feature_PE215_2, hls::stream<W_TYPE>& s_feature_PE215_3,
    hls::stream<W_TYPE>& s_feature_PE216_0, hls::stream<W_TYPE>& s_feature_PE216_1,
    hls::stream<W_TYPE>& s_feature_PE216_2, hls::stream<W_TYPE>& s_feature_PE216_3,
    hls::stream<W_TYPE>& s_feature_PE217_0, hls::stream<W_TYPE>& s_feature_PE217_1,
    hls::stream<W_TYPE>& s_feature_PE217_2, hls::stream<W_TYPE>& s_feature_PE217_3,
    hls::stream<W_TYPE>& s_feature_PE218_0, hls::stream<W_TYPE>& s_feature_PE218_1,
    hls::stream<W_TYPE>& s_feature_PE218_2, hls::stream<W_TYPE>& s_feature_PE218_3,
    hls::stream<W_TYPE>& s_feature_PE219_0, hls::stream<W_TYPE>& s_feature_PE219_1,
    hls::stream<W_TYPE>& s_feature_PE219_2, hls::stream<W_TYPE>& s_feature_PE219_3,
    hls::stream<W_TYPE>& s_feature_PE220_0, hls::stream<W_TYPE>& s_feature_PE220_1,
    hls::stream<W_TYPE>& s_feature_PE220_2, hls::stream<W_TYPE>& s_feature_PE220_3,
    hls::stream<W_TYPE>& s_feature_PE221_0, hls::stream<W_TYPE>& s_feature_PE221_1,
    hls::stream<W_TYPE>& s_feature_PE221_2, hls::stream<W_TYPE>& s_feature_PE221_3,
    hls::stream<W_TYPE>& s_feature_PE222_0, hls::stream<W_TYPE>& s_feature_PE222_1,
    hls::stream<W_TYPE>& s_feature_PE222_2, hls::stream<W_TYPE>& s_feature_PE222_3,
    hls::stream<W_TYPE>& s_feature_PE223_0, hls::stream<W_TYPE>& s_feature_PE223_1,
    hls::stream<W_TYPE>& s_feature_PE223_2, hls::stream<W_TYPE>& s_feature_PE223_3,
    hls::stream<W_TYPE>& s_feature_PE224_0, hls::stream<W_TYPE>& s_feature_PE224_1,
    hls::stream<W_TYPE>& s_feature_PE224_2, hls::stream<W_TYPE>& s_feature_PE224_3,
    hls::stream<W_TYPE>& s_feature_PE225_0, hls::stream<W_TYPE>& s_feature_PE225_1,
    hls::stream<W_TYPE>& s_feature_PE225_2, hls::stream<W_TYPE>& s_feature_PE225_3,
    hls::stream<W_TYPE>& s_feature_PE226_0, hls::stream<W_TYPE>& s_feature_PE226_1,
    hls::stream<W_TYPE>& s_feature_PE226_2, hls::stream<W_TYPE>& s_feature_PE226_3,
    hls::stream<W_TYPE>& s_feature_PE227_0, hls::stream<W_TYPE>& s_feature_PE227_1,
    hls::stream<W_TYPE>& s_feature_PE227_2, hls::stream<W_TYPE>& s_feature_PE227_3,
    hls::stream<W_TYPE>& s_feature_PE228_0, hls::stream<W_TYPE>& s_feature_PE228_1,
    hls::stream<W_TYPE>& s_feature_PE228_2, hls::stream<W_TYPE>& s_feature_PE228_3,
    hls::stream<W_TYPE>& s_feature_PE229_0, hls::stream<W_TYPE>& s_feature_PE229_1,
    hls::stream<W_TYPE>& s_feature_PE229_2, hls::stream<W_TYPE>& s_feature_PE229_3,
    hls::stream<W_TYPE>& s_feature_PE230_0, hls::stream<W_TYPE>& s_feature_PE230_1,
    hls::stream<W_TYPE>& s_feature_PE230_2, hls::stream<W_TYPE>& s_feature_PE230_3,
    hls::stream<W_TYPE>& s_feature_PE231_0, hls::stream<W_TYPE>& s_feature_PE231_1,
    hls::stream<W_TYPE>& s_feature_PE231_2, hls::stream<W_TYPE>& s_feature_PE231_3,
    hls::stream<W_TYPE>& s_feature_PE232_0, hls::stream<W_TYPE>& s_feature_PE232_1,
    hls::stream<W_TYPE>& s_feature_PE232_2, hls::stream<W_TYPE>& s_feature_PE232_3,
    hls::stream<W_TYPE>& s_feature_PE233_0, hls::stream<W_TYPE>& s_feature_PE233_1,
    hls::stream<W_TYPE>& s_feature_PE233_2, hls::stream<W_TYPE>& s_feature_PE233_3,
    hls::stream<W_TYPE>& s_feature_PE234_0, hls::stream<W_TYPE>& s_feature_PE234_1,
    hls::stream<W_TYPE>& s_feature_PE234_2, hls::stream<W_TYPE>& s_feature_PE234_3,
    hls::stream<W_TYPE>& s_feature_PE235_0, hls::stream<W_TYPE>& s_feature_PE235_1,
    hls::stream<W_TYPE>& s_feature_PE235_2, hls::stream<W_TYPE>& s_feature_PE235_3,
    hls::stream<W_TYPE>& s_feature_PE236_0, hls::stream<W_TYPE>& s_feature_PE236_1,
    hls::stream<W_TYPE>& s_feature_PE236_2, hls::stream<W_TYPE>& s_feature_PE236_3,
    hls::stream<W_TYPE>& s_feature_PE237_0, hls::stream<W_TYPE>& s_feature_PE237_1,
    hls::stream<W_TYPE>& s_feature_PE237_2, hls::stream<W_TYPE>& s_feature_PE237_3,
    hls::stream<W_TYPE>& s_feature_PE238_0, hls::stream<W_TYPE>& s_feature_PE238_1,
    hls::stream<W_TYPE>& s_feature_PE238_2, hls::stream<W_TYPE>& s_feature_PE238_3,
    hls::stream<W_TYPE>& s_feature_PE239_0, hls::stream<W_TYPE>& s_feature_PE239_1,
    hls::stream<W_TYPE>& s_feature_PE239_2, hls::stream<W_TYPE>& s_feature_PE239_3,
    hls::stream<W_TYPE>& s_feature_PE240_0, hls::stream<W_TYPE>& s_feature_PE240_1,
    hls::stream<W_TYPE>& s_feature_PE240_2, hls::stream<W_TYPE>& s_feature_PE240_3,
    hls::stream<W_TYPE>& s_feature_PE241_0, hls::stream<W_TYPE>& s_feature_PE241_1,
    hls::stream<W_TYPE>& s_feature_PE241_2, hls::stream<W_TYPE>& s_feature_PE241_3,
    hls::stream<W_TYPE>& s_feature_PE242_0, hls::stream<W_TYPE>& s_feature_PE242_1,
    hls::stream<W_TYPE>& s_feature_PE242_2, hls::stream<W_TYPE>& s_feature_PE242_3,
    hls::stream<W_TYPE>& s_feature_PE243_0, hls::stream<W_TYPE>& s_feature_PE243_1,
    hls::stream<W_TYPE>& s_feature_PE243_2, hls::stream<W_TYPE>& s_feature_PE243_3,
    hls::stream<W_TYPE>& s_feature_PE244_0, hls::stream<W_TYPE>& s_feature_PE244_1,
    hls::stream<W_TYPE>& s_feature_PE244_2, hls::stream<W_TYPE>& s_feature_PE244_3,
    hls::stream<W_TYPE>& s_feature_PE245_0, hls::stream<W_TYPE>& s_feature_PE245_1,
    hls::stream<W_TYPE>& s_feature_PE245_2, hls::stream<W_TYPE>& s_feature_PE245_3,
    hls::stream<W_TYPE>& s_feature_PE246_0, hls::stream<W_TYPE>& s_feature_PE246_1,
    hls::stream<W_TYPE>& s_feature_PE246_2, hls::stream<W_TYPE>& s_feature_PE246_3,
    hls::stream<W_TYPE>& s_feature_PE247_0, hls::stream<W_TYPE>& s_feature_PE247_1,
    hls::stream<W_TYPE>& s_feature_PE247_2, hls::stream<W_TYPE>& s_feature_PE247_3,
    hls::stream<W_TYPE>& s_feature_PE248_0, hls::stream<W_TYPE>& s_feature_PE248_1,
    hls::stream<W_TYPE>& s_feature_PE248_2, hls::stream<W_TYPE>& s_feature_PE248_3,
    hls::stream<W_TYPE>& s_feature_PE249_0, hls::stream<W_TYPE>& s_feature_PE249_1,
    hls::stream<W_TYPE>& s_feature_PE249_2, hls::stream<W_TYPE>& s_feature_PE249_3,
    hls::stream<W_TYPE>& s_feature_PE250_0, hls::stream<W_TYPE>& s_feature_PE250_1,
    hls::stream<W_TYPE>& s_feature_PE250_2, hls::stream<W_TYPE>& s_feature_PE250_3,
    hls::stream<W_TYPE>& s_feature_PE251_0, hls::stream<W_TYPE>& s_feature_PE251_1,
    hls::stream<W_TYPE>& s_feature_PE251_2, hls::stream<W_TYPE>& s_feature_PE251_3,
    hls::stream<W_TYPE>& s_feature_PE252_0, hls::stream<W_TYPE>& s_feature_PE252_1,
    hls::stream<W_TYPE>& s_feature_PE252_2, hls::stream<W_TYPE>& s_feature_PE252_3,
    hls::stream<W_TYPE>& s_feature_PE253_0, hls::stream<W_TYPE>& s_feature_PE253_1,
    hls::stream<W_TYPE>& s_feature_PE253_2, hls::stream<W_TYPE>& s_feature_PE253_3,
    hls::stream<W_TYPE>& s_feature_PE254_0, hls::stream<W_TYPE>& s_feature_PE254_1,
    hls::stream<W_TYPE>& s_feature_PE254_2, hls::stream<W_TYPE>& s_feature_PE254_3,
    hls::stream<W_TYPE>& s_feature_PE255_0, hls::stream<W_TYPE>& s_feature_PE255_1,
    hls::stream<W_TYPE>& s_feature_PE255_2, hls::stream<W_TYPE>& s_feature_PE255_3,
    hls::stream<W_TYPE>& s_feature_PE256_0, hls::stream<W_TYPE>& s_feature_PE256_1,
    hls::stream<W_TYPE>& s_feature_PE256_2, hls::stream<W_TYPE>& s_feature_PE256_3,
    hls::stream<W_TYPE>& s_feature_PE257_0, hls::stream<W_TYPE>& s_feature_PE257_1,
    hls::stream<W_TYPE>& s_feature_PE257_2, hls::stream<W_TYPE>& s_feature_PE257_3,
    hls::stream<W_TYPE>& s_feature_PE258_0, hls::stream<W_TYPE>& s_feature_PE258_1,
    hls::stream<W_TYPE>& s_feature_PE258_2, hls::stream<W_TYPE>& s_feature_PE258_3,
    hls::stream<W_TYPE>& s_feature_PE259_0, hls::stream<W_TYPE>& s_feature_PE259_1,
    hls::stream<W_TYPE>& s_feature_PE259_2, hls::stream<W_TYPE>& s_feature_PE259_3,
    hls::stream<W_TYPE>& s_feature_PE260_0, hls::stream<W_TYPE>& s_feature_PE260_1,
    hls::stream<W_TYPE>& s_feature_PE260_2, hls::stream<W_TYPE>& s_feature_PE260_3,
    hls::stream<W_TYPE>& s_feature_PE261_0, hls::stream<W_TYPE>& s_feature_PE261_1,
    hls::stream<W_TYPE>& s_feature_PE261_2, hls::stream<W_TYPE>& s_feature_PE261_3,
    hls::stream<W_TYPE>& s_feature_PE262_0, hls::stream<W_TYPE>& s_feature_PE262_1,
    hls::stream<W_TYPE>& s_feature_PE262_2, hls::stream<W_TYPE>& s_feature_PE262_3,
    hls::stream<W_TYPE>& s_feature_PE263_0, hls::stream<W_TYPE>& s_feature_PE263_1,
    hls::stream<W_TYPE>& s_feature_PE263_2, hls::stream<W_TYPE>& s_feature_PE263_3,
    hls::stream<W_TYPE>& s_feature_PE264_0, hls::stream<W_TYPE>& s_feature_PE264_1,
    hls::stream<W_TYPE>& s_feature_PE264_2, hls::stream<W_TYPE>& s_feature_PE264_3,
    hls::stream<W_TYPE>& s_feature_PE265_0, hls::stream<W_TYPE>& s_feature_PE265_1,
    hls::stream<W_TYPE>& s_feature_PE265_2, hls::stream<W_TYPE>& s_feature_PE265_3,
    hls::stream<W_TYPE>& s_feature_PE266_0, hls::stream<W_TYPE>& s_feature_PE266_1,
    hls::stream<W_TYPE>& s_feature_PE266_2, hls::stream<W_TYPE>& s_feature_PE266_3,
    hls::stream<W_TYPE>& s_feature_PE267_0, hls::stream<W_TYPE>& s_feature_PE267_1,
    hls::stream<W_TYPE>& s_feature_PE267_2, hls::stream<W_TYPE>& s_feature_PE267_3,
    hls::stream<W_TYPE>& s_feature_PE268_0, hls::stream<W_TYPE>& s_feature_PE268_1,
    hls::stream<W_TYPE>& s_feature_PE268_2, hls::stream<W_TYPE>& s_feature_PE268_3,
    hls::stream<W_TYPE>& s_feature_PE269_0, hls::stream<W_TYPE>& s_feature_PE269_1,
    hls::stream<W_TYPE>& s_feature_PE269_2, hls::stream<W_TYPE>& s_feature_PE269_3,
    hls::stream<W_TYPE>& s_feature_PE270_0, hls::stream<W_TYPE>& s_feature_PE270_1,
    hls::stream<W_TYPE>& s_feature_PE270_2, hls::stream<W_TYPE>& s_feature_PE270_3,
    hls::stream<W_TYPE>& s_feature_PE271_0, hls::stream<W_TYPE>& s_feature_PE271_1,
    hls::stream<W_TYPE>& s_feature_PE271_2, hls::stream<W_TYPE>& s_feature_PE271_3,
    hls::stream<W_TYPE>& s_feature_PE272_0, hls::stream<W_TYPE>& s_feature_PE272_1,
    hls::stream<W_TYPE>& s_feature_PE272_2, hls::stream<W_TYPE>& s_feature_PE272_3,
    hls::stream<W_TYPE>& s_feature_PE273_0, hls::stream<W_TYPE>& s_feature_PE273_1,
    hls::stream<W_TYPE>& s_feature_PE273_2, hls::stream<W_TYPE>& s_feature_PE273_3,
    hls::stream<W_TYPE>& s_feature_PE274_0, hls::stream<W_TYPE>& s_feature_PE274_1,
    hls::stream<W_TYPE>& s_feature_PE274_2, hls::stream<W_TYPE>& s_feature_PE274_3,
    hls::stream<W_TYPE>& s_feature_PE275_0, hls::stream<W_TYPE>& s_feature_PE275_1,
    hls::stream<W_TYPE>& s_feature_PE275_2, hls::stream<W_TYPE>& s_feature_PE275_3,
    hls::stream<W_TYPE>& s_feature_PE276_0, hls::stream<W_TYPE>& s_feature_PE276_1,
    hls::stream<W_TYPE>& s_feature_PE276_2, hls::stream<W_TYPE>& s_feature_PE276_3,
    hls::stream<W_TYPE>& s_feature_PE277_0, hls::stream<W_TYPE>& s_feature_PE277_1,
    hls::stream<W_TYPE>& s_feature_PE277_2, hls::stream<W_TYPE>& s_feature_PE277_3,
    hls::stream<W_TYPE>& s_feature_PE278_0, hls::stream<W_TYPE>& s_feature_PE278_1,
    hls::stream<W_TYPE>& s_feature_PE278_2, hls::stream<W_TYPE>& s_feature_PE278_3,
    hls::stream<W_TYPE>& s_feature_PE279_0, hls::stream<W_TYPE>& s_feature_PE279_1,
    hls::stream<W_TYPE>& s_feature_PE279_2, hls::stream<W_TYPE>& s_feature_PE279_3,
    hls::stream<W_TYPE>& s_feature_PE280_0, hls::stream<W_TYPE>& s_feature_PE280_1,
    hls::stream<W_TYPE>& s_feature_PE280_2, hls::stream<W_TYPE>& s_feature_PE280_3,
    hls::stream<W_TYPE>& s_feature_PE281_0, hls::stream<W_TYPE>& s_feature_PE281_1,
    hls::stream<W_TYPE>& s_feature_PE281_2, hls::stream<W_TYPE>& s_feature_PE281_3,
    hls::stream<W_TYPE>& s_feature_PE282_0, hls::stream<W_TYPE>& s_feature_PE282_1,
    hls::stream<W_TYPE>& s_feature_PE282_2, hls::stream<W_TYPE>& s_feature_PE282_3,
    hls::stream<W_TYPE>& s_feature_PE283_0, hls::stream<W_TYPE>& s_feature_PE283_1,
    hls::stream<W_TYPE>& s_feature_PE283_2, hls::stream<W_TYPE>& s_feature_PE283_3,
    hls::stream<W_TYPE>& s_feature_PE284_0, hls::stream<W_TYPE>& s_feature_PE284_1,
    hls::stream<W_TYPE>& s_feature_PE284_2, hls::stream<W_TYPE>& s_feature_PE284_3,
    hls::stream<W_TYPE>& s_feature_PE285_0, hls::stream<W_TYPE>& s_feature_PE285_1,
    hls::stream<W_TYPE>& s_feature_PE285_2, hls::stream<W_TYPE>& s_feature_PE285_3,
    hls::stream<W_TYPE>& s_feature_PE286_0, hls::stream<W_TYPE>& s_feature_PE286_1,
    hls::stream<W_TYPE>& s_feature_PE286_2, hls::stream<W_TYPE>& s_feature_PE286_3,
    hls::stream<W_TYPE>& s_feature_PE287_0, hls::stream<W_TYPE>& s_feature_PE287_1,
    hls::stream<W_TYPE>& s_feature_PE287_2, hls::stream<W_TYPE>& s_feature_PE287_3,
    hls::stream<W_TYPE>& s_feature_PE288_0, hls::stream<W_TYPE>& s_feature_PE288_1,
    hls::stream<W_TYPE>& s_feature_PE288_2, hls::stream<W_TYPE>& s_feature_PE288_3,
    hls::stream<W_TYPE>& s_feature_PE289_0, hls::stream<W_TYPE>& s_feature_PE289_1,
    hls::stream<W_TYPE>& s_feature_PE289_2, hls::stream<W_TYPE>& s_feature_PE289_3,
    hls::stream<W_TYPE>& s_feature_PE290_0, hls::stream<W_TYPE>& s_feature_PE290_1,
    hls::stream<W_TYPE>& s_feature_PE290_2, hls::stream<W_TYPE>& s_feature_PE290_3,
    hls::stream<W_TYPE>& s_feature_PE291_0, hls::stream<W_TYPE>& s_feature_PE291_1,
    hls::stream<W_TYPE>& s_feature_PE291_2, hls::stream<W_TYPE>& s_feature_PE291_3,
    hls::stream<W_TYPE>& s_feature_PE292_0, hls::stream<W_TYPE>& s_feature_PE292_1,
    hls::stream<W_TYPE>& s_feature_PE292_2, hls::stream<W_TYPE>& s_feature_PE292_3,
    hls::stream<W_TYPE>& s_feature_PE293_0, hls::stream<W_TYPE>& s_feature_PE293_1,
    hls::stream<W_TYPE>& s_feature_PE293_2, hls::stream<W_TYPE>& s_feature_PE293_3,
    hls::stream<W_TYPE>& s_feature_PE294_0, hls::stream<W_TYPE>& s_feature_PE294_1,
    hls::stream<W_TYPE>& s_feature_PE294_2, hls::stream<W_TYPE>& s_feature_PE294_3,
    hls::stream<W_TYPE>& s_feature_PE295_0, hls::stream<W_TYPE>& s_feature_PE295_1,
    hls::stream<W_TYPE>& s_feature_PE295_2, hls::stream<W_TYPE>& s_feature_PE295_3,
    hls::stream<W_TYPE>& s_feature_PE296_0, hls::stream<W_TYPE>& s_feature_PE296_1,
    hls::stream<W_TYPE>& s_feature_PE296_2, hls::stream<W_TYPE>& s_feature_PE296_3,
    hls::stream<W_TYPE>& s_feature_PE297_0, hls::stream<W_TYPE>& s_feature_PE297_1,
    hls::stream<W_TYPE>& s_feature_PE297_2, hls::stream<W_TYPE>& s_feature_PE297_3,
    hls::stream<W_TYPE>& s_feature_PE298_0, hls::stream<W_TYPE>& s_feature_PE298_1,
    hls::stream<W_TYPE>& s_feature_PE298_2, hls::stream<W_TYPE>& s_feature_PE298_3,
    hls::stream<W_TYPE>& s_feature_PE299_0, hls::stream<W_TYPE>& s_feature_PE299_1,
    hls::stream<W_TYPE>& s_feature_PE299_2, hls::stream<W_TYPE>& s_feature_PE299_3,
    hls::stream<W_TYPE>& s_feature_PE300_0, hls::stream<W_TYPE>& s_feature_PE300_1,
    hls::stream<W_TYPE>& s_feature_PE300_2, hls::stream<W_TYPE>& s_feature_PE300_3,
    hls::stream<W_TYPE>& s_feature_PE301_0, hls::stream<W_TYPE>& s_feature_PE301_1,
    hls::stream<W_TYPE>& s_feature_PE301_2, hls::stream<W_TYPE>& s_feature_PE301_3,
    hls::stream<W_TYPE>& s_feature_PE302_0, hls::stream<W_TYPE>& s_feature_PE302_1,
    hls::stream<W_TYPE>& s_feature_PE302_2, hls::stream<W_TYPE>& s_feature_PE302_3,
    hls::stream<W_TYPE>& s_feature_PE303_0, hls::stream<W_TYPE>& s_feature_PE303_1,
    hls::stream<W_TYPE>& s_feature_PE303_2, hls::stream<W_TYPE>& s_feature_PE303_3,
    hls::stream<W_TYPE>& s_feature_PE304_0, hls::stream<W_TYPE>& s_feature_PE304_1,
    hls::stream<W_TYPE>& s_feature_PE304_2, hls::stream<W_TYPE>& s_feature_PE304_3,
    hls::stream<W_TYPE>& s_feature_PE305_0, hls::stream<W_TYPE>& s_feature_PE305_1,
    hls::stream<W_TYPE>& s_feature_PE305_2, hls::stream<W_TYPE>& s_feature_PE305_3,
    hls::stream<W_TYPE>& s_feature_PE306_0, hls::stream<W_TYPE>& s_feature_PE306_1,
    hls::stream<W_TYPE>& s_feature_PE306_2, hls::stream<W_TYPE>& s_feature_PE306_3,
    hls::stream<W_TYPE>& s_feature_PE307_0, hls::stream<W_TYPE>& s_feature_PE307_1,
    hls::stream<W_TYPE>& s_feature_PE307_2, hls::stream<W_TYPE>& s_feature_PE307_3,
    hls::stream<W_TYPE>& s_feature_PE308_0, hls::stream<W_TYPE>& s_feature_PE308_1,
    hls::stream<W_TYPE>& s_feature_PE308_2, hls::stream<W_TYPE>& s_feature_PE308_3,
    hls::stream<W_TYPE>& s_feature_PE309_0, hls::stream<W_TYPE>& s_feature_PE309_1,
    hls::stream<W_TYPE>& s_feature_PE309_2, hls::stream<W_TYPE>& s_feature_PE309_3,
    hls::stream<W_TYPE>& s_feature_PE310_0, hls::stream<W_TYPE>& s_feature_PE310_1,
    hls::stream<W_TYPE>& s_feature_PE310_2, hls::stream<W_TYPE>& s_feature_PE310_3,
    hls::stream<W_TYPE>& s_feature_PE311_0, hls::stream<W_TYPE>& s_feature_PE311_1,
    hls::stream<W_TYPE>& s_feature_PE311_2, hls::stream<W_TYPE>& s_feature_PE311_3,
    hls::stream<W_TYPE>& s_feature_PE312_0, hls::stream<W_TYPE>& s_feature_PE312_1,
    hls::stream<W_TYPE>& s_feature_PE312_2, hls::stream<W_TYPE>& s_feature_PE312_3,
    hls::stream<W_TYPE>& s_feature_PE313_0, hls::stream<W_TYPE>& s_feature_PE313_1,
    hls::stream<W_TYPE>& s_feature_PE313_2, hls::stream<W_TYPE>& s_feature_PE313_3,
    hls::stream<W_TYPE>& s_feature_PE314_0, hls::stream<W_TYPE>& s_feature_PE314_1,
    hls::stream<W_TYPE>& s_feature_PE314_2, hls::stream<W_TYPE>& s_feature_PE314_3,
    hls::stream<W_TYPE>& s_feature_PE315_0, hls::stream<W_TYPE>& s_feature_PE315_1,
    hls::stream<W_TYPE>& s_feature_PE315_2, hls::stream<W_TYPE>& s_feature_PE315_3,
    hls::stream<W_TYPE>& s_feature_PE316_0, hls::stream<W_TYPE>& s_feature_PE316_1,
    hls::stream<W_TYPE>& s_feature_PE316_2, hls::stream<W_TYPE>& s_feature_PE316_3,
    hls::stream<W_TYPE>& s_feature_PE317_0, hls::stream<W_TYPE>& s_feature_PE317_1,
    hls::stream<W_TYPE>& s_feature_PE317_2, hls::stream<W_TYPE>& s_feature_PE317_3,
    hls::stream<W_TYPE>& s_feature_PE318_0, hls::stream<W_TYPE>& s_feature_PE318_1,
    hls::stream<W_TYPE>& s_feature_PE318_2, hls::stream<W_TYPE>& s_feature_PE318_3,
    hls::stream<W_TYPE>& s_feature_PE319_0, hls::stream<W_TYPE>& s_feature_PE319_1,
    hls::stream<W_TYPE>& s_feature_PE319_2, hls::stream<W_TYPE>& s_feature_PE319_3
);

template<const int FEATURE_SIZE>
void replicate_feature_512PEs_160PE(
    hls::stream<ap_uint<512> >& s_feature_in, 
    hls::stream<W_TYPE>& s_feature_PE0_0, hls::stream<W_TYPE>& s_feature_PE0_1,
    hls::stream<W_TYPE>& s_feature_PE0_2, hls::stream<W_TYPE>& s_feature_PE0_3,
    hls::stream<W_TYPE>& s_feature_PE1_0, hls::stream<W_TYPE>& s_feature_PE1_1,
    hls::stream<W_TYPE>& s_feature_PE1_2, hls::stream<W_TYPE>& s_feature_PE1_3,
    hls::stream<W_TYPE>& s_feature_PE2_0, hls::stream<W_TYPE>& s_feature_PE2_1,
    hls::stream<W_TYPE>& s_feature_PE2_2, hls::stream<W_TYPE>& s_feature_PE2_3,
    hls::stream<W_TYPE>& s_feature_PE3_0, hls::stream<W_TYPE>& s_feature_PE3_1,
    hls::stream<W_TYPE>& s_feature_PE3_2, hls::stream<W_TYPE>& s_feature_PE3_3,
    hls::stream<W_TYPE>& s_feature_PE4_0, hls::stream<W_TYPE>& s_feature_PE4_1,
    hls::stream<W_TYPE>& s_feature_PE4_2, hls::stream<W_TYPE>& s_feature_PE4_3,
    hls::stream<W_TYPE>& s_feature_PE5_0, hls::stream<W_TYPE>& s_feature_PE5_1,
    hls::stream<W_TYPE>& s_feature_PE5_2, hls::stream<W_TYPE>& s_feature_PE5_3,
    hls::stream<W_TYPE>& s_feature_PE6_0, hls::stream<W_TYPE>& s_feature_PE6_1,
    hls::stream<W_TYPE>& s_feature_PE6_2, hls::stream<W_TYPE>& s_feature_PE6_3,
    hls::stream<W_TYPE>& s_feature_PE7_0, hls::stream<W_TYPE>& s_feature_PE7_1,
    hls::stream<W_TYPE>& s_feature_PE7_2, hls::stream<W_TYPE>& s_feature_PE7_3,
    hls::stream<W_TYPE>& s_feature_PE8_0, hls::stream<W_TYPE>& s_feature_PE8_1,
    hls::stream<W_TYPE>& s_feature_PE8_2, hls::stream<W_TYPE>& s_feature_PE8_3,
    hls::stream<W_TYPE>& s_feature_PE9_0, hls::stream<W_TYPE>& s_feature_PE9_1,
    hls::stream<W_TYPE>& s_feature_PE9_2, hls::stream<W_TYPE>& s_feature_PE9_3,
    hls::stream<W_TYPE>& s_feature_PE10_0, hls::stream<W_TYPE>& s_feature_PE10_1,
    hls::stream<W_TYPE>& s_feature_PE10_2, hls::stream<W_TYPE>& s_feature_PE10_3,
    hls::stream<W_TYPE>& s_feature_PE11_0, hls::stream<W_TYPE>& s_feature_PE11_1,
    hls::stream<W_TYPE>& s_feature_PE11_2, hls::stream<W_TYPE>& s_feature_PE11_3,
    hls::stream<W_TYPE>& s_feature_PE12_0, hls::stream<W_TYPE>& s_feature_PE12_1,
    hls::stream<W_TYPE>& s_feature_PE12_2, hls::stream<W_TYPE>& s_feature_PE12_3,
    hls::stream<W_TYPE>& s_feature_PE13_0, hls::stream<W_TYPE>& s_feature_PE13_1,
    hls::stream<W_TYPE>& s_feature_PE13_2, hls::stream<W_TYPE>& s_feature_PE13_3,
    hls::stream<W_TYPE>& s_feature_PE14_0, hls::stream<W_TYPE>& s_feature_PE14_1,
    hls::stream<W_TYPE>& s_feature_PE14_2, hls::stream<W_TYPE>& s_feature_PE14_3,
    hls::stream<W_TYPE>& s_feature_PE15_0, hls::stream<W_TYPE>& s_feature_PE15_1,
    hls::stream<W_TYPE>& s_feature_PE15_2, hls::stream<W_TYPE>& s_feature_PE15_3,
    hls::stream<W_TYPE>& s_feature_PE16_0, hls::stream<W_TYPE>& s_feature_PE16_1,
    hls::stream<W_TYPE>& s_feature_PE16_2, hls::stream<W_TYPE>& s_feature_PE16_3,
    hls::stream<W_TYPE>& s_feature_PE17_0, hls::stream<W_TYPE>& s_feature_PE17_1,
    hls::stream<W_TYPE>& s_feature_PE17_2, hls::stream<W_TYPE>& s_feature_PE17_3,
    hls::stream<W_TYPE>& s_feature_PE18_0, hls::stream<W_TYPE>& s_feature_PE18_1,
    hls::stream<W_TYPE>& s_feature_PE18_2, hls::stream<W_TYPE>& s_feature_PE18_3,
    hls::stream<W_TYPE>& s_feature_PE19_0, hls::stream<W_TYPE>& s_feature_PE19_1,
    hls::stream<W_TYPE>& s_feature_PE19_2, hls::stream<W_TYPE>& s_feature_PE19_3,
    hls::stream<W_TYPE>& s_feature_PE20_0, hls::stream<W_TYPE>& s_feature_PE20_1,
    hls::stream<W_TYPE>& s_feature_PE20_2, hls::stream<W_TYPE>& s_feature_PE20_3,
    hls::stream<W_TYPE>& s_feature_PE21_0, hls::stream<W_TYPE>& s_feature_PE21_1,
    hls::stream<W_TYPE>& s_feature_PE21_2, hls::stream<W_TYPE>& s_feature_PE21_3,
    hls::stream<W_TYPE>& s_feature_PE22_0, hls::stream<W_TYPE>& s_feature_PE22_1,
    hls::stream<W_TYPE>& s_feature_PE22_2, hls::stream<W_TYPE>& s_feature_PE22_3,
    hls::stream<W_TYPE>& s_feature_PE23_0, hls::stream<W_TYPE>& s_feature_PE23_1,
    hls::stream<W_TYPE>& s_feature_PE23_2, hls::stream<W_TYPE>& s_feature_PE23_3,
    hls::stream<W_TYPE>& s_feature_PE24_0, hls::stream<W_TYPE>& s_feature_PE24_1,
    hls::stream<W_TYPE>& s_feature_PE24_2, hls::stream<W_TYPE>& s_feature_PE24_3,
    hls::stream<W_TYPE>& s_feature_PE25_0, hls::stream<W_TYPE>& s_feature_PE25_1,
    hls::stream<W_TYPE>& s_feature_PE25_2, hls::stream<W_TYPE>& s_feature_PE25_3,
    hls::stream<W_TYPE>& s_feature_PE26_0, hls::stream<W_TYPE>& s_feature_PE26_1,
    hls::stream<W_TYPE>& s_feature_PE26_2, hls::stream<W_TYPE>& s_feature_PE26_3,
    hls::stream<W_TYPE>& s_feature_PE27_0, hls::stream<W_TYPE>& s_feature_PE27_1,
    hls::stream<W_TYPE>& s_feature_PE27_2, hls::stream<W_TYPE>& s_feature_PE27_3,
    hls::stream<W_TYPE>& s_feature_PE28_0, hls::stream<W_TYPE>& s_feature_PE28_1,
    hls::stream<W_TYPE>& s_feature_PE28_2, hls::stream<W_TYPE>& s_feature_PE28_3,
    hls::stream<W_TYPE>& s_feature_PE29_0, hls::stream<W_TYPE>& s_feature_PE29_1,
    hls::stream<W_TYPE>& s_feature_PE29_2, hls::stream<W_TYPE>& s_feature_PE29_3,
    hls::stream<W_TYPE>& s_feature_PE30_0, hls::stream<W_TYPE>& s_feature_PE30_1,
    hls::stream<W_TYPE>& s_feature_PE30_2, hls::stream<W_TYPE>& s_feature_PE30_3,
    hls::stream<W_TYPE>& s_feature_PE31_0, hls::stream<W_TYPE>& s_feature_PE31_1,
    hls::stream<W_TYPE>& s_feature_PE31_2, hls::stream<W_TYPE>& s_feature_PE31_3,
    hls::stream<W_TYPE>& s_feature_PE32_0, hls::stream<W_TYPE>& s_feature_PE32_1,
    hls::stream<W_TYPE>& s_feature_PE32_2, hls::stream<W_TYPE>& s_feature_PE32_3,
    hls::stream<W_TYPE>& s_feature_PE33_0, hls::stream<W_TYPE>& s_feature_PE33_1,
    hls::stream<W_TYPE>& s_feature_PE33_2, hls::stream<W_TYPE>& s_feature_PE33_3,
    hls::stream<W_TYPE>& s_feature_PE34_0, hls::stream<W_TYPE>& s_feature_PE34_1,
    hls::stream<W_TYPE>& s_feature_PE34_2, hls::stream<W_TYPE>& s_feature_PE34_3,
    hls::stream<W_TYPE>& s_feature_PE35_0, hls::stream<W_TYPE>& s_feature_PE35_1,
    hls::stream<W_TYPE>& s_feature_PE35_2, hls::stream<W_TYPE>& s_feature_PE35_3,
    hls::stream<W_TYPE>& s_feature_PE36_0, hls::stream<W_TYPE>& s_feature_PE36_1,
    hls::stream<W_TYPE>& s_feature_PE36_2, hls::stream<W_TYPE>& s_feature_PE36_3,
    hls::stream<W_TYPE>& s_feature_PE37_0, hls::stream<W_TYPE>& s_feature_PE37_1,
    hls::stream<W_TYPE>& s_feature_PE37_2, hls::stream<W_TYPE>& s_feature_PE37_3,
    hls::stream<W_TYPE>& s_feature_PE38_0, hls::stream<W_TYPE>& s_feature_PE38_1,
    hls::stream<W_TYPE>& s_feature_PE38_2, hls::stream<W_TYPE>& s_feature_PE38_3,
    hls::stream<W_TYPE>& s_feature_PE39_0, hls::stream<W_TYPE>& s_feature_PE39_1,
    hls::stream<W_TYPE>& s_feature_PE39_2, hls::stream<W_TYPE>& s_feature_PE39_3,
    hls::stream<W_TYPE>& s_feature_PE40_0, hls::stream<W_TYPE>& s_feature_PE40_1,
    hls::stream<W_TYPE>& s_feature_PE40_2, hls::stream<W_TYPE>& s_feature_PE40_3,
    hls::stream<W_TYPE>& s_feature_PE41_0, hls::stream<W_TYPE>& s_feature_PE41_1,
    hls::stream<W_TYPE>& s_feature_PE41_2, hls::stream<W_TYPE>& s_feature_PE41_3,
    hls::stream<W_TYPE>& s_feature_PE42_0, hls::stream<W_TYPE>& s_feature_PE42_1,
    hls::stream<W_TYPE>& s_feature_PE42_2, hls::stream<W_TYPE>& s_feature_PE42_3,
    hls::stream<W_TYPE>& s_feature_PE43_0, hls::stream<W_TYPE>& s_feature_PE43_1,
    hls::stream<W_TYPE>& s_feature_PE43_2, hls::stream<W_TYPE>& s_feature_PE43_3,
    hls::stream<W_TYPE>& s_feature_PE44_0, hls::stream<W_TYPE>& s_feature_PE44_1,
    hls::stream<W_TYPE>& s_feature_PE44_2, hls::stream<W_TYPE>& s_feature_PE44_3,
    hls::stream<W_TYPE>& s_feature_PE45_0, hls::stream<W_TYPE>& s_feature_PE45_1,
    hls::stream<W_TYPE>& s_feature_PE45_2, hls::stream<W_TYPE>& s_feature_PE45_3,
    hls::stream<W_TYPE>& s_feature_PE46_0, hls::stream<W_TYPE>& s_feature_PE46_1,
    hls::stream<W_TYPE>& s_feature_PE46_2, hls::stream<W_TYPE>& s_feature_PE46_3,
    hls::stream<W_TYPE>& s_feature_PE47_0, hls::stream<W_TYPE>& s_feature_PE47_1,
    hls::stream<W_TYPE>& s_feature_PE47_2, hls::stream<W_TYPE>& s_feature_PE47_3,
    hls::stream<W_TYPE>& s_feature_PE48_0, hls::stream<W_TYPE>& s_feature_PE48_1,
    hls::stream<W_TYPE>& s_feature_PE48_2, hls::stream<W_TYPE>& s_feature_PE48_3,
    hls::stream<W_TYPE>& s_feature_PE49_0, hls::stream<W_TYPE>& s_feature_PE49_1,
    hls::stream<W_TYPE>& s_feature_PE49_2, hls::stream<W_TYPE>& s_feature_PE49_3,
    hls::stream<W_TYPE>& s_feature_PE50_0, hls::stream<W_TYPE>& s_feature_PE50_1,
    hls::stream<W_TYPE>& s_feature_PE50_2, hls::stream<W_TYPE>& s_feature_PE50_3,
    hls::stream<W_TYPE>& s_feature_PE51_0, hls::stream<W_TYPE>& s_feature_PE51_1,
    hls::stream<W_TYPE>& s_feature_PE51_2, hls::stream<W_TYPE>& s_feature_PE51_3,
    hls::stream<W_TYPE>& s_feature_PE52_0, hls::stream<W_TYPE>& s_feature_PE52_1,
    hls::stream<W_TYPE>& s_feature_PE52_2, hls::stream<W_TYPE>& s_feature_PE52_3,
    hls::stream<W_TYPE>& s_feature_PE53_0, hls::stream<W_TYPE>& s_feature_PE53_1,
    hls::stream<W_TYPE>& s_feature_PE53_2, hls::stream<W_TYPE>& s_feature_PE53_3,
    hls::stream<W_TYPE>& s_feature_PE54_0, hls::stream<W_TYPE>& s_feature_PE54_1,
    hls::stream<W_TYPE>& s_feature_PE54_2, hls::stream<W_TYPE>& s_feature_PE54_3,
    hls::stream<W_TYPE>& s_feature_PE55_0, hls::stream<W_TYPE>& s_feature_PE55_1,
    hls::stream<W_TYPE>& s_feature_PE55_2, hls::stream<W_TYPE>& s_feature_PE55_3,
    hls::stream<W_TYPE>& s_feature_PE56_0, hls::stream<W_TYPE>& s_feature_PE56_1,
    hls::stream<W_TYPE>& s_feature_PE56_2, hls::stream<W_TYPE>& s_feature_PE56_3,
    hls::stream<W_TYPE>& s_feature_PE57_0, hls::stream<W_TYPE>& s_feature_PE57_1,
    hls::stream<W_TYPE>& s_feature_PE57_2, hls::stream<W_TYPE>& s_feature_PE57_3,
    hls::stream<W_TYPE>& s_feature_PE58_0, hls::stream<W_TYPE>& s_feature_PE58_1,
    hls::stream<W_TYPE>& s_feature_PE58_2, hls::stream<W_TYPE>& s_feature_PE58_3,
    hls::stream<W_TYPE>& s_feature_PE59_0, hls::stream<W_TYPE>& s_feature_PE59_1,
    hls::stream<W_TYPE>& s_feature_PE59_2, hls::stream<W_TYPE>& s_feature_PE59_3,
    hls::stream<W_TYPE>& s_feature_PE60_0, hls::stream<W_TYPE>& s_feature_PE60_1,
    hls::stream<W_TYPE>& s_feature_PE60_2, hls::stream<W_TYPE>& s_feature_PE60_3,
    hls::stream<W_TYPE>& s_feature_PE61_0, hls::stream<W_TYPE>& s_feature_PE61_1,
    hls::stream<W_TYPE>& s_feature_PE61_2, hls::stream<W_TYPE>& s_feature_PE61_3,
    hls::stream<W_TYPE>& s_feature_PE62_0, hls::stream<W_TYPE>& s_feature_PE62_1,
    hls::stream<W_TYPE>& s_feature_PE62_2, hls::stream<W_TYPE>& s_feature_PE62_3,
    hls::stream<W_TYPE>& s_feature_PE63_0, hls::stream<W_TYPE>& s_feature_PE63_1,
    hls::stream<W_TYPE>& s_feature_PE63_2, hls::stream<W_TYPE>& s_feature_PE63_3,
    hls::stream<W_TYPE>& s_feature_PE64_0, hls::stream<W_TYPE>& s_feature_PE64_1,
    hls::stream<W_TYPE>& s_feature_PE64_2, hls::stream<W_TYPE>& s_feature_PE64_3,
    hls::stream<W_TYPE>& s_feature_PE65_0, hls::stream<W_TYPE>& s_feature_PE65_1,
    hls::stream<W_TYPE>& s_feature_PE65_2, hls::stream<W_TYPE>& s_feature_PE65_3,
    hls::stream<W_TYPE>& s_feature_PE66_0, hls::stream<W_TYPE>& s_feature_PE66_1,
    hls::stream<W_TYPE>& s_feature_PE66_2, hls::stream<W_TYPE>& s_feature_PE66_3,
    hls::stream<W_TYPE>& s_feature_PE67_0, hls::stream<W_TYPE>& s_feature_PE67_1,
    hls::stream<W_TYPE>& s_feature_PE67_2, hls::stream<W_TYPE>& s_feature_PE67_3,
    hls::stream<W_TYPE>& s_feature_PE68_0, hls::stream<W_TYPE>& s_feature_PE68_1,
    hls::stream<W_TYPE>& s_feature_PE68_2, hls::stream<W_TYPE>& s_feature_PE68_3,
    hls::stream<W_TYPE>& s_feature_PE69_0, hls::stream<W_TYPE>& s_feature_PE69_1,
    hls::stream<W_TYPE>& s_feature_PE69_2, hls::stream<W_TYPE>& s_feature_PE69_3,
    hls::stream<W_TYPE>& s_feature_PE70_0, hls::stream<W_TYPE>& s_feature_PE70_1,
    hls::stream<W_TYPE>& s_feature_PE70_2, hls::stream<W_TYPE>& s_feature_PE70_3,
    hls::stream<W_TYPE>& s_feature_PE71_0, hls::stream<W_TYPE>& s_feature_PE71_1,
    hls::stream<W_TYPE>& s_feature_PE71_2, hls::stream<W_TYPE>& s_feature_PE71_3,
    hls::stream<W_TYPE>& s_feature_PE72_0, hls::stream<W_TYPE>& s_feature_PE72_1,
    hls::stream<W_TYPE>& s_feature_PE72_2, hls::stream<W_TYPE>& s_feature_PE72_3,
    hls::stream<W_TYPE>& s_feature_PE73_0, hls::stream<W_TYPE>& s_feature_PE73_1,
    hls::stream<W_TYPE>& s_feature_PE73_2, hls::stream<W_TYPE>& s_feature_PE73_3,
    hls::stream<W_TYPE>& s_feature_PE74_0, hls::stream<W_TYPE>& s_feature_PE74_1,
    hls::stream<W_TYPE>& s_feature_PE74_2, hls::stream<W_TYPE>& s_feature_PE74_3,
    hls::stream<W_TYPE>& s_feature_PE75_0, hls::stream<W_TYPE>& s_feature_PE75_1,
    hls::stream<W_TYPE>& s_feature_PE75_2, hls::stream<W_TYPE>& s_feature_PE75_3,
    hls::stream<W_TYPE>& s_feature_PE76_0, hls::stream<W_TYPE>& s_feature_PE76_1,
    hls::stream<W_TYPE>& s_feature_PE76_2, hls::stream<W_TYPE>& s_feature_PE76_3,
    hls::stream<W_TYPE>& s_feature_PE77_0, hls::stream<W_TYPE>& s_feature_PE77_1,
    hls::stream<W_TYPE>& s_feature_PE77_2, hls::stream<W_TYPE>& s_feature_PE77_3,
    hls::stream<W_TYPE>& s_feature_PE78_0, hls::stream<W_TYPE>& s_feature_PE78_1,
    hls::stream<W_TYPE>& s_feature_PE78_2, hls::stream<W_TYPE>& s_feature_PE78_3,
    hls::stream<W_TYPE>& s_feature_PE79_0, hls::stream<W_TYPE>& s_feature_PE79_1,
    hls::stream<W_TYPE>& s_feature_PE79_2, hls::stream<W_TYPE>& s_feature_PE79_3,
    hls::stream<W_TYPE>& s_feature_PE80_0, hls::stream<W_TYPE>& s_feature_PE80_1,
    hls::stream<W_TYPE>& s_feature_PE80_2, hls::stream<W_TYPE>& s_feature_PE80_3,
    hls::stream<W_TYPE>& s_feature_PE81_0, hls::stream<W_TYPE>& s_feature_PE81_1,
    hls::stream<W_TYPE>& s_feature_PE81_2, hls::stream<W_TYPE>& s_feature_PE81_3,
    hls::stream<W_TYPE>& s_feature_PE82_0, hls::stream<W_TYPE>& s_feature_PE82_1,
    hls::stream<W_TYPE>& s_feature_PE82_2, hls::stream<W_TYPE>& s_feature_PE82_3,
    hls::stream<W_TYPE>& s_feature_PE83_0, hls::stream<W_TYPE>& s_feature_PE83_1,
    hls::stream<W_TYPE>& s_feature_PE83_2, hls::stream<W_TYPE>& s_feature_PE83_3,
    hls::stream<W_TYPE>& s_feature_PE84_0, hls::stream<W_TYPE>& s_feature_PE84_1,
    hls::stream<W_TYPE>& s_feature_PE84_2, hls::stream<W_TYPE>& s_feature_PE84_3,
    hls::stream<W_TYPE>& s_feature_PE85_0, hls::stream<W_TYPE>& s_feature_PE85_1,
    hls::stream<W_TYPE>& s_feature_PE85_2, hls::stream<W_TYPE>& s_feature_PE85_3,
    hls::stream<W_TYPE>& s_feature_PE86_0, hls::stream<W_TYPE>& s_feature_PE86_1,
    hls::stream<W_TYPE>& s_feature_PE86_2, hls::stream<W_TYPE>& s_feature_PE86_3,
    hls::stream<W_TYPE>& s_feature_PE87_0, hls::stream<W_TYPE>& s_feature_PE87_1,
    hls::stream<W_TYPE>& s_feature_PE87_2, hls::stream<W_TYPE>& s_feature_PE87_3,
    hls::stream<W_TYPE>& s_feature_PE88_0, hls::stream<W_TYPE>& s_feature_PE88_1,
    hls::stream<W_TYPE>& s_feature_PE88_2, hls::stream<W_TYPE>& s_feature_PE88_3,
    hls::stream<W_TYPE>& s_feature_PE89_0, hls::stream<W_TYPE>& s_feature_PE89_1,
    hls::stream<W_TYPE>& s_feature_PE89_2, hls::stream<W_TYPE>& s_feature_PE89_3,
    hls::stream<W_TYPE>& s_feature_PE90_0, hls::stream<W_TYPE>& s_feature_PE90_1,
    hls::stream<W_TYPE>& s_feature_PE90_2, hls::stream<W_TYPE>& s_feature_PE90_3,
    hls::stream<W_TYPE>& s_feature_PE91_0, hls::stream<W_TYPE>& s_feature_PE91_1,
    hls::stream<W_TYPE>& s_feature_PE91_2, hls::stream<W_TYPE>& s_feature_PE91_3,
    hls::stream<W_TYPE>& s_feature_PE92_0, hls::stream<W_TYPE>& s_feature_PE92_1,
    hls::stream<W_TYPE>& s_feature_PE92_2, hls::stream<W_TYPE>& s_feature_PE92_3,
    hls::stream<W_TYPE>& s_feature_PE93_0, hls::stream<W_TYPE>& s_feature_PE93_1,
    hls::stream<W_TYPE>& s_feature_PE93_2, hls::stream<W_TYPE>& s_feature_PE93_3,
    hls::stream<W_TYPE>& s_feature_PE94_0, hls::stream<W_TYPE>& s_feature_PE94_1,
    hls::stream<W_TYPE>& s_feature_PE94_2, hls::stream<W_TYPE>& s_feature_PE94_3,
    hls::stream<W_TYPE>& s_feature_PE95_0, hls::stream<W_TYPE>& s_feature_PE95_1,
    hls::stream<W_TYPE>& s_feature_PE95_2, hls::stream<W_TYPE>& s_feature_PE95_3,
    hls::stream<W_TYPE>& s_feature_PE96_0, hls::stream<W_TYPE>& s_feature_PE96_1,
    hls::stream<W_TYPE>& s_feature_PE96_2, hls::stream<W_TYPE>& s_feature_PE96_3,
    hls::stream<W_TYPE>& s_feature_PE97_0, hls::stream<W_TYPE>& s_feature_PE97_1,
    hls::stream<W_TYPE>& s_feature_PE97_2, hls::stream<W_TYPE>& s_feature_PE97_3,
    hls::stream<W_TYPE>& s_feature_PE98_0, hls::stream<W_TYPE>& s_feature_PE98_1,
    hls::stream<W_TYPE>& s_feature_PE98_2, hls::stream<W_TYPE>& s_feature_PE98_3,
    hls::stream<W_TYPE>& s_feature_PE99_0, hls::stream<W_TYPE>& s_feature_PE99_1,
    hls::stream<W_TYPE>& s_feature_PE99_2, hls::stream<W_TYPE>& s_feature_PE99_3,
    hls::stream<W_TYPE>& s_feature_PE100_0, hls::stream<W_TYPE>& s_feature_PE100_1,
    hls::stream<W_TYPE>& s_feature_PE100_2, hls::stream<W_TYPE>& s_feature_PE100_3,
    hls::stream<W_TYPE>& s_feature_PE101_0, hls::stream<W_TYPE>& s_feature_PE101_1,
    hls::stream<W_TYPE>& s_feature_PE101_2, hls::stream<W_TYPE>& s_feature_PE101_3,
    hls::stream<W_TYPE>& s_feature_PE102_0, hls::stream<W_TYPE>& s_feature_PE102_1,
    hls::stream<W_TYPE>& s_feature_PE102_2, hls::stream<W_TYPE>& s_feature_PE102_3,
    hls::stream<W_TYPE>& s_feature_PE103_0, hls::stream<W_TYPE>& s_feature_PE103_1,
    hls::stream<W_TYPE>& s_feature_PE103_2, hls::stream<W_TYPE>& s_feature_PE103_3,
    hls::stream<W_TYPE>& s_feature_PE104_0, hls::stream<W_TYPE>& s_feature_PE104_1,
    hls::stream<W_TYPE>& s_feature_PE104_2, hls::stream<W_TYPE>& s_feature_PE104_3,
    hls::stream<W_TYPE>& s_feature_PE105_0, hls::stream<W_TYPE>& s_feature_PE105_1,
    hls::stream<W_TYPE>& s_feature_PE105_2, hls::stream<W_TYPE>& s_feature_PE105_3,
    hls::stream<W_TYPE>& s_feature_PE106_0, hls::stream<W_TYPE>& s_feature_PE106_1,
    hls::stream<W_TYPE>& s_feature_PE106_2, hls::stream<W_TYPE>& s_feature_PE106_3,
    hls::stream<W_TYPE>& s_feature_PE107_0, hls::stream<W_TYPE>& s_feature_PE107_1,
    hls::stream<W_TYPE>& s_feature_PE107_2, hls::stream<W_TYPE>& s_feature_PE107_3,
    hls::stream<W_TYPE>& s_feature_PE108_0, hls::stream<W_TYPE>& s_feature_PE108_1,
    hls::stream<W_TYPE>& s_feature_PE108_2, hls::stream<W_TYPE>& s_feature_PE108_3,
    hls::stream<W_TYPE>& s_feature_PE109_0, hls::stream<W_TYPE>& s_feature_PE109_1,
    hls::stream<W_TYPE>& s_feature_PE109_2, hls::stream<W_TYPE>& s_feature_PE109_3,
    hls::stream<W_TYPE>& s_feature_PE110_0, hls::stream<W_TYPE>& s_feature_PE110_1,
    hls::stream<W_TYPE>& s_feature_PE110_2, hls::stream<W_TYPE>& s_feature_PE110_3,
    hls::stream<W_TYPE>& s_feature_PE111_0, hls::stream<W_TYPE>& s_feature_PE111_1,
    hls::stream<W_TYPE>& s_feature_PE111_2, hls::stream<W_TYPE>& s_feature_PE111_3,
    hls::stream<W_TYPE>& s_feature_PE112_0, hls::stream<W_TYPE>& s_feature_PE112_1,
    hls::stream<W_TYPE>& s_feature_PE112_2, hls::stream<W_TYPE>& s_feature_PE112_3,
    hls::stream<W_TYPE>& s_feature_PE113_0, hls::stream<W_TYPE>& s_feature_PE113_1,
    hls::stream<W_TYPE>& s_feature_PE113_2, hls::stream<W_TYPE>& s_feature_PE113_3,
    hls::stream<W_TYPE>& s_feature_PE114_0, hls::stream<W_TYPE>& s_feature_PE114_1,
    hls::stream<W_TYPE>& s_feature_PE114_2, hls::stream<W_TYPE>& s_feature_PE114_3,
    hls::stream<W_TYPE>& s_feature_PE115_0, hls::stream<W_TYPE>& s_feature_PE115_1,
    hls::stream<W_TYPE>& s_feature_PE115_2, hls::stream<W_TYPE>& s_feature_PE115_3,
    hls::stream<W_TYPE>& s_feature_PE116_0, hls::stream<W_TYPE>& s_feature_PE116_1,
    hls::stream<W_TYPE>& s_feature_PE116_2, hls::stream<W_TYPE>& s_feature_PE116_3,
    hls::stream<W_TYPE>& s_feature_PE117_0, hls::stream<W_TYPE>& s_feature_PE117_1,
    hls::stream<W_TYPE>& s_feature_PE117_2, hls::stream<W_TYPE>& s_feature_PE117_3,
    hls::stream<W_TYPE>& s_feature_PE118_0, hls::stream<W_TYPE>& s_feature_PE118_1,
    hls::stream<W_TYPE>& s_feature_PE118_2, hls::stream<W_TYPE>& s_feature_PE118_3,
    hls::stream<W_TYPE>& s_feature_PE119_0, hls::stream<W_TYPE>& s_feature_PE119_1,
    hls::stream<W_TYPE>& s_feature_PE119_2, hls::stream<W_TYPE>& s_feature_PE119_3,
    hls::stream<W_TYPE>& s_feature_PE120_0, hls::stream<W_TYPE>& s_feature_PE120_1,
    hls::stream<W_TYPE>& s_feature_PE120_2, hls::stream<W_TYPE>& s_feature_PE120_3,
    hls::stream<W_TYPE>& s_feature_PE121_0, hls::stream<W_TYPE>& s_feature_PE121_1,
    hls::stream<W_TYPE>& s_feature_PE121_2, hls::stream<W_TYPE>& s_feature_PE121_3,
    hls::stream<W_TYPE>& s_feature_PE122_0, hls::stream<W_TYPE>& s_feature_PE122_1,
    hls::stream<W_TYPE>& s_feature_PE122_2, hls::stream<W_TYPE>& s_feature_PE122_3,
    hls::stream<W_TYPE>& s_feature_PE123_0, hls::stream<W_TYPE>& s_feature_PE123_1,
    hls::stream<W_TYPE>& s_feature_PE123_2, hls::stream<W_TYPE>& s_feature_PE123_3,
    hls::stream<W_TYPE>& s_feature_PE124_0, hls::stream<W_TYPE>& s_feature_PE124_1,
    hls::stream<W_TYPE>& s_feature_PE124_2, hls::stream<W_TYPE>& s_feature_PE124_3,
    hls::stream<W_TYPE>& s_feature_PE125_0, hls::stream<W_TYPE>& s_feature_PE125_1,
    hls::stream<W_TYPE>& s_feature_PE125_2, hls::stream<W_TYPE>& s_feature_PE125_3,
    hls::stream<W_TYPE>& s_feature_PE126_0, hls::stream<W_TYPE>& s_feature_PE126_1,
    hls::stream<W_TYPE>& s_feature_PE126_2, hls::stream<W_TYPE>& s_feature_PE126_3,
    hls::stream<W_TYPE>& s_feature_PE127_0, hls::stream<W_TYPE>& s_feature_PE127_1,
    hls::stream<W_TYPE>& s_feature_PE127_2, hls::stream<W_TYPE>& s_feature_PE127_3,
    hls::stream<W_TYPE>& s_feature_PE128_0, hls::stream<W_TYPE>& s_feature_PE128_1,
    hls::stream<W_TYPE>& s_feature_PE128_2, hls::stream<W_TYPE>& s_feature_PE128_3,
    hls::stream<W_TYPE>& s_feature_PE129_0, hls::stream<W_TYPE>& s_feature_PE129_1,
    hls::stream<W_TYPE>& s_feature_PE129_2, hls::stream<W_TYPE>& s_feature_PE129_3,
    hls::stream<W_TYPE>& s_feature_PE130_0, hls::stream<W_TYPE>& s_feature_PE130_1,
    hls::stream<W_TYPE>& s_feature_PE130_2, hls::stream<W_TYPE>& s_feature_PE130_3,
    hls::stream<W_TYPE>& s_feature_PE131_0, hls::stream<W_TYPE>& s_feature_PE131_1,
    hls::stream<W_TYPE>& s_feature_PE131_2, hls::stream<W_TYPE>& s_feature_PE131_3,
    hls::stream<W_TYPE>& s_feature_PE132_0, hls::stream<W_TYPE>& s_feature_PE132_1,
    hls::stream<W_TYPE>& s_feature_PE132_2, hls::stream<W_TYPE>& s_feature_PE132_3,
    hls::stream<W_TYPE>& s_feature_PE133_0, hls::stream<W_TYPE>& s_feature_PE133_1,
    hls::stream<W_TYPE>& s_feature_PE133_2, hls::stream<W_TYPE>& s_feature_PE133_3,
    hls::stream<W_TYPE>& s_feature_PE134_0, hls::stream<W_TYPE>& s_feature_PE134_1,
    hls::stream<W_TYPE>& s_feature_PE134_2, hls::stream<W_TYPE>& s_feature_PE134_3,
    hls::stream<W_TYPE>& s_feature_PE135_0, hls::stream<W_TYPE>& s_feature_PE135_1,
    hls::stream<W_TYPE>& s_feature_PE135_2, hls::stream<W_TYPE>& s_feature_PE135_3,
    hls::stream<W_TYPE>& s_feature_PE136_0, hls::stream<W_TYPE>& s_feature_PE136_1,
    hls::stream<W_TYPE>& s_feature_PE136_2, hls::stream<W_TYPE>& s_feature_PE136_3,
    hls::stream<W_TYPE>& s_feature_PE137_0, hls::stream<W_TYPE>& s_feature_PE137_1,
    hls::stream<W_TYPE>& s_feature_PE137_2, hls::stream<W_TYPE>& s_feature_PE137_3,
    hls::stream<W_TYPE>& s_feature_PE138_0, hls::stream<W_TYPE>& s_feature_PE138_1,
    hls::stream<W_TYPE>& s_feature_PE138_2, hls::stream<W_TYPE>& s_feature_PE138_3,
    hls::stream<W_TYPE>& s_feature_PE139_0, hls::stream<W_TYPE>& s_feature_PE139_1,
    hls::stream<W_TYPE>& s_feature_PE139_2, hls::stream<W_TYPE>& s_feature_PE139_3,
    hls::stream<W_TYPE>& s_feature_PE140_0, hls::stream<W_TYPE>& s_feature_PE140_1,
    hls::stream<W_TYPE>& s_feature_PE140_2, hls::stream<W_TYPE>& s_feature_PE140_3,
    hls::stream<W_TYPE>& s_feature_PE141_0, hls::stream<W_TYPE>& s_feature_PE141_1,
    hls::stream<W_TYPE>& s_feature_PE141_2, hls::stream<W_TYPE>& s_feature_PE141_3,
    hls::stream<W_TYPE>& s_feature_PE142_0, hls::stream<W_TYPE>& s_feature_PE142_1,
    hls::stream<W_TYPE>& s_feature_PE142_2, hls::stream<W_TYPE>& s_feature_PE142_3,
    hls::stream<W_TYPE>& s_feature_PE143_0, hls::stream<W_TYPE>& s_feature_PE143_1,
    hls::stream<W_TYPE>& s_feature_PE143_2, hls::stream<W_TYPE>& s_feature_PE143_3,
    hls::stream<W_TYPE>& s_feature_PE144_0, hls::stream<W_TYPE>& s_feature_PE144_1,
    hls::stream<W_TYPE>& s_feature_PE144_2, hls::stream<W_TYPE>& s_feature_PE144_3,
    hls::stream<W_TYPE>& s_feature_PE145_0, hls::stream<W_TYPE>& s_feature_PE145_1,
    hls::stream<W_TYPE>& s_feature_PE145_2, hls::stream<W_TYPE>& s_feature_PE145_3,
    hls::stream<W_TYPE>& s_feature_PE146_0, hls::stream<W_TYPE>& s_feature_PE146_1,
    hls::stream<W_TYPE>& s_feature_PE146_2, hls::stream<W_TYPE>& s_feature_PE146_3,
    hls::stream<W_TYPE>& s_feature_PE147_0, hls::stream<W_TYPE>& s_feature_PE147_1,
    hls::stream<W_TYPE>& s_feature_PE147_2, hls::stream<W_TYPE>& s_feature_PE147_3,
    hls::stream<W_TYPE>& s_feature_PE148_0, hls::stream<W_TYPE>& s_feature_PE148_1,
    hls::stream<W_TYPE>& s_feature_PE148_2, hls::stream<W_TYPE>& s_feature_PE148_3,
    hls::stream<W_TYPE>& s_feature_PE149_0, hls::stream<W_TYPE>& s_feature_PE149_1,
    hls::stream<W_TYPE>& s_feature_PE149_2, hls::stream<W_TYPE>& s_feature_PE149_3,
    hls::stream<W_TYPE>& s_feature_PE150_0, hls::stream<W_TYPE>& s_feature_PE150_1,
    hls::stream<W_TYPE>& s_feature_PE150_2, hls::stream<W_TYPE>& s_feature_PE150_3,
    hls::stream<W_TYPE>& s_feature_PE151_0, hls::stream<W_TYPE>& s_feature_PE151_1,
    hls::stream<W_TYPE>& s_feature_PE151_2, hls::stream<W_TYPE>& s_feature_PE151_3,
    hls::stream<W_TYPE>& s_feature_PE152_0, hls::stream<W_TYPE>& s_feature_PE152_1,
    hls::stream<W_TYPE>& s_feature_PE152_2, hls::stream<W_TYPE>& s_feature_PE152_3,
    hls::stream<W_TYPE>& s_feature_PE153_0, hls::stream<W_TYPE>& s_feature_PE153_1,
    hls::stream<W_TYPE>& s_feature_PE153_2, hls::stream<W_TYPE>& s_feature_PE153_3,
    hls::stream<W_TYPE>& s_feature_PE154_0, hls::stream<W_TYPE>& s_feature_PE154_1,
    hls::stream<W_TYPE>& s_feature_PE154_2, hls::stream<W_TYPE>& s_feature_PE154_3,
    hls::stream<W_TYPE>& s_feature_PE155_0, hls::stream<W_TYPE>& s_feature_PE155_1,
    hls::stream<W_TYPE>& s_feature_PE155_2, hls::stream<W_TYPE>& s_feature_PE155_3,
    hls::stream<W_TYPE>& s_feature_PE156_0, hls::stream<W_TYPE>& s_feature_PE156_1,
    hls::stream<W_TYPE>& s_feature_PE156_2, hls::stream<W_TYPE>& s_feature_PE156_3,
    hls::stream<W_TYPE>& s_feature_PE157_0, hls::stream<W_TYPE>& s_feature_PE157_1,
    hls::stream<W_TYPE>& s_feature_PE157_2, hls::stream<W_TYPE>& s_feature_PE157_3,
    hls::stream<W_TYPE>& s_feature_PE158_0, hls::stream<W_TYPE>& s_feature_PE158_1,
    hls::stream<W_TYPE>& s_feature_PE158_2, hls::stream<W_TYPE>& s_feature_PE158_3,
    hls::stream<W_TYPE>& s_feature_PE159_0, hls::stream<W_TYPE>& s_feature_PE159_1,
    hls::stream<W_TYPE>& s_feature_PE159_2, hls::stream<W_TYPE>& s_feature_PE159_3
);

template<const int FEATURE_SIZE>
void replicate_feature_512PEs_80PE(
    hls::stream<ap_uint<512> >& s_feature_in, 
    hls::stream<W_TYPE>& s_feature_PE0_0, hls::stream<W_TYPE>& s_feature_PE0_1,
    hls::stream<W_TYPE>& s_feature_PE0_2, hls::stream<W_TYPE>& s_feature_PE0_3,
    hls::stream<W_TYPE>& s_feature_PE1_0, hls::stream<W_TYPE>& s_feature_PE1_1,
    hls::stream<W_TYPE>& s_feature_PE1_2, hls::stream<W_TYPE>& s_feature_PE1_3,
    hls::stream<W_TYPE>& s_feature_PE2_0, hls::stream<W_TYPE>& s_feature_PE2_1,
    hls::stream<W_TYPE>& s_feature_PE2_2, hls::stream<W_TYPE>& s_feature_PE2_3,
    hls::stream<W_TYPE>& s_feature_PE3_0, hls::stream<W_TYPE>& s_feature_PE3_1,
    hls::stream<W_TYPE>& s_feature_PE3_2, hls::stream<W_TYPE>& s_feature_PE3_3,
    hls::stream<W_TYPE>& s_feature_PE4_0, hls::stream<W_TYPE>& s_feature_PE4_1,
    hls::stream<W_TYPE>& s_feature_PE4_2, hls::stream<W_TYPE>& s_feature_PE4_3,
    hls::stream<W_TYPE>& s_feature_PE5_0, hls::stream<W_TYPE>& s_feature_PE5_1,
    hls::stream<W_TYPE>& s_feature_PE5_2, hls::stream<W_TYPE>& s_feature_PE5_3,
    hls::stream<W_TYPE>& s_feature_PE6_0, hls::stream<W_TYPE>& s_feature_PE6_1,
    hls::stream<W_TYPE>& s_feature_PE6_2, hls::stream<W_TYPE>& s_feature_PE6_3,
    hls::stream<W_TYPE>& s_feature_PE7_0, hls::stream<W_TYPE>& s_feature_PE7_1,
    hls::stream<W_TYPE>& s_feature_PE7_2, hls::stream<W_TYPE>& s_feature_PE7_3,
    hls::stream<W_TYPE>& s_feature_PE8_0, hls::stream<W_TYPE>& s_feature_PE8_1,
    hls::stream<W_TYPE>& s_feature_PE8_2, hls::stream<W_TYPE>& s_feature_PE8_3,
    hls::stream<W_TYPE>& s_feature_PE9_0, hls::stream<W_TYPE>& s_feature_PE9_1,
    hls::stream<W_TYPE>& s_feature_PE9_2, hls::stream<W_TYPE>& s_feature_PE9_3,
    hls::stream<W_TYPE>& s_feature_PE10_0, hls::stream<W_TYPE>& s_feature_PE10_1,
    hls::stream<W_TYPE>& s_feature_PE10_2, hls::stream<W_TYPE>& s_feature_PE10_3,
    hls::stream<W_TYPE>& s_feature_PE11_0, hls::stream<W_TYPE>& s_feature_PE11_1,
    hls::stream<W_TYPE>& s_feature_PE11_2, hls::stream<W_TYPE>& s_feature_PE11_3,
    hls::stream<W_TYPE>& s_feature_PE12_0, hls::stream<W_TYPE>& s_feature_PE12_1,
    hls::stream<W_TYPE>& s_feature_PE12_2, hls::stream<W_TYPE>& s_feature_PE12_3,
    hls::stream<W_TYPE>& s_feature_PE13_0, hls::stream<W_TYPE>& s_feature_PE13_1,
    hls::stream<W_TYPE>& s_feature_PE13_2, hls::stream<W_TYPE>& s_feature_PE13_3,
    hls::stream<W_TYPE>& s_feature_PE14_0, hls::stream<W_TYPE>& s_feature_PE14_1,
    hls::stream<W_TYPE>& s_feature_PE14_2, hls::stream<W_TYPE>& s_feature_PE14_3,
    hls::stream<W_TYPE>& s_feature_PE15_0, hls::stream<W_TYPE>& s_feature_PE15_1,
    hls::stream<W_TYPE>& s_feature_PE15_2, hls::stream<W_TYPE>& s_feature_PE15_3,
    hls::stream<W_TYPE>& s_feature_PE16_0, hls::stream<W_TYPE>& s_feature_PE16_1,
    hls::stream<W_TYPE>& s_feature_PE16_2, hls::stream<W_TYPE>& s_feature_PE16_3,
    hls::stream<W_TYPE>& s_feature_PE17_0, hls::stream<W_TYPE>& s_feature_PE17_1,
    hls::stream<W_TYPE>& s_feature_PE17_2, hls::stream<W_TYPE>& s_feature_PE17_3,
    hls::stream<W_TYPE>& s_feature_PE18_0, hls::stream<W_TYPE>& s_feature_PE18_1,
    hls::stream<W_TYPE>& s_feature_PE18_2, hls::stream<W_TYPE>& s_feature_PE18_3,
    hls::stream<W_TYPE>& s_feature_PE19_0, hls::stream<W_TYPE>& s_feature_PE19_1,
    hls::stream<W_TYPE>& s_feature_PE19_2, hls::stream<W_TYPE>& s_feature_PE19_3,
    hls::stream<W_TYPE>& s_feature_PE20_0, hls::stream<W_TYPE>& s_feature_PE20_1,
    hls::stream<W_TYPE>& s_feature_PE20_2, hls::stream<W_TYPE>& s_feature_PE20_3,
    hls::stream<W_TYPE>& s_feature_PE21_0, hls::stream<W_TYPE>& s_feature_PE21_1,
    hls::stream<W_TYPE>& s_feature_PE21_2, hls::stream<W_TYPE>& s_feature_PE21_3,
    hls::stream<W_TYPE>& s_feature_PE22_0, hls::stream<W_TYPE>& s_feature_PE22_1,
    hls::stream<W_TYPE>& s_feature_PE22_2, hls::stream<W_TYPE>& s_feature_PE22_3,
    hls::stream<W_TYPE>& s_feature_PE23_0, hls::stream<W_TYPE>& s_feature_PE23_1,
    hls::stream<W_TYPE>& s_feature_PE23_2, hls::stream<W_TYPE>& s_feature_PE23_3,
    hls::stream<W_TYPE>& s_feature_PE24_0, hls::stream<W_TYPE>& s_feature_PE24_1,
    hls::stream<W_TYPE>& s_feature_PE24_2, hls::stream<W_TYPE>& s_feature_PE24_3,
    hls::stream<W_TYPE>& s_feature_PE25_0, hls::stream<W_TYPE>& s_feature_PE25_1,
    hls::stream<W_TYPE>& s_feature_PE25_2, hls::stream<W_TYPE>& s_feature_PE25_3,
    hls::stream<W_TYPE>& s_feature_PE26_0, hls::stream<W_TYPE>& s_feature_PE26_1,
    hls::stream<W_TYPE>& s_feature_PE26_2, hls::stream<W_TYPE>& s_feature_PE26_3,
    hls::stream<W_TYPE>& s_feature_PE27_0, hls::stream<W_TYPE>& s_feature_PE27_1,
    hls::stream<W_TYPE>& s_feature_PE27_2, hls::stream<W_TYPE>& s_feature_PE27_3,
    hls::stream<W_TYPE>& s_feature_PE28_0, hls::stream<W_TYPE>& s_feature_PE28_1,
    hls::stream<W_TYPE>& s_feature_PE28_2, hls::stream<W_TYPE>& s_feature_PE28_3,
    hls::stream<W_TYPE>& s_feature_PE29_0, hls::stream<W_TYPE>& s_feature_PE29_1,
    hls::stream<W_TYPE>& s_feature_PE29_2, hls::stream<W_TYPE>& s_feature_PE29_3,
    hls::stream<W_TYPE>& s_feature_PE30_0, hls::stream<W_TYPE>& s_feature_PE30_1,
    hls::stream<W_TYPE>& s_feature_PE30_2, hls::stream<W_TYPE>& s_feature_PE30_3,
    hls::stream<W_TYPE>& s_feature_PE31_0, hls::stream<W_TYPE>& s_feature_PE31_1,
    hls::stream<W_TYPE>& s_feature_PE31_2, hls::stream<W_TYPE>& s_feature_PE31_3,
    hls::stream<W_TYPE>& s_feature_PE32_0, hls::stream<W_TYPE>& s_feature_PE32_1,
    hls::stream<W_TYPE>& s_feature_PE32_2, hls::stream<W_TYPE>& s_feature_PE32_3,
    hls::stream<W_TYPE>& s_feature_PE33_0, hls::stream<W_TYPE>& s_feature_PE33_1,
    hls::stream<W_TYPE>& s_feature_PE33_2, hls::stream<W_TYPE>& s_feature_PE33_3,
    hls::stream<W_TYPE>& s_feature_PE34_0, hls::stream<W_TYPE>& s_feature_PE34_1,
    hls::stream<W_TYPE>& s_feature_PE34_2, hls::stream<W_TYPE>& s_feature_PE34_3,
    hls::stream<W_TYPE>& s_feature_PE35_0, hls::stream<W_TYPE>& s_feature_PE35_1,
    hls::stream<W_TYPE>& s_feature_PE35_2, hls::stream<W_TYPE>& s_feature_PE35_3,
    hls::stream<W_TYPE>& s_feature_PE36_0, hls::stream<W_TYPE>& s_feature_PE36_1,
    hls::stream<W_TYPE>& s_feature_PE36_2, hls::stream<W_TYPE>& s_feature_PE36_3,
    hls::stream<W_TYPE>& s_feature_PE37_0, hls::stream<W_TYPE>& s_feature_PE37_1,
    hls::stream<W_TYPE>& s_feature_PE37_2, hls::stream<W_TYPE>& s_feature_PE37_3,
    hls::stream<W_TYPE>& s_feature_PE38_0, hls::stream<W_TYPE>& s_feature_PE38_1,
    hls::stream<W_TYPE>& s_feature_PE38_2, hls::stream<W_TYPE>& s_feature_PE38_3,
    hls::stream<W_TYPE>& s_feature_PE39_0, hls::stream<W_TYPE>& s_feature_PE39_1,
    hls::stream<W_TYPE>& s_feature_PE39_2, hls::stream<W_TYPE>& s_feature_PE39_3,
    hls::stream<W_TYPE>& s_feature_PE40_0, hls::stream<W_TYPE>& s_feature_PE40_1,
    hls::stream<W_TYPE>& s_feature_PE40_2, hls::stream<W_TYPE>& s_feature_PE40_3,
    hls::stream<W_TYPE>& s_feature_PE41_0, hls::stream<W_TYPE>& s_feature_PE41_1,
    hls::stream<W_TYPE>& s_feature_PE41_2, hls::stream<W_TYPE>& s_feature_PE41_3,
    hls::stream<W_TYPE>& s_feature_PE42_0, hls::stream<W_TYPE>& s_feature_PE42_1,
    hls::stream<W_TYPE>& s_feature_PE42_2, hls::stream<W_TYPE>& s_feature_PE42_3,
    hls::stream<W_TYPE>& s_feature_PE43_0, hls::stream<W_TYPE>& s_feature_PE43_1,
    hls::stream<W_TYPE>& s_feature_PE43_2, hls::stream<W_TYPE>& s_feature_PE43_3,
    hls::stream<W_TYPE>& s_feature_PE44_0, hls::stream<W_TYPE>& s_feature_PE44_1,
    hls::stream<W_TYPE>& s_feature_PE44_2, hls::stream<W_TYPE>& s_feature_PE44_3,
    hls::stream<W_TYPE>& s_feature_PE45_0, hls::stream<W_TYPE>& s_feature_PE45_1,
    hls::stream<W_TYPE>& s_feature_PE45_2, hls::stream<W_TYPE>& s_feature_PE45_3,
    hls::stream<W_TYPE>& s_feature_PE46_0, hls::stream<W_TYPE>& s_feature_PE46_1,
    hls::stream<W_TYPE>& s_feature_PE46_2, hls::stream<W_TYPE>& s_feature_PE46_3,
    hls::stream<W_TYPE>& s_feature_PE47_0, hls::stream<W_TYPE>& s_feature_PE47_1,
    hls::stream<W_TYPE>& s_feature_PE47_2, hls::stream<W_TYPE>& s_feature_PE47_3,
    hls::stream<W_TYPE>& s_feature_PE48_0, hls::stream<W_TYPE>& s_feature_PE48_1,
    hls::stream<W_TYPE>& s_feature_PE48_2, hls::stream<W_TYPE>& s_feature_PE48_3,
    hls::stream<W_TYPE>& s_feature_PE49_0, hls::stream<W_TYPE>& s_feature_PE49_1,
    hls::stream<W_TYPE>& s_feature_PE49_2, hls::stream<W_TYPE>& s_feature_PE49_3,
    hls::stream<W_TYPE>& s_feature_PE50_0, hls::stream<W_TYPE>& s_feature_PE50_1,
    hls::stream<W_TYPE>& s_feature_PE50_2, hls::stream<W_TYPE>& s_feature_PE50_3,
    hls::stream<W_TYPE>& s_feature_PE51_0, hls::stream<W_TYPE>& s_feature_PE51_1,
    hls::stream<W_TYPE>& s_feature_PE51_2, hls::stream<W_TYPE>& s_feature_PE51_3,
    hls::stream<W_TYPE>& s_feature_PE52_0, hls::stream<W_TYPE>& s_feature_PE52_1,
    hls::stream<W_TYPE>& s_feature_PE52_2, hls::stream<W_TYPE>& s_feature_PE52_3,
    hls::stream<W_TYPE>& s_feature_PE53_0, hls::stream<W_TYPE>& s_feature_PE53_1,
    hls::stream<W_TYPE>& s_feature_PE53_2, hls::stream<W_TYPE>& s_feature_PE53_3,
    hls::stream<W_TYPE>& s_feature_PE54_0, hls::stream<W_TYPE>& s_feature_PE54_1,
    hls::stream<W_TYPE>& s_feature_PE54_2, hls::stream<W_TYPE>& s_feature_PE54_3,
    hls::stream<W_TYPE>& s_feature_PE55_0, hls::stream<W_TYPE>& s_feature_PE55_1,
    hls::stream<W_TYPE>& s_feature_PE55_2, hls::stream<W_TYPE>& s_feature_PE55_3,
    hls::stream<W_TYPE>& s_feature_PE56_0, hls::stream<W_TYPE>& s_feature_PE56_1,
    hls::stream<W_TYPE>& s_feature_PE56_2, hls::stream<W_TYPE>& s_feature_PE56_3,
    hls::stream<W_TYPE>& s_feature_PE57_0, hls::stream<W_TYPE>& s_feature_PE57_1,
    hls::stream<W_TYPE>& s_feature_PE57_2, hls::stream<W_TYPE>& s_feature_PE57_3,
    hls::stream<W_TYPE>& s_feature_PE58_0, hls::stream<W_TYPE>& s_feature_PE58_1,
    hls::stream<W_TYPE>& s_feature_PE58_2, hls::stream<W_TYPE>& s_feature_PE58_3,
    hls::stream<W_TYPE>& s_feature_PE59_0, hls::stream<W_TYPE>& s_feature_PE59_1,
    hls::stream<W_TYPE>& s_feature_PE59_2, hls::stream<W_TYPE>& s_feature_PE59_3,
    hls::stream<W_TYPE>& s_feature_PE60_0, hls::stream<W_TYPE>& s_feature_PE60_1,
    hls::stream<W_TYPE>& s_feature_PE60_2, hls::stream<W_TYPE>& s_feature_PE60_3,
    hls::stream<W_TYPE>& s_feature_PE61_0, hls::stream<W_TYPE>& s_feature_PE61_1,
    hls::stream<W_TYPE>& s_feature_PE61_2, hls::stream<W_TYPE>& s_feature_PE61_3,
    hls::stream<W_TYPE>& s_feature_PE62_0, hls::stream<W_TYPE>& s_feature_PE62_1,
    hls::stream<W_TYPE>& s_feature_PE62_2, hls::stream<W_TYPE>& s_feature_PE62_3,
    hls::stream<W_TYPE>& s_feature_PE63_0, hls::stream<W_TYPE>& s_feature_PE63_1,
    hls::stream<W_TYPE>& s_feature_PE63_2, hls::stream<W_TYPE>& s_feature_PE63_3,
    hls::stream<W_TYPE>& s_feature_PE64_0, hls::stream<W_TYPE>& s_feature_PE64_1,
    hls::stream<W_TYPE>& s_feature_PE64_2, hls::stream<W_TYPE>& s_feature_PE64_3,
    hls::stream<W_TYPE>& s_feature_PE65_0, hls::stream<W_TYPE>& s_feature_PE65_1,
    hls::stream<W_TYPE>& s_feature_PE65_2, hls::stream<W_TYPE>& s_feature_PE65_3,
    hls::stream<W_TYPE>& s_feature_PE66_0, hls::stream<W_TYPE>& s_feature_PE66_1,
    hls::stream<W_TYPE>& s_feature_PE66_2, hls::stream<W_TYPE>& s_feature_PE66_3,
    hls::stream<W_TYPE>& s_feature_PE67_0, hls::stream<W_TYPE>& s_feature_PE67_1,
    hls::stream<W_TYPE>& s_feature_PE67_2, hls::stream<W_TYPE>& s_feature_PE67_3,
    hls::stream<W_TYPE>& s_feature_PE68_0, hls::stream<W_TYPE>& s_feature_PE68_1,
    hls::stream<W_TYPE>& s_feature_PE68_2, hls::stream<W_TYPE>& s_feature_PE68_3,
    hls::stream<W_TYPE>& s_feature_PE69_0, hls::stream<W_TYPE>& s_feature_PE69_1,
    hls::stream<W_TYPE>& s_feature_PE69_2, hls::stream<W_TYPE>& s_feature_PE69_3,
    hls::stream<W_TYPE>& s_feature_PE70_0, hls::stream<W_TYPE>& s_feature_PE70_1,
    hls::stream<W_TYPE>& s_feature_PE70_2, hls::stream<W_TYPE>& s_feature_PE70_3,
    hls::stream<W_TYPE>& s_feature_PE71_0, hls::stream<W_TYPE>& s_feature_PE71_1,
    hls::stream<W_TYPE>& s_feature_PE71_2, hls::stream<W_TYPE>& s_feature_PE71_3,
    hls::stream<W_TYPE>& s_feature_PE72_0, hls::stream<W_TYPE>& s_feature_PE72_1,
    hls::stream<W_TYPE>& s_feature_PE72_2, hls::stream<W_TYPE>& s_feature_PE72_3,
    hls::stream<W_TYPE>& s_feature_PE73_0, hls::stream<W_TYPE>& s_feature_PE73_1,
    hls::stream<W_TYPE>& s_feature_PE73_2, hls::stream<W_TYPE>& s_feature_PE73_3,
    hls::stream<W_TYPE>& s_feature_PE74_0, hls::stream<W_TYPE>& s_feature_PE74_1,
    hls::stream<W_TYPE>& s_feature_PE74_2, hls::stream<W_TYPE>& s_feature_PE74_3,
    hls::stream<W_TYPE>& s_feature_PE75_0, hls::stream<W_TYPE>& s_feature_PE75_1,
    hls::stream<W_TYPE>& s_feature_PE75_2, hls::stream<W_TYPE>& s_feature_PE75_3,
    hls::stream<W_TYPE>& s_feature_PE76_0, hls::stream<W_TYPE>& s_feature_PE76_1,
    hls::stream<W_TYPE>& s_feature_PE76_2, hls::stream<W_TYPE>& s_feature_PE76_3,
    hls::stream<W_TYPE>& s_feature_PE77_0, hls::stream<W_TYPE>& s_feature_PE77_1,
    hls::stream<W_TYPE>& s_feature_PE77_2, hls::stream<W_TYPE>& s_feature_PE77_3,
    hls::stream<W_TYPE>& s_feature_PE78_0, hls::stream<W_TYPE>& s_feature_PE78_1,
    hls::stream<W_TYPE>& s_feature_PE78_2, hls::stream<W_TYPE>& s_feature_PE78_3,
    hls::stream<W_TYPE>& s_feature_PE79_0, hls::stream<W_TYPE>& s_feature_PE79_1,
    hls::stream<W_TYPE>& s_feature_PE79_2, hls::stream<W_TYPE>& s_feature_PE79_3
);

template<const int FEATURE_SIZE>
void replicate_feature_512PEs_40PE(
    hls::stream<ap_uint<512> >& s_feature_in, 
    hls::stream<W_TYPE>& s_feature_PE0_0, hls::stream<W_TYPE>& s_feature_PE0_1,
    hls::stream<W_TYPE>& s_feature_PE0_2, hls::stream<W_TYPE>& s_feature_PE0_3,
    hls::stream<W_TYPE>& s_feature_PE1_0, hls::stream<W_TYPE>& s_feature_PE1_1,
    hls::stream<W_TYPE>& s_feature_PE1_2, hls::stream<W_TYPE>& s_feature_PE1_3,
    hls::stream<W_TYPE>& s_feature_PE2_0, hls::stream<W_TYPE>& s_feature_PE2_1,
    hls::stream<W_TYPE>& s_feature_PE2_2, hls::stream<W_TYPE>& s_feature_PE2_3,
    hls::stream<W_TYPE>& s_feature_PE3_0, hls::stream<W_TYPE>& s_feature_PE3_1,
    hls::stream<W_TYPE>& s_feature_PE3_2, hls::stream<W_TYPE>& s_feature_PE3_3,
    hls::stream<W_TYPE>& s_feature_PE4_0, hls::stream<W_TYPE>& s_feature_PE4_1,
    hls::stream<W_TYPE>& s_feature_PE4_2, hls::stream<W_TYPE>& s_feature_PE4_3,
    hls::stream<W_TYPE>& s_feature_PE5_0, hls::stream<W_TYPE>& s_feature_PE5_1,
    hls::stream<W_TYPE>& s_feature_PE5_2, hls::stream<W_TYPE>& s_feature_PE5_3,
    hls::stream<W_TYPE>& s_feature_PE6_0, hls::stream<W_TYPE>& s_feature_PE6_1,
    hls::stream<W_TYPE>& s_feature_PE6_2, hls::stream<W_TYPE>& s_feature_PE6_3,
    hls::stream<W_TYPE>& s_feature_PE7_0, hls::stream<W_TYPE>& s_feature_PE7_1,
    hls::stream<W_TYPE>& s_feature_PE7_2, hls::stream<W_TYPE>& s_feature_PE7_3,
    hls::stream<W_TYPE>& s_feature_PE8_0, hls::stream<W_TYPE>& s_feature_PE8_1,
    hls::stream<W_TYPE>& s_feature_PE8_2, hls::stream<W_TYPE>& s_feature_PE8_3,
    hls::stream<W_TYPE>& s_feature_PE9_0, hls::stream<W_TYPE>& s_feature_PE9_1,
    hls::stream<W_TYPE>& s_feature_PE9_2, hls::stream<W_TYPE>& s_feature_PE9_3,
    hls::stream<W_TYPE>& s_feature_PE10_0, hls::stream<W_TYPE>& s_feature_PE10_1,
    hls::stream<W_TYPE>& s_feature_PE10_2, hls::stream<W_TYPE>& s_feature_PE10_3,
    hls::stream<W_TYPE>& s_feature_PE11_0, hls::stream<W_TYPE>& s_feature_PE11_1,
    hls::stream<W_TYPE>& s_feature_PE11_2, hls::stream<W_TYPE>& s_feature_PE11_3,
    hls::stream<W_TYPE>& s_feature_PE12_0, hls::stream<W_TYPE>& s_feature_PE12_1,
    hls::stream<W_TYPE>& s_feature_PE12_2, hls::stream<W_TYPE>& s_feature_PE12_3,
    hls::stream<W_TYPE>& s_feature_PE13_0, hls::stream<W_TYPE>& s_feature_PE13_1,
    hls::stream<W_TYPE>& s_feature_PE13_2, hls::stream<W_TYPE>& s_feature_PE13_3,
    hls::stream<W_TYPE>& s_feature_PE14_0, hls::stream<W_TYPE>& s_feature_PE14_1,
    hls::stream<W_TYPE>& s_feature_PE14_2, hls::stream<W_TYPE>& s_feature_PE14_3,
    hls::stream<W_TYPE>& s_feature_PE15_0, hls::stream<W_TYPE>& s_feature_PE15_1,
    hls::stream<W_TYPE>& s_feature_PE15_2, hls::stream<W_TYPE>& s_feature_PE15_3,
    hls::stream<W_TYPE>& s_feature_PE16_0, hls::stream<W_TYPE>& s_feature_PE16_1,
    hls::stream<W_TYPE>& s_feature_PE16_2, hls::stream<W_TYPE>& s_feature_PE16_3,
    hls::stream<W_TYPE>& s_feature_PE17_0, hls::stream<W_TYPE>& s_feature_PE17_1,
    hls::stream<W_TYPE>& s_feature_PE17_2, hls::stream<W_TYPE>& s_feature_PE17_3,
    hls::stream<W_TYPE>& s_feature_PE18_0, hls::stream<W_TYPE>& s_feature_PE18_1,
    hls::stream<W_TYPE>& s_feature_PE18_2, hls::stream<W_TYPE>& s_feature_PE18_3,
    hls::stream<W_TYPE>& s_feature_PE19_0, hls::stream<W_TYPE>& s_feature_PE19_1,
    hls::stream<W_TYPE>& s_feature_PE19_2, hls::stream<W_TYPE>& s_feature_PE19_3,
    hls::stream<W_TYPE>& s_feature_PE20_0, hls::stream<W_TYPE>& s_feature_PE20_1,
    hls::stream<W_TYPE>& s_feature_PE20_2, hls::stream<W_TYPE>& s_feature_PE20_3,
    hls::stream<W_TYPE>& s_feature_PE21_0, hls::stream<W_TYPE>& s_feature_PE21_1,
    hls::stream<W_TYPE>& s_feature_PE21_2, hls::stream<W_TYPE>& s_feature_PE21_3,
    hls::stream<W_TYPE>& s_feature_PE22_0, hls::stream<W_TYPE>& s_feature_PE22_1,
    hls::stream<W_TYPE>& s_feature_PE22_2, hls::stream<W_TYPE>& s_feature_PE22_3,
    hls::stream<W_TYPE>& s_feature_PE23_0, hls::stream<W_TYPE>& s_feature_PE23_1,
    hls::stream<W_TYPE>& s_feature_PE23_2, hls::stream<W_TYPE>& s_feature_PE23_3,
    hls::stream<W_TYPE>& s_feature_PE24_0, hls::stream<W_TYPE>& s_feature_PE24_1,
    hls::stream<W_TYPE>& s_feature_PE24_2, hls::stream<W_TYPE>& s_feature_PE24_3,
    hls::stream<W_TYPE>& s_feature_PE25_0, hls::stream<W_TYPE>& s_feature_PE25_1,
    hls::stream<W_TYPE>& s_feature_PE25_2, hls::stream<W_TYPE>& s_feature_PE25_3,
    hls::stream<W_TYPE>& s_feature_PE26_0, hls::stream<W_TYPE>& s_feature_PE26_1,
    hls::stream<W_TYPE>& s_feature_PE26_2, hls::stream<W_TYPE>& s_feature_PE26_3,
    hls::stream<W_TYPE>& s_feature_PE27_0, hls::stream<W_TYPE>& s_feature_PE27_1,
    hls::stream<W_TYPE>& s_feature_PE27_2, hls::stream<W_TYPE>& s_feature_PE27_3,
    hls::stream<W_TYPE>& s_feature_PE28_0, hls::stream<W_TYPE>& s_feature_PE28_1,
    hls::stream<W_TYPE>& s_feature_PE28_2, hls::stream<W_TYPE>& s_feature_PE28_3,
    hls::stream<W_TYPE>& s_feature_PE29_0, hls::stream<W_TYPE>& s_feature_PE29_1,
    hls::stream<W_TYPE>& s_feature_PE29_2, hls::stream<W_TYPE>& s_feature_PE29_3,
    hls::stream<W_TYPE>& s_feature_PE30_0, hls::stream<W_TYPE>& s_feature_PE30_1,
    hls::stream<W_TYPE>& s_feature_PE30_2, hls::stream<W_TYPE>& s_feature_PE30_3,
    hls::stream<W_TYPE>& s_feature_PE31_0, hls::stream<W_TYPE>& s_feature_PE31_1,
    hls::stream<W_TYPE>& s_feature_PE31_2, hls::stream<W_TYPE>& s_feature_PE31_3,
    hls::stream<W_TYPE>& s_feature_PE32_0, hls::stream<W_TYPE>& s_feature_PE32_1,
    hls::stream<W_TYPE>& s_feature_PE32_2, hls::stream<W_TYPE>& s_feature_PE32_3,
    hls::stream<W_TYPE>& s_feature_PE33_0, hls::stream<W_TYPE>& s_feature_PE33_1,
    hls::stream<W_TYPE>& s_feature_PE33_2, hls::stream<W_TYPE>& s_feature_PE33_3,
    hls::stream<W_TYPE>& s_feature_PE34_0, hls::stream<W_TYPE>& s_feature_PE34_1,
    hls::stream<W_TYPE>& s_feature_PE34_2, hls::stream<W_TYPE>& s_feature_PE34_3,
    hls::stream<W_TYPE>& s_feature_PE35_0, hls::stream<W_TYPE>& s_feature_PE35_1,
    hls::stream<W_TYPE>& s_feature_PE35_2, hls::stream<W_TYPE>& s_feature_PE35_3,
    hls::stream<W_TYPE>& s_feature_PE36_0, hls::stream<W_TYPE>& s_feature_PE36_1,
    hls::stream<W_TYPE>& s_feature_PE36_2, hls::stream<W_TYPE>& s_feature_PE36_3,
    hls::stream<W_TYPE>& s_feature_PE37_0, hls::stream<W_TYPE>& s_feature_PE37_1,
    hls::stream<W_TYPE>& s_feature_PE37_2, hls::stream<W_TYPE>& s_feature_PE37_3,
    hls::stream<W_TYPE>& s_feature_PE38_0, hls::stream<W_TYPE>& s_feature_PE38_1,
    hls::stream<W_TYPE>& s_feature_PE38_2, hls::stream<W_TYPE>& s_feature_PE38_3,
    hls::stream<W_TYPE>& s_feature_PE39_0, hls::stream<W_TYPE>& s_feature_PE39_1,
    hls::stream<W_TYPE>& s_feature_PE39_2, hls::stream<W_TYPE>& s_feature_PE39_3
);

template<const int FEATURE_SIZE>
void replicate_feature_512PEs_32PE(
    hls::stream<ap_uint<512> >& s_feature_in, 
    hls::stream<W_TYPE>& s_feature_PE0_0, hls::stream<W_TYPE>& s_feature_PE0_1,
    hls::stream<W_TYPE>& s_feature_PE1_0, hls::stream<W_TYPE>& s_feature_PE1_1,
    hls::stream<W_TYPE>& s_feature_PE2_0, hls::stream<W_TYPE>& s_feature_PE2_1,
    hls::stream<W_TYPE>& s_feature_PE3_0, hls::stream<W_TYPE>& s_feature_PE3_1,
    hls::stream<W_TYPE>& s_feature_PE4_0, hls::stream<W_TYPE>& s_feature_PE4_1,
    hls::stream<W_TYPE>& s_feature_PE5_0, hls::stream<W_TYPE>& s_feature_PE5_1,
    hls::stream<W_TYPE>& s_feature_PE6_0, hls::stream<W_TYPE>& s_feature_PE6_1,
    hls::stream<W_TYPE>& s_feature_PE7_0, hls::stream<W_TYPE>& s_feature_PE7_1,
    hls::stream<W_TYPE>& s_feature_PE8_0, hls::stream<W_TYPE>& s_feature_PE8_1,
    hls::stream<W_TYPE>& s_feature_PE9_0, hls::stream<W_TYPE>& s_feature_PE9_1,
    hls::stream<W_TYPE>& s_feature_PE10_0, hls::stream<W_TYPE>& s_feature_PE10_1,
    hls::stream<W_TYPE>& s_feature_PE11_0, hls::stream<W_TYPE>& s_feature_PE11_1,
    hls::stream<W_TYPE>& s_feature_PE12_0, hls::stream<W_TYPE>& s_feature_PE12_1,
    hls::stream<W_TYPE>& s_feature_PE13_0, hls::stream<W_TYPE>& s_feature_PE13_1,
    hls::stream<W_TYPE>& s_feature_PE14_0, hls::stream<W_TYPE>& s_feature_PE14_1,
    hls::stream<W_TYPE>& s_feature_PE15_0, hls::stream<W_TYPE>& s_feature_PE15_1,
    hls::stream<W_TYPE>& s_feature_PE16_0, hls::stream<W_TYPE>& s_feature_PE16_1,
    hls::stream<W_TYPE>& s_feature_PE17_0, hls::stream<W_TYPE>& s_feature_PE17_1,
    hls::stream<W_TYPE>& s_feature_PE18_0, hls::stream<W_TYPE>& s_feature_PE18_1,
    hls::stream<W_TYPE>& s_feature_PE19_0, hls::stream<W_TYPE>& s_feature_PE19_1,
    hls::stream<W_TYPE>& s_feature_PE20_0, hls::stream<W_TYPE>& s_feature_PE20_1,
    hls::stream<W_TYPE>& s_feature_PE21_0, hls::stream<W_TYPE>& s_feature_PE21_1,
    hls::stream<W_TYPE>& s_feature_PE22_0, hls::stream<W_TYPE>& s_feature_PE22_1,
    hls::stream<W_TYPE>& s_feature_PE23_0, hls::stream<W_TYPE>& s_feature_PE23_1,
    hls::stream<W_TYPE>& s_feature_PE24_0, hls::stream<W_TYPE>& s_feature_PE24_1,
    hls::stream<W_TYPE>& s_feature_PE25_0, hls::stream<W_TYPE>& s_feature_PE25_1,
    hls::stream<W_TYPE>& s_feature_PE26_0, hls::stream<W_TYPE>& s_feature_PE26_1,
    hls::stream<W_TYPE>& s_feature_PE27_0, hls::stream<W_TYPE>& s_feature_PE27_1,
    hls::stream<W_TYPE>& s_feature_PE28_0, hls::stream<W_TYPE>& s_feature_PE28_1,
    hls::stream<W_TYPE>& s_feature_PE29_0, hls::stream<W_TYPE>& s_feature_PE29_1,
    hls::stream<W_TYPE>& s_feature_PE30_0, hls::stream<W_TYPE>& s_feature_PE30_1,
    hls::stream<W_TYPE>& s_feature_PE31_0, hls::stream<W_TYPE>& s_feature_PE31_1
);

template<const int ROW_PER_PE>
void gather_results_512PEs_320PE(
    hls::stream<D_TYPE>& s_result_PE0, hls::stream<D_TYPE>& s_result_PE1, 
    hls::stream<D_TYPE>& s_result_PE2, hls::stream<D_TYPE>& s_result_PE3, 
    hls::stream<D_TYPE>& s_result_PE4, hls::stream<D_TYPE>& s_result_PE5, 
    hls::stream<D_TYPE>& s_result_PE6, hls::stream<D_TYPE>& s_result_PE7, 
    hls::stream<D_TYPE>& s_result_PE8, hls::stream<D_TYPE>& s_result_PE9, 
    hls::stream<D_TYPE>& s_result_PE10, hls::stream<D_TYPE>& s_result_PE11, 
    hls::stream<D_TYPE>& s_result_PE12, hls::stream<D_TYPE>& s_result_PE13, 
    hls::stream<D_TYPE>& s_result_PE14, hls::stream<D_TYPE>& s_result_PE15, 
    hls::stream<D_TYPE>& s_result_PE16, hls::stream<D_TYPE>& s_result_PE17, 
    hls::stream<D_TYPE>& s_result_PE18, hls::stream<D_TYPE>& s_result_PE19, 
    hls::stream<D_TYPE>& s_result_PE20, hls::stream<D_TYPE>& s_result_PE21, 
    hls::stream<D_TYPE>& s_result_PE22, hls::stream<D_TYPE>& s_result_PE23, 
    hls::stream<D_TYPE>& s_result_PE24, hls::stream<D_TYPE>& s_result_PE25, 
    hls::stream<D_TYPE>& s_result_PE26, hls::stream<D_TYPE>& s_result_PE27, 
    hls::stream<D_TYPE>& s_result_PE28, hls::stream<D_TYPE>& s_result_PE29, 
    hls::stream<D_TYPE>& s_result_PE30, hls::stream<D_TYPE>& s_result_PE31, 
    hls::stream<D_TYPE>& s_result_PE32, hls::stream<D_TYPE>& s_result_PE33, 
    hls::stream<D_TYPE>& s_result_PE34, hls::stream<D_TYPE>& s_result_PE35, 
    hls::stream<D_TYPE>& s_result_PE36, hls::stream<D_TYPE>& s_result_PE37, 
    hls::stream<D_TYPE>& s_result_PE38, hls::stream<D_TYPE>& s_result_PE39, 
    hls::stream<D_TYPE>& s_result_PE40, hls::stream<D_TYPE>& s_result_PE41, 
    hls::stream<D_TYPE>& s_result_PE42, hls::stream<D_TYPE>& s_result_PE43, 
    hls::stream<D_TYPE>& s_result_PE44, hls::stream<D_TYPE>& s_result_PE45, 
    hls::stream<D_TYPE>& s_result_PE46, hls::stream<D_TYPE>& s_result_PE47, 
    hls::stream<D_TYPE>& s_result_PE48, hls::stream<D_TYPE>& s_result_PE49, 
    hls::stream<D_TYPE>& s_result_PE50, hls::stream<D_TYPE>& s_result_PE51, 
    hls::stream<D_TYPE>& s_result_PE52, hls::stream<D_TYPE>& s_result_PE53, 
    hls::stream<D_TYPE>& s_result_PE54, hls::stream<D_TYPE>& s_result_PE55, 
    hls::stream<D_TYPE>& s_result_PE56, hls::stream<D_TYPE>& s_result_PE57, 
    hls::stream<D_TYPE>& s_result_PE58, hls::stream<D_TYPE>& s_result_PE59, 
    hls::stream<D_TYPE>& s_result_PE60, hls::stream<D_TYPE>& s_result_PE61, 
    hls::stream<D_TYPE>& s_result_PE62, hls::stream<D_TYPE>& s_result_PE63, 
    hls::stream<D_TYPE>& s_result_PE64, hls::stream<D_TYPE>& s_result_PE65, 
    hls::stream<D_TYPE>& s_result_PE66, hls::stream<D_TYPE>& s_result_PE67, 
    hls::stream<D_TYPE>& s_result_PE68, hls::stream<D_TYPE>& s_result_PE69, 
    hls::stream<D_TYPE>& s_result_PE70, hls::stream<D_TYPE>& s_result_PE71, 
    hls::stream<D_TYPE>& s_result_PE72, hls::stream<D_TYPE>& s_result_PE73, 
    hls::stream<D_TYPE>& s_result_PE74, hls::stream<D_TYPE>& s_result_PE75, 
    hls::stream<D_TYPE>& s_result_PE76, hls::stream<D_TYPE>& s_result_PE77, 
    hls::stream<D_TYPE>& s_result_PE78, hls::stream<D_TYPE>& s_result_PE79, 
    hls::stream<D_TYPE>& s_result_PE80, hls::stream<D_TYPE>& s_result_PE81, 
    hls::stream<D_TYPE>& s_result_PE82, hls::stream<D_TYPE>& s_result_PE83, 
    hls::stream<D_TYPE>& s_result_PE84, hls::stream<D_TYPE>& s_result_PE85, 
    hls::stream<D_TYPE>& s_result_PE86, hls::stream<D_TYPE>& s_result_PE87, 
    hls::stream<D_TYPE>& s_result_PE88, hls::stream<D_TYPE>& s_result_PE89, 
    hls::stream<D_TYPE>& s_result_PE90, hls::stream<D_TYPE>& s_result_PE91, 
    hls::stream<D_TYPE>& s_result_PE92, hls::stream<D_TYPE>& s_result_PE93, 
    hls::stream<D_TYPE>& s_result_PE94, hls::stream<D_TYPE>& s_result_PE95, 
    hls::stream<D_TYPE>& s_result_PE96, hls::stream<D_TYPE>& s_result_PE97, 
    hls::stream<D_TYPE>& s_result_PE98, hls::stream<D_TYPE>& s_result_PE99, 
    hls::stream<D_TYPE>& s_result_PE100, hls::stream<D_TYPE>& s_result_PE101, 
    hls::stream<D_TYPE>& s_result_PE102, hls::stream<D_TYPE>& s_result_PE103, 
    hls::stream<D_TYPE>& s_result_PE104, hls::stream<D_TYPE>& s_result_PE105, 
    hls::stream<D_TYPE>& s_result_PE106, hls::stream<D_TYPE>& s_result_PE107, 
    hls::stream<D_TYPE>& s_result_PE108, hls::stream<D_TYPE>& s_result_PE109, 
    hls::stream<D_TYPE>& s_result_PE110, hls::stream<D_TYPE>& s_result_PE111, 
    hls::stream<D_TYPE>& s_result_PE112, hls::stream<D_TYPE>& s_result_PE113, 
    hls::stream<D_TYPE>& s_result_PE114, hls::stream<D_TYPE>& s_result_PE115, 
    hls::stream<D_TYPE>& s_result_PE116, hls::stream<D_TYPE>& s_result_PE117, 
    hls::stream<D_TYPE>& s_result_PE118, hls::stream<D_TYPE>& s_result_PE119, 
    hls::stream<D_TYPE>& s_result_PE120, hls::stream<D_TYPE>& s_result_PE121, 
    hls::stream<D_TYPE>& s_result_PE122, hls::stream<D_TYPE>& s_result_PE123, 
    hls::stream<D_TYPE>& s_result_PE124, hls::stream<D_TYPE>& s_result_PE125, 
    hls::stream<D_TYPE>& s_result_PE126, hls::stream<D_TYPE>& s_result_PE127, 
    hls::stream<D_TYPE>& s_result_PE128, hls::stream<D_TYPE>& s_result_PE129,
    hls::stream<D_TYPE>& s_result_PE130, hls::stream<D_TYPE>& s_result_PE131,
    hls::stream<D_TYPE>& s_result_PE132, hls::stream<D_TYPE>& s_result_PE133,
    hls::stream<D_TYPE>& s_result_PE134, hls::stream<D_TYPE>& s_result_PE135,
    hls::stream<D_TYPE>& s_result_PE136, hls::stream<D_TYPE>& s_result_PE137,
    hls::stream<D_TYPE>& s_result_PE138, hls::stream<D_TYPE>& s_result_PE139,
    hls::stream<D_TYPE>& s_result_PE140, hls::stream<D_TYPE>& s_result_PE141,
    hls::stream<D_TYPE>& s_result_PE142, hls::stream<D_TYPE>& s_result_PE143,
    hls::stream<D_TYPE>& s_result_PE144, hls::stream<D_TYPE>& s_result_PE145,
    hls::stream<D_TYPE>& s_result_PE146, hls::stream<D_TYPE>& s_result_PE147,
    hls::stream<D_TYPE>& s_result_PE148, hls::stream<D_TYPE>& s_result_PE149,
    hls::stream<D_TYPE>& s_result_PE150, hls::stream<D_TYPE>& s_result_PE151,
    hls::stream<D_TYPE>& s_result_PE152, hls::stream<D_TYPE>& s_result_PE153,
    hls::stream<D_TYPE>& s_result_PE154, hls::stream<D_TYPE>& s_result_PE155,
    hls::stream<D_TYPE>& s_result_PE156, hls::stream<D_TYPE>& s_result_PE157,
    hls::stream<D_TYPE>& s_result_PE158, hls::stream<D_TYPE>& s_result_PE159,
    hls::stream<D_TYPE>& s_result_PE160, hls::stream<D_TYPE>& s_result_PE161,
    hls::stream<D_TYPE>& s_result_PE162, hls::stream<D_TYPE>& s_result_PE163,
    hls::stream<D_TYPE>& s_result_PE164, hls::stream<D_TYPE>& s_result_PE165,
    hls::stream<D_TYPE>& s_result_PE166, hls::stream<D_TYPE>& s_result_PE167,
    hls::stream<D_TYPE>& s_result_PE168, hls::stream<D_TYPE>& s_result_PE169,
    hls::stream<D_TYPE>& s_result_PE170, hls::stream<D_TYPE>& s_result_PE171,
    hls::stream<D_TYPE>& s_result_PE172, hls::stream<D_TYPE>& s_result_PE173,
    hls::stream<D_TYPE>& s_result_PE174, hls::stream<D_TYPE>& s_result_PE175,
    hls::stream<D_TYPE>& s_result_PE176, hls::stream<D_TYPE>& s_result_PE177,
    hls::stream<D_TYPE>& s_result_PE178, hls::stream<D_TYPE>& s_result_PE179,
    hls::stream<D_TYPE>& s_result_PE180, hls::stream<D_TYPE>& s_result_PE181,
    hls::stream<D_TYPE>& s_result_PE182, hls::stream<D_TYPE>& s_result_PE183,
    hls::stream<D_TYPE>& s_result_PE184, hls::stream<D_TYPE>& s_result_PE185,
    hls::stream<D_TYPE>& s_result_PE186, hls::stream<D_TYPE>& s_result_PE187,
    hls::stream<D_TYPE>& s_result_PE188, hls::stream<D_TYPE>& s_result_PE189,
    hls::stream<D_TYPE>& s_result_PE190, hls::stream<D_TYPE>& s_result_PE191,
    hls::stream<D_TYPE>& s_result_PE192, hls::stream<D_TYPE>& s_result_PE193, 
    hls::stream<D_TYPE>& s_result_PE194, hls::stream<D_TYPE>& s_result_PE195, 
    hls::stream<D_TYPE>& s_result_PE196, hls::stream<D_TYPE>& s_result_PE197, 
    hls::stream<D_TYPE>& s_result_PE198, hls::stream<D_TYPE>& s_result_PE199,
    hls::stream<D_TYPE>& s_result_PE200, hls::stream<D_TYPE>& s_result_PE201, 
    hls::stream<D_TYPE>& s_result_PE202, hls::stream<D_TYPE>& s_result_PE203, 
    hls::stream<D_TYPE>& s_result_PE204, hls::stream<D_TYPE>& s_result_PE205, 
    hls::stream<D_TYPE>& s_result_PE206, hls::stream<D_TYPE>& s_result_PE207, 
    hls::stream<D_TYPE>& s_result_PE208, hls::stream<D_TYPE>& s_result_PE209, 
    hls::stream<D_TYPE>& s_result_PE210, hls::stream<D_TYPE>& s_result_PE211, 
    hls::stream<D_TYPE>& s_result_PE212, hls::stream<D_TYPE>& s_result_PE213, 
    hls::stream<D_TYPE>& s_result_PE214, hls::stream<D_TYPE>& s_result_PE215, 
    hls::stream<D_TYPE>& s_result_PE216, hls::stream<D_TYPE>& s_result_PE217, 
    hls::stream<D_TYPE>& s_result_PE218, hls::stream<D_TYPE>& s_result_PE219, 
    hls::stream<D_TYPE>& s_result_PE220, hls::stream<D_TYPE>& s_result_PE221, 
    hls::stream<D_TYPE>& s_result_PE222, hls::stream<D_TYPE>& s_result_PE223, 
    hls::stream<D_TYPE>& s_result_PE224, hls::stream<D_TYPE>& s_result_PE225, 
    hls::stream<D_TYPE>& s_result_PE226, hls::stream<D_TYPE>& s_result_PE227, 
    hls::stream<D_TYPE>& s_result_PE228, hls::stream<D_TYPE>& s_result_PE229,
    hls::stream<D_TYPE>& s_result_PE230, hls::stream<D_TYPE>& s_result_PE231,
    hls::stream<D_TYPE>& s_result_PE232, hls::stream<D_TYPE>& s_result_PE233,
    hls::stream<D_TYPE>& s_result_PE234, hls::stream<D_TYPE>& s_result_PE235,
    hls::stream<D_TYPE>& s_result_PE236, hls::stream<D_TYPE>& s_result_PE237,
    hls::stream<D_TYPE>& s_result_PE238, hls::stream<D_TYPE>& s_result_PE239,
    hls::stream<D_TYPE>& s_result_PE240, hls::stream<D_TYPE>& s_result_PE241,
    hls::stream<D_TYPE>& s_result_PE242, hls::stream<D_TYPE>& s_result_PE243,
    hls::stream<D_TYPE>& s_result_PE244, hls::stream<D_TYPE>& s_result_PE245,
    hls::stream<D_TYPE>& s_result_PE246, hls::stream<D_TYPE>& s_result_PE247,
    hls::stream<D_TYPE>& s_result_PE248, hls::stream<D_TYPE>& s_result_PE249,
    hls::stream<D_TYPE>& s_result_PE250, hls::stream<D_TYPE>& s_result_PE251,
    hls::stream<D_TYPE>& s_result_PE252, hls::stream<D_TYPE>& s_result_PE253,
    hls::stream<D_TYPE>& s_result_PE254, hls::stream<D_TYPE>& s_result_PE255,
    hls::stream<D_TYPE>& s_result_PE256, hls::stream<D_TYPE>& s_result_PE257,
    hls::stream<D_TYPE>& s_result_PE258, hls::stream<D_TYPE>& s_result_PE259,
    hls::stream<D_TYPE>& s_result_PE260, hls::stream<D_TYPE>& s_result_PE261,
    hls::stream<D_TYPE>& s_result_PE262, hls::stream<D_TYPE>& s_result_PE263,
    hls::stream<D_TYPE>& s_result_PE264, hls::stream<D_TYPE>& s_result_PE265,
    hls::stream<D_TYPE>& s_result_PE266, hls::stream<D_TYPE>& s_result_PE267,
    hls::stream<D_TYPE>& s_result_PE268, hls::stream<D_TYPE>& s_result_PE269,
    hls::stream<D_TYPE>& s_result_PE270, hls::stream<D_TYPE>& s_result_PE271,
    hls::stream<D_TYPE>& s_result_PE272, hls::stream<D_TYPE>& s_result_PE273,
    hls::stream<D_TYPE>& s_result_PE274, hls::stream<D_TYPE>& s_result_PE275,
    hls::stream<D_TYPE>& s_result_PE276, hls::stream<D_TYPE>& s_result_PE277,
    hls::stream<D_TYPE>& s_result_PE278, hls::stream<D_TYPE>& s_result_PE279,
    hls::stream<D_TYPE>& s_result_PE280, hls::stream<D_TYPE>& s_result_PE281,
    hls::stream<D_TYPE>& s_result_PE282, hls::stream<D_TYPE>& s_result_PE283,
    hls::stream<D_TYPE>& s_result_PE284, hls::stream<D_TYPE>& s_result_PE285,
    hls::stream<D_TYPE>& s_result_PE286, hls::stream<D_TYPE>& s_result_PE287,
    hls::stream<D_TYPE>& s_result_PE288, hls::stream<D_TYPE>& s_result_PE289,
    hls::stream<D_TYPE>& s_result_PE290, hls::stream<D_TYPE>& s_result_PE291,
    hls::stream<D_TYPE>& s_result_PE292, hls::stream<D_TYPE>& s_result_PE293, 
    hls::stream<D_TYPE>& s_result_PE294, hls::stream<D_TYPE>& s_result_PE295, 
    hls::stream<D_TYPE>& s_result_PE296, hls::stream<D_TYPE>& s_result_PE297, 
    hls::stream<D_TYPE>& s_result_PE298, hls::stream<D_TYPE>& s_result_PE299,
    hls::stream<D_TYPE>& s_result_PE300, hls::stream<D_TYPE>& s_result_PE301, 
    hls::stream<D_TYPE>& s_result_PE302, hls::stream<D_TYPE>& s_result_PE303, 
    hls::stream<D_TYPE>& s_result_PE304, hls::stream<D_TYPE>& s_result_PE305, 
    hls::stream<D_TYPE>& s_result_PE306, hls::stream<D_TYPE>& s_result_PE307, 
    hls::stream<D_TYPE>& s_result_PE308, hls::stream<D_TYPE>& s_result_PE309, 
    hls::stream<D_TYPE>& s_result_PE310, hls::stream<D_TYPE>& s_result_PE311, 
    hls::stream<D_TYPE>& s_result_PE312, hls::stream<D_TYPE>& s_result_PE313, 
    hls::stream<D_TYPE>& s_result_PE314, hls::stream<D_TYPE>& s_result_PE315, 
    hls::stream<D_TYPE>& s_result_PE316, hls::stream<D_TYPE>& s_result_PE317, 
    hls::stream<D_TYPE>& s_result_PE318, hls::stream<D_TYPE>& s_result_PE319,
    hls::stream<ap_uint<512> >& s_result_all);

template<const int ROW_PER_PE>
void gather_results_192PEs(
    hls::stream<D_TYPE>& s_result_PE0, hls::stream<D_TYPE>& s_result_PE1, 
    hls::stream<D_TYPE>& s_result_PE2, hls::stream<D_TYPE>& s_result_PE3, 
    hls::stream<D_TYPE>& s_result_PE4, hls::stream<D_TYPE>& s_result_PE5, 
    hls::stream<D_TYPE>& s_result_PE6, hls::stream<D_TYPE>& s_result_PE7, 
    hls::stream<D_TYPE>& s_result_PE8, hls::stream<D_TYPE>& s_result_PE9, 
    hls::stream<D_TYPE>& s_result_PE10, hls::stream<D_TYPE>& s_result_PE11, 
    hls::stream<D_TYPE>& s_result_PE12, hls::stream<D_TYPE>& s_result_PE13, 
    hls::stream<D_TYPE>& s_result_PE14, hls::stream<D_TYPE>& s_result_PE15, 
    hls::stream<D_TYPE>& s_result_PE16, hls::stream<D_TYPE>& s_result_PE17, 
    hls::stream<D_TYPE>& s_result_PE18, hls::stream<D_TYPE>& s_result_PE19, 
    hls::stream<D_TYPE>& s_result_PE20, hls::stream<D_TYPE>& s_result_PE21, 
    hls::stream<D_TYPE>& s_result_PE22, hls::stream<D_TYPE>& s_result_PE23, 
    hls::stream<D_TYPE>& s_result_PE24, hls::stream<D_TYPE>& s_result_PE25, 
    hls::stream<D_TYPE>& s_result_PE26, hls::stream<D_TYPE>& s_result_PE27, 
    hls::stream<D_TYPE>& s_result_PE28, hls::stream<D_TYPE>& s_result_PE29, 
    hls::stream<D_TYPE>& s_result_PE30, hls::stream<D_TYPE>& s_result_PE31, 
    hls::stream<D_TYPE>& s_result_PE32, hls::stream<D_TYPE>& s_result_PE33, 
    hls::stream<D_TYPE>& s_result_PE34, hls::stream<D_TYPE>& s_result_PE35, 
    hls::stream<D_TYPE>& s_result_PE36, hls::stream<D_TYPE>& s_result_PE37, 
    hls::stream<D_TYPE>& s_result_PE38, hls::stream<D_TYPE>& s_result_PE39, 
    hls::stream<D_TYPE>& s_result_PE40, hls::stream<D_TYPE>& s_result_PE41, 
    hls::stream<D_TYPE>& s_result_PE42, hls::stream<D_TYPE>& s_result_PE43, 
    hls::stream<D_TYPE>& s_result_PE44, hls::stream<D_TYPE>& s_result_PE45, 
    hls::stream<D_TYPE>& s_result_PE46, hls::stream<D_TYPE>& s_result_PE47, 
    hls::stream<D_TYPE>& s_result_PE48, hls::stream<D_TYPE>& s_result_PE49, 
    hls::stream<D_TYPE>& s_result_PE50, hls::stream<D_TYPE>& s_result_PE51, 
    hls::stream<D_TYPE>& s_result_PE52, hls::stream<D_TYPE>& s_result_PE53, 
    hls::stream<D_TYPE>& s_result_PE54, hls::stream<D_TYPE>& s_result_PE55, 
    hls::stream<D_TYPE>& s_result_PE56, hls::stream<D_TYPE>& s_result_PE57, 
    hls::stream<D_TYPE>& s_result_PE58, hls::stream<D_TYPE>& s_result_PE59, 
    hls::stream<D_TYPE>& s_result_PE60, hls::stream<D_TYPE>& s_result_PE61, 
    hls::stream<D_TYPE>& s_result_PE62, hls::stream<D_TYPE>& s_result_PE63, 
    hls::stream<D_TYPE>& s_result_PE64, hls::stream<D_TYPE>& s_result_PE65, 
    hls::stream<D_TYPE>& s_result_PE66, hls::stream<D_TYPE>& s_result_PE67, 
    hls::stream<D_TYPE>& s_result_PE68, hls::stream<D_TYPE>& s_result_PE69, 
    hls::stream<D_TYPE>& s_result_PE70, hls::stream<D_TYPE>& s_result_PE71, 
    hls::stream<D_TYPE>& s_result_PE72, hls::stream<D_TYPE>& s_result_PE73, 
    hls::stream<D_TYPE>& s_result_PE74, hls::stream<D_TYPE>& s_result_PE75, 
    hls::stream<D_TYPE>& s_result_PE76, hls::stream<D_TYPE>& s_result_PE77, 
    hls::stream<D_TYPE>& s_result_PE78, hls::stream<D_TYPE>& s_result_PE79, 
    hls::stream<D_TYPE>& s_result_PE80, hls::stream<D_TYPE>& s_result_PE81, 
    hls::stream<D_TYPE>& s_result_PE82, hls::stream<D_TYPE>& s_result_PE83, 
    hls::stream<D_TYPE>& s_result_PE84, hls::stream<D_TYPE>& s_result_PE85, 
    hls::stream<D_TYPE>& s_result_PE86, hls::stream<D_TYPE>& s_result_PE87, 
    hls::stream<D_TYPE>& s_result_PE88, hls::stream<D_TYPE>& s_result_PE89, 
    hls::stream<D_TYPE>& s_result_PE90, hls::stream<D_TYPE>& s_result_PE91, 
    hls::stream<D_TYPE>& s_result_PE92, hls::stream<D_TYPE>& s_result_PE93, 
    hls::stream<D_TYPE>& s_result_PE94, hls::stream<D_TYPE>& s_result_PE95, 
    hls::stream<D_TYPE>& s_result_PE96, hls::stream<D_TYPE>& s_result_PE97, 
    hls::stream<D_TYPE>& s_result_PE98, hls::stream<D_TYPE>& s_result_PE99, 
    hls::stream<D_TYPE>& s_result_PE100, hls::stream<D_TYPE>& s_result_PE101, 
    hls::stream<D_TYPE>& s_result_PE102, hls::stream<D_TYPE>& s_result_PE103, 
    hls::stream<D_TYPE>& s_result_PE104, hls::stream<D_TYPE>& s_result_PE105, 
    hls::stream<D_TYPE>& s_result_PE106, hls::stream<D_TYPE>& s_result_PE107, 
    hls::stream<D_TYPE>& s_result_PE108, hls::stream<D_TYPE>& s_result_PE109, 
    hls::stream<D_TYPE>& s_result_PE110, hls::stream<D_TYPE>& s_result_PE111, 
    hls::stream<D_TYPE>& s_result_PE112, hls::stream<D_TYPE>& s_result_PE113, 
    hls::stream<D_TYPE>& s_result_PE114, hls::stream<D_TYPE>& s_result_PE115, 
    hls::stream<D_TYPE>& s_result_PE116, hls::stream<D_TYPE>& s_result_PE117, 
    hls::stream<D_TYPE>& s_result_PE118, hls::stream<D_TYPE>& s_result_PE119, 
    hls::stream<D_TYPE>& s_result_PE120, hls::stream<D_TYPE>& s_result_PE121, 
    hls::stream<D_TYPE>& s_result_PE122, hls::stream<D_TYPE>& s_result_PE123, 
    hls::stream<D_TYPE>& s_result_PE124, hls::stream<D_TYPE>& s_result_PE125, 
    hls::stream<D_TYPE>& s_result_PE126, hls::stream<D_TYPE>& s_result_PE127, 
    hls::stream<D_TYPE>& s_result_PE128, hls::stream<D_TYPE>& s_result_PE129,
    hls::stream<D_TYPE>& s_result_PE130, hls::stream<D_TYPE>& s_result_PE131,
    hls::stream<D_TYPE>& s_result_PE132, hls::stream<D_TYPE>& s_result_PE133,
    hls::stream<D_TYPE>& s_result_PE134, hls::stream<D_TYPE>& s_result_PE135,
    hls::stream<D_TYPE>& s_result_PE136, hls::stream<D_TYPE>& s_result_PE137,
    hls::stream<D_TYPE>& s_result_PE138, hls::stream<D_TYPE>& s_result_PE139,
    hls::stream<D_TYPE>& s_result_PE140, hls::stream<D_TYPE>& s_result_PE141,
    hls::stream<D_TYPE>& s_result_PE142, hls::stream<D_TYPE>& s_result_PE143,
    hls::stream<D_TYPE>& s_result_PE144, hls::stream<D_TYPE>& s_result_PE145,
    hls::stream<D_TYPE>& s_result_PE146, hls::stream<D_TYPE>& s_result_PE147,
    hls::stream<D_TYPE>& s_result_PE148, hls::stream<D_TYPE>& s_result_PE149,
    hls::stream<D_TYPE>& s_result_PE150, hls::stream<D_TYPE>& s_result_PE151,
    hls::stream<D_TYPE>& s_result_PE152, hls::stream<D_TYPE>& s_result_PE153,
    hls::stream<D_TYPE>& s_result_PE154, hls::stream<D_TYPE>& s_result_PE155,
    hls::stream<D_TYPE>& s_result_PE156, hls::stream<D_TYPE>& s_result_PE157,
    hls::stream<D_TYPE>& s_result_PE158, hls::stream<D_TYPE>& s_result_PE159,
    hls::stream<D_TYPE>& s_result_PE160, hls::stream<D_TYPE>& s_result_PE161,
    hls::stream<D_TYPE>& s_result_PE162, hls::stream<D_TYPE>& s_result_PE163,
    hls::stream<D_TYPE>& s_result_PE164, hls::stream<D_TYPE>& s_result_PE165,
    hls::stream<D_TYPE>& s_result_PE166, hls::stream<D_TYPE>& s_result_PE167,
    hls::stream<D_TYPE>& s_result_PE168, hls::stream<D_TYPE>& s_result_PE169,
    hls::stream<D_TYPE>& s_result_PE170, hls::stream<D_TYPE>& s_result_PE171,
    hls::stream<D_TYPE>& s_result_PE172, hls::stream<D_TYPE>& s_result_PE173,
    hls::stream<D_TYPE>& s_result_PE174, hls::stream<D_TYPE>& s_result_PE175,
    hls::stream<D_TYPE>& s_result_PE176, hls::stream<D_TYPE>& s_result_PE177,
    hls::stream<D_TYPE>& s_result_PE178, hls::stream<D_TYPE>& s_result_PE179,
    hls::stream<D_TYPE>& s_result_PE180, hls::stream<D_TYPE>& s_result_PE181,
    hls::stream<D_TYPE>& s_result_PE182, hls::stream<D_TYPE>& s_result_PE183,
    hls::stream<D_TYPE>& s_result_PE184, hls::stream<D_TYPE>& s_result_PE185,
    hls::stream<D_TYPE>& s_result_PE186, hls::stream<D_TYPE>& s_result_PE187,
    hls::stream<D_TYPE>& s_result_PE188, hls::stream<D_TYPE>& s_result_PE189,
    hls::stream<D_TYPE>& s_result_PE190, hls::stream<D_TYPE>& s_result_PE191,
    hls::stream<ap_uint<512> >& s_result_all);

template<const int ROW_PER_PE>
void gather_results_512PEs_160PE(
    hls::stream<D_TYPE>& s_result_PE0, hls::stream<D_TYPE>& s_result_PE1, 
    hls::stream<D_TYPE>& s_result_PE2, hls::stream<D_TYPE>& s_result_PE3, 
    hls::stream<D_TYPE>& s_result_PE4, hls::stream<D_TYPE>& s_result_PE5, 
    hls::stream<D_TYPE>& s_result_PE6, hls::stream<D_TYPE>& s_result_PE7, 
    hls::stream<D_TYPE>& s_result_PE8, hls::stream<D_TYPE>& s_result_PE9, 
    hls::stream<D_TYPE>& s_result_PE10, hls::stream<D_TYPE>& s_result_PE11, 
    hls::stream<D_TYPE>& s_result_PE12, hls::stream<D_TYPE>& s_result_PE13, 
    hls::stream<D_TYPE>& s_result_PE14, hls::stream<D_TYPE>& s_result_PE15, 
    hls::stream<D_TYPE>& s_result_PE16, hls::stream<D_TYPE>& s_result_PE17, 
    hls::stream<D_TYPE>& s_result_PE18, hls::stream<D_TYPE>& s_result_PE19, 
    hls::stream<D_TYPE>& s_result_PE20, hls::stream<D_TYPE>& s_result_PE21, 
    hls::stream<D_TYPE>& s_result_PE22, hls::stream<D_TYPE>& s_result_PE23, 
    hls::stream<D_TYPE>& s_result_PE24, hls::stream<D_TYPE>& s_result_PE25, 
    hls::stream<D_TYPE>& s_result_PE26, hls::stream<D_TYPE>& s_result_PE27, 
    hls::stream<D_TYPE>& s_result_PE28, hls::stream<D_TYPE>& s_result_PE29, 
    hls::stream<D_TYPE>& s_result_PE30, hls::stream<D_TYPE>& s_result_PE31, 
    hls::stream<D_TYPE>& s_result_PE32, hls::stream<D_TYPE>& s_result_PE33, 
    hls::stream<D_TYPE>& s_result_PE34, hls::stream<D_TYPE>& s_result_PE35, 
    hls::stream<D_TYPE>& s_result_PE36, hls::stream<D_TYPE>& s_result_PE37, 
    hls::stream<D_TYPE>& s_result_PE38, hls::stream<D_TYPE>& s_result_PE39, 
    hls::stream<D_TYPE>& s_result_PE40, hls::stream<D_TYPE>& s_result_PE41, 
    hls::stream<D_TYPE>& s_result_PE42, hls::stream<D_TYPE>& s_result_PE43, 
    hls::stream<D_TYPE>& s_result_PE44, hls::stream<D_TYPE>& s_result_PE45, 
    hls::stream<D_TYPE>& s_result_PE46, hls::stream<D_TYPE>& s_result_PE47, 
    hls::stream<D_TYPE>& s_result_PE48, hls::stream<D_TYPE>& s_result_PE49, 
    hls::stream<D_TYPE>& s_result_PE50, hls::stream<D_TYPE>& s_result_PE51, 
    hls::stream<D_TYPE>& s_result_PE52, hls::stream<D_TYPE>& s_result_PE53, 
    hls::stream<D_TYPE>& s_result_PE54, hls::stream<D_TYPE>& s_result_PE55, 
    hls::stream<D_TYPE>& s_result_PE56, hls::stream<D_TYPE>& s_result_PE57, 
    hls::stream<D_TYPE>& s_result_PE58, hls::stream<D_TYPE>& s_result_PE59, 
    hls::stream<D_TYPE>& s_result_PE60, hls::stream<D_TYPE>& s_result_PE61, 
    hls::stream<D_TYPE>& s_result_PE62, hls::stream<D_TYPE>& s_result_PE63, 
    hls::stream<D_TYPE>& s_result_PE64, hls::stream<D_TYPE>& s_result_PE65, 
    hls::stream<D_TYPE>& s_result_PE66, hls::stream<D_TYPE>& s_result_PE67, 
    hls::stream<D_TYPE>& s_result_PE68, hls::stream<D_TYPE>& s_result_PE69, 
    hls::stream<D_TYPE>& s_result_PE70, hls::stream<D_TYPE>& s_result_PE71, 
    hls::stream<D_TYPE>& s_result_PE72, hls::stream<D_TYPE>& s_result_PE73, 
    hls::stream<D_TYPE>& s_result_PE74, hls::stream<D_TYPE>& s_result_PE75, 
    hls::stream<D_TYPE>& s_result_PE76, hls::stream<D_TYPE>& s_result_PE77, 
    hls::stream<D_TYPE>& s_result_PE78, hls::stream<D_TYPE>& s_result_PE79, 
    hls::stream<D_TYPE>& s_result_PE80, hls::stream<D_TYPE>& s_result_PE81, 
    hls::stream<D_TYPE>& s_result_PE82, hls::stream<D_TYPE>& s_result_PE83, 
    hls::stream<D_TYPE>& s_result_PE84, hls::stream<D_TYPE>& s_result_PE85, 
    hls::stream<D_TYPE>& s_result_PE86, hls::stream<D_TYPE>& s_result_PE87, 
    hls::stream<D_TYPE>& s_result_PE88, hls::stream<D_TYPE>& s_result_PE89, 
    hls::stream<D_TYPE>& s_result_PE90, hls::stream<D_TYPE>& s_result_PE91, 
    hls::stream<D_TYPE>& s_result_PE92, hls::stream<D_TYPE>& s_result_PE93, 
    hls::stream<D_TYPE>& s_result_PE94, hls::stream<D_TYPE>& s_result_PE95, 
    hls::stream<D_TYPE>& s_result_PE96, hls::stream<D_TYPE>& s_result_PE97, 
    hls::stream<D_TYPE>& s_result_PE98, hls::stream<D_TYPE>& s_result_PE99, 
    hls::stream<D_TYPE>& s_result_PE100, hls::stream<D_TYPE>& s_result_PE101, 
    hls::stream<D_TYPE>& s_result_PE102, hls::stream<D_TYPE>& s_result_PE103, 
    hls::stream<D_TYPE>& s_result_PE104, hls::stream<D_TYPE>& s_result_PE105, 
    hls::stream<D_TYPE>& s_result_PE106, hls::stream<D_TYPE>& s_result_PE107, 
    hls::stream<D_TYPE>& s_result_PE108, hls::stream<D_TYPE>& s_result_PE109, 
    hls::stream<D_TYPE>& s_result_PE110, hls::stream<D_TYPE>& s_result_PE111, 
    hls::stream<D_TYPE>& s_result_PE112, hls::stream<D_TYPE>& s_result_PE113, 
    hls::stream<D_TYPE>& s_result_PE114, hls::stream<D_TYPE>& s_result_PE115, 
    hls::stream<D_TYPE>& s_result_PE116, hls::stream<D_TYPE>& s_result_PE117, 
    hls::stream<D_TYPE>& s_result_PE118, hls::stream<D_TYPE>& s_result_PE119, 
    hls::stream<D_TYPE>& s_result_PE120, hls::stream<D_TYPE>& s_result_PE121, 
    hls::stream<D_TYPE>& s_result_PE122, hls::stream<D_TYPE>& s_result_PE123, 
    hls::stream<D_TYPE>& s_result_PE124, hls::stream<D_TYPE>& s_result_PE125, 
    hls::stream<D_TYPE>& s_result_PE126, hls::stream<D_TYPE>& s_result_PE127, 
    hls::stream<D_TYPE>& s_result_PE128, hls::stream<D_TYPE>& s_result_PE129,
    hls::stream<D_TYPE>& s_result_PE130, hls::stream<D_TYPE>& s_result_PE131,
    hls::stream<D_TYPE>& s_result_PE132, hls::stream<D_TYPE>& s_result_PE133,
    hls::stream<D_TYPE>& s_result_PE134, hls::stream<D_TYPE>& s_result_PE135,
    hls::stream<D_TYPE>& s_result_PE136, hls::stream<D_TYPE>& s_result_PE137,
    hls::stream<D_TYPE>& s_result_PE138, hls::stream<D_TYPE>& s_result_PE139,
    hls::stream<D_TYPE>& s_result_PE140, hls::stream<D_TYPE>& s_result_PE141,
    hls::stream<D_TYPE>& s_result_PE142, hls::stream<D_TYPE>& s_result_PE143,
    hls::stream<D_TYPE>& s_result_PE144, hls::stream<D_TYPE>& s_result_PE145,
    hls::stream<D_TYPE>& s_result_PE146, hls::stream<D_TYPE>& s_result_PE147,
    hls::stream<D_TYPE>& s_result_PE148, hls::stream<D_TYPE>& s_result_PE149,
    hls::stream<D_TYPE>& s_result_PE150, hls::stream<D_TYPE>& s_result_PE151,
    hls::stream<D_TYPE>& s_result_PE152, hls::stream<D_TYPE>& s_result_PE153,
    hls::stream<D_TYPE>& s_result_PE154, hls::stream<D_TYPE>& s_result_PE155,
    hls::stream<D_TYPE>& s_result_PE156, hls::stream<D_TYPE>& s_result_PE157,
    hls::stream<D_TYPE>& s_result_PE158, hls::stream<D_TYPE>& s_result_PE159,
    hls::stream<ap_uint<512> >& s_result_all);

template<const int ROW_PER_PE>
void gather_results_224PEs(
    hls::stream<D_TYPE>& s_result_PE0, hls::stream<D_TYPE>& s_result_PE1, 
    hls::stream<D_TYPE>& s_result_PE2, hls::stream<D_TYPE>& s_result_PE3, 
    hls::stream<D_TYPE>& s_result_PE4, hls::stream<D_TYPE>& s_result_PE5, 
    hls::stream<D_TYPE>& s_result_PE6, hls::stream<D_TYPE>& s_result_PE7, 
    hls::stream<D_TYPE>& s_result_PE8, hls::stream<D_TYPE>& s_result_PE9, 
    hls::stream<D_TYPE>& s_result_PE10, hls::stream<D_TYPE>& s_result_PE11, 
    hls::stream<D_TYPE>& s_result_PE12, hls::stream<D_TYPE>& s_result_PE13, 
    hls::stream<D_TYPE>& s_result_PE14, hls::stream<D_TYPE>& s_result_PE15, 
    hls::stream<D_TYPE>& s_result_PE16, hls::stream<D_TYPE>& s_result_PE17, 
    hls::stream<D_TYPE>& s_result_PE18, hls::stream<D_TYPE>& s_result_PE19, 
    hls::stream<D_TYPE>& s_result_PE20, hls::stream<D_TYPE>& s_result_PE21, 
    hls::stream<D_TYPE>& s_result_PE22, hls::stream<D_TYPE>& s_result_PE23, 
    hls::stream<D_TYPE>& s_result_PE24, hls::stream<D_TYPE>& s_result_PE25, 
    hls::stream<D_TYPE>& s_result_PE26, hls::stream<D_TYPE>& s_result_PE27, 
    hls::stream<D_TYPE>& s_result_PE28, hls::stream<D_TYPE>& s_result_PE29, 
    hls::stream<D_TYPE>& s_result_PE30, hls::stream<D_TYPE>& s_result_PE31, 
    hls::stream<D_TYPE>& s_result_PE32, hls::stream<D_TYPE>& s_result_PE33, 
    hls::stream<D_TYPE>& s_result_PE34, hls::stream<D_TYPE>& s_result_PE35, 
    hls::stream<D_TYPE>& s_result_PE36, hls::stream<D_TYPE>& s_result_PE37, 
    hls::stream<D_TYPE>& s_result_PE38, hls::stream<D_TYPE>& s_result_PE39, 
    hls::stream<D_TYPE>& s_result_PE40, hls::stream<D_TYPE>& s_result_PE41, 
    hls::stream<D_TYPE>& s_result_PE42, hls::stream<D_TYPE>& s_result_PE43, 
    hls::stream<D_TYPE>& s_result_PE44, hls::stream<D_TYPE>& s_result_PE45, 
    hls::stream<D_TYPE>& s_result_PE46, hls::stream<D_TYPE>& s_result_PE47, 
    hls::stream<D_TYPE>& s_result_PE48, hls::stream<D_TYPE>& s_result_PE49, 
    hls::stream<D_TYPE>& s_result_PE50, hls::stream<D_TYPE>& s_result_PE51, 
    hls::stream<D_TYPE>& s_result_PE52, hls::stream<D_TYPE>& s_result_PE53, 
    hls::stream<D_TYPE>& s_result_PE54, hls::stream<D_TYPE>& s_result_PE55, 
    hls::stream<D_TYPE>& s_result_PE56, hls::stream<D_TYPE>& s_result_PE57, 
    hls::stream<D_TYPE>& s_result_PE58, hls::stream<D_TYPE>& s_result_PE59, 
    hls::stream<D_TYPE>& s_result_PE60, hls::stream<D_TYPE>& s_result_PE61, 
    hls::stream<D_TYPE>& s_result_PE62, hls::stream<D_TYPE>& s_result_PE63, 
    hls::stream<D_TYPE>& s_result_PE64, hls::stream<D_TYPE>& s_result_PE65, 
    hls::stream<D_TYPE>& s_result_PE66, hls::stream<D_TYPE>& s_result_PE67, 
    hls::stream<D_TYPE>& s_result_PE68, hls::stream<D_TYPE>& s_result_PE69, 
    hls::stream<D_TYPE>& s_result_PE70, hls::stream<D_TYPE>& s_result_PE71, 
    hls::stream<D_TYPE>& s_result_PE72, hls::stream<D_TYPE>& s_result_PE73, 
    hls::stream<D_TYPE>& s_result_PE74, hls::stream<D_TYPE>& s_result_PE75, 
    hls::stream<D_TYPE>& s_result_PE76, hls::stream<D_TYPE>& s_result_PE77, 
    hls::stream<D_TYPE>& s_result_PE78, hls::stream<D_TYPE>& s_result_PE79, 
    hls::stream<D_TYPE>& s_result_PE80, hls::stream<D_TYPE>& s_result_PE81, 
    hls::stream<D_TYPE>& s_result_PE82, hls::stream<D_TYPE>& s_result_PE83, 
    hls::stream<D_TYPE>& s_result_PE84, hls::stream<D_TYPE>& s_result_PE85, 
    hls::stream<D_TYPE>& s_result_PE86, hls::stream<D_TYPE>& s_result_PE87, 
    hls::stream<D_TYPE>& s_result_PE88, hls::stream<D_TYPE>& s_result_PE89, 
    hls::stream<D_TYPE>& s_result_PE90, hls::stream<D_TYPE>& s_result_PE91, 
    hls::stream<D_TYPE>& s_result_PE92, hls::stream<D_TYPE>& s_result_PE93, 
    hls::stream<D_TYPE>& s_result_PE94, hls::stream<D_TYPE>& s_result_PE95, 
    hls::stream<D_TYPE>& s_result_PE96, hls::stream<D_TYPE>& s_result_PE97, 
    hls::stream<D_TYPE>& s_result_PE98, hls::stream<D_TYPE>& s_result_PE99, 
    hls::stream<D_TYPE>& s_result_PE100, hls::stream<D_TYPE>& s_result_PE101, 
    hls::stream<D_TYPE>& s_result_PE102, hls::stream<D_TYPE>& s_result_PE103, 
    hls::stream<D_TYPE>& s_result_PE104, hls::stream<D_TYPE>& s_result_PE105, 
    hls::stream<D_TYPE>& s_result_PE106, hls::stream<D_TYPE>& s_result_PE107, 
    hls::stream<D_TYPE>& s_result_PE108, hls::stream<D_TYPE>& s_result_PE109, 
    hls::stream<D_TYPE>& s_result_PE110, hls::stream<D_TYPE>& s_result_PE111, 
    hls::stream<D_TYPE>& s_result_PE112, hls::stream<D_TYPE>& s_result_PE113, 
    hls::stream<D_TYPE>& s_result_PE114, hls::stream<D_TYPE>& s_result_PE115, 
    hls::stream<D_TYPE>& s_result_PE116, hls::stream<D_TYPE>& s_result_PE117, 
    hls::stream<D_TYPE>& s_result_PE118, hls::stream<D_TYPE>& s_result_PE119, 
    hls::stream<D_TYPE>& s_result_PE120, hls::stream<D_TYPE>& s_result_PE121, 
    hls::stream<D_TYPE>& s_result_PE122, hls::stream<D_TYPE>& s_result_PE123, 
    hls::stream<D_TYPE>& s_result_PE124, hls::stream<D_TYPE>& s_result_PE125, 
    hls::stream<D_TYPE>& s_result_PE126, hls::stream<D_TYPE>& s_result_PE127, 
    hls::stream<D_TYPE>& s_result_PE128, hls::stream<D_TYPE>& s_result_PE129,
    hls::stream<D_TYPE>& s_result_PE130, hls::stream<D_TYPE>& s_result_PE131,
    hls::stream<D_TYPE>& s_result_PE132, hls::stream<D_TYPE>& s_result_PE133,
    hls::stream<D_TYPE>& s_result_PE134, hls::stream<D_TYPE>& s_result_PE135,
    hls::stream<D_TYPE>& s_result_PE136, hls::stream<D_TYPE>& s_result_PE137,
    hls::stream<D_TYPE>& s_result_PE138, hls::stream<D_TYPE>& s_result_PE139,
    hls::stream<D_TYPE>& s_result_PE140, hls::stream<D_TYPE>& s_result_PE141,
    hls::stream<D_TYPE>& s_result_PE142, hls::stream<D_TYPE>& s_result_PE143,
    hls::stream<D_TYPE>& s_result_PE144, hls::stream<D_TYPE>& s_result_PE145,
    hls::stream<D_TYPE>& s_result_PE146, hls::stream<D_TYPE>& s_result_PE147,
    hls::stream<D_TYPE>& s_result_PE148, hls::stream<D_TYPE>& s_result_PE149,
    hls::stream<D_TYPE>& s_result_PE150, hls::stream<D_TYPE>& s_result_PE151,
    hls::stream<D_TYPE>& s_result_PE152, hls::stream<D_TYPE>& s_result_PE153,
    hls::stream<D_TYPE>& s_result_PE154, hls::stream<D_TYPE>& s_result_PE155,
    hls::stream<D_TYPE>& s_result_PE156, hls::stream<D_TYPE>& s_result_PE157,
    hls::stream<D_TYPE>& s_result_PE158, hls::stream<D_TYPE>& s_result_PE159,
    hls::stream<D_TYPE>& s_result_PE160, hls::stream<D_TYPE>& s_result_PE161,
    hls::stream<D_TYPE>& s_result_PE162, hls::stream<D_TYPE>& s_result_PE163,
    hls::stream<D_TYPE>& s_result_PE164, hls::stream<D_TYPE>& s_result_PE165,
    hls::stream<D_TYPE>& s_result_PE166, hls::stream<D_TYPE>& s_result_PE167,
    hls::stream<D_TYPE>& s_result_PE168, hls::stream<D_TYPE>& s_result_PE169,
    hls::stream<D_TYPE>& s_result_PE170, hls::stream<D_TYPE>& s_result_PE171,
    hls::stream<D_TYPE>& s_result_PE172, hls::stream<D_TYPE>& s_result_PE173,
    hls::stream<D_TYPE>& s_result_PE174, hls::stream<D_TYPE>& s_result_PE175,
    hls::stream<D_TYPE>& s_result_PE176, hls::stream<D_TYPE>& s_result_PE177,
    hls::stream<D_TYPE>& s_result_PE178, hls::stream<D_TYPE>& s_result_PE179,
    hls::stream<D_TYPE>& s_result_PE180, hls::stream<D_TYPE>& s_result_PE181,
    hls::stream<D_TYPE>& s_result_PE182, hls::stream<D_TYPE>& s_result_PE183,
    hls::stream<D_TYPE>& s_result_PE184, hls::stream<D_TYPE>& s_result_PE185,
    hls::stream<D_TYPE>& s_result_PE186, hls::stream<D_TYPE>& s_result_PE187,
    hls::stream<D_TYPE>& s_result_PE188, hls::stream<D_TYPE>& s_result_PE189,
    hls::stream<D_TYPE>& s_result_PE190, hls::stream<D_TYPE>& s_result_PE191,
    hls::stream<D_TYPE>& s_result_PE192, hls::stream<D_TYPE>& s_result_PE193,
    hls::stream<D_TYPE>& s_result_PE194, hls::stream<D_TYPE>& s_result_PE195,
    hls::stream<D_TYPE>& s_result_PE196, hls::stream<D_TYPE>& s_result_PE197,
    hls::stream<D_TYPE>& s_result_PE198, hls::stream<D_TYPE>& s_result_PE199,
    hls::stream<D_TYPE>& s_result_PE200, hls::stream<D_TYPE>& s_result_PE201, 
    hls::stream<D_TYPE>& s_result_PE202, hls::stream<D_TYPE>& s_result_PE203, 
    hls::stream<D_TYPE>& s_result_PE204, hls::stream<D_TYPE>& s_result_PE205, 
    hls::stream<D_TYPE>& s_result_PE206, hls::stream<D_TYPE>& s_result_PE207, 
    hls::stream<D_TYPE>& s_result_PE208, hls::stream<D_TYPE>& s_result_PE209, 
    hls::stream<D_TYPE>& s_result_PE210, hls::stream<D_TYPE>& s_result_PE211, 
    hls::stream<D_TYPE>& s_result_PE212, hls::stream<D_TYPE>& s_result_PE213, 
    hls::stream<D_TYPE>& s_result_PE214, hls::stream<D_TYPE>& s_result_PE215,
    hls::stream<D_TYPE>& s_result_PE216, hls::stream<D_TYPE>& s_result_PE217, 
    hls::stream<D_TYPE>& s_result_PE218, hls::stream<D_TYPE>& s_result_PE219, 
    hls::stream<D_TYPE>& s_result_PE220, hls::stream<D_TYPE>& s_result_PE221, 
    hls::stream<D_TYPE>& s_result_PE222, hls::stream<D_TYPE>& s_result_PE223, 
    hls::stream<ap_uint<512> >& s_result_all);

template<const int ROW_PER_PE>
void gather_results_32PEs(
    hls::stream<D_TYPE>& s_result_PE0, hls::stream<D_TYPE>& s_result_PE1, 
    hls::stream<D_TYPE>& s_result_PE2, hls::stream<D_TYPE>& s_result_PE3, 
    hls::stream<D_TYPE>& s_result_PE4, hls::stream<D_TYPE>& s_result_PE5, 
    hls::stream<D_TYPE>& s_result_PE6, hls::stream<D_TYPE>& s_result_PE7, 
    hls::stream<D_TYPE>& s_result_PE8, hls::stream<D_TYPE>& s_result_PE9, 
    hls::stream<D_TYPE>& s_result_PE10, hls::stream<D_TYPE>& s_result_PE11, 
    hls::stream<D_TYPE>& s_result_PE12, hls::stream<D_TYPE>& s_result_PE13, 
    hls::stream<D_TYPE>& s_result_PE14, hls::stream<D_TYPE>& s_result_PE15, 
    hls::stream<D_TYPE>& s_result_PE16, hls::stream<D_TYPE>& s_result_PE17, 
    hls::stream<D_TYPE>& s_result_PE18, hls::stream<D_TYPE>& s_result_PE19, 
    hls::stream<D_TYPE>& s_result_PE20, hls::stream<D_TYPE>& s_result_PE21, 
    hls::stream<D_TYPE>& s_result_PE22, hls::stream<D_TYPE>& s_result_PE23, 
    hls::stream<D_TYPE>& s_result_PE24, hls::stream<D_TYPE>& s_result_PE25, 
    hls::stream<D_TYPE>& s_result_PE26, hls::stream<D_TYPE>& s_result_PE27, 
    hls::stream<D_TYPE>& s_result_PE28, hls::stream<D_TYPE>& s_result_PE29, 
    hls::stream<D_TYPE>& s_result_PE30, hls::stream<D_TYPE>& s_result_PE31, 
    hls::stream<ap_uint<512> >& s_result_all);

template<const int ROW_PER_PE>
void gather_results_48PEs(
    hls::stream<D_TYPE>& s_result_PE0, hls::stream<D_TYPE>& s_result_PE1, 
    hls::stream<D_TYPE>& s_result_PE2, hls::stream<D_TYPE>& s_result_PE3, 
    hls::stream<D_TYPE>& s_result_PE4, hls::stream<D_TYPE>& s_result_PE5, 
    hls::stream<D_TYPE>& s_result_PE6, hls::stream<D_TYPE>& s_result_PE7, 
    hls::stream<D_TYPE>& s_result_PE8, hls::stream<D_TYPE>& s_result_PE9, 
    hls::stream<D_TYPE>& s_result_PE10, hls::stream<D_TYPE>& s_result_PE11, 
    hls::stream<D_TYPE>& s_result_PE12, hls::stream<D_TYPE>& s_result_PE13, 
    hls::stream<D_TYPE>& s_result_PE14, hls::stream<D_TYPE>& s_result_PE15, 
    hls::stream<D_TYPE>& s_result_PE16, hls::stream<D_TYPE>& s_result_PE17, 
    hls::stream<D_TYPE>& s_result_PE18, hls::stream<D_TYPE>& s_result_PE19, 
    hls::stream<D_TYPE>& s_result_PE20, hls::stream<D_TYPE>& s_result_PE21, 
    hls::stream<D_TYPE>& s_result_PE22, hls::stream<D_TYPE>& s_result_PE23, 
    hls::stream<D_TYPE>& s_result_PE24, hls::stream<D_TYPE>& s_result_PE25, 
    hls::stream<D_TYPE>& s_result_PE26, hls::stream<D_TYPE>& s_result_PE27, 
    hls::stream<D_TYPE>& s_result_PE28, hls::stream<D_TYPE>& s_result_PE29, 
    hls::stream<D_TYPE>& s_result_PE30, hls::stream<D_TYPE>& s_result_PE31, 
    hls::stream<D_TYPE>& s_result_PE32, hls::stream<D_TYPE>& s_result_PE33, 
    hls::stream<D_TYPE>& s_result_PE34, hls::stream<D_TYPE>& s_result_PE35, 
    hls::stream<D_TYPE>& s_result_PE36, hls::stream<D_TYPE>& s_result_PE37, 
    hls::stream<D_TYPE>& s_result_PE38, hls::stream<D_TYPE>& s_result_PE39, 
    hls::stream<D_TYPE>& s_result_PE40, hls::stream<D_TYPE>& s_result_PE41, 
    hls::stream<D_TYPE>& s_result_PE42, hls::stream<D_TYPE>& s_result_PE43, 
    hls::stream<D_TYPE>& s_result_PE44, hls::stream<D_TYPE>& s_result_PE45, 
    hls::stream<D_TYPE>& s_result_PE46, hls::stream<D_TYPE>& s_result_PE47, 
    hls::stream<ap_uint<512> >& s_result_all);

void dataTransform(
    hls::stream<ap_uint<512> > & s_result_partial_1, hls::stream<ap_uint<512> > & s_result_partial_2, 
    hls::stream<ap_uint<512> > & s_result_partial_3, hls::stream<ap_uint<512> > & s_result_partial_4, 
    hls::stream<ap_uint<512> > & s_result_partial_5, hls::stream<ap_uint<512> > & s_result_partial_6, 
    hls::stream<ap_uint<512> > & s_result_partial_7, hls::stream<ap_uint<512> > & s_result_partial_8, 
    hls::stream<ap_uint<512> > & s_result_partial_9, hls::stream<ap_uint<512> > & s_result_partial_10,
    hls::stream<ap_uint<512> > & s_result_partial_11,
    hls::stream<ap_uint<512> > & s_data_out);

void gather_results_layer1(hls::stream<ap_uint<512> > & s_result1_node2, hls::stream<ap_uint<512> > & s_result1_node3, hls::stream<ap_uint<512> > & s_result1_all_1, hls::stream<ap_uint<512> > & s_result1_all_2);

const int trip_count_item_num = BATCH_NUM * BATCH_SIZE;

const int fifo_batch_size = FIFO_BATCH_SIZE;

const int depth_s_embedding_buffer_HBM0 = VECTOR_SIZE_HBM_BANK_0 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM1 = VECTOR_SIZE_HBM_BANK_1 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM2 = VECTOR_SIZE_HBM_BANK_2 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM3 = VECTOR_SIZE_HBM_BANK_3 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM4 = VECTOR_SIZE_HBM_BANK_4 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM5 = VECTOR_SIZE_HBM_BANK_5 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM6 = VECTOR_SIZE_HBM_BANK_6 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM7 = VECTOR_SIZE_HBM_BANK_7 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM8 = VECTOR_SIZE_HBM_BANK_8 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM9 = VECTOR_SIZE_HBM_BANK_9 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM10 = VECTOR_SIZE_HBM_BANK_10 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM11 = VECTOR_SIZE_HBM_BANK_11 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM12 = VECTOR_SIZE_HBM_BANK_12 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM13 = VECTOR_SIZE_HBM_BANK_13 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM14 = VECTOR_SIZE_HBM_BANK_14 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM15 = VECTOR_SIZE_HBM_BANK_15 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM16 = VECTOR_SIZE_HBM_BANK_16 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM17 = VECTOR_SIZE_HBM_BANK_17 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM18 = VECTOR_SIZE_HBM_BANK_18 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM19 = VECTOR_SIZE_HBM_BANK_19 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM20 = VECTOR_SIZE_HBM_BANK_20 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM21 = VECTOR_SIZE_HBM_BANK_21 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM22 = VECTOR_SIZE_HBM_BANK_22 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM23 = VECTOR_SIZE_HBM_BANK_23 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM24 = VECTOR_SIZE_HBM_BANK_24 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM25 = VECTOR_SIZE_HBM_BANK_25 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM26 = VECTOR_SIZE_HBM_BANK_26 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM27 = VECTOR_SIZE_HBM_BANK_27 * FIFO_BATCH_SIZE;
//const int depth_s_embedding_buffer_HBM28 = VECTOR_SIZE_HBM_BANK_28 * FIFO_BATCH_SIZE;
//const int depth_s_embedding_buffer_HBM29 = VECTOR_SIZE_HBM_BANK_29 * FIFO_BATCH_SIZE;
//const int depth_s_embedding_buffer_HBM30 = VECTOR_SIZE_HBM_BANK_30 * FIFO_BATCH_SIZE;
//const int depth_s_embedding_buffer_HBM31 = VECTOR_SIZE_HBM_BANK_31 * FIFO_BATCH_SIZE;
//
//const int depth_s_embedding_buffer_PLRAM0 = VECTOR_SIZE_PLRAM_BANK_0 * FIFO_BATCH_SIZE;
//const int depth_s_embedding_buffer_PLRAM1 = VECTOR_SIZE_PLRAM_BANK_1 * FIFO_BATCH_SIZE;
//const int depth_s_embedding_buffer_PLRAM2 = VECTOR_SIZE_PLRAM_BANK_2 * FIFO_BATCH_SIZE;
//const int depth_s_embedding_buffer_PLRAM3 = VECTOR_SIZE_PLRAM_BANK_3 * FIFO_BATCH_SIZE;
//
//const int depth_s_embedding_buffer_DDR0 = VECTOR_SIZE_DDR_BANK_0 * FIFO_BATCH_SIZE;
//const int depth_s_embedding_buffer_DDR1 = VECTOR_SIZE_DDR_BANK_1 * FIFO_BATCH_SIZE;


void recvDataTransform(hls::stream<ap_uint<512> > & s_data_in, hls::stream<ap_uint<512> > & s_feature_in, hls::stream<ap_uint<512> > & s_result1_partial){
    // s_data_in is the whole result of layer 1 from node 2
    // s_feature_in and s_result1_all are the same
    // s_feature_in is used to replicate features
    // s_result1_all is used to transfer the result of layer 1 to node 4
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        for (int i = 0; i < 55; i++){
            #pragma HLS pipeline II=1
            ap_uint<512> s_data = s_data_in.read();
            s_feature_in.write(s_data);
        }
        for (int i = 0; i < 52; i++){
            #pragma HLS pipeline II=1
            ap_uint<512> s_data = s_data_in.read();
            s_result1_partial.write(s_data);
        }

    }
}

void recvDataTransform_1(hls::stream<ap_uint<512> > & s_data_in, hls::stream<ap_uint<512> > & s_feature_in_1, hls::stream<ap_uint<512> > & s_result1_all){
    // s_data_in is the whole result of layer 1 from node 2
    // s_feature_in and s_result1_all are the same
    // s_feature_in is used to replicate features
    // s_result1_all is used to transfer the result of layer 1 to node 4
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        for (int i = 0; i < HIDDEN_SIZE1 / 4 / 4; i++){
            #pragma HLS pipeline II=1

            ap_uint<512> s_data = s_data_in.read();

            s_feature_in_1.write(s_data);
            s_result1_all.write(s_data);
        }

    }
}

void recvDataTransform_4(hls::stream<ap_uint<512> > & s_data_in, hls::stream<ap_uint<512> > & s_feature_in_0, hls::stream<ap_uint<512> > & s_feature_in_1, hls::stream<ap_uint<512> > & s_feature_in_2, hls::stream<ap_uint<512> > & s_feature_in_3, hls::stream<ap_uint<512> > & s_result1_all){
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        for (int i = 0; i < HIDDEN_SIZE1 / 4 / 4; i++){
            #pragma HLS pipeline II=1

            ap_uint<512> s_data = s_data_in.read();

            s_feature_in_0.write(s_data);
            s_feature_in_1.write(s_data);
            s_feature_in_2.write(s_data);
            s_feature_in_3.write(s_data);
            s_result1_all.write(s_data);
        }

    }
}

void recvDataTransform_8(
    hls::stream<ap_uint<512> > & s_data_in, 
    hls::stream<ap_uint<512> > & s_feature_in_0, hls::stream<ap_uint<512> > & s_feature_in_1, 
    hls::stream<ap_uint<512> > & s_feature_in_2, hls::stream<ap_uint<512> > & s_feature_in_3, 
    hls::stream<ap_uint<512> > & s_feature_in_4, hls::stream<ap_uint<512> > & s_feature_in_5, 
    hls::stream<ap_uint<512> > & s_feature_in_6, hls::stream<ap_uint<512> > & s_feature_in_7, 
    hls::stream<ap_uint<512> > & s_result1_all){

    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        for (int i = 0; i < HIDDEN_SIZE1 / 4 / 4; i++){
            #pragma HLS pipeline II=1

            ap_uint<512> s_data = s_data_in.read();

            s_feature_in_0.write(s_data);
            s_feature_in_1.write(s_data);
            s_feature_in_2.write(s_data);
            s_feature_in_3.write(s_data);
            s_feature_in_4.write(s_data);
            s_feature_in_5.write(s_data);
            s_feature_in_6.write(s_data);
            s_feature_in_7.write(s_data);

            s_result1_all.write(s_data);
        }
    }
}

void recvDataTransform_10(
    hls::stream<ap_uint<512> > & s_data_in, 
    hls::stream<ap_uint<512> > & s_feature_in_0, hls::stream<ap_uint<512> > & s_feature_in_1, 
    hls::stream<ap_uint<512> > & s_feature_in_2, hls::stream<ap_uint<512> > & s_feature_in_3, 
    hls::stream<ap_uint<512> > & s_feature_in_4, hls::stream<ap_uint<512> > & s_feature_in_5, 
    hls::stream<ap_uint<512> > & s_feature_in_6, hls::stream<ap_uint<512> > & s_feature_in_7, 
    hls::stream<ap_uint<512> > & s_feature_in_8, hls::stream<ap_uint<512> > & s_feature_in_9, 
    hls::stream<ap_uint<512> > & s_result1_all){

    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        for (int i = 0; i < HIDDEN_SIZE1 / 4 / 4; i++){
            #pragma HLS pipeline II=1

            ap_uint<512> s_data = s_data_in.read();

            s_feature_in_0.write(s_data);
            s_feature_in_1.write(s_data);
            s_feature_in_2.write(s_data);
            s_feature_in_3.write(s_data);
            s_feature_in_4.write(s_data);
            s_feature_in_5.write(s_data);
            s_feature_in_6.write(s_data);
            s_feature_in_7.write(s_data);
            s_feature_in_8.write(s_data);
            s_feature_in_9.write(s_data);

            s_result1_all.write(s_data);
        }
    }
}

void replicate_feature_in_6(
    hls::stream<ap_uint<512> > & s_feature_in, 
    hls::stream<ap_uint<512> > & s_feature_in_0, hls::stream<ap_uint<512> > & s_feature_in_1, 
    hls::stream<ap_uint<512> > & s_feature_in_2, hls::stream<ap_uint<512> > & s_feature_in_3, 
    hls::stream<ap_uint<512> > & s_feature_in_4, hls::stream<ap_uint<512> > & s_feature_in_5)
{
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        for (int i = 0; i < 55; i++){
            #pragma HLS pipeline II=1
            ap_uint<512> s_data = s_feature_in.read();
            s_feature_in_0.write(s_data);
            s_feature_in_1.write(s_data);
            s_feature_in_2.write(s_data);
            s_feature_in_3.write(s_data);
            s_feature_in_4.write(s_data);
            s_feature_in_5.write(s_data);
        }

    }
}

void replicate_feature_in_7(
    hls::stream<ap_uint<512> > & s_feature_in, 
    hls::stream<ap_uint<512> > & s_feature_in_0, hls::stream<ap_uint<512> > & s_feature_in_1, 
    hls::stream<ap_uint<512> > & s_feature_in_2, hls::stream<ap_uint<512> > & s_feature_in_3, 
    hls::stream<ap_uint<512> > & s_feature_in_4, hls::stream<ap_uint<512> > & s_feature_in_5,
    hls::stream<ap_uint<512> > & s_feature_in_6)
{
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        for (int i = 0; i < 64; i++){
            #pragma HLS pipeline II=1
            ap_uint<512> s_data = s_feature_in.read();
            s_feature_in_0.write(s_data);
            s_feature_in_1.write(s_data);
            s_feature_in_2.write(s_data);
            s_feature_in_3.write(s_data);
            s_feature_in_4.write(s_data);
            s_feature_in_5.write(s_data);
            s_feature_in_6.write(s_data);
        }

    }
}

void replicate_feature_in_16(
    hls::stream<ap_uint<512> > & s_feature_in, 
    hls::stream<ap_uint<512> > & s_feature_in_0, hls::stream<ap_uint<512> > & s_feature_in_1, 
    hls::stream<ap_uint<512> > & s_feature_in_2, hls::stream<ap_uint<512> > & s_feature_in_3, 
    hls::stream<ap_uint<512> > & s_feature_in_4, hls::stream<ap_uint<512> > & s_feature_in_5, 
    hls::stream<ap_uint<512> > & s_feature_in_6, hls::stream<ap_uint<512> > & s_feature_in_7, 
    hls::stream<ap_uint<512> > & s_feature_in_8, hls::stream<ap_uint<512> > & s_feature_in_9, 
    hls::stream<ap_uint<512> > & s_feature_in_10, hls::stream<ap_uint<512> > & s_feature_in_11, 
    hls::stream<ap_uint<512> > & s_feature_in_12, hls::stream<ap_uint<512> > & s_feature_in_13, 
    hls::stream<ap_uint<512> > & s_feature_in_14, hls::stream<ap_uint<512> > & s_feature_in_15)
{
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        for (int i = 0; i < HIDDEN_SIZE1 / INTS_PER_W / 4; i++){
            #pragma HLS pipeline II=1
            ap_uint<512> s_data = s_feature_in.read();
            s_feature_in_0.write(s_data);
            s_feature_in_1.write(s_data);
            s_feature_in_2.write(s_data);
            s_feature_in_3.write(s_data);
            s_feature_in_4.write(s_data);
            s_feature_in_5.write(s_data);
            s_feature_in_6.write(s_data);
            s_feature_in_7.write(s_data);
            s_feature_in_8.write(s_data);
            s_feature_in_9.write(s_data);
            s_feature_in_10.write(s_data);
            s_feature_in_11.write(s_data);
            s_feature_in_12.write(s_data);
            s_feature_in_13.write(s_data);
            s_feature_in_14.write(s_data);
            s_feature_in_15.write(s_data);
        }

    }
}

template<const int FEATURE_SIZE, const int INDEX_ROW>
void matmul_PE_UNROLL8_layer1(
    hls::stream<W_TYPE>& s_feature_PE_0,
    hls::stream<W_TYPE>& s_feature_PE_1,
    hls::stream<D_TYPE>& s_result_PE){

#pragma HLS inline off

    W_TYPE weights_transpose_local[FEATURE_SIZE / INTS_PER_W];
#pragma HLS resource variable=weights_transpose_local core=RAM_2P_BRAM
    //if (INDEX_ROW==INDEX_EVEN){
    //    W_TYPE weights_transpose_local[FEATURE_SIZE / INTS_PER_W];
    //#pragma HLS resource variable=weights_transpose_local core=RAM_2P_BRAM
    //}
    //else{
    //    W_TYPE weights_transpose_local[FEATURE_SIZE / INTS_PER_W];
    //#pragma HLS resource variable=weights_transpose_local core=RAM_2P_URAM
    //}
    
    init_weights<FEATURE_SIZE, INDEX_ROW>(weights_transpose_local);

    item_loop:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        
        D_TYPE result = 0;
        dot_product:
        // NOTE: manually unroll 2 here
        for (int d = 0; d < FEATURE_SIZE / INTS_PER_W / 2; d++) {
            // #pragma HLS unroll factor=4
            #pragma HLS pipeline II=1
            // feature[d] * weights_transpose_local[result_idx][d]
            W_TYPE reg_f_0 = s_feature_PE_0.read();
            W_TYPE reg_f_1 = s_feature_PE_1.read();
            W_TYPE reg_w_0 = weights_transpose_local[2 * d];
            W_TYPE reg_w_1 = weights_transpose_local[2 * d + 1];

            D_TYPE first_f_0 = reg_f_0.range(31, 0);
            D_TYPE second_f_0 = reg_f_0.range(63, 32);
            D_TYPE third_f_0 = reg_f_0.range(95, 64);
            D_TYPE fourth_f_0 = reg_f_0.range(127, 96);

            D_TYPE first_w_0= reg_w_0.range(31, 0);
            D_TYPE second_w_0 = reg_w_0.range(63, 32);
            D_TYPE third_w_0 = reg_w_0.range(95, 64);
            D_TYPE fourth_w_0 = reg_w_0.range(127, 96);

            D_TYPE first_f_1 = reg_f_1.range(31, 0);
            D_TYPE second_f_1 = reg_f_1.range(63, 32);
            D_TYPE third_f_1 = reg_f_1.range(95, 64);
            D_TYPE fourth_f_1 = reg_f_1.range(127, 96);

            D_TYPE first_w_1= reg_w_1.range(31, 0);
            D_TYPE second_w_1 = reg_w_1.range(63, 32);
            D_TYPE third_w_1 = reg_w_1.range(95, 64);
            D_TYPE fourth_w_1 = reg_w_1.range(127, 96);
            result += 
                first_f_0 * first_w_0 + second_f_0 * second_w_0 + 
                third_f_0 * third_w_0 + fourth_f_0 * fourth_w_0 + 
                first_f_1 * first_w_1 + second_f_1 * second_w_1 + 
                third_f_1 * third_w_1 + fourth_f_1 * fourth_w_1;
        }
        s_result_PE.write(result);
    }

}

template<const int FEATURE_SIZE, const int INDEX_ROW>
void matmul_PE_UNROLL8_layer2(
    hls::stream<W_TYPE>& s_feature_PE_0,
    hls::stream<W_TYPE>& s_feature_PE_1,
    hls::stream<D_TYPE>& s_result_PE){

#pragma HLS inline off

    W_TYPE weights_transpose_local[FEATURE_SIZE / INTS_PER_W];
#pragma HLS resource variable=weights_transpose_local core=RAM_2P_URAM
    //if (INDEX_ROW==INDEX_EVEN){
    //    W_TYPE weights_transpose_local[FEATURE_SIZE / INTS_PER_W];
    //#pragma HLS resource variable=weights_transpose_local core=RAM_2P_BRAM
    //}
    //else{
    //    W_TYPE weights_transpose_local[FEATURE_SIZE / INTS_PER_W];
    //#pragma HLS resource variable=weights_transpose_local core=RAM_2P_URAM
    //}
    
    init_weights<FEATURE_SIZE, INDEX_ROW>(weights_transpose_local);

    item_loop:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        
        D_TYPE result = 0;
        dot_product:
        // NOTE: manually unroll 2 here
        for (int d = 0; d < FEATURE_SIZE / INTS_PER_W / 2; d++) {
            // #pragma HLS unroll factor=4
            #pragma HLS pipeline II=1
            // feature[d] * weights_transpose_local[result_idx][d]
            W_TYPE reg_f_0 = s_feature_PE_0.read();
            W_TYPE reg_f_1 = s_feature_PE_1.read();
            W_TYPE reg_w_0 = weights_transpose_local[2 * d];
            W_TYPE reg_w_1 = weights_transpose_local[2 * d + 1];

            D_TYPE first_f_0 = reg_f_0.range(31, 0);
            D_TYPE second_f_0 = reg_f_0.range(63, 32);
            D_TYPE third_f_0 = reg_f_0.range(95, 64);
            D_TYPE fourth_f_0 = reg_f_0.range(127, 96);

            D_TYPE first_w_0= reg_w_0.range(31, 0);
            D_TYPE second_w_0 = reg_w_0.range(63, 32);
            D_TYPE third_w_0 = reg_w_0.range(95, 64);
            D_TYPE fourth_w_0 = reg_w_0.range(127, 96);

            D_TYPE first_f_1 = reg_f_1.range(31, 0);
            D_TYPE second_f_1 = reg_f_1.range(63, 32);
            D_TYPE third_f_1 = reg_f_1.range(95, 64);
            D_TYPE fourth_f_1 = reg_f_1.range(127, 96);

            D_TYPE first_w_1= reg_w_1.range(31, 0);
            D_TYPE second_w_1 = reg_w_1.range(63, 32);
            D_TYPE third_w_1 = reg_w_1.range(95, 64);
            D_TYPE fourth_w_1 = reg_w_1.range(127, 96);
            result += 
                first_f_0 * first_w_0 + second_f_0 * second_w_0 + 
                third_f_0 * third_w_0 + fourth_f_0 * fourth_w_0 + 
                first_f_1 * first_w_1 + second_f_1 * second_w_1 + 
                third_f_1 * third_w_1 + fourth_f_1 * fourth_w_1;
        }
        s_result_PE.write(result);
    }

}

template<>
void init_weights<INPUT_SIZE, INDEX_EVEN>(W_TYPE* weights_transpose_local) {

    D_TYPE row_template_even[INPUT_SIZE] = 
      { 0,  0,  0,  0,  0,  0,  0, -1,  0,  1,  0,  0, -1,  0,  0,  0,  0,
        1,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       -1,  0,  0,  0,  0,  0,  0,  0, -1,  0, -1,  0,  0, -1,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0, -1, -1,  0,  0,  0,  0, -1,  0,  0,  0,
        0,  0,  1,  0,  0,  0,  0,  0,  0,  0, -1,  1,  0,  0,  0,  0,  1,
        0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  1,  0, -1, -1,  0, -1,  0,
       -1,  1,  0,  0,  0,  0, -1,  0,  0, -1,  0,  1,  0,  0, -1,  1, -1,
        0,  0,  1,  0,  0,  0,  0,  0, -1,  0, -1,  0,  0,  1, -1,  0,  0,
        0,  0,  0,  0,  1,  0,  1, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0, -1,  0,  1,  0,  0,  1, -1,  0,  0,  1,  1,  1,
        0,  0,  0,  0,  0,  1,  0,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,
        1,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  0,  1,  0, -1,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1, -1,  1,  0,  0, -1,  0,
       -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,
        0,  0,  0,  0,  1,  0,  0,  0,  0,  0, -1,  1,  0,  0,  0,  0,  0,
       -1, -1,  0,  0, -1,  0,  0,  0,  0,  0,  0,  0,  1, -1,  0,  0,  0,
        0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  1,  0,  0,  0,  1,  0,  0,
        0,  0,  0, -1,  0, -1,  0,  0,  0,  0,  1, -1,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  1,  0,  0,  0,  1,  0, -1,  0,  0,  1,  1,  0,  0,  0,  0,
        0,  1,  0,  0,  0,  0,  0,  0,  1,  0,  1,  0, -1,  1,  0,  1, -1,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  1,  0,  0,  0,  1,  0,
        1,  0,  0,  0,  0,  1,  0,  0, -1,  0,  0,  0,  1,  0,  0,  0,  0,
        0,  0,  1,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0, -1,  0,  0,  0,
        1,  0,  0,  0,  0,  0,  0,  0, -1,  0, -1,  0,  0,  0,  0,  0,  0,
       -1,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,
        0,  0,  0,  0,  1, -1,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  0,
        0,  0,  0, -1,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0, -1,  0,  0, -1,
        0,  0,  0,  0, -1,  0, -1,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,
        1,  0,  0,  0, -1,  0,  0,  0,  0, -1, -1,  0,  1,  1,  0,  0, -1,
        0,  0,  0,  1,  0,  0,  0,  0, -1,  0, -1,  0,  0,  0,  0,  0,  1,
        0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  0, -1,  1, -1,  0,  0,
        0,  0,  0,  0,  0,  1,  1,  0, -1, -1,  0,  0,  0,  0, -1,  1,  0,
        0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0, -1,  1,  0, -1,  0,  0,
        0, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,
        0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  1,  0, -1, -1,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  0,  0,  1,  0,
        0,  0,  0,  0,  0,  0, -1,  0,  0,  0, -1,  0,  0,  0, -1,  0,  0,
        1,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,
        0, -1,  0,  0,  0, -1, -1,  0,  0, -1,  0,  0,  0,  1,  0,  1,  0,
        0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,
        0,  0,  1,  0,  0,  0,  1,  0,  0,  1, -1, -1,  0,  0, -1,  0,  1,
        0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  1,
        0,  0,  0,  0,  0,  0,  0,  0,  0, -1, -1,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  1, -1,  0,  0,  0,  1, -1,  0,  1,  0,  1,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0, -1,  0,  0, -1,  0,  0, -1,  0,  0,  0,  0,
        1,  0,  1,  0, -1,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,
        1,  0,  0,  1,  1, -1,  0,  1,  0,  0,  0,  0,  0,  0, -1,  0,  0,
        0,  1,  0,  0, -1,  0,  1,  0, -1, -1,  0,  1,  0};

    // load weights, convert to wide type
    for (int i = 0; i < INPUT_SIZE / INTS_PER_W; i++) {
        #pragma HLS pipeline II=1
        W_TYPE reg_even;
        reg_even.range(31, 0) = row_template_even[INTS_PER_W * i];
        reg_even.range(63, 32) = row_template_even[INTS_PER_W * i + 1];
        reg_even.range(95, 64) = row_template_even[INTS_PER_W * i + 2];
        reg_even.range(127, 96) = row_template_even[INTS_PER_W * i + 3];

        weights_transpose_local[i] = reg_even;
    }

}

template<>
void init_weights<INPUT_SIZE, INDEX_ODD>(W_TYPE* weights_transpose_local) {

    D_TYPE row_template_odd[INPUT_SIZE] = 
      { 1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,
        1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0, -1, -1,  0, -1,
        0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  1,  0,  0,  0,  0,  0,
        0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  1,  0,  0,  0,  0,  1,  0, -1,  0,  0,  1,  0, -1,  0,  0,
       -1,  0,  0,  0,  1,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0, -1,
        0,  0,  0,  0, -1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0, -1,  0,  0,
        0,  0,  0, -1,  0, -1,  1,  1,  0,  0,  0, -1,  0,  0, -1,  0, -1,
        0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  1,  0,  0, -1,
        0,  0,  0,  0,  0, -1, -1,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  1,
        1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0,  0,  1,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1, -1,  0,  0,  1, -1,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,
        0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       -1,  0,  0,  0, -1,  1, -1,  1,  0,  0,  1,  0,  0, -1, -1,  0,  0,
        0,  0,  1,  1,  0,  0,  1,  0,  0,  1,  0, -1,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0, -1,  0, -1,  0, -1,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0, -1,  0,  1,  0,
        0, -1,  0, -1,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0, -1,  1,  0,  0,  0, -1,  0, -1,  0,  0,  0,  0,  0,  0, -1,
        0,  0,  0,  0, -1,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  1,  0,
        0,  0, -1, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,
        0,  0,  0, -1,  1,  0,  0, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  1,  0,  0, -1,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  1,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0, -1, -1,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  1,  0,  0,  0,  0,  0,  0,
       -1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0, -1,  0, -1,  0,  0,  0,  0,  0,  1,  0,  0,  0,
        0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  1,
        0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0, -1,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  1,  1,  0,
        0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0, -1,  0,  0,  0,  0,
        1,  0,  0,  0,  0,  1, -1,  0,  0, -1,  0,  0, -1, -1,  0,  0, -1,
        1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  1,
        0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  0,  0,  0,
       -1,  0,  0,  0,  0, -1,  0,  0,  0, -1,  0, -1,  0,  0,  0,  0,  1,
        0,  0,  0,  1,  0, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0, -1,  0,  1,
        0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  1,  1,  0,  0, -1,
        0,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0, -1, -1, -1,  0,  0,  0,  1,  0,  0,  0,  0,
       -1,  0,  0,  0,  0,  1,  1,  0, -1, -1,  0,  0,  0,  0,  0,  0,  1,
        1,  0,  0,  1,  0, -1,  0,  0,  0,  1,  0,  0, -1};


    // load weights, convert to wide type
    for (int i = 0; i < INPUT_SIZE / INTS_PER_W; i++) {
        #pragma HLS pipeline II=1
        W_TYPE reg_odd;
        reg_odd.range(31, 0) = row_template_odd[INTS_PER_W * i];
        reg_odd.range(63, 32) = row_template_odd[INTS_PER_W * i + 1];
        reg_odd.range(95, 64) = row_template_odd[INTS_PER_W * i + 2];
        reg_odd.range(127, 96) = row_template_odd[INTS_PER_W * i + 3];
        weights_transpose_local[i] = reg_odd;
    }
}

template<>
void init_weights<HIDDEN_SIZE1, INDEX_EVEN>(W_TYPE* weights_transpose_local) {
    // same as the host side, len = 1024
    D_TYPE row_template_even[HIDDEN_SIZE1] = 
      { 1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,
        1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0, -1, -1,  0, -1,
        0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  1,  0,  0,  0,  0,  0,
        0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  1,  0,  0,  0,  0,  1,  0, -1,  0,  0,  1,  0, -1,  0,  0,
       -1,  0,  0,  0,  1,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0, -1,
        0,  0,  0,  0, -1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0, -1,  0,  0,
        0,  0,  0, -1,  0, -1,  1,  1,  0,  0,  0, -1,  0,  0, -1,  0, -1,
        0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  1,  0,  0, -1,
        0,  0,  0,  0,  0, -1, -1,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  1,
        1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0,  0,  1,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1, -1,  0,  0,  1, -1,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,
        0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       -1,  0,  0,  0, -1,  1, -1,  1,  0,  0,  1,  0,  0, -1, -1,  0,  0,
        0,  0,  1,  1,  0,  0,  1,  0,  0,  1,  0, -1,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0, -1,  0, -1,  0, -1,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0, -1,  0,  1,  0,
        0, -1,  0, -1,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0, -1,  1,  0,  0,  0, -1,  0, -1,  0,  0,  0,  0,  0,  0, -1,
        0,  0,  0,  0, -1,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  1,  0,
        0,  0, -1, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,
        0,  0,  0, -1,  1,  0,  0, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  1,  0,  0, -1,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  1,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0, -1, -1,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  1,  0,  0,  0,  0,  0,  0,
       -1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0, -1,  0, -1,  0,  0,  0,  0,  0,  1,  0,  0,  0,
        0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  1,
        0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0, -1,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  1,  1,  0,
        0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0, -1,  0,  0,  0,  0,
        1,  0,  0,  0,  0,  1, -1,  0,  0, -1,  0,  0, -1, -1,  0,  0, -1,
        1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  1,
        0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  0,  0,  0,
       -1,  0,  0,  0,  0, -1,  0,  0,  0, -1,  0, -1,  0,  0,  0,  0,  1,
        0,  0,  0,  1,  0, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0, -1,  0,  1,
        0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  1,  1,  0,  0, -1,
        0,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0, -1, -1, -1,  0,  0,  0,  1,  0,  0,  0,  0,
       -1,  0,  0,  0,  0,  1,  1,  0, -1, -1,  0,  0,  0,  0,  0,  0,  1,
        1,  0,  0,  1,  0, -1,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,
        1,  0,  0,  0, -1,  0,  0,  0,  0,  1,  0,  1,  0, -1,  0,  0, -1,
        0,  0,  1,  0,  0,  0,  0,  0, -1, -1,  0,  1,  0,  0, -1,  1,  0,
        0,  0, -1,  0, -1,  0,  0,  0,  1,  1,  0,  0,  0,  1,  0, -1,  1,
        0,  0,  0,  1,  0,  0, -1,  1,  0,  0,  0,  0, -1,  0,  1,  0,  1,
        0,  0,  0,  1,  1,  0,  0,  0,  0,  0,  1,  0,  0,  0,  1,  0, -1,
        0,  0,  0,  0,  1, -1,  0,  0,  1,  1,  0,  0,  1,  0, -1, -1,  0,
       -1,  0,  0,  0,  1,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  1,  0,  0,  0,  1,  0,  0,  0,  0,  1,  0, -1,  0,  0,  0, -1,
        0,  1,  0,  0};

    // for the index to be even
    for (int i = 0; i < HIDDEN_SIZE1 / INTS_PER_W; i++) {
        #pragma HLS pipeline II=1
        W_TYPE reg_even;
        reg_even.range(31, 0) = row_template_even[INTS_PER_W * i];
        reg_even.range(63, 32) = row_template_even[INTS_PER_W * i + 1];
        reg_even.range(95, 64) = row_template_even[INTS_PER_W * i + 2];
        reg_even.range(127, 96) = row_template_even[INTS_PER_W * i + 3];

        weights_transpose_local[i] = reg_even;
        //std::cout << "weights is " << weights_transpose_local[i] << std::endl;

    }
}

template<>
void init_weights<HIDDEN_SIZE1, INDEX_ODD>(W_TYPE* weights_transpose_local) {
    // same as the host side, len = 1024

    D_TYPE row_template_odd[HIDDEN_SIZE1] = 
      { 0,  0,  0,  0,  0,  0,  0, -1,  0,  1,  0,  0, -1,  0,  0,  0,  0,
        1,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       -1,  0,  0,  0,  0,  0,  0,  0, -1,  0, -1,  0,  0, -1,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0, -1, -1,  0,  0,  0,  0, -1,  0,  0,  0,
        0,  0,  1,  0,  0,  0,  0,  0,  0,  0, -1,  1,  0,  0,  0,  0,  1,
        0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  1,  0, -1, -1,  0, -1,  0,
       -1,  1,  0,  0,  0,  0, -1,  0,  0, -1,  0,  1,  0,  0, -1,  1, -1,
        0,  0,  1,  0,  0,  0,  0,  0, -1,  0, -1,  0,  0,  1, -1,  0,  0,
        0,  0,  0,  0,  1,  0,  1, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0, -1,  0,  1,  0,  0,  1, -1,  0,  0,  1,  1,  1,
        0,  0,  0,  0,  0,  1,  0,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,
        1,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  0,  1,  0, -1,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1, -1,  1,  0,  0, -1,  0,
       -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,
        0,  0,  0,  0,  1,  0,  0,  0,  0,  0, -1,  1,  0,  0,  0,  0,  0,
       -1, -1,  0,  0, -1,  0,  0,  0,  0,  0,  0,  0,  1, -1,  0,  0,  0,
        0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  1,  0,  0,  0,  1,  0,  0,
        0,  0,  0, -1,  0, -1,  0,  0,  0,  0,  1, -1,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  1,  0,  0,  0,  1,  0, -1,  0,  0,  1,  1,  0,  0,  0,  0,
        0,  1,  0,  0,  0,  0,  0,  0,  1,  0,  1,  0, -1,  1,  0,  1, -1,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  1,  0,  0,  0,  1,  0,
        1,  0,  0,  0,  0,  1,  0,  0, -1,  0,  0,  0,  1,  0,  0,  0,  0,
        0,  0,  1,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0, -1,  0,  0,  0,
        1,  0,  0,  0,  0,  0,  0,  0, -1,  0, -1,  0,  0,  0,  0,  0,  0,
       -1,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,
        0,  0,  0,  0,  1, -1,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  0,
        0,  0,  0, -1,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0, -1,  0,  0, -1,
        0,  0,  0,  0, -1,  0, -1,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,
        1,  0,  0,  0, -1,  0,  0,  0,  0, -1, -1,  0,  1,  1,  0,  0, -1,
        0,  0,  0,  1,  0,  0,  0,  0, -1,  0, -1,  0,  0,  0,  0,  0,  1,
        0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  0, -1,  1, -1,  0,  0,
        0,  0,  0,  0,  0,  1,  1,  0, -1, -1,  0,  0,  0,  0, -1,  1,  0,
        0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0, -1,  1,  0, -1,  0,  0,
        0, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,
        0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  1,  0, -1, -1,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  0,  0,  1,  0,
        0,  0,  0,  0,  0,  0, -1,  0,  0,  0, -1,  0,  0,  0, -1,  0,  0,
        1,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,
        0, -1,  0,  0,  0, -1, -1,  0,  0, -1,  0,  0,  0,  1,  0,  1,  0,
        0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,
        0,  0,  1,  0,  0,  0,  1,  0,  0,  1, -1, -1,  0,  0, -1,  0,  1,
        0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  1,
        0,  0,  0,  0,  0,  0,  0,  0,  0, -1, -1,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  1, -1,  0,  0,  0,  1, -1,  0,  1,  0,  1,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0, -1,  0,  0, -1,  0,  0, -1,  0,  0,  0,  0,
        1,  0,  1,  0, -1,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,
        1,  0,  0,  1,  1, -1,  0,  1,  0,  0,  0,  0,  0,  0, -1,  0,  0,
        0,  1,  0,  0, -1,  0,  1,  0, -1,  0,  0,  0,  0,  0,  0,  0,  0,
        0, -1,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0, -1,  1,  0,  1,  0,
        0,  0,  0,  1,  0,  1,  0,  0,  0, -1,  1,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0, -1,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        1,  0,  0,  0,  1,  0,  0,  0,  0,  0, -1,  0,  1,  0,  0,  0,  1,
        0,  0,  1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,
        0,  1, -1, -1,  0,  1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  1,  0,  0,  0,
        0,  0,  0,  0};

    // load weights, convert to wide type
    for (int i = 0; i < HIDDEN_SIZE1 / INTS_PER_W; i++) {
        #pragma HLS pipeline II=1
        W_TYPE reg_odd;
        reg_odd.range(31, 0) = row_template_odd[INTS_PER_W * i];
        reg_odd.range(63, 32) = row_template_odd[INTS_PER_W * i + 1];
        reg_odd.range(95, 64) = row_template_odd[INTS_PER_W * i + 2];
        reg_odd.range(127, 96) = row_template_odd[INTS_PER_W * i + 3];

        weights_transpose_local[i] = reg_odd;
    }
}


template<const int FEATURE_SIZE>
void replicate_feature_512PEs_320PE(
    hls::stream<ap_uint<512> >& s_feature_in, 
    hls::stream<W_TYPE>& s_feature_PE0_0, hls::stream<W_TYPE>& s_feature_PE0_1,
    hls::stream<W_TYPE>& s_feature_PE0_2, hls::stream<W_TYPE>& s_feature_PE0_3,
    hls::stream<W_TYPE>& s_feature_PE1_0, hls::stream<W_TYPE>& s_feature_PE1_1,
    hls::stream<W_TYPE>& s_feature_PE1_2, hls::stream<W_TYPE>& s_feature_PE1_3,
    hls::stream<W_TYPE>& s_feature_PE2_0, hls::stream<W_TYPE>& s_feature_PE2_1,
    hls::stream<W_TYPE>& s_feature_PE2_2, hls::stream<W_TYPE>& s_feature_PE2_3,
    hls::stream<W_TYPE>& s_feature_PE3_0, hls::stream<W_TYPE>& s_feature_PE3_1,
    hls::stream<W_TYPE>& s_feature_PE3_2, hls::stream<W_TYPE>& s_feature_PE3_3,
    hls::stream<W_TYPE>& s_feature_PE4_0, hls::stream<W_TYPE>& s_feature_PE4_1,
    hls::stream<W_TYPE>& s_feature_PE4_2, hls::stream<W_TYPE>& s_feature_PE4_3,
    hls::stream<W_TYPE>& s_feature_PE5_0, hls::stream<W_TYPE>& s_feature_PE5_1,
    hls::stream<W_TYPE>& s_feature_PE5_2, hls::stream<W_TYPE>& s_feature_PE5_3,
    hls::stream<W_TYPE>& s_feature_PE6_0, hls::stream<W_TYPE>& s_feature_PE6_1,
    hls::stream<W_TYPE>& s_feature_PE6_2, hls::stream<W_TYPE>& s_feature_PE6_3,
    hls::stream<W_TYPE>& s_feature_PE7_0, hls::stream<W_TYPE>& s_feature_PE7_1,
    hls::stream<W_TYPE>& s_feature_PE7_2, hls::stream<W_TYPE>& s_feature_PE7_3,
    hls::stream<W_TYPE>& s_feature_PE8_0, hls::stream<W_TYPE>& s_feature_PE8_1,
    hls::stream<W_TYPE>& s_feature_PE8_2, hls::stream<W_TYPE>& s_feature_PE8_3,
    hls::stream<W_TYPE>& s_feature_PE9_0, hls::stream<W_TYPE>& s_feature_PE9_1,
    hls::stream<W_TYPE>& s_feature_PE9_2, hls::stream<W_TYPE>& s_feature_PE9_3,
    hls::stream<W_TYPE>& s_feature_PE10_0, hls::stream<W_TYPE>& s_feature_PE10_1,
    hls::stream<W_TYPE>& s_feature_PE10_2, hls::stream<W_TYPE>& s_feature_PE10_3,
    hls::stream<W_TYPE>& s_feature_PE11_0, hls::stream<W_TYPE>& s_feature_PE11_1,
    hls::stream<W_TYPE>& s_feature_PE11_2, hls::stream<W_TYPE>& s_feature_PE11_3,
    hls::stream<W_TYPE>& s_feature_PE12_0, hls::stream<W_TYPE>& s_feature_PE12_1,
    hls::stream<W_TYPE>& s_feature_PE12_2, hls::stream<W_TYPE>& s_feature_PE12_3,
    hls::stream<W_TYPE>& s_feature_PE13_0, hls::stream<W_TYPE>& s_feature_PE13_1,
    hls::stream<W_TYPE>& s_feature_PE13_2, hls::stream<W_TYPE>& s_feature_PE13_3,
    hls::stream<W_TYPE>& s_feature_PE14_0, hls::stream<W_TYPE>& s_feature_PE14_1,
    hls::stream<W_TYPE>& s_feature_PE14_2, hls::stream<W_TYPE>& s_feature_PE14_3,
    hls::stream<W_TYPE>& s_feature_PE15_0, hls::stream<W_TYPE>& s_feature_PE15_1,
    hls::stream<W_TYPE>& s_feature_PE15_2, hls::stream<W_TYPE>& s_feature_PE15_3,
    hls::stream<W_TYPE>& s_feature_PE16_0, hls::stream<W_TYPE>& s_feature_PE16_1,
    hls::stream<W_TYPE>& s_feature_PE16_2, hls::stream<W_TYPE>& s_feature_PE16_3,
    hls::stream<W_TYPE>& s_feature_PE17_0, hls::stream<W_TYPE>& s_feature_PE17_1,
    hls::stream<W_TYPE>& s_feature_PE17_2, hls::stream<W_TYPE>& s_feature_PE17_3,
    hls::stream<W_TYPE>& s_feature_PE18_0, hls::stream<W_TYPE>& s_feature_PE18_1,
    hls::stream<W_TYPE>& s_feature_PE18_2, hls::stream<W_TYPE>& s_feature_PE18_3,
    hls::stream<W_TYPE>& s_feature_PE19_0, hls::stream<W_TYPE>& s_feature_PE19_1,
    hls::stream<W_TYPE>& s_feature_PE19_2, hls::stream<W_TYPE>& s_feature_PE19_3,
    hls::stream<W_TYPE>& s_feature_PE20_0, hls::stream<W_TYPE>& s_feature_PE20_1,
    hls::stream<W_TYPE>& s_feature_PE20_2, hls::stream<W_TYPE>& s_feature_PE20_3,
    hls::stream<W_TYPE>& s_feature_PE21_0, hls::stream<W_TYPE>& s_feature_PE21_1,
    hls::stream<W_TYPE>& s_feature_PE21_2, hls::stream<W_TYPE>& s_feature_PE21_3,
    hls::stream<W_TYPE>& s_feature_PE22_0, hls::stream<W_TYPE>& s_feature_PE22_1,
    hls::stream<W_TYPE>& s_feature_PE22_2, hls::stream<W_TYPE>& s_feature_PE22_3,
    hls::stream<W_TYPE>& s_feature_PE23_0, hls::stream<W_TYPE>& s_feature_PE23_1,
    hls::stream<W_TYPE>& s_feature_PE23_2, hls::stream<W_TYPE>& s_feature_PE23_3,
    hls::stream<W_TYPE>& s_feature_PE24_0, hls::stream<W_TYPE>& s_feature_PE24_1,
    hls::stream<W_TYPE>& s_feature_PE24_2, hls::stream<W_TYPE>& s_feature_PE24_3,
    hls::stream<W_TYPE>& s_feature_PE25_0, hls::stream<W_TYPE>& s_feature_PE25_1,
    hls::stream<W_TYPE>& s_feature_PE25_2, hls::stream<W_TYPE>& s_feature_PE25_3,
    hls::stream<W_TYPE>& s_feature_PE26_0, hls::stream<W_TYPE>& s_feature_PE26_1,
    hls::stream<W_TYPE>& s_feature_PE26_2, hls::stream<W_TYPE>& s_feature_PE26_3,
    hls::stream<W_TYPE>& s_feature_PE27_0, hls::stream<W_TYPE>& s_feature_PE27_1,
    hls::stream<W_TYPE>& s_feature_PE27_2, hls::stream<W_TYPE>& s_feature_PE27_3,
    hls::stream<W_TYPE>& s_feature_PE28_0, hls::stream<W_TYPE>& s_feature_PE28_1,
    hls::stream<W_TYPE>& s_feature_PE28_2, hls::stream<W_TYPE>& s_feature_PE28_3,
    hls::stream<W_TYPE>& s_feature_PE29_0, hls::stream<W_TYPE>& s_feature_PE29_1,
    hls::stream<W_TYPE>& s_feature_PE29_2, hls::stream<W_TYPE>& s_feature_PE29_3,
    hls::stream<W_TYPE>& s_feature_PE30_0, hls::stream<W_TYPE>& s_feature_PE30_1,
    hls::stream<W_TYPE>& s_feature_PE30_2, hls::stream<W_TYPE>& s_feature_PE30_3,
    hls::stream<W_TYPE>& s_feature_PE31_0, hls::stream<W_TYPE>& s_feature_PE31_1,
    hls::stream<W_TYPE>& s_feature_PE31_2, hls::stream<W_TYPE>& s_feature_PE31_3,
    hls::stream<W_TYPE>& s_feature_PE32_0, hls::stream<W_TYPE>& s_feature_PE32_1,
    hls::stream<W_TYPE>& s_feature_PE32_2, hls::stream<W_TYPE>& s_feature_PE32_3,
    hls::stream<W_TYPE>& s_feature_PE33_0, hls::stream<W_TYPE>& s_feature_PE33_1,
    hls::stream<W_TYPE>& s_feature_PE33_2, hls::stream<W_TYPE>& s_feature_PE33_3,
    hls::stream<W_TYPE>& s_feature_PE34_0, hls::stream<W_TYPE>& s_feature_PE34_1,
    hls::stream<W_TYPE>& s_feature_PE34_2, hls::stream<W_TYPE>& s_feature_PE34_3,
    hls::stream<W_TYPE>& s_feature_PE35_0, hls::stream<W_TYPE>& s_feature_PE35_1,
    hls::stream<W_TYPE>& s_feature_PE35_2, hls::stream<W_TYPE>& s_feature_PE35_3,
    hls::stream<W_TYPE>& s_feature_PE36_0, hls::stream<W_TYPE>& s_feature_PE36_1,
    hls::stream<W_TYPE>& s_feature_PE36_2, hls::stream<W_TYPE>& s_feature_PE36_3,
    hls::stream<W_TYPE>& s_feature_PE37_0, hls::stream<W_TYPE>& s_feature_PE37_1,
    hls::stream<W_TYPE>& s_feature_PE37_2, hls::stream<W_TYPE>& s_feature_PE37_3,
    hls::stream<W_TYPE>& s_feature_PE38_0, hls::stream<W_TYPE>& s_feature_PE38_1,
    hls::stream<W_TYPE>& s_feature_PE38_2, hls::stream<W_TYPE>& s_feature_PE38_3,
    hls::stream<W_TYPE>& s_feature_PE39_0, hls::stream<W_TYPE>& s_feature_PE39_1,
    hls::stream<W_TYPE>& s_feature_PE39_2, hls::stream<W_TYPE>& s_feature_PE39_3,
    hls::stream<W_TYPE>& s_feature_PE40_0, hls::stream<W_TYPE>& s_feature_PE40_1,
    hls::stream<W_TYPE>& s_feature_PE40_2, hls::stream<W_TYPE>& s_feature_PE40_3,
    hls::stream<W_TYPE>& s_feature_PE41_0, hls::stream<W_TYPE>& s_feature_PE41_1,
    hls::stream<W_TYPE>& s_feature_PE41_2, hls::stream<W_TYPE>& s_feature_PE41_3,
    hls::stream<W_TYPE>& s_feature_PE42_0, hls::stream<W_TYPE>& s_feature_PE42_1,
    hls::stream<W_TYPE>& s_feature_PE42_2, hls::stream<W_TYPE>& s_feature_PE42_3,
    hls::stream<W_TYPE>& s_feature_PE43_0, hls::stream<W_TYPE>& s_feature_PE43_1,
    hls::stream<W_TYPE>& s_feature_PE43_2, hls::stream<W_TYPE>& s_feature_PE43_3,
    hls::stream<W_TYPE>& s_feature_PE44_0, hls::stream<W_TYPE>& s_feature_PE44_1,
    hls::stream<W_TYPE>& s_feature_PE44_2, hls::stream<W_TYPE>& s_feature_PE44_3,
    hls::stream<W_TYPE>& s_feature_PE45_0, hls::stream<W_TYPE>& s_feature_PE45_1,
    hls::stream<W_TYPE>& s_feature_PE45_2, hls::stream<W_TYPE>& s_feature_PE45_3,
    hls::stream<W_TYPE>& s_feature_PE46_0, hls::stream<W_TYPE>& s_feature_PE46_1,
    hls::stream<W_TYPE>& s_feature_PE46_2, hls::stream<W_TYPE>& s_feature_PE46_3,
    hls::stream<W_TYPE>& s_feature_PE47_0, hls::stream<W_TYPE>& s_feature_PE47_1,
    hls::stream<W_TYPE>& s_feature_PE47_2, hls::stream<W_TYPE>& s_feature_PE47_3,
    hls::stream<W_TYPE>& s_feature_PE48_0, hls::stream<W_TYPE>& s_feature_PE48_1,
    hls::stream<W_TYPE>& s_feature_PE48_2, hls::stream<W_TYPE>& s_feature_PE48_3,
    hls::stream<W_TYPE>& s_feature_PE49_0, hls::stream<W_TYPE>& s_feature_PE49_1,
    hls::stream<W_TYPE>& s_feature_PE49_2, hls::stream<W_TYPE>& s_feature_PE49_3,
    hls::stream<W_TYPE>& s_feature_PE50_0, hls::stream<W_TYPE>& s_feature_PE50_1,
    hls::stream<W_TYPE>& s_feature_PE50_2, hls::stream<W_TYPE>& s_feature_PE50_3,
    hls::stream<W_TYPE>& s_feature_PE51_0, hls::stream<W_TYPE>& s_feature_PE51_1,
    hls::stream<W_TYPE>& s_feature_PE51_2, hls::stream<W_TYPE>& s_feature_PE51_3,
    hls::stream<W_TYPE>& s_feature_PE52_0, hls::stream<W_TYPE>& s_feature_PE52_1,
    hls::stream<W_TYPE>& s_feature_PE52_2, hls::stream<W_TYPE>& s_feature_PE52_3,
    hls::stream<W_TYPE>& s_feature_PE53_0, hls::stream<W_TYPE>& s_feature_PE53_1,
    hls::stream<W_TYPE>& s_feature_PE53_2, hls::stream<W_TYPE>& s_feature_PE53_3,
    hls::stream<W_TYPE>& s_feature_PE54_0, hls::stream<W_TYPE>& s_feature_PE54_1,
    hls::stream<W_TYPE>& s_feature_PE54_2, hls::stream<W_TYPE>& s_feature_PE54_3,
    hls::stream<W_TYPE>& s_feature_PE55_0, hls::stream<W_TYPE>& s_feature_PE55_1,
    hls::stream<W_TYPE>& s_feature_PE55_2, hls::stream<W_TYPE>& s_feature_PE55_3,
    hls::stream<W_TYPE>& s_feature_PE56_0, hls::stream<W_TYPE>& s_feature_PE56_1,
    hls::stream<W_TYPE>& s_feature_PE56_2, hls::stream<W_TYPE>& s_feature_PE56_3,
    hls::stream<W_TYPE>& s_feature_PE57_0, hls::stream<W_TYPE>& s_feature_PE57_1,
    hls::stream<W_TYPE>& s_feature_PE57_2, hls::stream<W_TYPE>& s_feature_PE57_3,
    hls::stream<W_TYPE>& s_feature_PE58_0, hls::stream<W_TYPE>& s_feature_PE58_1,
    hls::stream<W_TYPE>& s_feature_PE58_2, hls::stream<W_TYPE>& s_feature_PE58_3,
    hls::stream<W_TYPE>& s_feature_PE59_0, hls::stream<W_TYPE>& s_feature_PE59_1,
    hls::stream<W_TYPE>& s_feature_PE59_2, hls::stream<W_TYPE>& s_feature_PE59_3,
    hls::stream<W_TYPE>& s_feature_PE60_0, hls::stream<W_TYPE>& s_feature_PE60_1,
    hls::stream<W_TYPE>& s_feature_PE60_2, hls::stream<W_TYPE>& s_feature_PE60_3,
    hls::stream<W_TYPE>& s_feature_PE61_0, hls::stream<W_TYPE>& s_feature_PE61_1,
    hls::stream<W_TYPE>& s_feature_PE61_2, hls::stream<W_TYPE>& s_feature_PE61_3,
    hls::stream<W_TYPE>& s_feature_PE62_0, hls::stream<W_TYPE>& s_feature_PE62_1,
    hls::stream<W_TYPE>& s_feature_PE62_2, hls::stream<W_TYPE>& s_feature_PE62_3,
    hls::stream<W_TYPE>& s_feature_PE63_0, hls::stream<W_TYPE>& s_feature_PE63_1,
    hls::stream<W_TYPE>& s_feature_PE63_2, hls::stream<W_TYPE>& s_feature_PE63_3,
    hls::stream<W_TYPE>& s_feature_PE64_0, hls::stream<W_TYPE>& s_feature_PE64_1,
    hls::stream<W_TYPE>& s_feature_PE64_2, hls::stream<W_TYPE>& s_feature_PE64_3,
    hls::stream<W_TYPE>& s_feature_PE65_0, hls::stream<W_TYPE>& s_feature_PE65_1,
    hls::stream<W_TYPE>& s_feature_PE65_2, hls::stream<W_TYPE>& s_feature_PE65_3,
    hls::stream<W_TYPE>& s_feature_PE66_0, hls::stream<W_TYPE>& s_feature_PE66_1,
    hls::stream<W_TYPE>& s_feature_PE66_2, hls::stream<W_TYPE>& s_feature_PE66_3,
    hls::stream<W_TYPE>& s_feature_PE67_0, hls::stream<W_TYPE>& s_feature_PE67_1,
    hls::stream<W_TYPE>& s_feature_PE67_2, hls::stream<W_TYPE>& s_feature_PE67_3,
    hls::stream<W_TYPE>& s_feature_PE68_0, hls::stream<W_TYPE>& s_feature_PE68_1,
    hls::stream<W_TYPE>& s_feature_PE68_2, hls::stream<W_TYPE>& s_feature_PE68_3,
    hls::stream<W_TYPE>& s_feature_PE69_0, hls::stream<W_TYPE>& s_feature_PE69_1,
    hls::stream<W_TYPE>& s_feature_PE69_2, hls::stream<W_TYPE>& s_feature_PE69_3,
    hls::stream<W_TYPE>& s_feature_PE70_0, hls::stream<W_TYPE>& s_feature_PE70_1,
    hls::stream<W_TYPE>& s_feature_PE70_2, hls::stream<W_TYPE>& s_feature_PE70_3,
    hls::stream<W_TYPE>& s_feature_PE71_0, hls::stream<W_TYPE>& s_feature_PE71_1,
    hls::stream<W_TYPE>& s_feature_PE71_2, hls::stream<W_TYPE>& s_feature_PE71_3,
    hls::stream<W_TYPE>& s_feature_PE72_0, hls::stream<W_TYPE>& s_feature_PE72_1,
    hls::stream<W_TYPE>& s_feature_PE72_2, hls::stream<W_TYPE>& s_feature_PE72_3,
    hls::stream<W_TYPE>& s_feature_PE73_0, hls::stream<W_TYPE>& s_feature_PE73_1,
    hls::stream<W_TYPE>& s_feature_PE73_2, hls::stream<W_TYPE>& s_feature_PE73_3,
    hls::stream<W_TYPE>& s_feature_PE74_0, hls::stream<W_TYPE>& s_feature_PE74_1,
    hls::stream<W_TYPE>& s_feature_PE74_2, hls::stream<W_TYPE>& s_feature_PE74_3,
    hls::stream<W_TYPE>& s_feature_PE75_0, hls::stream<W_TYPE>& s_feature_PE75_1,
    hls::stream<W_TYPE>& s_feature_PE75_2, hls::stream<W_TYPE>& s_feature_PE75_3,
    hls::stream<W_TYPE>& s_feature_PE76_0, hls::stream<W_TYPE>& s_feature_PE76_1,
    hls::stream<W_TYPE>& s_feature_PE76_2, hls::stream<W_TYPE>& s_feature_PE76_3,
    hls::stream<W_TYPE>& s_feature_PE77_0, hls::stream<W_TYPE>& s_feature_PE77_1,
    hls::stream<W_TYPE>& s_feature_PE77_2, hls::stream<W_TYPE>& s_feature_PE77_3,
    hls::stream<W_TYPE>& s_feature_PE78_0, hls::stream<W_TYPE>& s_feature_PE78_1,
    hls::stream<W_TYPE>& s_feature_PE78_2, hls::stream<W_TYPE>& s_feature_PE78_3,
    hls::stream<W_TYPE>& s_feature_PE79_0, hls::stream<W_TYPE>& s_feature_PE79_1,
    hls::stream<W_TYPE>& s_feature_PE79_2, hls::stream<W_TYPE>& s_feature_PE79_3,
    hls::stream<W_TYPE>& s_feature_PE80_0, hls::stream<W_TYPE>& s_feature_PE80_1,
    hls::stream<W_TYPE>& s_feature_PE80_2, hls::stream<W_TYPE>& s_feature_PE80_3,
    hls::stream<W_TYPE>& s_feature_PE81_0, hls::stream<W_TYPE>& s_feature_PE81_1,
    hls::stream<W_TYPE>& s_feature_PE81_2, hls::stream<W_TYPE>& s_feature_PE81_3,
    hls::stream<W_TYPE>& s_feature_PE82_0, hls::stream<W_TYPE>& s_feature_PE82_1,
    hls::stream<W_TYPE>& s_feature_PE82_2, hls::stream<W_TYPE>& s_feature_PE82_3,
    hls::stream<W_TYPE>& s_feature_PE83_0, hls::stream<W_TYPE>& s_feature_PE83_1,
    hls::stream<W_TYPE>& s_feature_PE83_2, hls::stream<W_TYPE>& s_feature_PE83_3,
    hls::stream<W_TYPE>& s_feature_PE84_0, hls::stream<W_TYPE>& s_feature_PE84_1,
    hls::stream<W_TYPE>& s_feature_PE84_2, hls::stream<W_TYPE>& s_feature_PE84_3,
    hls::stream<W_TYPE>& s_feature_PE85_0, hls::stream<W_TYPE>& s_feature_PE85_1,
    hls::stream<W_TYPE>& s_feature_PE85_2, hls::stream<W_TYPE>& s_feature_PE85_3,
    hls::stream<W_TYPE>& s_feature_PE86_0, hls::stream<W_TYPE>& s_feature_PE86_1,
    hls::stream<W_TYPE>& s_feature_PE86_2, hls::stream<W_TYPE>& s_feature_PE86_3,
    hls::stream<W_TYPE>& s_feature_PE87_0, hls::stream<W_TYPE>& s_feature_PE87_1,
    hls::stream<W_TYPE>& s_feature_PE87_2, hls::stream<W_TYPE>& s_feature_PE87_3,
    hls::stream<W_TYPE>& s_feature_PE88_0, hls::stream<W_TYPE>& s_feature_PE88_1,
    hls::stream<W_TYPE>& s_feature_PE88_2, hls::stream<W_TYPE>& s_feature_PE88_3,
    hls::stream<W_TYPE>& s_feature_PE89_0, hls::stream<W_TYPE>& s_feature_PE89_1,
    hls::stream<W_TYPE>& s_feature_PE89_2, hls::stream<W_TYPE>& s_feature_PE89_3,
    hls::stream<W_TYPE>& s_feature_PE90_0, hls::stream<W_TYPE>& s_feature_PE90_1,
    hls::stream<W_TYPE>& s_feature_PE90_2, hls::stream<W_TYPE>& s_feature_PE90_3,
    hls::stream<W_TYPE>& s_feature_PE91_0, hls::stream<W_TYPE>& s_feature_PE91_1,
    hls::stream<W_TYPE>& s_feature_PE91_2, hls::stream<W_TYPE>& s_feature_PE91_3,
    hls::stream<W_TYPE>& s_feature_PE92_0, hls::stream<W_TYPE>& s_feature_PE92_1,
    hls::stream<W_TYPE>& s_feature_PE92_2, hls::stream<W_TYPE>& s_feature_PE92_3,
    hls::stream<W_TYPE>& s_feature_PE93_0, hls::stream<W_TYPE>& s_feature_PE93_1,
    hls::stream<W_TYPE>& s_feature_PE93_2, hls::stream<W_TYPE>& s_feature_PE93_3,
    hls::stream<W_TYPE>& s_feature_PE94_0, hls::stream<W_TYPE>& s_feature_PE94_1,
    hls::stream<W_TYPE>& s_feature_PE94_2, hls::stream<W_TYPE>& s_feature_PE94_3,
    hls::stream<W_TYPE>& s_feature_PE95_0, hls::stream<W_TYPE>& s_feature_PE95_1,
    hls::stream<W_TYPE>& s_feature_PE95_2, hls::stream<W_TYPE>& s_feature_PE95_3,
    hls::stream<W_TYPE>& s_feature_PE96_0, hls::stream<W_TYPE>& s_feature_PE96_1,
    hls::stream<W_TYPE>& s_feature_PE96_2, hls::stream<W_TYPE>& s_feature_PE96_3,
    hls::stream<W_TYPE>& s_feature_PE97_0, hls::stream<W_TYPE>& s_feature_PE97_1,
    hls::stream<W_TYPE>& s_feature_PE97_2, hls::stream<W_TYPE>& s_feature_PE97_3,
    hls::stream<W_TYPE>& s_feature_PE98_0, hls::stream<W_TYPE>& s_feature_PE98_1,
    hls::stream<W_TYPE>& s_feature_PE98_2, hls::stream<W_TYPE>& s_feature_PE98_3,
    hls::stream<W_TYPE>& s_feature_PE99_0, hls::stream<W_TYPE>& s_feature_PE99_1,
    hls::stream<W_TYPE>& s_feature_PE99_2, hls::stream<W_TYPE>& s_feature_PE99_3,
    hls::stream<W_TYPE>& s_feature_PE100_0, hls::stream<W_TYPE>& s_feature_PE100_1,
    hls::stream<W_TYPE>& s_feature_PE100_2, hls::stream<W_TYPE>& s_feature_PE100_3,
    hls::stream<W_TYPE>& s_feature_PE101_0, hls::stream<W_TYPE>& s_feature_PE101_1,
    hls::stream<W_TYPE>& s_feature_PE101_2, hls::stream<W_TYPE>& s_feature_PE101_3,
    hls::stream<W_TYPE>& s_feature_PE102_0, hls::stream<W_TYPE>& s_feature_PE102_1,
    hls::stream<W_TYPE>& s_feature_PE102_2, hls::stream<W_TYPE>& s_feature_PE102_3,
    hls::stream<W_TYPE>& s_feature_PE103_0, hls::stream<W_TYPE>& s_feature_PE103_1,
    hls::stream<W_TYPE>& s_feature_PE103_2, hls::stream<W_TYPE>& s_feature_PE103_3,
    hls::stream<W_TYPE>& s_feature_PE104_0, hls::stream<W_TYPE>& s_feature_PE104_1,
    hls::stream<W_TYPE>& s_feature_PE104_2, hls::stream<W_TYPE>& s_feature_PE104_3,
    hls::stream<W_TYPE>& s_feature_PE105_0, hls::stream<W_TYPE>& s_feature_PE105_1,
    hls::stream<W_TYPE>& s_feature_PE105_2, hls::stream<W_TYPE>& s_feature_PE105_3,
    hls::stream<W_TYPE>& s_feature_PE106_0, hls::stream<W_TYPE>& s_feature_PE106_1,
    hls::stream<W_TYPE>& s_feature_PE106_2, hls::stream<W_TYPE>& s_feature_PE106_3,
    hls::stream<W_TYPE>& s_feature_PE107_0, hls::stream<W_TYPE>& s_feature_PE107_1,
    hls::stream<W_TYPE>& s_feature_PE107_2, hls::stream<W_TYPE>& s_feature_PE107_3,
    hls::stream<W_TYPE>& s_feature_PE108_0, hls::stream<W_TYPE>& s_feature_PE108_1,
    hls::stream<W_TYPE>& s_feature_PE108_2, hls::stream<W_TYPE>& s_feature_PE108_3,
    hls::stream<W_TYPE>& s_feature_PE109_0, hls::stream<W_TYPE>& s_feature_PE109_1,
    hls::stream<W_TYPE>& s_feature_PE109_2, hls::stream<W_TYPE>& s_feature_PE109_3,
    hls::stream<W_TYPE>& s_feature_PE110_0, hls::stream<W_TYPE>& s_feature_PE110_1,
    hls::stream<W_TYPE>& s_feature_PE110_2, hls::stream<W_TYPE>& s_feature_PE110_3,
    hls::stream<W_TYPE>& s_feature_PE111_0, hls::stream<W_TYPE>& s_feature_PE111_1,
    hls::stream<W_TYPE>& s_feature_PE111_2, hls::stream<W_TYPE>& s_feature_PE111_3,
    hls::stream<W_TYPE>& s_feature_PE112_0, hls::stream<W_TYPE>& s_feature_PE112_1,
    hls::stream<W_TYPE>& s_feature_PE112_2, hls::stream<W_TYPE>& s_feature_PE112_3,
    hls::stream<W_TYPE>& s_feature_PE113_0, hls::stream<W_TYPE>& s_feature_PE113_1,
    hls::stream<W_TYPE>& s_feature_PE113_2, hls::stream<W_TYPE>& s_feature_PE113_3,
    hls::stream<W_TYPE>& s_feature_PE114_0, hls::stream<W_TYPE>& s_feature_PE114_1,
    hls::stream<W_TYPE>& s_feature_PE114_2, hls::stream<W_TYPE>& s_feature_PE114_3,
    hls::stream<W_TYPE>& s_feature_PE115_0, hls::stream<W_TYPE>& s_feature_PE115_1,
    hls::stream<W_TYPE>& s_feature_PE115_2, hls::stream<W_TYPE>& s_feature_PE115_3,
    hls::stream<W_TYPE>& s_feature_PE116_0, hls::stream<W_TYPE>& s_feature_PE116_1,
    hls::stream<W_TYPE>& s_feature_PE116_2, hls::stream<W_TYPE>& s_feature_PE116_3,
    hls::stream<W_TYPE>& s_feature_PE117_0, hls::stream<W_TYPE>& s_feature_PE117_1,
    hls::stream<W_TYPE>& s_feature_PE117_2, hls::stream<W_TYPE>& s_feature_PE117_3,
    hls::stream<W_TYPE>& s_feature_PE118_0, hls::stream<W_TYPE>& s_feature_PE118_1,
    hls::stream<W_TYPE>& s_feature_PE118_2, hls::stream<W_TYPE>& s_feature_PE118_3,
    hls::stream<W_TYPE>& s_feature_PE119_0, hls::stream<W_TYPE>& s_feature_PE119_1,
    hls::stream<W_TYPE>& s_feature_PE119_2, hls::stream<W_TYPE>& s_feature_PE119_3,
    hls::stream<W_TYPE>& s_feature_PE120_0, hls::stream<W_TYPE>& s_feature_PE120_1,
    hls::stream<W_TYPE>& s_feature_PE120_2, hls::stream<W_TYPE>& s_feature_PE120_3,
    hls::stream<W_TYPE>& s_feature_PE121_0, hls::stream<W_TYPE>& s_feature_PE121_1,
    hls::stream<W_TYPE>& s_feature_PE121_2, hls::stream<W_TYPE>& s_feature_PE121_3,
    hls::stream<W_TYPE>& s_feature_PE122_0, hls::stream<W_TYPE>& s_feature_PE122_1,
    hls::stream<W_TYPE>& s_feature_PE122_2, hls::stream<W_TYPE>& s_feature_PE122_3,
    hls::stream<W_TYPE>& s_feature_PE123_0, hls::stream<W_TYPE>& s_feature_PE123_1,
    hls::stream<W_TYPE>& s_feature_PE123_2, hls::stream<W_TYPE>& s_feature_PE123_3,
    hls::stream<W_TYPE>& s_feature_PE124_0, hls::stream<W_TYPE>& s_feature_PE124_1,
    hls::stream<W_TYPE>& s_feature_PE124_2, hls::stream<W_TYPE>& s_feature_PE124_3,
    hls::stream<W_TYPE>& s_feature_PE125_0, hls::stream<W_TYPE>& s_feature_PE125_1,
    hls::stream<W_TYPE>& s_feature_PE125_2, hls::stream<W_TYPE>& s_feature_PE125_3,
    hls::stream<W_TYPE>& s_feature_PE126_0, hls::stream<W_TYPE>& s_feature_PE126_1,
    hls::stream<W_TYPE>& s_feature_PE126_2, hls::stream<W_TYPE>& s_feature_PE126_3,
    hls::stream<W_TYPE>& s_feature_PE127_0, hls::stream<W_TYPE>& s_feature_PE127_1,
    hls::stream<W_TYPE>& s_feature_PE127_2, hls::stream<W_TYPE>& s_feature_PE127_3,
    hls::stream<W_TYPE>& s_feature_PE128_0, hls::stream<W_TYPE>& s_feature_PE128_1,
    hls::stream<W_TYPE>& s_feature_PE128_2, hls::stream<W_TYPE>& s_feature_PE128_3,
    hls::stream<W_TYPE>& s_feature_PE129_0, hls::stream<W_TYPE>& s_feature_PE129_1,
    hls::stream<W_TYPE>& s_feature_PE129_2, hls::stream<W_TYPE>& s_feature_PE129_3,
    hls::stream<W_TYPE>& s_feature_PE130_0, hls::stream<W_TYPE>& s_feature_PE130_1,
    hls::stream<W_TYPE>& s_feature_PE130_2, hls::stream<W_TYPE>& s_feature_PE130_3,
    hls::stream<W_TYPE>& s_feature_PE131_0, hls::stream<W_TYPE>& s_feature_PE131_1,
    hls::stream<W_TYPE>& s_feature_PE131_2, hls::stream<W_TYPE>& s_feature_PE131_3,
    hls::stream<W_TYPE>& s_feature_PE132_0, hls::stream<W_TYPE>& s_feature_PE132_1,
    hls::stream<W_TYPE>& s_feature_PE132_2, hls::stream<W_TYPE>& s_feature_PE132_3,
    hls::stream<W_TYPE>& s_feature_PE133_0, hls::stream<W_TYPE>& s_feature_PE133_1,
    hls::stream<W_TYPE>& s_feature_PE133_2, hls::stream<W_TYPE>& s_feature_PE133_3,
    hls::stream<W_TYPE>& s_feature_PE134_0, hls::stream<W_TYPE>& s_feature_PE134_1,
    hls::stream<W_TYPE>& s_feature_PE134_2, hls::stream<W_TYPE>& s_feature_PE134_3,
    hls::stream<W_TYPE>& s_feature_PE135_0, hls::stream<W_TYPE>& s_feature_PE135_1,
    hls::stream<W_TYPE>& s_feature_PE135_2, hls::stream<W_TYPE>& s_feature_PE135_3,
    hls::stream<W_TYPE>& s_feature_PE136_0, hls::stream<W_TYPE>& s_feature_PE136_1,
    hls::stream<W_TYPE>& s_feature_PE136_2, hls::stream<W_TYPE>& s_feature_PE136_3,
    hls::stream<W_TYPE>& s_feature_PE137_0, hls::stream<W_TYPE>& s_feature_PE137_1,
    hls::stream<W_TYPE>& s_feature_PE137_2, hls::stream<W_TYPE>& s_feature_PE137_3,
    hls::stream<W_TYPE>& s_feature_PE138_0, hls::stream<W_TYPE>& s_feature_PE138_1,
    hls::stream<W_TYPE>& s_feature_PE138_2, hls::stream<W_TYPE>& s_feature_PE138_3,
    hls::stream<W_TYPE>& s_feature_PE139_0, hls::stream<W_TYPE>& s_feature_PE139_1,
    hls::stream<W_TYPE>& s_feature_PE139_2, hls::stream<W_TYPE>& s_feature_PE139_3,
    hls::stream<W_TYPE>& s_feature_PE140_0, hls::stream<W_TYPE>& s_feature_PE140_1,
    hls::stream<W_TYPE>& s_feature_PE140_2, hls::stream<W_TYPE>& s_feature_PE140_3,
    hls::stream<W_TYPE>& s_feature_PE141_0, hls::stream<W_TYPE>& s_feature_PE141_1,
    hls::stream<W_TYPE>& s_feature_PE141_2, hls::stream<W_TYPE>& s_feature_PE141_3,
    hls::stream<W_TYPE>& s_feature_PE142_0, hls::stream<W_TYPE>& s_feature_PE142_1,
    hls::stream<W_TYPE>& s_feature_PE142_2, hls::stream<W_TYPE>& s_feature_PE142_3,
    hls::stream<W_TYPE>& s_feature_PE143_0, hls::stream<W_TYPE>& s_feature_PE143_1,
    hls::stream<W_TYPE>& s_feature_PE143_2, hls::stream<W_TYPE>& s_feature_PE143_3,
    hls::stream<W_TYPE>& s_feature_PE144_0, hls::stream<W_TYPE>& s_feature_PE144_1,
    hls::stream<W_TYPE>& s_feature_PE144_2, hls::stream<W_TYPE>& s_feature_PE144_3,
    hls::stream<W_TYPE>& s_feature_PE145_0, hls::stream<W_TYPE>& s_feature_PE145_1,
    hls::stream<W_TYPE>& s_feature_PE145_2, hls::stream<W_TYPE>& s_feature_PE145_3,
    hls::stream<W_TYPE>& s_feature_PE146_0, hls::stream<W_TYPE>& s_feature_PE146_1,
    hls::stream<W_TYPE>& s_feature_PE146_2, hls::stream<W_TYPE>& s_feature_PE146_3,
    hls::stream<W_TYPE>& s_feature_PE147_0, hls::stream<W_TYPE>& s_feature_PE147_1,
    hls::stream<W_TYPE>& s_feature_PE147_2, hls::stream<W_TYPE>& s_feature_PE147_3,
    hls::stream<W_TYPE>& s_feature_PE148_0, hls::stream<W_TYPE>& s_feature_PE148_1,
    hls::stream<W_TYPE>& s_feature_PE148_2, hls::stream<W_TYPE>& s_feature_PE148_3,
    hls::stream<W_TYPE>& s_feature_PE149_0, hls::stream<W_TYPE>& s_feature_PE149_1,
    hls::stream<W_TYPE>& s_feature_PE149_2, hls::stream<W_TYPE>& s_feature_PE149_3,
    hls::stream<W_TYPE>& s_feature_PE150_0, hls::stream<W_TYPE>& s_feature_PE150_1,
    hls::stream<W_TYPE>& s_feature_PE150_2, hls::stream<W_TYPE>& s_feature_PE150_3,
    hls::stream<W_TYPE>& s_feature_PE151_0, hls::stream<W_TYPE>& s_feature_PE151_1,
    hls::stream<W_TYPE>& s_feature_PE151_2, hls::stream<W_TYPE>& s_feature_PE151_3,
    hls::stream<W_TYPE>& s_feature_PE152_0, hls::stream<W_TYPE>& s_feature_PE152_1,
    hls::stream<W_TYPE>& s_feature_PE152_2, hls::stream<W_TYPE>& s_feature_PE152_3,
    hls::stream<W_TYPE>& s_feature_PE153_0, hls::stream<W_TYPE>& s_feature_PE153_1,
    hls::stream<W_TYPE>& s_feature_PE153_2, hls::stream<W_TYPE>& s_feature_PE153_3,
    hls::stream<W_TYPE>& s_feature_PE154_0, hls::stream<W_TYPE>& s_feature_PE154_1,
    hls::stream<W_TYPE>& s_feature_PE154_2, hls::stream<W_TYPE>& s_feature_PE154_3,
    hls::stream<W_TYPE>& s_feature_PE155_0, hls::stream<W_TYPE>& s_feature_PE155_1,
    hls::stream<W_TYPE>& s_feature_PE155_2, hls::stream<W_TYPE>& s_feature_PE155_3,
    hls::stream<W_TYPE>& s_feature_PE156_0, hls::stream<W_TYPE>& s_feature_PE156_1,
    hls::stream<W_TYPE>& s_feature_PE156_2, hls::stream<W_TYPE>& s_feature_PE156_3,
    hls::stream<W_TYPE>& s_feature_PE157_0, hls::stream<W_TYPE>& s_feature_PE157_1,
    hls::stream<W_TYPE>& s_feature_PE157_2, hls::stream<W_TYPE>& s_feature_PE157_3,
    hls::stream<W_TYPE>& s_feature_PE158_0, hls::stream<W_TYPE>& s_feature_PE158_1,
    hls::stream<W_TYPE>& s_feature_PE158_2, hls::stream<W_TYPE>& s_feature_PE158_3,
    hls::stream<W_TYPE>& s_feature_PE159_0, hls::stream<W_TYPE>& s_feature_PE159_1,
    hls::stream<W_TYPE>& s_feature_PE159_2, hls::stream<W_TYPE>& s_feature_PE159_3,
    hls::stream<W_TYPE>& s_feature_PE160_0, hls::stream<W_TYPE>& s_feature_PE160_1,
    hls::stream<W_TYPE>& s_feature_PE160_2, hls::stream<W_TYPE>& s_feature_PE160_3,
    hls::stream<W_TYPE>& s_feature_PE161_0, hls::stream<W_TYPE>& s_feature_PE161_1,
    hls::stream<W_TYPE>& s_feature_PE161_2, hls::stream<W_TYPE>& s_feature_PE161_3,
    hls::stream<W_TYPE>& s_feature_PE162_0, hls::stream<W_TYPE>& s_feature_PE162_1,
    hls::stream<W_TYPE>& s_feature_PE162_2, hls::stream<W_TYPE>& s_feature_PE162_3,
    hls::stream<W_TYPE>& s_feature_PE163_0, hls::stream<W_TYPE>& s_feature_PE163_1,
    hls::stream<W_TYPE>& s_feature_PE163_2, hls::stream<W_TYPE>& s_feature_PE163_3,
    hls::stream<W_TYPE>& s_feature_PE164_0, hls::stream<W_TYPE>& s_feature_PE164_1,
    hls::stream<W_TYPE>& s_feature_PE164_2, hls::stream<W_TYPE>& s_feature_PE164_3,
    hls::stream<W_TYPE>& s_feature_PE165_0, hls::stream<W_TYPE>& s_feature_PE165_1,
    hls::stream<W_TYPE>& s_feature_PE165_2, hls::stream<W_TYPE>& s_feature_PE165_3,
    hls::stream<W_TYPE>& s_feature_PE166_0, hls::stream<W_TYPE>& s_feature_PE166_1,
    hls::stream<W_TYPE>& s_feature_PE166_2, hls::stream<W_TYPE>& s_feature_PE166_3,
    hls::stream<W_TYPE>& s_feature_PE167_0, hls::stream<W_TYPE>& s_feature_PE167_1,
    hls::stream<W_TYPE>& s_feature_PE167_2, hls::stream<W_TYPE>& s_feature_PE167_3,
    hls::stream<W_TYPE>& s_feature_PE168_0, hls::stream<W_TYPE>& s_feature_PE168_1,
    hls::stream<W_TYPE>& s_feature_PE168_2, hls::stream<W_TYPE>& s_feature_PE168_3,
    hls::stream<W_TYPE>& s_feature_PE169_0, hls::stream<W_TYPE>& s_feature_PE169_1,
    hls::stream<W_TYPE>& s_feature_PE169_2, hls::stream<W_TYPE>& s_feature_PE169_3,
    hls::stream<W_TYPE>& s_feature_PE170_0, hls::stream<W_TYPE>& s_feature_PE170_1,
    hls::stream<W_TYPE>& s_feature_PE170_2, hls::stream<W_TYPE>& s_feature_PE170_3,
    hls::stream<W_TYPE>& s_feature_PE171_0, hls::stream<W_TYPE>& s_feature_PE171_1,
    hls::stream<W_TYPE>& s_feature_PE171_2, hls::stream<W_TYPE>& s_feature_PE171_3,
    hls::stream<W_TYPE>& s_feature_PE172_0, hls::stream<W_TYPE>& s_feature_PE172_1,
    hls::stream<W_TYPE>& s_feature_PE172_2, hls::stream<W_TYPE>& s_feature_PE172_3,
    hls::stream<W_TYPE>& s_feature_PE173_0, hls::stream<W_TYPE>& s_feature_PE173_1,
    hls::stream<W_TYPE>& s_feature_PE173_2, hls::stream<W_TYPE>& s_feature_PE173_3,
    hls::stream<W_TYPE>& s_feature_PE174_0, hls::stream<W_TYPE>& s_feature_PE174_1,
    hls::stream<W_TYPE>& s_feature_PE174_2, hls::stream<W_TYPE>& s_feature_PE174_3,
    hls::stream<W_TYPE>& s_feature_PE175_0, hls::stream<W_TYPE>& s_feature_PE175_1,
    hls::stream<W_TYPE>& s_feature_PE175_2, hls::stream<W_TYPE>& s_feature_PE175_3,
    hls::stream<W_TYPE>& s_feature_PE176_0, hls::stream<W_TYPE>& s_feature_PE176_1,
    hls::stream<W_TYPE>& s_feature_PE176_2, hls::stream<W_TYPE>& s_feature_PE176_3,
    hls::stream<W_TYPE>& s_feature_PE177_0, hls::stream<W_TYPE>& s_feature_PE177_1,
    hls::stream<W_TYPE>& s_feature_PE177_2, hls::stream<W_TYPE>& s_feature_PE177_3,
    hls::stream<W_TYPE>& s_feature_PE178_0, hls::stream<W_TYPE>& s_feature_PE178_1,
    hls::stream<W_TYPE>& s_feature_PE178_2, hls::stream<W_TYPE>& s_feature_PE178_3,
    hls::stream<W_TYPE>& s_feature_PE179_0, hls::stream<W_TYPE>& s_feature_PE179_1,
    hls::stream<W_TYPE>& s_feature_PE179_2, hls::stream<W_TYPE>& s_feature_PE179_3,
    hls::stream<W_TYPE>& s_feature_PE180_0, hls::stream<W_TYPE>& s_feature_PE180_1,
    hls::stream<W_TYPE>& s_feature_PE180_2, hls::stream<W_TYPE>& s_feature_PE180_3,
    hls::stream<W_TYPE>& s_feature_PE181_0, hls::stream<W_TYPE>& s_feature_PE181_1,
    hls::stream<W_TYPE>& s_feature_PE181_2, hls::stream<W_TYPE>& s_feature_PE181_3,
    hls::stream<W_TYPE>& s_feature_PE182_0, hls::stream<W_TYPE>& s_feature_PE182_1,
    hls::stream<W_TYPE>& s_feature_PE182_2, hls::stream<W_TYPE>& s_feature_PE182_3,
    hls::stream<W_TYPE>& s_feature_PE183_0, hls::stream<W_TYPE>& s_feature_PE183_1,
    hls::stream<W_TYPE>& s_feature_PE183_2, hls::stream<W_TYPE>& s_feature_PE183_3,
    hls::stream<W_TYPE>& s_feature_PE184_0, hls::stream<W_TYPE>& s_feature_PE184_1,
    hls::stream<W_TYPE>& s_feature_PE184_2, hls::stream<W_TYPE>& s_feature_PE184_3,
    hls::stream<W_TYPE>& s_feature_PE185_0, hls::stream<W_TYPE>& s_feature_PE185_1,
    hls::stream<W_TYPE>& s_feature_PE185_2, hls::stream<W_TYPE>& s_feature_PE185_3,
    hls::stream<W_TYPE>& s_feature_PE186_0, hls::stream<W_TYPE>& s_feature_PE186_1,
    hls::stream<W_TYPE>& s_feature_PE186_2, hls::stream<W_TYPE>& s_feature_PE186_3,
    hls::stream<W_TYPE>& s_feature_PE187_0, hls::stream<W_TYPE>& s_feature_PE187_1,
    hls::stream<W_TYPE>& s_feature_PE187_2, hls::stream<W_TYPE>& s_feature_PE187_3,
    hls::stream<W_TYPE>& s_feature_PE188_0, hls::stream<W_TYPE>& s_feature_PE188_1,
    hls::stream<W_TYPE>& s_feature_PE188_2, hls::stream<W_TYPE>& s_feature_PE188_3,
    hls::stream<W_TYPE>& s_feature_PE189_0, hls::stream<W_TYPE>& s_feature_PE189_1,
    hls::stream<W_TYPE>& s_feature_PE189_2, hls::stream<W_TYPE>& s_feature_PE189_3,
    hls::stream<W_TYPE>& s_feature_PE190_0, hls::stream<W_TYPE>& s_feature_PE190_1,
    hls::stream<W_TYPE>& s_feature_PE190_2, hls::stream<W_TYPE>& s_feature_PE190_3,
    hls::stream<W_TYPE>& s_feature_PE191_0, hls::stream<W_TYPE>& s_feature_PE191_1,
    hls::stream<W_TYPE>& s_feature_PE191_2, hls::stream<W_TYPE>& s_feature_PE191_3,
    hls::stream<W_TYPE>& s_feature_PE192_0, hls::stream<W_TYPE>& s_feature_PE192_1,
    hls::stream<W_TYPE>& s_feature_PE192_2, hls::stream<W_TYPE>& s_feature_PE192_3,
    hls::stream<W_TYPE>& s_feature_PE193_0, hls::stream<W_TYPE>& s_feature_PE193_1,
    hls::stream<W_TYPE>& s_feature_PE193_2, hls::stream<W_TYPE>& s_feature_PE193_3,
    hls::stream<W_TYPE>& s_feature_PE194_0, hls::stream<W_TYPE>& s_feature_PE194_1,
    hls::stream<W_TYPE>& s_feature_PE194_2, hls::stream<W_TYPE>& s_feature_PE194_3,
    hls::stream<W_TYPE>& s_feature_PE195_0, hls::stream<W_TYPE>& s_feature_PE195_1,
    hls::stream<W_TYPE>& s_feature_PE195_2, hls::stream<W_TYPE>& s_feature_PE195_3,
    hls::stream<W_TYPE>& s_feature_PE196_0, hls::stream<W_TYPE>& s_feature_PE196_1,
    hls::stream<W_TYPE>& s_feature_PE196_2, hls::stream<W_TYPE>& s_feature_PE196_3,
    hls::stream<W_TYPE>& s_feature_PE197_0, hls::stream<W_TYPE>& s_feature_PE197_1,
    hls::stream<W_TYPE>& s_feature_PE197_2, hls::stream<W_TYPE>& s_feature_PE197_3,
    hls::stream<W_TYPE>& s_feature_PE198_0, hls::stream<W_TYPE>& s_feature_PE198_1,
    hls::stream<W_TYPE>& s_feature_PE198_2, hls::stream<W_TYPE>& s_feature_PE198_3,
    hls::stream<W_TYPE>& s_feature_PE199_0, hls::stream<W_TYPE>& s_feature_PE199_1,
    hls::stream<W_TYPE>& s_feature_PE199_2, hls::stream<W_TYPE>& s_feature_PE199_3,
    hls::stream<W_TYPE>& s_feature_PE200_0, hls::stream<W_TYPE>& s_feature_PE200_1,
    hls::stream<W_TYPE>& s_feature_PE200_2, hls::stream<W_TYPE>& s_feature_PE200_3,
    hls::stream<W_TYPE>& s_feature_PE201_0, hls::stream<W_TYPE>& s_feature_PE201_1,
    hls::stream<W_TYPE>& s_feature_PE201_2, hls::stream<W_TYPE>& s_feature_PE201_3,
    hls::stream<W_TYPE>& s_feature_PE202_0, hls::stream<W_TYPE>& s_feature_PE202_1,
    hls::stream<W_TYPE>& s_feature_PE202_2, hls::stream<W_TYPE>& s_feature_PE202_3,
    hls::stream<W_TYPE>& s_feature_PE203_0, hls::stream<W_TYPE>& s_feature_PE203_1,
    hls::stream<W_TYPE>& s_feature_PE203_2, hls::stream<W_TYPE>& s_feature_PE203_3,
    hls::stream<W_TYPE>& s_feature_PE204_0, hls::stream<W_TYPE>& s_feature_PE204_1,
    hls::stream<W_TYPE>& s_feature_PE204_2, hls::stream<W_TYPE>& s_feature_PE204_3,
    hls::stream<W_TYPE>& s_feature_PE205_0, hls::stream<W_TYPE>& s_feature_PE205_1,
    hls::stream<W_TYPE>& s_feature_PE205_2, hls::stream<W_TYPE>& s_feature_PE205_3,
    hls::stream<W_TYPE>& s_feature_PE206_0, hls::stream<W_TYPE>& s_feature_PE206_1,
    hls::stream<W_TYPE>& s_feature_PE206_2, hls::stream<W_TYPE>& s_feature_PE206_3,
    hls::stream<W_TYPE>& s_feature_PE207_0, hls::stream<W_TYPE>& s_feature_PE207_1,
    hls::stream<W_TYPE>& s_feature_PE207_2, hls::stream<W_TYPE>& s_feature_PE207_3,
    hls::stream<W_TYPE>& s_feature_PE208_0, hls::stream<W_TYPE>& s_feature_PE208_1,
    hls::stream<W_TYPE>& s_feature_PE208_2, hls::stream<W_TYPE>& s_feature_PE208_3,
    hls::stream<W_TYPE>& s_feature_PE209_0, hls::stream<W_TYPE>& s_feature_PE209_1,
    hls::stream<W_TYPE>& s_feature_PE209_2, hls::stream<W_TYPE>& s_feature_PE209_3,
    hls::stream<W_TYPE>& s_feature_PE210_0, hls::stream<W_TYPE>& s_feature_PE210_1,
    hls::stream<W_TYPE>& s_feature_PE210_2, hls::stream<W_TYPE>& s_feature_PE210_3,
    hls::stream<W_TYPE>& s_feature_PE211_0, hls::stream<W_TYPE>& s_feature_PE211_1,
    hls::stream<W_TYPE>& s_feature_PE211_2, hls::stream<W_TYPE>& s_feature_PE211_3,
    hls::stream<W_TYPE>& s_feature_PE212_0, hls::stream<W_TYPE>& s_feature_PE212_1,
    hls::stream<W_TYPE>& s_feature_PE212_2, hls::stream<W_TYPE>& s_feature_PE212_3,
    hls::stream<W_TYPE>& s_feature_PE213_0, hls::stream<W_TYPE>& s_feature_PE213_1,
    hls::stream<W_TYPE>& s_feature_PE213_2, hls::stream<W_TYPE>& s_feature_PE213_3,
    hls::stream<W_TYPE>& s_feature_PE214_0, hls::stream<W_TYPE>& s_feature_PE214_1,
    hls::stream<W_TYPE>& s_feature_PE214_2, hls::stream<W_TYPE>& s_feature_PE214_3,
    hls::stream<W_TYPE>& s_feature_PE215_0, hls::stream<W_TYPE>& s_feature_PE215_1,
    hls::stream<W_TYPE>& s_feature_PE215_2, hls::stream<W_TYPE>& s_feature_PE215_3,
    hls::stream<W_TYPE>& s_feature_PE216_0, hls::stream<W_TYPE>& s_feature_PE216_1,
    hls::stream<W_TYPE>& s_feature_PE216_2, hls::stream<W_TYPE>& s_feature_PE216_3,
    hls::stream<W_TYPE>& s_feature_PE217_0, hls::stream<W_TYPE>& s_feature_PE217_1,
    hls::stream<W_TYPE>& s_feature_PE217_2, hls::stream<W_TYPE>& s_feature_PE217_3,
    hls::stream<W_TYPE>& s_feature_PE218_0, hls::stream<W_TYPE>& s_feature_PE218_1,
    hls::stream<W_TYPE>& s_feature_PE218_2, hls::stream<W_TYPE>& s_feature_PE218_3,
    hls::stream<W_TYPE>& s_feature_PE219_0, hls::stream<W_TYPE>& s_feature_PE219_1,
    hls::stream<W_TYPE>& s_feature_PE219_2, hls::stream<W_TYPE>& s_feature_PE219_3,
    hls::stream<W_TYPE>& s_feature_PE220_0, hls::stream<W_TYPE>& s_feature_PE220_1,
    hls::stream<W_TYPE>& s_feature_PE220_2, hls::stream<W_TYPE>& s_feature_PE220_3,
    hls::stream<W_TYPE>& s_feature_PE221_0, hls::stream<W_TYPE>& s_feature_PE221_1,
    hls::stream<W_TYPE>& s_feature_PE221_2, hls::stream<W_TYPE>& s_feature_PE221_3,
    hls::stream<W_TYPE>& s_feature_PE222_0, hls::stream<W_TYPE>& s_feature_PE222_1,
    hls::stream<W_TYPE>& s_feature_PE222_2, hls::stream<W_TYPE>& s_feature_PE222_3,
    hls::stream<W_TYPE>& s_feature_PE223_0, hls::stream<W_TYPE>& s_feature_PE223_1,
    hls::stream<W_TYPE>& s_feature_PE223_2, hls::stream<W_TYPE>& s_feature_PE223_3,
    hls::stream<W_TYPE>& s_feature_PE224_0, hls::stream<W_TYPE>& s_feature_PE224_1,
    hls::stream<W_TYPE>& s_feature_PE224_2, hls::stream<W_TYPE>& s_feature_PE224_3,
    hls::stream<W_TYPE>& s_feature_PE225_0, hls::stream<W_TYPE>& s_feature_PE225_1,
    hls::stream<W_TYPE>& s_feature_PE225_2, hls::stream<W_TYPE>& s_feature_PE225_3,
    hls::stream<W_TYPE>& s_feature_PE226_0, hls::stream<W_TYPE>& s_feature_PE226_1,
    hls::stream<W_TYPE>& s_feature_PE226_2, hls::stream<W_TYPE>& s_feature_PE226_3,
    hls::stream<W_TYPE>& s_feature_PE227_0, hls::stream<W_TYPE>& s_feature_PE227_1,
    hls::stream<W_TYPE>& s_feature_PE227_2, hls::stream<W_TYPE>& s_feature_PE227_3,
    hls::stream<W_TYPE>& s_feature_PE228_0, hls::stream<W_TYPE>& s_feature_PE228_1,
    hls::stream<W_TYPE>& s_feature_PE228_2, hls::stream<W_TYPE>& s_feature_PE228_3,
    hls::stream<W_TYPE>& s_feature_PE229_0, hls::stream<W_TYPE>& s_feature_PE229_1,
    hls::stream<W_TYPE>& s_feature_PE229_2, hls::stream<W_TYPE>& s_feature_PE229_3,
    hls::stream<W_TYPE>& s_feature_PE230_0, hls::stream<W_TYPE>& s_feature_PE230_1,
    hls::stream<W_TYPE>& s_feature_PE230_2, hls::stream<W_TYPE>& s_feature_PE230_3,
    hls::stream<W_TYPE>& s_feature_PE231_0, hls::stream<W_TYPE>& s_feature_PE231_1,
    hls::stream<W_TYPE>& s_feature_PE231_2, hls::stream<W_TYPE>& s_feature_PE231_3,
    hls::stream<W_TYPE>& s_feature_PE232_0, hls::stream<W_TYPE>& s_feature_PE232_1,
    hls::stream<W_TYPE>& s_feature_PE232_2, hls::stream<W_TYPE>& s_feature_PE232_3,
    hls::stream<W_TYPE>& s_feature_PE233_0, hls::stream<W_TYPE>& s_feature_PE233_1,
    hls::stream<W_TYPE>& s_feature_PE233_2, hls::stream<W_TYPE>& s_feature_PE233_3,
    hls::stream<W_TYPE>& s_feature_PE234_0, hls::stream<W_TYPE>& s_feature_PE234_1,
    hls::stream<W_TYPE>& s_feature_PE234_2, hls::stream<W_TYPE>& s_feature_PE234_3,
    hls::stream<W_TYPE>& s_feature_PE235_0, hls::stream<W_TYPE>& s_feature_PE235_1,
    hls::stream<W_TYPE>& s_feature_PE235_2, hls::stream<W_TYPE>& s_feature_PE235_3,
    hls::stream<W_TYPE>& s_feature_PE236_0, hls::stream<W_TYPE>& s_feature_PE236_1,
    hls::stream<W_TYPE>& s_feature_PE236_2, hls::stream<W_TYPE>& s_feature_PE236_3,
    hls::stream<W_TYPE>& s_feature_PE237_0, hls::stream<W_TYPE>& s_feature_PE237_1,
    hls::stream<W_TYPE>& s_feature_PE237_2, hls::stream<W_TYPE>& s_feature_PE237_3,
    hls::stream<W_TYPE>& s_feature_PE238_0, hls::stream<W_TYPE>& s_feature_PE238_1,
    hls::stream<W_TYPE>& s_feature_PE238_2, hls::stream<W_TYPE>& s_feature_PE238_3,
    hls::stream<W_TYPE>& s_feature_PE239_0, hls::stream<W_TYPE>& s_feature_PE239_1,
    hls::stream<W_TYPE>& s_feature_PE239_2, hls::stream<W_TYPE>& s_feature_PE239_3,
    hls::stream<W_TYPE>& s_feature_PE240_0, hls::stream<W_TYPE>& s_feature_PE240_1,
    hls::stream<W_TYPE>& s_feature_PE240_2, hls::stream<W_TYPE>& s_feature_PE240_3,
    hls::stream<W_TYPE>& s_feature_PE241_0, hls::stream<W_TYPE>& s_feature_PE241_1,
    hls::stream<W_TYPE>& s_feature_PE241_2, hls::stream<W_TYPE>& s_feature_PE241_3,
    hls::stream<W_TYPE>& s_feature_PE242_0, hls::stream<W_TYPE>& s_feature_PE242_1,
    hls::stream<W_TYPE>& s_feature_PE242_2, hls::stream<W_TYPE>& s_feature_PE242_3,
    hls::stream<W_TYPE>& s_feature_PE243_0, hls::stream<W_TYPE>& s_feature_PE243_1,
    hls::stream<W_TYPE>& s_feature_PE243_2, hls::stream<W_TYPE>& s_feature_PE243_3,
    hls::stream<W_TYPE>& s_feature_PE244_0, hls::stream<W_TYPE>& s_feature_PE244_1,
    hls::stream<W_TYPE>& s_feature_PE244_2, hls::stream<W_TYPE>& s_feature_PE244_3,
    hls::stream<W_TYPE>& s_feature_PE245_0, hls::stream<W_TYPE>& s_feature_PE245_1,
    hls::stream<W_TYPE>& s_feature_PE245_2, hls::stream<W_TYPE>& s_feature_PE245_3,
    hls::stream<W_TYPE>& s_feature_PE246_0, hls::stream<W_TYPE>& s_feature_PE246_1,
    hls::stream<W_TYPE>& s_feature_PE246_2, hls::stream<W_TYPE>& s_feature_PE246_3,
    hls::stream<W_TYPE>& s_feature_PE247_0, hls::stream<W_TYPE>& s_feature_PE247_1,
    hls::stream<W_TYPE>& s_feature_PE247_2, hls::stream<W_TYPE>& s_feature_PE247_3,
    hls::stream<W_TYPE>& s_feature_PE248_0, hls::stream<W_TYPE>& s_feature_PE248_1,
    hls::stream<W_TYPE>& s_feature_PE248_2, hls::stream<W_TYPE>& s_feature_PE248_3,
    hls::stream<W_TYPE>& s_feature_PE249_0, hls::stream<W_TYPE>& s_feature_PE249_1,
    hls::stream<W_TYPE>& s_feature_PE249_2, hls::stream<W_TYPE>& s_feature_PE249_3,
    hls::stream<W_TYPE>& s_feature_PE250_0, hls::stream<W_TYPE>& s_feature_PE250_1,
    hls::stream<W_TYPE>& s_feature_PE250_2, hls::stream<W_TYPE>& s_feature_PE250_3,
    hls::stream<W_TYPE>& s_feature_PE251_0, hls::stream<W_TYPE>& s_feature_PE251_1,
    hls::stream<W_TYPE>& s_feature_PE251_2, hls::stream<W_TYPE>& s_feature_PE251_3,
    hls::stream<W_TYPE>& s_feature_PE252_0, hls::stream<W_TYPE>& s_feature_PE252_1,
    hls::stream<W_TYPE>& s_feature_PE252_2, hls::stream<W_TYPE>& s_feature_PE252_3,
    hls::stream<W_TYPE>& s_feature_PE253_0, hls::stream<W_TYPE>& s_feature_PE253_1,
    hls::stream<W_TYPE>& s_feature_PE253_2, hls::stream<W_TYPE>& s_feature_PE253_3,
    hls::stream<W_TYPE>& s_feature_PE254_0, hls::stream<W_TYPE>& s_feature_PE254_1,
    hls::stream<W_TYPE>& s_feature_PE254_2, hls::stream<W_TYPE>& s_feature_PE254_3,
    hls::stream<W_TYPE>& s_feature_PE255_0, hls::stream<W_TYPE>& s_feature_PE255_1,
    hls::stream<W_TYPE>& s_feature_PE255_2, hls::stream<W_TYPE>& s_feature_PE255_3,
    hls::stream<W_TYPE>& s_feature_PE256_0, hls::stream<W_TYPE>& s_feature_PE256_1,
    hls::stream<W_TYPE>& s_feature_PE256_2, hls::stream<W_TYPE>& s_feature_PE256_3,
    hls::stream<W_TYPE>& s_feature_PE257_0, hls::stream<W_TYPE>& s_feature_PE257_1,
    hls::stream<W_TYPE>& s_feature_PE257_2, hls::stream<W_TYPE>& s_feature_PE257_3,
    hls::stream<W_TYPE>& s_feature_PE258_0, hls::stream<W_TYPE>& s_feature_PE258_1,
    hls::stream<W_TYPE>& s_feature_PE258_2, hls::stream<W_TYPE>& s_feature_PE258_3,
    hls::stream<W_TYPE>& s_feature_PE259_0, hls::stream<W_TYPE>& s_feature_PE259_1,
    hls::stream<W_TYPE>& s_feature_PE259_2, hls::stream<W_TYPE>& s_feature_PE259_3,
    hls::stream<W_TYPE>& s_feature_PE260_0, hls::stream<W_TYPE>& s_feature_PE260_1,
    hls::stream<W_TYPE>& s_feature_PE260_2, hls::stream<W_TYPE>& s_feature_PE260_3,
    hls::stream<W_TYPE>& s_feature_PE261_0, hls::stream<W_TYPE>& s_feature_PE261_1,
    hls::stream<W_TYPE>& s_feature_PE261_2, hls::stream<W_TYPE>& s_feature_PE261_3,
    hls::stream<W_TYPE>& s_feature_PE262_0, hls::stream<W_TYPE>& s_feature_PE262_1,
    hls::stream<W_TYPE>& s_feature_PE262_2, hls::stream<W_TYPE>& s_feature_PE262_3,
    hls::stream<W_TYPE>& s_feature_PE263_0, hls::stream<W_TYPE>& s_feature_PE263_1,
    hls::stream<W_TYPE>& s_feature_PE263_2, hls::stream<W_TYPE>& s_feature_PE263_3,
    hls::stream<W_TYPE>& s_feature_PE264_0, hls::stream<W_TYPE>& s_feature_PE264_1,
    hls::stream<W_TYPE>& s_feature_PE264_2, hls::stream<W_TYPE>& s_feature_PE264_3,
    hls::stream<W_TYPE>& s_feature_PE265_0, hls::stream<W_TYPE>& s_feature_PE265_1,
    hls::stream<W_TYPE>& s_feature_PE265_2, hls::stream<W_TYPE>& s_feature_PE265_3,
    hls::stream<W_TYPE>& s_feature_PE266_0, hls::stream<W_TYPE>& s_feature_PE266_1,
    hls::stream<W_TYPE>& s_feature_PE266_2, hls::stream<W_TYPE>& s_feature_PE266_3,
    hls::stream<W_TYPE>& s_feature_PE267_0, hls::stream<W_TYPE>& s_feature_PE267_1,
    hls::stream<W_TYPE>& s_feature_PE267_2, hls::stream<W_TYPE>& s_feature_PE267_3,
    hls::stream<W_TYPE>& s_feature_PE268_0, hls::stream<W_TYPE>& s_feature_PE268_1,
    hls::stream<W_TYPE>& s_feature_PE268_2, hls::stream<W_TYPE>& s_feature_PE268_3,
    hls::stream<W_TYPE>& s_feature_PE269_0, hls::stream<W_TYPE>& s_feature_PE269_1,
    hls::stream<W_TYPE>& s_feature_PE269_2, hls::stream<W_TYPE>& s_feature_PE269_3,
    hls::stream<W_TYPE>& s_feature_PE270_0, hls::stream<W_TYPE>& s_feature_PE270_1,
    hls::stream<W_TYPE>& s_feature_PE270_2, hls::stream<W_TYPE>& s_feature_PE270_3,
    hls::stream<W_TYPE>& s_feature_PE271_0, hls::stream<W_TYPE>& s_feature_PE271_1,
    hls::stream<W_TYPE>& s_feature_PE271_2, hls::stream<W_TYPE>& s_feature_PE271_3,
    hls::stream<W_TYPE>& s_feature_PE272_0, hls::stream<W_TYPE>& s_feature_PE272_1,
    hls::stream<W_TYPE>& s_feature_PE272_2, hls::stream<W_TYPE>& s_feature_PE272_3,
    hls::stream<W_TYPE>& s_feature_PE273_0, hls::stream<W_TYPE>& s_feature_PE273_1,
    hls::stream<W_TYPE>& s_feature_PE273_2, hls::stream<W_TYPE>& s_feature_PE273_3,
    hls::stream<W_TYPE>& s_feature_PE274_0, hls::stream<W_TYPE>& s_feature_PE274_1,
    hls::stream<W_TYPE>& s_feature_PE274_2, hls::stream<W_TYPE>& s_feature_PE274_3,
    hls::stream<W_TYPE>& s_feature_PE275_0, hls::stream<W_TYPE>& s_feature_PE275_1,
    hls::stream<W_TYPE>& s_feature_PE275_2, hls::stream<W_TYPE>& s_feature_PE275_3,
    hls::stream<W_TYPE>& s_feature_PE276_0, hls::stream<W_TYPE>& s_feature_PE276_1,
    hls::stream<W_TYPE>& s_feature_PE276_2, hls::stream<W_TYPE>& s_feature_PE276_3,
    hls::stream<W_TYPE>& s_feature_PE277_0, hls::stream<W_TYPE>& s_feature_PE277_1,
    hls::stream<W_TYPE>& s_feature_PE277_2, hls::stream<W_TYPE>& s_feature_PE277_3,
    hls::stream<W_TYPE>& s_feature_PE278_0, hls::stream<W_TYPE>& s_feature_PE278_1,
    hls::stream<W_TYPE>& s_feature_PE278_2, hls::stream<W_TYPE>& s_feature_PE278_3,
    hls::stream<W_TYPE>& s_feature_PE279_0, hls::stream<W_TYPE>& s_feature_PE279_1,
    hls::stream<W_TYPE>& s_feature_PE279_2, hls::stream<W_TYPE>& s_feature_PE279_3,
    hls::stream<W_TYPE>& s_feature_PE280_0, hls::stream<W_TYPE>& s_feature_PE280_1,
    hls::stream<W_TYPE>& s_feature_PE280_2, hls::stream<W_TYPE>& s_feature_PE280_3,
    hls::stream<W_TYPE>& s_feature_PE281_0, hls::stream<W_TYPE>& s_feature_PE281_1,
    hls::stream<W_TYPE>& s_feature_PE281_2, hls::stream<W_TYPE>& s_feature_PE281_3,
    hls::stream<W_TYPE>& s_feature_PE282_0, hls::stream<W_TYPE>& s_feature_PE282_1,
    hls::stream<W_TYPE>& s_feature_PE282_2, hls::stream<W_TYPE>& s_feature_PE282_3,
    hls::stream<W_TYPE>& s_feature_PE283_0, hls::stream<W_TYPE>& s_feature_PE283_1,
    hls::stream<W_TYPE>& s_feature_PE283_2, hls::stream<W_TYPE>& s_feature_PE283_3,
    hls::stream<W_TYPE>& s_feature_PE284_0, hls::stream<W_TYPE>& s_feature_PE284_1,
    hls::stream<W_TYPE>& s_feature_PE284_2, hls::stream<W_TYPE>& s_feature_PE284_3,
    hls::stream<W_TYPE>& s_feature_PE285_0, hls::stream<W_TYPE>& s_feature_PE285_1,
    hls::stream<W_TYPE>& s_feature_PE285_2, hls::stream<W_TYPE>& s_feature_PE285_3,
    hls::stream<W_TYPE>& s_feature_PE286_0, hls::stream<W_TYPE>& s_feature_PE286_1,
    hls::stream<W_TYPE>& s_feature_PE286_2, hls::stream<W_TYPE>& s_feature_PE286_3,
    hls::stream<W_TYPE>& s_feature_PE287_0, hls::stream<W_TYPE>& s_feature_PE287_1,
    hls::stream<W_TYPE>& s_feature_PE287_2, hls::stream<W_TYPE>& s_feature_PE287_3,
    hls::stream<W_TYPE>& s_feature_PE288_0, hls::stream<W_TYPE>& s_feature_PE288_1,
    hls::stream<W_TYPE>& s_feature_PE288_2, hls::stream<W_TYPE>& s_feature_PE288_3,
    hls::stream<W_TYPE>& s_feature_PE289_0, hls::stream<W_TYPE>& s_feature_PE289_1,
    hls::stream<W_TYPE>& s_feature_PE289_2, hls::stream<W_TYPE>& s_feature_PE289_3,
    hls::stream<W_TYPE>& s_feature_PE290_0, hls::stream<W_TYPE>& s_feature_PE290_1,
    hls::stream<W_TYPE>& s_feature_PE290_2, hls::stream<W_TYPE>& s_feature_PE290_3,
    hls::stream<W_TYPE>& s_feature_PE291_0, hls::stream<W_TYPE>& s_feature_PE291_1,
    hls::stream<W_TYPE>& s_feature_PE291_2, hls::stream<W_TYPE>& s_feature_PE291_3,
    hls::stream<W_TYPE>& s_feature_PE292_0, hls::stream<W_TYPE>& s_feature_PE292_1,
    hls::stream<W_TYPE>& s_feature_PE292_2, hls::stream<W_TYPE>& s_feature_PE292_3,
    hls::stream<W_TYPE>& s_feature_PE293_0, hls::stream<W_TYPE>& s_feature_PE293_1,
    hls::stream<W_TYPE>& s_feature_PE293_2, hls::stream<W_TYPE>& s_feature_PE293_3,
    hls::stream<W_TYPE>& s_feature_PE294_0, hls::stream<W_TYPE>& s_feature_PE294_1,
    hls::stream<W_TYPE>& s_feature_PE294_2, hls::stream<W_TYPE>& s_feature_PE294_3,
    hls::stream<W_TYPE>& s_feature_PE295_0, hls::stream<W_TYPE>& s_feature_PE295_1,
    hls::stream<W_TYPE>& s_feature_PE295_2, hls::stream<W_TYPE>& s_feature_PE295_3,
    hls::stream<W_TYPE>& s_feature_PE296_0, hls::stream<W_TYPE>& s_feature_PE296_1,
    hls::stream<W_TYPE>& s_feature_PE296_2, hls::stream<W_TYPE>& s_feature_PE296_3,
    hls::stream<W_TYPE>& s_feature_PE297_0, hls::stream<W_TYPE>& s_feature_PE297_1,
    hls::stream<W_TYPE>& s_feature_PE297_2, hls::stream<W_TYPE>& s_feature_PE297_3,
    hls::stream<W_TYPE>& s_feature_PE298_0, hls::stream<W_TYPE>& s_feature_PE298_1,
    hls::stream<W_TYPE>& s_feature_PE298_2, hls::stream<W_TYPE>& s_feature_PE298_3,
    hls::stream<W_TYPE>& s_feature_PE299_0, hls::stream<W_TYPE>& s_feature_PE299_1,
    hls::stream<W_TYPE>& s_feature_PE299_2, hls::stream<W_TYPE>& s_feature_PE299_3,
    hls::stream<W_TYPE>& s_feature_PE300_0, hls::stream<W_TYPE>& s_feature_PE300_1,
    hls::stream<W_TYPE>& s_feature_PE300_2, hls::stream<W_TYPE>& s_feature_PE300_3,
    hls::stream<W_TYPE>& s_feature_PE301_0, hls::stream<W_TYPE>& s_feature_PE301_1,
    hls::stream<W_TYPE>& s_feature_PE301_2, hls::stream<W_TYPE>& s_feature_PE301_3,
    hls::stream<W_TYPE>& s_feature_PE302_0, hls::stream<W_TYPE>& s_feature_PE302_1,
    hls::stream<W_TYPE>& s_feature_PE302_2, hls::stream<W_TYPE>& s_feature_PE302_3,
    hls::stream<W_TYPE>& s_feature_PE303_0, hls::stream<W_TYPE>& s_feature_PE303_1,
    hls::stream<W_TYPE>& s_feature_PE303_2, hls::stream<W_TYPE>& s_feature_PE303_3,
    hls::stream<W_TYPE>& s_feature_PE304_0, hls::stream<W_TYPE>& s_feature_PE304_1,
    hls::stream<W_TYPE>& s_feature_PE304_2, hls::stream<W_TYPE>& s_feature_PE304_3,
    hls::stream<W_TYPE>& s_feature_PE305_0, hls::stream<W_TYPE>& s_feature_PE305_1,
    hls::stream<W_TYPE>& s_feature_PE305_2, hls::stream<W_TYPE>& s_feature_PE305_3,
    hls::stream<W_TYPE>& s_feature_PE306_0, hls::stream<W_TYPE>& s_feature_PE306_1,
    hls::stream<W_TYPE>& s_feature_PE306_2, hls::stream<W_TYPE>& s_feature_PE306_3,
    hls::stream<W_TYPE>& s_feature_PE307_0, hls::stream<W_TYPE>& s_feature_PE307_1,
    hls::stream<W_TYPE>& s_feature_PE307_2, hls::stream<W_TYPE>& s_feature_PE307_3,
    hls::stream<W_TYPE>& s_feature_PE308_0, hls::stream<W_TYPE>& s_feature_PE308_1,
    hls::stream<W_TYPE>& s_feature_PE308_2, hls::stream<W_TYPE>& s_feature_PE308_3,
    hls::stream<W_TYPE>& s_feature_PE309_0, hls::stream<W_TYPE>& s_feature_PE309_1,
    hls::stream<W_TYPE>& s_feature_PE309_2, hls::stream<W_TYPE>& s_feature_PE309_3,
    hls::stream<W_TYPE>& s_feature_PE310_0, hls::stream<W_TYPE>& s_feature_PE310_1,
    hls::stream<W_TYPE>& s_feature_PE310_2, hls::stream<W_TYPE>& s_feature_PE310_3,
    hls::stream<W_TYPE>& s_feature_PE311_0, hls::stream<W_TYPE>& s_feature_PE311_1,
    hls::stream<W_TYPE>& s_feature_PE311_2, hls::stream<W_TYPE>& s_feature_PE311_3,
    hls::stream<W_TYPE>& s_feature_PE312_0, hls::stream<W_TYPE>& s_feature_PE312_1,
    hls::stream<W_TYPE>& s_feature_PE312_2, hls::stream<W_TYPE>& s_feature_PE312_3,
    hls::stream<W_TYPE>& s_feature_PE313_0, hls::stream<W_TYPE>& s_feature_PE313_1,
    hls::stream<W_TYPE>& s_feature_PE313_2, hls::stream<W_TYPE>& s_feature_PE313_3,
    hls::stream<W_TYPE>& s_feature_PE314_0, hls::stream<W_TYPE>& s_feature_PE314_1,
    hls::stream<W_TYPE>& s_feature_PE314_2, hls::stream<W_TYPE>& s_feature_PE314_3,
    hls::stream<W_TYPE>& s_feature_PE315_0, hls::stream<W_TYPE>& s_feature_PE315_1,
    hls::stream<W_TYPE>& s_feature_PE315_2, hls::stream<W_TYPE>& s_feature_PE315_3,
    hls::stream<W_TYPE>& s_feature_PE316_0, hls::stream<W_TYPE>& s_feature_PE316_1,
    hls::stream<W_TYPE>& s_feature_PE316_2, hls::stream<W_TYPE>& s_feature_PE316_3,
    hls::stream<W_TYPE>& s_feature_PE317_0, hls::stream<W_TYPE>& s_feature_PE317_1,
    hls::stream<W_TYPE>& s_feature_PE317_2, hls::stream<W_TYPE>& s_feature_PE317_3,
    hls::stream<W_TYPE>& s_feature_PE318_0, hls::stream<W_TYPE>& s_feature_PE318_1,
    hls::stream<W_TYPE>& s_feature_PE318_2, hls::stream<W_TYPE>& s_feature_PE318_3,
    hls::stream<W_TYPE>& s_feature_PE319_0, hls::stream<W_TYPE>& s_feature_PE319_1,
    hls::stream<W_TYPE>& s_feature_PE319_2, hls::stream<W_TYPE>& s_feature_PE319_3
) {
        for (int i = 0; i < BATCH_NUM * BATCH_SIZE * FEATURE_SIZE / INTS_PER_W / 4; i++) {
            #pragma HLS pipeline II=1

            ap_uint<512> reg = s_feature_in.read();

            W_TYPE reg0 = reg.range(127, 0);
            W_TYPE reg1 = reg.range(255, 128);
            W_TYPE reg2 = reg.range(383, 256);
            W_TYPE reg3 = reg.range(511, 255);

            s_feature_PE0_0.write(reg0);
            s_feature_PE0_1.write(reg1);
            s_feature_PE0_2.write(reg2);
            s_feature_PE0_3.write(reg3);
            s_feature_PE1_0.write(reg0);
            s_feature_PE1_1.write(reg1);
            s_feature_PE1_2.write(reg2);
            s_feature_PE1_3.write(reg3);
            s_feature_PE2_0.write(reg0);
            s_feature_PE2_1.write(reg1);
            s_feature_PE2_2.write(reg2);
            s_feature_PE2_3.write(reg3);
            s_feature_PE3_0.write(reg0);
            s_feature_PE3_1.write(reg1);
            s_feature_PE3_2.write(reg2);
            s_feature_PE3_3.write(reg3);
            s_feature_PE4_0.write(reg0);
            s_feature_PE4_1.write(reg1);
            s_feature_PE4_2.write(reg2);
            s_feature_PE4_3.write(reg3);
            s_feature_PE5_0.write(reg0);
            s_feature_PE5_1.write(reg1);
            s_feature_PE5_2.write(reg2);
            s_feature_PE5_3.write(reg3);
            s_feature_PE6_0.write(reg0);
            s_feature_PE6_1.write(reg1);
            s_feature_PE6_2.write(reg2);
            s_feature_PE6_3.write(reg3);
            s_feature_PE7_0.write(reg0);
            s_feature_PE7_1.write(reg1);
            s_feature_PE7_2.write(reg2);
            s_feature_PE7_3.write(reg3);
            s_feature_PE8_0.write(reg0);
            s_feature_PE8_1.write(reg1);
            s_feature_PE8_2.write(reg2);
            s_feature_PE8_3.write(reg3);
            s_feature_PE9_0.write(reg0);
            s_feature_PE9_1.write(reg1);
            s_feature_PE9_2.write(reg2);
            s_feature_PE9_3.write(reg3);
            s_feature_PE10_0.write(reg0);
            s_feature_PE10_1.write(reg1);
            s_feature_PE10_2.write(reg2);
            s_feature_PE10_3.write(reg3);
            s_feature_PE11_0.write(reg0);
            s_feature_PE11_1.write(reg1);
            s_feature_PE11_2.write(reg2);
            s_feature_PE11_3.write(reg3);
            s_feature_PE12_0.write(reg0);
            s_feature_PE12_1.write(reg1);
            s_feature_PE12_2.write(reg2);
            s_feature_PE12_3.write(reg3);
            s_feature_PE13_0.write(reg0);
            s_feature_PE13_1.write(reg1);
            s_feature_PE13_2.write(reg2);
            s_feature_PE13_3.write(reg3);
            s_feature_PE14_0.write(reg0);
            s_feature_PE14_1.write(reg1);
            s_feature_PE14_2.write(reg2);
            s_feature_PE14_3.write(reg3);
            s_feature_PE15_0.write(reg0);
            s_feature_PE15_1.write(reg1);
            s_feature_PE15_2.write(reg2);
            s_feature_PE15_3.write(reg3);
            s_feature_PE16_0.write(reg0);
            s_feature_PE16_1.write(reg1);
            s_feature_PE16_2.write(reg2);
            s_feature_PE16_3.write(reg3);
            s_feature_PE17_0.write(reg0);
            s_feature_PE17_1.write(reg1);
            s_feature_PE17_2.write(reg2);
            s_feature_PE17_3.write(reg3);
            s_feature_PE18_0.write(reg0);
            s_feature_PE18_1.write(reg1);
            s_feature_PE18_2.write(reg2);
            s_feature_PE18_3.write(reg3);
            s_feature_PE19_0.write(reg0);
            s_feature_PE19_1.write(reg1);
            s_feature_PE19_2.write(reg2);
            s_feature_PE19_3.write(reg3);
            s_feature_PE20_0.write(reg0);
            s_feature_PE20_1.write(reg1);
            s_feature_PE20_2.write(reg2);
            s_feature_PE20_3.write(reg3);
            s_feature_PE21_0.write(reg0);
            s_feature_PE21_1.write(reg1);
            s_feature_PE21_2.write(reg2);
            s_feature_PE21_3.write(reg3);
            s_feature_PE22_0.write(reg0);
            s_feature_PE22_1.write(reg1);
            s_feature_PE22_2.write(reg2);
            s_feature_PE22_3.write(reg3);
            s_feature_PE23_0.write(reg0);
            s_feature_PE23_1.write(reg1);
            s_feature_PE23_2.write(reg2);
            s_feature_PE23_3.write(reg3);
            s_feature_PE24_0.write(reg0);
            s_feature_PE24_1.write(reg1);
            s_feature_PE24_2.write(reg2);
            s_feature_PE24_3.write(reg3);
            s_feature_PE25_0.write(reg0);
            s_feature_PE25_1.write(reg1);
            s_feature_PE25_2.write(reg2);
            s_feature_PE25_3.write(reg3);
            s_feature_PE26_0.write(reg0);
            s_feature_PE26_1.write(reg1);
            s_feature_PE26_2.write(reg2);
            s_feature_PE26_3.write(reg3);
            s_feature_PE27_0.write(reg0);
            s_feature_PE27_1.write(reg1);
            s_feature_PE27_2.write(reg2);
            s_feature_PE27_3.write(reg3);
            s_feature_PE28_0.write(reg0);
            s_feature_PE28_1.write(reg1);
            s_feature_PE28_2.write(reg2);
            s_feature_PE28_3.write(reg3);
            s_feature_PE29_0.write(reg0);
            s_feature_PE29_1.write(reg1);
            s_feature_PE29_2.write(reg2);
            s_feature_PE29_3.write(reg3);
            s_feature_PE30_0.write(reg0);
            s_feature_PE30_1.write(reg1);
            s_feature_PE30_2.write(reg2);
            s_feature_PE30_3.write(reg3);
            s_feature_PE31_0.write(reg0);
            s_feature_PE31_1.write(reg1);
            s_feature_PE31_2.write(reg2);
            s_feature_PE31_3.write(reg3);
            s_feature_PE32_0.write(reg0);
            s_feature_PE32_1.write(reg1);
            s_feature_PE32_2.write(reg2);
            s_feature_PE32_3.write(reg3);
            s_feature_PE33_0.write(reg0);
            s_feature_PE33_1.write(reg1);
            s_feature_PE33_2.write(reg2);
            s_feature_PE33_3.write(reg3);
            s_feature_PE34_0.write(reg0);
            s_feature_PE34_1.write(reg1);
            s_feature_PE34_2.write(reg2);
            s_feature_PE34_3.write(reg3);
            s_feature_PE35_0.write(reg0);
            s_feature_PE35_1.write(reg1);
            s_feature_PE35_2.write(reg2);
            s_feature_PE35_3.write(reg3);
            s_feature_PE36_0.write(reg0);
            s_feature_PE36_1.write(reg1);
            s_feature_PE36_2.write(reg2);
            s_feature_PE36_3.write(reg3);
            s_feature_PE37_0.write(reg0);
            s_feature_PE37_1.write(reg1);
            s_feature_PE37_2.write(reg2);
            s_feature_PE37_3.write(reg3);
            s_feature_PE38_0.write(reg0);
            s_feature_PE38_1.write(reg1);
            s_feature_PE38_2.write(reg2);
            s_feature_PE38_3.write(reg3);
            s_feature_PE39_0.write(reg0);
            s_feature_PE39_1.write(reg1);
            s_feature_PE39_2.write(reg2);
            s_feature_PE39_3.write(reg3);
            s_feature_PE40_0.write(reg0);
            s_feature_PE40_1.write(reg1);
            s_feature_PE40_2.write(reg2);
            s_feature_PE40_3.write(reg3);
            s_feature_PE41_0.write(reg0);
            s_feature_PE41_1.write(reg1);
            s_feature_PE41_2.write(reg2);
            s_feature_PE41_3.write(reg3);
            s_feature_PE42_0.write(reg0);
            s_feature_PE42_1.write(reg1);
            s_feature_PE42_2.write(reg2);
            s_feature_PE42_3.write(reg3);
            s_feature_PE43_0.write(reg0);
            s_feature_PE43_1.write(reg1);
            s_feature_PE43_2.write(reg2);
            s_feature_PE43_3.write(reg3);
            s_feature_PE44_0.write(reg0);
            s_feature_PE44_1.write(reg1);
            s_feature_PE44_2.write(reg2);
            s_feature_PE44_3.write(reg3);
            s_feature_PE45_0.write(reg0);
            s_feature_PE45_1.write(reg1);
            s_feature_PE45_2.write(reg2);
            s_feature_PE45_3.write(reg3);
            s_feature_PE46_0.write(reg0);
            s_feature_PE46_1.write(reg1);
            s_feature_PE46_2.write(reg2);
            s_feature_PE46_3.write(reg3);
            s_feature_PE47_0.write(reg0);
            s_feature_PE47_1.write(reg1);
            s_feature_PE47_2.write(reg2);
            s_feature_PE47_3.write(reg3);
            s_feature_PE48_0.write(reg0);
            s_feature_PE48_1.write(reg1);
            s_feature_PE48_2.write(reg2);
            s_feature_PE48_3.write(reg3);
            s_feature_PE49_0.write(reg0);
            s_feature_PE49_1.write(reg1);
            s_feature_PE49_2.write(reg2);
            s_feature_PE49_3.write(reg3);
            s_feature_PE50_0.write(reg0);
            s_feature_PE50_1.write(reg1);
            s_feature_PE50_2.write(reg2);
            s_feature_PE50_3.write(reg3);
            s_feature_PE51_0.write(reg0);
            s_feature_PE51_1.write(reg1);
            s_feature_PE51_2.write(reg2);
            s_feature_PE51_3.write(reg3);
            s_feature_PE52_0.write(reg0);
            s_feature_PE52_1.write(reg1);
            s_feature_PE52_2.write(reg2);
            s_feature_PE52_3.write(reg3);
            s_feature_PE53_0.write(reg0);
            s_feature_PE53_1.write(reg1);
            s_feature_PE53_2.write(reg2);
            s_feature_PE53_3.write(reg3);
            s_feature_PE54_0.write(reg0);
            s_feature_PE54_1.write(reg1);
            s_feature_PE54_2.write(reg2);
            s_feature_PE54_3.write(reg3);
            s_feature_PE55_0.write(reg0);
            s_feature_PE55_1.write(reg1);
            s_feature_PE55_2.write(reg2);
            s_feature_PE55_3.write(reg3);
            s_feature_PE56_0.write(reg0);
            s_feature_PE56_1.write(reg1);
            s_feature_PE56_2.write(reg2);
            s_feature_PE56_3.write(reg3);
            s_feature_PE57_0.write(reg0);
            s_feature_PE57_1.write(reg1);
            s_feature_PE57_2.write(reg2);
            s_feature_PE57_3.write(reg3);
            s_feature_PE58_0.write(reg0);
            s_feature_PE58_1.write(reg1);
            s_feature_PE58_2.write(reg2);
            s_feature_PE58_3.write(reg3);
            s_feature_PE59_0.write(reg0);
            s_feature_PE59_1.write(reg1);
            s_feature_PE59_2.write(reg2);
            s_feature_PE59_3.write(reg3);
            s_feature_PE60_0.write(reg0);
            s_feature_PE60_1.write(reg1);
            s_feature_PE60_2.write(reg2);
            s_feature_PE60_3.write(reg3);
            s_feature_PE61_0.write(reg0);
            s_feature_PE61_1.write(reg1);
            s_feature_PE61_2.write(reg2);
            s_feature_PE61_3.write(reg3);
            s_feature_PE62_0.write(reg0);
            s_feature_PE62_1.write(reg1);
            s_feature_PE62_2.write(reg2);
            s_feature_PE62_3.write(reg3);
            s_feature_PE63_0.write(reg0);
            s_feature_PE63_1.write(reg1);
            s_feature_PE63_2.write(reg2);
            s_feature_PE63_3.write(reg3);
            s_feature_PE64_0.write(reg0);
            s_feature_PE64_1.write(reg1);
            s_feature_PE64_2.write(reg2);
            s_feature_PE64_3.write(reg3);
            s_feature_PE65_0.write(reg0);
            s_feature_PE65_1.write(reg1);
            s_feature_PE65_2.write(reg2);
            s_feature_PE65_3.write(reg3);
            s_feature_PE66_0.write(reg0);
            s_feature_PE66_1.write(reg1);
            s_feature_PE66_2.write(reg2);
            s_feature_PE66_3.write(reg3);
            s_feature_PE67_0.write(reg0);
            s_feature_PE67_1.write(reg1);
            s_feature_PE67_2.write(reg2);
            s_feature_PE67_3.write(reg3);
            s_feature_PE68_0.write(reg0);
            s_feature_PE68_1.write(reg1);
            s_feature_PE68_2.write(reg2);
            s_feature_PE68_3.write(reg3);
            s_feature_PE69_0.write(reg0);
            s_feature_PE69_1.write(reg1);
            s_feature_PE69_2.write(reg2);
            s_feature_PE69_3.write(reg3);
            s_feature_PE70_0.write(reg0);
            s_feature_PE70_1.write(reg1);
            s_feature_PE70_2.write(reg2);
            s_feature_PE70_3.write(reg3);
            s_feature_PE71_0.write(reg0);
            s_feature_PE71_1.write(reg1);
            s_feature_PE71_2.write(reg2);
            s_feature_PE71_3.write(reg3);
            s_feature_PE72_0.write(reg0);
            s_feature_PE72_1.write(reg1);
            s_feature_PE72_2.write(reg2);
            s_feature_PE72_3.write(reg3);
            s_feature_PE73_0.write(reg0);
            s_feature_PE73_1.write(reg1);
            s_feature_PE73_2.write(reg2);
            s_feature_PE73_3.write(reg3);
            s_feature_PE74_0.write(reg0);
            s_feature_PE74_1.write(reg1);
            s_feature_PE74_2.write(reg2);
            s_feature_PE74_3.write(reg3);
            s_feature_PE75_0.write(reg0);
            s_feature_PE75_1.write(reg1);
            s_feature_PE75_2.write(reg2);
            s_feature_PE75_3.write(reg3);
            s_feature_PE76_0.write(reg0);
            s_feature_PE76_1.write(reg1);
            s_feature_PE76_2.write(reg2);
            s_feature_PE76_3.write(reg3);
            s_feature_PE77_0.write(reg0);
            s_feature_PE77_1.write(reg1);
            s_feature_PE77_2.write(reg2);
            s_feature_PE77_3.write(reg3);
            s_feature_PE78_0.write(reg0);
            s_feature_PE78_1.write(reg1);
            s_feature_PE78_2.write(reg2);
            s_feature_PE78_3.write(reg3);
            s_feature_PE79_0.write(reg0);
            s_feature_PE79_1.write(reg1);
            s_feature_PE79_2.write(reg2);
            s_feature_PE79_3.write(reg3);
            s_feature_PE80_0.write(reg0);
            s_feature_PE80_1.write(reg1);
            s_feature_PE80_2.write(reg2);
            s_feature_PE80_3.write(reg3);
            s_feature_PE81_0.write(reg0);
            s_feature_PE81_1.write(reg1);
            s_feature_PE81_2.write(reg2);
            s_feature_PE81_3.write(reg3);
            s_feature_PE82_0.write(reg0);
            s_feature_PE82_1.write(reg1);
            s_feature_PE82_2.write(reg2);
            s_feature_PE82_3.write(reg3);
            s_feature_PE83_0.write(reg0);
            s_feature_PE83_1.write(reg1);
            s_feature_PE83_2.write(reg2);
            s_feature_PE83_3.write(reg3);
            s_feature_PE84_0.write(reg0);
            s_feature_PE84_1.write(reg1);
            s_feature_PE84_2.write(reg2);
            s_feature_PE84_3.write(reg3);
            s_feature_PE85_0.write(reg0);
            s_feature_PE85_1.write(reg1);
            s_feature_PE85_2.write(reg2);
            s_feature_PE85_3.write(reg3);
            s_feature_PE86_0.write(reg0);
            s_feature_PE86_1.write(reg1);
            s_feature_PE86_2.write(reg2);
            s_feature_PE86_3.write(reg3);
            s_feature_PE87_0.write(reg0);
            s_feature_PE87_1.write(reg1);
            s_feature_PE87_2.write(reg2);
            s_feature_PE87_3.write(reg3);
            s_feature_PE88_0.write(reg0);
            s_feature_PE88_1.write(reg1);
            s_feature_PE88_2.write(reg2);
            s_feature_PE88_3.write(reg3);
            s_feature_PE89_0.write(reg0);
            s_feature_PE89_1.write(reg1);
            s_feature_PE89_2.write(reg2);
            s_feature_PE89_3.write(reg3);
            s_feature_PE90_0.write(reg0);
            s_feature_PE90_1.write(reg1);
            s_feature_PE90_2.write(reg2);
            s_feature_PE90_3.write(reg3);
            s_feature_PE91_0.write(reg0);
            s_feature_PE91_1.write(reg1);
            s_feature_PE91_2.write(reg2);
            s_feature_PE91_3.write(reg3);
            s_feature_PE92_0.write(reg0);
            s_feature_PE92_1.write(reg1);
            s_feature_PE92_2.write(reg2);
            s_feature_PE92_3.write(reg3);
            s_feature_PE93_0.write(reg0);
            s_feature_PE93_1.write(reg1);
            s_feature_PE93_2.write(reg2);
            s_feature_PE93_3.write(reg3);
            s_feature_PE94_0.write(reg0);
            s_feature_PE94_1.write(reg1);
            s_feature_PE94_2.write(reg2);
            s_feature_PE94_3.write(reg3);
            s_feature_PE95_0.write(reg0);
            s_feature_PE95_1.write(reg1);
            s_feature_PE95_2.write(reg2);
            s_feature_PE95_3.write(reg3);
            s_feature_PE96_0.write(reg0);
            s_feature_PE96_1.write(reg1);
            s_feature_PE96_2.write(reg2);
            s_feature_PE96_3.write(reg3);
            s_feature_PE97_0.write(reg0);
            s_feature_PE97_1.write(reg1);
            s_feature_PE97_2.write(reg2);
            s_feature_PE97_3.write(reg3);
            s_feature_PE98_0.write(reg0);
            s_feature_PE98_1.write(reg1);
            s_feature_PE98_2.write(reg2);
            s_feature_PE98_3.write(reg3);
            s_feature_PE99_0.write(reg0);
            s_feature_PE99_1.write(reg1);
            s_feature_PE99_2.write(reg2);
            s_feature_PE99_3.write(reg3);
            s_feature_PE100_0.write(reg0);
            s_feature_PE100_1.write(reg1);
            s_feature_PE100_2.write(reg2);
            s_feature_PE100_3.write(reg3);
            s_feature_PE101_0.write(reg0);
            s_feature_PE101_1.write(reg1);
            s_feature_PE101_2.write(reg2);
            s_feature_PE101_3.write(reg3);
            s_feature_PE102_0.write(reg0);
            s_feature_PE102_1.write(reg1);
            s_feature_PE102_2.write(reg2);
            s_feature_PE102_3.write(reg3);
            s_feature_PE103_0.write(reg0);
            s_feature_PE103_1.write(reg1);
            s_feature_PE103_2.write(reg2);
            s_feature_PE103_3.write(reg3);
            s_feature_PE104_0.write(reg0);
            s_feature_PE104_1.write(reg1);
            s_feature_PE104_2.write(reg2);
            s_feature_PE104_3.write(reg3);
            s_feature_PE105_0.write(reg0);
            s_feature_PE105_1.write(reg1);
            s_feature_PE105_2.write(reg2);
            s_feature_PE105_3.write(reg3);
            s_feature_PE106_0.write(reg0);
            s_feature_PE106_1.write(reg1);
            s_feature_PE106_2.write(reg2);
            s_feature_PE106_3.write(reg3);
            s_feature_PE107_0.write(reg0);
            s_feature_PE107_1.write(reg1);
            s_feature_PE107_2.write(reg2);
            s_feature_PE107_3.write(reg3);
            s_feature_PE108_0.write(reg0);
            s_feature_PE108_1.write(reg1);
            s_feature_PE108_2.write(reg2);
            s_feature_PE108_3.write(reg3);
            s_feature_PE109_0.write(reg0);
            s_feature_PE109_1.write(reg1);
            s_feature_PE109_2.write(reg2);
            s_feature_PE109_3.write(reg3);
            s_feature_PE110_0.write(reg0);
            s_feature_PE110_1.write(reg1);
            s_feature_PE110_2.write(reg2);
            s_feature_PE110_3.write(reg3);
            s_feature_PE111_0.write(reg0);
            s_feature_PE111_1.write(reg1);
            s_feature_PE111_2.write(reg2);
            s_feature_PE111_3.write(reg3);
            s_feature_PE112_0.write(reg0);
            s_feature_PE112_1.write(reg1);
            s_feature_PE112_2.write(reg2);
            s_feature_PE112_3.write(reg3);
            s_feature_PE113_0.write(reg0);
            s_feature_PE113_1.write(reg1);
            s_feature_PE113_2.write(reg2);
            s_feature_PE113_3.write(reg3);
            s_feature_PE114_0.write(reg0);
            s_feature_PE114_1.write(reg1);
            s_feature_PE114_2.write(reg2);
            s_feature_PE114_3.write(reg3);
            s_feature_PE115_0.write(reg0);
            s_feature_PE115_1.write(reg1);
            s_feature_PE115_2.write(reg2);
            s_feature_PE115_3.write(reg3);
            s_feature_PE116_0.write(reg0);
            s_feature_PE116_1.write(reg1);
            s_feature_PE116_2.write(reg2);
            s_feature_PE116_3.write(reg3);
            s_feature_PE117_0.write(reg0);
            s_feature_PE117_1.write(reg1);
            s_feature_PE117_2.write(reg2);
            s_feature_PE117_3.write(reg3);
            s_feature_PE118_0.write(reg0);
            s_feature_PE118_1.write(reg1);
            s_feature_PE118_2.write(reg2);
            s_feature_PE118_3.write(reg3);
            s_feature_PE119_0.write(reg0);
            s_feature_PE119_1.write(reg1);
            s_feature_PE119_2.write(reg2);
            s_feature_PE119_3.write(reg3);
            s_feature_PE120_0.write(reg0);
            s_feature_PE120_1.write(reg1);
            s_feature_PE120_2.write(reg2);
            s_feature_PE120_3.write(reg3);
            s_feature_PE121_0.write(reg0);
            s_feature_PE121_1.write(reg1);
            s_feature_PE121_2.write(reg2);
            s_feature_PE121_3.write(reg3);
            s_feature_PE122_0.write(reg0);
            s_feature_PE122_1.write(reg1);
            s_feature_PE122_2.write(reg2);
            s_feature_PE122_3.write(reg3);
            s_feature_PE123_0.write(reg0);
            s_feature_PE123_1.write(reg1);
            s_feature_PE123_2.write(reg2);
            s_feature_PE123_3.write(reg3);
            s_feature_PE124_0.write(reg0);
            s_feature_PE124_1.write(reg1);
            s_feature_PE124_2.write(reg2);
            s_feature_PE124_3.write(reg3);
            s_feature_PE125_0.write(reg0);
            s_feature_PE125_1.write(reg1);
            s_feature_PE125_2.write(reg2);
            s_feature_PE125_3.write(reg3);
            s_feature_PE126_0.write(reg0);
            s_feature_PE126_1.write(reg1);
            s_feature_PE126_2.write(reg2);
            s_feature_PE126_3.write(reg3);
            s_feature_PE127_0.write(reg0);
            s_feature_PE127_1.write(reg1);
            s_feature_PE127_2.write(reg2);
            s_feature_PE127_3.write(reg3);
            s_feature_PE128_0.write(reg0);
            s_feature_PE128_1.write(reg1);
            s_feature_PE128_2.write(reg2);
            s_feature_PE128_3.write(reg3);
            s_feature_PE129_0.write(reg0);
            s_feature_PE129_1.write(reg1);
            s_feature_PE129_2.write(reg2);
            s_feature_PE129_3.write(reg3);
            s_feature_PE130_0.write(reg0);
            s_feature_PE130_1.write(reg1);
            s_feature_PE130_2.write(reg2);
            s_feature_PE130_3.write(reg3);
            s_feature_PE131_0.write(reg0);
            s_feature_PE131_1.write(reg1);
            s_feature_PE131_2.write(reg2);
            s_feature_PE131_3.write(reg3);
            s_feature_PE132_0.write(reg0);
            s_feature_PE132_1.write(reg1);
            s_feature_PE132_2.write(reg2);
            s_feature_PE132_3.write(reg3);
            s_feature_PE133_0.write(reg0);
            s_feature_PE133_1.write(reg1);
            s_feature_PE133_2.write(reg2);
            s_feature_PE133_3.write(reg3);
            s_feature_PE134_0.write(reg0);
            s_feature_PE134_1.write(reg1);
            s_feature_PE134_2.write(reg2);
            s_feature_PE134_3.write(reg3);
            s_feature_PE135_0.write(reg0);
            s_feature_PE135_1.write(reg1);
            s_feature_PE135_2.write(reg2);
            s_feature_PE135_3.write(reg3);
            s_feature_PE136_0.write(reg0);
            s_feature_PE136_1.write(reg1);
            s_feature_PE136_2.write(reg2);
            s_feature_PE136_3.write(reg3);
            s_feature_PE137_0.write(reg0);
            s_feature_PE137_1.write(reg1);
            s_feature_PE137_2.write(reg2);
            s_feature_PE137_3.write(reg3);
            s_feature_PE138_0.write(reg0);
            s_feature_PE138_1.write(reg1);
            s_feature_PE138_2.write(reg2);
            s_feature_PE138_3.write(reg3);
            s_feature_PE139_0.write(reg0);
            s_feature_PE139_1.write(reg1);
            s_feature_PE139_2.write(reg2);
            s_feature_PE139_3.write(reg3);
            s_feature_PE140_0.write(reg0);
            s_feature_PE140_1.write(reg1);
            s_feature_PE140_2.write(reg2);
            s_feature_PE140_3.write(reg3);
            s_feature_PE141_0.write(reg0);
            s_feature_PE141_1.write(reg1);
            s_feature_PE141_2.write(reg2);
            s_feature_PE141_3.write(reg3);
            s_feature_PE142_0.write(reg0);
            s_feature_PE142_1.write(reg1);
            s_feature_PE142_2.write(reg2);
            s_feature_PE142_3.write(reg3);
            s_feature_PE143_0.write(reg0);
            s_feature_PE143_1.write(reg1);
            s_feature_PE143_2.write(reg2);
            s_feature_PE143_3.write(reg3);
            s_feature_PE144_0.write(reg0);
            s_feature_PE144_1.write(reg1);
            s_feature_PE144_2.write(reg2);
            s_feature_PE144_3.write(reg3);
            s_feature_PE145_0.write(reg0);
            s_feature_PE145_1.write(reg1);
            s_feature_PE145_2.write(reg2);
            s_feature_PE145_3.write(reg3);
            s_feature_PE146_0.write(reg0);
            s_feature_PE146_1.write(reg1);
            s_feature_PE146_2.write(reg2);
            s_feature_PE146_3.write(reg3);
            s_feature_PE147_0.write(reg0);
            s_feature_PE147_1.write(reg1);
            s_feature_PE147_2.write(reg2);
            s_feature_PE147_3.write(reg3);
            s_feature_PE148_0.write(reg0);
            s_feature_PE148_1.write(reg1);
            s_feature_PE148_2.write(reg2);
            s_feature_PE148_3.write(reg3);
            s_feature_PE149_0.write(reg0);
            s_feature_PE149_1.write(reg1);
            s_feature_PE149_2.write(reg2);
            s_feature_PE149_3.write(reg3);
            s_feature_PE150_0.write(reg0);
            s_feature_PE150_1.write(reg1);
            s_feature_PE150_2.write(reg2);
            s_feature_PE150_3.write(reg3);
            s_feature_PE151_0.write(reg0);
            s_feature_PE151_1.write(reg1);
            s_feature_PE151_2.write(reg2);
            s_feature_PE151_3.write(reg3);
            s_feature_PE152_0.write(reg0);
            s_feature_PE152_1.write(reg1);
            s_feature_PE152_2.write(reg2);
            s_feature_PE152_3.write(reg3);
            s_feature_PE153_0.write(reg0);
            s_feature_PE153_1.write(reg1);
            s_feature_PE153_2.write(reg2);
            s_feature_PE153_3.write(reg3);
            s_feature_PE154_0.write(reg0);
            s_feature_PE154_1.write(reg1);
            s_feature_PE154_2.write(reg2);
            s_feature_PE154_3.write(reg3);
            s_feature_PE155_0.write(reg0);
            s_feature_PE155_1.write(reg1);
            s_feature_PE155_2.write(reg2);
            s_feature_PE155_3.write(reg3);
            s_feature_PE156_0.write(reg0);
            s_feature_PE156_1.write(reg1);
            s_feature_PE156_2.write(reg2);
            s_feature_PE156_3.write(reg3);
            s_feature_PE157_0.write(reg0);
            s_feature_PE157_1.write(reg1);
            s_feature_PE157_2.write(reg2);
            s_feature_PE157_3.write(reg3);
            s_feature_PE158_0.write(reg0);
            s_feature_PE158_1.write(reg1);
            s_feature_PE158_2.write(reg2);
            s_feature_PE158_3.write(reg3);
            s_feature_PE159_0.write(reg0);
            s_feature_PE159_1.write(reg1);
            s_feature_PE159_2.write(reg2);
            s_feature_PE159_3.write(reg3);
            s_feature_PE160_0.write(reg0);
            s_feature_PE160_1.write(reg1);
            s_feature_PE160_2.write(reg2);
            s_feature_PE160_3.write(reg3);
            s_feature_PE161_0.write(reg0);
            s_feature_PE161_1.write(reg1);
            s_feature_PE161_2.write(reg2);
            s_feature_PE161_3.write(reg3);
            s_feature_PE162_0.write(reg0);
            s_feature_PE162_1.write(reg1);
            s_feature_PE162_2.write(reg2);
            s_feature_PE162_3.write(reg3);
            s_feature_PE163_0.write(reg0);
            s_feature_PE163_1.write(reg1);
            s_feature_PE163_2.write(reg2);
            s_feature_PE163_3.write(reg3);
            s_feature_PE164_0.write(reg0);
            s_feature_PE164_1.write(reg1);
            s_feature_PE164_2.write(reg2);
            s_feature_PE164_3.write(reg3);
            s_feature_PE165_0.write(reg0);
            s_feature_PE165_1.write(reg1);
            s_feature_PE165_2.write(reg2);
            s_feature_PE165_3.write(reg3);
            s_feature_PE166_0.write(reg0);
            s_feature_PE166_1.write(reg1);
            s_feature_PE166_2.write(reg2);
            s_feature_PE166_3.write(reg3);
            s_feature_PE167_0.write(reg0);
            s_feature_PE167_1.write(reg1);
            s_feature_PE167_2.write(reg2);
            s_feature_PE167_3.write(reg3);
            s_feature_PE168_0.write(reg0);
            s_feature_PE168_1.write(reg1);
            s_feature_PE168_2.write(reg2);
            s_feature_PE168_3.write(reg3);
            s_feature_PE169_0.write(reg0);
            s_feature_PE169_1.write(reg1);
            s_feature_PE169_2.write(reg2);
            s_feature_PE169_3.write(reg3);
            s_feature_PE170_0.write(reg0);
            s_feature_PE170_1.write(reg1);
            s_feature_PE170_2.write(reg2);
            s_feature_PE170_3.write(reg3);
            s_feature_PE171_0.write(reg0);
            s_feature_PE171_1.write(reg1);
            s_feature_PE171_2.write(reg2);
            s_feature_PE171_3.write(reg3);
            s_feature_PE172_0.write(reg0);
            s_feature_PE172_1.write(reg1);
            s_feature_PE172_2.write(reg2);
            s_feature_PE172_3.write(reg3);
            s_feature_PE173_0.write(reg0);
            s_feature_PE173_1.write(reg1);
            s_feature_PE173_2.write(reg2);
            s_feature_PE173_3.write(reg3);
            s_feature_PE174_0.write(reg0);
            s_feature_PE174_1.write(reg1);
            s_feature_PE174_2.write(reg2);
            s_feature_PE174_3.write(reg3);
            s_feature_PE175_0.write(reg0);
            s_feature_PE175_1.write(reg1);
            s_feature_PE175_2.write(reg2);
            s_feature_PE175_3.write(reg3);
            s_feature_PE176_0.write(reg0);
            s_feature_PE176_1.write(reg1);
            s_feature_PE176_2.write(reg2);
            s_feature_PE176_3.write(reg3);
            s_feature_PE177_0.write(reg0);
            s_feature_PE177_1.write(reg1);
            s_feature_PE177_2.write(reg2);
            s_feature_PE177_3.write(reg3);
            s_feature_PE178_0.write(reg0);
            s_feature_PE178_1.write(reg1);
            s_feature_PE178_2.write(reg2);
            s_feature_PE178_3.write(reg3);
            s_feature_PE179_0.write(reg0);
            s_feature_PE179_1.write(reg1);
            s_feature_PE179_2.write(reg2);
            s_feature_PE179_3.write(reg3);
            s_feature_PE180_0.write(reg0);
            s_feature_PE180_1.write(reg1);
            s_feature_PE180_2.write(reg2);
            s_feature_PE180_3.write(reg3);
            s_feature_PE181_0.write(reg0);
            s_feature_PE181_1.write(reg1);
            s_feature_PE181_2.write(reg2);
            s_feature_PE181_3.write(reg3);
            s_feature_PE182_0.write(reg0);
            s_feature_PE182_1.write(reg1);
            s_feature_PE182_2.write(reg2);
            s_feature_PE182_3.write(reg3);
            s_feature_PE183_0.write(reg0);
            s_feature_PE183_1.write(reg1);
            s_feature_PE183_2.write(reg2);
            s_feature_PE183_3.write(reg3);
            s_feature_PE184_0.write(reg0);
            s_feature_PE184_1.write(reg1);
            s_feature_PE184_2.write(reg2);
            s_feature_PE184_3.write(reg3);
            s_feature_PE185_0.write(reg0);
            s_feature_PE185_1.write(reg1);
            s_feature_PE185_2.write(reg2);
            s_feature_PE185_3.write(reg3);
            s_feature_PE186_0.write(reg0);
            s_feature_PE186_1.write(reg1);
            s_feature_PE186_2.write(reg2);
            s_feature_PE186_3.write(reg3);
            s_feature_PE187_0.write(reg0);
            s_feature_PE187_1.write(reg1);
            s_feature_PE187_2.write(reg2);
            s_feature_PE187_3.write(reg3);
            s_feature_PE188_0.write(reg0);
            s_feature_PE188_1.write(reg1);
            s_feature_PE188_2.write(reg2);
            s_feature_PE188_3.write(reg3);
            s_feature_PE189_0.write(reg0);
            s_feature_PE189_1.write(reg1);
            s_feature_PE189_2.write(reg2);
            s_feature_PE189_3.write(reg3);
            s_feature_PE190_0.write(reg0);
            s_feature_PE190_1.write(reg1);
            s_feature_PE190_2.write(reg2);
            s_feature_PE190_3.write(reg3);
            s_feature_PE191_0.write(reg0);
            s_feature_PE191_1.write(reg1);
            s_feature_PE191_2.write(reg2);
            s_feature_PE191_3.write(reg3);
            s_feature_PE192_0.write(reg0);
            s_feature_PE192_1.write(reg1);
            s_feature_PE192_2.write(reg2);
            s_feature_PE192_3.write(reg3);
            s_feature_PE193_0.write(reg0);
            s_feature_PE193_1.write(reg1);
            s_feature_PE193_2.write(reg2);
            s_feature_PE193_3.write(reg3);
            s_feature_PE194_0.write(reg0);
            s_feature_PE194_1.write(reg1);
            s_feature_PE194_2.write(reg2);
            s_feature_PE194_3.write(reg3);
            s_feature_PE195_0.write(reg0);
            s_feature_PE195_1.write(reg1);
            s_feature_PE195_2.write(reg2);
            s_feature_PE195_3.write(reg3);
            s_feature_PE196_0.write(reg0);
            s_feature_PE196_1.write(reg1);
            s_feature_PE196_2.write(reg2);
            s_feature_PE196_3.write(reg3);
            s_feature_PE197_0.write(reg0);
            s_feature_PE197_1.write(reg1);
            s_feature_PE197_2.write(reg2);
            s_feature_PE197_3.write(reg3);
            s_feature_PE198_0.write(reg0);
            s_feature_PE198_1.write(reg1);
            s_feature_PE198_2.write(reg2);
            s_feature_PE198_3.write(reg3);
            s_feature_PE199_0.write(reg0);
            s_feature_PE199_1.write(reg1);
            s_feature_PE199_2.write(reg2);
            s_feature_PE199_3.write(reg3);
            s_feature_PE200_0.write(reg0);
            s_feature_PE200_1.write(reg1);
            s_feature_PE200_2.write(reg2);
            s_feature_PE200_3.write(reg3);
            s_feature_PE201_0.write(reg0);
            s_feature_PE201_1.write(reg1);
            s_feature_PE201_2.write(reg2);
            s_feature_PE201_3.write(reg3);
            s_feature_PE202_0.write(reg0);
            s_feature_PE202_1.write(reg1);
            s_feature_PE202_2.write(reg2);
            s_feature_PE202_3.write(reg3);
            s_feature_PE203_0.write(reg0);
            s_feature_PE203_1.write(reg1);
            s_feature_PE203_2.write(reg2);
            s_feature_PE203_3.write(reg3);
            s_feature_PE204_0.write(reg0);
            s_feature_PE204_1.write(reg1);
            s_feature_PE204_2.write(reg2);
            s_feature_PE204_3.write(reg3);
            s_feature_PE205_0.write(reg0);
            s_feature_PE205_1.write(reg1);
            s_feature_PE205_2.write(reg2);
            s_feature_PE205_3.write(reg3);
            s_feature_PE206_0.write(reg0);
            s_feature_PE206_1.write(reg1);
            s_feature_PE206_2.write(reg2);
            s_feature_PE206_3.write(reg3);
            s_feature_PE207_0.write(reg0);
            s_feature_PE207_1.write(reg1);
            s_feature_PE207_2.write(reg2);
            s_feature_PE207_3.write(reg3);
            s_feature_PE208_0.write(reg0);
            s_feature_PE208_1.write(reg1);
            s_feature_PE208_2.write(reg2);
            s_feature_PE208_3.write(reg3);
            s_feature_PE209_0.write(reg0);
            s_feature_PE209_1.write(reg1);
            s_feature_PE209_2.write(reg2);
            s_feature_PE209_3.write(reg3);
            s_feature_PE210_0.write(reg0);
            s_feature_PE210_1.write(reg1);
            s_feature_PE210_2.write(reg2);
            s_feature_PE210_3.write(reg3);
            s_feature_PE211_0.write(reg0);
            s_feature_PE211_1.write(reg1);
            s_feature_PE211_2.write(reg2);
            s_feature_PE211_3.write(reg3);
            s_feature_PE212_0.write(reg0);
            s_feature_PE212_1.write(reg1);
            s_feature_PE212_2.write(reg2);
            s_feature_PE212_3.write(reg3);
            s_feature_PE213_0.write(reg0);
            s_feature_PE213_1.write(reg1);
            s_feature_PE213_2.write(reg2);
            s_feature_PE213_3.write(reg3);
            s_feature_PE214_0.write(reg0);
            s_feature_PE214_1.write(reg1);
            s_feature_PE214_2.write(reg2);
            s_feature_PE214_3.write(reg3);
            s_feature_PE215_0.write(reg0);
            s_feature_PE215_1.write(reg1);
            s_feature_PE215_2.write(reg2);
            s_feature_PE215_3.write(reg3);
            s_feature_PE216_0.write(reg0);
            s_feature_PE216_1.write(reg1);
            s_feature_PE216_2.write(reg2);
            s_feature_PE216_3.write(reg3);
            s_feature_PE217_0.write(reg0);
            s_feature_PE217_1.write(reg1);
            s_feature_PE217_2.write(reg2);
            s_feature_PE217_3.write(reg3);
            s_feature_PE218_0.write(reg0);
            s_feature_PE218_1.write(reg1);
            s_feature_PE218_2.write(reg2);
            s_feature_PE218_3.write(reg3);
            s_feature_PE219_0.write(reg0);
            s_feature_PE219_1.write(reg1);
            s_feature_PE219_2.write(reg2);
            s_feature_PE219_3.write(reg3);
            s_feature_PE220_0.write(reg0);
            s_feature_PE220_1.write(reg1);
            s_feature_PE220_2.write(reg2);
            s_feature_PE220_3.write(reg3);
            s_feature_PE221_0.write(reg0);
            s_feature_PE221_1.write(reg1);
            s_feature_PE221_2.write(reg2);
            s_feature_PE221_3.write(reg3);
            s_feature_PE222_0.write(reg0);
            s_feature_PE222_1.write(reg1);
            s_feature_PE222_2.write(reg2);
            s_feature_PE222_3.write(reg3);
            s_feature_PE223_0.write(reg0);
            s_feature_PE223_1.write(reg1);
            s_feature_PE223_2.write(reg2);
            s_feature_PE223_3.write(reg3);
            s_feature_PE224_0.write(reg0);
            s_feature_PE224_1.write(reg1);
            s_feature_PE224_2.write(reg2);
            s_feature_PE224_3.write(reg3);
            s_feature_PE225_0.write(reg0);
            s_feature_PE225_1.write(reg1);
            s_feature_PE225_2.write(reg2);
            s_feature_PE225_3.write(reg3);
            s_feature_PE226_0.write(reg0);
            s_feature_PE226_1.write(reg1);
            s_feature_PE226_2.write(reg2);
            s_feature_PE226_3.write(reg3);
            s_feature_PE227_0.write(reg0);
            s_feature_PE227_1.write(reg1);
            s_feature_PE227_2.write(reg2);
            s_feature_PE227_3.write(reg3);
            s_feature_PE228_0.write(reg0);
            s_feature_PE228_1.write(reg1);
            s_feature_PE228_2.write(reg2);
            s_feature_PE228_3.write(reg3);
            s_feature_PE229_0.write(reg0);
            s_feature_PE229_1.write(reg1);
            s_feature_PE229_2.write(reg2);
            s_feature_PE229_3.write(reg3);
            s_feature_PE230_0.write(reg0);
            s_feature_PE230_1.write(reg1);
            s_feature_PE230_2.write(reg2);
            s_feature_PE230_3.write(reg3);
            s_feature_PE231_0.write(reg0);
            s_feature_PE231_1.write(reg1);
            s_feature_PE231_2.write(reg2);
            s_feature_PE231_3.write(reg3);
            s_feature_PE232_0.write(reg0);
            s_feature_PE232_1.write(reg1);
            s_feature_PE232_2.write(reg2);
            s_feature_PE232_3.write(reg3);
            s_feature_PE233_0.write(reg0);
            s_feature_PE233_1.write(reg1);
            s_feature_PE233_2.write(reg2);
            s_feature_PE233_3.write(reg3);
            s_feature_PE234_0.write(reg0);
            s_feature_PE234_1.write(reg1);
            s_feature_PE234_2.write(reg2);
            s_feature_PE234_3.write(reg3);
            s_feature_PE235_0.write(reg0);
            s_feature_PE235_1.write(reg1);
            s_feature_PE235_2.write(reg2);
            s_feature_PE235_3.write(reg3);
            s_feature_PE236_0.write(reg0);
            s_feature_PE236_1.write(reg1);
            s_feature_PE236_2.write(reg2);
            s_feature_PE236_3.write(reg3);
            s_feature_PE237_0.write(reg0);
            s_feature_PE237_1.write(reg1);
            s_feature_PE237_2.write(reg2);
            s_feature_PE237_3.write(reg3);
            s_feature_PE238_0.write(reg0);
            s_feature_PE238_1.write(reg1);
            s_feature_PE238_2.write(reg2);
            s_feature_PE238_3.write(reg3);
            s_feature_PE239_0.write(reg0);
            s_feature_PE239_1.write(reg1);
            s_feature_PE239_2.write(reg2);
            s_feature_PE239_3.write(reg3);
            s_feature_PE240_0.write(reg0);
            s_feature_PE240_1.write(reg1);
            s_feature_PE240_2.write(reg2);
            s_feature_PE240_3.write(reg3);
            s_feature_PE241_0.write(reg0);
            s_feature_PE241_1.write(reg1);
            s_feature_PE241_2.write(reg2);
            s_feature_PE241_3.write(reg3);
            s_feature_PE242_0.write(reg0);
            s_feature_PE242_1.write(reg1);
            s_feature_PE242_2.write(reg2);
            s_feature_PE242_3.write(reg3);
            s_feature_PE243_0.write(reg0);
            s_feature_PE243_1.write(reg1);
            s_feature_PE243_2.write(reg2);
            s_feature_PE243_3.write(reg3);
            s_feature_PE244_0.write(reg0);
            s_feature_PE244_1.write(reg1);
            s_feature_PE244_2.write(reg2);
            s_feature_PE244_3.write(reg3);
            s_feature_PE245_0.write(reg0);
            s_feature_PE245_1.write(reg1);
            s_feature_PE245_2.write(reg2);
            s_feature_PE245_3.write(reg3);
            s_feature_PE246_0.write(reg0);
            s_feature_PE246_1.write(reg1);
            s_feature_PE246_2.write(reg2);
            s_feature_PE246_3.write(reg3);
            s_feature_PE247_0.write(reg0);
            s_feature_PE247_1.write(reg1);
            s_feature_PE247_2.write(reg2);
            s_feature_PE247_3.write(reg3);
            s_feature_PE248_0.write(reg0);
            s_feature_PE248_1.write(reg1);
            s_feature_PE248_2.write(reg2);
            s_feature_PE248_3.write(reg3);
            s_feature_PE249_0.write(reg0);
            s_feature_PE249_1.write(reg1);
            s_feature_PE249_2.write(reg2);
            s_feature_PE249_3.write(reg3);
            s_feature_PE250_0.write(reg0);
            s_feature_PE250_1.write(reg1);
            s_feature_PE250_2.write(reg2);
            s_feature_PE250_3.write(reg3);
            s_feature_PE251_0.write(reg0);
            s_feature_PE251_1.write(reg1);
            s_feature_PE251_2.write(reg2);
            s_feature_PE251_3.write(reg3);
            s_feature_PE252_0.write(reg0);
            s_feature_PE252_1.write(reg1);
            s_feature_PE252_2.write(reg2);
            s_feature_PE252_3.write(reg3);
            s_feature_PE253_0.write(reg0);
            s_feature_PE253_1.write(reg1);
            s_feature_PE253_2.write(reg2);
            s_feature_PE253_3.write(reg3);
            s_feature_PE254_0.write(reg0);
            s_feature_PE254_1.write(reg1);
            s_feature_PE254_2.write(reg2);
            s_feature_PE254_3.write(reg3);
            s_feature_PE255_0.write(reg0);
            s_feature_PE255_1.write(reg1);
            s_feature_PE255_2.write(reg2);
            s_feature_PE255_3.write(reg3);
            s_feature_PE256_0.write(reg0);
            s_feature_PE256_1.write(reg1);
            s_feature_PE256_2.write(reg2);
            s_feature_PE256_3.write(reg3);
            s_feature_PE257_0.write(reg0);
            s_feature_PE257_1.write(reg1);
            s_feature_PE257_2.write(reg2);
            s_feature_PE257_3.write(reg3);
            s_feature_PE258_0.write(reg0);
            s_feature_PE258_1.write(reg1);
            s_feature_PE258_2.write(reg2);
            s_feature_PE258_3.write(reg3);
            s_feature_PE259_0.write(reg0);
            s_feature_PE259_1.write(reg1);
            s_feature_PE259_2.write(reg2);
            s_feature_PE259_3.write(reg3);
            s_feature_PE260_0.write(reg0);
            s_feature_PE260_1.write(reg1);
            s_feature_PE260_2.write(reg2);
            s_feature_PE260_3.write(reg3);
            s_feature_PE261_0.write(reg0);
            s_feature_PE261_1.write(reg1);
            s_feature_PE261_2.write(reg2);
            s_feature_PE261_3.write(reg3);
            s_feature_PE262_0.write(reg0);
            s_feature_PE262_1.write(reg1);
            s_feature_PE262_2.write(reg2);
            s_feature_PE262_3.write(reg3);
            s_feature_PE263_0.write(reg0);
            s_feature_PE263_1.write(reg1);
            s_feature_PE263_2.write(reg2);
            s_feature_PE263_3.write(reg3);
            s_feature_PE264_0.write(reg0);
            s_feature_PE264_1.write(reg1);
            s_feature_PE264_2.write(reg2);
            s_feature_PE264_3.write(reg3);
            s_feature_PE265_0.write(reg0);
            s_feature_PE265_1.write(reg1);
            s_feature_PE265_2.write(reg2);
            s_feature_PE265_3.write(reg3);
            s_feature_PE266_0.write(reg0);
            s_feature_PE266_1.write(reg1);
            s_feature_PE266_2.write(reg2);
            s_feature_PE266_3.write(reg3);
            s_feature_PE267_0.write(reg0);
            s_feature_PE267_1.write(reg1);
            s_feature_PE267_2.write(reg2);
            s_feature_PE267_3.write(reg3);
            s_feature_PE268_0.write(reg0);
            s_feature_PE268_1.write(reg1);
            s_feature_PE268_2.write(reg2);
            s_feature_PE268_3.write(reg3);
            s_feature_PE269_0.write(reg0);
            s_feature_PE269_1.write(reg1);
            s_feature_PE269_2.write(reg2);
            s_feature_PE269_3.write(reg3);
            s_feature_PE270_0.write(reg0);
            s_feature_PE270_1.write(reg1);
            s_feature_PE270_2.write(reg2);
            s_feature_PE270_3.write(reg3);
            s_feature_PE271_0.write(reg0);
            s_feature_PE271_1.write(reg1);
            s_feature_PE271_2.write(reg2);
            s_feature_PE271_3.write(reg3);
            s_feature_PE272_0.write(reg0);
            s_feature_PE272_1.write(reg1);
            s_feature_PE272_2.write(reg2);
            s_feature_PE272_3.write(reg3);
            s_feature_PE273_0.write(reg0);
            s_feature_PE273_1.write(reg1);
            s_feature_PE273_2.write(reg2);
            s_feature_PE273_3.write(reg3);
            s_feature_PE274_0.write(reg0);
            s_feature_PE274_1.write(reg1);
            s_feature_PE274_2.write(reg2);
            s_feature_PE274_3.write(reg3);
            s_feature_PE275_0.write(reg0);
            s_feature_PE275_1.write(reg1);
            s_feature_PE275_2.write(reg2);
            s_feature_PE275_3.write(reg3);
            s_feature_PE276_0.write(reg0);
            s_feature_PE276_1.write(reg1);
            s_feature_PE276_2.write(reg2);
            s_feature_PE276_3.write(reg3);
            s_feature_PE277_0.write(reg0);
            s_feature_PE277_1.write(reg1);
            s_feature_PE277_2.write(reg2);
            s_feature_PE277_3.write(reg3);
            s_feature_PE278_0.write(reg0);
            s_feature_PE278_1.write(reg1);
            s_feature_PE278_2.write(reg2);
            s_feature_PE278_3.write(reg3);
            s_feature_PE279_0.write(reg0);
            s_feature_PE279_1.write(reg1);
            s_feature_PE279_2.write(reg2);
            s_feature_PE279_3.write(reg3);
            s_feature_PE280_0.write(reg0);
            s_feature_PE280_1.write(reg1);
            s_feature_PE280_2.write(reg2);
            s_feature_PE280_3.write(reg3);
            s_feature_PE281_0.write(reg0);
            s_feature_PE281_1.write(reg1);
            s_feature_PE281_2.write(reg2);
            s_feature_PE281_3.write(reg3);
            s_feature_PE282_0.write(reg0);
            s_feature_PE282_1.write(reg1);
            s_feature_PE282_2.write(reg2);
            s_feature_PE282_3.write(reg3);
            s_feature_PE283_0.write(reg0);
            s_feature_PE283_1.write(reg1);
            s_feature_PE283_2.write(reg2);
            s_feature_PE283_3.write(reg3);
            s_feature_PE284_0.write(reg0);
            s_feature_PE284_1.write(reg1);
            s_feature_PE284_2.write(reg2);
            s_feature_PE284_3.write(reg3);
            s_feature_PE285_0.write(reg0);
            s_feature_PE285_1.write(reg1);
            s_feature_PE285_2.write(reg2);
            s_feature_PE285_3.write(reg3);
            s_feature_PE286_0.write(reg0);
            s_feature_PE286_1.write(reg1);
            s_feature_PE286_2.write(reg2);
            s_feature_PE286_3.write(reg3);
            s_feature_PE287_0.write(reg0);
            s_feature_PE287_1.write(reg1);
            s_feature_PE287_2.write(reg2);
            s_feature_PE287_3.write(reg3);
            s_feature_PE288_0.write(reg0);
            s_feature_PE288_1.write(reg1);
            s_feature_PE288_2.write(reg2);
            s_feature_PE288_3.write(reg3);
            s_feature_PE289_0.write(reg0);
            s_feature_PE289_1.write(reg1);
            s_feature_PE289_2.write(reg2);
            s_feature_PE289_3.write(reg3);
            s_feature_PE290_0.write(reg0);
            s_feature_PE290_1.write(reg1);
            s_feature_PE290_2.write(reg2);
            s_feature_PE290_3.write(reg3);
            s_feature_PE291_0.write(reg0);
            s_feature_PE291_1.write(reg1);
            s_feature_PE291_2.write(reg2);
            s_feature_PE291_3.write(reg3);
            s_feature_PE292_0.write(reg0);
            s_feature_PE292_1.write(reg1);
            s_feature_PE292_2.write(reg2);
            s_feature_PE292_3.write(reg3);
            s_feature_PE293_0.write(reg0);
            s_feature_PE293_1.write(reg1);
            s_feature_PE293_2.write(reg2);
            s_feature_PE293_3.write(reg3);
            s_feature_PE294_0.write(reg0);
            s_feature_PE294_1.write(reg1);
            s_feature_PE294_2.write(reg2);
            s_feature_PE294_3.write(reg3);
            s_feature_PE295_0.write(reg0);
            s_feature_PE295_1.write(reg1);
            s_feature_PE295_2.write(reg2);
            s_feature_PE295_3.write(reg3);
            s_feature_PE296_0.write(reg0);
            s_feature_PE296_1.write(reg1);
            s_feature_PE296_2.write(reg2);
            s_feature_PE296_3.write(reg3);
            s_feature_PE297_0.write(reg0);
            s_feature_PE297_1.write(reg1);
            s_feature_PE297_2.write(reg2);
            s_feature_PE297_3.write(reg3);
            s_feature_PE298_0.write(reg0);
            s_feature_PE298_1.write(reg1);
            s_feature_PE298_2.write(reg2);
            s_feature_PE298_3.write(reg3);
            s_feature_PE299_0.write(reg0);
            s_feature_PE299_1.write(reg1);
            s_feature_PE299_2.write(reg2);
            s_feature_PE299_3.write(reg3);
            s_feature_PE300_0.write(reg0);
            s_feature_PE300_1.write(reg1);
            s_feature_PE300_2.write(reg2);
            s_feature_PE300_3.write(reg3);
            s_feature_PE301_0.write(reg0);
            s_feature_PE301_1.write(reg1);
            s_feature_PE301_2.write(reg2);
            s_feature_PE301_3.write(reg3);
            s_feature_PE302_0.write(reg0);
            s_feature_PE302_1.write(reg1);
            s_feature_PE302_2.write(reg2);
            s_feature_PE302_3.write(reg3);
            s_feature_PE303_0.write(reg0);
            s_feature_PE303_1.write(reg1);
            s_feature_PE303_2.write(reg2);
            s_feature_PE303_3.write(reg3);
            s_feature_PE304_0.write(reg0);
            s_feature_PE304_1.write(reg1);
            s_feature_PE304_2.write(reg2);
            s_feature_PE304_3.write(reg3);
            s_feature_PE305_0.write(reg0);
            s_feature_PE305_1.write(reg1);
            s_feature_PE305_2.write(reg2);
            s_feature_PE305_3.write(reg3);
            s_feature_PE306_0.write(reg0);
            s_feature_PE306_1.write(reg1);
            s_feature_PE306_2.write(reg2);
            s_feature_PE306_3.write(reg3);
            s_feature_PE307_0.write(reg0);
            s_feature_PE307_1.write(reg1);
            s_feature_PE307_2.write(reg2);
            s_feature_PE307_3.write(reg3);
            s_feature_PE308_0.write(reg0);
            s_feature_PE308_1.write(reg1);
            s_feature_PE308_2.write(reg2);
            s_feature_PE308_3.write(reg3);
            s_feature_PE309_0.write(reg0);
            s_feature_PE309_1.write(reg1);
            s_feature_PE309_2.write(reg2);
            s_feature_PE309_3.write(reg3);
            s_feature_PE310_0.write(reg0);
            s_feature_PE310_1.write(reg1);
            s_feature_PE310_2.write(reg2);
            s_feature_PE310_3.write(reg3);
            s_feature_PE311_0.write(reg0);
            s_feature_PE311_1.write(reg1);
            s_feature_PE311_2.write(reg2);
            s_feature_PE311_3.write(reg3);
            s_feature_PE312_0.write(reg0);
            s_feature_PE312_1.write(reg1);
            s_feature_PE312_2.write(reg2);
            s_feature_PE312_3.write(reg3);
            s_feature_PE313_0.write(reg0);
            s_feature_PE313_1.write(reg1);
            s_feature_PE313_2.write(reg2);
            s_feature_PE313_3.write(reg3);
            s_feature_PE314_0.write(reg0);
            s_feature_PE314_1.write(reg1);
            s_feature_PE314_2.write(reg2);
            s_feature_PE314_3.write(reg3);
            s_feature_PE315_0.write(reg0);
            s_feature_PE315_1.write(reg1);
            s_feature_PE315_2.write(reg2);
            s_feature_PE315_3.write(reg3);
            s_feature_PE316_0.write(reg0);
            s_feature_PE316_1.write(reg1);
            s_feature_PE316_2.write(reg2);
            s_feature_PE316_3.write(reg3);
            s_feature_PE317_0.write(reg0);
            s_feature_PE317_1.write(reg1);
            s_feature_PE317_2.write(reg2);
            s_feature_PE317_3.write(reg3);
            s_feature_PE318_0.write(reg0);
            s_feature_PE318_1.write(reg1);
            s_feature_PE318_2.write(reg2);
            s_feature_PE318_3.write(reg3);
            s_feature_PE319_0.write(reg0);
            s_feature_PE319_1.write(reg1);
            s_feature_PE319_2.write(reg2);
            s_feature_PE319_3.write(reg3);
        }
}

template<const int FEATURE_SIZE>
void replicate_feature_512PEs_160PE(
    hls::stream<ap_uint<512> >& s_feature_in, 
    hls::stream<W_TYPE>& s_feature_PE0_0, hls::stream<W_TYPE>& s_feature_PE0_1,
    hls::stream<W_TYPE>& s_feature_PE0_2, hls::stream<W_TYPE>& s_feature_PE0_3,
    hls::stream<W_TYPE>& s_feature_PE1_0, hls::stream<W_TYPE>& s_feature_PE1_1,
    hls::stream<W_TYPE>& s_feature_PE1_2, hls::stream<W_TYPE>& s_feature_PE1_3,
    hls::stream<W_TYPE>& s_feature_PE2_0, hls::stream<W_TYPE>& s_feature_PE2_1,
    hls::stream<W_TYPE>& s_feature_PE2_2, hls::stream<W_TYPE>& s_feature_PE2_3,
    hls::stream<W_TYPE>& s_feature_PE3_0, hls::stream<W_TYPE>& s_feature_PE3_1,
    hls::stream<W_TYPE>& s_feature_PE3_2, hls::stream<W_TYPE>& s_feature_PE3_3,
    hls::stream<W_TYPE>& s_feature_PE4_0, hls::stream<W_TYPE>& s_feature_PE4_1,
    hls::stream<W_TYPE>& s_feature_PE4_2, hls::stream<W_TYPE>& s_feature_PE4_3,
    hls::stream<W_TYPE>& s_feature_PE5_0, hls::stream<W_TYPE>& s_feature_PE5_1,
    hls::stream<W_TYPE>& s_feature_PE5_2, hls::stream<W_TYPE>& s_feature_PE5_3,
    hls::stream<W_TYPE>& s_feature_PE6_0, hls::stream<W_TYPE>& s_feature_PE6_1,
    hls::stream<W_TYPE>& s_feature_PE6_2, hls::stream<W_TYPE>& s_feature_PE6_3,
    hls::stream<W_TYPE>& s_feature_PE7_0, hls::stream<W_TYPE>& s_feature_PE7_1,
    hls::stream<W_TYPE>& s_feature_PE7_2, hls::stream<W_TYPE>& s_feature_PE7_3,
    hls::stream<W_TYPE>& s_feature_PE8_0, hls::stream<W_TYPE>& s_feature_PE8_1,
    hls::stream<W_TYPE>& s_feature_PE8_2, hls::stream<W_TYPE>& s_feature_PE8_3,
    hls::stream<W_TYPE>& s_feature_PE9_0, hls::stream<W_TYPE>& s_feature_PE9_1,
    hls::stream<W_TYPE>& s_feature_PE9_2, hls::stream<W_TYPE>& s_feature_PE9_3,
    hls::stream<W_TYPE>& s_feature_PE10_0, hls::stream<W_TYPE>& s_feature_PE10_1,
    hls::stream<W_TYPE>& s_feature_PE10_2, hls::stream<W_TYPE>& s_feature_PE10_3,
    hls::stream<W_TYPE>& s_feature_PE11_0, hls::stream<W_TYPE>& s_feature_PE11_1,
    hls::stream<W_TYPE>& s_feature_PE11_2, hls::stream<W_TYPE>& s_feature_PE11_3,
    hls::stream<W_TYPE>& s_feature_PE12_0, hls::stream<W_TYPE>& s_feature_PE12_1,
    hls::stream<W_TYPE>& s_feature_PE12_2, hls::stream<W_TYPE>& s_feature_PE12_3,
    hls::stream<W_TYPE>& s_feature_PE13_0, hls::stream<W_TYPE>& s_feature_PE13_1,
    hls::stream<W_TYPE>& s_feature_PE13_2, hls::stream<W_TYPE>& s_feature_PE13_3,
    hls::stream<W_TYPE>& s_feature_PE14_0, hls::stream<W_TYPE>& s_feature_PE14_1,
    hls::stream<W_TYPE>& s_feature_PE14_2, hls::stream<W_TYPE>& s_feature_PE14_3,
    hls::stream<W_TYPE>& s_feature_PE15_0, hls::stream<W_TYPE>& s_feature_PE15_1,
    hls::stream<W_TYPE>& s_feature_PE15_2, hls::stream<W_TYPE>& s_feature_PE15_3,
    hls::stream<W_TYPE>& s_feature_PE16_0, hls::stream<W_TYPE>& s_feature_PE16_1,
    hls::stream<W_TYPE>& s_feature_PE16_2, hls::stream<W_TYPE>& s_feature_PE16_3,
    hls::stream<W_TYPE>& s_feature_PE17_0, hls::stream<W_TYPE>& s_feature_PE17_1,
    hls::stream<W_TYPE>& s_feature_PE17_2, hls::stream<W_TYPE>& s_feature_PE17_3,
    hls::stream<W_TYPE>& s_feature_PE18_0, hls::stream<W_TYPE>& s_feature_PE18_1,
    hls::stream<W_TYPE>& s_feature_PE18_2, hls::stream<W_TYPE>& s_feature_PE18_3,
    hls::stream<W_TYPE>& s_feature_PE19_0, hls::stream<W_TYPE>& s_feature_PE19_1,
    hls::stream<W_TYPE>& s_feature_PE19_2, hls::stream<W_TYPE>& s_feature_PE19_3,
    hls::stream<W_TYPE>& s_feature_PE20_0, hls::stream<W_TYPE>& s_feature_PE20_1,
    hls::stream<W_TYPE>& s_feature_PE20_2, hls::stream<W_TYPE>& s_feature_PE20_3,
    hls::stream<W_TYPE>& s_feature_PE21_0, hls::stream<W_TYPE>& s_feature_PE21_1,
    hls::stream<W_TYPE>& s_feature_PE21_2, hls::stream<W_TYPE>& s_feature_PE21_3,
    hls::stream<W_TYPE>& s_feature_PE22_0, hls::stream<W_TYPE>& s_feature_PE22_1,
    hls::stream<W_TYPE>& s_feature_PE22_2, hls::stream<W_TYPE>& s_feature_PE22_3,
    hls::stream<W_TYPE>& s_feature_PE23_0, hls::stream<W_TYPE>& s_feature_PE23_1,
    hls::stream<W_TYPE>& s_feature_PE23_2, hls::stream<W_TYPE>& s_feature_PE23_3,
    hls::stream<W_TYPE>& s_feature_PE24_0, hls::stream<W_TYPE>& s_feature_PE24_1,
    hls::stream<W_TYPE>& s_feature_PE24_2, hls::stream<W_TYPE>& s_feature_PE24_3,
    hls::stream<W_TYPE>& s_feature_PE25_0, hls::stream<W_TYPE>& s_feature_PE25_1,
    hls::stream<W_TYPE>& s_feature_PE25_2, hls::stream<W_TYPE>& s_feature_PE25_3,
    hls::stream<W_TYPE>& s_feature_PE26_0, hls::stream<W_TYPE>& s_feature_PE26_1,
    hls::stream<W_TYPE>& s_feature_PE26_2, hls::stream<W_TYPE>& s_feature_PE26_3,
    hls::stream<W_TYPE>& s_feature_PE27_0, hls::stream<W_TYPE>& s_feature_PE27_1,
    hls::stream<W_TYPE>& s_feature_PE27_2, hls::stream<W_TYPE>& s_feature_PE27_3,
    hls::stream<W_TYPE>& s_feature_PE28_0, hls::stream<W_TYPE>& s_feature_PE28_1,
    hls::stream<W_TYPE>& s_feature_PE28_2, hls::stream<W_TYPE>& s_feature_PE28_3,
    hls::stream<W_TYPE>& s_feature_PE29_0, hls::stream<W_TYPE>& s_feature_PE29_1,
    hls::stream<W_TYPE>& s_feature_PE29_2, hls::stream<W_TYPE>& s_feature_PE29_3,
    hls::stream<W_TYPE>& s_feature_PE30_0, hls::stream<W_TYPE>& s_feature_PE30_1,
    hls::stream<W_TYPE>& s_feature_PE30_2, hls::stream<W_TYPE>& s_feature_PE30_3,
    hls::stream<W_TYPE>& s_feature_PE31_0, hls::stream<W_TYPE>& s_feature_PE31_1,
    hls::stream<W_TYPE>& s_feature_PE31_2, hls::stream<W_TYPE>& s_feature_PE31_3,
    hls::stream<W_TYPE>& s_feature_PE32_0, hls::stream<W_TYPE>& s_feature_PE32_1,
    hls::stream<W_TYPE>& s_feature_PE32_2, hls::stream<W_TYPE>& s_feature_PE32_3,
    hls::stream<W_TYPE>& s_feature_PE33_0, hls::stream<W_TYPE>& s_feature_PE33_1,
    hls::stream<W_TYPE>& s_feature_PE33_2, hls::stream<W_TYPE>& s_feature_PE33_3,
    hls::stream<W_TYPE>& s_feature_PE34_0, hls::stream<W_TYPE>& s_feature_PE34_1,
    hls::stream<W_TYPE>& s_feature_PE34_2, hls::stream<W_TYPE>& s_feature_PE34_3,
    hls::stream<W_TYPE>& s_feature_PE35_0, hls::stream<W_TYPE>& s_feature_PE35_1,
    hls::stream<W_TYPE>& s_feature_PE35_2, hls::stream<W_TYPE>& s_feature_PE35_3,
    hls::stream<W_TYPE>& s_feature_PE36_0, hls::stream<W_TYPE>& s_feature_PE36_1,
    hls::stream<W_TYPE>& s_feature_PE36_2, hls::stream<W_TYPE>& s_feature_PE36_3,
    hls::stream<W_TYPE>& s_feature_PE37_0, hls::stream<W_TYPE>& s_feature_PE37_1,
    hls::stream<W_TYPE>& s_feature_PE37_2, hls::stream<W_TYPE>& s_feature_PE37_3,
    hls::stream<W_TYPE>& s_feature_PE38_0, hls::stream<W_TYPE>& s_feature_PE38_1,
    hls::stream<W_TYPE>& s_feature_PE38_2, hls::stream<W_TYPE>& s_feature_PE38_3,
    hls::stream<W_TYPE>& s_feature_PE39_0, hls::stream<W_TYPE>& s_feature_PE39_1,
    hls::stream<W_TYPE>& s_feature_PE39_2, hls::stream<W_TYPE>& s_feature_PE39_3,
    hls::stream<W_TYPE>& s_feature_PE40_0, hls::stream<W_TYPE>& s_feature_PE40_1,
    hls::stream<W_TYPE>& s_feature_PE40_2, hls::stream<W_TYPE>& s_feature_PE40_3,
    hls::stream<W_TYPE>& s_feature_PE41_0, hls::stream<W_TYPE>& s_feature_PE41_1,
    hls::stream<W_TYPE>& s_feature_PE41_2, hls::stream<W_TYPE>& s_feature_PE41_3,
    hls::stream<W_TYPE>& s_feature_PE42_0, hls::stream<W_TYPE>& s_feature_PE42_1,
    hls::stream<W_TYPE>& s_feature_PE42_2, hls::stream<W_TYPE>& s_feature_PE42_3,
    hls::stream<W_TYPE>& s_feature_PE43_0, hls::stream<W_TYPE>& s_feature_PE43_1,
    hls::stream<W_TYPE>& s_feature_PE43_2, hls::stream<W_TYPE>& s_feature_PE43_3,
    hls::stream<W_TYPE>& s_feature_PE44_0, hls::stream<W_TYPE>& s_feature_PE44_1,
    hls::stream<W_TYPE>& s_feature_PE44_2, hls::stream<W_TYPE>& s_feature_PE44_3,
    hls::stream<W_TYPE>& s_feature_PE45_0, hls::stream<W_TYPE>& s_feature_PE45_1,
    hls::stream<W_TYPE>& s_feature_PE45_2, hls::stream<W_TYPE>& s_feature_PE45_3,
    hls::stream<W_TYPE>& s_feature_PE46_0, hls::stream<W_TYPE>& s_feature_PE46_1,
    hls::stream<W_TYPE>& s_feature_PE46_2, hls::stream<W_TYPE>& s_feature_PE46_3,
    hls::stream<W_TYPE>& s_feature_PE47_0, hls::stream<W_TYPE>& s_feature_PE47_1,
    hls::stream<W_TYPE>& s_feature_PE47_2, hls::stream<W_TYPE>& s_feature_PE47_3,
    hls::stream<W_TYPE>& s_feature_PE48_0, hls::stream<W_TYPE>& s_feature_PE48_1,
    hls::stream<W_TYPE>& s_feature_PE48_2, hls::stream<W_TYPE>& s_feature_PE48_3,
    hls::stream<W_TYPE>& s_feature_PE49_0, hls::stream<W_TYPE>& s_feature_PE49_1,
    hls::stream<W_TYPE>& s_feature_PE49_2, hls::stream<W_TYPE>& s_feature_PE49_3,
    hls::stream<W_TYPE>& s_feature_PE50_0, hls::stream<W_TYPE>& s_feature_PE50_1,
    hls::stream<W_TYPE>& s_feature_PE50_2, hls::stream<W_TYPE>& s_feature_PE50_3,
    hls::stream<W_TYPE>& s_feature_PE51_0, hls::stream<W_TYPE>& s_feature_PE51_1,
    hls::stream<W_TYPE>& s_feature_PE51_2, hls::stream<W_TYPE>& s_feature_PE51_3,
    hls::stream<W_TYPE>& s_feature_PE52_0, hls::stream<W_TYPE>& s_feature_PE52_1,
    hls::stream<W_TYPE>& s_feature_PE52_2, hls::stream<W_TYPE>& s_feature_PE52_3,
    hls::stream<W_TYPE>& s_feature_PE53_0, hls::stream<W_TYPE>& s_feature_PE53_1,
    hls::stream<W_TYPE>& s_feature_PE53_2, hls::stream<W_TYPE>& s_feature_PE53_3,
    hls::stream<W_TYPE>& s_feature_PE54_0, hls::stream<W_TYPE>& s_feature_PE54_1,
    hls::stream<W_TYPE>& s_feature_PE54_2, hls::stream<W_TYPE>& s_feature_PE54_3,
    hls::stream<W_TYPE>& s_feature_PE55_0, hls::stream<W_TYPE>& s_feature_PE55_1,
    hls::stream<W_TYPE>& s_feature_PE55_2, hls::stream<W_TYPE>& s_feature_PE55_3,
    hls::stream<W_TYPE>& s_feature_PE56_0, hls::stream<W_TYPE>& s_feature_PE56_1,
    hls::stream<W_TYPE>& s_feature_PE56_2, hls::stream<W_TYPE>& s_feature_PE56_3,
    hls::stream<W_TYPE>& s_feature_PE57_0, hls::stream<W_TYPE>& s_feature_PE57_1,
    hls::stream<W_TYPE>& s_feature_PE57_2, hls::stream<W_TYPE>& s_feature_PE57_3,
    hls::stream<W_TYPE>& s_feature_PE58_0, hls::stream<W_TYPE>& s_feature_PE58_1,
    hls::stream<W_TYPE>& s_feature_PE58_2, hls::stream<W_TYPE>& s_feature_PE58_3,
    hls::stream<W_TYPE>& s_feature_PE59_0, hls::stream<W_TYPE>& s_feature_PE59_1,
    hls::stream<W_TYPE>& s_feature_PE59_2, hls::stream<W_TYPE>& s_feature_PE59_3,
    hls::stream<W_TYPE>& s_feature_PE60_0, hls::stream<W_TYPE>& s_feature_PE60_1,
    hls::stream<W_TYPE>& s_feature_PE60_2, hls::stream<W_TYPE>& s_feature_PE60_3,
    hls::stream<W_TYPE>& s_feature_PE61_0, hls::stream<W_TYPE>& s_feature_PE61_1,
    hls::stream<W_TYPE>& s_feature_PE61_2, hls::stream<W_TYPE>& s_feature_PE61_3,
    hls::stream<W_TYPE>& s_feature_PE62_0, hls::stream<W_TYPE>& s_feature_PE62_1,
    hls::stream<W_TYPE>& s_feature_PE62_2, hls::stream<W_TYPE>& s_feature_PE62_3,
    hls::stream<W_TYPE>& s_feature_PE63_0, hls::stream<W_TYPE>& s_feature_PE63_1,
    hls::stream<W_TYPE>& s_feature_PE63_2, hls::stream<W_TYPE>& s_feature_PE63_3,
    hls::stream<W_TYPE>& s_feature_PE64_0, hls::stream<W_TYPE>& s_feature_PE64_1,
    hls::stream<W_TYPE>& s_feature_PE64_2, hls::stream<W_TYPE>& s_feature_PE64_3,
    hls::stream<W_TYPE>& s_feature_PE65_0, hls::stream<W_TYPE>& s_feature_PE65_1,
    hls::stream<W_TYPE>& s_feature_PE65_2, hls::stream<W_TYPE>& s_feature_PE65_3,
    hls::stream<W_TYPE>& s_feature_PE66_0, hls::stream<W_TYPE>& s_feature_PE66_1,
    hls::stream<W_TYPE>& s_feature_PE66_2, hls::stream<W_TYPE>& s_feature_PE66_3,
    hls::stream<W_TYPE>& s_feature_PE67_0, hls::stream<W_TYPE>& s_feature_PE67_1,
    hls::stream<W_TYPE>& s_feature_PE67_2, hls::stream<W_TYPE>& s_feature_PE67_3,
    hls::stream<W_TYPE>& s_feature_PE68_0, hls::stream<W_TYPE>& s_feature_PE68_1,
    hls::stream<W_TYPE>& s_feature_PE68_2, hls::stream<W_TYPE>& s_feature_PE68_3,
    hls::stream<W_TYPE>& s_feature_PE69_0, hls::stream<W_TYPE>& s_feature_PE69_1,
    hls::stream<W_TYPE>& s_feature_PE69_2, hls::stream<W_TYPE>& s_feature_PE69_3,
    hls::stream<W_TYPE>& s_feature_PE70_0, hls::stream<W_TYPE>& s_feature_PE70_1,
    hls::stream<W_TYPE>& s_feature_PE70_2, hls::stream<W_TYPE>& s_feature_PE70_3,
    hls::stream<W_TYPE>& s_feature_PE71_0, hls::stream<W_TYPE>& s_feature_PE71_1,
    hls::stream<W_TYPE>& s_feature_PE71_2, hls::stream<W_TYPE>& s_feature_PE71_3,
    hls::stream<W_TYPE>& s_feature_PE72_0, hls::stream<W_TYPE>& s_feature_PE72_1,
    hls::stream<W_TYPE>& s_feature_PE72_2, hls::stream<W_TYPE>& s_feature_PE72_3,
    hls::stream<W_TYPE>& s_feature_PE73_0, hls::stream<W_TYPE>& s_feature_PE73_1,
    hls::stream<W_TYPE>& s_feature_PE73_2, hls::stream<W_TYPE>& s_feature_PE73_3,
    hls::stream<W_TYPE>& s_feature_PE74_0, hls::stream<W_TYPE>& s_feature_PE74_1,
    hls::stream<W_TYPE>& s_feature_PE74_2, hls::stream<W_TYPE>& s_feature_PE74_3,
    hls::stream<W_TYPE>& s_feature_PE75_0, hls::stream<W_TYPE>& s_feature_PE75_1,
    hls::stream<W_TYPE>& s_feature_PE75_2, hls::stream<W_TYPE>& s_feature_PE75_3,
    hls::stream<W_TYPE>& s_feature_PE76_0, hls::stream<W_TYPE>& s_feature_PE76_1,
    hls::stream<W_TYPE>& s_feature_PE76_2, hls::stream<W_TYPE>& s_feature_PE76_3,
    hls::stream<W_TYPE>& s_feature_PE77_0, hls::stream<W_TYPE>& s_feature_PE77_1,
    hls::stream<W_TYPE>& s_feature_PE77_2, hls::stream<W_TYPE>& s_feature_PE77_3,
    hls::stream<W_TYPE>& s_feature_PE78_0, hls::stream<W_TYPE>& s_feature_PE78_1,
    hls::stream<W_TYPE>& s_feature_PE78_2, hls::stream<W_TYPE>& s_feature_PE78_3,
    hls::stream<W_TYPE>& s_feature_PE79_0, hls::stream<W_TYPE>& s_feature_PE79_1,
    hls::stream<W_TYPE>& s_feature_PE79_2, hls::stream<W_TYPE>& s_feature_PE79_3,
    hls::stream<W_TYPE>& s_feature_PE80_0, hls::stream<W_TYPE>& s_feature_PE80_1,
    hls::stream<W_TYPE>& s_feature_PE80_2, hls::stream<W_TYPE>& s_feature_PE80_3,
    hls::stream<W_TYPE>& s_feature_PE81_0, hls::stream<W_TYPE>& s_feature_PE81_1,
    hls::stream<W_TYPE>& s_feature_PE81_2, hls::stream<W_TYPE>& s_feature_PE81_3,
    hls::stream<W_TYPE>& s_feature_PE82_0, hls::stream<W_TYPE>& s_feature_PE82_1,
    hls::stream<W_TYPE>& s_feature_PE82_2, hls::stream<W_TYPE>& s_feature_PE82_3,
    hls::stream<W_TYPE>& s_feature_PE83_0, hls::stream<W_TYPE>& s_feature_PE83_1,
    hls::stream<W_TYPE>& s_feature_PE83_2, hls::stream<W_TYPE>& s_feature_PE83_3,
    hls::stream<W_TYPE>& s_feature_PE84_0, hls::stream<W_TYPE>& s_feature_PE84_1,
    hls::stream<W_TYPE>& s_feature_PE84_2, hls::stream<W_TYPE>& s_feature_PE84_3,
    hls::stream<W_TYPE>& s_feature_PE85_0, hls::stream<W_TYPE>& s_feature_PE85_1,
    hls::stream<W_TYPE>& s_feature_PE85_2, hls::stream<W_TYPE>& s_feature_PE85_3,
    hls::stream<W_TYPE>& s_feature_PE86_0, hls::stream<W_TYPE>& s_feature_PE86_1,
    hls::stream<W_TYPE>& s_feature_PE86_2, hls::stream<W_TYPE>& s_feature_PE86_3,
    hls::stream<W_TYPE>& s_feature_PE87_0, hls::stream<W_TYPE>& s_feature_PE87_1,
    hls::stream<W_TYPE>& s_feature_PE87_2, hls::stream<W_TYPE>& s_feature_PE87_3,
    hls::stream<W_TYPE>& s_feature_PE88_0, hls::stream<W_TYPE>& s_feature_PE88_1,
    hls::stream<W_TYPE>& s_feature_PE88_2, hls::stream<W_TYPE>& s_feature_PE88_3,
    hls::stream<W_TYPE>& s_feature_PE89_0, hls::stream<W_TYPE>& s_feature_PE89_1,
    hls::stream<W_TYPE>& s_feature_PE89_2, hls::stream<W_TYPE>& s_feature_PE89_3,
    hls::stream<W_TYPE>& s_feature_PE90_0, hls::stream<W_TYPE>& s_feature_PE90_1,
    hls::stream<W_TYPE>& s_feature_PE90_2, hls::stream<W_TYPE>& s_feature_PE90_3,
    hls::stream<W_TYPE>& s_feature_PE91_0, hls::stream<W_TYPE>& s_feature_PE91_1,
    hls::stream<W_TYPE>& s_feature_PE91_2, hls::stream<W_TYPE>& s_feature_PE91_3,
    hls::stream<W_TYPE>& s_feature_PE92_0, hls::stream<W_TYPE>& s_feature_PE92_1,
    hls::stream<W_TYPE>& s_feature_PE92_2, hls::stream<W_TYPE>& s_feature_PE92_3,
    hls::stream<W_TYPE>& s_feature_PE93_0, hls::stream<W_TYPE>& s_feature_PE93_1,
    hls::stream<W_TYPE>& s_feature_PE93_2, hls::stream<W_TYPE>& s_feature_PE93_3,
    hls::stream<W_TYPE>& s_feature_PE94_0, hls::stream<W_TYPE>& s_feature_PE94_1,
    hls::stream<W_TYPE>& s_feature_PE94_2, hls::stream<W_TYPE>& s_feature_PE94_3,
    hls::stream<W_TYPE>& s_feature_PE95_0, hls::stream<W_TYPE>& s_feature_PE95_1,
    hls::stream<W_TYPE>& s_feature_PE95_2, hls::stream<W_TYPE>& s_feature_PE95_3,
    hls::stream<W_TYPE>& s_feature_PE96_0, hls::stream<W_TYPE>& s_feature_PE96_1,
    hls::stream<W_TYPE>& s_feature_PE96_2, hls::stream<W_TYPE>& s_feature_PE96_3,
    hls::stream<W_TYPE>& s_feature_PE97_0, hls::stream<W_TYPE>& s_feature_PE97_1,
    hls::stream<W_TYPE>& s_feature_PE97_2, hls::stream<W_TYPE>& s_feature_PE97_3,
    hls::stream<W_TYPE>& s_feature_PE98_0, hls::stream<W_TYPE>& s_feature_PE98_1,
    hls::stream<W_TYPE>& s_feature_PE98_2, hls::stream<W_TYPE>& s_feature_PE98_3,
    hls::stream<W_TYPE>& s_feature_PE99_0, hls::stream<W_TYPE>& s_feature_PE99_1,
    hls::stream<W_TYPE>& s_feature_PE99_2, hls::stream<W_TYPE>& s_feature_PE99_3,
    hls::stream<W_TYPE>& s_feature_PE100_0, hls::stream<W_TYPE>& s_feature_PE100_1,
    hls::stream<W_TYPE>& s_feature_PE100_2, hls::stream<W_TYPE>& s_feature_PE100_3,
    hls::stream<W_TYPE>& s_feature_PE101_0, hls::stream<W_TYPE>& s_feature_PE101_1,
    hls::stream<W_TYPE>& s_feature_PE101_2, hls::stream<W_TYPE>& s_feature_PE101_3,
    hls::stream<W_TYPE>& s_feature_PE102_0, hls::stream<W_TYPE>& s_feature_PE102_1,
    hls::stream<W_TYPE>& s_feature_PE102_2, hls::stream<W_TYPE>& s_feature_PE102_3,
    hls::stream<W_TYPE>& s_feature_PE103_0, hls::stream<W_TYPE>& s_feature_PE103_1,
    hls::stream<W_TYPE>& s_feature_PE103_2, hls::stream<W_TYPE>& s_feature_PE103_3,
    hls::stream<W_TYPE>& s_feature_PE104_0, hls::stream<W_TYPE>& s_feature_PE104_1,
    hls::stream<W_TYPE>& s_feature_PE104_2, hls::stream<W_TYPE>& s_feature_PE104_3,
    hls::stream<W_TYPE>& s_feature_PE105_0, hls::stream<W_TYPE>& s_feature_PE105_1,
    hls::stream<W_TYPE>& s_feature_PE105_2, hls::stream<W_TYPE>& s_feature_PE105_3,
    hls::stream<W_TYPE>& s_feature_PE106_0, hls::stream<W_TYPE>& s_feature_PE106_1,
    hls::stream<W_TYPE>& s_feature_PE106_2, hls::stream<W_TYPE>& s_feature_PE106_3,
    hls::stream<W_TYPE>& s_feature_PE107_0, hls::stream<W_TYPE>& s_feature_PE107_1,
    hls::stream<W_TYPE>& s_feature_PE107_2, hls::stream<W_TYPE>& s_feature_PE107_3,
    hls::stream<W_TYPE>& s_feature_PE108_0, hls::stream<W_TYPE>& s_feature_PE108_1,
    hls::stream<W_TYPE>& s_feature_PE108_2, hls::stream<W_TYPE>& s_feature_PE108_3,
    hls::stream<W_TYPE>& s_feature_PE109_0, hls::stream<W_TYPE>& s_feature_PE109_1,
    hls::stream<W_TYPE>& s_feature_PE109_2, hls::stream<W_TYPE>& s_feature_PE109_3,
    hls::stream<W_TYPE>& s_feature_PE110_0, hls::stream<W_TYPE>& s_feature_PE110_1,
    hls::stream<W_TYPE>& s_feature_PE110_2, hls::stream<W_TYPE>& s_feature_PE110_3,
    hls::stream<W_TYPE>& s_feature_PE111_0, hls::stream<W_TYPE>& s_feature_PE111_1,
    hls::stream<W_TYPE>& s_feature_PE111_2, hls::stream<W_TYPE>& s_feature_PE111_3,
    hls::stream<W_TYPE>& s_feature_PE112_0, hls::stream<W_TYPE>& s_feature_PE112_1,
    hls::stream<W_TYPE>& s_feature_PE112_2, hls::stream<W_TYPE>& s_feature_PE112_3,
    hls::stream<W_TYPE>& s_feature_PE113_0, hls::stream<W_TYPE>& s_feature_PE113_1,
    hls::stream<W_TYPE>& s_feature_PE113_2, hls::stream<W_TYPE>& s_feature_PE113_3,
    hls::stream<W_TYPE>& s_feature_PE114_0, hls::stream<W_TYPE>& s_feature_PE114_1,
    hls::stream<W_TYPE>& s_feature_PE114_2, hls::stream<W_TYPE>& s_feature_PE114_3,
    hls::stream<W_TYPE>& s_feature_PE115_0, hls::stream<W_TYPE>& s_feature_PE115_1,
    hls::stream<W_TYPE>& s_feature_PE115_2, hls::stream<W_TYPE>& s_feature_PE115_3,
    hls::stream<W_TYPE>& s_feature_PE116_0, hls::stream<W_TYPE>& s_feature_PE116_1,
    hls::stream<W_TYPE>& s_feature_PE116_2, hls::stream<W_TYPE>& s_feature_PE116_3,
    hls::stream<W_TYPE>& s_feature_PE117_0, hls::stream<W_TYPE>& s_feature_PE117_1,
    hls::stream<W_TYPE>& s_feature_PE117_2, hls::stream<W_TYPE>& s_feature_PE117_3,
    hls::stream<W_TYPE>& s_feature_PE118_0, hls::stream<W_TYPE>& s_feature_PE118_1,
    hls::stream<W_TYPE>& s_feature_PE118_2, hls::stream<W_TYPE>& s_feature_PE118_3,
    hls::stream<W_TYPE>& s_feature_PE119_0, hls::stream<W_TYPE>& s_feature_PE119_1,
    hls::stream<W_TYPE>& s_feature_PE119_2, hls::stream<W_TYPE>& s_feature_PE119_3,
    hls::stream<W_TYPE>& s_feature_PE120_0, hls::stream<W_TYPE>& s_feature_PE120_1,
    hls::stream<W_TYPE>& s_feature_PE120_2, hls::stream<W_TYPE>& s_feature_PE120_3,
    hls::stream<W_TYPE>& s_feature_PE121_0, hls::stream<W_TYPE>& s_feature_PE121_1,
    hls::stream<W_TYPE>& s_feature_PE121_2, hls::stream<W_TYPE>& s_feature_PE121_3,
    hls::stream<W_TYPE>& s_feature_PE122_0, hls::stream<W_TYPE>& s_feature_PE122_1,
    hls::stream<W_TYPE>& s_feature_PE122_2, hls::stream<W_TYPE>& s_feature_PE122_3,
    hls::stream<W_TYPE>& s_feature_PE123_0, hls::stream<W_TYPE>& s_feature_PE123_1,
    hls::stream<W_TYPE>& s_feature_PE123_2, hls::stream<W_TYPE>& s_feature_PE123_3,
    hls::stream<W_TYPE>& s_feature_PE124_0, hls::stream<W_TYPE>& s_feature_PE124_1,
    hls::stream<W_TYPE>& s_feature_PE124_2, hls::stream<W_TYPE>& s_feature_PE124_3,
    hls::stream<W_TYPE>& s_feature_PE125_0, hls::stream<W_TYPE>& s_feature_PE125_1,
    hls::stream<W_TYPE>& s_feature_PE125_2, hls::stream<W_TYPE>& s_feature_PE125_3,
    hls::stream<W_TYPE>& s_feature_PE126_0, hls::stream<W_TYPE>& s_feature_PE126_1,
    hls::stream<W_TYPE>& s_feature_PE126_2, hls::stream<W_TYPE>& s_feature_PE126_3,
    hls::stream<W_TYPE>& s_feature_PE127_0, hls::stream<W_TYPE>& s_feature_PE127_1,
    hls::stream<W_TYPE>& s_feature_PE127_2, hls::stream<W_TYPE>& s_feature_PE127_3,
    hls::stream<W_TYPE>& s_feature_PE128_0, hls::stream<W_TYPE>& s_feature_PE128_1,
    hls::stream<W_TYPE>& s_feature_PE128_2, hls::stream<W_TYPE>& s_feature_PE128_3,
    hls::stream<W_TYPE>& s_feature_PE129_0, hls::stream<W_TYPE>& s_feature_PE129_1,
    hls::stream<W_TYPE>& s_feature_PE129_2, hls::stream<W_TYPE>& s_feature_PE129_3,
    hls::stream<W_TYPE>& s_feature_PE130_0, hls::stream<W_TYPE>& s_feature_PE130_1,
    hls::stream<W_TYPE>& s_feature_PE130_2, hls::stream<W_TYPE>& s_feature_PE130_3,
    hls::stream<W_TYPE>& s_feature_PE131_0, hls::stream<W_TYPE>& s_feature_PE131_1,
    hls::stream<W_TYPE>& s_feature_PE131_2, hls::stream<W_TYPE>& s_feature_PE131_3,
    hls::stream<W_TYPE>& s_feature_PE132_0, hls::stream<W_TYPE>& s_feature_PE132_1,
    hls::stream<W_TYPE>& s_feature_PE132_2, hls::stream<W_TYPE>& s_feature_PE132_3,
    hls::stream<W_TYPE>& s_feature_PE133_0, hls::stream<W_TYPE>& s_feature_PE133_1,
    hls::stream<W_TYPE>& s_feature_PE133_2, hls::stream<W_TYPE>& s_feature_PE133_3,
    hls::stream<W_TYPE>& s_feature_PE134_0, hls::stream<W_TYPE>& s_feature_PE134_1,
    hls::stream<W_TYPE>& s_feature_PE134_2, hls::stream<W_TYPE>& s_feature_PE134_3,
    hls::stream<W_TYPE>& s_feature_PE135_0, hls::stream<W_TYPE>& s_feature_PE135_1,
    hls::stream<W_TYPE>& s_feature_PE135_2, hls::stream<W_TYPE>& s_feature_PE135_3,
    hls::stream<W_TYPE>& s_feature_PE136_0, hls::stream<W_TYPE>& s_feature_PE136_1,
    hls::stream<W_TYPE>& s_feature_PE136_2, hls::stream<W_TYPE>& s_feature_PE136_3,
    hls::stream<W_TYPE>& s_feature_PE137_0, hls::stream<W_TYPE>& s_feature_PE137_1,
    hls::stream<W_TYPE>& s_feature_PE137_2, hls::stream<W_TYPE>& s_feature_PE137_3,
    hls::stream<W_TYPE>& s_feature_PE138_0, hls::stream<W_TYPE>& s_feature_PE138_1,
    hls::stream<W_TYPE>& s_feature_PE138_2, hls::stream<W_TYPE>& s_feature_PE138_3,
    hls::stream<W_TYPE>& s_feature_PE139_0, hls::stream<W_TYPE>& s_feature_PE139_1,
    hls::stream<W_TYPE>& s_feature_PE139_2, hls::stream<W_TYPE>& s_feature_PE139_3,
    hls::stream<W_TYPE>& s_feature_PE140_0, hls::stream<W_TYPE>& s_feature_PE140_1,
    hls::stream<W_TYPE>& s_feature_PE140_2, hls::stream<W_TYPE>& s_feature_PE140_3,
    hls::stream<W_TYPE>& s_feature_PE141_0, hls::stream<W_TYPE>& s_feature_PE141_1,
    hls::stream<W_TYPE>& s_feature_PE141_2, hls::stream<W_TYPE>& s_feature_PE141_3,
    hls::stream<W_TYPE>& s_feature_PE142_0, hls::stream<W_TYPE>& s_feature_PE142_1,
    hls::stream<W_TYPE>& s_feature_PE142_2, hls::stream<W_TYPE>& s_feature_PE142_3,
    hls::stream<W_TYPE>& s_feature_PE143_0, hls::stream<W_TYPE>& s_feature_PE143_1,
    hls::stream<W_TYPE>& s_feature_PE143_2, hls::stream<W_TYPE>& s_feature_PE143_3,
    hls::stream<W_TYPE>& s_feature_PE144_0, hls::stream<W_TYPE>& s_feature_PE144_1,
    hls::stream<W_TYPE>& s_feature_PE144_2, hls::stream<W_TYPE>& s_feature_PE144_3,
    hls::stream<W_TYPE>& s_feature_PE145_0, hls::stream<W_TYPE>& s_feature_PE145_1,
    hls::stream<W_TYPE>& s_feature_PE145_2, hls::stream<W_TYPE>& s_feature_PE145_3,
    hls::stream<W_TYPE>& s_feature_PE146_0, hls::stream<W_TYPE>& s_feature_PE146_1,
    hls::stream<W_TYPE>& s_feature_PE146_2, hls::stream<W_TYPE>& s_feature_PE146_3,
    hls::stream<W_TYPE>& s_feature_PE147_0, hls::stream<W_TYPE>& s_feature_PE147_1,
    hls::stream<W_TYPE>& s_feature_PE147_2, hls::stream<W_TYPE>& s_feature_PE147_3,
    hls::stream<W_TYPE>& s_feature_PE148_0, hls::stream<W_TYPE>& s_feature_PE148_1,
    hls::stream<W_TYPE>& s_feature_PE148_2, hls::stream<W_TYPE>& s_feature_PE148_3,
    hls::stream<W_TYPE>& s_feature_PE149_0, hls::stream<W_TYPE>& s_feature_PE149_1,
    hls::stream<W_TYPE>& s_feature_PE149_2, hls::stream<W_TYPE>& s_feature_PE149_3,
    hls::stream<W_TYPE>& s_feature_PE150_0, hls::stream<W_TYPE>& s_feature_PE150_1,
    hls::stream<W_TYPE>& s_feature_PE150_2, hls::stream<W_TYPE>& s_feature_PE150_3,
    hls::stream<W_TYPE>& s_feature_PE151_0, hls::stream<W_TYPE>& s_feature_PE151_1,
    hls::stream<W_TYPE>& s_feature_PE151_2, hls::stream<W_TYPE>& s_feature_PE151_3,
    hls::stream<W_TYPE>& s_feature_PE152_0, hls::stream<W_TYPE>& s_feature_PE152_1,
    hls::stream<W_TYPE>& s_feature_PE152_2, hls::stream<W_TYPE>& s_feature_PE152_3,
    hls::stream<W_TYPE>& s_feature_PE153_0, hls::stream<W_TYPE>& s_feature_PE153_1,
    hls::stream<W_TYPE>& s_feature_PE153_2, hls::stream<W_TYPE>& s_feature_PE153_3,
    hls::stream<W_TYPE>& s_feature_PE154_0, hls::stream<W_TYPE>& s_feature_PE154_1,
    hls::stream<W_TYPE>& s_feature_PE154_2, hls::stream<W_TYPE>& s_feature_PE154_3,
    hls::stream<W_TYPE>& s_feature_PE155_0, hls::stream<W_TYPE>& s_feature_PE155_1,
    hls::stream<W_TYPE>& s_feature_PE155_2, hls::stream<W_TYPE>& s_feature_PE155_3,
    hls::stream<W_TYPE>& s_feature_PE156_0, hls::stream<W_TYPE>& s_feature_PE156_1,
    hls::stream<W_TYPE>& s_feature_PE156_2, hls::stream<W_TYPE>& s_feature_PE156_3,
    hls::stream<W_TYPE>& s_feature_PE157_0, hls::stream<W_TYPE>& s_feature_PE157_1,
    hls::stream<W_TYPE>& s_feature_PE157_2, hls::stream<W_TYPE>& s_feature_PE157_3,
    hls::stream<W_TYPE>& s_feature_PE158_0, hls::stream<W_TYPE>& s_feature_PE158_1,
    hls::stream<W_TYPE>& s_feature_PE158_2, hls::stream<W_TYPE>& s_feature_PE158_3,
    hls::stream<W_TYPE>& s_feature_PE159_0, hls::stream<W_TYPE>& s_feature_PE159_1,
    hls::stream<W_TYPE>& s_feature_PE159_2, hls::stream<W_TYPE>& s_feature_PE159_3
){
        for (int i = 0; i < BATCH_NUM * BATCH_SIZE * FEATURE_SIZE / INTS_PER_W / 4; i++) {
            #pragma HLS pipeline II=1

            ap_uint<512> reg = s_feature_in.read();

            W_TYPE reg0 = reg.range(127, 0);
            W_TYPE reg1 = reg.range(255, 128);
            W_TYPE reg2 = reg.range(383, 256);
            W_TYPE reg3 = reg.range(511, 255);

            s_feature_PE0_0.write(reg0);
            s_feature_PE0_1.write(reg1);
            s_feature_PE0_2.write(reg2);
            s_feature_PE0_3.write(reg3);
            s_feature_PE1_0.write(reg0);
            s_feature_PE1_1.write(reg1);
            s_feature_PE1_2.write(reg2);
            s_feature_PE1_3.write(reg3);
            s_feature_PE2_0.write(reg0);
            s_feature_PE2_1.write(reg1);
            s_feature_PE2_2.write(reg2);
            s_feature_PE2_3.write(reg3);
            s_feature_PE3_0.write(reg0);
            s_feature_PE3_1.write(reg1);
            s_feature_PE3_2.write(reg2);
            s_feature_PE3_3.write(reg3);
            s_feature_PE4_0.write(reg0);
            s_feature_PE4_1.write(reg1);
            s_feature_PE4_2.write(reg2);
            s_feature_PE4_3.write(reg3);
            s_feature_PE5_0.write(reg0);
            s_feature_PE5_1.write(reg1);
            s_feature_PE5_2.write(reg2);
            s_feature_PE5_3.write(reg3);
            s_feature_PE6_0.write(reg0);
            s_feature_PE6_1.write(reg1);
            s_feature_PE6_2.write(reg2);
            s_feature_PE6_3.write(reg3);
            s_feature_PE7_0.write(reg0);
            s_feature_PE7_1.write(reg1);
            s_feature_PE7_2.write(reg2);
            s_feature_PE7_3.write(reg3);
            s_feature_PE8_0.write(reg0);
            s_feature_PE8_1.write(reg1);
            s_feature_PE8_2.write(reg2);
            s_feature_PE8_3.write(reg3);
            s_feature_PE9_0.write(reg0);
            s_feature_PE9_1.write(reg1);
            s_feature_PE9_2.write(reg2);
            s_feature_PE9_3.write(reg3);
            s_feature_PE10_0.write(reg0);
            s_feature_PE10_1.write(reg1);
            s_feature_PE10_2.write(reg2);
            s_feature_PE10_3.write(reg3);
            s_feature_PE11_0.write(reg0);
            s_feature_PE11_1.write(reg1);
            s_feature_PE11_2.write(reg2);
            s_feature_PE11_3.write(reg3);
            s_feature_PE12_0.write(reg0);
            s_feature_PE12_1.write(reg1);
            s_feature_PE12_2.write(reg2);
            s_feature_PE12_3.write(reg3);
            s_feature_PE13_0.write(reg0);
            s_feature_PE13_1.write(reg1);
            s_feature_PE13_2.write(reg2);
            s_feature_PE13_3.write(reg3);
            s_feature_PE14_0.write(reg0);
            s_feature_PE14_1.write(reg1);
            s_feature_PE14_2.write(reg2);
            s_feature_PE14_3.write(reg3);
            s_feature_PE15_0.write(reg0);
            s_feature_PE15_1.write(reg1);
            s_feature_PE15_2.write(reg2);
            s_feature_PE15_3.write(reg3);
            s_feature_PE16_0.write(reg0);
            s_feature_PE16_1.write(reg1);
            s_feature_PE16_2.write(reg2);
            s_feature_PE16_3.write(reg3);
            s_feature_PE17_0.write(reg0);
            s_feature_PE17_1.write(reg1);
            s_feature_PE17_2.write(reg2);
            s_feature_PE17_3.write(reg3);
            s_feature_PE18_0.write(reg0);
            s_feature_PE18_1.write(reg1);
            s_feature_PE18_2.write(reg2);
            s_feature_PE18_3.write(reg3);
            s_feature_PE19_0.write(reg0);
            s_feature_PE19_1.write(reg1);
            s_feature_PE19_2.write(reg2);
            s_feature_PE19_3.write(reg3);
            s_feature_PE20_0.write(reg0);
            s_feature_PE20_1.write(reg1);
            s_feature_PE20_2.write(reg2);
            s_feature_PE20_3.write(reg3);
            s_feature_PE21_0.write(reg0);
            s_feature_PE21_1.write(reg1);
            s_feature_PE21_2.write(reg2);
            s_feature_PE21_3.write(reg3);
            s_feature_PE22_0.write(reg0);
            s_feature_PE22_1.write(reg1);
            s_feature_PE22_2.write(reg2);
            s_feature_PE22_3.write(reg3);
            s_feature_PE23_0.write(reg0);
            s_feature_PE23_1.write(reg1);
            s_feature_PE23_2.write(reg2);
            s_feature_PE23_3.write(reg3);
            s_feature_PE24_0.write(reg0);
            s_feature_PE24_1.write(reg1);
            s_feature_PE24_2.write(reg2);
            s_feature_PE24_3.write(reg3);
            s_feature_PE25_0.write(reg0);
            s_feature_PE25_1.write(reg1);
            s_feature_PE25_2.write(reg2);
            s_feature_PE25_3.write(reg3);
            s_feature_PE26_0.write(reg0);
            s_feature_PE26_1.write(reg1);
            s_feature_PE26_2.write(reg2);
            s_feature_PE26_3.write(reg3);
            s_feature_PE27_0.write(reg0);
            s_feature_PE27_1.write(reg1);
            s_feature_PE27_2.write(reg2);
            s_feature_PE27_3.write(reg3);
            s_feature_PE28_0.write(reg0);
            s_feature_PE28_1.write(reg1);
            s_feature_PE28_2.write(reg2);
            s_feature_PE28_3.write(reg3);
            s_feature_PE29_0.write(reg0);
            s_feature_PE29_1.write(reg1);
            s_feature_PE29_2.write(reg2);
            s_feature_PE29_3.write(reg3);
            s_feature_PE30_0.write(reg0);
            s_feature_PE30_1.write(reg1);
            s_feature_PE30_2.write(reg2);
            s_feature_PE30_3.write(reg3);
            s_feature_PE31_0.write(reg0);
            s_feature_PE31_1.write(reg1);
            s_feature_PE31_2.write(reg2);
            s_feature_PE31_3.write(reg3);
            s_feature_PE32_0.write(reg0);
            s_feature_PE32_1.write(reg1);
            s_feature_PE32_2.write(reg2);
            s_feature_PE32_3.write(reg3);
            s_feature_PE33_0.write(reg0);
            s_feature_PE33_1.write(reg1);
            s_feature_PE33_2.write(reg2);
            s_feature_PE33_3.write(reg3);
            s_feature_PE34_0.write(reg0);
            s_feature_PE34_1.write(reg1);
            s_feature_PE34_2.write(reg2);
            s_feature_PE34_3.write(reg3);
            s_feature_PE35_0.write(reg0);
            s_feature_PE35_1.write(reg1);
            s_feature_PE35_2.write(reg2);
            s_feature_PE35_3.write(reg3);
            s_feature_PE36_0.write(reg0);
            s_feature_PE36_1.write(reg1);
            s_feature_PE36_2.write(reg2);
            s_feature_PE36_3.write(reg3);
            s_feature_PE37_0.write(reg0);
            s_feature_PE37_1.write(reg1);
            s_feature_PE37_2.write(reg2);
            s_feature_PE37_3.write(reg3);
            s_feature_PE38_0.write(reg0);
            s_feature_PE38_1.write(reg1);
            s_feature_PE38_2.write(reg2);
            s_feature_PE38_3.write(reg3);
            s_feature_PE39_0.write(reg0);
            s_feature_PE39_1.write(reg1);
            s_feature_PE39_2.write(reg2);
            s_feature_PE39_3.write(reg3);
            s_feature_PE40_0.write(reg0);
            s_feature_PE40_1.write(reg1);
            s_feature_PE40_2.write(reg2);
            s_feature_PE40_3.write(reg3);
            s_feature_PE41_0.write(reg0);
            s_feature_PE41_1.write(reg1);
            s_feature_PE41_2.write(reg2);
            s_feature_PE41_3.write(reg3);
            s_feature_PE42_0.write(reg0);
            s_feature_PE42_1.write(reg1);
            s_feature_PE42_2.write(reg2);
            s_feature_PE42_3.write(reg3);
            s_feature_PE43_0.write(reg0);
            s_feature_PE43_1.write(reg1);
            s_feature_PE43_2.write(reg2);
            s_feature_PE43_3.write(reg3);
            s_feature_PE44_0.write(reg0);
            s_feature_PE44_1.write(reg1);
            s_feature_PE44_2.write(reg2);
            s_feature_PE44_3.write(reg3);
            s_feature_PE45_0.write(reg0);
            s_feature_PE45_1.write(reg1);
            s_feature_PE45_2.write(reg2);
            s_feature_PE45_3.write(reg3);
            s_feature_PE46_0.write(reg0);
            s_feature_PE46_1.write(reg1);
            s_feature_PE46_2.write(reg2);
            s_feature_PE46_3.write(reg3);
            s_feature_PE47_0.write(reg0);
            s_feature_PE47_1.write(reg1);
            s_feature_PE47_2.write(reg2);
            s_feature_PE47_3.write(reg3);
            s_feature_PE48_0.write(reg0);
            s_feature_PE48_1.write(reg1);
            s_feature_PE48_2.write(reg2);
            s_feature_PE48_3.write(reg3);
            s_feature_PE49_0.write(reg0);
            s_feature_PE49_1.write(reg1);
            s_feature_PE49_2.write(reg2);
            s_feature_PE49_3.write(reg3);
            s_feature_PE50_0.write(reg0);
            s_feature_PE50_1.write(reg1);
            s_feature_PE50_2.write(reg2);
            s_feature_PE50_3.write(reg3);
            s_feature_PE51_0.write(reg0);
            s_feature_PE51_1.write(reg1);
            s_feature_PE51_2.write(reg2);
            s_feature_PE51_3.write(reg3);
            s_feature_PE52_0.write(reg0);
            s_feature_PE52_1.write(reg1);
            s_feature_PE52_2.write(reg2);
            s_feature_PE52_3.write(reg3);
            s_feature_PE53_0.write(reg0);
            s_feature_PE53_1.write(reg1);
            s_feature_PE53_2.write(reg2);
            s_feature_PE53_3.write(reg3);
            s_feature_PE54_0.write(reg0);
            s_feature_PE54_1.write(reg1);
            s_feature_PE54_2.write(reg2);
            s_feature_PE54_3.write(reg3);
            s_feature_PE55_0.write(reg0);
            s_feature_PE55_1.write(reg1);
            s_feature_PE55_2.write(reg2);
            s_feature_PE55_3.write(reg3);
            s_feature_PE56_0.write(reg0);
            s_feature_PE56_1.write(reg1);
            s_feature_PE56_2.write(reg2);
            s_feature_PE56_3.write(reg3);
            s_feature_PE57_0.write(reg0);
            s_feature_PE57_1.write(reg1);
            s_feature_PE57_2.write(reg2);
            s_feature_PE57_3.write(reg3);
            s_feature_PE58_0.write(reg0);
            s_feature_PE58_1.write(reg1);
            s_feature_PE58_2.write(reg2);
            s_feature_PE58_3.write(reg3);
            s_feature_PE59_0.write(reg0);
            s_feature_PE59_1.write(reg1);
            s_feature_PE59_2.write(reg2);
            s_feature_PE59_3.write(reg3);
            s_feature_PE60_0.write(reg0);
            s_feature_PE60_1.write(reg1);
            s_feature_PE60_2.write(reg2);
            s_feature_PE60_3.write(reg3);
            s_feature_PE61_0.write(reg0);
            s_feature_PE61_1.write(reg1);
            s_feature_PE61_2.write(reg2);
            s_feature_PE61_3.write(reg3);
            s_feature_PE62_0.write(reg0);
            s_feature_PE62_1.write(reg1);
            s_feature_PE62_2.write(reg2);
            s_feature_PE62_3.write(reg3);
            s_feature_PE63_0.write(reg0);
            s_feature_PE63_1.write(reg1);
            s_feature_PE63_2.write(reg2);
            s_feature_PE63_3.write(reg3);
            s_feature_PE64_0.write(reg0);
            s_feature_PE64_1.write(reg1);
            s_feature_PE64_2.write(reg2);
            s_feature_PE64_3.write(reg3);
            s_feature_PE65_0.write(reg0);
            s_feature_PE65_1.write(reg1);
            s_feature_PE65_2.write(reg2);
            s_feature_PE65_3.write(reg3);
            s_feature_PE66_0.write(reg0);
            s_feature_PE66_1.write(reg1);
            s_feature_PE66_2.write(reg2);
            s_feature_PE66_3.write(reg3);
            s_feature_PE67_0.write(reg0);
            s_feature_PE67_1.write(reg1);
            s_feature_PE67_2.write(reg2);
            s_feature_PE67_3.write(reg3);
            s_feature_PE68_0.write(reg0);
            s_feature_PE68_1.write(reg1);
            s_feature_PE68_2.write(reg2);
            s_feature_PE68_3.write(reg3);
            s_feature_PE69_0.write(reg0);
            s_feature_PE69_1.write(reg1);
            s_feature_PE69_2.write(reg2);
            s_feature_PE69_3.write(reg3);
            s_feature_PE70_0.write(reg0);
            s_feature_PE70_1.write(reg1);
            s_feature_PE70_2.write(reg2);
            s_feature_PE70_3.write(reg3);
            s_feature_PE71_0.write(reg0);
            s_feature_PE71_1.write(reg1);
            s_feature_PE71_2.write(reg2);
            s_feature_PE71_3.write(reg3);
            s_feature_PE72_0.write(reg0);
            s_feature_PE72_1.write(reg1);
            s_feature_PE72_2.write(reg2);
            s_feature_PE72_3.write(reg3);
            s_feature_PE73_0.write(reg0);
            s_feature_PE73_1.write(reg1);
            s_feature_PE73_2.write(reg2);
            s_feature_PE73_3.write(reg3);
            s_feature_PE74_0.write(reg0);
            s_feature_PE74_1.write(reg1);
            s_feature_PE74_2.write(reg2);
            s_feature_PE74_3.write(reg3);
            s_feature_PE75_0.write(reg0);
            s_feature_PE75_1.write(reg1);
            s_feature_PE75_2.write(reg2);
            s_feature_PE75_3.write(reg3);
            s_feature_PE76_0.write(reg0);
            s_feature_PE76_1.write(reg1);
            s_feature_PE76_2.write(reg2);
            s_feature_PE76_3.write(reg3);
            s_feature_PE77_0.write(reg0);
            s_feature_PE77_1.write(reg1);
            s_feature_PE77_2.write(reg2);
            s_feature_PE77_3.write(reg3);
            s_feature_PE78_0.write(reg0);
            s_feature_PE78_1.write(reg1);
            s_feature_PE78_2.write(reg2);
            s_feature_PE78_3.write(reg3);
            s_feature_PE79_0.write(reg0);
            s_feature_PE79_1.write(reg1);
            s_feature_PE79_2.write(reg2);
            s_feature_PE79_3.write(reg3);
            s_feature_PE80_0.write(reg0);
            s_feature_PE80_1.write(reg1);
            s_feature_PE80_2.write(reg2);
            s_feature_PE80_3.write(reg3);
            s_feature_PE81_0.write(reg0);
            s_feature_PE81_1.write(reg1);
            s_feature_PE81_2.write(reg2);
            s_feature_PE81_3.write(reg3);
            s_feature_PE82_0.write(reg0);
            s_feature_PE82_1.write(reg1);
            s_feature_PE82_2.write(reg2);
            s_feature_PE82_3.write(reg3);
            s_feature_PE83_0.write(reg0);
            s_feature_PE83_1.write(reg1);
            s_feature_PE83_2.write(reg2);
            s_feature_PE83_3.write(reg3);
            s_feature_PE84_0.write(reg0);
            s_feature_PE84_1.write(reg1);
            s_feature_PE84_2.write(reg2);
            s_feature_PE84_3.write(reg3);
            s_feature_PE85_0.write(reg0);
            s_feature_PE85_1.write(reg1);
            s_feature_PE85_2.write(reg2);
            s_feature_PE85_3.write(reg3);
            s_feature_PE86_0.write(reg0);
            s_feature_PE86_1.write(reg1);
            s_feature_PE86_2.write(reg2);
            s_feature_PE86_3.write(reg3);
            s_feature_PE87_0.write(reg0);
            s_feature_PE87_1.write(reg1);
            s_feature_PE87_2.write(reg2);
            s_feature_PE87_3.write(reg3);
            s_feature_PE88_0.write(reg0);
            s_feature_PE88_1.write(reg1);
            s_feature_PE88_2.write(reg2);
            s_feature_PE88_3.write(reg3);
            s_feature_PE89_0.write(reg0);
            s_feature_PE89_1.write(reg1);
            s_feature_PE89_2.write(reg2);
            s_feature_PE89_3.write(reg3);
            s_feature_PE90_0.write(reg0);
            s_feature_PE90_1.write(reg1);
            s_feature_PE90_2.write(reg2);
            s_feature_PE90_3.write(reg3);
            s_feature_PE91_0.write(reg0);
            s_feature_PE91_1.write(reg1);
            s_feature_PE91_2.write(reg2);
            s_feature_PE91_3.write(reg3);
            s_feature_PE92_0.write(reg0);
            s_feature_PE92_1.write(reg1);
            s_feature_PE92_2.write(reg2);
            s_feature_PE92_3.write(reg3);
            s_feature_PE93_0.write(reg0);
            s_feature_PE93_1.write(reg1);
            s_feature_PE93_2.write(reg2);
            s_feature_PE93_3.write(reg3);
            s_feature_PE94_0.write(reg0);
            s_feature_PE94_1.write(reg1);
            s_feature_PE94_2.write(reg2);
            s_feature_PE94_3.write(reg3);
            s_feature_PE95_0.write(reg0);
            s_feature_PE95_1.write(reg1);
            s_feature_PE95_2.write(reg2);
            s_feature_PE95_3.write(reg3);
            s_feature_PE96_0.write(reg0);
            s_feature_PE96_1.write(reg1);
            s_feature_PE96_2.write(reg2);
            s_feature_PE96_3.write(reg3);
            s_feature_PE97_0.write(reg0);
            s_feature_PE97_1.write(reg1);
            s_feature_PE97_2.write(reg2);
            s_feature_PE97_3.write(reg3);
            s_feature_PE98_0.write(reg0);
            s_feature_PE98_1.write(reg1);
            s_feature_PE98_2.write(reg2);
            s_feature_PE98_3.write(reg3);
            s_feature_PE99_0.write(reg0);
            s_feature_PE99_1.write(reg1);
            s_feature_PE99_2.write(reg2);
            s_feature_PE99_3.write(reg3);
            s_feature_PE100_0.write(reg0);
            s_feature_PE100_1.write(reg1);
            s_feature_PE100_2.write(reg2);
            s_feature_PE100_3.write(reg3);
            s_feature_PE101_0.write(reg0);
            s_feature_PE101_1.write(reg1);
            s_feature_PE101_2.write(reg2);
            s_feature_PE101_3.write(reg3);
            s_feature_PE102_0.write(reg0);
            s_feature_PE102_1.write(reg1);
            s_feature_PE102_2.write(reg2);
            s_feature_PE102_3.write(reg3);
            s_feature_PE103_0.write(reg0);
            s_feature_PE103_1.write(reg1);
            s_feature_PE103_2.write(reg2);
            s_feature_PE103_3.write(reg3);
            s_feature_PE104_0.write(reg0);
            s_feature_PE104_1.write(reg1);
            s_feature_PE104_2.write(reg2);
            s_feature_PE104_3.write(reg3);
            s_feature_PE105_0.write(reg0);
            s_feature_PE105_1.write(reg1);
            s_feature_PE105_2.write(reg2);
            s_feature_PE105_3.write(reg3);
            s_feature_PE106_0.write(reg0);
            s_feature_PE106_1.write(reg1);
            s_feature_PE106_2.write(reg2);
            s_feature_PE106_3.write(reg3);
            s_feature_PE107_0.write(reg0);
            s_feature_PE107_1.write(reg1);
            s_feature_PE107_2.write(reg2);
            s_feature_PE107_3.write(reg3);
            s_feature_PE108_0.write(reg0);
            s_feature_PE108_1.write(reg1);
            s_feature_PE108_2.write(reg2);
            s_feature_PE108_3.write(reg3);
            s_feature_PE109_0.write(reg0);
            s_feature_PE109_1.write(reg1);
            s_feature_PE109_2.write(reg2);
            s_feature_PE109_3.write(reg3);
            s_feature_PE110_0.write(reg0);
            s_feature_PE110_1.write(reg1);
            s_feature_PE110_2.write(reg2);
            s_feature_PE110_3.write(reg3);
            s_feature_PE111_0.write(reg0);
            s_feature_PE111_1.write(reg1);
            s_feature_PE111_2.write(reg2);
            s_feature_PE111_3.write(reg3);
            s_feature_PE112_0.write(reg0);
            s_feature_PE112_1.write(reg1);
            s_feature_PE112_2.write(reg2);
            s_feature_PE112_3.write(reg3);
            s_feature_PE113_0.write(reg0);
            s_feature_PE113_1.write(reg1);
            s_feature_PE113_2.write(reg2);
            s_feature_PE113_3.write(reg3);
            s_feature_PE114_0.write(reg0);
            s_feature_PE114_1.write(reg1);
            s_feature_PE114_2.write(reg2);
            s_feature_PE114_3.write(reg3);
            s_feature_PE115_0.write(reg0);
            s_feature_PE115_1.write(reg1);
            s_feature_PE115_2.write(reg2);
            s_feature_PE115_3.write(reg3);
            s_feature_PE116_0.write(reg0);
            s_feature_PE116_1.write(reg1);
            s_feature_PE116_2.write(reg2);
            s_feature_PE116_3.write(reg3);
            s_feature_PE117_0.write(reg0);
            s_feature_PE117_1.write(reg1);
            s_feature_PE117_2.write(reg2);
            s_feature_PE117_3.write(reg3);
            s_feature_PE118_0.write(reg0);
            s_feature_PE118_1.write(reg1);
            s_feature_PE118_2.write(reg2);
            s_feature_PE118_3.write(reg3);
            s_feature_PE119_0.write(reg0);
            s_feature_PE119_1.write(reg1);
            s_feature_PE119_2.write(reg2);
            s_feature_PE119_3.write(reg3);
            s_feature_PE120_0.write(reg0);
            s_feature_PE120_1.write(reg1);
            s_feature_PE120_2.write(reg2);
            s_feature_PE120_3.write(reg3);
            s_feature_PE121_0.write(reg0);
            s_feature_PE121_1.write(reg1);
            s_feature_PE121_2.write(reg2);
            s_feature_PE121_3.write(reg3);
            s_feature_PE122_0.write(reg0);
            s_feature_PE122_1.write(reg1);
            s_feature_PE122_2.write(reg2);
            s_feature_PE122_3.write(reg3);
            s_feature_PE123_0.write(reg0);
            s_feature_PE123_1.write(reg1);
            s_feature_PE123_2.write(reg2);
            s_feature_PE123_3.write(reg3);
            s_feature_PE124_0.write(reg0);
            s_feature_PE124_1.write(reg1);
            s_feature_PE124_2.write(reg2);
            s_feature_PE124_3.write(reg3);
            s_feature_PE125_0.write(reg0);
            s_feature_PE125_1.write(reg1);
            s_feature_PE125_2.write(reg2);
            s_feature_PE125_3.write(reg3);
            s_feature_PE126_0.write(reg0);
            s_feature_PE126_1.write(reg1);
            s_feature_PE126_2.write(reg2);
            s_feature_PE126_3.write(reg3);
            s_feature_PE127_0.write(reg0);
            s_feature_PE127_1.write(reg1);
            s_feature_PE127_2.write(reg2);
            s_feature_PE127_3.write(reg3);
            s_feature_PE128_0.write(reg0);
            s_feature_PE128_1.write(reg1);
            s_feature_PE128_2.write(reg2);
            s_feature_PE128_3.write(reg3);
            s_feature_PE129_0.write(reg0);
            s_feature_PE129_1.write(reg1);
            s_feature_PE129_2.write(reg2);
            s_feature_PE129_3.write(reg3);
            s_feature_PE130_0.write(reg0);
            s_feature_PE130_1.write(reg1);
            s_feature_PE130_2.write(reg2);
            s_feature_PE130_3.write(reg3);
            s_feature_PE131_0.write(reg0);
            s_feature_PE131_1.write(reg1);
            s_feature_PE131_2.write(reg2);
            s_feature_PE131_3.write(reg3);
            s_feature_PE132_0.write(reg0);
            s_feature_PE132_1.write(reg1);
            s_feature_PE132_2.write(reg2);
            s_feature_PE132_3.write(reg3);
            s_feature_PE133_0.write(reg0);
            s_feature_PE133_1.write(reg1);
            s_feature_PE133_2.write(reg2);
            s_feature_PE133_3.write(reg3);
            s_feature_PE134_0.write(reg0);
            s_feature_PE134_1.write(reg1);
            s_feature_PE134_2.write(reg2);
            s_feature_PE134_3.write(reg3);
            s_feature_PE135_0.write(reg0);
            s_feature_PE135_1.write(reg1);
            s_feature_PE135_2.write(reg2);
            s_feature_PE135_3.write(reg3);
            s_feature_PE136_0.write(reg0);
            s_feature_PE136_1.write(reg1);
            s_feature_PE136_2.write(reg2);
            s_feature_PE136_3.write(reg3);
            s_feature_PE137_0.write(reg0);
            s_feature_PE137_1.write(reg1);
            s_feature_PE137_2.write(reg2);
            s_feature_PE137_3.write(reg3);
            s_feature_PE138_0.write(reg0);
            s_feature_PE138_1.write(reg1);
            s_feature_PE138_2.write(reg2);
            s_feature_PE138_3.write(reg3);
            s_feature_PE139_0.write(reg0);
            s_feature_PE139_1.write(reg1);
            s_feature_PE139_2.write(reg2);
            s_feature_PE139_3.write(reg3);
            s_feature_PE140_0.write(reg0);
            s_feature_PE140_1.write(reg1);
            s_feature_PE140_2.write(reg2);
            s_feature_PE140_3.write(reg3);
            s_feature_PE141_0.write(reg0);
            s_feature_PE141_1.write(reg1);
            s_feature_PE141_2.write(reg2);
            s_feature_PE141_3.write(reg3);
            s_feature_PE142_0.write(reg0);
            s_feature_PE142_1.write(reg1);
            s_feature_PE142_2.write(reg2);
            s_feature_PE142_3.write(reg3);
            s_feature_PE143_0.write(reg0);
            s_feature_PE143_1.write(reg1);
            s_feature_PE143_2.write(reg2);
            s_feature_PE143_3.write(reg3);
            s_feature_PE144_0.write(reg0);
            s_feature_PE144_1.write(reg1);
            s_feature_PE144_2.write(reg2);
            s_feature_PE144_3.write(reg3);
            s_feature_PE145_0.write(reg0);
            s_feature_PE145_1.write(reg1);
            s_feature_PE145_2.write(reg2);
            s_feature_PE145_3.write(reg3);
            s_feature_PE146_0.write(reg0);
            s_feature_PE146_1.write(reg1);
            s_feature_PE146_2.write(reg2);
            s_feature_PE146_3.write(reg3);
            s_feature_PE147_0.write(reg0);
            s_feature_PE147_1.write(reg1);
            s_feature_PE147_2.write(reg2);
            s_feature_PE147_3.write(reg3);
            s_feature_PE148_0.write(reg0);
            s_feature_PE148_1.write(reg1);
            s_feature_PE148_2.write(reg2);
            s_feature_PE148_3.write(reg3);
            s_feature_PE149_0.write(reg0);
            s_feature_PE149_1.write(reg1);
            s_feature_PE149_2.write(reg2);
            s_feature_PE149_3.write(reg3);
            s_feature_PE150_0.write(reg0);
            s_feature_PE150_1.write(reg1);
            s_feature_PE150_2.write(reg2);
            s_feature_PE150_3.write(reg3);
            s_feature_PE151_0.write(reg0);
            s_feature_PE151_1.write(reg1);
            s_feature_PE151_2.write(reg2);
            s_feature_PE151_3.write(reg3);
            s_feature_PE152_0.write(reg0);
            s_feature_PE152_1.write(reg1);
            s_feature_PE152_2.write(reg2);
            s_feature_PE152_3.write(reg3);
            s_feature_PE153_0.write(reg0);
            s_feature_PE153_1.write(reg1);
            s_feature_PE153_2.write(reg2);
            s_feature_PE153_3.write(reg3);
            s_feature_PE154_0.write(reg0);
            s_feature_PE154_1.write(reg1);
            s_feature_PE154_2.write(reg2);
            s_feature_PE154_3.write(reg3);
            s_feature_PE155_0.write(reg0);
            s_feature_PE155_1.write(reg1);
            s_feature_PE155_2.write(reg2);
            s_feature_PE155_3.write(reg3);
            s_feature_PE156_0.write(reg0);
            s_feature_PE156_1.write(reg1);
            s_feature_PE156_2.write(reg2);
            s_feature_PE156_3.write(reg3);
            s_feature_PE157_0.write(reg0);
            s_feature_PE157_1.write(reg1);
            s_feature_PE157_2.write(reg2);
            s_feature_PE157_3.write(reg3);
            s_feature_PE158_0.write(reg0);
            s_feature_PE158_1.write(reg1);
            s_feature_PE158_2.write(reg2);
            s_feature_PE158_3.write(reg3);
            s_feature_PE159_0.write(reg0);
            s_feature_PE159_1.write(reg1);
            s_feature_PE159_2.write(reg2);
            s_feature_PE159_3.write(reg3);
        }
}

template<const int FEATURE_SIZE>
void replicate_feature_512PEs_80PE(
    hls::stream<ap_uint<512> >& s_feature_in, 
    hls::stream<W_TYPE>& s_feature_PE0_0, hls::stream<W_TYPE>& s_feature_PE0_1,
    hls::stream<W_TYPE>& s_feature_PE0_2, hls::stream<W_TYPE>& s_feature_PE0_3,
    hls::stream<W_TYPE>& s_feature_PE1_0, hls::stream<W_TYPE>& s_feature_PE1_1,
    hls::stream<W_TYPE>& s_feature_PE1_2, hls::stream<W_TYPE>& s_feature_PE1_3,
    hls::stream<W_TYPE>& s_feature_PE2_0, hls::stream<W_TYPE>& s_feature_PE2_1,
    hls::stream<W_TYPE>& s_feature_PE2_2, hls::stream<W_TYPE>& s_feature_PE2_3,
    hls::stream<W_TYPE>& s_feature_PE3_0, hls::stream<W_TYPE>& s_feature_PE3_1,
    hls::stream<W_TYPE>& s_feature_PE3_2, hls::stream<W_TYPE>& s_feature_PE3_3,
    hls::stream<W_TYPE>& s_feature_PE4_0, hls::stream<W_TYPE>& s_feature_PE4_1,
    hls::stream<W_TYPE>& s_feature_PE4_2, hls::stream<W_TYPE>& s_feature_PE4_3,
    hls::stream<W_TYPE>& s_feature_PE5_0, hls::stream<W_TYPE>& s_feature_PE5_1,
    hls::stream<W_TYPE>& s_feature_PE5_2, hls::stream<W_TYPE>& s_feature_PE5_3,
    hls::stream<W_TYPE>& s_feature_PE6_0, hls::stream<W_TYPE>& s_feature_PE6_1,
    hls::stream<W_TYPE>& s_feature_PE6_2, hls::stream<W_TYPE>& s_feature_PE6_3,
    hls::stream<W_TYPE>& s_feature_PE7_0, hls::stream<W_TYPE>& s_feature_PE7_1,
    hls::stream<W_TYPE>& s_feature_PE7_2, hls::stream<W_TYPE>& s_feature_PE7_3,
    hls::stream<W_TYPE>& s_feature_PE8_0, hls::stream<W_TYPE>& s_feature_PE8_1,
    hls::stream<W_TYPE>& s_feature_PE8_2, hls::stream<W_TYPE>& s_feature_PE8_3,
    hls::stream<W_TYPE>& s_feature_PE9_0, hls::stream<W_TYPE>& s_feature_PE9_1,
    hls::stream<W_TYPE>& s_feature_PE9_2, hls::stream<W_TYPE>& s_feature_PE9_3,
    hls::stream<W_TYPE>& s_feature_PE10_0, hls::stream<W_TYPE>& s_feature_PE10_1,
    hls::stream<W_TYPE>& s_feature_PE10_2, hls::stream<W_TYPE>& s_feature_PE10_3,
    hls::stream<W_TYPE>& s_feature_PE11_0, hls::stream<W_TYPE>& s_feature_PE11_1,
    hls::stream<W_TYPE>& s_feature_PE11_2, hls::stream<W_TYPE>& s_feature_PE11_3,
    hls::stream<W_TYPE>& s_feature_PE12_0, hls::stream<W_TYPE>& s_feature_PE12_1,
    hls::stream<W_TYPE>& s_feature_PE12_2, hls::stream<W_TYPE>& s_feature_PE12_3,
    hls::stream<W_TYPE>& s_feature_PE13_0, hls::stream<W_TYPE>& s_feature_PE13_1,
    hls::stream<W_TYPE>& s_feature_PE13_2, hls::stream<W_TYPE>& s_feature_PE13_3,
    hls::stream<W_TYPE>& s_feature_PE14_0, hls::stream<W_TYPE>& s_feature_PE14_1,
    hls::stream<W_TYPE>& s_feature_PE14_2, hls::stream<W_TYPE>& s_feature_PE14_3,
    hls::stream<W_TYPE>& s_feature_PE15_0, hls::stream<W_TYPE>& s_feature_PE15_1,
    hls::stream<W_TYPE>& s_feature_PE15_2, hls::stream<W_TYPE>& s_feature_PE15_3,
    hls::stream<W_TYPE>& s_feature_PE16_0, hls::stream<W_TYPE>& s_feature_PE16_1,
    hls::stream<W_TYPE>& s_feature_PE16_2, hls::stream<W_TYPE>& s_feature_PE16_3,
    hls::stream<W_TYPE>& s_feature_PE17_0, hls::stream<W_TYPE>& s_feature_PE17_1,
    hls::stream<W_TYPE>& s_feature_PE17_2, hls::stream<W_TYPE>& s_feature_PE17_3,
    hls::stream<W_TYPE>& s_feature_PE18_0, hls::stream<W_TYPE>& s_feature_PE18_1,
    hls::stream<W_TYPE>& s_feature_PE18_2, hls::stream<W_TYPE>& s_feature_PE18_3,
    hls::stream<W_TYPE>& s_feature_PE19_0, hls::stream<W_TYPE>& s_feature_PE19_1,
    hls::stream<W_TYPE>& s_feature_PE19_2, hls::stream<W_TYPE>& s_feature_PE19_3,
    hls::stream<W_TYPE>& s_feature_PE20_0, hls::stream<W_TYPE>& s_feature_PE20_1,
    hls::stream<W_TYPE>& s_feature_PE20_2, hls::stream<W_TYPE>& s_feature_PE20_3,
    hls::stream<W_TYPE>& s_feature_PE21_0, hls::stream<W_TYPE>& s_feature_PE21_1,
    hls::stream<W_TYPE>& s_feature_PE21_2, hls::stream<W_TYPE>& s_feature_PE21_3,
    hls::stream<W_TYPE>& s_feature_PE22_0, hls::stream<W_TYPE>& s_feature_PE22_1,
    hls::stream<W_TYPE>& s_feature_PE22_2, hls::stream<W_TYPE>& s_feature_PE22_3,
    hls::stream<W_TYPE>& s_feature_PE23_0, hls::stream<W_TYPE>& s_feature_PE23_1,
    hls::stream<W_TYPE>& s_feature_PE23_2, hls::stream<W_TYPE>& s_feature_PE23_3,
    hls::stream<W_TYPE>& s_feature_PE24_0, hls::stream<W_TYPE>& s_feature_PE24_1,
    hls::stream<W_TYPE>& s_feature_PE24_2, hls::stream<W_TYPE>& s_feature_PE24_3,
    hls::stream<W_TYPE>& s_feature_PE25_0, hls::stream<W_TYPE>& s_feature_PE25_1,
    hls::stream<W_TYPE>& s_feature_PE25_2, hls::stream<W_TYPE>& s_feature_PE25_3,
    hls::stream<W_TYPE>& s_feature_PE26_0, hls::stream<W_TYPE>& s_feature_PE26_1,
    hls::stream<W_TYPE>& s_feature_PE26_2, hls::stream<W_TYPE>& s_feature_PE26_3,
    hls::stream<W_TYPE>& s_feature_PE27_0, hls::stream<W_TYPE>& s_feature_PE27_1,
    hls::stream<W_TYPE>& s_feature_PE27_2, hls::stream<W_TYPE>& s_feature_PE27_3,
    hls::stream<W_TYPE>& s_feature_PE28_0, hls::stream<W_TYPE>& s_feature_PE28_1,
    hls::stream<W_TYPE>& s_feature_PE28_2, hls::stream<W_TYPE>& s_feature_PE28_3,
    hls::stream<W_TYPE>& s_feature_PE29_0, hls::stream<W_TYPE>& s_feature_PE29_1,
    hls::stream<W_TYPE>& s_feature_PE29_2, hls::stream<W_TYPE>& s_feature_PE29_3,
    hls::stream<W_TYPE>& s_feature_PE30_0, hls::stream<W_TYPE>& s_feature_PE30_1,
    hls::stream<W_TYPE>& s_feature_PE30_2, hls::stream<W_TYPE>& s_feature_PE30_3,
    hls::stream<W_TYPE>& s_feature_PE31_0, hls::stream<W_TYPE>& s_feature_PE31_1,
    hls::stream<W_TYPE>& s_feature_PE31_2, hls::stream<W_TYPE>& s_feature_PE31_3,
    hls::stream<W_TYPE>& s_feature_PE32_0, hls::stream<W_TYPE>& s_feature_PE32_1,
    hls::stream<W_TYPE>& s_feature_PE32_2, hls::stream<W_TYPE>& s_feature_PE32_3,
    hls::stream<W_TYPE>& s_feature_PE33_0, hls::stream<W_TYPE>& s_feature_PE33_1,
    hls::stream<W_TYPE>& s_feature_PE33_2, hls::stream<W_TYPE>& s_feature_PE33_3,
    hls::stream<W_TYPE>& s_feature_PE34_0, hls::stream<W_TYPE>& s_feature_PE34_1,
    hls::stream<W_TYPE>& s_feature_PE34_2, hls::stream<W_TYPE>& s_feature_PE34_3,
    hls::stream<W_TYPE>& s_feature_PE35_0, hls::stream<W_TYPE>& s_feature_PE35_1,
    hls::stream<W_TYPE>& s_feature_PE35_2, hls::stream<W_TYPE>& s_feature_PE35_3,
    hls::stream<W_TYPE>& s_feature_PE36_0, hls::stream<W_TYPE>& s_feature_PE36_1,
    hls::stream<W_TYPE>& s_feature_PE36_2, hls::stream<W_TYPE>& s_feature_PE36_3,
    hls::stream<W_TYPE>& s_feature_PE37_0, hls::stream<W_TYPE>& s_feature_PE37_1,
    hls::stream<W_TYPE>& s_feature_PE37_2, hls::stream<W_TYPE>& s_feature_PE37_3,
    hls::stream<W_TYPE>& s_feature_PE38_0, hls::stream<W_TYPE>& s_feature_PE38_1,
    hls::stream<W_TYPE>& s_feature_PE38_2, hls::stream<W_TYPE>& s_feature_PE38_3,
    hls::stream<W_TYPE>& s_feature_PE39_0, hls::stream<W_TYPE>& s_feature_PE39_1,
    hls::stream<W_TYPE>& s_feature_PE39_2, hls::stream<W_TYPE>& s_feature_PE39_3,
    hls::stream<W_TYPE>& s_feature_PE40_0, hls::stream<W_TYPE>& s_feature_PE40_1,
    hls::stream<W_TYPE>& s_feature_PE40_2, hls::stream<W_TYPE>& s_feature_PE40_3,
    hls::stream<W_TYPE>& s_feature_PE41_0, hls::stream<W_TYPE>& s_feature_PE41_1,
    hls::stream<W_TYPE>& s_feature_PE41_2, hls::stream<W_TYPE>& s_feature_PE41_3,
    hls::stream<W_TYPE>& s_feature_PE42_0, hls::stream<W_TYPE>& s_feature_PE42_1,
    hls::stream<W_TYPE>& s_feature_PE42_2, hls::stream<W_TYPE>& s_feature_PE42_3,
    hls::stream<W_TYPE>& s_feature_PE43_0, hls::stream<W_TYPE>& s_feature_PE43_1,
    hls::stream<W_TYPE>& s_feature_PE43_2, hls::stream<W_TYPE>& s_feature_PE43_3,
    hls::stream<W_TYPE>& s_feature_PE44_0, hls::stream<W_TYPE>& s_feature_PE44_1,
    hls::stream<W_TYPE>& s_feature_PE44_2, hls::stream<W_TYPE>& s_feature_PE44_3,
    hls::stream<W_TYPE>& s_feature_PE45_0, hls::stream<W_TYPE>& s_feature_PE45_1,
    hls::stream<W_TYPE>& s_feature_PE45_2, hls::stream<W_TYPE>& s_feature_PE45_3,
    hls::stream<W_TYPE>& s_feature_PE46_0, hls::stream<W_TYPE>& s_feature_PE46_1,
    hls::stream<W_TYPE>& s_feature_PE46_2, hls::stream<W_TYPE>& s_feature_PE46_3,
    hls::stream<W_TYPE>& s_feature_PE47_0, hls::stream<W_TYPE>& s_feature_PE47_1,
    hls::stream<W_TYPE>& s_feature_PE47_2, hls::stream<W_TYPE>& s_feature_PE47_3,
    hls::stream<W_TYPE>& s_feature_PE48_0, hls::stream<W_TYPE>& s_feature_PE48_1,
    hls::stream<W_TYPE>& s_feature_PE48_2, hls::stream<W_TYPE>& s_feature_PE48_3,
    hls::stream<W_TYPE>& s_feature_PE49_0, hls::stream<W_TYPE>& s_feature_PE49_1,
    hls::stream<W_TYPE>& s_feature_PE49_2, hls::stream<W_TYPE>& s_feature_PE49_3,
    hls::stream<W_TYPE>& s_feature_PE50_0, hls::stream<W_TYPE>& s_feature_PE50_1,
    hls::stream<W_TYPE>& s_feature_PE50_2, hls::stream<W_TYPE>& s_feature_PE50_3,
    hls::stream<W_TYPE>& s_feature_PE51_0, hls::stream<W_TYPE>& s_feature_PE51_1,
    hls::stream<W_TYPE>& s_feature_PE51_2, hls::stream<W_TYPE>& s_feature_PE51_3,
    hls::stream<W_TYPE>& s_feature_PE52_0, hls::stream<W_TYPE>& s_feature_PE52_1,
    hls::stream<W_TYPE>& s_feature_PE52_2, hls::stream<W_TYPE>& s_feature_PE52_3,
    hls::stream<W_TYPE>& s_feature_PE53_0, hls::stream<W_TYPE>& s_feature_PE53_1,
    hls::stream<W_TYPE>& s_feature_PE53_2, hls::stream<W_TYPE>& s_feature_PE53_3,
    hls::stream<W_TYPE>& s_feature_PE54_0, hls::stream<W_TYPE>& s_feature_PE54_1,
    hls::stream<W_TYPE>& s_feature_PE54_2, hls::stream<W_TYPE>& s_feature_PE54_3,
    hls::stream<W_TYPE>& s_feature_PE55_0, hls::stream<W_TYPE>& s_feature_PE55_1,
    hls::stream<W_TYPE>& s_feature_PE55_2, hls::stream<W_TYPE>& s_feature_PE55_3,
    hls::stream<W_TYPE>& s_feature_PE56_0, hls::stream<W_TYPE>& s_feature_PE56_1,
    hls::stream<W_TYPE>& s_feature_PE56_2, hls::stream<W_TYPE>& s_feature_PE56_3,
    hls::stream<W_TYPE>& s_feature_PE57_0, hls::stream<W_TYPE>& s_feature_PE57_1,
    hls::stream<W_TYPE>& s_feature_PE57_2, hls::stream<W_TYPE>& s_feature_PE57_3,
    hls::stream<W_TYPE>& s_feature_PE58_0, hls::stream<W_TYPE>& s_feature_PE58_1,
    hls::stream<W_TYPE>& s_feature_PE58_2, hls::stream<W_TYPE>& s_feature_PE58_3,
    hls::stream<W_TYPE>& s_feature_PE59_0, hls::stream<W_TYPE>& s_feature_PE59_1,
    hls::stream<W_TYPE>& s_feature_PE59_2, hls::stream<W_TYPE>& s_feature_PE59_3,
    hls::stream<W_TYPE>& s_feature_PE60_0, hls::stream<W_TYPE>& s_feature_PE60_1,
    hls::stream<W_TYPE>& s_feature_PE60_2, hls::stream<W_TYPE>& s_feature_PE60_3,
    hls::stream<W_TYPE>& s_feature_PE61_0, hls::stream<W_TYPE>& s_feature_PE61_1,
    hls::stream<W_TYPE>& s_feature_PE61_2, hls::stream<W_TYPE>& s_feature_PE61_3,
    hls::stream<W_TYPE>& s_feature_PE62_0, hls::stream<W_TYPE>& s_feature_PE62_1,
    hls::stream<W_TYPE>& s_feature_PE62_2, hls::stream<W_TYPE>& s_feature_PE62_3,
    hls::stream<W_TYPE>& s_feature_PE63_0, hls::stream<W_TYPE>& s_feature_PE63_1,
    hls::stream<W_TYPE>& s_feature_PE63_2, hls::stream<W_TYPE>& s_feature_PE63_3,
    hls::stream<W_TYPE>& s_feature_PE64_0, hls::stream<W_TYPE>& s_feature_PE64_1,
    hls::stream<W_TYPE>& s_feature_PE64_2, hls::stream<W_TYPE>& s_feature_PE64_3,
    hls::stream<W_TYPE>& s_feature_PE65_0, hls::stream<W_TYPE>& s_feature_PE65_1,
    hls::stream<W_TYPE>& s_feature_PE65_2, hls::stream<W_TYPE>& s_feature_PE65_3,
    hls::stream<W_TYPE>& s_feature_PE66_0, hls::stream<W_TYPE>& s_feature_PE66_1,
    hls::stream<W_TYPE>& s_feature_PE66_2, hls::stream<W_TYPE>& s_feature_PE66_3,
    hls::stream<W_TYPE>& s_feature_PE67_0, hls::stream<W_TYPE>& s_feature_PE67_1,
    hls::stream<W_TYPE>& s_feature_PE67_2, hls::stream<W_TYPE>& s_feature_PE67_3,
    hls::stream<W_TYPE>& s_feature_PE68_0, hls::stream<W_TYPE>& s_feature_PE68_1,
    hls::stream<W_TYPE>& s_feature_PE68_2, hls::stream<W_TYPE>& s_feature_PE68_3,
    hls::stream<W_TYPE>& s_feature_PE69_0, hls::stream<W_TYPE>& s_feature_PE69_1,
    hls::stream<W_TYPE>& s_feature_PE69_2, hls::stream<W_TYPE>& s_feature_PE69_3,
    hls::stream<W_TYPE>& s_feature_PE70_0, hls::stream<W_TYPE>& s_feature_PE70_1,
    hls::stream<W_TYPE>& s_feature_PE70_2, hls::stream<W_TYPE>& s_feature_PE70_3,
    hls::stream<W_TYPE>& s_feature_PE71_0, hls::stream<W_TYPE>& s_feature_PE71_1,
    hls::stream<W_TYPE>& s_feature_PE71_2, hls::stream<W_TYPE>& s_feature_PE71_3,
    hls::stream<W_TYPE>& s_feature_PE72_0, hls::stream<W_TYPE>& s_feature_PE72_1,
    hls::stream<W_TYPE>& s_feature_PE72_2, hls::stream<W_TYPE>& s_feature_PE72_3,
    hls::stream<W_TYPE>& s_feature_PE73_0, hls::stream<W_TYPE>& s_feature_PE73_1,
    hls::stream<W_TYPE>& s_feature_PE73_2, hls::stream<W_TYPE>& s_feature_PE73_3,
    hls::stream<W_TYPE>& s_feature_PE74_0, hls::stream<W_TYPE>& s_feature_PE74_1,
    hls::stream<W_TYPE>& s_feature_PE74_2, hls::stream<W_TYPE>& s_feature_PE74_3,
    hls::stream<W_TYPE>& s_feature_PE75_0, hls::stream<W_TYPE>& s_feature_PE75_1,
    hls::stream<W_TYPE>& s_feature_PE75_2, hls::stream<W_TYPE>& s_feature_PE75_3,
    hls::stream<W_TYPE>& s_feature_PE76_0, hls::stream<W_TYPE>& s_feature_PE76_1,
    hls::stream<W_TYPE>& s_feature_PE76_2, hls::stream<W_TYPE>& s_feature_PE76_3,
    hls::stream<W_TYPE>& s_feature_PE77_0, hls::stream<W_TYPE>& s_feature_PE77_1,
    hls::stream<W_TYPE>& s_feature_PE77_2, hls::stream<W_TYPE>& s_feature_PE77_3,
    hls::stream<W_TYPE>& s_feature_PE78_0, hls::stream<W_TYPE>& s_feature_PE78_1,
    hls::stream<W_TYPE>& s_feature_PE78_2, hls::stream<W_TYPE>& s_feature_PE78_3,
    hls::stream<W_TYPE>& s_feature_PE79_0, hls::stream<W_TYPE>& s_feature_PE79_1,
    hls::stream<W_TYPE>& s_feature_PE79_2, hls::stream<W_TYPE>& s_feature_PE79_3
){
        for (int i = 0; i < BATCH_NUM * BATCH_SIZE * FEATURE_SIZE / INTS_PER_W / 4; i++) {
            #pragma HLS pipeline II=1

            ap_uint<512> reg = s_feature_in.read();

            W_TYPE reg0 = reg.range(127, 0);
            W_TYPE reg1 = reg.range(255, 128);
            W_TYPE reg2 = reg.range(383, 256);
            W_TYPE reg3 = reg.range(511, 255);

            s_feature_PE0_0.write(reg0);
            s_feature_PE0_1.write(reg1);
            s_feature_PE0_2.write(reg2);
            s_feature_PE0_3.write(reg3);
            s_feature_PE1_0.write(reg0);
            s_feature_PE1_1.write(reg1);
            s_feature_PE1_2.write(reg2);
            s_feature_PE1_3.write(reg3);
            s_feature_PE2_0.write(reg0);
            s_feature_PE2_1.write(reg1);
            s_feature_PE2_2.write(reg2);
            s_feature_PE2_3.write(reg3);
            s_feature_PE3_0.write(reg0);
            s_feature_PE3_1.write(reg1);
            s_feature_PE3_2.write(reg2);
            s_feature_PE3_3.write(reg3);
            s_feature_PE4_0.write(reg0);
            s_feature_PE4_1.write(reg1);
            s_feature_PE4_2.write(reg2);
            s_feature_PE4_3.write(reg3);
            s_feature_PE5_0.write(reg0);
            s_feature_PE5_1.write(reg1);
            s_feature_PE5_2.write(reg2);
            s_feature_PE5_3.write(reg3);
            s_feature_PE6_0.write(reg0);
            s_feature_PE6_1.write(reg1);
            s_feature_PE6_2.write(reg2);
            s_feature_PE6_3.write(reg3);
            s_feature_PE7_0.write(reg0);
            s_feature_PE7_1.write(reg1);
            s_feature_PE7_2.write(reg2);
            s_feature_PE7_3.write(reg3);
            s_feature_PE8_0.write(reg0);
            s_feature_PE8_1.write(reg1);
            s_feature_PE8_2.write(reg2);
            s_feature_PE8_3.write(reg3);
            s_feature_PE9_0.write(reg0);
            s_feature_PE9_1.write(reg1);
            s_feature_PE9_2.write(reg2);
            s_feature_PE9_3.write(reg3);
            s_feature_PE10_0.write(reg0);
            s_feature_PE10_1.write(reg1);
            s_feature_PE10_2.write(reg2);
            s_feature_PE10_3.write(reg3);
            s_feature_PE11_0.write(reg0);
            s_feature_PE11_1.write(reg1);
            s_feature_PE11_2.write(reg2);
            s_feature_PE11_3.write(reg3);
            s_feature_PE12_0.write(reg0);
            s_feature_PE12_1.write(reg1);
            s_feature_PE12_2.write(reg2);
            s_feature_PE12_3.write(reg3);
            s_feature_PE13_0.write(reg0);
            s_feature_PE13_1.write(reg1);
            s_feature_PE13_2.write(reg2);
            s_feature_PE13_3.write(reg3);
            s_feature_PE14_0.write(reg0);
            s_feature_PE14_1.write(reg1);
            s_feature_PE14_2.write(reg2);
            s_feature_PE14_3.write(reg3);
            s_feature_PE15_0.write(reg0);
            s_feature_PE15_1.write(reg1);
            s_feature_PE15_2.write(reg2);
            s_feature_PE15_3.write(reg3);
            s_feature_PE16_0.write(reg0);
            s_feature_PE16_1.write(reg1);
            s_feature_PE16_2.write(reg2);
            s_feature_PE16_3.write(reg3);
            s_feature_PE17_0.write(reg0);
            s_feature_PE17_1.write(reg1);
            s_feature_PE17_2.write(reg2);
            s_feature_PE17_3.write(reg3);
            s_feature_PE18_0.write(reg0);
            s_feature_PE18_1.write(reg1);
            s_feature_PE18_2.write(reg2);
            s_feature_PE18_3.write(reg3);
            s_feature_PE19_0.write(reg0);
            s_feature_PE19_1.write(reg1);
            s_feature_PE19_2.write(reg2);
            s_feature_PE19_3.write(reg3);
            s_feature_PE20_0.write(reg0);
            s_feature_PE20_1.write(reg1);
            s_feature_PE20_2.write(reg2);
            s_feature_PE20_3.write(reg3);
            s_feature_PE21_0.write(reg0);
            s_feature_PE21_1.write(reg1);
            s_feature_PE21_2.write(reg2);
            s_feature_PE21_3.write(reg3);
            s_feature_PE22_0.write(reg0);
            s_feature_PE22_1.write(reg1);
            s_feature_PE22_2.write(reg2);
            s_feature_PE22_3.write(reg3);
            s_feature_PE23_0.write(reg0);
            s_feature_PE23_1.write(reg1);
            s_feature_PE23_2.write(reg2);
            s_feature_PE23_3.write(reg3);
            s_feature_PE24_0.write(reg0);
            s_feature_PE24_1.write(reg1);
            s_feature_PE24_2.write(reg2);
            s_feature_PE24_3.write(reg3);
            s_feature_PE25_0.write(reg0);
            s_feature_PE25_1.write(reg1);
            s_feature_PE25_2.write(reg2);
            s_feature_PE25_3.write(reg3);
            s_feature_PE26_0.write(reg0);
            s_feature_PE26_1.write(reg1);
            s_feature_PE26_2.write(reg2);
            s_feature_PE26_3.write(reg3);
            s_feature_PE27_0.write(reg0);
            s_feature_PE27_1.write(reg1);
            s_feature_PE27_2.write(reg2);
            s_feature_PE27_3.write(reg3);
            s_feature_PE28_0.write(reg0);
            s_feature_PE28_1.write(reg1);
            s_feature_PE28_2.write(reg2);
            s_feature_PE28_3.write(reg3);
            s_feature_PE29_0.write(reg0);
            s_feature_PE29_1.write(reg1);
            s_feature_PE29_2.write(reg2);
            s_feature_PE29_3.write(reg3);
            s_feature_PE30_0.write(reg0);
            s_feature_PE30_1.write(reg1);
            s_feature_PE30_2.write(reg2);
            s_feature_PE30_3.write(reg3);
            s_feature_PE31_0.write(reg0);
            s_feature_PE31_1.write(reg1);
            s_feature_PE31_2.write(reg2);
            s_feature_PE31_3.write(reg3);
            s_feature_PE32_0.write(reg0);
            s_feature_PE32_1.write(reg1);
            s_feature_PE32_2.write(reg2);
            s_feature_PE32_3.write(reg3);
            s_feature_PE33_0.write(reg0);
            s_feature_PE33_1.write(reg1);
            s_feature_PE33_2.write(reg2);
            s_feature_PE33_3.write(reg3);
            s_feature_PE34_0.write(reg0);
            s_feature_PE34_1.write(reg1);
            s_feature_PE34_2.write(reg2);
            s_feature_PE34_3.write(reg3);
            s_feature_PE35_0.write(reg0);
            s_feature_PE35_1.write(reg1);
            s_feature_PE35_2.write(reg2);
            s_feature_PE35_3.write(reg3);
            s_feature_PE36_0.write(reg0);
            s_feature_PE36_1.write(reg1);
            s_feature_PE36_2.write(reg2);
            s_feature_PE36_3.write(reg3);
            s_feature_PE37_0.write(reg0);
            s_feature_PE37_1.write(reg1);
            s_feature_PE37_2.write(reg2);
            s_feature_PE37_3.write(reg3);
            s_feature_PE38_0.write(reg0);
            s_feature_PE38_1.write(reg1);
            s_feature_PE38_2.write(reg2);
            s_feature_PE38_3.write(reg3);
            s_feature_PE39_0.write(reg0);
            s_feature_PE39_1.write(reg1);
            s_feature_PE39_2.write(reg2);
            s_feature_PE39_3.write(reg3);
            s_feature_PE40_0.write(reg0);
            s_feature_PE40_1.write(reg1);
            s_feature_PE40_2.write(reg2);
            s_feature_PE40_3.write(reg3);
            s_feature_PE41_0.write(reg0);
            s_feature_PE41_1.write(reg1);
            s_feature_PE41_2.write(reg2);
            s_feature_PE41_3.write(reg3);
            s_feature_PE42_0.write(reg0);
            s_feature_PE42_1.write(reg1);
            s_feature_PE42_2.write(reg2);
            s_feature_PE42_3.write(reg3);
            s_feature_PE43_0.write(reg0);
            s_feature_PE43_1.write(reg1);
            s_feature_PE43_2.write(reg2);
            s_feature_PE43_3.write(reg3);
            s_feature_PE44_0.write(reg0);
            s_feature_PE44_1.write(reg1);
            s_feature_PE44_2.write(reg2);
            s_feature_PE44_3.write(reg3);
            s_feature_PE45_0.write(reg0);
            s_feature_PE45_1.write(reg1);
            s_feature_PE45_2.write(reg2);
            s_feature_PE45_3.write(reg3);
            s_feature_PE46_0.write(reg0);
            s_feature_PE46_1.write(reg1);
            s_feature_PE46_2.write(reg2);
            s_feature_PE46_3.write(reg3);
            s_feature_PE47_0.write(reg0);
            s_feature_PE47_1.write(reg1);
            s_feature_PE47_2.write(reg2);
            s_feature_PE47_3.write(reg3);
            s_feature_PE48_0.write(reg0);
            s_feature_PE48_1.write(reg1);
            s_feature_PE48_2.write(reg2);
            s_feature_PE48_3.write(reg3);
            s_feature_PE49_0.write(reg0);
            s_feature_PE49_1.write(reg1);
            s_feature_PE49_2.write(reg2);
            s_feature_PE49_3.write(reg3);
            s_feature_PE50_0.write(reg0);
            s_feature_PE50_1.write(reg1);
            s_feature_PE50_2.write(reg2);
            s_feature_PE50_3.write(reg3);
            s_feature_PE51_0.write(reg0);
            s_feature_PE51_1.write(reg1);
            s_feature_PE51_2.write(reg2);
            s_feature_PE51_3.write(reg3);
            s_feature_PE52_0.write(reg0);
            s_feature_PE52_1.write(reg1);
            s_feature_PE52_2.write(reg2);
            s_feature_PE52_3.write(reg3);
            s_feature_PE53_0.write(reg0);
            s_feature_PE53_1.write(reg1);
            s_feature_PE53_2.write(reg2);
            s_feature_PE53_3.write(reg3);
            s_feature_PE54_0.write(reg0);
            s_feature_PE54_1.write(reg1);
            s_feature_PE54_2.write(reg2);
            s_feature_PE54_3.write(reg3);
            s_feature_PE55_0.write(reg0);
            s_feature_PE55_1.write(reg1);
            s_feature_PE55_2.write(reg2);
            s_feature_PE55_3.write(reg3);
            s_feature_PE56_0.write(reg0);
            s_feature_PE56_1.write(reg1);
            s_feature_PE56_2.write(reg2);
            s_feature_PE56_3.write(reg3);
            s_feature_PE57_0.write(reg0);
            s_feature_PE57_1.write(reg1);
            s_feature_PE57_2.write(reg2);
            s_feature_PE57_3.write(reg3);
            s_feature_PE58_0.write(reg0);
            s_feature_PE58_1.write(reg1);
            s_feature_PE58_2.write(reg2);
            s_feature_PE58_3.write(reg3);
            s_feature_PE59_0.write(reg0);
            s_feature_PE59_1.write(reg1);
            s_feature_PE59_2.write(reg2);
            s_feature_PE59_3.write(reg3);
            s_feature_PE60_0.write(reg0);
            s_feature_PE60_1.write(reg1);
            s_feature_PE60_2.write(reg2);
            s_feature_PE60_3.write(reg3);
            s_feature_PE61_0.write(reg0);
            s_feature_PE61_1.write(reg1);
            s_feature_PE61_2.write(reg2);
            s_feature_PE61_3.write(reg3);
            s_feature_PE62_0.write(reg0);
            s_feature_PE62_1.write(reg1);
            s_feature_PE62_2.write(reg2);
            s_feature_PE62_3.write(reg3);
            s_feature_PE63_0.write(reg0);
            s_feature_PE63_1.write(reg1);
            s_feature_PE63_2.write(reg2);
            s_feature_PE63_3.write(reg3);
            s_feature_PE64_0.write(reg0);
            s_feature_PE64_1.write(reg1);
            s_feature_PE64_2.write(reg2);
            s_feature_PE64_3.write(reg3);
            s_feature_PE65_0.write(reg0);
            s_feature_PE65_1.write(reg1);
            s_feature_PE65_2.write(reg2);
            s_feature_PE65_3.write(reg3);
            s_feature_PE66_0.write(reg0);
            s_feature_PE66_1.write(reg1);
            s_feature_PE66_2.write(reg2);
            s_feature_PE66_3.write(reg3);
            s_feature_PE67_0.write(reg0);
            s_feature_PE67_1.write(reg1);
            s_feature_PE67_2.write(reg2);
            s_feature_PE67_3.write(reg3);
            s_feature_PE68_0.write(reg0);
            s_feature_PE68_1.write(reg1);
            s_feature_PE68_2.write(reg2);
            s_feature_PE68_3.write(reg3);
            s_feature_PE69_0.write(reg0);
            s_feature_PE69_1.write(reg1);
            s_feature_PE69_2.write(reg2);
            s_feature_PE69_3.write(reg3);
            s_feature_PE70_0.write(reg0);
            s_feature_PE70_1.write(reg1);
            s_feature_PE70_2.write(reg2);
            s_feature_PE70_3.write(reg3);
            s_feature_PE71_0.write(reg0);
            s_feature_PE71_1.write(reg1);
            s_feature_PE71_2.write(reg2);
            s_feature_PE71_3.write(reg3);
            s_feature_PE72_0.write(reg0);
            s_feature_PE72_1.write(reg1);
            s_feature_PE72_2.write(reg2);
            s_feature_PE72_3.write(reg3);
            s_feature_PE73_0.write(reg0);
            s_feature_PE73_1.write(reg1);
            s_feature_PE73_2.write(reg2);
            s_feature_PE73_3.write(reg3);
            s_feature_PE74_0.write(reg0);
            s_feature_PE74_1.write(reg1);
            s_feature_PE74_2.write(reg2);
            s_feature_PE74_3.write(reg3);
            s_feature_PE75_0.write(reg0);
            s_feature_PE75_1.write(reg1);
            s_feature_PE75_2.write(reg2);
            s_feature_PE75_3.write(reg3);
            s_feature_PE76_0.write(reg0);
            s_feature_PE76_1.write(reg1);
            s_feature_PE76_2.write(reg2);
            s_feature_PE76_3.write(reg3);
            s_feature_PE77_0.write(reg0);
            s_feature_PE77_1.write(reg1);
            s_feature_PE77_2.write(reg2);
            s_feature_PE77_3.write(reg3);
            s_feature_PE78_0.write(reg0);
            s_feature_PE78_1.write(reg1);
            s_feature_PE78_2.write(reg2);
            s_feature_PE78_3.write(reg3);
            s_feature_PE79_0.write(reg0);
            s_feature_PE79_1.write(reg1);
            s_feature_PE79_2.write(reg2);
            s_feature_PE79_3.write(reg3);
        }
}

template<const int FEATURE_SIZE>
void replicate_feature_512PEs_40PE(
    hls::stream<ap_uint<512> >& s_feature_in, 
    hls::stream<W_TYPE>& s_feature_PE0_0, hls::stream<W_TYPE>& s_feature_PE0_1,
    hls::stream<W_TYPE>& s_feature_PE0_2, hls::stream<W_TYPE>& s_feature_PE0_3,
    hls::stream<W_TYPE>& s_feature_PE1_0, hls::stream<W_TYPE>& s_feature_PE1_1,
    hls::stream<W_TYPE>& s_feature_PE1_2, hls::stream<W_TYPE>& s_feature_PE1_3,
    hls::stream<W_TYPE>& s_feature_PE2_0, hls::stream<W_TYPE>& s_feature_PE2_1,
    hls::stream<W_TYPE>& s_feature_PE2_2, hls::stream<W_TYPE>& s_feature_PE2_3,
    hls::stream<W_TYPE>& s_feature_PE3_0, hls::stream<W_TYPE>& s_feature_PE3_1,
    hls::stream<W_TYPE>& s_feature_PE3_2, hls::stream<W_TYPE>& s_feature_PE3_3,
    hls::stream<W_TYPE>& s_feature_PE4_0, hls::stream<W_TYPE>& s_feature_PE4_1,
    hls::stream<W_TYPE>& s_feature_PE4_2, hls::stream<W_TYPE>& s_feature_PE4_3,
    hls::stream<W_TYPE>& s_feature_PE5_0, hls::stream<W_TYPE>& s_feature_PE5_1,
    hls::stream<W_TYPE>& s_feature_PE5_2, hls::stream<W_TYPE>& s_feature_PE5_3,
    hls::stream<W_TYPE>& s_feature_PE6_0, hls::stream<W_TYPE>& s_feature_PE6_1,
    hls::stream<W_TYPE>& s_feature_PE6_2, hls::stream<W_TYPE>& s_feature_PE6_3,
    hls::stream<W_TYPE>& s_feature_PE7_0, hls::stream<W_TYPE>& s_feature_PE7_1,
    hls::stream<W_TYPE>& s_feature_PE7_2, hls::stream<W_TYPE>& s_feature_PE7_3,
    hls::stream<W_TYPE>& s_feature_PE8_0, hls::stream<W_TYPE>& s_feature_PE8_1,
    hls::stream<W_TYPE>& s_feature_PE8_2, hls::stream<W_TYPE>& s_feature_PE8_3,
    hls::stream<W_TYPE>& s_feature_PE9_0, hls::stream<W_TYPE>& s_feature_PE9_1,
    hls::stream<W_TYPE>& s_feature_PE9_2, hls::stream<W_TYPE>& s_feature_PE9_3,
    hls::stream<W_TYPE>& s_feature_PE10_0, hls::stream<W_TYPE>& s_feature_PE10_1,
    hls::stream<W_TYPE>& s_feature_PE10_2, hls::stream<W_TYPE>& s_feature_PE10_3,
    hls::stream<W_TYPE>& s_feature_PE11_0, hls::stream<W_TYPE>& s_feature_PE11_1,
    hls::stream<W_TYPE>& s_feature_PE11_2, hls::stream<W_TYPE>& s_feature_PE11_3,
    hls::stream<W_TYPE>& s_feature_PE12_0, hls::stream<W_TYPE>& s_feature_PE12_1,
    hls::stream<W_TYPE>& s_feature_PE12_2, hls::stream<W_TYPE>& s_feature_PE12_3,
    hls::stream<W_TYPE>& s_feature_PE13_0, hls::stream<W_TYPE>& s_feature_PE13_1,
    hls::stream<W_TYPE>& s_feature_PE13_2, hls::stream<W_TYPE>& s_feature_PE13_3,
    hls::stream<W_TYPE>& s_feature_PE14_0, hls::stream<W_TYPE>& s_feature_PE14_1,
    hls::stream<W_TYPE>& s_feature_PE14_2, hls::stream<W_TYPE>& s_feature_PE14_3,
    hls::stream<W_TYPE>& s_feature_PE15_0, hls::stream<W_TYPE>& s_feature_PE15_1,
    hls::stream<W_TYPE>& s_feature_PE15_2, hls::stream<W_TYPE>& s_feature_PE15_3,
    hls::stream<W_TYPE>& s_feature_PE16_0, hls::stream<W_TYPE>& s_feature_PE16_1,
    hls::stream<W_TYPE>& s_feature_PE16_2, hls::stream<W_TYPE>& s_feature_PE16_3,
    hls::stream<W_TYPE>& s_feature_PE17_0, hls::stream<W_TYPE>& s_feature_PE17_1,
    hls::stream<W_TYPE>& s_feature_PE17_2, hls::stream<W_TYPE>& s_feature_PE17_3,
    hls::stream<W_TYPE>& s_feature_PE18_0, hls::stream<W_TYPE>& s_feature_PE18_1,
    hls::stream<W_TYPE>& s_feature_PE18_2, hls::stream<W_TYPE>& s_feature_PE18_3,
    hls::stream<W_TYPE>& s_feature_PE19_0, hls::stream<W_TYPE>& s_feature_PE19_1,
    hls::stream<W_TYPE>& s_feature_PE19_2, hls::stream<W_TYPE>& s_feature_PE19_3,
    hls::stream<W_TYPE>& s_feature_PE20_0, hls::stream<W_TYPE>& s_feature_PE20_1,
    hls::stream<W_TYPE>& s_feature_PE20_2, hls::stream<W_TYPE>& s_feature_PE20_3,
    hls::stream<W_TYPE>& s_feature_PE21_0, hls::stream<W_TYPE>& s_feature_PE21_1,
    hls::stream<W_TYPE>& s_feature_PE21_2, hls::stream<W_TYPE>& s_feature_PE21_3,
    hls::stream<W_TYPE>& s_feature_PE22_0, hls::stream<W_TYPE>& s_feature_PE22_1,
    hls::stream<W_TYPE>& s_feature_PE22_2, hls::stream<W_TYPE>& s_feature_PE22_3,
    hls::stream<W_TYPE>& s_feature_PE23_0, hls::stream<W_TYPE>& s_feature_PE23_1,
    hls::stream<W_TYPE>& s_feature_PE23_2, hls::stream<W_TYPE>& s_feature_PE23_3,
    hls::stream<W_TYPE>& s_feature_PE24_0, hls::stream<W_TYPE>& s_feature_PE24_1,
    hls::stream<W_TYPE>& s_feature_PE24_2, hls::stream<W_TYPE>& s_feature_PE24_3,
    hls::stream<W_TYPE>& s_feature_PE25_0, hls::stream<W_TYPE>& s_feature_PE25_1,
    hls::stream<W_TYPE>& s_feature_PE25_2, hls::stream<W_TYPE>& s_feature_PE25_3,
    hls::stream<W_TYPE>& s_feature_PE26_0, hls::stream<W_TYPE>& s_feature_PE26_1,
    hls::stream<W_TYPE>& s_feature_PE26_2, hls::stream<W_TYPE>& s_feature_PE26_3,
    hls::stream<W_TYPE>& s_feature_PE27_0, hls::stream<W_TYPE>& s_feature_PE27_1,
    hls::stream<W_TYPE>& s_feature_PE27_2, hls::stream<W_TYPE>& s_feature_PE27_3,
    hls::stream<W_TYPE>& s_feature_PE28_0, hls::stream<W_TYPE>& s_feature_PE28_1,
    hls::stream<W_TYPE>& s_feature_PE28_2, hls::stream<W_TYPE>& s_feature_PE28_3,
    hls::stream<W_TYPE>& s_feature_PE29_0, hls::stream<W_TYPE>& s_feature_PE29_1,
    hls::stream<W_TYPE>& s_feature_PE29_2, hls::stream<W_TYPE>& s_feature_PE29_3,
    hls::stream<W_TYPE>& s_feature_PE30_0, hls::stream<W_TYPE>& s_feature_PE30_1,
    hls::stream<W_TYPE>& s_feature_PE30_2, hls::stream<W_TYPE>& s_feature_PE30_3,
    hls::stream<W_TYPE>& s_feature_PE31_0, hls::stream<W_TYPE>& s_feature_PE31_1,
    hls::stream<W_TYPE>& s_feature_PE31_2, hls::stream<W_TYPE>& s_feature_PE31_3,
    hls::stream<W_TYPE>& s_feature_PE32_0, hls::stream<W_TYPE>& s_feature_PE32_1,
    hls::stream<W_TYPE>& s_feature_PE32_2, hls::stream<W_TYPE>& s_feature_PE32_3,
    hls::stream<W_TYPE>& s_feature_PE33_0, hls::stream<W_TYPE>& s_feature_PE33_1,
    hls::stream<W_TYPE>& s_feature_PE33_2, hls::stream<W_TYPE>& s_feature_PE33_3,
    hls::stream<W_TYPE>& s_feature_PE34_0, hls::stream<W_TYPE>& s_feature_PE34_1,
    hls::stream<W_TYPE>& s_feature_PE34_2, hls::stream<W_TYPE>& s_feature_PE34_3,
    hls::stream<W_TYPE>& s_feature_PE35_0, hls::stream<W_TYPE>& s_feature_PE35_1,
    hls::stream<W_TYPE>& s_feature_PE35_2, hls::stream<W_TYPE>& s_feature_PE35_3,
    hls::stream<W_TYPE>& s_feature_PE36_0, hls::stream<W_TYPE>& s_feature_PE36_1,
    hls::stream<W_TYPE>& s_feature_PE36_2, hls::stream<W_TYPE>& s_feature_PE36_3,
    hls::stream<W_TYPE>& s_feature_PE37_0, hls::stream<W_TYPE>& s_feature_PE37_1,
    hls::stream<W_TYPE>& s_feature_PE37_2, hls::stream<W_TYPE>& s_feature_PE37_3,
    hls::stream<W_TYPE>& s_feature_PE38_0, hls::stream<W_TYPE>& s_feature_PE38_1,
    hls::stream<W_TYPE>& s_feature_PE38_2, hls::stream<W_TYPE>& s_feature_PE38_3,
    hls::stream<W_TYPE>& s_feature_PE39_0, hls::stream<W_TYPE>& s_feature_PE39_1,
    hls::stream<W_TYPE>& s_feature_PE39_2, hls::stream<W_TYPE>& s_feature_PE39_3
){
        for (int i = 0; i < BATCH_NUM * BATCH_SIZE * FEATURE_SIZE / INTS_PER_W / 4; i++) {
            #pragma HLS pipeline II=1

            ap_uint<512> reg = s_feature_in.read();

            W_TYPE reg0 = reg.range(127, 0);
            W_TYPE reg1 = reg.range(255, 128);
            W_TYPE reg2 = reg.range(383, 256);
            W_TYPE reg3 = reg.range(511, 255);

            s_feature_PE0_0.write(reg0);
            s_feature_PE0_1.write(reg1);
            s_feature_PE0_2.write(reg2);
            s_feature_PE0_3.write(reg3);
            s_feature_PE1_0.write(reg0);
            s_feature_PE1_1.write(reg1);
            s_feature_PE1_2.write(reg2);
            s_feature_PE1_3.write(reg3);
            s_feature_PE2_0.write(reg0);
            s_feature_PE2_1.write(reg1);
            s_feature_PE2_2.write(reg2);
            s_feature_PE2_3.write(reg3);
            s_feature_PE3_0.write(reg0);
            s_feature_PE3_1.write(reg1);
            s_feature_PE3_2.write(reg2);
            s_feature_PE3_3.write(reg3);
            s_feature_PE4_0.write(reg0);
            s_feature_PE4_1.write(reg1);
            s_feature_PE4_2.write(reg2);
            s_feature_PE4_3.write(reg3);
            s_feature_PE5_0.write(reg0);
            s_feature_PE5_1.write(reg1);
            s_feature_PE5_2.write(reg2);
            s_feature_PE5_3.write(reg3);
            s_feature_PE6_0.write(reg0);
            s_feature_PE6_1.write(reg1);
            s_feature_PE6_2.write(reg2);
            s_feature_PE6_3.write(reg3);
            s_feature_PE7_0.write(reg0);
            s_feature_PE7_1.write(reg1);
            s_feature_PE7_2.write(reg2);
            s_feature_PE7_3.write(reg3);
            s_feature_PE8_0.write(reg0);
            s_feature_PE8_1.write(reg1);
            s_feature_PE8_2.write(reg2);
            s_feature_PE8_3.write(reg3);
            s_feature_PE9_0.write(reg0);
            s_feature_PE9_1.write(reg1);
            s_feature_PE9_2.write(reg2);
            s_feature_PE9_3.write(reg3);
            s_feature_PE10_0.write(reg0);
            s_feature_PE10_1.write(reg1);
            s_feature_PE10_2.write(reg2);
            s_feature_PE10_3.write(reg3);
            s_feature_PE11_0.write(reg0);
            s_feature_PE11_1.write(reg1);
            s_feature_PE11_2.write(reg2);
            s_feature_PE11_3.write(reg3);
            s_feature_PE12_0.write(reg0);
            s_feature_PE12_1.write(reg1);
            s_feature_PE12_2.write(reg2);
            s_feature_PE12_3.write(reg3);
            s_feature_PE13_0.write(reg0);
            s_feature_PE13_1.write(reg1);
            s_feature_PE13_2.write(reg2);
            s_feature_PE13_3.write(reg3);
            s_feature_PE14_0.write(reg0);
            s_feature_PE14_1.write(reg1);
            s_feature_PE14_2.write(reg2);
            s_feature_PE14_3.write(reg3);
            s_feature_PE15_0.write(reg0);
            s_feature_PE15_1.write(reg1);
            s_feature_PE15_2.write(reg2);
            s_feature_PE15_3.write(reg3);
            s_feature_PE16_0.write(reg0);
            s_feature_PE16_1.write(reg1);
            s_feature_PE16_2.write(reg2);
            s_feature_PE16_3.write(reg3);
            s_feature_PE17_0.write(reg0);
            s_feature_PE17_1.write(reg1);
            s_feature_PE17_2.write(reg2);
            s_feature_PE17_3.write(reg3);
            s_feature_PE18_0.write(reg0);
            s_feature_PE18_1.write(reg1);
            s_feature_PE18_2.write(reg2);
            s_feature_PE18_3.write(reg3);
            s_feature_PE19_0.write(reg0);
            s_feature_PE19_1.write(reg1);
            s_feature_PE19_2.write(reg2);
            s_feature_PE19_3.write(reg3);
            s_feature_PE20_0.write(reg0);
            s_feature_PE20_1.write(reg1);
            s_feature_PE20_2.write(reg2);
            s_feature_PE20_3.write(reg3);
            s_feature_PE21_0.write(reg0);
            s_feature_PE21_1.write(reg1);
            s_feature_PE21_2.write(reg2);
            s_feature_PE21_3.write(reg3);
            s_feature_PE22_0.write(reg0);
            s_feature_PE22_1.write(reg1);
            s_feature_PE22_2.write(reg2);
            s_feature_PE22_3.write(reg3);
            s_feature_PE23_0.write(reg0);
            s_feature_PE23_1.write(reg1);
            s_feature_PE23_2.write(reg2);
            s_feature_PE23_3.write(reg3);
            s_feature_PE24_0.write(reg0);
            s_feature_PE24_1.write(reg1);
            s_feature_PE24_2.write(reg2);
            s_feature_PE24_3.write(reg3);
            s_feature_PE25_0.write(reg0);
            s_feature_PE25_1.write(reg1);
            s_feature_PE25_2.write(reg2);
            s_feature_PE25_3.write(reg3);
            s_feature_PE26_0.write(reg0);
            s_feature_PE26_1.write(reg1);
            s_feature_PE26_2.write(reg2);
            s_feature_PE26_3.write(reg3);
            s_feature_PE27_0.write(reg0);
            s_feature_PE27_1.write(reg1);
            s_feature_PE27_2.write(reg2);
            s_feature_PE27_3.write(reg3);
            s_feature_PE28_0.write(reg0);
            s_feature_PE28_1.write(reg1);
            s_feature_PE28_2.write(reg2);
            s_feature_PE28_3.write(reg3);
            s_feature_PE29_0.write(reg0);
            s_feature_PE29_1.write(reg1);
            s_feature_PE29_2.write(reg2);
            s_feature_PE29_3.write(reg3);
            s_feature_PE30_0.write(reg0);
            s_feature_PE30_1.write(reg1);
            s_feature_PE30_2.write(reg2);
            s_feature_PE30_3.write(reg3);
            s_feature_PE31_0.write(reg0);
            s_feature_PE31_1.write(reg1);
            s_feature_PE31_2.write(reg2);
            s_feature_PE31_3.write(reg3);
            s_feature_PE32_0.write(reg0);
            s_feature_PE32_1.write(reg1);
            s_feature_PE32_2.write(reg2);
            s_feature_PE32_3.write(reg3);
            s_feature_PE33_0.write(reg0);
            s_feature_PE33_1.write(reg1);
            s_feature_PE33_2.write(reg2);
            s_feature_PE33_3.write(reg3);
            s_feature_PE34_0.write(reg0);
            s_feature_PE34_1.write(reg1);
            s_feature_PE34_2.write(reg2);
            s_feature_PE34_3.write(reg3);
            s_feature_PE35_0.write(reg0);
            s_feature_PE35_1.write(reg1);
            s_feature_PE35_2.write(reg2);
            s_feature_PE35_3.write(reg3);
            s_feature_PE36_0.write(reg0);
            s_feature_PE36_1.write(reg1);
            s_feature_PE36_2.write(reg2);
            s_feature_PE36_3.write(reg3);
            s_feature_PE37_0.write(reg0);
            s_feature_PE37_1.write(reg1);
            s_feature_PE37_2.write(reg2);
            s_feature_PE37_3.write(reg3);
            s_feature_PE38_0.write(reg0);
            s_feature_PE38_1.write(reg1);
            s_feature_PE38_2.write(reg2);
            s_feature_PE38_3.write(reg3);
            s_feature_PE39_0.write(reg0);
            s_feature_PE39_1.write(reg1);
            s_feature_PE39_2.write(reg2);
            s_feature_PE39_3.write(reg3);
        }
}

template<const int FEATURE_SIZE>
void replicate_feature_512PEs_32PE(
    hls::stream<ap_uint<512> >& s_feature_in, 
    hls::stream<W_TYPE>& s_feature_PE0_0, hls::stream<W_TYPE>& s_feature_PE0_1,
    hls::stream<W_TYPE>& s_feature_PE1_0, hls::stream<W_TYPE>& s_feature_PE1_1,
    hls::stream<W_TYPE>& s_feature_PE2_0, hls::stream<W_TYPE>& s_feature_PE2_1,
    hls::stream<W_TYPE>& s_feature_PE3_0, hls::stream<W_TYPE>& s_feature_PE3_1,
    hls::stream<W_TYPE>& s_feature_PE4_0, hls::stream<W_TYPE>& s_feature_PE4_1,
    hls::stream<W_TYPE>& s_feature_PE5_0, hls::stream<W_TYPE>& s_feature_PE5_1,
    hls::stream<W_TYPE>& s_feature_PE6_0, hls::stream<W_TYPE>& s_feature_PE6_1,
    hls::stream<W_TYPE>& s_feature_PE7_0, hls::stream<W_TYPE>& s_feature_PE7_1,
    hls::stream<W_TYPE>& s_feature_PE8_0, hls::stream<W_TYPE>& s_feature_PE8_1,
    hls::stream<W_TYPE>& s_feature_PE9_0, hls::stream<W_TYPE>& s_feature_PE9_1,
    hls::stream<W_TYPE>& s_feature_PE10_0, hls::stream<W_TYPE>& s_feature_PE10_1,
    hls::stream<W_TYPE>& s_feature_PE11_0, hls::stream<W_TYPE>& s_feature_PE11_1,
    hls::stream<W_TYPE>& s_feature_PE12_0, hls::stream<W_TYPE>& s_feature_PE12_1,
    hls::stream<W_TYPE>& s_feature_PE13_0, hls::stream<W_TYPE>& s_feature_PE13_1,
    hls::stream<W_TYPE>& s_feature_PE14_0, hls::stream<W_TYPE>& s_feature_PE14_1,
    hls::stream<W_TYPE>& s_feature_PE15_0, hls::stream<W_TYPE>& s_feature_PE15_1,
    hls::stream<W_TYPE>& s_feature_PE16_0, hls::stream<W_TYPE>& s_feature_PE16_1,
    hls::stream<W_TYPE>& s_feature_PE17_0, hls::stream<W_TYPE>& s_feature_PE17_1,
    hls::stream<W_TYPE>& s_feature_PE18_0, hls::stream<W_TYPE>& s_feature_PE18_1,
    hls::stream<W_TYPE>& s_feature_PE19_0, hls::stream<W_TYPE>& s_feature_PE19_1,
    hls::stream<W_TYPE>& s_feature_PE20_0, hls::stream<W_TYPE>& s_feature_PE20_1,
    hls::stream<W_TYPE>& s_feature_PE21_0, hls::stream<W_TYPE>& s_feature_PE21_1,
    hls::stream<W_TYPE>& s_feature_PE22_0, hls::stream<W_TYPE>& s_feature_PE22_1,
    hls::stream<W_TYPE>& s_feature_PE23_0, hls::stream<W_TYPE>& s_feature_PE23_1,
    hls::stream<W_TYPE>& s_feature_PE24_0, hls::stream<W_TYPE>& s_feature_PE24_1,
    hls::stream<W_TYPE>& s_feature_PE25_0, hls::stream<W_TYPE>& s_feature_PE25_1,
    hls::stream<W_TYPE>& s_feature_PE26_0, hls::stream<W_TYPE>& s_feature_PE26_1,
    hls::stream<W_TYPE>& s_feature_PE27_0, hls::stream<W_TYPE>& s_feature_PE27_1,
    hls::stream<W_TYPE>& s_feature_PE28_0, hls::stream<W_TYPE>& s_feature_PE28_1,
    hls::stream<W_TYPE>& s_feature_PE29_0, hls::stream<W_TYPE>& s_feature_PE29_1,
    hls::stream<W_TYPE>& s_feature_PE30_0, hls::stream<W_TYPE>& s_feature_PE30_1,
    hls::stream<W_TYPE>& s_feature_PE31_0, hls::stream<W_TYPE>& s_feature_PE31_1
){
        for (int i = 0; i < BATCH_NUM * BATCH_SIZE * FEATURE_SIZE / INTS_PER_W / 4; i++) {
            #pragma HLS pipeline II=2

            ap_uint<512> reg = s_feature_in.read();

            W_TYPE reg0 = reg.range(127, 0);
            W_TYPE reg1 = reg.range(255, 128);
            W_TYPE reg2 = reg.range(383, 256);
            W_TYPE reg3 = reg.range(511, 255);

            s_feature_PE0_0.write(reg0);
            s_feature_PE0_1.write(reg1);
            s_feature_PE0_0.write(reg2);
            s_feature_PE0_1.write(reg3);
            s_feature_PE1_0.write(reg0);
            s_feature_PE1_1.write(reg1);
            s_feature_PE1_0.write(reg2);
            s_feature_PE1_1.write(reg3);
            s_feature_PE2_0.write(reg0);
            s_feature_PE2_1.write(reg1);
            s_feature_PE2_0.write(reg2);
            s_feature_PE2_1.write(reg3);
            s_feature_PE3_0.write(reg0);
            s_feature_PE3_1.write(reg1);
            s_feature_PE3_0.write(reg2);
            s_feature_PE3_1.write(reg3);
            s_feature_PE4_0.write(reg0);
            s_feature_PE4_1.write(reg1);
            s_feature_PE4_0.write(reg2);
            s_feature_PE4_1.write(reg3);
            s_feature_PE5_0.write(reg0);
            s_feature_PE5_1.write(reg1);
            s_feature_PE5_0.write(reg2);
            s_feature_PE5_1.write(reg3);
            s_feature_PE6_0.write(reg0);
            s_feature_PE6_1.write(reg1);
            s_feature_PE6_0.write(reg2);
            s_feature_PE6_1.write(reg3);
            s_feature_PE7_0.write(reg0);
            s_feature_PE7_1.write(reg1);
            s_feature_PE7_0.write(reg2);
            s_feature_PE7_1.write(reg3);
            s_feature_PE8_0.write(reg0);
            s_feature_PE8_1.write(reg1);
            s_feature_PE8_0.write(reg2);
            s_feature_PE8_1.write(reg3);
            s_feature_PE9_0.write(reg0);
            s_feature_PE9_1.write(reg1);
            s_feature_PE9_0.write(reg2);
            s_feature_PE9_1.write(reg3);
            s_feature_PE10_0.write(reg0);
            s_feature_PE10_1.write(reg1);
            s_feature_PE10_0.write(reg2);
            s_feature_PE10_1.write(reg3);
            s_feature_PE11_0.write(reg0);
            s_feature_PE11_1.write(reg1);
            s_feature_PE11_0.write(reg2);
            s_feature_PE11_1.write(reg3);
            s_feature_PE12_0.write(reg0);
            s_feature_PE12_1.write(reg1);
            s_feature_PE12_0.write(reg2);
            s_feature_PE12_1.write(reg3);
            s_feature_PE13_0.write(reg0);
            s_feature_PE13_1.write(reg1);
            s_feature_PE13_0.write(reg2);
            s_feature_PE13_1.write(reg3);
            s_feature_PE14_0.write(reg0);
            s_feature_PE14_1.write(reg1);
            s_feature_PE14_0.write(reg2);
            s_feature_PE14_1.write(reg3);
            s_feature_PE15_0.write(reg0);
            s_feature_PE15_1.write(reg1);
            s_feature_PE15_0.write(reg2);
            s_feature_PE15_1.write(reg3);
            s_feature_PE16_0.write(reg0);
            s_feature_PE16_1.write(reg1);
            s_feature_PE16_0.write(reg2);
            s_feature_PE16_1.write(reg3);
            s_feature_PE17_0.write(reg0);
            s_feature_PE17_1.write(reg1);
            s_feature_PE17_0.write(reg2);
            s_feature_PE17_1.write(reg3);
            s_feature_PE18_0.write(reg0);
            s_feature_PE18_1.write(reg1);
            s_feature_PE18_0.write(reg2);
            s_feature_PE18_1.write(reg3);
            s_feature_PE19_0.write(reg0);
            s_feature_PE19_1.write(reg1);
            s_feature_PE19_0.write(reg2);
            s_feature_PE19_1.write(reg3);
            s_feature_PE20_0.write(reg0);
            s_feature_PE20_1.write(reg1);
            s_feature_PE20_0.write(reg2);
            s_feature_PE20_1.write(reg3);
            s_feature_PE21_0.write(reg0);
            s_feature_PE21_1.write(reg1);
            s_feature_PE21_0.write(reg2);
            s_feature_PE21_1.write(reg3);
            s_feature_PE22_0.write(reg0);
            s_feature_PE22_1.write(reg1);
            s_feature_PE22_0.write(reg2);
            s_feature_PE22_1.write(reg3);
            s_feature_PE23_0.write(reg0);
            s_feature_PE23_1.write(reg1);
            s_feature_PE23_0.write(reg2);
            s_feature_PE23_1.write(reg3);
            s_feature_PE24_0.write(reg0);
            s_feature_PE24_1.write(reg1);
            s_feature_PE24_0.write(reg2);
            s_feature_PE24_1.write(reg3);
            s_feature_PE25_0.write(reg0);
            s_feature_PE25_1.write(reg1);
            s_feature_PE25_0.write(reg2);
            s_feature_PE25_1.write(reg3);
            s_feature_PE26_0.write(reg0);
            s_feature_PE26_1.write(reg1);
            s_feature_PE26_0.write(reg2);
            s_feature_PE26_1.write(reg3);
            s_feature_PE27_0.write(reg0);
            s_feature_PE27_1.write(reg1);
            s_feature_PE27_0.write(reg2);
            s_feature_PE27_1.write(reg3);
            s_feature_PE28_0.write(reg0);
            s_feature_PE28_1.write(reg1);
            s_feature_PE28_0.write(reg2);
            s_feature_PE28_1.write(reg3);
            s_feature_PE29_0.write(reg0);
            s_feature_PE29_1.write(reg1);
            s_feature_PE29_0.write(reg2);
            s_feature_PE29_1.write(reg3);
            s_feature_PE30_0.write(reg0);
            s_feature_PE30_1.write(reg1);
            s_feature_PE30_0.write(reg2);
            s_feature_PE30_1.write(reg3);
            s_feature_PE31_0.write(reg0);
            s_feature_PE31_1.write(reg1);
            s_feature_PE31_0.write(reg2);
            s_feature_PE31_1.write(reg3);
        }
}

template<const int ROW_PER_PE>
void gather_results_512PEs_320PE(
    hls::stream<D_TYPE>& s_result_PE0, hls::stream<D_TYPE>& s_result_PE1, 
    hls::stream<D_TYPE>& s_result_PE2, hls::stream<D_TYPE>& s_result_PE3, 
    hls::stream<D_TYPE>& s_result_PE4, hls::stream<D_TYPE>& s_result_PE5, 
    hls::stream<D_TYPE>& s_result_PE6, hls::stream<D_TYPE>& s_result_PE7, 
    hls::stream<D_TYPE>& s_result_PE8, hls::stream<D_TYPE>& s_result_PE9, 
    hls::stream<D_TYPE>& s_result_PE10, hls::stream<D_TYPE>& s_result_PE11, 
    hls::stream<D_TYPE>& s_result_PE12, hls::stream<D_TYPE>& s_result_PE13, 
    hls::stream<D_TYPE>& s_result_PE14, hls::stream<D_TYPE>& s_result_PE15, 
    hls::stream<D_TYPE>& s_result_PE16, hls::stream<D_TYPE>& s_result_PE17, 
    hls::stream<D_TYPE>& s_result_PE18, hls::stream<D_TYPE>& s_result_PE19, 
    hls::stream<D_TYPE>& s_result_PE20, hls::stream<D_TYPE>& s_result_PE21, 
    hls::stream<D_TYPE>& s_result_PE22, hls::stream<D_TYPE>& s_result_PE23, 
    hls::stream<D_TYPE>& s_result_PE24, hls::stream<D_TYPE>& s_result_PE25, 
    hls::stream<D_TYPE>& s_result_PE26, hls::stream<D_TYPE>& s_result_PE27, 
    hls::stream<D_TYPE>& s_result_PE28, hls::stream<D_TYPE>& s_result_PE29, 
    hls::stream<D_TYPE>& s_result_PE30, hls::stream<D_TYPE>& s_result_PE31, 
    hls::stream<D_TYPE>& s_result_PE32, hls::stream<D_TYPE>& s_result_PE33, 
    hls::stream<D_TYPE>& s_result_PE34, hls::stream<D_TYPE>& s_result_PE35, 
    hls::stream<D_TYPE>& s_result_PE36, hls::stream<D_TYPE>& s_result_PE37, 
    hls::stream<D_TYPE>& s_result_PE38, hls::stream<D_TYPE>& s_result_PE39, 
    hls::stream<D_TYPE>& s_result_PE40, hls::stream<D_TYPE>& s_result_PE41, 
    hls::stream<D_TYPE>& s_result_PE42, hls::stream<D_TYPE>& s_result_PE43, 
    hls::stream<D_TYPE>& s_result_PE44, hls::stream<D_TYPE>& s_result_PE45, 
    hls::stream<D_TYPE>& s_result_PE46, hls::stream<D_TYPE>& s_result_PE47, 
    hls::stream<D_TYPE>& s_result_PE48, hls::stream<D_TYPE>& s_result_PE49, 
    hls::stream<D_TYPE>& s_result_PE50, hls::stream<D_TYPE>& s_result_PE51, 
    hls::stream<D_TYPE>& s_result_PE52, hls::stream<D_TYPE>& s_result_PE53, 
    hls::stream<D_TYPE>& s_result_PE54, hls::stream<D_TYPE>& s_result_PE55, 
    hls::stream<D_TYPE>& s_result_PE56, hls::stream<D_TYPE>& s_result_PE57, 
    hls::stream<D_TYPE>& s_result_PE58, hls::stream<D_TYPE>& s_result_PE59, 
    hls::stream<D_TYPE>& s_result_PE60, hls::stream<D_TYPE>& s_result_PE61, 
    hls::stream<D_TYPE>& s_result_PE62, hls::stream<D_TYPE>& s_result_PE63, 
    hls::stream<D_TYPE>& s_result_PE64, hls::stream<D_TYPE>& s_result_PE65, 
    hls::stream<D_TYPE>& s_result_PE66, hls::stream<D_TYPE>& s_result_PE67, 
    hls::stream<D_TYPE>& s_result_PE68, hls::stream<D_TYPE>& s_result_PE69, 
    hls::stream<D_TYPE>& s_result_PE70, hls::stream<D_TYPE>& s_result_PE71, 
    hls::stream<D_TYPE>& s_result_PE72, hls::stream<D_TYPE>& s_result_PE73, 
    hls::stream<D_TYPE>& s_result_PE74, hls::stream<D_TYPE>& s_result_PE75, 
    hls::stream<D_TYPE>& s_result_PE76, hls::stream<D_TYPE>& s_result_PE77, 
    hls::stream<D_TYPE>& s_result_PE78, hls::stream<D_TYPE>& s_result_PE79, 
    hls::stream<D_TYPE>& s_result_PE80, hls::stream<D_TYPE>& s_result_PE81, 
    hls::stream<D_TYPE>& s_result_PE82, hls::stream<D_TYPE>& s_result_PE83, 
    hls::stream<D_TYPE>& s_result_PE84, hls::stream<D_TYPE>& s_result_PE85, 
    hls::stream<D_TYPE>& s_result_PE86, hls::stream<D_TYPE>& s_result_PE87, 
    hls::stream<D_TYPE>& s_result_PE88, hls::stream<D_TYPE>& s_result_PE89, 
    hls::stream<D_TYPE>& s_result_PE90, hls::stream<D_TYPE>& s_result_PE91, 
    hls::stream<D_TYPE>& s_result_PE92, hls::stream<D_TYPE>& s_result_PE93, 
    hls::stream<D_TYPE>& s_result_PE94, hls::stream<D_TYPE>& s_result_PE95, 
    hls::stream<D_TYPE>& s_result_PE96, hls::stream<D_TYPE>& s_result_PE97, 
    hls::stream<D_TYPE>& s_result_PE98, hls::stream<D_TYPE>& s_result_PE99, 
    hls::stream<D_TYPE>& s_result_PE100, hls::stream<D_TYPE>& s_result_PE101, 
    hls::stream<D_TYPE>& s_result_PE102, hls::stream<D_TYPE>& s_result_PE103, 
    hls::stream<D_TYPE>& s_result_PE104, hls::stream<D_TYPE>& s_result_PE105, 
    hls::stream<D_TYPE>& s_result_PE106, hls::stream<D_TYPE>& s_result_PE107, 
    hls::stream<D_TYPE>& s_result_PE108, hls::stream<D_TYPE>& s_result_PE109, 
    hls::stream<D_TYPE>& s_result_PE110, hls::stream<D_TYPE>& s_result_PE111, 
    hls::stream<D_TYPE>& s_result_PE112, hls::stream<D_TYPE>& s_result_PE113, 
    hls::stream<D_TYPE>& s_result_PE114, hls::stream<D_TYPE>& s_result_PE115, 
    hls::stream<D_TYPE>& s_result_PE116, hls::stream<D_TYPE>& s_result_PE117, 
    hls::stream<D_TYPE>& s_result_PE118, hls::stream<D_TYPE>& s_result_PE119, 
    hls::stream<D_TYPE>& s_result_PE120, hls::stream<D_TYPE>& s_result_PE121, 
    hls::stream<D_TYPE>& s_result_PE122, hls::stream<D_TYPE>& s_result_PE123, 
    hls::stream<D_TYPE>& s_result_PE124, hls::stream<D_TYPE>& s_result_PE125, 
    hls::stream<D_TYPE>& s_result_PE126, hls::stream<D_TYPE>& s_result_PE127, 
    hls::stream<D_TYPE>& s_result_PE128, hls::stream<D_TYPE>& s_result_PE129,
    hls::stream<D_TYPE>& s_result_PE130, hls::stream<D_TYPE>& s_result_PE131,
    hls::stream<D_TYPE>& s_result_PE132, hls::stream<D_TYPE>& s_result_PE133,
    hls::stream<D_TYPE>& s_result_PE134, hls::stream<D_TYPE>& s_result_PE135,
    hls::stream<D_TYPE>& s_result_PE136, hls::stream<D_TYPE>& s_result_PE137,
    hls::stream<D_TYPE>& s_result_PE138, hls::stream<D_TYPE>& s_result_PE139,
    hls::stream<D_TYPE>& s_result_PE140, hls::stream<D_TYPE>& s_result_PE141,
    hls::stream<D_TYPE>& s_result_PE142, hls::stream<D_TYPE>& s_result_PE143,
    hls::stream<D_TYPE>& s_result_PE144, hls::stream<D_TYPE>& s_result_PE145,
    hls::stream<D_TYPE>& s_result_PE146, hls::stream<D_TYPE>& s_result_PE147,
    hls::stream<D_TYPE>& s_result_PE148, hls::stream<D_TYPE>& s_result_PE149,
    hls::stream<D_TYPE>& s_result_PE150, hls::stream<D_TYPE>& s_result_PE151,
    hls::stream<D_TYPE>& s_result_PE152, hls::stream<D_TYPE>& s_result_PE153,
    hls::stream<D_TYPE>& s_result_PE154, hls::stream<D_TYPE>& s_result_PE155,
    hls::stream<D_TYPE>& s_result_PE156, hls::stream<D_TYPE>& s_result_PE157,
    hls::stream<D_TYPE>& s_result_PE158, hls::stream<D_TYPE>& s_result_PE159,
    hls::stream<D_TYPE>& s_result_PE160, hls::stream<D_TYPE>& s_result_PE161,
    hls::stream<D_TYPE>& s_result_PE162, hls::stream<D_TYPE>& s_result_PE163,
    hls::stream<D_TYPE>& s_result_PE164, hls::stream<D_TYPE>& s_result_PE165,
    hls::stream<D_TYPE>& s_result_PE166, hls::stream<D_TYPE>& s_result_PE167,
    hls::stream<D_TYPE>& s_result_PE168, hls::stream<D_TYPE>& s_result_PE169,
    hls::stream<D_TYPE>& s_result_PE170, hls::stream<D_TYPE>& s_result_PE171,
    hls::stream<D_TYPE>& s_result_PE172, hls::stream<D_TYPE>& s_result_PE173,
    hls::stream<D_TYPE>& s_result_PE174, hls::stream<D_TYPE>& s_result_PE175,
    hls::stream<D_TYPE>& s_result_PE176, hls::stream<D_TYPE>& s_result_PE177,
    hls::stream<D_TYPE>& s_result_PE178, hls::stream<D_TYPE>& s_result_PE179,
    hls::stream<D_TYPE>& s_result_PE180, hls::stream<D_TYPE>& s_result_PE181,
    hls::stream<D_TYPE>& s_result_PE182, hls::stream<D_TYPE>& s_result_PE183,
    hls::stream<D_TYPE>& s_result_PE184, hls::stream<D_TYPE>& s_result_PE185,
    hls::stream<D_TYPE>& s_result_PE186, hls::stream<D_TYPE>& s_result_PE187,
    hls::stream<D_TYPE>& s_result_PE188, hls::stream<D_TYPE>& s_result_PE189,
    hls::stream<D_TYPE>& s_result_PE190, hls::stream<D_TYPE>& s_result_PE191,
    hls::stream<D_TYPE>& s_result_PE192, hls::stream<D_TYPE>& s_result_PE193, 
    hls::stream<D_TYPE>& s_result_PE194, hls::stream<D_TYPE>& s_result_PE195, 
    hls::stream<D_TYPE>& s_result_PE196, hls::stream<D_TYPE>& s_result_PE197, 
    hls::stream<D_TYPE>& s_result_PE198, hls::stream<D_TYPE>& s_result_PE199,
    hls::stream<D_TYPE>& s_result_PE200, hls::stream<D_TYPE>& s_result_PE201, 
    hls::stream<D_TYPE>& s_result_PE202, hls::stream<D_TYPE>& s_result_PE203, 
    hls::stream<D_TYPE>& s_result_PE204, hls::stream<D_TYPE>& s_result_PE205, 
    hls::stream<D_TYPE>& s_result_PE206, hls::stream<D_TYPE>& s_result_PE207, 
    hls::stream<D_TYPE>& s_result_PE208, hls::stream<D_TYPE>& s_result_PE209, 
    hls::stream<D_TYPE>& s_result_PE210, hls::stream<D_TYPE>& s_result_PE211, 
    hls::stream<D_TYPE>& s_result_PE212, hls::stream<D_TYPE>& s_result_PE213, 
    hls::stream<D_TYPE>& s_result_PE214, hls::stream<D_TYPE>& s_result_PE215, 
    hls::stream<D_TYPE>& s_result_PE216, hls::stream<D_TYPE>& s_result_PE217, 
    hls::stream<D_TYPE>& s_result_PE218, hls::stream<D_TYPE>& s_result_PE219, 
    hls::stream<D_TYPE>& s_result_PE220, hls::stream<D_TYPE>& s_result_PE221, 
    hls::stream<D_TYPE>& s_result_PE222, hls::stream<D_TYPE>& s_result_PE223, 
    hls::stream<D_TYPE>& s_result_PE224, hls::stream<D_TYPE>& s_result_PE225, 
    hls::stream<D_TYPE>& s_result_PE226, hls::stream<D_TYPE>& s_result_PE227, 
    hls::stream<D_TYPE>& s_result_PE228, hls::stream<D_TYPE>& s_result_PE229,
    hls::stream<D_TYPE>& s_result_PE230, hls::stream<D_TYPE>& s_result_PE231,
    hls::stream<D_TYPE>& s_result_PE232, hls::stream<D_TYPE>& s_result_PE233,
    hls::stream<D_TYPE>& s_result_PE234, hls::stream<D_TYPE>& s_result_PE235,
    hls::stream<D_TYPE>& s_result_PE236, hls::stream<D_TYPE>& s_result_PE237,
    hls::stream<D_TYPE>& s_result_PE238, hls::stream<D_TYPE>& s_result_PE239,
    hls::stream<D_TYPE>& s_result_PE240, hls::stream<D_TYPE>& s_result_PE241,
    hls::stream<D_TYPE>& s_result_PE242, hls::stream<D_TYPE>& s_result_PE243,
    hls::stream<D_TYPE>& s_result_PE244, hls::stream<D_TYPE>& s_result_PE245,
    hls::stream<D_TYPE>& s_result_PE246, hls::stream<D_TYPE>& s_result_PE247,
    hls::stream<D_TYPE>& s_result_PE248, hls::stream<D_TYPE>& s_result_PE249,
    hls::stream<D_TYPE>& s_result_PE250, hls::stream<D_TYPE>& s_result_PE251,
    hls::stream<D_TYPE>& s_result_PE252, hls::stream<D_TYPE>& s_result_PE253,
    hls::stream<D_TYPE>& s_result_PE254, hls::stream<D_TYPE>& s_result_PE255,
    hls::stream<D_TYPE>& s_result_PE256, hls::stream<D_TYPE>& s_result_PE257,
    hls::stream<D_TYPE>& s_result_PE258, hls::stream<D_TYPE>& s_result_PE259,
    hls::stream<D_TYPE>& s_result_PE260, hls::stream<D_TYPE>& s_result_PE261,
    hls::stream<D_TYPE>& s_result_PE262, hls::stream<D_TYPE>& s_result_PE263,
    hls::stream<D_TYPE>& s_result_PE264, hls::stream<D_TYPE>& s_result_PE265,
    hls::stream<D_TYPE>& s_result_PE266, hls::stream<D_TYPE>& s_result_PE267,
    hls::stream<D_TYPE>& s_result_PE268, hls::stream<D_TYPE>& s_result_PE269,
    hls::stream<D_TYPE>& s_result_PE270, hls::stream<D_TYPE>& s_result_PE271,
    hls::stream<D_TYPE>& s_result_PE272, hls::stream<D_TYPE>& s_result_PE273,
    hls::stream<D_TYPE>& s_result_PE274, hls::stream<D_TYPE>& s_result_PE275,
    hls::stream<D_TYPE>& s_result_PE276, hls::stream<D_TYPE>& s_result_PE277,
    hls::stream<D_TYPE>& s_result_PE278, hls::stream<D_TYPE>& s_result_PE279,
    hls::stream<D_TYPE>& s_result_PE280, hls::stream<D_TYPE>& s_result_PE281,
    hls::stream<D_TYPE>& s_result_PE282, hls::stream<D_TYPE>& s_result_PE283,
    hls::stream<D_TYPE>& s_result_PE284, hls::stream<D_TYPE>& s_result_PE285,
    hls::stream<D_TYPE>& s_result_PE286, hls::stream<D_TYPE>& s_result_PE287,
    hls::stream<D_TYPE>& s_result_PE288, hls::stream<D_TYPE>& s_result_PE289,
    hls::stream<D_TYPE>& s_result_PE290, hls::stream<D_TYPE>& s_result_PE291,
    hls::stream<D_TYPE>& s_result_PE292, hls::stream<D_TYPE>& s_result_PE293, 
    hls::stream<D_TYPE>& s_result_PE294, hls::stream<D_TYPE>& s_result_PE295, 
    hls::stream<D_TYPE>& s_result_PE296, hls::stream<D_TYPE>& s_result_PE297, 
    hls::stream<D_TYPE>& s_result_PE298, hls::stream<D_TYPE>& s_result_PE299,
    hls::stream<D_TYPE>& s_result_PE300, hls::stream<D_TYPE>& s_result_PE301, 
    hls::stream<D_TYPE>& s_result_PE302, hls::stream<D_TYPE>& s_result_PE303, 
    hls::stream<D_TYPE>& s_result_PE304, hls::stream<D_TYPE>& s_result_PE305, 
    hls::stream<D_TYPE>& s_result_PE306, hls::stream<D_TYPE>& s_result_PE307, 
    hls::stream<D_TYPE>& s_result_PE308, hls::stream<D_TYPE>& s_result_PE309, 
    hls::stream<D_TYPE>& s_result_PE310, hls::stream<D_TYPE>& s_result_PE311, 
    hls::stream<D_TYPE>& s_result_PE312, hls::stream<D_TYPE>& s_result_PE313, 
    hls::stream<D_TYPE>& s_result_PE314, hls::stream<D_TYPE>& s_result_PE315, 
    hls::stream<D_TYPE>& s_result_PE316, hls::stream<D_TYPE>& s_result_PE317, 
    hls::stream<D_TYPE>& s_result_PE318, hls::stream<D_TYPE>& s_result_PE319,
    hls::stream<ap_uint<512> >& s_result_all)
{
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++){
        #pragma HLS pipeline II=20
        ap_uint<512> reg0, reg1, reg2, reg3, reg4, reg5, reg6, reg7, 
            reg8, reg9, reg10, reg11, reg12, reg13, reg14, reg15, 
            reg16, reg17, reg18, reg19;

        reg0.range(31, 0) = s_result_PE0.read() + 1;
        reg0.range(63, 32) = s_result_PE1.read() + 1;
        reg0.range(95, 64) = s_result_PE2.read() + 1;
        reg0.range(127, 96) = s_result_PE3.read() + 1;
        reg0.range(159, 128) = s_result_PE4.read() + 1;
        reg0.range(191, 160) = s_result_PE5.read() + 1;
        reg0.range(223, 192) = s_result_PE6.read() + 1;
        reg0.range(255, 224) = s_result_PE7.read() + 1;
        reg0.range(287, 256) = s_result_PE8.read() + 1;
        reg0.range(319, 288) = s_result_PE9.read() + 1;
        reg0.range(351, 320) = s_result_PE10.read() + 1;
        reg0.range(383, 352) = s_result_PE11.read() + 1;
        reg0.range(415, 384) = s_result_PE12.read() + 1;
        reg0.range(447, 416) = s_result_PE13.read() + 1;
        reg0.range(479, 448) = s_result_PE14.read() + 1;
        reg0.range(511, 480) = s_result_PE15.read() + 1;
        s_result_all.write(reg0);

        reg1.range(31, 0) = s_result_PE16.read() + 1;
        reg1.range(63, 32) = s_result_PE17.read() + 1;
        reg1.range(95, 64) = s_result_PE18.read() + 1;
        reg1.range(127, 96) = s_result_PE19.read() + 1;
        reg1.range(159, 128) = s_result_PE20.read() + 1;
        reg1.range(191, 160) = s_result_PE21.read() + 1;
        reg1.range(223, 192) = s_result_PE22.read() + 1;
        reg1.range(255, 224) = s_result_PE23.read() + 1;
        reg1.range(287, 256) = s_result_PE24.read() + 1;
        reg1.range(319, 288) = s_result_PE25.read() + 1;
        reg1.range(351, 320) = s_result_PE26.read() + 1;
        reg1.range(383, 352) = s_result_PE27.read() + 1;
        reg1.range(415, 384) = s_result_PE28.read() + 1;
        reg1.range(447, 416) = s_result_PE29.read() + 1;
        reg1.range(479, 448) = s_result_PE30.read() + 1;
        reg1.range(511, 480) = s_result_PE31.read() + 1;
        s_result_all.write(reg1);

        reg2.range(31, 0) = s_result_PE32.read() + 1;
        reg2.range(63, 32) = s_result_PE33.read() + 1;
        reg2.range(95, 64) = s_result_PE34.read() + 1;
        reg2.range(127, 96) = s_result_PE35.read() + 1;
        reg2.range(159, 128) = s_result_PE36.read() + 1;
        reg2.range(191, 160) = s_result_PE37.read() + 1;
        reg2.range(223, 192) = s_result_PE38.read() + 1;
        reg2.range(255, 224) = s_result_PE39.read() + 1;
        reg2.range(287, 256) = s_result_PE40.read() + 1;
        reg2.range(319, 288) = s_result_PE41.read() + 1;
        reg2.range(351, 320) = s_result_PE42.read() + 1;
        reg2.range(383, 352) = s_result_PE43.read() + 1;
        reg2.range(415, 384) = s_result_PE44.read() + 1;
        reg2.range(447, 416) = s_result_PE45.read() + 1;
        reg2.range(479, 448) = s_result_PE46.read() + 1;
        reg2.range(511, 480) = s_result_PE47.read() + 1;
        s_result_all.write(reg2);

        reg3.range(31, 0) = s_result_PE48.read() + 1;
        reg3.range(63, 32) = s_result_PE49.read() + 1;
        reg3.range(95, 64) = s_result_PE50.read() + 1;
        reg3.range(127, 96) = s_result_PE51.read() + 1;
        reg3.range(159, 128) = s_result_PE52.read() + 1;
        reg3.range(191, 160) = s_result_PE53.read() + 1;
        reg3.range(223, 192) = s_result_PE54.read() + 1;
        reg3.range(255, 224) = s_result_PE55.read() + 1;
        reg3.range(287, 256) = s_result_PE56.read() + 1;
        reg3.range(319, 288) = s_result_PE57.read() + 1;
        reg3.range(351, 320) = s_result_PE58.read() + 1;
        reg3.range(383, 352) = s_result_PE59.read() + 1;
        reg3.range(415, 384) = s_result_PE60.read() + 1;
        reg3.range(447, 416) = s_result_PE61.read() + 1;
        reg3.range(479, 448) = s_result_PE62.read() + 1;
        reg3.range(511, 480) = s_result_PE63.read() + 1;
        s_result_all.write(reg3);

        reg4.range(31, 0) = s_result_PE64.read() + 1;
        reg4.range(63, 32) = s_result_PE65.read() + 1;
        reg4.range(95, 64) = s_result_PE66.read() + 1;
        reg4.range(127, 96) = s_result_PE67.read() + 1;
        reg4.range(159, 128) = s_result_PE68.read() + 1;
        reg4.range(191, 160) = s_result_PE69.read() + 1;
        reg4.range(223, 192) = s_result_PE70.read() + 1;
        reg4.range(255, 224) = s_result_PE71.read() + 1;
        reg4.range(287, 256) = s_result_PE72.read() + 1;
        reg4.range(319, 288) = s_result_PE73.read() + 1;
        reg4.range(351, 320) = s_result_PE74.read() + 1;
        reg4.range(383, 352) = s_result_PE75.read() + 1;
        reg4.range(415, 384) = s_result_PE76.read() + 1;
        reg4.range(447, 416) = s_result_PE77.read() + 1;
        reg4.range(479, 448) = s_result_PE78.read() + 1;
        reg4.range(511, 480) = s_result_PE79.read() + 1;
        s_result_all.write(reg4);

        reg5.range(31, 0) = s_result_PE80.read() + 1;
        reg5.range(63, 32) = s_result_PE81.read() + 1;
        reg5.range(95, 64) = s_result_PE82.read() + 1;
        reg5.range(127, 96) = s_result_PE83.read() + 1;
        reg5.range(159, 128) = s_result_PE84.read() + 1;
        reg5.range(191, 160) = s_result_PE85.read() + 1;
        reg5.range(223, 192) = s_result_PE86.read() + 1;
        reg5.range(255, 224) = s_result_PE87.read() + 1;
        reg5.range(287, 256) = s_result_PE88.read() + 1;
        reg5.range(319, 288) = s_result_PE89.read() + 1;
        reg5.range(351, 320) = s_result_PE90.read() + 1;
        reg5.range(383, 352) = s_result_PE91.read() + 1;
        reg5.range(415, 384) = s_result_PE92.read() + 1;
        reg5.range(447, 416) = s_result_PE93.read() + 1;
        reg5.range(479, 448) = s_result_PE94.read() + 1;
        reg5.range(511, 480) = s_result_PE95.read() + 1;
        s_result_all.write(reg5);

        reg6.range(31, 0) = s_result_PE96.read() + 1;
        reg6.range(63, 32) = s_result_PE97.read() + 1;
        reg6.range(95, 64) = s_result_PE98.read() + 1;
        reg6.range(127, 96) = s_result_PE99.read() + 1;
        reg6.range(159, 128) = s_result_PE100.read() + 1;
        reg6.range(191, 160) = s_result_PE101.read() + 1;
        reg6.range(223, 192) = s_result_PE102.read() + 1;
        reg6.range(255, 224) = s_result_PE103.read() + 1;
        reg6.range(287, 256) = s_result_PE104.read() + 1;
        reg6.range(319, 288) = s_result_PE105.read() + 1;
        reg6.range(351, 320) = s_result_PE106.read() + 1;
        reg6.range(383, 352) = s_result_PE107.read() + 1;
        reg6.range(415, 384) = s_result_PE108.read() + 1;
        reg6.range(447, 416) = s_result_PE109.read() + 1;
        reg6.range(479, 448) = s_result_PE110.read() + 1;
        reg6.range(511, 480) = s_result_PE111.read() + 1;
        s_result_all.write(reg6);

        reg7.range(31, 0) = s_result_PE112.read() + 1;
        reg7.range(63, 32) = s_result_PE113.read() + 1;
        reg7.range(95, 64) = s_result_PE114.read() + 1;
        reg7.range(127, 96) = s_result_PE115.read() + 1;
        reg7.range(159, 128) = s_result_PE116.read() + 1;
        reg7.range(191, 160) = s_result_PE117.read() + 1;
        reg7.range(223, 192) = s_result_PE118.read() + 1;
        reg7.range(255, 224) = s_result_PE119.read() + 1;
        reg7.range(287, 256) = s_result_PE120.read() + 1;
        reg7.range(319, 288) = s_result_PE121.read() + 1;
        reg7.range(351, 320) = s_result_PE122.read() + 1;
        reg7.range(383, 352) = s_result_PE123.read() + 1;
        reg7.range(415, 384) = s_result_PE124.read() + 1;
        reg7.range(447, 416) = s_result_PE125.read() + 1;
        reg7.range(479, 448) = s_result_PE126.read() + 1;
        reg7.range(511, 480) = s_result_PE127.read() + 1;
        s_result_all.write(reg7);

        reg8.range(31, 0) = s_result_PE128.read() + 1;
        reg8.range(63, 32) = s_result_PE129.read() + 1;
        reg8.range(95, 64) = s_result_PE130.read() + 1;
        reg8.range(127, 96) = s_result_PE131.read() + 1;
        reg8.range(159, 128) = s_result_PE132.read() + 1;
        reg8.range(191, 160) = s_result_PE133.read() + 1;
        reg8.range(223, 192) = s_result_PE134.read() + 1;
        reg8.range(255, 224) = s_result_PE135.read() + 1;
        reg8.range(287, 256) = s_result_PE136.read() + 1;
        reg8.range(319, 288) = s_result_PE137.read() + 1;
        reg8.range(351, 320) = s_result_PE138.read() + 1;
        reg8.range(383, 352) = s_result_PE139.read() + 1;
        reg8.range(415, 384) = s_result_PE140.read() + 1;
        reg8.range(447, 416) = s_result_PE141.read() + 1;
        reg8.range(479, 448) = s_result_PE142.read() + 1;
        reg8.range(511, 480) = s_result_PE143.read() + 1;
        s_result_all.write(reg8);

        reg9.range(31, 0) = s_result_PE144.read() + 1;
        reg9.range(63, 32) = s_result_PE145.read() + 1;
        reg9.range(95, 64) = s_result_PE146.read() + 1;
        reg9.range(127, 96) = s_result_PE147.read() + 1;
        reg9.range(159, 128) = s_result_PE148.read() + 1;
        reg9.range(191, 160) = s_result_PE149.read() + 1;
        reg9.range(223, 192) = s_result_PE150.read() + 1;
        reg9.range(255, 224) = s_result_PE151.read() + 1;
        reg9.range(287, 256) = s_result_PE152.read() + 1;
        reg9.range(319, 288) = s_result_PE153.read() + 1;
        reg9.range(351, 320) = s_result_PE154.read() + 1;
        reg9.range(383, 352) = s_result_PE155.read() + 1;
        reg9.range(415, 384) = s_result_PE156.read() + 1;
        reg9.range(447, 416) = s_result_PE157.read() + 1;
        reg9.range(479, 448) = s_result_PE158.read() + 1;
        reg9.range(511, 480) = s_result_PE159.read() + 1;
        s_result_all.write(reg9);

        reg10.range(31, 0) = s_result_PE160.read() + 1;
        reg10.range(63, 32) = s_result_PE161.read() + 1;
        reg10.range(95, 64) = s_result_PE162.read() + 1;
        reg10.range(127, 96) = s_result_PE163.read() + 1;
        reg10.range(159, 128) = s_result_PE164.read() + 1;
        reg10.range(191, 160) = s_result_PE165.read() + 1;
        reg10.range(223, 192) = s_result_PE166.read() + 1;
        reg10.range(255, 224) = s_result_PE167.read() + 1;
        reg10.range(287, 256) = s_result_PE168.read() + 1;
        reg10.range(319, 288) = s_result_PE169.read() + 1;
        reg10.range(351, 320) = s_result_PE170.read() + 1;
        reg10.range(383, 352) = s_result_PE171.read() + 1;
        reg10.range(415, 384) = s_result_PE172.read() + 1;
        reg10.range(447, 416) = s_result_PE173.read() + 1;
        reg10.range(479, 448) = s_result_PE174.read() + 1;
        reg10.range(511, 480) = s_result_PE175.read() + 1;
        s_result_all.write(reg10);

        reg11.range(31, 0) = s_result_PE176.read() + 1;
        reg11.range(63, 32) = s_result_PE177.read() + 1;
        reg11.range(95, 64) = s_result_PE178.read() + 1;
        reg11.range(127, 96) = s_result_PE179.read() + 1;
        reg11.range(159, 128) = s_result_PE180.read() + 1;
        reg11.range(191, 160) = s_result_PE181.read() + 1;
        reg11.range(223, 192) = s_result_PE182.read() + 1;
        reg11.range(255, 224) = s_result_PE183.read() + 1;
        reg11.range(287, 256) = s_result_PE184.read() + 1;
        reg11.range(319, 288) = s_result_PE185.read() + 1;
        reg11.range(351, 320) = s_result_PE186.read() + 1;
        reg11.range(383, 352) = s_result_PE187.read() + 1;
        reg11.range(415, 384) = s_result_PE188.read() + 1;
        reg11.range(447, 416) = s_result_PE189.read() + 1;
        reg11.range(479, 448) = s_result_PE190.read() + 1;
        reg11.range(511, 480) = s_result_PE191.read() + 1;
        s_result_all.write(reg11);

        reg12.range(31, 0) = s_result_PE192.read() + 1;
        reg12.range(63, 32) = s_result_PE193.read() + 1;
        reg12.range(95, 64) = s_result_PE194.read() + 1;
        reg12.range(127, 96) = s_result_PE195.read() + 1;
        reg12.range(159, 128) = s_result_PE196.read() + 1;
        reg12.range(191, 160) = s_result_PE197.read() + 1;
        reg12.range(223, 192) = s_result_PE198.read() + 1;
        reg12.range(255, 224) = s_result_PE199.read() + 1;
        reg12.range(287, 256) = s_result_PE200.read() + 1;
        reg12.range(319, 288) = s_result_PE201.read() + 1;
        reg12.range(351, 320) = s_result_PE202.read() + 1;
        reg12.range(383, 352) = s_result_PE203.read() + 1;
        reg12.range(415, 384) = s_result_PE204.read() + 1;
        reg12.range(447, 416) = s_result_PE205.read() + 1;
        reg12.range(479, 448) = s_result_PE206.read() + 1;
        reg12.range(511, 480) = s_result_PE207.read() + 1;
        s_result_all.write(reg12);

        reg13.range(31, 0) = s_result_PE208.read() + 1;
        reg13.range(63, 32) = s_result_PE209.read() + 1;
        reg13.range(95, 64) = s_result_PE210.read() + 1;
        reg13.range(127, 96) = s_result_PE211.read() + 1;
        reg13.range(159, 128) = s_result_PE212.read() + 1;
        reg13.range(191, 160) = s_result_PE213.read() + 1;
        reg13.range(223, 192) = s_result_PE214.read() + 1;
        reg13.range(255, 224) = s_result_PE215.read() + 1;
        reg13.range(287, 256) = s_result_PE216.read() + 1;
        reg13.range(319, 288) = s_result_PE217.read() + 1;
        reg13.range(351, 320) = s_result_PE218.read() + 1;
        reg13.range(383, 352) = s_result_PE219.read() + 1;
        reg13.range(415, 384) = s_result_PE220.read() + 1;
        reg13.range(447, 416) = s_result_PE221.read() + 1;
        reg13.range(479, 448) = s_result_PE222.read() + 1;
        reg13.range(511, 480) = s_result_PE223.read() + 1;
        s_result_all.write(reg13);

        reg14.range(31, 0) = s_result_PE224.read() + 1;
        reg14.range(63, 32) = s_result_PE225.read() + 1;
        reg14.range(95, 64) = s_result_PE226.read() + 1;
        reg14.range(127, 96) = s_result_PE227.read() + 1;
        reg14.range(159, 128) = s_result_PE228.read() + 1;
        reg14.range(191, 160) = s_result_PE229.read() + 1;
        reg14.range(223, 192) = s_result_PE230.read() + 1;
        reg14.range(255, 224) = s_result_PE231.read() + 1;
        reg14.range(287, 256) = s_result_PE232.read() + 1;
        reg14.range(319, 288) = s_result_PE233.read() + 1;
        reg14.range(351, 320) = s_result_PE234.read() + 1;
        reg14.range(383, 352) = s_result_PE235.read() + 1;
        reg14.range(415, 384) = s_result_PE236.read() + 1;
        reg14.range(447, 416) = s_result_PE237.read() + 1;
        reg14.range(479, 448) = s_result_PE238.read() + 1;
        reg14.range(511, 480) = s_result_PE239.read() + 1;
        s_result_all.write(reg14);

        reg15.range(31, 0) = s_result_PE240.read() + 1;
        reg15.range(63, 32) = s_result_PE241.read() + 1;
        reg15.range(95, 64) = s_result_PE242.read() + 1;
        reg15.range(127, 96) = s_result_PE243.read() + 1;
        reg15.range(159, 128) = s_result_PE244.read() + 1;
        reg15.range(191, 160) = s_result_PE245.read() + 1;
        reg15.range(223, 192) = s_result_PE246.read() + 1;
        reg15.range(255, 224) = s_result_PE247.read() + 1;
        reg15.range(287, 256) = s_result_PE248.read() + 1;
        reg15.range(319, 288) = s_result_PE249.read() + 1;
        reg15.range(351, 320) = s_result_PE250.read() + 1;
        reg15.range(383, 352) = s_result_PE251.read() + 1;
        reg15.range(415, 384) = s_result_PE252.read() + 1;
        reg15.range(447, 416) = s_result_PE253.read() + 1;
        reg15.range(479, 448) = s_result_PE254.read() + 1;
        reg15.range(511, 480) = s_result_PE255.read() + 1;
        s_result_all.write(reg15);

        reg16.range(31, 0) = s_result_PE256.read() + 1;
        reg16.range(63, 32) = s_result_PE257.read() + 1;
        reg16.range(95, 64) = s_result_PE258.read() + 1;
        reg16.range(127, 96) = s_result_PE259.read() + 1;
        reg16.range(159, 128) = s_result_PE260.read() + 1;
        reg16.range(191, 160) = s_result_PE261.read() + 1;
        reg16.range(223, 192) = s_result_PE262.read() + 1;
        reg16.range(255, 224) = s_result_PE263.read() + 1;
        reg16.range(287, 256) = s_result_PE264.read() + 1;
        reg16.range(319, 288) = s_result_PE265.read() + 1;
        reg16.range(351, 320) = s_result_PE266.read() + 1;
        reg16.range(383, 352) = s_result_PE267.read() + 1;
        reg16.range(415, 384) = s_result_PE268.read() + 1;
        reg16.range(447, 416) = s_result_PE269.read() + 1;
        reg16.range(479, 448) = s_result_PE270.read() + 1;
        reg16.range(511, 480) = s_result_PE271.read() + 1;
        s_result_all.write(reg16);

        reg17.range(31, 0) = s_result_PE272.read() + 1;
        reg17.range(63, 32) = s_result_PE273.read() + 1;
        reg17.range(95, 64) = s_result_PE274.read() + 1;
        reg17.range(127, 96) = s_result_PE275.read() + 1;
        reg17.range(159, 128) = s_result_PE276.read() + 1;
        reg17.range(191, 160) = s_result_PE277.read() + 1;
        reg17.range(223, 192) = s_result_PE278.read() + 1;
        reg17.range(255, 224) = s_result_PE279.read() + 1;
        reg17.range(287, 256) = s_result_PE280.read() + 1;
        reg17.range(319, 288) = s_result_PE281.read() + 1;
        reg17.range(351, 320) = s_result_PE282.read() + 1;
        reg17.range(383, 352) = s_result_PE283.read() + 1;
        reg17.range(415, 384) = s_result_PE284.read() + 1;
        reg17.range(447, 416) = s_result_PE285.read() + 1;
        reg17.range(479, 448) = s_result_PE286.read() + 1;
        reg17.range(511, 480) = s_result_PE287.read() + 1;
        s_result_all.write(reg17);

        reg18.range(31, 0) = s_result_PE288.read() + 1;
        reg18.range(63, 32) = s_result_PE289.read() + 1;
        reg18.range(95, 64) = s_result_PE290.read() + 1;
        reg18.range(127, 96) = s_result_PE291.read() + 1;
        reg18.range(159, 128) = s_result_PE292.read() + 1;
        reg18.range(191, 160) = s_result_PE293.read() + 1;
        reg18.range(223, 192) = s_result_PE294.read() + 1;
        reg18.range(255, 224) = s_result_PE295.read() + 1;
        reg18.range(287, 256) = s_result_PE296.read() + 1;
        reg18.range(319, 288) = s_result_PE297.read() + 1;
        reg18.range(351, 320) = s_result_PE298.read() + 1;
        reg18.range(383, 352) = s_result_PE299.read() + 1;
        reg18.range(415, 384) = s_result_PE300.read() + 1;
        reg18.range(447, 416) = s_result_PE301.read() + 1;
        reg18.range(479, 448) = s_result_PE302.read() + 1;
        reg18.range(511, 480) = s_result_PE303.read() + 1;
        s_result_all.write(reg18);

        reg19.range(31, 0) = s_result_PE304.read() + 1;
        reg19.range(63, 32) = s_result_PE305.read() + 1;
        reg19.range(95, 64) = s_result_PE306.read() + 1;
        reg19.range(127, 96) = s_result_PE307.read() + 1;
        reg19.range(159, 128) = s_result_PE308.read() + 1;
        reg19.range(191, 160) = s_result_PE309.read() + 1;
        reg19.range(223, 192) = s_result_PE310.read() + 1;
        reg19.range(255, 224) = s_result_PE311.read() + 1;
        reg19.range(287, 256) = s_result_PE312.read() + 1;
        reg19.range(319, 288) = s_result_PE313.read() + 1;
        reg19.range(351, 320) = s_result_PE314.read() + 1;
        reg19.range(383, 352) = s_result_PE315.read() + 1;
        reg19.range(415, 384) = s_result_PE316.read() + 1;
        reg19.range(447, 416) = s_result_PE317.read() + 1;
        reg19.range(479, 448) = s_result_PE318.read() + 1;
        reg19.range(511, 480) = s_result_PE319.read() + 1;
        s_result_all.write(reg19);
    }
}

template<const int ROW_PER_PE>
void gather_results_192PEs(
    hls::stream<D_TYPE>& s_result_PE0, hls::stream<D_TYPE>& s_result_PE1, 
    hls::stream<D_TYPE>& s_result_PE2, hls::stream<D_TYPE>& s_result_PE3, 
    hls::stream<D_TYPE>& s_result_PE4, hls::stream<D_TYPE>& s_result_PE5, 
    hls::stream<D_TYPE>& s_result_PE6, hls::stream<D_TYPE>& s_result_PE7, 
    hls::stream<D_TYPE>& s_result_PE8, hls::stream<D_TYPE>& s_result_PE9, 
    hls::stream<D_TYPE>& s_result_PE10, hls::stream<D_TYPE>& s_result_PE11, 
    hls::stream<D_TYPE>& s_result_PE12, hls::stream<D_TYPE>& s_result_PE13, 
    hls::stream<D_TYPE>& s_result_PE14, hls::stream<D_TYPE>& s_result_PE15, 
    hls::stream<D_TYPE>& s_result_PE16, hls::stream<D_TYPE>& s_result_PE17, 
    hls::stream<D_TYPE>& s_result_PE18, hls::stream<D_TYPE>& s_result_PE19, 
    hls::stream<D_TYPE>& s_result_PE20, hls::stream<D_TYPE>& s_result_PE21, 
    hls::stream<D_TYPE>& s_result_PE22, hls::stream<D_TYPE>& s_result_PE23, 
    hls::stream<D_TYPE>& s_result_PE24, hls::stream<D_TYPE>& s_result_PE25, 
    hls::stream<D_TYPE>& s_result_PE26, hls::stream<D_TYPE>& s_result_PE27, 
    hls::stream<D_TYPE>& s_result_PE28, hls::stream<D_TYPE>& s_result_PE29, 
    hls::stream<D_TYPE>& s_result_PE30, hls::stream<D_TYPE>& s_result_PE31, 
    hls::stream<D_TYPE>& s_result_PE32, hls::stream<D_TYPE>& s_result_PE33, 
    hls::stream<D_TYPE>& s_result_PE34, hls::stream<D_TYPE>& s_result_PE35, 
    hls::stream<D_TYPE>& s_result_PE36, hls::stream<D_TYPE>& s_result_PE37, 
    hls::stream<D_TYPE>& s_result_PE38, hls::stream<D_TYPE>& s_result_PE39, 
    hls::stream<D_TYPE>& s_result_PE40, hls::stream<D_TYPE>& s_result_PE41, 
    hls::stream<D_TYPE>& s_result_PE42, hls::stream<D_TYPE>& s_result_PE43, 
    hls::stream<D_TYPE>& s_result_PE44, hls::stream<D_TYPE>& s_result_PE45, 
    hls::stream<D_TYPE>& s_result_PE46, hls::stream<D_TYPE>& s_result_PE47, 
    hls::stream<D_TYPE>& s_result_PE48, hls::stream<D_TYPE>& s_result_PE49, 
    hls::stream<D_TYPE>& s_result_PE50, hls::stream<D_TYPE>& s_result_PE51, 
    hls::stream<D_TYPE>& s_result_PE52, hls::stream<D_TYPE>& s_result_PE53, 
    hls::stream<D_TYPE>& s_result_PE54, hls::stream<D_TYPE>& s_result_PE55, 
    hls::stream<D_TYPE>& s_result_PE56, hls::stream<D_TYPE>& s_result_PE57, 
    hls::stream<D_TYPE>& s_result_PE58, hls::stream<D_TYPE>& s_result_PE59, 
    hls::stream<D_TYPE>& s_result_PE60, hls::stream<D_TYPE>& s_result_PE61, 
    hls::stream<D_TYPE>& s_result_PE62, hls::stream<D_TYPE>& s_result_PE63, 
    hls::stream<D_TYPE>& s_result_PE64, hls::stream<D_TYPE>& s_result_PE65, 
    hls::stream<D_TYPE>& s_result_PE66, hls::stream<D_TYPE>& s_result_PE67, 
    hls::stream<D_TYPE>& s_result_PE68, hls::stream<D_TYPE>& s_result_PE69, 
    hls::stream<D_TYPE>& s_result_PE70, hls::stream<D_TYPE>& s_result_PE71, 
    hls::stream<D_TYPE>& s_result_PE72, hls::stream<D_TYPE>& s_result_PE73, 
    hls::stream<D_TYPE>& s_result_PE74, hls::stream<D_TYPE>& s_result_PE75, 
    hls::stream<D_TYPE>& s_result_PE76, hls::stream<D_TYPE>& s_result_PE77, 
    hls::stream<D_TYPE>& s_result_PE78, hls::stream<D_TYPE>& s_result_PE79, 
    hls::stream<D_TYPE>& s_result_PE80, hls::stream<D_TYPE>& s_result_PE81, 
    hls::stream<D_TYPE>& s_result_PE82, hls::stream<D_TYPE>& s_result_PE83, 
    hls::stream<D_TYPE>& s_result_PE84, hls::stream<D_TYPE>& s_result_PE85, 
    hls::stream<D_TYPE>& s_result_PE86, hls::stream<D_TYPE>& s_result_PE87, 
    hls::stream<D_TYPE>& s_result_PE88, hls::stream<D_TYPE>& s_result_PE89, 
    hls::stream<D_TYPE>& s_result_PE90, hls::stream<D_TYPE>& s_result_PE91, 
    hls::stream<D_TYPE>& s_result_PE92, hls::stream<D_TYPE>& s_result_PE93, 
    hls::stream<D_TYPE>& s_result_PE94, hls::stream<D_TYPE>& s_result_PE95, 
    hls::stream<D_TYPE>& s_result_PE96, hls::stream<D_TYPE>& s_result_PE97, 
    hls::stream<D_TYPE>& s_result_PE98, hls::stream<D_TYPE>& s_result_PE99, 
    hls::stream<D_TYPE>& s_result_PE100, hls::stream<D_TYPE>& s_result_PE101, 
    hls::stream<D_TYPE>& s_result_PE102, hls::stream<D_TYPE>& s_result_PE103, 
    hls::stream<D_TYPE>& s_result_PE104, hls::stream<D_TYPE>& s_result_PE105, 
    hls::stream<D_TYPE>& s_result_PE106, hls::stream<D_TYPE>& s_result_PE107, 
    hls::stream<D_TYPE>& s_result_PE108, hls::stream<D_TYPE>& s_result_PE109, 
    hls::stream<D_TYPE>& s_result_PE110, hls::stream<D_TYPE>& s_result_PE111, 
    hls::stream<D_TYPE>& s_result_PE112, hls::stream<D_TYPE>& s_result_PE113, 
    hls::stream<D_TYPE>& s_result_PE114, hls::stream<D_TYPE>& s_result_PE115, 
    hls::stream<D_TYPE>& s_result_PE116, hls::stream<D_TYPE>& s_result_PE117, 
    hls::stream<D_TYPE>& s_result_PE118, hls::stream<D_TYPE>& s_result_PE119, 
    hls::stream<D_TYPE>& s_result_PE120, hls::stream<D_TYPE>& s_result_PE121, 
    hls::stream<D_TYPE>& s_result_PE122, hls::stream<D_TYPE>& s_result_PE123, 
    hls::stream<D_TYPE>& s_result_PE124, hls::stream<D_TYPE>& s_result_PE125, 
    hls::stream<D_TYPE>& s_result_PE126, hls::stream<D_TYPE>& s_result_PE127, 
    hls::stream<D_TYPE>& s_result_PE128, hls::stream<D_TYPE>& s_result_PE129,
    hls::stream<D_TYPE>& s_result_PE130, hls::stream<D_TYPE>& s_result_PE131,
    hls::stream<D_TYPE>& s_result_PE132, hls::stream<D_TYPE>& s_result_PE133,
    hls::stream<D_TYPE>& s_result_PE134, hls::stream<D_TYPE>& s_result_PE135,
    hls::stream<D_TYPE>& s_result_PE136, hls::stream<D_TYPE>& s_result_PE137,
    hls::stream<D_TYPE>& s_result_PE138, hls::stream<D_TYPE>& s_result_PE139,
    hls::stream<D_TYPE>& s_result_PE140, hls::stream<D_TYPE>& s_result_PE141,
    hls::stream<D_TYPE>& s_result_PE142, hls::stream<D_TYPE>& s_result_PE143,
    hls::stream<D_TYPE>& s_result_PE144, hls::stream<D_TYPE>& s_result_PE145,
    hls::stream<D_TYPE>& s_result_PE146, hls::stream<D_TYPE>& s_result_PE147,
    hls::stream<D_TYPE>& s_result_PE148, hls::stream<D_TYPE>& s_result_PE149,
    hls::stream<D_TYPE>& s_result_PE150, hls::stream<D_TYPE>& s_result_PE151,
    hls::stream<D_TYPE>& s_result_PE152, hls::stream<D_TYPE>& s_result_PE153,
    hls::stream<D_TYPE>& s_result_PE154, hls::stream<D_TYPE>& s_result_PE155,
    hls::stream<D_TYPE>& s_result_PE156, hls::stream<D_TYPE>& s_result_PE157,
    hls::stream<D_TYPE>& s_result_PE158, hls::stream<D_TYPE>& s_result_PE159,
    hls::stream<D_TYPE>& s_result_PE160, hls::stream<D_TYPE>& s_result_PE161,
    hls::stream<D_TYPE>& s_result_PE162, hls::stream<D_TYPE>& s_result_PE163,
    hls::stream<D_TYPE>& s_result_PE164, hls::stream<D_TYPE>& s_result_PE165,
    hls::stream<D_TYPE>& s_result_PE166, hls::stream<D_TYPE>& s_result_PE167,
    hls::stream<D_TYPE>& s_result_PE168, hls::stream<D_TYPE>& s_result_PE169,
    hls::stream<D_TYPE>& s_result_PE170, hls::stream<D_TYPE>& s_result_PE171,
    hls::stream<D_TYPE>& s_result_PE172, hls::stream<D_TYPE>& s_result_PE173,
    hls::stream<D_TYPE>& s_result_PE174, hls::stream<D_TYPE>& s_result_PE175,
    hls::stream<D_TYPE>& s_result_PE176, hls::stream<D_TYPE>& s_result_PE177,
    hls::stream<D_TYPE>& s_result_PE178, hls::stream<D_TYPE>& s_result_PE179,
    hls::stream<D_TYPE>& s_result_PE180, hls::stream<D_TYPE>& s_result_PE181,
    hls::stream<D_TYPE>& s_result_PE182, hls::stream<D_TYPE>& s_result_PE183,
    hls::stream<D_TYPE>& s_result_PE184, hls::stream<D_TYPE>& s_result_PE185,
    hls::stream<D_TYPE>& s_result_PE186, hls::stream<D_TYPE>& s_result_PE187,
    hls::stream<D_TYPE>& s_result_PE188, hls::stream<D_TYPE>& s_result_PE189,
    hls::stream<D_TYPE>& s_result_PE190, hls::stream<D_TYPE>& s_result_PE191,
    hls::stream<ap_uint<512> >& s_result_all) {
     
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        #pragma HLS pipeline II=12  // write 1 result_all per CC

        ap_uint<512> reg0, reg1, reg2, reg3, reg4, reg5, reg6, reg7, 
            reg8, reg9, reg10, reg11;

    //print("        reg",str(i),".range(31, 0)    = s_result_PE",str(16*i),".read() + 1;",sep='')
    //print("        reg",str(i),".range(63, 32)   = s_result_PE",str(16*i+1),".read() + 1;",sep='')
    //print("        reg",str(i),".range(95, 64)   = s_result_PE",str(16*i+2),".read() + 1;",sep='')
    //print("        reg",str(i),".range(127, 96)  = s_result_PE",str(16*i+3),".read() + 1;",sep='')
    //print("        reg",str(i),".range(159, 128) = s_result_PE",str(16*i+4),".read() + 1;",sep='')
    //print("        reg",str(i),".range(191, 160) = s_result_PE",str(16*i+5),".read() + 1;",sep='')
    //print("        reg",str(i),".range(223, 192) = s_result_PE",str(16*i+6),".read() + 1;",sep='')
    //print("        reg",str(i),".range(255, 224) = s_result_PE",str(16*i+7),".read() + 1;",sep='')
    //print("        reg",str(i),".range(287, 256) = s_result_PE",str(16*i+8),".read() + 1;",sep='')
    //print("        reg",str(i),".range(319, 288) = s_result_PE",str(16*i+9),".read() + 1;",sep='')
    //print("        reg",str(i),".range(351, 320) = s_result_PE",str(16*i+10),".read() + 1;",sep='')
    //print("        reg",str(i),".range(383, 352) = s_result_PE",str(16*i+11),".read() + 1;",sep='')
    //print("        reg",str(i),".range(415, 384) = s_result_PE",str(16*i+12),".read() + 1;",sep='')
    //print("        reg",str(i),".range(447, 416) = s_result_PE",str(16*i+13),".read() + 1;",sep='')
    //print("        reg",str(i),".range(479, 448) = s_result_PE",str(16*i+14),".read() + 1;",sep='')
    //print("        reg",str(i),".range(511, 480) = s_result_PE",str(16*i+15),".read() + 1;",sep='')

        reg0.range(31, 0)    = s_result_PE0.read() + 1;
        reg0.range(63, 32)   = s_result_PE1.read() + 1;
        reg0.range(95, 64)   = s_result_PE2.read() + 1;
        reg0.range(127, 96)  = s_result_PE3.read() + 1;
        reg0.range(159, 128) = s_result_PE4.read() + 1;
        reg0.range(191, 160) = s_result_PE5.read() + 1;
        reg0.range(223, 192) = s_result_PE6.read() + 1;
        reg0.range(255, 224) = s_result_PE7.read() + 1;
        reg0.range(287, 256) = s_result_PE8.read() + 1;
        reg0.range(319, 288) = s_result_PE9.read() + 1;
        reg0.range(351, 320) = s_result_PE10.read() + 1;
        reg0.range(383, 352) = s_result_PE11.read() + 1;
        reg0.range(415, 384) = s_result_PE12.read() + 1;
        reg0.range(447, 416) = s_result_PE13.read() + 1;
        reg0.range(479, 448) = s_result_PE14.read() + 1;
        reg0.range(511, 480) = s_result_PE15.read() + 1;
        s_result_all.write(reg0);

        reg1.range(31, 0)    = s_result_PE16.read() + 1;
        reg1.range(63, 32)   = s_result_PE17.read() + 1;
        reg1.range(95, 64)   = s_result_PE18.read() + 1;
        reg1.range(127, 96)  = s_result_PE19.read() + 1;
        reg1.range(159, 128) = s_result_PE20.read() + 1;
        reg1.range(191, 160) = s_result_PE21.read() + 1;
        reg1.range(223, 192) = s_result_PE22.read() + 1;
        reg1.range(255, 224) = s_result_PE23.read() + 1;
        reg1.range(287, 256) = s_result_PE24.read() + 1;
        reg1.range(319, 288) = s_result_PE25.read() + 1;
        reg1.range(351, 320) = s_result_PE26.read() + 1;
        reg1.range(383, 352) = s_result_PE27.read() + 1;
        reg1.range(415, 384) = s_result_PE28.read() + 1;
        reg1.range(447, 416) = s_result_PE29.read() + 1;
        reg1.range(479, 448) = s_result_PE30.read() + 1;
        reg1.range(511, 480) = s_result_PE31.read() + 1;
        s_result_all.write(reg1);

        reg2.range(31, 0)    = s_result_PE32.read() + 1;
        reg2.range(63, 32)   = s_result_PE33.read() + 1;
        reg2.range(95, 64)   = s_result_PE34.read() + 1;
        reg2.range(127, 96)  = s_result_PE35.read() + 1;
        reg2.range(159, 128) = s_result_PE36.read() + 1;
        reg2.range(191, 160) = s_result_PE37.read() + 1;
        reg2.range(223, 192) = s_result_PE38.read() + 1;
        reg2.range(255, 224) = s_result_PE39.read() + 1;
        reg2.range(287, 256) = s_result_PE40.read() + 1;
        reg2.range(319, 288) = s_result_PE41.read() + 1;
        reg2.range(351, 320) = s_result_PE42.read() + 1;
        reg2.range(383, 352) = s_result_PE43.read() + 1;
        reg2.range(415, 384) = s_result_PE44.read() + 1;
        reg2.range(447, 416) = s_result_PE45.read() + 1;
        reg2.range(479, 448) = s_result_PE46.read() + 1;
        reg2.range(511, 480) = s_result_PE47.read() + 1;
        s_result_all.write(reg2);

        reg3.range(31, 0)    = s_result_PE48.read() + 1;
        reg3.range(63, 32)   = s_result_PE49.read() + 1;
        reg3.range(95, 64)   = s_result_PE50.read() + 1;
        reg3.range(127, 96)  = s_result_PE51.read() + 1;
        reg3.range(159, 128) = s_result_PE52.read() + 1;
        reg3.range(191, 160) = s_result_PE53.read() + 1;
        reg3.range(223, 192) = s_result_PE54.read() + 1;
        reg3.range(255, 224) = s_result_PE55.read() + 1;
        reg3.range(287, 256) = s_result_PE56.read() + 1;
        reg3.range(319, 288) = s_result_PE57.read() + 1;
        reg3.range(351, 320) = s_result_PE58.read() + 1;
        reg3.range(383, 352) = s_result_PE59.read() + 1;
        reg3.range(415, 384) = s_result_PE60.read() + 1;
        reg3.range(447, 416) = s_result_PE61.read() + 1;
        reg3.range(479, 448) = s_result_PE62.read() + 1;
        reg3.range(511, 480) = s_result_PE63.read() + 1;
        s_result_all.write(reg3);

        reg4.range(31, 0)    = s_result_PE64.read() + 1;
        reg4.range(63, 32)   = s_result_PE65.read() + 1;
        reg4.range(95, 64)   = s_result_PE66.read() + 1;
        reg4.range(127, 96)  = s_result_PE67.read() + 1;
        reg4.range(159, 128) = s_result_PE68.read() + 1;
        reg4.range(191, 160) = s_result_PE69.read() + 1;
        reg4.range(223, 192) = s_result_PE70.read() + 1;
        reg4.range(255, 224) = s_result_PE71.read() + 1;
        reg4.range(287, 256) = s_result_PE72.read() + 1;
        reg4.range(319, 288) = s_result_PE73.read() + 1;
        reg4.range(351, 320) = s_result_PE74.read() + 1;
        reg4.range(383, 352) = s_result_PE75.read() + 1;
        reg4.range(415, 384) = s_result_PE76.read() + 1;
        reg4.range(447, 416) = s_result_PE77.read() + 1;
        reg4.range(479, 448) = s_result_PE78.read() + 1;
        reg4.range(511, 480) = s_result_PE79.read() + 1;
        s_result_all.write(reg4);

        reg5.range(31, 0)    = s_result_PE80.read() + 1;
        reg5.range(63, 32)   = s_result_PE81.read() + 1;
        reg5.range(95, 64)   = s_result_PE82.read() + 1;
        reg5.range(127, 96)  = s_result_PE83.read() + 1;
        reg5.range(159, 128) = s_result_PE84.read() + 1;
        reg5.range(191, 160) = s_result_PE85.read() + 1;
        reg5.range(223, 192) = s_result_PE86.read() + 1;
        reg5.range(255, 224) = s_result_PE87.read() + 1;
        reg5.range(287, 256) = s_result_PE88.read() + 1;
        reg5.range(319, 288) = s_result_PE89.read() + 1;
        reg5.range(351, 320) = s_result_PE90.read() + 1;
        reg5.range(383, 352) = s_result_PE91.read() + 1;
        reg5.range(415, 384) = s_result_PE92.read() + 1;
        reg5.range(447, 416) = s_result_PE93.read() + 1;
        reg5.range(479, 448) = s_result_PE94.read() + 1;
        reg5.range(511, 480) = s_result_PE95.read() + 1;
        s_result_all.write(reg5);

        reg6.range(31, 0)    = s_result_PE96.read() + 1;
        reg6.range(63, 32)   = s_result_PE97.read() + 1;
        reg6.range(95, 64)   = s_result_PE98.read() + 1;
        reg6.range(127, 96)  = s_result_PE99.read() + 1;
        reg6.range(159, 128) = s_result_PE100.read() + 1;
        reg6.range(191, 160) = s_result_PE101.read() + 1;
        reg6.range(223, 192) = s_result_PE102.read() + 1;
        reg6.range(255, 224) = s_result_PE103.read() + 1;
        reg6.range(287, 256) = s_result_PE104.read() + 1;
        reg6.range(319, 288) = s_result_PE105.read() + 1;
        reg6.range(351, 320) = s_result_PE106.read() + 1;
        reg6.range(383, 352) = s_result_PE107.read() + 1;
        reg6.range(415, 384) = s_result_PE108.read() + 1;
        reg6.range(447, 416) = s_result_PE109.read() + 1;
        reg6.range(479, 448) = s_result_PE110.read() + 1;
        reg6.range(511, 480) = s_result_PE111.read() + 1;
        s_result_all.write(reg6);

        reg7.range(31, 0)    = s_result_PE112.read() + 1;
        reg7.range(63, 32)   = s_result_PE113.read() + 1;
        reg7.range(95, 64)   = s_result_PE114.read() + 1;
        reg7.range(127, 96)  = s_result_PE115.read() + 1;
        reg7.range(159, 128) = s_result_PE116.read() + 1;
        reg7.range(191, 160) = s_result_PE117.read() + 1;
        reg7.range(223, 192) = s_result_PE118.read() + 1;
        reg7.range(255, 224) = s_result_PE119.read() + 1;
        reg7.range(287, 256) = s_result_PE120.read() + 1;
        reg7.range(319, 288) = s_result_PE121.read() + 1;
        reg7.range(351, 320) = s_result_PE122.read() + 1;
        reg7.range(383, 352) = s_result_PE123.read() + 1;
        reg7.range(415, 384) = s_result_PE124.read() + 1;
        reg7.range(447, 416) = s_result_PE125.read() + 1;
        reg7.range(479, 448) = s_result_PE126.read() + 1;
        reg7.range(511, 480) = s_result_PE127.read() + 1;
        s_result_all.write(reg7);

        reg8.range(31, 0)    = s_result_PE128.read() + 1;
        reg8.range(63, 32)   = s_result_PE129.read() + 1;
        reg8.range(95, 64)   = s_result_PE130.read() + 1;
        reg8.range(127, 96)  = s_result_PE131.read() + 1;
        reg8.range(159, 128) = s_result_PE132.read() + 1;
        reg8.range(191, 160) = s_result_PE133.read() + 1;
        reg8.range(223, 192) = s_result_PE134.read() + 1;
        reg8.range(255, 224) = s_result_PE135.read() + 1;
        reg8.range(287, 256) = s_result_PE136.read() + 1;
        reg8.range(319, 288) = s_result_PE137.read() + 1;
        reg8.range(351, 320) = s_result_PE138.read() + 1;
        reg8.range(383, 352) = s_result_PE139.read() + 1;
        reg8.range(415, 384) = s_result_PE140.read() + 1;
        reg8.range(447, 416) = s_result_PE141.read() + 1;
        reg8.range(479, 448) = s_result_PE142.read() + 1;
        reg8.range(511, 480) = s_result_PE143.read() + 1;
        s_result_all.write(reg8);

        reg9.range(31, 0)    = s_result_PE144.read() + 1;
        reg9.range(63, 32)   = s_result_PE145.read() + 1;
        reg9.range(95, 64)   = s_result_PE146.read() + 1;
        reg9.range(127, 96)  = s_result_PE147.read() + 1;
        reg9.range(159, 128) = s_result_PE148.read() + 1;
        reg9.range(191, 160) = s_result_PE149.read() + 1;
        reg9.range(223, 192) = s_result_PE150.read() + 1;
        reg9.range(255, 224) = s_result_PE151.read() + 1;
        reg9.range(287, 256) = s_result_PE152.read() + 1;
        reg9.range(319, 288) = s_result_PE153.read() + 1;
        reg9.range(351, 320) = s_result_PE154.read() + 1;
        reg9.range(383, 352) = s_result_PE155.read() + 1;
        reg9.range(415, 384) = s_result_PE156.read() + 1;
        reg9.range(447, 416) = s_result_PE157.read() + 1;
        reg9.range(479, 448) = s_result_PE158.read() + 1;
        reg9.range(511, 480) = s_result_PE159.read() + 1;
        s_result_all.write(reg9);

        reg10.range(31, 0)    = s_result_PE160.read() + 1;
        reg10.range(63, 32)   = s_result_PE161.read() + 1;
        reg10.range(95, 64)   = s_result_PE162.read() + 1;
        reg10.range(127, 96)  = s_result_PE163.read() + 1;
        reg10.range(159, 128) = s_result_PE164.read() + 1;
        reg10.range(191, 160) = s_result_PE165.read() + 1;
        reg10.range(223, 192) = s_result_PE166.read() + 1;
        reg10.range(255, 224) = s_result_PE167.read() + 1;
        reg10.range(287, 256) = s_result_PE168.read() + 1;
        reg10.range(319, 288) = s_result_PE169.read() + 1;
        reg10.range(351, 320) = s_result_PE170.read() + 1;
        reg10.range(383, 352) = s_result_PE171.read() + 1;
        reg10.range(415, 384) = s_result_PE172.read() + 1;
        reg10.range(447, 416) = s_result_PE173.read() + 1;
        reg10.range(479, 448) = s_result_PE174.read() + 1;
        reg10.range(511, 480) = s_result_PE175.read() + 1;
        s_result_all.write(reg10);

        reg11.range(31, 0)    = s_result_PE176.read() + 1;
        reg11.range(63, 32)   = s_result_PE177.read() + 1;
        reg11.range(95, 64)   = s_result_PE178.read() + 1;
        reg11.range(127, 96)  = s_result_PE179.read() + 1;
        reg11.range(159, 128) = s_result_PE180.read() + 1;
        reg11.range(191, 160) = s_result_PE181.read() + 1;
        reg11.range(223, 192) = s_result_PE182.read() + 1;
        reg11.range(255, 224) = s_result_PE183.read() + 1;
        reg11.range(287, 256) = s_result_PE184.read() + 1;
        reg11.range(319, 288) = s_result_PE185.read() + 1;
        reg11.range(351, 320) = s_result_PE186.read() + 1;
        reg11.range(383, 352) = s_result_PE187.read() + 1;
        reg11.range(415, 384) = s_result_PE188.read() + 1;
        reg11.range(447, 416) = s_result_PE189.read() + 1;
        reg11.range(479, 448) = s_result_PE190.read() + 1;
        reg11.range(511, 480) = s_result_PE191.read() + 1;
        s_result_all.write(reg11);
    }
}

template<const int ROW_PER_PE>
void gather_results_512PEs_160PE(
    hls::stream<D_TYPE>& s_result_PE0, hls::stream<D_TYPE>& s_result_PE1, 
    hls::stream<D_TYPE>& s_result_PE2, hls::stream<D_TYPE>& s_result_PE3, 
    hls::stream<D_TYPE>& s_result_PE4, hls::stream<D_TYPE>& s_result_PE5, 
    hls::stream<D_TYPE>& s_result_PE6, hls::stream<D_TYPE>& s_result_PE7, 
    hls::stream<D_TYPE>& s_result_PE8, hls::stream<D_TYPE>& s_result_PE9, 
    hls::stream<D_TYPE>& s_result_PE10, hls::stream<D_TYPE>& s_result_PE11, 
    hls::stream<D_TYPE>& s_result_PE12, hls::stream<D_TYPE>& s_result_PE13, 
    hls::stream<D_TYPE>& s_result_PE14, hls::stream<D_TYPE>& s_result_PE15, 
    hls::stream<D_TYPE>& s_result_PE16, hls::stream<D_TYPE>& s_result_PE17, 
    hls::stream<D_TYPE>& s_result_PE18, hls::stream<D_TYPE>& s_result_PE19, 
    hls::stream<D_TYPE>& s_result_PE20, hls::stream<D_TYPE>& s_result_PE21, 
    hls::stream<D_TYPE>& s_result_PE22, hls::stream<D_TYPE>& s_result_PE23, 
    hls::stream<D_TYPE>& s_result_PE24, hls::stream<D_TYPE>& s_result_PE25, 
    hls::stream<D_TYPE>& s_result_PE26, hls::stream<D_TYPE>& s_result_PE27, 
    hls::stream<D_TYPE>& s_result_PE28, hls::stream<D_TYPE>& s_result_PE29, 
    hls::stream<D_TYPE>& s_result_PE30, hls::stream<D_TYPE>& s_result_PE31, 
    hls::stream<D_TYPE>& s_result_PE32, hls::stream<D_TYPE>& s_result_PE33, 
    hls::stream<D_TYPE>& s_result_PE34, hls::stream<D_TYPE>& s_result_PE35, 
    hls::stream<D_TYPE>& s_result_PE36, hls::stream<D_TYPE>& s_result_PE37, 
    hls::stream<D_TYPE>& s_result_PE38, hls::stream<D_TYPE>& s_result_PE39, 
    hls::stream<D_TYPE>& s_result_PE40, hls::stream<D_TYPE>& s_result_PE41, 
    hls::stream<D_TYPE>& s_result_PE42, hls::stream<D_TYPE>& s_result_PE43, 
    hls::stream<D_TYPE>& s_result_PE44, hls::stream<D_TYPE>& s_result_PE45, 
    hls::stream<D_TYPE>& s_result_PE46, hls::stream<D_TYPE>& s_result_PE47, 
    hls::stream<D_TYPE>& s_result_PE48, hls::stream<D_TYPE>& s_result_PE49, 
    hls::stream<D_TYPE>& s_result_PE50, hls::stream<D_TYPE>& s_result_PE51, 
    hls::stream<D_TYPE>& s_result_PE52, hls::stream<D_TYPE>& s_result_PE53, 
    hls::stream<D_TYPE>& s_result_PE54, hls::stream<D_TYPE>& s_result_PE55, 
    hls::stream<D_TYPE>& s_result_PE56, hls::stream<D_TYPE>& s_result_PE57, 
    hls::stream<D_TYPE>& s_result_PE58, hls::stream<D_TYPE>& s_result_PE59, 
    hls::stream<D_TYPE>& s_result_PE60, hls::stream<D_TYPE>& s_result_PE61, 
    hls::stream<D_TYPE>& s_result_PE62, hls::stream<D_TYPE>& s_result_PE63, 
    hls::stream<D_TYPE>& s_result_PE64, hls::stream<D_TYPE>& s_result_PE65, 
    hls::stream<D_TYPE>& s_result_PE66, hls::stream<D_TYPE>& s_result_PE67, 
    hls::stream<D_TYPE>& s_result_PE68, hls::stream<D_TYPE>& s_result_PE69, 
    hls::stream<D_TYPE>& s_result_PE70, hls::stream<D_TYPE>& s_result_PE71, 
    hls::stream<D_TYPE>& s_result_PE72, hls::stream<D_TYPE>& s_result_PE73, 
    hls::stream<D_TYPE>& s_result_PE74, hls::stream<D_TYPE>& s_result_PE75, 
    hls::stream<D_TYPE>& s_result_PE76, hls::stream<D_TYPE>& s_result_PE77, 
    hls::stream<D_TYPE>& s_result_PE78, hls::stream<D_TYPE>& s_result_PE79, 
    hls::stream<D_TYPE>& s_result_PE80, hls::stream<D_TYPE>& s_result_PE81, 
    hls::stream<D_TYPE>& s_result_PE82, hls::stream<D_TYPE>& s_result_PE83, 
    hls::stream<D_TYPE>& s_result_PE84, hls::stream<D_TYPE>& s_result_PE85, 
    hls::stream<D_TYPE>& s_result_PE86, hls::stream<D_TYPE>& s_result_PE87, 
    hls::stream<D_TYPE>& s_result_PE88, hls::stream<D_TYPE>& s_result_PE89, 
    hls::stream<D_TYPE>& s_result_PE90, hls::stream<D_TYPE>& s_result_PE91, 
    hls::stream<D_TYPE>& s_result_PE92, hls::stream<D_TYPE>& s_result_PE93, 
    hls::stream<D_TYPE>& s_result_PE94, hls::stream<D_TYPE>& s_result_PE95, 
    hls::stream<D_TYPE>& s_result_PE96, hls::stream<D_TYPE>& s_result_PE97, 
    hls::stream<D_TYPE>& s_result_PE98, hls::stream<D_TYPE>& s_result_PE99, 
    hls::stream<D_TYPE>& s_result_PE100, hls::stream<D_TYPE>& s_result_PE101, 
    hls::stream<D_TYPE>& s_result_PE102, hls::stream<D_TYPE>& s_result_PE103, 
    hls::stream<D_TYPE>& s_result_PE104, hls::stream<D_TYPE>& s_result_PE105, 
    hls::stream<D_TYPE>& s_result_PE106, hls::stream<D_TYPE>& s_result_PE107, 
    hls::stream<D_TYPE>& s_result_PE108, hls::stream<D_TYPE>& s_result_PE109, 
    hls::stream<D_TYPE>& s_result_PE110, hls::stream<D_TYPE>& s_result_PE111, 
    hls::stream<D_TYPE>& s_result_PE112, hls::stream<D_TYPE>& s_result_PE113, 
    hls::stream<D_TYPE>& s_result_PE114, hls::stream<D_TYPE>& s_result_PE115, 
    hls::stream<D_TYPE>& s_result_PE116, hls::stream<D_TYPE>& s_result_PE117, 
    hls::stream<D_TYPE>& s_result_PE118, hls::stream<D_TYPE>& s_result_PE119, 
    hls::stream<D_TYPE>& s_result_PE120, hls::stream<D_TYPE>& s_result_PE121, 
    hls::stream<D_TYPE>& s_result_PE122, hls::stream<D_TYPE>& s_result_PE123, 
    hls::stream<D_TYPE>& s_result_PE124, hls::stream<D_TYPE>& s_result_PE125, 
    hls::stream<D_TYPE>& s_result_PE126, hls::stream<D_TYPE>& s_result_PE127, 
    hls::stream<D_TYPE>& s_result_PE128, hls::stream<D_TYPE>& s_result_PE129,
    hls::stream<D_TYPE>& s_result_PE130, hls::stream<D_TYPE>& s_result_PE131,
    hls::stream<D_TYPE>& s_result_PE132, hls::stream<D_TYPE>& s_result_PE133,
    hls::stream<D_TYPE>& s_result_PE134, hls::stream<D_TYPE>& s_result_PE135,
    hls::stream<D_TYPE>& s_result_PE136, hls::stream<D_TYPE>& s_result_PE137,
    hls::stream<D_TYPE>& s_result_PE138, hls::stream<D_TYPE>& s_result_PE139,
    hls::stream<D_TYPE>& s_result_PE140, hls::stream<D_TYPE>& s_result_PE141,
    hls::stream<D_TYPE>& s_result_PE142, hls::stream<D_TYPE>& s_result_PE143,
    hls::stream<D_TYPE>& s_result_PE144, hls::stream<D_TYPE>& s_result_PE145,
    hls::stream<D_TYPE>& s_result_PE146, hls::stream<D_TYPE>& s_result_PE147,
    hls::stream<D_TYPE>& s_result_PE148, hls::stream<D_TYPE>& s_result_PE149,
    hls::stream<D_TYPE>& s_result_PE150, hls::stream<D_TYPE>& s_result_PE151,
    hls::stream<D_TYPE>& s_result_PE152, hls::stream<D_TYPE>& s_result_PE153,
    hls::stream<D_TYPE>& s_result_PE154, hls::stream<D_TYPE>& s_result_PE155,
    hls::stream<D_TYPE>& s_result_PE156, hls::stream<D_TYPE>& s_result_PE157,
    hls::stream<D_TYPE>& s_result_PE158, hls::stream<D_TYPE>& s_result_PE159,
    hls::stream<ap_uint<512> >& s_result_all)
{
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++){
        #pragma HLS pipeline II=20
        ap_uint<512> reg0, reg1, reg2, reg3, reg4, reg5, reg6, reg7, 
            reg8, reg9;

        reg0.range(31, 0) = s_result_PE0.read() + 1;
        reg0.range(63, 32) = s_result_PE1.read() + 1;
        reg0.range(95, 64) = s_result_PE2.read() + 1;
        reg0.range(127, 96) = s_result_PE3.read() + 1;
        reg0.range(159, 128) = s_result_PE4.read() + 1;
        reg0.range(191, 160) = s_result_PE5.read() + 1;
        reg0.range(223, 192) = s_result_PE6.read() + 1;
        reg0.range(255, 224) = s_result_PE7.read() + 1;
        reg0.range(287, 256) = s_result_PE8.read() + 1;
        reg0.range(319, 288) = s_result_PE9.read() + 1;
        reg0.range(351, 320) = s_result_PE10.read() + 1;
        reg0.range(383, 352) = s_result_PE11.read() + 1;
        reg0.range(415, 384) = s_result_PE12.read() + 1;
        reg0.range(447, 416) = s_result_PE13.read() + 1;
        reg0.range(479, 448) = s_result_PE14.read() + 1;
        reg0.range(511, 480) = s_result_PE15.read() + 1;
        s_result_all.write(reg0);

        reg1.range(31, 0) = s_result_PE16.read() + 1;
        reg1.range(63, 32) = s_result_PE17.read() + 1;
        reg1.range(95, 64) = s_result_PE18.read() + 1;
        reg1.range(127, 96) = s_result_PE19.read() + 1;
        reg1.range(159, 128) = s_result_PE20.read() + 1;
        reg1.range(191, 160) = s_result_PE21.read() + 1;
        reg1.range(223, 192) = s_result_PE22.read() + 1;
        reg1.range(255, 224) = s_result_PE23.read() + 1;
        reg1.range(287, 256) = s_result_PE24.read() + 1;
        reg1.range(319, 288) = s_result_PE25.read() + 1;
        reg1.range(351, 320) = s_result_PE26.read() + 1;
        reg1.range(383, 352) = s_result_PE27.read() + 1;
        reg1.range(415, 384) = s_result_PE28.read() + 1;
        reg1.range(447, 416) = s_result_PE29.read() + 1;
        reg1.range(479, 448) = s_result_PE30.read() + 1;
        reg1.range(511, 480) = s_result_PE31.read() + 1;
        s_result_all.write(reg1);

        reg2.range(31, 0) = s_result_PE32.read() + 1;
        reg2.range(63, 32) = s_result_PE33.read() + 1;
        reg2.range(95, 64) = s_result_PE34.read() + 1;
        reg2.range(127, 96) = s_result_PE35.read() + 1;
        reg2.range(159, 128) = s_result_PE36.read() + 1;
        reg2.range(191, 160) = s_result_PE37.read() + 1;
        reg2.range(223, 192) = s_result_PE38.read() + 1;
        reg2.range(255, 224) = s_result_PE39.read() + 1;
        reg2.range(287, 256) = s_result_PE40.read() + 1;
        reg2.range(319, 288) = s_result_PE41.read() + 1;
        reg2.range(351, 320) = s_result_PE42.read() + 1;
        reg2.range(383, 352) = s_result_PE43.read() + 1;
        reg2.range(415, 384) = s_result_PE44.read() + 1;
        reg2.range(447, 416) = s_result_PE45.read() + 1;
        reg2.range(479, 448) = s_result_PE46.read() + 1;
        reg2.range(511, 480) = s_result_PE47.read() + 1;
        s_result_all.write(reg2);

        reg3.range(31, 0) = s_result_PE48.read() + 1;
        reg3.range(63, 32) = s_result_PE49.read() + 1;
        reg3.range(95, 64) = s_result_PE50.read() + 1;
        reg3.range(127, 96) = s_result_PE51.read() + 1;
        reg3.range(159, 128) = s_result_PE52.read() + 1;
        reg3.range(191, 160) = s_result_PE53.read() + 1;
        reg3.range(223, 192) = s_result_PE54.read() + 1;
        reg3.range(255, 224) = s_result_PE55.read() + 1;
        reg3.range(287, 256) = s_result_PE56.read() + 1;
        reg3.range(319, 288) = s_result_PE57.read() + 1;
        reg3.range(351, 320) = s_result_PE58.read() + 1;
        reg3.range(383, 352) = s_result_PE59.read() + 1;
        reg3.range(415, 384) = s_result_PE60.read() + 1;
        reg3.range(447, 416) = s_result_PE61.read() + 1;
        reg3.range(479, 448) = s_result_PE62.read() + 1;
        reg3.range(511, 480) = s_result_PE63.read() + 1;
        s_result_all.write(reg3);

        reg4.range(31, 0) = s_result_PE64.read() + 1;
        reg4.range(63, 32) = s_result_PE65.read() + 1;
        reg4.range(95, 64) = s_result_PE66.read() + 1;
        reg4.range(127, 96) = s_result_PE67.read() + 1;
        reg4.range(159, 128) = s_result_PE68.read() + 1;
        reg4.range(191, 160) = s_result_PE69.read() + 1;
        reg4.range(223, 192) = s_result_PE70.read() + 1;
        reg4.range(255, 224) = s_result_PE71.read() + 1;
        reg4.range(287, 256) = s_result_PE72.read() + 1;
        reg4.range(319, 288) = s_result_PE73.read() + 1;
        reg4.range(351, 320) = s_result_PE74.read() + 1;
        reg4.range(383, 352) = s_result_PE75.read() + 1;
        reg4.range(415, 384) = s_result_PE76.read() + 1;
        reg4.range(447, 416) = s_result_PE77.read() + 1;
        reg4.range(479, 448) = s_result_PE78.read() + 1;
        reg4.range(511, 480) = s_result_PE79.read() + 1;
        s_result_all.write(reg4);

        reg5.range(31, 0) = s_result_PE80.read() + 1;
        reg5.range(63, 32) = s_result_PE81.read() + 1;
        reg5.range(95, 64) = s_result_PE82.read() + 1;
        reg5.range(127, 96) = s_result_PE83.read() + 1;
        reg5.range(159, 128) = s_result_PE84.read() + 1;
        reg5.range(191, 160) = s_result_PE85.read() + 1;
        reg5.range(223, 192) = s_result_PE86.read() + 1;
        reg5.range(255, 224) = s_result_PE87.read() + 1;
        reg5.range(287, 256) = s_result_PE88.read() + 1;
        reg5.range(319, 288) = s_result_PE89.read() + 1;
        reg5.range(351, 320) = s_result_PE90.read() + 1;
        reg5.range(383, 352) = s_result_PE91.read() + 1;
        reg5.range(415, 384) = s_result_PE92.read() + 1;
        reg5.range(447, 416) = s_result_PE93.read() + 1;
        reg5.range(479, 448) = s_result_PE94.read() + 1;
        reg5.range(511, 480) = s_result_PE95.read() + 1;
        s_result_all.write(reg5);

        reg6.range(31, 0) = s_result_PE96.read() + 1;
        reg6.range(63, 32) = s_result_PE97.read() + 1;
        reg6.range(95, 64) = s_result_PE98.read() + 1;
        reg6.range(127, 96) = s_result_PE99.read() + 1;
        reg6.range(159, 128) = s_result_PE100.read() + 1;
        reg6.range(191, 160) = s_result_PE101.read() + 1;
        reg6.range(223, 192) = s_result_PE102.read() + 1;
        reg6.range(255, 224) = s_result_PE103.read() + 1;
        reg6.range(287, 256) = s_result_PE104.read() + 1;
        reg6.range(319, 288) = s_result_PE105.read() + 1;
        reg6.range(351, 320) = s_result_PE106.read() + 1;
        reg6.range(383, 352) = s_result_PE107.read() + 1;
        reg6.range(415, 384) = s_result_PE108.read() + 1;
        reg6.range(447, 416) = s_result_PE109.read() + 1;
        reg6.range(479, 448) = s_result_PE110.read() + 1;
        reg6.range(511, 480) = s_result_PE111.read() + 1;
        s_result_all.write(reg6);

        reg7.range(31, 0) = s_result_PE112.read() + 1;
        reg7.range(63, 32) = s_result_PE113.read() + 1;
        reg7.range(95, 64) = s_result_PE114.read() + 1;
        reg7.range(127, 96) = s_result_PE115.read() + 1;
        reg7.range(159, 128) = s_result_PE116.read() + 1;
        reg7.range(191, 160) = s_result_PE117.read() + 1;
        reg7.range(223, 192) = s_result_PE118.read() + 1;
        reg7.range(255, 224) = s_result_PE119.read() + 1;
        reg7.range(287, 256) = s_result_PE120.read() + 1;
        reg7.range(319, 288) = s_result_PE121.read() + 1;
        reg7.range(351, 320) = s_result_PE122.read() + 1;
        reg7.range(383, 352) = s_result_PE123.read() + 1;
        reg7.range(415, 384) = s_result_PE124.read() + 1;
        reg7.range(447, 416) = s_result_PE125.read() + 1;
        reg7.range(479, 448) = s_result_PE126.read() + 1;
        reg7.range(511, 480) = s_result_PE127.read() + 1;
        s_result_all.write(reg7);

        reg8.range(31, 0) = s_result_PE128.read() + 1;
        reg8.range(63, 32) = s_result_PE129.read() + 1;
        reg8.range(95, 64) = s_result_PE130.read() + 1;
        reg8.range(127, 96) = s_result_PE131.read() + 1;
        reg8.range(159, 128) = s_result_PE132.read() + 1;
        reg8.range(191, 160) = s_result_PE133.read() + 1;
        reg8.range(223, 192) = s_result_PE134.read() + 1;
        reg8.range(255, 224) = s_result_PE135.read() + 1;
        reg8.range(287, 256) = s_result_PE136.read() + 1;
        reg8.range(319, 288) = s_result_PE137.read() + 1;
        reg8.range(351, 320) = s_result_PE138.read() + 1;
        reg8.range(383, 352) = s_result_PE139.read() + 1;
        reg8.range(415, 384) = s_result_PE140.read() + 1;
        reg8.range(447, 416) = s_result_PE141.read() + 1;
        reg8.range(479, 448) = s_result_PE142.read() + 1;
        reg8.range(511, 480) = s_result_PE143.read() + 1;
        s_result_all.write(reg8);

        reg9.range(31, 0) = s_result_PE144.read() + 1;
        reg9.range(63, 32) = s_result_PE145.read() + 1;
        reg9.range(95, 64) = s_result_PE146.read() + 1;
        reg9.range(127, 96) = s_result_PE147.read() + 1;
        reg9.range(159, 128) = s_result_PE148.read() + 1;
        reg9.range(191, 160) = s_result_PE149.read() + 1;
        reg9.range(223, 192) = s_result_PE150.read() + 1;
        reg9.range(255, 224) = s_result_PE151.read() + 1;
        reg9.range(287, 256) = s_result_PE152.read() + 1;
        reg9.range(319, 288) = s_result_PE153.read() + 1;
        reg9.range(351, 320) = s_result_PE154.read() + 1;
        reg9.range(383, 352) = s_result_PE155.read() + 1;
        reg9.range(415, 384) = s_result_PE156.read() + 1;
        reg9.range(447, 416) = s_result_PE157.read() + 1;
        reg9.range(479, 448) = s_result_PE158.read() + 1;
        reg9.range(511, 480) = s_result_PE159.read() + 1;
        s_result_all.write(reg9);
    }
}

template<const int ROW_PER_PE>
void gather_results_224PEs(
    hls::stream<D_TYPE>& s_result_PE0, hls::stream<D_TYPE>& s_result_PE1, 
    hls::stream<D_TYPE>& s_result_PE2, hls::stream<D_TYPE>& s_result_PE3, 
    hls::stream<D_TYPE>& s_result_PE4, hls::stream<D_TYPE>& s_result_PE5, 
    hls::stream<D_TYPE>& s_result_PE6, hls::stream<D_TYPE>& s_result_PE7, 
    hls::stream<D_TYPE>& s_result_PE8, hls::stream<D_TYPE>& s_result_PE9, 
    hls::stream<D_TYPE>& s_result_PE10, hls::stream<D_TYPE>& s_result_PE11, 
    hls::stream<D_TYPE>& s_result_PE12, hls::stream<D_TYPE>& s_result_PE13, 
    hls::stream<D_TYPE>& s_result_PE14, hls::stream<D_TYPE>& s_result_PE15, 
    hls::stream<D_TYPE>& s_result_PE16, hls::stream<D_TYPE>& s_result_PE17, 
    hls::stream<D_TYPE>& s_result_PE18, hls::stream<D_TYPE>& s_result_PE19, 
    hls::stream<D_TYPE>& s_result_PE20, hls::stream<D_TYPE>& s_result_PE21, 
    hls::stream<D_TYPE>& s_result_PE22, hls::stream<D_TYPE>& s_result_PE23, 
    hls::stream<D_TYPE>& s_result_PE24, hls::stream<D_TYPE>& s_result_PE25, 
    hls::stream<D_TYPE>& s_result_PE26, hls::stream<D_TYPE>& s_result_PE27, 
    hls::stream<D_TYPE>& s_result_PE28, hls::stream<D_TYPE>& s_result_PE29, 
    hls::stream<D_TYPE>& s_result_PE30, hls::stream<D_TYPE>& s_result_PE31, 
    hls::stream<D_TYPE>& s_result_PE32, hls::stream<D_TYPE>& s_result_PE33, 
    hls::stream<D_TYPE>& s_result_PE34, hls::stream<D_TYPE>& s_result_PE35, 
    hls::stream<D_TYPE>& s_result_PE36, hls::stream<D_TYPE>& s_result_PE37, 
    hls::stream<D_TYPE>& s_result_PE38, hls::stream<D_TYPE>& s_result_PE39, 
    hls::stream<D_TYPE>& s_result_PE40, hls::stream<D_TYPE>& s_result_PE41, 
    hls::stream<D_TYPE>& s_result_PE42, hls::stream<D_TYPE>& s_result_PE43, 
    hls::stream<D_TYPE>& s_result_PE44, hls::stream<D_TYPE>& s_result_PE45, 
    hls::stream<D_TYPE>& s_result_PE46, hls::stream<D_TYPE>& s_result_PE47, 
    hls::stream<D_TYPE>& s_result_PE48, hls::stream<D_TYPE>& s_result_PE49, 
    hls::stream<D_TYPE>& s_result_PE50, hls::stream<D_TYPE>& s_result_PE51, 
    hls::stream<D_TYPE>& s_result_PE52, hls::stream<D_TYPE>& s_result_PE53, 
    hls::stream<D_TYPE>& s_result_PE54, hls::stream<D_TYPE>& s_result_PE55, 
    hls::stream<D_TYPE>& s_result_PE56, hls::stream<D_TYPE>& s_result_PE57, 
    hls::stream<D_TYPE>& s_result_PE58, hls::stream<D_TYPE>& s_result_PE59, 
    hls::stream<D_TYPE>& s_result_PE60, hls::stream<D_TYPE>& s_result_PE61, 
    hls::stream<D_TYPE>& s_result_PE62, hls::stream<D_TYPE>& s_result_PE63, 
    hls::stream<D_TYPE>& s_result_PE64, hls::stream<D_TYPE>& s_result_PE65, 
    hls::stream<D_TYPE>& s_result_PE66, hls::stream<D_TYPE>& s_result_PE67, 
    hls::stream<D_TYPE>& s_result_PE68, hls::stream<D_TYPE>& s_result_PE69, 
    hls::stream<D_TYPE>& s_result_PE70, hls::stream<D_TYPE>& s_result_PE71, 
    hls::stream<D_TYPE>& s_result_PE72, hls::stream<D_TYPE>& s_result_PE73, 
    hls::stream<D_TYPE>& s_result_PE74, hls::stream<D_TYPE>& s_result_PE75, 
    hls::stream<D_TYPE>& s_result_PE76, hls::stream<D_TYPE>& s_result_PE77, 
    hls::stream<D_TYPE>& s_result_PE78, hls::stream<D_TYPE>& s_result_PE79, 
    hls::stream<D_TYPE>& s_result_PE80, hls::stream<D_TYPE>& s_result_PE81, 
    hls::stream<D_TYPE>& s_result_PE82, hls::stream<D_TYPE>& s_result_PE83, 
    hls::stream<D_TYPE>& s_result_PE84, hls::stream<D_TYPE>& s_result_PE85, 
    hls::stream<D_TYPE>& s_result_PE86, hls::stream<D_TYPE>& s_result_PE87, 
    hls::stream<D_TYPE>& s_result_PE88, hls::stream<D_TYPE>& s_result_PE89, 
    hls::stream<D_TYPE>& s_result_PE90, hls::stream<D_TYPE>& s_result_PE91, 
    hls::stream<D_TYPE>& s_result_PE92, hls::stream<D_TYPE>& s_result_PE93, 
    hls::stream<D_TYPE>& s_result_PE94, hls::stream<D_TYPE>& s_result_PE95, 
    hls::stream<D_TYPE>& s_result_PE96, hls::stream<D_TYPE>& s_result_PE97, 
    hls::stream<D_TYPE>& s_result_PE98, hls::stream<D_TYPE>& s_result_PE99, 
    hls::stream<D_TYPE>& s_result_PE100, hls::stream<D_TYPE>& s_result_PE101, 
    hls::stream<D_TYPE>& s_result_PE102, hls::stream<D_TYPE>& s_result_PE103, 
    hls::stream<D_TYPE>& s_result_PE104, hls::stream<D_TYPE>& s_result_PE105, 
    hls::stream<D_TYPE>& s_result_PE106, hls::stream<D_TYPE>& s_result_PE107, 
    hls::stream<D_TYPE>& s_result_PE108, hls::stream<D_TYPE>& s_result_PE109, 
    hls::stream<D_TYPE>& s_result_PE110, hls::stream<D_TYPE>& s_result_PE111, 
    hls::stream<D_TYPE>& s_result_PE112, hls::stream<D_TYPE>& s_result_PE113, 
    hls::stream<D_TYPE>& s_result_PE114, hls::stream<D_TYPE>& s_result_PE115, 
    hls::stream<D_TYPE>& s_result_PE116, hls::stream<D_TYPE>& s_result_PE117, 
    hls::stream<D_TYPE>& s_result_PE118, hls::stream<D_TYPE>& s_result_PE119, 
    hls::stream<D_TYPE>& s_result_PE120, hls::stream<D_TYPE>& s_result_PE121, 
    hls::stream<D_TYPE>& s_result_PE122, hls::stream<D_TYPE>& s_result_PE123, 
    hls::stream<D_TYPE>& s_result_PE124, hls::stream<D_TYPE>& s_result_PE125, 
    hls::stream<D_TYPE>& s_result_PE126, hls::stream<D_TYPE>& s_result_PE127, 
    hls::stream<D_TYPE>& s_result_PE128, hls::stream<D_TYPE>& s_result_PE129,
    hls::stream<D_TYPE>& s_result_PE130, hls::stream<D_TYPE>& s_result_PE131,
    hls::stream<D_TYPE>& s_result_PE132, hls::stream<D_TYPE>& s_result_PE133,
    hls::stream<D_TYPE>& s_result_PE134, hls::stream<D_TYPE>& s_result_PE135,
    hls::stream<D_TYPE>& s_result_PE136, hls::stream<D_TYPE>& s_result_PE137,
    hls::stream<D_TYPE>& s_result_PE138, hls::stream<D_TYPE>& s_result_PE139,
    hls::stream<D_TYPE>& s_result_PE140, hls::stream<D_TYPE>& s_result_PE141,
    hls::stream<D_TYPE>& s_result_PE142, hls::stream<D_TYPE>& s_result_PE143,
    hls::stream<D_TYPE>& s_result_PE144, hls::stream<D_TYPE>& s_result_PE145,
    hls::stream<D_TYPE>& s_result_PE146, hls::stream<D_TYPE>& s_result_PE147,
    hls::stream<D_TYPE>& s_result_PE148, hls::stream<D_TYPE>& s_result_PE149,
    hls::stream<D_TYPE>& s_result_PE150, hls::stream<D_TYPE>& s_result_PE151,
    hls::stream<D_TYPE>& s_result_PE152, hls::stream<D_TYPE>& s_result_PE153,
    hls::stream<D_TYPE>& s_result_PE154, hls::stream<D_TYPE>& s_result_PE155,
    hls::stream<D_TYPE>& s_result_PE156, hls::stream<D_TYPE>& s_result_PE157,
    hls::stream<D_TYPE>& s_result_PE158, hls::stream<D_TYPE>& s_result_PE159,
    hls::stream<D_TYPE>& s_result_PE160, hls::stream<D_TYPE>& s_result_PE161,
    hls::stream<D_TYPE>& s_result_PE162, hls::stream<D_TYPE>& s_result_PE163,
    hls::stream<D_TYPE>& s_result_PE164, hls::stream<D_TYPE>& s_result_PE165,
    hls::stream<D_TYPE>& s_result_PE166, hls::stream<D_TYPE>& s_result_PE167,
    hls::stream<D_TYPE>& s_result_PE168, hls::stream<D_TYPE>& s_result_PE169,
    hls::stream<D_TYPE>& s_result_PE170, hls::stream<D_TYPE>& s_result_PE171,
    hls::stream<D_TYPE>& s_result_PE172, hls::stream<D_TYPE>& s_result_PE173,
    hls::stream<D_TYPE>& s_result_PE174, hls::stream<D_TYPE>& s_result_PE175,
    hls::stream<D_TYPE>& s_result_PE176, hls::stream<D_TYPE>& s_result_PE177,
    hls::stream<D_TYPE>& s_result_PE178, hls::stream<D_TYPE>& s_result_PE179,
    hls::stream<D_TYPE>& s_result_PE180, hls::stream<D_TYPE>& s_result_PE181,
    hls::stream<D_TYPE>& s_result_PE182, hls::stream<D_TYPE>& s_result_PE183,
    hls::stream<D_TYPE>& s_result_PE184, hls::stream<D_TYPE>& s_result_PE185,
    hls::stream<D_TYPE>& s_result_PE186, hls::stream<D_TYPE>& s_result_PE187,
    hls::stream<D_TYPE>& s_result_PE188, hls::stream<D_TYPE>& s_result_PE189,
    hls::stream<D_TYPE>& s_result_PE190, hls::stream<D_TYPE>& s_result_PE191,
    hls::stream<D_TYPE>& s_result_PE192, hls::stream<D_TYPE>& s_result_PE193,
    hls::stream<D_TYPE>& s_result_PE194, hls::stream<D_TYPE>& s_result_PE195,
    hls::stream<D_TYPE>& s_result_PE196, hls::stream<D_TYPE>& s_result_PE197,
    hls::stream<D_TYPE>& s_result_PE198, hls::stream<D_TYPE>& s_result_PE199,
    hls::stream<D_TYPE>& s_result_PE200, hls::stream<D_TYPE>& s_result_PE201, 
    hls::stream<D_TYPE>& s_result_PE202, hls::stream<D_TYPE>& s_result_PE203, 
    hls::stream<D_TYPE>& s_result_PE204, hls::stream<D_TYPE>& s_result_PE205, 
    hls::stream<D_TYPE>& s_result_PE206, hls::stream<D_TYPE>& s_result_PE207, 
    hls::stream<D_TYPE>& s_result_PE208, hls::stream<D_TYPE>& s_result_PE209, 
    hls::stream<D_TYPE>& s_result_PE210, hls::stream<D_TYPE>& s_result_PE211, 
    hls::stream<D_TYPE>& s_result_PE212, hls::stream<D_TYPE>& s_result_PE213, 
    hls::stream<D_TYPE>& s_result_PE214, hls::stream<D_TYPE>& s_result_PE215,
    hls::stream<D_TYPE>& s_result_PE216, hls::stream<D_TYPE>& s_result_PE217, 
    hls::stream<D_TYPE>& s_result_PE218, hls::stream<D_TYPE>& s_result_PE219, 
    hls::stream<D_TYPE>& s_result_PE220, hls::stream<D_TYPE>& s_result_PE221, 
    hls::stream<D_TYPE>& s_result_PE222, hls::stream<D_TYPE>& s_result_PE223, 
    hls::stream<ap_uint<512> >& s_result_all) {
     
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        #pragma HLS pipeline II=14  // write 1 result_all per CC

        ap_uint<512> reg0, reg1, reg2, reg3, reg4, reg5, reg6, reg7, 
            reg8, reg9, reg10, reg11, reg12, reg13;

    //print("        reg",str(i),".range(31, 0)    = s_result_PE",str(16*i),".read() + 1;",sep='')
    //print("        reg",str(i),".range(63, 32)   = s_result_PE",str(16*i+1),".read() + 1;",sep='')
    //print("        reg",str(i),".range(95, 64)   = s_result_PE",str(16*i+2),".read() + 1;",sep='')
    //print("        reg",str(i),".range(127, 96)  = s_result_PE",str(16*i+3),".read() + 1;",sep='')
    //print("        reg",str(i),".range(159, 128) = s_result_PE",str(16*i+4),".read() + 1;",sep='')
    //print("        reg",str(i),".range(191, 160) = s_result_PE",str(16*i+5),".read() + 1;",sep='')
    //print("        reg",str(i),".range(223, 192) = s_result_PE",str(16*i+6),".read() + 1;",sep='')
    //print("        reg",str(i),".range(255, 224) = s_result_PE",str(16*i+7),".read() + 1;",sep='')
    //print("        reg",str(i),".range(287, 256) = s_result_PE",str(16*i+8),".read() + 1;",sep='')
    //print("        reg",str(i),".range(319, 288) = s_result_PE",str(16*i+9),".read() + 1;",sep='')
    //print("        reg",str(i),".range(351, 320) = s_result_PE",str(16*i+10),".read() + 1;",sep='')
    //print("        reg",str(i),".range(383, 352) = s_result_PE",str(16*i+11),".read() + 1;",sep='')
    //print("        reg",str(i),".range(415, 384) = s_result_PE",str(16*i+12),".read() + 1;",sep='')
    //print("        reg",str(i),".range(447, 416) = s_result_PE",str(16*i+13),".read() + 1;",sep='')
    //print("        reg",str(i),".range(479, 448) = s_result_PE",str(16*i+14),".read() + 1;",sep='')
    //print("        reg",str(i),".range(511, 480) = s_result_PE",str(16*i+15),".read() + 1;",sep='')

        reg0.range(31, 0)    = s_result_PE0.read() + 1;
        reg0.range(63, 32)   = s_result_PE1.read() + 1;
        reg0.range(95, 64)   = s_result_PE2.read() + 1;
        reg0.range(127, 96)  = s_result_PE3.read() + 1;
        reg0.range(159, 128) = s_result_PE4.read() + 1;
        reg0.range(191, 160) = s_result_PE5.read() + 1;
        reg0.range(223, 192) = s_result_PE6.read() + 1;
        reg0.range(255, 224) = s_result_PE7.read() + 1;
        reg0.range(287, 256) = s_result_PE8.read() + 1;
        reg0.range(319, 288) = s_result_PE9.read() + 1;
        reg0.range(351, 320) = s_result_PE10.read() + 1;
        reg0.range(383, 352) = s_result_PE11.read() + 1;
        reg0.range(415, 384) = s_result_PE12.read() + 1;
        reg0.range(447, 416) = s_result_PE13.read() + 1;
        reg0.range(479, 448) = s_result_PE14.read() + 1;
        reg0.range(511, 480) = s_result_PE15.read() + 1;
        s_result_all.write(reg0);

        reg1.range(31, 0)    = s_result_PE16.read() + 1;
        reg1.range(63, 32)   = s_result_PE17.read() + 1;
        reg1.range(95, 64)   = s_result_PE18.read() + 1;
        reg1.range(127, 96)  = s_result_PE19.read() + 1;
        reg1.range(159, 128) = s_result_PE20.read() + 1;
        reg1.range(191, 160) = s_result_PE21.read() + 1;
        reg1.range(223, 192) = s_result_PE22.read() + 1;
        reg1.range(255, 224) = s_result_PE23.read() + 1;
        reg1.range(287, 256) = s_result_PE24.read() + 1;
        reg1.range(319, 288) = s_result_PE25.read() + 1;
        reg1.range(351, 320) = s_result_PE26.read() + 1;
        reg1.range(383, 352) = s_result_PE27.read() + 1;
        reg1.range(415, 384) = s_result_PE28.read() + 1;
        reg1.range(447, 416) = s_result_PE29.read() + 1;
        reg1.range(479, 448) = s_result_PE30.read() + 1;
        reg1.range(511, 480) = s_result_PE31.read() + 1;
        s_result_all.write(reg1);

        reg2.range(31, 0)    = s_result_PE32.read() + 1;
        reg2.range(63, 32)   = s_result_PE33.read() + 1;
        reg2.range(95, 64)   = s_result_PE34.read() + 1;
        reg2.range(127, 96)  = s_result_PE35.read() + 1;
        reg2.range(159, 128) = s_result_PE36.read() + 1;
        reg2.range(191, 160) = s_result_PE37.read() + 1;
        reg2.range(223, 192) = s_result_PE38.read() + 1;
        reg2.range(255, 224) = s_result_PE39.read() + 1;
        reg2.range(287, 256) = s_result_PE40.read() + 1;
        reg2.range(319, 288) = s_result_PE41.read() + 1;
        reg2.range(351, 320) = s_result_PE42.read() + 1;
        reg2.range(383, 352) = s_result_PE43.read() + 1;
        reg2.range(415, 384) = s_result_PE44.read() + 1;
        reg2.range(447, 416) = s_result_PE45.read() + 1;
        reg2.range(479, 448) = s_result_PE46.read() + 1;
        reg2.range(511, 480) = s_result_PE47.read() + 1;
        s_result_all.write(reg2);

        reg3.range(31, 0)    = s_result_PE48.read() + 1;
        reg3.range(63, 32)   = s_result_PE49.read() + 1;
        reg3.range(95, 64)   = s_result_PE50.read() + 1;
        reg3.range(127, 96)  = s_result_PE51.read() + 1;
        reg3.range(159, 128) = s_result_PE52.read() + 1;
        reg3.range(191, 160) = s_result_PE53.read() + 1;
        reg3.range(223, 192) = s_result_PE54.read() + 1;
        reg3.range(255, 224) = s_result_PE55.read() + 1;
        reg3.range(287, 256) = s_result_PE56.read() + 1;
        reg3.range(319, 288) = s_result_PE57.read() + 1;
        reg3.range(351, 320) = s_result_PE58.read() + 1;
        reg3.range(383, 352) = s_result_PE59.read() + 1;
        reg3.range(415, 384) = s_result_PE60.read() + 1;
        reg3.range(447, 416) = s_result_PE61.read() + 1;
        reg3.range(479, 448) = s_result_PE62.read() + 1;
        reg3.range(511, 480) = s_result_PE63.read() + 1;
        s_result_all.write(reg3);

        reg4.range(31, 0)    = s_result_PE64.read() + 1;
        reg4.range(63, 32)   = s_result_PE65.read() + 1;
        reg4.range(95, 64)   = s_result_PE66.read() + 1;
        reg4.range(127, 96)  = s_result_PE67.read() + 1;
        reg4.range(159, 128) = s_result_PE68.read() + 1;
        reg4.range(191, 160) = s_result_PE69.read() + 1;
        reg4.range(223, 192) = s_result_PE70.read() + 1;
        reg4.range(255, 224) = s_result_PE71.read() + 1;
        reg4.range(287, 256) = s_result_PE72.read() + 1;
        reg4.range(319, 288) = s_result_PE73.read() + 1;
        reg4.range(351, 320) = s_result_PE74.read() + 1;
        reg4.range(383, 352) = s_result_PE75.read() + 1;
        reg4.range(415, 384) = s_result_PE76.read() + 1;
        reg4.range(447, 416) = s_result_PE77.read() + 1;
        reg4.range(479, 448) = s_result_PE78.read() + 1;
        reg4.range(511, 480) = s_result_PE79.read() + 1;
        s_result_all.write(reg4);

        reg5.range(31, 0)    = s_result_PE80.read() + 1;
        reg5.range(63, 32)   = s_result_PE81.read() + 1;
        reg5.range(95, 64)   = s_result_PE82.read() + 1;
        reg5.range(127, 96)  = s_result_PE83.read() + 1;
        reg5.range(159, 128) = s_result_PE84.read() + 1;
        reg5.range(191, 160) = s_result_PE85.read() + 1;
        reg5.range(223, 192) = s_result_PE86.read() + 1;
        reg5.range(255, 224) = s_result_PE87.read() + 1;
        reg5.range(287, 256) = s_result_PE88.read() + 1;
        reg5.range(319, 288) = s_result_PE89.read() + 1;
        reg5.range(351, 320) = s_result_PE90.read() + 1;
        reg5.range(383, 352) = s_result_PE91.read() + 1;
        reg5.range(415, 384) = s_result_PE92.read() + 1;
        reg5.range(447, 416) = s_result_PE93.read() + 1;
        reg5.range(479, 448) = s_result_PE94.read() + 1;
        reg5.range(511, 480) = s_result_PE95.read() + 1;
        s_result_all.write(reg5);

        reg6.range(31, 0)    = s_result_PE96.read() + 1;
        reg6.range(63, 32)   = s_result_PE97.read() + 1;
        reg6.range(95, 64)   = s_result_PE98.read() + 1;
        reg6.range(127, 96)  = s_result_PE99.read() + 1;
        reg6.range(159, 128) = s_result_PE100.read() + 1;
        reg6.range(191, 160) = s_result_PE101.read() + 1;
        reg6.range(223, 192) = s_result_PE102.read() + 1;
        reg6.range(255, 224) = s_result_PE103.read() + 1;
        reg6.range(287, 256) = s_result_PE104.read() + 1;
        reg6.range(319, 288) = s_result_PE105.read() + 1;
        reg6.range(351, 320) = s_result_PE106.read() + 1;
        reg6.range(383, 352) = s_result_PE107.read() + 1;
        reg6.range(415, 384) = s_result_PE108.read() + 1;
        reg6.range(447, 416) = s_result_PE109.read() + 1;
        reg6.range(479, 448) = s_result_PE110.read() + 1;
        reg6.range(511, 480) = s_result_PE111.read() + 1;
        s_result_all.write(reg6);

        reg7.range(31, 0)    = s_result_PE112.read() + 1;
        reg7.range(63, 32)   = s_result_PE113.read() + 1;
        reg7.range(95, 64)   = s_result_PE114.read() + 1;
        reg7.range(127, 96)  = s_result_PE115.read() + 1;
        reg7.range(159, 128) = s_result_PE116.read() + 1;
        reg7.range(191, 160) = s_result_PE117.read() + 1;
        reg7.range(223, 192) = s_result_PE118.read() + 1;
        reg7.range(255, 224) = s_result_PE119.read() + 1;
        reg7.range(287, 256) = s_result_PE120.read() + 1;
        reg7.range(319, 288) = s_result_PE121.read() + 1;
        reg7.range(351, 320) = s_result_PE122.read() + 1;
        reg7.range(383, 352) = s_result_PE123.read() + 1;
        reg7.range(415, 384) = s_result_PE124.read() + 1;
        reg7.range(447, 416) = s_result_PE125.read() + 1;
        reg7.range(479, 448) = s_result_PE126.read() + 1;
        reg7.range(511, 480) = s_result_PE127.read() + 1;
        s_result_all.write(reg7);

        reg8.range(31, 0)    = s_result_PE128.read() + 1;
        reg8.range(63, 32)   = s_result_PE129.read() + 1;
        reg8.range(95, 64)   = s_result_PE130.read() + 1;
        reg8.range(127, 96)  = s_result_PE131.read() + 1;
        reg8.range(159, 128) = s_result_PE132.read() + 1;
        reg8.range(191, 160) = s_result_PE133.read() + 1;
        reg8.range(223, 192) = s_result_PE134.read() + 1;
        reg8.range(255, 224) = s_result_PE135.read() + 1;
        reg8.range(287, 256) = s_result_PE136.read() + 1;
        reg8.range(319, 288) = s_result_PE137.read() + 1;
        reg8.range(351, 320) = s_result_PE138.read() + 1;
        reg8.range(383, 352) = s_result_PE139.read() + 1;
        reg8.range(415, 384) = s_result_PE140.read() + 1;
        reg8.range(447, 416) = s_result_PE141.read() + 1;
        reg8.range(479, 448) = s_result_PE142.read() + 1;
        reg8.range(511, 480) = s_result_PE143.read() + 1;
        s_result_all.write(reg8);

        reg9.range(31, 0)    = s_result_PE144.read() + 1;
        reg9.range(63, 32)   = s_result_PE145.read() + 1;
        reg9.range(95, 64)   = s_result_PE146.read() + 1;
        reg9.range(127, 96)  = s_result_PE147.read() + 1;
        reg9.range(159, 128) = s_result_PE148.read() + 1;
        reg9.range(191, 160) = s_result_PE149.read() + 1;
        reg9.range(223, 192) = s_result_PE150.read() + 1;
        reg9.range(255, 224) = s_result_PE151.read() + 1;
        reg9.range(287, 256) = s_result_PE152.read() + 1;
        reg9.range(319, 288) = s_result_PE153.read() + 1;
        reg9.range(351, 320) = s_result_PE154.read() + 1;
        reg9.range(383, 352) = s_result_PE155.read() + 1;
        reg9.range(415, 384) = s_result_PE156.read() + 1;
        reg9.range(447, 416) = s_result_PE157.read() + 1;
        reg9.range(479, 448) = s_result_PE158.read() + 1;
        reg9.range(511, 480) = s_result_PE159.read() + 1;
        s_result_all.write(reg9);

        reg10.range(31, 0)    = s_result_PE160.read() + 1;
        reg10.range(63, 32)   = s_result_PE161.read() + 1;
        reg10.range(95, 64)   = s_result_PE162.read() + 1;
        reg10.range(127, 96)  = s_result_PE163.read() + 1;
        reg10.range(159, 128) = s_result_PE164.read() + 1;
        reg10.range(191, 160) = s_result_PE165.read() + 1;
        reg10.range(223, 192) = s_result_PE166.read() + 1;
        reg10.range(255, 224) = s_result_PE167.read() + 1;
        reg10.range(287, 256) = s_result_PE168.read() + 1;
        reg10.range(319, 288) = s_result_PE169.read() + 1;
        reg10.range(351, 320) = s_result_PE170.read() + 1;
        reg10.range(383, 352) = s_result_PE171.read() + 1;
        reg10.range(415, 384) = s_result_PE172.read() + 1;
        reg10.range(447, 416) = s_result_PE173.read() + 1;
        reg10.range(479, 448) = s_result_PE174.read() + 1;
        reg10.range(511, 480) = s_result_PE175.read() + 1;
        s_result_all.write(reg10);

        reg11.range(31, 0)    = s_result_PE176.read() + 1;
        reg11.range(63, 32)   = s_result_PE177.read() + 1;
        reg11.range(95, 64)   = s_result_PE178.read() + 1;
        reg11.range(127, 96)  = s_result_PE179.read() + 1;
        reg11.range(159, 128) = s_result_PE180.read() + 1;
        reg11.range(191, 160) = s_result_PE181.read() + 1;
        reg11.range(223, 192) = s_result_PE182.read() + 1;
        reg11.range(255, 224) = s_result_PE183.read() + 1;
        reg11.range(287, 256) = s_result_PE184.read() + 1;
        reg11.range(319, 288) = s_result_PE185.read() + 1;
        reg11.range(351, 320) = s_result_PE186.read() + 1;
        reg11.range(383, 352) = s_result_PE187.read() + 1;
        reg11.range(415, 384) = s_result_PE188.read() + 1;
        reg11.range(447, 416) = s_result_PE189.read() + 1;
        reg11.range(479, 448) = s_result_PE190.read() + 1;
        reg11.range(511, 480) = s_result_PE191.read() + 1;
        s_result_all.write(reg11);

        reg12.range(31, 0)    = s_result_PE192.read() + 1;
        reg12.range(63, 32)   = s_result_PE193.read() + 1;
        reg12.range(95, 64)   = s_result_PE194.read() + 1;
        reg12.range(127, 96)  = s_result_PE195.read() + 1;
        reg12.range(159, 128) = s_result_PE196.read() + 1;
        reg12.range(191, 160) = s_result_PE197.read() + 1;
        reg12.range(223, 192) = s_result_PE198.read() + 1;
        reg12.range(255, 224) = s_result_PE199.read() + 1;
        reg12.range(287, 256) = s_result_PE200.read() + 1;
        reg12.range(319, 288) = s_result_PE201.read() + 1;
        reg12.range(351, 320) = s_result_PE202.read() + 1;
        reg12.range(383, 352) = s_result_PE203.read() + 1;
        reg12.range(415, 384) = s_result_PE204.read() + 1;
        reg12.range(447, 416) = s_result_PE205.read() + 1;
        reg12.range(479, 448) = s_result_PE206.read() + 1;
        reg12.range(511, 480) = s_result_PE207.read() + 1;
        s_result_all.write(reg12);

        reg13.range(31, 0)    = s_result_PE208.read() + 1;
        reg13.range(63, 32)   = s_result_PE209.read() + 1;
        reg13.range(95, 64)   = s_result_PE210.read() + 1;
        reg13.range(127, 96)  = s_result_PE211.read() + 1;
        reg13.range(159, 128) = s_result_PE212.read() + 1;
        reg13.range(191, 160) = s_result_PE213.read() + 1;
        reg13.range(223, 192) = s_result_PE214.read() + 1;
        reg13.range(255, 224) = s_result_PE215.read() + 1;
        reg13.range(287, 256) = s_result_PE216.read() + 1;
        reg13.range(319, 288) = s_result_PE217.read() + 1;
        reg13.range(351, 320) = s_result_PE218.read() + 1;
        reg13.range(383, 352) = s_result_PE219.read() + 1;
        reg13.range(415, 384) = s_result_PE220.read() + 1;
        reg13.range(447, 416) = s_result_PE221.read() + 1;
        reg13.range(479, 448) = s_result_PE222.read() + 1;
        reg13.range(511, 480) = s_result_PE223.read() + 1;
        s_result_all.write(reg13);
    }
}

template<const int ROW_PER_PE>
void gather_results_32PEs(
    hls::stream<D_TYPE>& s_result_PE0, hls::stream<D_TYPE>& s_result_PE1, 
    hls::stream<D_TYPE>& s_result_PE2, hls::stream<D_TYPE>& s_result_PE3, 
    hls::stream<D_TYPE>& s_result_PE4, hls::stream<D_TYPE>& s_result_PE5, 
    hls::stream<D_TYPE>& s_result_PE6, hls::stream<D_TYPE>& s_result_PE7, 
    hls::stream<D_TYPE>& s_result_PE8, hls::stream<D_TYPE>& s_result_PE9, 
    hls::stream<D_TYPE>& s_result_PE10, hls::stream<D_TYPE>& s_result_PE11, 
    hls::stream<D_TYPE>& s_result_PE12, hls::stream<D_TYPE>& s_result_PE13, 
    hls::stream<D_TYPE>& s_result_PE14, hls::stream<D_TYPE>& s_result_PE15, 
    hls::stream<D_TYPE>& s_result_PE16, hls::stream<D_TYPE>& s_result_PE17, 
    hls::stream<D_TYPE>& s_result_PE18, hls::stream<D_TYPE>& s_result_PE19, 
    hls::stream<D_TYPE>& s_result_PE20, hls::stream<D_TYPE>& s_result_PE21, 
    hls::stream<D_TYPE>& s_result_PE22, hls::stream<D_TYPE>& s_result_PE23, 
    hls::stream<D_TYPE>& s_result_PE24, hls::stream<D_TYPE>& s_result_PE25, 
    hls::stream<D_TYPE>& s_result_PE26, hls::stream<D_TYPE>& s_result_PE27, 
    hls::stream<D_TYPE>& s_result_PE28, hls::stream<D_TYPE>& s_result_PE29, 
    hls::stream<D_TYPE>& s_result_PE30, hls::stream<D_TYPE>& s_result_PE31, 
    hls::stream<ap_uint<512> >& s_result_all) {
     
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        #pragma HLS pipeline II=2  // write 1 result_all per CC

        W_TYPE reg0, reg1;

        reg0.range(31, 0)    = s_result_PE0.read() + 1;
        reg0.range(63, 32)   = s_result_PE1.read() + 1;
        reg0.range(95, 64)   = s_result_PE2.read() + 1;
        reg0.range(127, 96)  = s_result_PE3.read() + 1;
        reg0.range(159, 128) = s_result_PE4.read() + 1;
        reg0.range(191, 160) = s_result_PE5.read() + 1;
        reg0.range(223, 192) = s_result_PE6.read() + 1;
        reg0.range(255, 224) = s_result_PE7.read() + 1;
        reg0.range(287, 256) = s_result_PE8.read() + 1;
        reg0.range(319, 288) = s_result_PE9.read() + 1;
        reg0.range(351, 320) = s_result_PE10.read() + 1;
        reg0.range(383, 352) = s_result_PE11.read() + 1;
        reg0.range(415, 384) = s_result_PE12.read() + 1;
        reg0.range(447, 416) = s_result_PE13.read() + 1;
        reg0.range(479, 448) = s_result_PE14.read() + 1;
        reg0.range(511, 480) = s_result_PE15.read() + 1;
        s_result_all.write(reg0);

        reg1.range(31, 0)    = s_result_PE16.read() + 1;
        reg1.range(63, 32)   = s_result_PE17.read() + 1;
        reg1.range(95, 64)   = s_result_PE18.read() + 1;
        reg1.range(127, 96)  = s_result_PE19.read() + 1;
        reg1.range(159, 128) = s_result_PE20.read() + 1;
        reg1.range(191, 160) = s_result_PE21.read() + 1;
        reg1.range(223, 192) = s_result_PE22.read() + 1;
        reg1.range(255, 224) = s_result_PE23.read() + 1;
        reg1.range(287, 256) = s_result_PE24.read() + 1;
        reg1.range(319, 288) = s_result_PE25.read() + 1;
        reg1.range(351, 320) = s_result_PE26.read() + 1;
        reg1.range(383, 352) = s_result_PE27.read() + 1;
        reg1.range(415, 384) = s_result_PE28.read() + 1;
        reg1.range(447, 416) = s_result_PE29.read() + 1;
        reg1.range(479, 448) = s_result_PE30.read() + 1;
        reg1.range(511, 480) = s_result_PE31.read() + 1;
        s_result_all.write(reg1);
    }
}

template<const int ROW_PER_PE>
void gather_results_48PEs(
    hls::stream<D_TYPE>& s_result_PE0, hls::stream<D_TYPE>& s_result_PE1, 
    hls::stream<D_TYPE>& s_result_PE2, hls::stream<D_TYPE>& s_result_PE3, 
    hls::stream<D_TYPE>& s_result_PE4, hls::stream<D_TYPE>& s_result_PE5, 
    hls::stream<D_TYPE>& s_result_PE6, hls::stream<D_TYPE>& s_result_PE7, 
    hls::stream<D_TYPE>& s_result_PE8, hls::stream<D_TYPE>& s_result_PE9, 
    hls::stream<D_TYPE>& s_result_PE10, hls::stream<D_TYPE>& s_result_PE11, 
    hls::stream<D_TYPE>& s_result_PE12, hls::stream<D_TYPE>& s_result_PE13, 
    hls::stream<D_TYPE>& s_result_PE14, hls::stream<D_TYPE>& s_result_PE15, 
    hls::stream<D_TYPE>& s_result_PE16, hls::stream<D_TYPE>& s_result_PE17, 
    hls::stream<D_TYPE>& s_result_PE18, hls::stream<D_TYPE>& s_result_PE19, 
    hls::stream<D_TYPE>& s_result_PE20, hls::stream<D_TYPE>& s_result_PE21, 
    hls::stream<D_TYPE>& s_result_PE22, hls::stream<D_TYPE>& s_result_PE23, 
    hls::stream<D_TYPE>& s_result_PE24, hls::stream<D_TYPE>& s_result_PE25, 
    hls::stream<D_TYPE>& s_result_PE26, hls::stream<D_TYPE>& s_result_PE27, 
    hls::stream<D_TYPE>& s_result_PE28, hls::stream<D_TYPE>& s_result_PE29, 
    hls::stream<D_TYPE>& s_result_PE30, hls::stream<D_TYPE>& s_result_PE31, 
    hls::stream<D_TYPE>& s_result_PE32, hls::stream<D_TYPE>& s_result_PE33, 
    hls::stream<D_TYPE>& s_result_PE34, hls::stream<D_TYPE>& s_result_PE35, 
    hls::stream<D_TYPE>& s_result_PE36, hls::stream<D_TYPE>& s_result_PE37, 
    hls::stream<D_TYPE>& s_result_PE38, hls::stream<D_TYPE>& s_result_PE39, 
    hls::stream<D_TYPE>& s_result_PE40, hls::stream<D_TYPE>& s_result_PE41, 
    hls::stream<D_TYPE>& s_result_PE42, hls::stream<D_TYPE>& s_result_PE43, 
    hls::stream<D_TYPE>& s_result_PE44, hls::stream<D_TYPE>& s_result_PE45, 
    hls::stream<D_TYPE>& s_result_PE46, hls::stream<D_TYPE>& s_result_PE47, 
    hls::stream<ap_uint<512> >& s_result_all) {
     
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        #pragma HLS pipeline II=3  // write 1 result_all per CC

        W_TYPE reg0, reg1, reg2;

        reg0.range(31, 0)    = s_result_PE0.read() + 1;
        reg0.range(63, 32)   = s_result_PE1.read() + 1;
        reg0.range(95, 64)   = s_result_PE2.read() + 1;
        reg0.range(127, 96)  = s_result_PE3.read() + 1;
        reg0.range(159, 128) = s_result_PE4.read() + 1;
        reg0.range(191, 160) = s_result_PE5.read() + 1;
        reg0.range(223, 192) = s_result_PE6.read() + 1;
        reg0.range(255, 224) = s_result_PE7.read() + 1;
        reg0.range(287, 256) = s_result_PE8.read() + 1;
        reg0.range(319, 288) = s_result_PE9.read() + 1;
        reg0.range(351, 320) = s_result_PE10.read() + 1;
        reg0.range(383, 352) = s_result_PE11.read() + 1;
        reg0.range(415, 384) = s_result_PE12.read() + 1;
        reg0.range(447, 416) = s_result_PE13.read() + 1;
        reg0.range(479, 448) = s_result_PE14.read() + 1;
        reg0.range(511, 480) = s_result_PE15.read() + 1;
        s_result_all.write(reg0);

        reg1.range(31, 0)    = s_result_PE16.read() + 1;
        reg1.range(63, 32)   = s_result_PE17.read() + 1;
        reg1.range(95, 64)   = s_result_PE18.read() + 1;
        reg1.range(127, 96)  = s_result_PE19.read() + 1;
        reg1.range(159, 128) = s_result_PE20.read() + 1;
        reg1.range(191, 160) = s_result_PE21.read() + 1;
        reg1.range(223, 192) = s_result_PE22.read() + 1;
        reg1.range(255, 224) = s_result_PE23.read() + 1;
        reg1.range(287, 256) = s_result_PE24.read() + 1;
        reg1.range(319, 288) = s_result_PE25.read() + 1;
        reg1.range(351, 320) = s_result_PE26.read() + 1;
        reg1.range(383, 352) = s_result_PE27.read() + 1;
        reg1.range(415, 384) = s_result_PE28.read() + 1;
        reg1.range(447, 416) = s_result_PE29.read() + 1;
        reg1.range(479, 448) = s_result_PE30.read() + 1;
        reg1.range(511, 480) = s_result_PE31.read() + 1;
        s_result_all.write(reg1);

        reg2.range(31, 0)    = s_result_PE32.read() + 1;
        reg2.range(63, 32)   = s_result_PE33.read() + 1;
        reg2.range(95, 64)   = s_result_PE34.read() + 1;
        reg2.range(127, 96)  = s_result_PE35.read() + 1;
        reg2.range(159, 128) = s_result_PE36.read() + 1;
        reg2.range(191, 160) = s_result_PE37.read() + 1;
        reg2.range(223, 192) = s_result_PE38.read() + 1;
        reg2.range(255, 224) = s_result_PE39.read() + 1;
        reg2.range(287, 256) = s_result_PE40.read() + 1;
        reg2.range(319, 288) = s_result_PE41.read() + 1;
        reg2.range(351, 320) = s_result_PE42.read() + 1;
        reg2.range(383, 352) = s_result_PE43.read() + 1;
        reg2.range(415, 384) = s_result_PE44.read() + 1;
        reg2.range(447, 416) = s_result_PE45.read() + 1;
        reg2.range(479, 448) = s_result_PE46.read() + 1;
        reg2.range(511, 480) = s_result_PE47.read() + 1;
        s_result_all.write(reg2);
    }
}

void dataTransform(
    hls::stream<ap_uint<512> > & s_result_partial_1, hls::stream<ap_uint<512> > & s_result_partial_2, 
    hls::stream<ap_uint<512> > & s_result_partial_3, hls::stream<ap_uint<512> > & s_result_partial_4, 
    hls::stream<ap_uint<512> > & s_result_partial_5, hls::stream<ap_uint<512> > & s_result_partial_6, 
    hls::stream<ap_uint<512> > & s_result_partial_7, hls::stream<ap_uint<512> > & s_result_partial_8, 
    hls::stream<ap_uint<512> > & s_result_partial_9, hls::stream<ap_uint<512> > & s_result_partial_10,
    hls::stream<ap_uint<512> > & s_result_partial_11,
    hls::stream<ap_uint<512> > & s_result_node){
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        for (int i = 0; i < 3; i++){
            #pragma HLS pipeline II=1
            s_result_node.write(s_result_partial_1.read());
        }
        for (int i = 0; i < 3; i++){
            #pragma HLS pipeline II=1
            s_result_node.write(s_result_partial_2.read());
        }
        for (int i = 0; i < 3; i++){
            #pragma HLS pipeline II=1
            s_result_node.write(s_result_partial_3.read());
        }
        for (int i = 0; i < 3; i++){
            #pragma HLS pipeline II=1
            s_result_node.write(s_result_partial_4.read());
        }
        for (int i = 0; i < 3; i++){
            #pragma HLS pipeline II=1
            s_result_node.write(s_result_partial_5.read());
        }
        for (int i = 0; i < 3; i++){
            #pragma HLS pipeline II=1
            s_result_node.write(s_result_partial_6.read());
        }
        for (int i = 0; i < 3; i++){
            #pragma HLS pipeline II=1
            s_result_node.write(s_result_partial_7.read());
        }
        for (int i = 0; i < 3; i++){
            #pragma HLS pipeline II=1
            s_result_node.write(s_result_partial_8.read());
        }
        for (int i = 0; i < 3; i++){
            #pragma HLS pipeline II=1
            s_result_node.write(s_result_partial_9.read());
        }
        for (int i = 0; i < 3; i++){
            #pragma HLS pipeline II=1
            s_result_node.write(s_result_partial_10.read());
        }
        for (int i = 0; i < 2; i++){
            #pragma HLS pipeline II=1
            s_result_node.write(s_result_partial_11.read());
        }
    }
}

void gather_results_layer1(hls::stream<ap_uint<512> > & s_result1_node2, hls::stream<ap_uint<512> > & s_result1_node3, hls::stream<ap_uint<512> > & s_result1_all_1, hls::stream<ap_uint<512> > & s_result1_all_2){
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        for (int i = 0; i < 52; i++){
            #pragma HLS pipeline II=1
            ap_uint<512> s_data = s_result1_node2.read();
            s_result1_all_1.write(s_data);
            s_result1_all_2.write(s_data);
        }
        for (int i = 0; i < 12; i++){
            #pragma HLS pipeline II=1
            ap_uint<512> s_data = s_result1_node3.read();
            s_result1_all_1.write(s_data);
            s_result1_all_2.write(s_data);
        }

    }
}