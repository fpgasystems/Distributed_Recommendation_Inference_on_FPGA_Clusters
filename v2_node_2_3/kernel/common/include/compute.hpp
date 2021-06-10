#include <hls_stream.h>
#include "constants.hpp"

void recvDataTransform(hls::stream<ap_uint<512> > & s_data_in, hls::stream<W_TYPE> & s_feature_in, hls::stream<W_TYPE> & s_result1_node1);

template<const int FEATURE_SIZE, const int ROW_PER_PE, const int INDEX_ROW_PE>
void matmul_PE_UNROLL8(
    hls::stream<W_TYPE>& s_feature_PE,
    hls::stream<D_TYPE>& s_result_PE);

template<>
void matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1, INDEX_ROW_PE1_BRAM>(
    hls::stream<W_TYPE>& s_feature_PE,
    hls::stream<D_TYPE>& s_result_PE);

template<>
void matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1, INDEX_ROW_PE1_URAM>(
    hls::stream<W_TYPE>& s_feature_PE,
    hls::stream<D_TYPE>& s_result_PE);

template<const int FEATURE_SIZE, const int ROW_PER_PE>
void init_weights(W_TYPE* weights_transpose); 

template<>
void init_weights<INPUT_SIZE, ROW_PER_PE1>(W_TYPE* weights_transpose_local);

template<const int FEATURE_SIZE>
void replicate_feature_512PEs_312PE(
    hls::stream<W_TYPE>& s_feature_in, 
    hls::stream<W_TYPE>& s_feature_PE0, hls::stream<W_TYPE>& s_feature_PE1, 
    hls::stream<W_TYPE>& s_feature_PE2, hls::stream<W_TYPE>& s_feature_PE3, 
    hls::stream<W_TYPE>& s_feature_PE4, hls::stream<W_TYPE>& s_feature_PE5, 
    hls::stream<W_TYPE>& s_feature_PE6, hls::stream<W_TYPE>& s_feature_PE7, 
    hls::stream<W_TYPE>& s_feature_PE8, hls::stream<W_TYPE>& s_feature_PE9, 
    hls::stream<W_TYPE>& s_feature_PE10, hls::stream<W_TYPE>& s_feature_PE11, 
    hls::stream<W_TYPE>& s_feature_PE12, hls::stream<W_TYPE>& s_feature_PE13, 
    hls::stream<W_TYPE>& s_feature_PE14, hls::stream<W_TYPE>& s_feature_PE15, 
    hls::stream<W_TYPE>& s_feature_PE16, hls::stream<W_TYPE>& s_feature_PE17, 
    hls::stream<W_TYPE>& s_feature_PE18, hls::stream<W_TYPE>& s_feature_PE19, 
    hls::stream<W_TYPE>& s_feature_PE20, hls::stream<W_TYPE>& s_feature_PE21, 
    hls::stream<W_TYPE>& s_feature_PE22, hls::stream<W_TYPE>& s_feature_PE23, 
    hls::stream<W_TYPE>& s_feature_PE24, hls::stream<W_TYPE>& s_feature_PE25, 
    hls::stream<W_TYPE>& s_feature_PE26, hls::stream<W_TYPE>& s_feature_PE27, 
    hls::stream<W_TYPE>& s_feature_PE28, hls::stream<W_TYPE>& s_feature_PE29, 
    hls::stream<W_TYPE>& s_feature_PE30, hls::stream<W_TYPE>& s_feature_PE31, 
    hls::stream<W_TYPE>& s_feature_PE32, hls::stream<W_TYPE>& s_feature_PE33, 
    hls::stream<W_TYPE>& s_feature_PE34, hls::stream<W_TYPE>& s_feature_PE35, 
    hls::stream<W_TYPE>& s_feature_PE36, hls::stream<W_TYPE>& s_feature_PE37, 
    hls::stream<W_TYPE>& s_feature_PE38, hls::stream<W_TYPE>& s_feature_PE39, 
    hls::stream<W_TYPE>& s_feature_PE40, hls::stream<W_TYPE>& s_feature_PE41, 
    hls::stream<W_TYPE>& s_feature_PE42, hls::stream<W_TYPE>& s_feature_PE43, 
    hls::stream<W_TYPE>& s_feature_PE44, hls::stream<W_TYPE>& s_feature_PE45, 
    hls::stream<W_TYPE>& s_feature_PE46, hls::stream<W_TYPE>& s_feature_PE47, 
    hls::stream<W_TYPE>& s_feature_PE48, hls::stream<W_TYPE>& s_feature_PE49, 
    hls::stream<W_TYPE>& s_feature_PE50, hls::stream<W_TYPE>& s_feature_PE51, 
    hls::stream<W_TYPE>& s_feature_PE52, hls::stream<W_TYPE>& s_feature_PE53, 
    hls::stream<W_TYPE>& s_feature_PE54, hls::stream<W_TYPE>& s_feature_PE55, 
    hls::stream<W_TYPE>& s_feature_PE56, hls::stream<W_TYPE>& s_feature_PE57, 
    hls::stream<W_TYPE>& s_feature_PE58, hls::stream<W_TYPE>& s_feature_PE59, 
    hls::stream<W_TYPE>& s_feature_PE60, hls::stream<W_TYPE>& s_feature_PE61, 
    hls::stream<W_TYPE>& s_feature_PE62, hls::stream<W_TYPE>& s_feature_PE63, 
    hls::stream<W_TYPE>& s_feature_PE64, hls::stream<W_TYPE>& s_feature_PE65, 
    hls::stream<W_TYPE>& s_feature_PE66, hls::stream<W_TYPE>& s_feature_PE67, 
    hls::stream<W_TYPE>& s_feature_PE68, hls::stream<W_TYPE>& s_feature_PE69, 
    hls::stream<W_TYPE>& s_feature_PE70, hls::stream<W_TYPE>& s_feature_PE71, 
    hls::stream<W_TYPE>& s_feature_PE72, hls::stream<W_TYPE>& s_feature_PE73, 
    hls::stream<W_TYPE>& s_feature_PE74, hls::stream<W_TYPE>& s_feature_PE75, 
    hls::stream<W_TYPE>& s_feature_PE76, hls::stream<W_TYPE>& s_feature_PE77, 
    hls::stream<W_TYPE>& s_feature_PE78, hls::stream<W_TYPE>& s_feature_PE79, 
    hls::stream<W_TYPE>& s_feature_PE80, hls::stream<W_TYPE>& s_feature_PE81, 
    hls::stream<W_TYPE>& s_feature_PE82, hls::stream<W_TYPE>& s_feature_PE83, 
    hls::stream<W_TYPE>& s_feature_PE84, hls::stream<W_TYPE>& s_feature_PE85, 
    hls::stream<W_TYPE>& s_feature_PE86, hls::stream<W_TYPE>& s_feature_PE87, 
    hls::stream<W_TYPE>& s_feature_PE88, hls::stream<W_TYPE>& s_feature_PE89, 
    hls::stream<W_TYPE>& s_feature_PE90, hls::stream<W_TYPE>& s_feature_PE91, 
    hls::stream<W_TYPE>& s_feature_PE92, hls::stream<W_TYPE>& s_feature_PE93, 
    hls::stream<W_TYPE>& s_feature_PE94, hls::stream<W_TYPE>& s_feature_PE95, 
    hls::stream<W_TYPE>& s_feature_PE96, hls::stream<W_TYPE>& s_feature_PE97, 
    hls::stream<W_TYPE>& s_feature_PE98, hls::stream<W_TYPE>& s_feature_PE99, 
    hls::stream<W_TYPE>& s_feature_PE100, hls::stream<W_TYPE>& s_feature_PE101, 
    hls::stream<W_TYPE>& s_feature_PE102, hls::stream<W_TYPE>& s_feature_PE103, 
    hls::stream<W_TYPE>& s_feature_PE104, hls::stream<W_TYPE>& s_feature_PE105, 
    hls::stream<W_TYPE>& s_feature_PE106, hls::stream<W_TYPE>& s_feature_PE107, 
    hls::stream<W_TYPE>& s_feature_PE108, hls::stream<W_TYPE>& s_feature_PE109, 
    hls::stream<W_TYPE>& s_feature_PE110, hls::stream<W_TYPE>& s_feature_PE111, 
    hls::stream<W_TYPE>& s_feature_PE112, hls::stream<W_TYPE>& s_feature_PE113, 
    hls::stream<W_TYPE>& s_feature_PE114, hls::stream<W_TYPE>& s_feature_PE115, 
    hls::stream<W_TYPE>& s_feature_PE116, hls::stream<W_TYPE>& s_feature_PE117, 
    hls::stream<W_TYPE>& s_feature_PE118, hls::stream<W_TYPE>& s_feature_PE119, 
    hls::stream<W_TYPE>& s_feature_PE120, hls::stream<W_TYPE>& s_feature_PE121, 
    hls::stream<W_TYPE>& s_feature_PE122, hls::stream<W_TYPE>& s_feature_PE123, 
    hls::stream<W_TYPE>& s_feature_PE124, hls::stream<W_TYPE>& s_feature_PE125, 
    hls::stream<W_TYPE>& s_feature_PE126, hls::stream<W_TYPE>& s_feature_PE127,
    hls::stream<W_TYPE>& s_feature_PE128, hls::stream<W_TYPE>& s_feature_PE129,
    hls::stream<W_TYPE>& s_feature_PE130, hls::stream<W_TYPE>& s_feature_PE131,
    hls::stream<W_TYPE>& s_feature_PE132, hls::stream<W_TYPE>& s_feature_PE133,
    hls::stream<W_TYPE>& s_feature_PE134, hls::stream<W_TYPE>& s_feature_PE135,
    hls::stream<W_TYPE>& s_feature_PE136, hls::stream<W_TYPE>& s_feature_PE137,
    hls::stream<W_TYPE>& s_feature_PE138, hls::stream<W_TYPE>& s_feature_PE139,
    hls::stream<W_TYPE>& s_feature_PE140, hls::stream<W_TYPE>& s_feature_PE141,
    hls::stream<W_TYPE>& s_feature_PE142, hls::stream<W_TYPE>& s_feature_PE143,
    hls::stream<W_TYPE>& s_feature_PE144, hls::stream<W_TYPE>& s_feature_PE145,
    hls::stream<W_TYPE>& s_feature_PE146, hls::stream<W_TYPE>& s_feature_PE147,
    hls::stream<W_TYPE>& s_feature_PE148, hls::stream<W_TYPE>& s_feature_PE149,
    hls::stream<W_TYPE>& s_feature_PE150, hls::stream<W_TYPE>& s_feature_PE151,
    hls::stream<W_TYPE>& s_feature_PE152, hls::stream<W_TYPE>& s_feature_PE153,
    hls::stream<W_TYPE>& s_feature_PE154, hls::stream<W_TYPE>& s_feature_PE155,
    hls::stream<W_TYPE>& s_feature_PE156, hls::stream<W_TYPE>& s_feature_PE157,
    hls::stream<W_TYPE>& s_feature_PE158, hls::stream<W_TYPE>& s_feature_PE159,
    hls::stream<W_TYPE>& s_feature_PE160, hls::stream<W_TYPE>& s_feature_PE161,
    hls::stream<W_TYPE>& s_feature_PE162, hls::stream<W_TYPE>& s_feature_PE163,
    hls::stream<W_TYPE>& s_feature_PE164, hls::stream<W_TYPE>& s_feature_PE165,
    hls::stream<W_TYPE>& s_feature_PE166, hls::stream<W_TYPE>& s_feature_PE167,
    hls::stream<W_TYPE>& s_feature_PE168, hls::stream<W_TYPE>& s_feature_PE169,
    hls::stream<W_TYPE>& s_feature_PE170, hls::stream<W_TYPE>& s_feature_PE171,
    hls::stream<W_TYPE>& s_feature_PE172, hls::stream<W_TYPE>& s_feature_PE173,
    hls::stream<W_TYPE>& s_feature_PE174, hls::stream<W_TYPE>& s_feature_PE175,
    hls::stream<W_TYPE>& s_feature_PE176, hls::stream<W_TYPE>& s_feature_PE177,
    hls::stream<W_TYPE>& s_feature_PE178, hls::stream<W_TYPE>& s_feature_PE179,
    hls::stream<W_TYPE>& s_feature_PE180, hls::stream<W_TYPE>& s_feature_PE181,
    hls::stream<W_TYPE>& s_feature_PE182, hls::stream<W_TYPE>& s_feature_PE183,
    hls::stream<W_TYPE>& s_feature_PE184, hls::stream<W_TYPE>& s_feature_PE185,
    hls::stream<W_TYPE>& s_feature_PE186, hls::stream<W_TYPE>& s_feature_PE187,
    hls::stream<W_TYPE>& s_feature_PE188, hls::stream<W_TYPE>& s_feature_PE189,
    hls::stream<W_TYPE>& s_feature_PE190, hls::stream<W_TYPE>& s_feature_PE191,
    hls::stream<W_TYPE>& s_feature_PE192, hls::stream<W_TYPE>& s_feature_PE193,
    hls::stream<W_TYPE>& s_feature_PE194, hls::stream<W_TYPE>& s_feature_PE195,
    hls::stream<W_TYPE>& s_feature_PE196, hls::stream<W_TYPE>& s_feature_PE197,
    hls::stream<W_TYPE>& s_feature_PE198, hls::stream<W_TYPE>& s_feature_PE199,
    hls::stream<W_TYPE>& s_feature_PE200, hls::stream<W_TYPE>& s_feature_PE201, 
    hls::stream<W_TYPE>& s_feature_PE202, hls::stream<W_TYPE>& s_feature_PE203, 
    hls::stream<W_TYPE>& s_feature_PE204, hls::stream<W_TYPE>& s_feature_PE205, 
    hls::stream<W_TYPE>& s_feature_PE206, hls::stream<W_TYPE>& s_feature_PE207, 
    hls::stream<W_TYPE>& s_feature_PE208, hls::stream<W_TYPE>& s_feature_PE209, 
    hls::stream<W_TYPE>& s_feature_PE210, hls::stream<W_TYPE>& s_feature_PE211, 
    hls::stream<W_TYPE>& s_feature_PE212, hls::stream<W_TYPE>& s_feature_PE213, 
    hls::stream<W_TYPE>& s_feature_PE214, hls::stream<W_TYPE>& s_feature_PE215, 
    hls::stream<W_TYPE>& s_feature_PE216, hls::stream<W_TYPE>& s_feature_PE217, 
    hls::stream<W_TYPE>& s_feature_PE218, hls::stream<W_TYPE>& s_feature_PE219, 
    hls::stream<W_TYPE>& s_feature_PE220, hls::stream<W_TYPE>& s_feature_PE221, 
    hls::stream<W_TYPE>& s_feature_PE222, hls::stream<W_TYPE>& s_feature_PE223, 
    hls::stream<W_TYPE>& s_feature_PE224, hls::stream<W_TYPE>& s_feature_PE225, 
    hls::stream<W_TYPE>& s_feature_PE226, hls::stream<W_TYPE>& s_feature_PE227,
    hls::stream<W_TYPE>& s_feature_PE228, hls::stream<W_TYPE>& s_feature_PE229,
    hls::stream<W_TYPE>& s_feature_PE230, hls::stream<W_TYPE>& s_feature_PE231,
    hls::stream<W_TYPE>& s_feature_PE232, hls::stream<W_TYPE>& s_feature_PE233,
    hls::stream<W_TYPE>& s_feature_PE234, hls::stream<W_TYPE>& s_feature_PE235,
    hls::stream<W_TYPE>& s_feature_PE236, hls::stream<W_TYPE>& s_feature_PE237,
    hls::stream<W_TYPE>& s_feature_PE238, hls::stream<W_TYPE>& s_feature_PE239,
    hls::stream<W_TYPE>& s_feature_PE240, hls::stream<W_TYPE>& s_feature_PE241,
    hls::stream<W_TYPE>& s_feature_PE242, hls::stream<W_TYPE>& s_feature_PE243,
    hls::stream<W_TYPE>& s_feature_PE244, hls::stream<W_TYPE>& s_feature_PE245,
    hls::stream<W_TYPE>& s_feature_PE246, hls::stream<W_TYPE>& s_feature_PE247,
    hls::stream<W_TYPE>& s_feature_PE248, hls::stream<W_TYPE>& s_feature_PE249,
    hls::stream<W_TYPE>& s_feature_PE250, hls::stream<W_TYPE>& s_feature_PE251,
    hls::stream<W_TYPE>& s_feature_PE252, hls::stream<W_TYPE>& s_feature_PE253,
    hls::stream<W_TYPE>& s_feature_PE254, hls::stream<W_TYPE>& s_feature_PE255,
    hls::stream<W_TYPE>& s_feature_PE256, hls::stream<W_TYPE>& s_feature_PE257,
    hls::stream<W_TYPE>& s_feature_PE258, hls::stream<W_TYPE>& s_feature_PE259,
    hls::stream<W_TYPE>& s_feature_PE260, hls::stream<W_TYPE>& s_feature_PE261,
    hls::stream<W_TYPE>& s_feature_PE262, hls::stream<W_TYPE>& s_feature_PE263,
    hls::stream<W_TYPE>& s_feature_PE264, hls::stream<W_TYPE>& s_feature_PE265,
    hls::stream<W_TYPE>& s_feature_PE266, hls::stream<W_TYPE>& s_feature_PE267,
    hls::stream<W_TYPE>& s_feature_PE268, hls::stream<W_TYPE>& s_feature_PE269,
    hls::stream<W_TYPE>& s_feature_PE270, hls::stream<W_TYPE>& s_feature_PE271,
    hls::stream<W_TYPE>& s_feature_PE272, hls::stream<W_TYPE>& s_feature_PE273,
    hls::stream<W_TYPE>& s_feature_PE274, hls::stream<W_TYPE>& s_feature_PE275,
    hls::stream<W_TYPE>& s_feature_PE276, hls::stream<W_TYPE>& s_feature_PE277,
    hls::stream<W_TYPE>& s_feature_PE278, hls::stream<W_TYPE>& s_feature_PE279,
    hls::stream<W_TYPE>& s_feature_PE280, hls::stream<W_TYPE>& s_feature_PE281,
    hls::stream<W_TYPE>& s_feature_PE282, hls::stream<W_TYPE>& s_feature_PE283,
    hls::stream<W_TYPE>& s_feature_PE284, hls::stream<W_TYPE>& s_feature_PE285,
    hls::stream<W_TYPE>& s_feature_PE286, hls::stream<W_TYPE>& s_feature_PE287,
    hls::stream<W_TYPE>& s_feature_PE288, hls::stream<W_TYPE>& s_feature_PE289,
    hls::stream<W_TYPE>& s_feature_PE290, hls::stream<W_TYPE>& s_feature_PE291,
    hls::stream<W_TYPE>& s_feature_PE292, hls::stream<W_TYPE>& s_feature_PE293,
    hls::stream<W_TYPE>& s_feature_PE294, hls::stream<W_TYPE>& s_feature_PE295,
    hls::stream<W_TYPE>& s_feature_PE296, hls::stream<W_TYPE>& s_feature_PE297,
    hls::stream<W_TYPE>& s_feature_PE298, hls::stream<W_TYPE>& s_feature_PE299,
    hls::stream<W_TYPE>& s_feature_PE300, hls::stream<W_TYPE>& s_feature_PE301,
    hls::stream<W_TYPE>& s_feature_PE302, hls::stream<W_TYPE>& s_feature_PE303,
    hls::stream<W_TYPE>& s_feature_PE304, hls::stream<W_TYPE>& s_feature_PE305,
    hls::stream<W_TYPE>& s_feature_PE306, hls::stream<W_TYPE>& s_feature_PE307,
    hls::stream<W_TYPE>& s_feature_PE308, hls::stream<W_TYPE>& s_feature_PE309,
    hls::stream<W_TYPE>& s_feature_PE310, hls::stream<W_TYPE>& s_feature_PE311
);
    
template<const int ROW_PER_PE>
void gather_results_512PEs_312PE(
    hls::stream<W_TYPE>& s_result1_node1,
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
    hls::stream<W_TYPE>& s_result_all);

void dataTransform(hls::stream<W_TYPE> & s_result_all, hls::stream<ap_uint<512> > & s_data_out);


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

void recvDataTransform(hls::stream<ap_uint<512> > & s_data_in, hls::stream<W_TYPE> & s_feature_in, hls::stream<W_TYPE> & s_result1_node1){
    // for every 5 pacekts
    // for every 16*512 bits in each packet
    // the first 11*512 bits is embedding table -> s_feature_in
    // the last 5*512 bits is partial result of layer 1 from node 1 -> s_result1_node1
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE * 5; item++) {
        for (int i = 0; i < 11; i++){
            #pragma HLS pipeline II=1
            W_TYPE reg0, reg1, reg2, reg3;

            ap_uint<512> s_data = s_data_in.read();
            reg0 = s_data(127, 0);
            reg1 = s_data(255, 128);
            reg2 = s_data(383, 256);
            reg3 = s_data(511, 384);

            s_feature_in.write(reg0);
            s_feature_in.write(reg1);
            s_feature_in.write(reg2);
            s_feature_in.write(reg3);
        }
        for (int i = 0; i < 5; i++){
            #pragma HLS pipeline II=1
            W_TYPE reg0, reg1, reg2, reg3;

            ap_uint<512> s_data = s_data_in.read();
            reg0 = s_data(127, 0);
            reg1 = s_data(255, 128);
            reg2 = s_data(383, 256);
            reg3 = s_data(511, 384);

            s_result1_node1.write(reg0);
            s_result1_node1.write(reg1);
            s_result1_node1.write(reg2);
            s_result1_node1.write(reg3);
        }

    }
}

template<>
void matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1, INDEX_ROW_PE1_BRAM>(
    hls::stream<W_TYPE>& s_feature_PE,
    hls::stream<D_TYPE>& s_result_PE) {
#pragma HLS inline off
    // store weights to local at the beginning
    // transpose the weights as well -> e.g., 
    //     orginal weights (row_size, COL_PER_PE)
    //     now: (COL_PER_PE, row_size)
    // so that the dot product is more natural -> 
    //     feature x row0, feature x row1, ...
    W_TYPE weights_transpose_local[ROW_PER_PE1 * INPUT_SIZE / INTS_PER_W];
    W_TYPE feature_local[INPUT_SIZE / INTS_PER_W];
//#pragma HLS resource variable=weights_transpose_local core=RAM_2P_URAM
//#pragma HLS resource variable=feature_local core=RAM_2P_URAM

    init_weights<INPUT_SIZE, ROW_PER_PE1>(weights_transpose_local);

    item_loop:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        // read 
        read_loop:
        for (int i = 0; i < INPUT_SIZE / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            feature_local[i] = s_feature_PE.read();
        }
        // compute and write
        row_loop:
        for (int result_idx = 0; result_idx < ROW_PER_PE1; result_idx++) {
            
            D_TYPE result = 0;
            dot_product:
            // NOTE: manually unroll 2 here
            for (int d = 0; d < INPUT_SIZE / INTS_PER_W / 2; d++) {
                // #pragma HLS unroll factor=4
                #pragma HLS pipeline II=1
                // feature[d] * weights_transpose_local[result_idx][d]
                W_TYPE reg_f_0 = feature_local[2 * d];
                W_TYPE reg_f_1 = feature_local[2 * d + 1];
                W_TYPE reg_w_0 = weights_transpose_local[
                    result_idx * INPUT_SIZE / INTS_PER_W + 2 * d];
                W_TYPE reg_w_1 = weights_transpose_local[
                    result_idx * INPUT_SIZE / INTS_PER_W + 2 * d + 1];

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
} 

template<>
void matmul_PE_UNROLL8<INPUT_SIZE, ROW_PER_PE1, INDEX_ROW_PE1_URAM>(
    hls::stream<W_TYPE>& s_feature_PE,
    hls::stream<D_TYPE>& s_result_PE) {
#pragma HLS inline off
    // store weights to local at the beginning
    // transpose the weights as well -> e.g., 
    //     orginal weights (row_size, COL_PER_PE)
    //     now: (COL_PER_PE, row_size)
    // so that the dot product is more natural -> 
    //     feature x row0, feature x row1, ...
    W_TYPE weights_transpose_local[ROW_PER_PE1 * INPUT_SIZE / INTS_PER_W];
    W_TYPE feature_local[INPUT_SIZE / INTS_PER_W];
#pragma HLS resource variable=weights_transpose_local core=RAM_2P_URAM
#pragma HLS resource variable=feature_local core=RAM_2P_URAM

    init_weights<INPUT_SIZE, ROW_PER_PE1>(weights_transpose_local);

    item_loop:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        // read 
        read_loop:
        for (int i = 0; i < INPUT_SIZE / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            feature_local[i] = s_feature_PE.read();
        }
        // compute and write
        row_loop:
        for (int result_idx = 0; result_idx < ROW_PER_PE1; result_idx++) {
            
            D_TYPE result = 0;
            dot_product:
            // NOTE: manually unroll 2 here
            for (int d = 0; d < INPUT_SIZE / INTS_PER_W / 2; d++) {
                // #pragma HLS unroll factor=4
                #pragma HLS pipeline II=1
                // feature[d] * weights_transpose_local[result_idx][d]
                W_TYPE reg_f_0 = feature_local[2 * d];
                W_TYPE reg_f_1 = feature_local[2 * d + 1];
                W_TYPE reg_w_0 = weights_transpose_local[
                    result_idx * INPUT_SIZE / INTS_PER_W + 2 * d];
                W_TYPE reg_w_1 = weights_transpose_local[
                    result_idx * INPUT_SIZE / INTS_PER_W + 2 * d + 1];

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
}

template<>
void init_weights<INPUT_SIZE, ROW_PER_PE1>(W_TYPE* weights_transpose_local) {
        // same as host side
    // same as the host side, len = 352
    D_TYPE row_template_even[INPUT_SIZE] = 
      { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    D_TYPE row_template_odd[INPUT_SIZE] = 
      { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    // load weights, convert to wide type
    for (int row = 0; row < ROW_PER_PE1 / 2; row++) {
        for (int i = 0; i < INPUT_SIZE / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            W_TYPE reg_even, reg_odd;
            reg_even.range(31, 0) = row_template_even[INTS_PER_W * i];
            reg_even.range(63, 32) = row_template_even[INTS_PER_W * i + 1];
            reg_even.range(95, 64) = row_template_even[INTS_PER_W * i + 2];
            reg_even.range(127, 96) = row_template_even[INTS_PER_W * i + 3];

            reg_odd.range(31, 0) = row_template_odd[INTS_PER_W * i];
            reg_odd.range(63, 32) = row_template_odd[INTS_PER_W * i + 1];
            reg_odd.range(95, 64) = row_template_odd[INTS_PER_W * i + 2];
            reg_odd.range(127, 96) = row_template_odd[INTS_PER_W * i + 3];

            weights_transpose_local[2 * row * INPUT_SIZE / INTS_PER_W + i] = reg_even;
            weights_transpose_local[(2 * row + 1) * INPUT_SIZE / INTS_PER_W + i] = reg_odd;
        }
    }
}


template<const int FEATURE_SIZE>
void replicate_feature_512PEs_312PE(
    hls::stream<W_TYPE>& s_feature_in, 
    hls::stream<W_TYPE>& s_feature_PE0, hls::stream<W_TYPE>& s_feature_PE1, 
    hls::stream<W_TYPE>& s_feature_PE2, hls::stream<W_TYPE>& s_feature_PE3, 
    hls::stream<W_TYPE>& s_feature_PE4, hls::stream<W_TYPE>& s_feature_PE5, 
    hls::stream<W_TYPE>& s_feature_PE6, hls::stream<W_TYPE>& s_feature_PE7, 
    hls::stream<W_TYPE>& s_feature_PE8, hls::stream<W_TYPE>& s_feature_PE9, 
    hls::stream<W_TYPE>& s_feature_PE10, hls::stream<W_TYPE>& s_feature_PE11, 
    hls::stream<W_TYPE>& s_feature_PE12, hls::stream<W_TYPE>& s_feature_PE13, 
    hls::stream<W_TYPE>& s_feature_PE14, hls::stream<W_TYPE>& s_feature_PE15, 
    hls::stream<W_TYPE>& s_feature_PE16, hls::stream<W_TYPE>& s_feature_PE17, 
    hls::stream<W_TYPE>& s_feature_PE18, hls::stream<W_TYPE>& s_feature_PE19, 
    hls::stream<W_TYPE>& s_feature_PE20, hls::stream<W_TYPE>& s_feature_PE21, 
    hls::stream<W_TYPE>& s_feature_PE22, hls::stream<W_TYPE>& s_feature_PE23, 
    hls::stream<W_TYPE>& s_feature_PE24, hls::stream<W_TYPE>& s_feature_PE25, 
    hls::stream<W_TYPE>& s_feature_PE26, hls::stream<W_TYPE>& s_feature_PE27, 
    hls::stream<W_TYPE>& s_feature_PE28, hls::stream<W_TYPE>& s_feature_PE29, 
    hls::stream<W_TYPE>& s_feature_PE30, hls::stream<W_TYPE>& s_feature_PE31, 
    hls::stream<W_TYPE>& s_feature_PE32, hls::stream<W_TYPE>& s_feature_PE33, 
    hls::stream<W_TYPE>& s_feature_PE34, hls::stream<W_TYPE>& s_feature_PE35, 
    hls::stream<W_TYPE>& s_feature_PE36, hls::stream<W_TYPE>& s_feature_PE37, 
    hls::stream<W_TYPE>& s_feature_PE38, hls::stream<W_TYPE>& s_feature_PE39, 
    hls::stream<W_TYPE>& s_feature_PE40, hls::stream<W_TYPE>& s_feature_PE41, 
    hls::stream<W_TYPE>& s_feature_PE42, hls::stream<W_TYPE>& s_feature_PE43, 
    hls::stream<W_TYPE>& s_feature_PE44, hls::stream<W_TYPE>& s_feature_PE45, 
    hls::stream<W_TYPE>& s_feature_PE46, hls::stream<W_TYPE>& s_feature_PE47, 
    hls::stream<W_TYPE>& s_feature_PE48, hls::stream<W_TYPE>& s_feature_PE49, 
    hls::stream<W_TYPE>& s_feature_PE50, hls::stream<W_TYPE>& s_feature_PE51, 
    hls::stream<W_TYPE>& s_feature_PE52, hls::stream<W_TYPE>& s_feature_PE53, 
    hls::stream<W_TYPE>& s_feature_PE54, hls::stream<W_TYPE>& s_feature_PE55, 
    hls::stream<W_TYPE>& s_feature_PE56, hls::stream<W_TYPE>& s_feature_PE57, 
    hls::stream<W_TYPE>& s_feature_PE58, hls::stream<W_TYPE>& s_feature_PE59, 
    hls::stream<W_TYPE>& s_feature_PE60, hls::stream<W_TYPE>& s_feature_PE61, 
    hls::stream<W_TYPE>& s_feature_PE62, hls::stream<W_TYPE>& s_feature_PE63, 
    hls::stream<W_TYPE>& s_feature_PE64, hls::stream<W_TYPE>& s_feature_PE65, 
    hls::stream<W_TYPE>& s_feature_PE66, hls::stream<W_TYPE>& s_feature_PE67, 
    hls::stream<W_TYPE>& s_feature_PE68, hls::stream<W_TYPE>& s_feature_PE69, 
    hls::stream<W_TYPE>& s_feature_PE70, hls::stream<W_TYPE>& s_feature_PE71, 
    hls::stream<W_TYPE>& s_feature_PE72, hls::stream<W_TYPE>& s_feature_PE73, 
    hls::stream<W_TYPE>& s_feature_PE74, hls::stream<W_TYPE>& s_feature_PE75, 
    hls::stream<W_TYPE>& s_feature_PE76, hls::stream<W_TYPE>& s_feature_PE77, 
    hls::stream<W_TYPE>& s_feature_PE78, hls::stream<W_TYPE>& s_feature_PE79, 
    hls::stream<W_TYPE>& s_feature_PE80, hls::stream<W_TYPE>& s_feature_PE81, 
    hls::stream<W_TYPE>& s_feature_PE82, hls::stream<W_TYPE>& s_feature_PE83, 
    hls::stream<W_TYPE>& s_feature_PE84, hls::stream<W_TYPE>& s_feature_PE85, 
    hls::stream<W_TYPE>& s_feature_PE86, hls::stream<W_TYPE>& s_feature_PE87, 
    hls::stream<W_TYPE>& s_feature_PE88, hls::stream<W_TYPE>& s_feature_PE89, 
    hls::stream<W_TYPE>& s_feature_PE90, hls::stream<W_TYPE>& s_feature_PE91, 
    hls::stream<W_TYPE>& s_feature_PE92, hls::stream<W_TYPE>& s_feature_PE93, 
    hls::stream<W_TYPE>& s_feature_PE94, hls::stream<W_TYPE>& s_feature_PE95, 
    hls::stream<W_TYPE>& s_feature_PE96, hls::stream<W_TYPE>& s_feature_PE97, 
    hls::stream<W_TYPE>& s_feature_PE98, hls::stream<W_TYPE>& s_feature_PE99, 
    hls::stream<W_TYPE>& s_feature_PE100, hls::stream<W_TYPE>& s_feature_PE101, 
    hls::stream<W_TYPE>& s_feature_PE102, hls::stream<W_TYPE>& s_feature_PE103, 
    hls::stream<W_TYPE>& s_feature_PE104, hls::stream<W_TYPE>& s_feature_PE105, 
    hls::stream<W_TYPE>& s_feature_PE106, hls::stream<W_TYPE>& s_feature_PE107, 
    hls::stream<W_TYPE>& s_feature_PE108, hls::stream<W_TYPE>& s_feature_PE109, 
    hls::stream<W_TYPE>& s_feature_PE110, hls::stream<W_TYPE>& s_feature_PE111, 
    hls::stream<W_TYPE>& s_feature_PE112, hls::stream<W_TYPE>& s_feature_PE113, 
    hls::stream<W_TYPE>& s_feature_PE114, hls::stream<W_TYPE>& s_feature_PE115, 
    hls::stream<W_TYPE>& s_feature_PE116, hls::stream<W_TYPE>& s_feature_PE117, 
    hls::stream<W_TYPE>& s_feature_PE118, hls::stream<W_TYPE>& s_feature_PE119, 
    hls::stream<W_TYPE>& s_feature_PE120, hls::stream<W_TYPE>& s_feature_PE121, 
    hls::stream<W_TYPE>& s_feature_PE122, hls::stream<W_TYPE>& s_feature_PE123, 
    hls::stream<W_TYPE>& s_feature_PE124, hls::stream<W_TYPE>& s_feature_PE125, 
    hls::stream<W_TYPE>& s_feature_PE126, hls::stream<W_TYPE>& s_feature_PE127,
    hls::stream<W_TYPE>& s_feature_PE128, hls::stream<W_TYPE>& s_feature_PE129,
    hls::stream<W_TYPE>& s_feature_PE130, hls::stream<W_TYPE>& s_feature_PE131,
    hls::stream<W_TYPE>& s_feature_PE132, hls::stream<W_TYPE>& s_feature_PE133,
    hls::stream<W_TYPE>& s_feature_PE134, hls::stream<W_TYPE>& s_feature_PE135,
    hls::stream<W_TYPE>& s_feature_PE136, hls::stream<W_TYPE>& s_feature_PE137,
    hls::stream<W_TYPE>& s_feature_PE138, hls::stream<W_TYPE>& s_feature_PE139,
    hls::stream<W_TYPE>& s_feature_PE140, hls::stream<W_TYPE>& s_feature_PE141,
    hls::stream<W_TYPE>& s_feature_PE142, hls::stream<W_TYPE>& s_feature_PE143,
    hls::stream<W_TYPE>& s_feature_PE144, hls::stream<W_TYPE>& s_feature_PE145,
    hls::stream<W_TYPE>& s_feature_PE146, hls::stream<W_TYPE>& s_feature_PE147,
    hls::stream<W_TYPE>& s_feature_PE148, hls::stream<W_TYPE>& s_feature_PE149,
    hls::stream<W_TYPE>& s_feature_PE150, hls::stream<W_TYPE>& s_feature_PE151,
    hls::stream<W_TYPE>& s_feature_PE152, hls::stream<W_TYPE>& s_feature_PE153,
    hls::stream<W_TYPE>& s_feature_PE154, hls::stream<W_TYPE>& s_feature_PE155,
    hls::stream<W_TYPE>& s_feature_PE156, hls::stream<W_TYPE>& s_feature_PE157,
    hls::stream<W_TYPE>& s_feature_PE158, hls::stream<W_TYPE>& s_feature_PE159,
    hls::stream<W_TYPE>& s_feature_PE160, hls::stream<W_TYPE>& s_feature_PE161,
    hls::stream<W_TYPE>& s_feature_PE162, hls::stream<W_TYPE>& s_feature_PE163,
    hls::stream<W_TYPE>& s_feature_PE164, hls::stream<W_TYPE>& s_feature_PE165,
    hls::stream<W_TYPE>& s_feature_PE166, hls::stream<W_TYPE>& s_feature_PE167,
    hls::stream<W_TYPE>& s_feature_PE168, hls::stream<W_TYPE>& s_feature_PE169,
    hls::stream<W_TYPE>& s_feature_PE170, hls::stream<W_TYPE>& s_feature_PE171,
    hls::stream<W_TYPE>& s_feature_PE172, hls::stream<W_TYPE>& s_feature_PE173,
    hls::stream<W_TYPE>& s_feature_PE174, hls::stream<W_TYPE>& s_feature_PE175,
    hls::stream<W_TYPE>& s_feature_PE176, hls::stream<W_TYPE>& s_feature_PE177,
    hls::stream<W_TYPE>& s_feature_PE178, hls::stream<W_TYPE>& s_feature_PE179,
    hls::stream<W_TYPE>& s_feature_PE180, hls::stream<W_TYPE>& s_feature_PE181,
    hls::stream<W_TYPE>& s_feature_PE182, hls::stream<W_TYPE>& s_feature_PE183,
    hls::stream<W_TYPE>& s_feature_PE184, hls::stream<W_TYPE>& s_feature_PE185,
    hls::stream<W_TYPE>& s_feature_PE186, hls::stream<W_TYPE>& s_feature_PE187,
    hls::stream<W_TYPE>& s_feature_PE188, hls::stream<W_TYPE>& s_feature_PE189,
    hls::stream<W_TYPE>& s_feature_PE190, hls::stream<W_TYPE>& s_feature_PE191,
    hls::stream<W_TYPE>& s_feature_PE192, hls::stream<W_TYPE>& s_feature_PE193,
    hls::stream<W_TYPE>& s_feature_PE194, hls::stream<W_TYPE>& s_feature_PE195,
    hls::stream<W_TYPE>& s_feature_PE196, hls::stream<W_TYPE>& s_feature_PE197,
    hls::stream<W_TYPE>& s_feature_PE198, hls::stream<W_TYPE>& s_feature_PE199,
    hls::stream<W_TYPE>& s_feature_PE200, hls::stream<W_TYPE>& s_feature_PE201, 
    hls::stream<W_TYPE>& s_feature_PE202, hls::stream<W_TYPE>& s_feature_PE203, 
    hls::stream<W_TYPE>& s_feature_PE204, hls::stream<W_TYPE>& s_feature_PE205, 
    hls::stream<W_TYPE>& s_feature_PE206, hls::stream<W_TYPE>& s_feature_PE207, 
    hls::stream<W_TYPE>& s_feature_PE208, hls::stream<W_TYPE>& s_feature_PE209, 
    hls::stream<W_TYPE>& s_feature_PE210, hls::stream<W_TYPE>& s_feature_PE211, 
    hls::stream<W_TYPE>& s_feature_PE212, hls::stream<W_TYPE>& s_feature_PE213, 
    hls::stream<W_TYPE>& s_feature_PE214, hls::stream<W_TYPE>& s_feature_PE215, 
    hls::stream<W_TYPE>& s_feature_PE216, hls::stream<W_TYPE>& s_feature_PE217, 
    hls::stream<W_TYPE>& s_feature_PE218, hls::stream<W_TYPE>& s_feature_PE219, 
    hls::stream<W_TYPE>& s_feature_PE220, hls::stream<W_TYPE>& s_feature_PE221, 
    hls::stream<W_TYPE>& s_feature_PE222, hls::stream<W_TYPE>& s_feature_PE223, 
    hls::stream<W_TYPE>& s_feature_PE224, hls::stream<W_TYPE>& s_feature_PE225, 
    hls::stream<W_TYPE>& s_feature_PE226, hls::stream<W_TYPE>& s_feature_PE227,
    hls::stream<W_TYPE>& s_feature_PE228, hls::stream<W_TYPE>& s_feature_PE229,
    hls::stream<W_TYPE>& s_feature_PE230, hls::stream<W_TYPE>& s_feature_PE231,
    hls::stream<W_TYPE>& s_feature_PE232, hls::stream<W_TYPE>& s_feature_PE233,
    hls::stream<W_TYPE>& s_feature_PE234, hls::stream<W_TYPE>& s_feature_PE235,
    hls::stream<W_TYPE>& s_feature_PE236, hls::stream<W_TYPE>& s_feature_PE237,
    hls::stream<W_TYPE>& s_feature_PE238, hls::stream<W_TYPE>& s_feature_PE239,
    hls::stream<W_TYPE>& s_feature_PE240, hls::stream<W_TYPE>& s_feature_PE241,
    hls::stream<W_TYPE>& s_feature_PE242, hls::stream<W_TYPE>& s_feature_PE243,
    hls::stream<W_TYPE>& s_feature_PE244, hls::stream<W_TYPE>& s_feature_PE245,
    hls::stream<W_TYPE>& s_feature_PE246, hls::stream<W_TYPE>& s_feature_PE247,
    hls::stream<W_TYPE>& s_feature_PE248, hls::stream<W_TYPE>& s_feature_PE249,
    hls::stream<W_TYPE>& s_feature_PE250, hls::stream<W_TYPE>& s_feature_PE251,
    hls::stream<W_TYPE>& s_feature_PE252, hls::stream<W_TYPE>& s_feature_PE253,
    hls::stream<W_TYPE>& s_feature_PE254, hls::stream<W_TYPE>& s_feature_PE255,
    hls::stream<W_TYPE>& s_feature_PE256, hls::stream<W_TYPE>& s_feature_PE257,
    hls::stream<W_TYPE>& s_feature_PE258, hls::stream<W_TYPE>& s_feature_PE259,
    hls::stream<W_TYPE>& s_feature_PE260, hls::stream<W_TYPE>& s_feature_PE261,
    hls::stream<W_TYPE>& s_feature_PE262, hls::stream<W_TYPE>& s_feature_PE263,
    hls::stream<W_TYPE>& s_feature_PE264, hls::stream<W_TYPE>& s_feature_PE265,
    hls::stream<W_TYPE>& s_feature_PE266, hls::stream<W_TYPE>& s_feature_PE267,
    hls::stream<W_TYPE>& s_feature_PE268, hls::stream<W_TYPE>& s_feature_PE269,
    hls::stream<W_TYPE>& s_feature_PE270, hls::stream<W_TYPE>& s_feature_PE271,
    hls::stream<W_TYPE>& s_feature_PE272, hls::stream<W_TYPE>& s_feature_PE273,
    hls::stream<W_TYPE>& s_feature_PE274, hls::stream<W_TYPE>& s_feature_PE275,
    hls::stream<W_TYPE>& s_feature_PE276, hls::stream<W_TYPE>& s_feature_PE277,
    hls::stream<W_TYPE>& s_feature_PE278, hls::stream<W_TYPE>& s_feature_PE279,
    hls::stream<W_TYPE>& s_feature_PE280, hls::stream<W_TYPE>& s_feature_PE281,
    hls::stream<W_TYPE>& s_feature_PE282, hls::stream<W_TYPE>& s_feature_PE283,
    hls::stream<W_TYPE>& s_feature_PE284, hls::stream<W_TYPE>& s_feature_PE285,
    hls::stream<W_TYPE>& s_feature_PE286, hls::stream<W_TYPE>& s_feature_PE287,
    hls::stream<W_TYPE>& s_feature_PE288, hls::stream<W_TYPE>& s_feature_PE289,
    hls::stream<W_TYPE>& s_feature_PE290, hls::stream<W_TYPE>& s_feature_PE291,
    hls::stream<W_TYPE>& s_feature_PE292, hls::stream<W_TYPE>& s_feature_PE293,
    hls::stream<W_TYPE>& s_feature_PE294, hls::stream<W_TYPE>& s_feature_PE295,
    hls::stream<W_TYPE>& s_feature_PE296, hls::stream<W_TYPE>& s_feature_PE297,
    hls::stream<W_TYPE>& s_feature_PE298, hls::stream<W_TYPE>& s_feature_PE299,
    hls::stream<W_TYPE>& s_feature_PE300, hls::stream<W_TYPE>& s_feature_PE301,
    hls::stream<W_TYPE>& s_feature_PE302, hls::stream<W_TYPE>& s_feature_PE303,
    hls::stream<W_TYPE>& s_feature_PE304, hls::stream<W_TYPE>& s_feature_PE305,
    hls::stream<W_TYPE>& s_feature_PE306, hls::stream<W_TYPE>& s_feature_PE307,
    hls::stream<W_TYPE>& s_feature_PE308, hls::stream<W_TYPE>& s_feature_PE309,
    hls::stream<W_TYPE>& s_feature_PE310, hls::stream<W_TYPE>& s_feature_PE311
) {
     
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE * FEATURE_SIZE / INTS_PER_W; item++) {
        #pragma HLS pipeline II=1  // write 1 result_all per CC

        W_TYPE reg = s_feature_in.read();

        s_feature_PE0.write(reg);
        s_feature_PE1.write(reg);
        s_feature_PE2.write(reg);
        s_feature_PE3.write(reg);
        s_feature_PE4.write(reg);
        s_feature_PE5.write(reg);
        s_feature_PE6.write(reg);
        s_feature_PE7.write(reg);
        s_feature_PE8.write(reg);
        s_feature_PE9.write(reg);
        s_feature_PE10.write(reg);
        s_feature_PE11.write(reg);
        s_feature_PE12.write(reg);
        s_feature_PE13.write(reg);
        s_feature_PE14.write(reg);
        s_feature_PE15.write(reg);
        s_feature_PE16.write(reg);
        s_feature_PE17.write(reg);
        s_feature_PE18.write(reg);
        s_feature_PE19.write(reg);
        s_feature_PE20.write(reg);
        s_feature_PE21.write(reg);
        s_feature_PE22.write(reg);
        s_feature_PE23.write(reg);
        s_feature_PE24.write(reg);
        s_feature_PE25.write(reg);
        s_feature_PE26.write(reg);
        s_feature_PE27.write(reg);
        s_feature_PE28.write(reg);
        s_feature_PE29.write(reg);
        s_feature_PE30.write(reg);
        s_feature_PE31.write(reg);
        s_feature_PE32.write(reg);
        s_feature_PE33.write(reg);
        s_feature_PE34.write(reg);
        s_feature_PE35.write(reg);
        s_feature_PE36.write(reg);
        s_feature_PE37.write(reg);
        s_feature_PE38.write(reg);
        s_feature_PE39.write(reg);
        s_feature_PE40.write(reg);
        s_feature_PE41.write(reg);
        s_feature_PE42.write(reg);
        s_feature_PE43.write(reg);
        s_feature_PE44.write(reg);
        s_feature_PE45.write(reg);
        s_feature_PE46.write(reg);
        s_feature_PE47.write(reg);
        s_feature_PE48.write(reg);
        s_feature_PE49.write(reg);
        s_feature_PE50.write(reg);
        s_feature_PE51.write(reg);
        s_feature_PE52.write(reg);
        s_feature_PE53.write(reg);
        s_feature_PE54.write(reg);
        s_feature_PE55.write(reg);
        s_feature_PE56.write(reg);
        s_feature_PE57.write(reg);
        s_feature_PE58.write(reg);
        s_feature_PE59.write(reg);
        s_feature_PE60.write(reg);
        s_feature_PE61.write(reg);
        s_feature_PE62.write(reg);
        s_feature_PE63.write(reg);
        s_feature_PE64.write(reg);
        s_feature_PE65.write(reg);
        s_feature_PE66.write(reg);
        s_feature_PE67.write(reg);
        s_feature_PE68.write(reg);
        s_feature_PE69.write(reg);
        s_feature_PE70.write(reg);
        s_feature_PE71.write(reg);
        s_feature_PE72.write(reg);
        s_feature_PE73.write(reg);
        s_feature_PE74.write(reg);
        s_feature_PE75.write(reg);
        s_feature_PE76.write(reg);
        s_feature_PE77.write(reg);
        s_feature_PE78.write(reg);
        s_feature_PE79.write(reg);
        s_feature_PE80.write(reg);
        s_feature_PE81.write(reg);
        s_feature_PE82.write(reg);
        s_feature_PE83.write(reg);
        s_feature_PE84.write(reg);
        s_feature_PE85.write(reg);
        s_feature_PE86.write(reg);
        s_feature_PE87.write(reg);
        s_feature_PE88.write(reg);
        s_feature_PE89.write(reg);
        s_feature_PE90.write(reg);
        s_feature_PE91.write(reg);
        s_feature_PE92.write(reg);
        s_feature_PE93.write(reg);
        s_feature_PE94.write(reg);
        s_feature_PE95.write(reg);
        s_feature_PE96.write(reg);
        s_feature_PE97.write(reg);
        s_feature_PE98.write(reg);
        s_feature_PE99.write(reg);
        s_feature_PE100.write(reg);
        s_feature_PE101.write(reg);
        s_feature_PE102.write(reg);
        s_feature_PE103.write(reg);
        s_feature_PE104.write(reg);
        s_feature_PE105.write(reg);
        s_feature_PE106.write(reg);
        s_feature_PE107.write(reg);
        s_feature_PE108.write(reg);
        s_feature_PE109.write(reg);
        s_feature_PE110.write(reg);
        s_feature_PE111.write(reg);
        s_feature_PE112.write(reg);
        s_feature_PE113.write(reg);
        s_feature_PE114.write(reg);
        s_feature_PE115.write(reg);
        s_feature_PE116.write(reg);
        s_feature_PE117.write(reg);
        s_feature_PE118.write(reg);
        s_feature_PE119.write(reg);
        s_feature_PE120.write(reg);
        s_feature_PE121.write(reg);
        s_feature_PE122.write(reg);
        s_feature_PE123.write(reg);
        s_feature_PE124.write(reg);
        s_feature_PE125.write(reg);
        s_feature_PE126.write(reg);
        s_feature_PE127.write(reg);
        s_feature_PE128.write(reg);
        s_feature_PE129.write(reg);
        s_feature_PE130.write(reg);
        s_feature_PE131.write(reg);
        s_feature_PE132.write(reg);
        s_feature_PE133.write(reg);
        s_feature_PE134.write(reg);
        s_feature_PE135.write(reg);
        s_feature_PE136.write(reg);
        s_feature_PE137.write(reg);
        s_feature_PE138.write(reg);
        s_feature_PE139.write(reg);
        s_feature_PE140.write(reg);
        s_feature_PE141.write(reg);
        s_feature_PE142.write(reg);
        s_feature_PE143.write(reg);
        s_feature_PE144.write(reg);
        s_feature_PE145.write(reg);
        s_feature_PE146.write(reg);
        s_feature_PE147.write(reg);
        s_feature_PE148.write(reg);
        s_feature_PE149.write(reg);
        s_feature_PE150.write(reg);
        s_feature_PE151.write(reg);
        s_feature_PE152.write(reg);
        s_feature_PE153.write(reg);
        s_feature_PE154.write(reg);
        s_feature_PE155.write(reg);
        s_feature_PE156.write(reg);
        s_feature_PE157.write(reg);
        s_feature_PE158.write(reg);
        s_feature_PE159.write(reg);
        s_feature_PE160.write(reg);
        s_feature_PE161.write(reg);
        s_feature_PE162.write(reg);
        s_feature_PE163.write(reg);
        s_feature_PE164.write(reg);
        s_feature_PE165.write(reg);
        s_feature_PE166.write(reg);
        s_feature_PE167.write(reg);
        s_feature_PE168.write(reg);
        s_feature_PE169.write(reg);
        s_feature_PE170.write(reg);
        s_feature_PE171.write(reg);
        s_feature_PE172.write(reg);
        s_feature_PE173.write(reg);
        s_feature_PE174.write(reg);
        s_feature_PE175.write(reg);
        s_feature_PE176.write(reg);
        s_feature_PE177.write(reg);
        s_feature_PE178.write(reg);
        s_feature_PE179.write(reg);
        s_feature_PE180.write(reg);
        s_feature_PE181.write(reg);
        s_feature_PE182.write(reg);
        s_feature_PE183.write(reg);
        s_feature_PE184.write(reg);
        s_feature_PE185.write(reg);
        s_feature_PE186.write(reg);
        s_feature_PE187.write(reg);
        s_feature_PE188.write(reg);
        s_feature_PE189.write(reg);
        s_feature_PE190.write(reg);
        s_feature_PE191.write(reg);
        s_feature_PE192.write(reg);
        s_feature_PE193.write(reg);
        s_feature_PE194.write(reg);
        s_feature_PE195.write(reg);
        s_feature_PE196.write(reg);
        s_feature_PE197.write(reg);
        s_feature_PE198.write(reg);
        s_feature_PE199.write(reg);
        s_feature_PE200.write(reg);
        s_feature_PE201.write(reg);
        s_feature_PE202.write(reg);
        s_feature_PE203.write(reg);
        s_feature_PE204.write(reg);
        s_feature_PE205.write(reg);
        s_feature_PE206.write(reg);
        s_feature_PE207.write(reg);
        s_feature_PE208.write(reg);
        s_feature_PE209.write(reg);
        s_feature_PE210.write(reg);
        s_feature_PE211.write(reg);
        s_feature_PE212.write(reg);
        s_feature_PE213.write(reg);
        s_feature_PE214.write(reg);
        s_feature_PE215.write(reg);
        s_feature_PE216.write(reg);
        s_feature_PE217.write(reg);
        s_feature_PE218.write(reg);
        s_feature_PE219.write(reg);
        s_feature_PE220.write(reg);
        s_feature_PE221.write(reg);
        s_feature_PE222.write(reg);
        s_feature_PE223.write(reg);
        s_feature_PE224.write(reg);
        s_feature_PE225.write(reg);
        s_feature_PE226.write(reg);
        s_feature_PE227.write(reg);
        s_feature_PE228.write(reg);
        s_feature_PE229.write(reg);
        s_feature_PE230.write(reg);
        s_feature_PE231.write(reg);
        s_feature_PE232.write(reg);
        s_feature_PE233.write(reg);
        s_feature_PE234.write(reg);
        s_feature_PE235.write(reg);
        s_feature_PE236.write(reg);
        s_feature_PE237.write(reg);
        s_feature_PE238.write(reg);
        s_feature_PE239.write(reg);
        s_feature_PE240.write(reg);
        s_feature_PE241.write(reg);
        s_feature_PE242.write(reg);
        s_feature_PE243.write(reg);
        s_feature_PE244.write(reg);
        s_feature_PE245.write(reg);
        s_feature_PE246.write(reg);
        s_feature_PE247.write(reg);
        s_feature_PE248.write(reg);
        s_feature_PE249.write(reg);
        s_feature_PE250.write(reg);
        s_feature_PE251.write(reg);
        s_feature_PE252.write(reg);
        s_feature_PE253.write(reg);
        s_feature_PE254.write(reg);
        s_feature_PE255.write(reg);
        s_feature_PE256.write(reg);
        s_feature_PE257.write(reg);
        s_feature_PE258.write(reg);
        s_feature_PE259.write(reg);
        s_feature_PE260.write(reg);
        s_feature_PE261.write(reg);
        s_feature_PE262.write(reg);
        s_feature_PE263.write(reg);
        s_feature_PE264.write(reg);
        s_feature_PE265.write(reg);
        s_feature_PE266.write(reg);
        s_feature_PE267.write(reg);
        s_feature_PE268.write(reg);
        s_feature_PE269.write(reg);
        s_feature_PE270.write(reg);
        s_feature_PE271.write(reg);
        s_feature_PE272.write(reg);
        s_feature_PE273.write(reg);
        s_feature_PE274.write(reg);
        s_feature_PE275.write(reg);
        s_feature_PE276.write(reg);
        s_feature_PE277.write(reg);
        s_feature_PE278.write(reg);
        s_feature_PE279.write(reg);
        s_feature_PE280.write(reg);
        s_feature_PE281.write(reg);
        s_feature_PE282.write(reg);
        s_feature_PE283.write(reg);
        s_feature_PE284.write(reg);
        s_feature_PE285.write(reg);
        s_feature_PE286.write(reg);
        s_feature_PE287.write(reg);
        s_feature_PE288.write(reg);
        s_feature_PE289.write(reg);
        s_feature_PE290.write(reg);
        s_feature_PE291.write(reg);
        s_feature_PE292.write(reg);
        s_feature_PE293.write(reg);
        s_feature_PE294.write(reg);
        s_feature_PE295.write(reg);
        s_feature_PE296.write(reg);
        s_feature_PE297.write(reg);
        s_feature_PE298.write(reg);
        s_feature_PE299.write(reg);
        s_feature_PE300.write(reg);
        s_feature_PE301.write(reg);
        s_feature_PE302.write(reg);
        s_feature_PE303.write(reg);
        s_feature_PE304.write(reg);
        s_feature_PE305.write(reg);
        s_feature_PE306.write(reg);
        s_feature_PE307.write(reg);
        s_feature_PE308.write(reg);
        s_feature_PE309.write(reg);
        s_feature_PE310.write(reg);
        s_feature_PE311.write(reg);
    }
}

template<const int ROW_PER_PE>
void gather_results_512PEs_312PE(
    hls::stream<W_TYPE>& s_result1_node1,
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
    hls::stream<W_TYPE>& s_result_all
){
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++){
        #pragma HLS pipeline II=1
        W_TYPE reg0, reg1, reg2, reg3, reg4, reg5, reg6, reg7,
            reg8, reg9, reg10, reg11, reg12, reg13, reg14, reg15,
            reg16, reg17, reg18, reg19, reg20, reg21, reg22, reg23,
            reg24, reg25, reg26, reg27, reg28, reg29, reg30, reg31,
            reg32, reg33, reg34, reg35, reg36, reg37, reg38, reg39,
            reg40, reg41, reg42, reg43, reg44, reg45, reg46, reg47,
            reg48, reg49, reg50, reg51, reg52, reg53, reg54, reg55,
            reg56, reg57, reg58, reg59, reg60, reg61, reg62, reg63,
            reg64, reg65, reg66, reg67, reg68, reg69, reg70, reg71,
            reg72, reg73, reg74, reg75, reg76, reg77, reg78, reg79,
            reg80, reg81, reg82, reg83, reg84, reg85, reg86, reg87,
            reg88, reg89, reg90, reg91, reg92, reg93, reg94, reg95,
            reg96, reg97, reg98, reg99, reg100, reg101, reg102, reg103,
            reg104, reg105, reg106, reg107, reg108, reg109, reg110, reg111,
            reg112, reg113, reg114, reg115, reg116, reg117, reg118, reg119,
            reg120, reg121, reg122, reg123, reg124, reg125, reg126, reg127,
            reg128, reg129, reg130, reg131, reg132, reg133, reg134, reg135,
            reg136, reg137, reg138, reg139, reg140, reg141, reg142, reg143,
            reg144, reg145, reg146, reg147, reg148, reg149, reg150, reg151,
            reg152, reg153, reg154, reg155, reg156, reg157, reg158, reg159,
            reg160, reg161, reg162, reg163, reg164, reg165, reg166, reg167,
            reg168, reg169, reg170, reg171, reg172, reg173, reg174, reg175,
            reg176, reg177, reg178, reg179, reg180, reg181, reg182, reg183,
            reg184, reg185, reg186, reg187, reg188, reg189, reg190, reg191,
            reg192, reg193, reg194, reg195, reg196, reg197, reg198, reg199,
            reg200, reg201, reg202, reg203, reg204, reg205, reg206, reg207,
            reg208, reg209, reg210, reg211, reg212, reg213, reg214, reg215,
            reg216, reg217, reg218, reg219, reg220, reg221, reg222, reg223,
            reg224, reg225, reg226, reg227, reg228, reg229, reg230, reg231,
            reg232, reg233, reg234, reg235, reg236, reg237, reg238, reg239,
            reg240, reg241, reg242, reg243, reg244, reg245, reg246, reg247,
            reg248, reg249, reg250, reg251, reg252, reg253, reg254, reg255;

        // top 100 reg for s_result1_node1
        // last 78 reg for s_result_PE
        reg0 = s_result1_node1.read();
        s_result_all.write(reg0);

        reg1 = s_result1_node1.read();
        s_result_all.write(reg1);

        reg2 = s_result1_node1.read();
        s_result_all.write(reg2);

        reg3 = s_result1_node1.read();
        s_result_all.write(reg3);

        reg4 = s_result1_node1.read();
        s_result_all.write(reg4);

        reg5 = s_result1_node1.read();
        s_result_all.write(reg5);

        reg6 = s_result1_node1.read();
        s_result_all.write(reg6);

        reg7 = s_result1_node1.read();
        s_result_all.write(reg7);

        reg8 = s_result1_node1.read();
        s_result_all.write(reg8);

        reg9 = s_result1_node1.read();
        s_result_all.write(reg9);

        reg10 = s_result1_node1.read();
        s_result_all.write(reg10);

        reg11 = s_result1_node1.read();
        s_result_all.write(reg11);

        reg12 = s_result1_node1.read();
        s_result_all.write(reg12);

        reg13 = s_result1_node1.read();
        s_result_all.write(reg13);

        reg14 = s_result1_node1.read();
        s_result_all.write(reg14);

        reg15 = s_result1_node1.read();
        s_result_all.write(reg15);

        reg16 = s_result1_node1.read();
        s_result_all.write(reg16);

        reg17 = s_result1_node1.read();
        s_result_all.write(reg17);

        reg18 = s_result1_node1.read();
        s_result_all.write(reg18);

        reg19 = s_result1_node1.read();
        s_result_all.write(reg19);

        reg20 = s_result1_node1.read();
        s_result_all.write(reg20);

        reg21 = s_result1_node1.read();
        s_result_all.write(reg21);

        reg22 = s_result1_node1.read();
        s_result_all.write(reg22);

        reg23 = s_result1_node1.read();
        s_result_all.write(reg23);

        reg24 = s_result1_node1.read();
        s_result_all.write(reg24);

        reg25 = s_result1_node1.read();
        s_result_all.write(reg25);

        reg26 = s_result1_node1.read();
        s_result_all.write(reg26);

        reg27 = s_result1_node1.read();
        s_result_all.write(reg27);

        reg28 = s_result1_node1.read();
        s_result_all.write(reg28);

        reg29 = s_result1_node1.read();
        s_result_all.write(reg29);

        reg30 = s_result1_node1.read();
        s_result_all.write(reg30);

        reg31 = s_result1_node1.read();
        s_result_all.write(reg31);

        reg32 = s_result1_node1.read();
        s_result_all.write(reg32);

        reg33 = s_result1_node1.read();
        s_result_all.write(reg33);

        reg34 = s_result1_node1.read();
        s_result_all.write(reg34);

        reg35 = s_result1_node1.read();
        s_result_all.write(reg35);

        reg36 = s_result1_node1.read();
        s_result_all.write(reg36);

        reg37 = s_result1_node1.read();
        s_result_all.write(reg37);

        reg38 = s_result1_node1.read();
        s_result_all.write(reg38);

        reg39 = s_result1_node1.read();
        s_result_all.write(reg39);

        reg40 = s_result1_node1.read();
        s_result_all.write(reg40);

        reg41 = s_result1_node1.read();
        s_result_all.write(reg41);

        reg42 = s_result1_node1.read();
        s_result_all.write(reg42);

        reg43 = s_result1_node1.read();
        s_result_all.write(reg43);

        reg44 = s_result1_node1.read();
        s_result_all.write(reg44);

        reg45 = s_result1_node1.read();
        s_result_all.write(reg45);

        reg46 = s_result1_node1.read();
        s_result_all.write(reg46);

        reg47 = s_result1_node1.read();
        s_result_all.write(reg47);

        reg48 = s_result1_node1.read();
        s_result_all.write(reg48);

        reg49 = s_result1_node1.read();
        s_result_all.write(reg49);

        reg50 = s_result1_node1.read();
        s_result_all.write(reg50);

        reg51 = s_result1_node1.read();
        s_result_all.write(reg51);

        reg52 = s_result1_node1.read();
        s_result_all.write(reg52);

        reg53 = s_result1_node1.read();
        s_result_all.write(reg53);

        reg54 = s_result1_node1.read();
        s_result_all.write(reg54);

        reg55 = s_result1_node1.read();
        s_result_all.write(reg55);

        reg56 = s_result1_node1.read();
        s_result_all.write(reg56);

        reg57 = s_result1_node1.read();
        s_result_all.write(reg57);

        reg58 = s_result1_node1.read();
        s_result_all.write(reg58);

        reg59 = s_result1_node1.read();
        s_result_all.write(reg59);

        reg60 = s_result1_node1.read();
        s_result_all.write(reg60);

        reg61 = s_result1_node1.read();
        s_result_all.write(reg61);

        reg62 = s_result1_node1.read();
        s_result_all.write(reg62);

        reg63 = s_result1_node1.read();
        s_result_all.write(reg63);

        reg64 = s_result1_node1.read();
        s_result_all.write(reg64);

        reg65 = s_result1_node1.read();
        s_result_all.write(reg65);

        reg66 = s_result1_node1.read();
        s_result_all.write(reg66);

        reg67 = s_result1_node1.read();
        s_result_all.write(reg67);

        reg68 = s_result1_node1.read();
        s_result_all.write(reg68);

        reg69 = s_result1_node1.read();
        s_result_all.write(reg69);

        reg70 = s_result1_node1.read();
        s_result_all.write(reg70);

        reg71 = s_result1_node1.read();
        s_result_all.write(reg71);

        reg72 = s_result1_node1.read();
        s_result_all.write(reg72);

        reg73 = s_result1_node1.read();
        s_result_all.write(reg73);

        reg74 = s_result1_node1.read();
        s_result_all.write(reg74);

        reg75 = s_result1_node1.read();
        s_result_all.write(reg75);

        reg76 = s_result1_node1.read();
        s_result_all.write(reg76);

        reg77 = s_result1_node1.read();
        s_result_all.write(reg77);

        reg78 = s_result1_node1.read();
        s_result_all.write(reg78);

        reg79 = s_result1_node1.read();
        s_result_all.write(reg79);

        reg80 = s_result1_node1.read();
        s_result_all.write(reg80);

        reg81 = s_result1_node1.read();
        s_result_all.write(reg81);

        reg82 = s_result1_node1.read();
        s_result_all.write(reg82);

        reg83 = s_result1_node1.read();
        s_result_all.write(reg83);

        reg84 = s_result1_node1.read();
        s_result_all.write(reg84);

        reg85 = s_result1_node1.read();
        s_result_all.write(reg85);

        reg86 = s_result1_node1.read();
        s_result_all.write(reg86);

        reg87 = s_result1_node1.read();
        s_result_all.write(reg87);

        reg88 = s_result1_node1.read();
        s_result_all.write(reg88);

        reg89 = s_result1_node1.read();
        s_result_all.write(reg89);

        reg90 = s_result1_node1.read();
        s_result_all.write(reg90);

        reg91 = s_result1_node1.read();
        s_result_all.write(reg91);

        reg92 = s_result1_node1.read();
        s_result_all.write(reg92);

        reg93 = s_result1_node1.read();
        s_result_all.write(reg93);

        reg94 = s_result1_node1.read();
        s_result_all.write(reg94);

        reg95 = s_result1_node1.read();
        s_result_all.write(reg95);

        reg96 = s_result1_node1.read();
        s_result_all.write(reg96);

        reg97 = s_result1_node1.read();
        s_result_all.write(reg97);

        reg98 = s_result1_node1.read();
        s_result_all.write(reg98);

        reg99 = s_result1_node1.read();
        s_result_all.write(reg99);

        reg100.range(31, 0) = s_result_PE0.read() + 1;
        reg100.range(63, 32) = s_result_PE0.read() + 1;
        reg100.range(95, 64) = s_result_PE1.read() + 1;
        reg100.range(127, 96) = s_result_PE1.read() + 1;
        s_result_all.write(reg100);

        reg101.range(31, 0) = s_result_PE2.read() + 1;
        reg101.range(63, 32) = s_result_PE2.read() + 1;
        reg101.range(95, 64) = s_result_PE3.read() + 1;
        reg101.range(127, 96) = s_result_PE3.read() + 1;
        s_result_all.write(reg101);

        reg102.range(31, 0) = s_result_PE4.read() + 1;
        reg102.range(63, 32) = s_result_PE4.read() + 1;
        reg102.range(95, 64) = s_result_PE5.read() + 1;
        reg102.range(127, 96) = s_result_PE5.read() + 1;
        s_result_all.write(reg102);

        reg103.range(31, 0) = s_result_PE6.read() + 1;
        reg103.range(63, 32) = s_result_PE6.read() + 1;
        reg103.range(95, 64) = s_result_PE7.read() + 1;
        reg103.range(127, 96) = s_result_PE7.read() + 1;
        s_result_all.write(reg103);

        reg104.range(31, 0) = s_result_PE8.read() + 1;
        reg104.range(63, 32) = s_result_PE8.read() + 1;
        reg104.range(95, 64) = s_result_PE9.read() + 1;
        reg104.range(127, 96) = s_result_PE9.read() + 1;
        s_result_all.write(reg104);

        reg105.range(31, 0) = s_result_PE10.read() + 1;
        reg105.range(63, 32) = s_result_PE10.read() + 1;
        reg105.range(95, 64) = s_result_PE11.read() + 1;
        reg105.range(127, 96) = s_result_PE11.read() + 1;
        s_result_all.write(reg105);

        reg106.range(31, 0) = s_result_PE12.read() + 1;
        reg106.range(63, 32) = s_result_PE12.read() + 1;
        reg106.range(95, 64) = s_result_PE13.read() + 1;
        reg106.range(127, 96) = s_result_PE13.read() + 1;
        s_result_all.write(reg106);

        reg107.range(31, 0) = s_result_PE14.read() + 1;
        reg107.range(63, 32) = s_result_PE14.read() + 1;
        reg107.range(95, 64) = s_result_PE15.read() + 1;
        reg107.range(127, 96) = s_result_PE15.read() + 1;
        s_result_all.write(reg107);

        reg108.range(31, 0) = s_result_PE16.read() + 1;
        reg108.range(63, 32) = s_result_PE16.read() + 1;
        reg108.range(95, 64) = s_result_PE17.read() + 1;
        reg108.range(127, 96) = s_result_PE17.read() + 1;
        s_result_all.write(reg108);

        reg109.range(31, 0) = s_result_PE18.read() + 1;
        reg109.range(63, 32) = s_result_PE18.read() + 1;
        reg109.range(95, 64) = s_result_PE19.read() + 1;
        reg109.range(127, 96) = s_result_PE19.read() + 1;
        s_result_all.write(reg109);

        reg110.range(31, 0) = s_result_PE20.read() + 1;
        reg110.range(63, 32) = s_result_PE20.read() + 1;
        reg110.range(95, 64) = s_result_PE21.read() + 1;
        reg110.range(127, 96) = s_result_PE21.read() + 1;
        s_result_all.write(reg110);

        reg111.range(31, 0) = s_result_PE22.read() + 1;
        reg111.range(63, 32) = s_result_PE22.read() + 1;
        reg111.range(95, 64) = s_result_PE23.read() + 1;
        reg111.range(127, 96) = s_result_PE23.read() + 1;
        s_result_all.write(reg111);

        reg112.range(31, 0) = s_result_PE24.read() + 1;
        reg112.range(63, 32) = s_result_PE24.read() + 1;
        reg112.range(95, 64) = s_result_PE25.read() + 1;
        reg112.range(127, 96) = s_result_PE25.read() + 1;
        s_result_all.write(reg112);

        reg113.range(31, 0) = s_result_PE26.read() + 1;
        reg113.range(63, 32) = s_result_PE26.read() + 1;
        reg113.range(95, 64) = s_result_PE27.read() + 1;
        reg113.range(127, 96) = s_result_PE27.read() + 1;
        s_result_all.write(reg113);

        reg114.range(31, 0) = s_result_PE28.read() + 1;
        reg114.range(63, 32) = s_result_PE28.read() + 1;
        reg114.range(95, 64) = s_result_PE29.read() + 1;
        reg114.range(127, 96) = s_result_PE29.read() + 1;
        s_result_all.write(reg114);

        reg115.range(31, 0) = s_result_PE30.read() + 1;
        reg115.range(63, 32) = s_result_PE30.read() + 1;
        reg115.range(95, 64) = s_result_PE31.read() + 1;
        reg115.range(127, 96) = s_result_PE31.read() + 1;
        s_result_all.write(reg115);

        reg116.range(31, 0) = s_result_PE32.read() + 1;
        reg116.range(63, 32) = s_result_PE32.read() + 1;
        reg116.range(95, 64) = s_result_PE33.read() + 1;
        reg116.range(127, 96) = s_result_PE33.read() + 1;
        s_result_all.write(reg116);

        reg117.range(31, 0) = s_result_PE34.read() + 1;
        reg117.range(63, 32) = s_result_PE34.read() + 1;
        reg117.range(95, 64) = s_result_PE35.read() + 1;
        reg117.range(127, 96) = s_result_PE35.read() + 1;
        s_result_all.write(reg117);

        reg118.range(31, 0) = s_result_PE36.read() + 1;
        reg118.range(63, 32) = s_result_PE36.read() + 1;
        reg118.range(95, 64) = s_result_PE37.read() + 1;
        reg118.range(127, 96) = s_result_PE37.read() + 1;
        s_result_all.write(reg118);

        reg119.range(31, 0) = s_result_PE38.read() + 1;
        reg119.range(63, 32) = s_result_PE38.read() + 1;
        reg119.range(95, 64) = s_result_PE39.read() + 1;
        reg119.range(127, 96) = s_result_PE39.read() + 1;
        s_result_all.write(reg119);

        reg120.range(31, 0) = s_result_PE40.read() + 1;
        reg120.range(63, 32) = s_result_PE40.read() + 1;
        reg120.range(95, 64) = s_result_PE41.read() + 1;
        reg120.range(127, 96) = s_result_PE41.read() + 1;
        s_result_all.write(reg120);

        reg121.range(31, 0) = s_result_PE42.read() + 1;
        reg121.range(63, 32) = s_result_PE42.read() + 1;
        reg121.range(95, 64) = s_result_PE43.read() + 1;
        reg121.range(127, 96) = s_result_PE43.read() + 1;
        s_result_all.write(reg121);

        reg122.range(31, 0) = s_result_PE44.read() + 1;
        reg122.range(63, 32) = s_result_PE44.read() + 1;
        reg122.range(95, 64) = s_result_PE45.read() + 1;
        reg122.range(127, 96) = s_result_PE45.read() + 1;
        s_result_all.write(reg122);

        reg123.range(31, 0) = s_result_PE46.read() + 1;
        reg123.range(63, 32) = s_result_PE46.read() + 1;
        reg123.range(95, 64) = s_result_PE47.read() + 1;
        reg123.range(127, 96) = s_result_PE47.read() + 1;
        s_result_all.write(reg123);

        reg124.range(31, 0) = s_result_PE48.read() + 1;
        reg124.range(63, 32) = s_result_PE48.read() + 1;
        reg124.range(95, 64) = s_result_PE49.read() + 1;
        reg124.range(127, 96) = s_result_PE49.read() + 1;
        s_result_all.write(reg124);

        reg125.range(31, 0) = s_result_PE50.read() + 1;
        reg125.range(63, 32) = s_result_PE50.read() + 1;
        reg125.range(95, 64) = s_result_PE51.read() + 1;
        reg125.range(127, 96) = s_result_PE51.read() + 1;
        s_result_all.write(reg125);

        reg126.range(31, 0) = s_result_PE52.read() + 1;
        reg126.range(63, 32) = s_result_PE52.read() + 1;
        reg126.range(95, 64) = s_result_PE53.read() + 1;
        reg126.range(127, 96) = s_result_PE53.read() + 1;
        s_result_all.write(reg126);

        reg127.range(31, 0) = s_result_PE54.read() + 1;
        reg127.range(63, 32) = s_result_PE54.read() + 1;
        reg127.range(95, 64) = s_result_PE55.read() + 1;
        reg127.range(127, 96) = s_result_PE55.read() + 1;
        s_result_all.write(reg127);

        reg128.range(31, 0) = s_result_PE56.read() + 1;
        reg128.range(63, 32) = s_result_PE56.read() + 1;
        reg128.range(95, 64) = s_result_PE57.read() + 1;
        reg128.range(127, 96) = s_result_PE57.read() + 1;
        s_result_all.write(reg128);

        reg129.range(31, 0) = s_result_PE58.read() + 1;
        reg129.range(63, 32) = s_result_PE58.read() + 1;
        reg129.range(95, 64) = s_result_PE59.read() + 1;
        reg129.range(127, 96) = s_result_PE59.read() + 1;
        s_result_all.write(reg129);

        reg130.range(31, 0) = s_result_PE60.read() + 1;
        reg130.range(63, 32) = s_result_PE60.read() + 1;
        reg130.range(95, 64) = s_result_PE61.read() + 1;
        reg130.range(127, 96) = s_result_PE61.read() + 1;
        s_result_all.write(reg130);

        reg131.range(31, 0) = s_result_PE62.read() + 1;
        reg131.range(63, 32) = s_result_PE62.read() + 1;
        reg131.range(95, 64) = s_result_PE63.read() + 1;
        reg131.range(127, 96) = s_result_PE63.read() + 1;
        s_result_all.write(reg131);

        reg132.range(31, 0) = s_result_PE64.read() + 1;
        reg132.range(63, 32) = s_result_PE64.read() + 1;
        reg132.range(95, 64) = s_result_PE65.read() + 1;
        reg132.range(127, 96) = s_result_PE65.read() + 1;
        s_result_all.write(reg132);

        reg133.range(31, 0) = s_result_PE66.read() + 1;
        reg133.range(63, 32) = s_result_PE66.read() + 1;
        reg133.range(95, 64) = s_result_PE67.read() + 1;
        reg133.range(127, 96) = s_result_PE67.read() + 1;
        s_result_all.write(reg133);

        reg134.range(31, 0) = s_result_PE68.read() + 1;
        reg134.range(63, 32) = s_result_PE68.read() + 1;
        reg134.range(95, 64) = s_result_PE69.read() + 1;
        reg134.range(127, 96) = s_result_PE69.read() + 1;
        s_result_all.write(reg134);

        reg135.range(31, 0) = s_result_PE70.read() + 1;
        reg135.range(63, 32) = s_result_PE70.read() + 1;
        reg135.range(95, 64) = s_result_PE71.read() + 1;
        reg135.range(127, 96) = s_result_PE71.read() + 1;
        s_result_all.write(reg135);

        reg136.range(31, 0) = s_result_PE72.read() + 1;
        reg136.range(63, 32) = s_result_PE72.read() + 1;
        reg136.range(95, 64) = s_result_PE73.read() + 1;
        reg136.range(127, 96) = s_result_PE73.read() + 1;
        s_result_all.write(reg136);

        reg137.range(31, 0) = s_result_PE74.read() + 1;
        reg137.range(63, 32) = s_result_PE74.read() + 1;
        reg137.range(95, 64) = s_result_PE75.read() + 1;
        reg137.range(127, 96) = s_result_PE75.read() + 1;
        s_result_all.write(reg137);

        reg138.range(31, 0) = s_result_PE76.read() + 1;
        reg138.range(63, 32) = s_result_PE76.read() + 1;
        reg138.range(95, 64) = s_result_PE77.read() + 1;
        reg138.range(127, 96) = s_result_PE77.read() + 1;
        s_result_all.write(reg138);

        reg139.range(31, 0) = s_result_PE78.read() + 1;
        reg139.range(63, 32) = s_result_PE78.read() + 1;
        reg139.range(95, 64) = s_result_PE79.read() + 1;
        reg139.range(127, 96) = s_result_PE79.read() + 1;
        s_result_all.write(reg139);

        reg140.range(31, 0) = s_result_PE80.read() + 1;
        reg140.range(63, 32) = s_result_PE80.read() + 1;
        reg140.range(95, 64) = s_result_PE81.read() + 1;
        reg140.range(127, 96) = s_result_PE81.read() + 1;
        s_result_all.write(reg140);

        reg141.range(31, 0) = s_result_PE82.read() + 1;
        reg141.range(63, 32) = s_result_PE82.read() + 1;
        reg141.range(95, 64) = s_result_PE83.read() + 1;
        reg141.range(127, 96) = s_result_PE83.read() + 1;
        s_result_all.write(reg141);

        reg142.range(31, 0) = s_result_PE84.read() + 1;
        reg142.range(63, 32) = s_result_PE84.read() + 1;
        reg142.range(95, 64) = s_result_PE85.read() + 1;
        reg142.range(127, 96) = s_result_PE85.read() + 1;
        s_result_all.write(reg142);

        reg143.range(31, 0) = s_result_PE86.read() + 1;
        reg143.range(63, 32) = s_result_PE86.read() + 1;
        reg143.range(95, 64) = s_result_PE87.read() + 1;
        reg143.range(127, 96) = s_result_PE87.read() + 1;
        s_result_all.write(reg143);

        reg144.range(31, 0) = s_result_PE88.read() + 1;
        reg144.range(63, 32) = s_result_PE88.read() + 1;
        reg144.range(95, 64) = s_result_PE89.read() + 1;
        reg144.range(127, 96) = s_result_PE89.read() + 1;
        s_result_all.write(reg144);

        reg145.range(31, 0) = s_result_PE90.read() + 1;
        reg145.range(63, 32) = s_result_PE90.read() + 1;
        reg145.range(95, 64) = s_result_PE91.read() + 1;
        reg145.range(127, 96) = s_result_PE91.read() + 1;
        s_result_all.write(reg145);

        reg146.range(31, 0) = s_result_PE92.read() + 1;
        reg146.range(63, 32) = s_result_PE92.read() + 1;
        reg146.range(95, 64) = s_result_PE93.read() + 1;
        reg146.range(127, 96) = s_result_PE93.read() + 1;
        s_result_all.write(reg146);

        reg147.range(31, 0) = s_result_PE94.read() + 1;
        reg147.range(63, 32) = s_result_PE94.read() + 1;
        reg147.range(95, 64) = s_result_PE95.read() + 1;
        reg147.range(127, 96) = s_result_PE95.read() + 1;
        s_result_all.write(reg147);

        reg148.range(31, 0) = s_result_PE96.read() + 1;
        reg148.range(63, 32) = s_result_PE96.read() + 1;
        reg148.range(95, 64) = s_result_PE97.read() + 1;
        reg148.range(127, 96) = s_result_PE97.read() + 1;
        s_result_all.write(reg148);

        reg149.range(31, 0) = s_result_PE98.read() + 1;
        reg149.range(63, 32) = s_result_PE98.read() + 1;
        reg149.range(95, 64) = s_result_PE99.read() + 1;
        reg149.range(127, 96) = s_result_PE99.read() + 1;
        s_result_all.write(reg149);

        reg150.range(31, 0) = s_result_PE100.read() + 1;
        reg150.range(63, 32) = s_result_PE100.read() + 1;
        reg150.range(95, 64) = s_result_PE101.read() + 1;
        reg150.range(127, 96) = s_result_PE101.read() + 1;
        s_result_all.write(reg150);

        reg151.range(31, 0) = s_result_PE102.read() + 1;
        reg151.range(63, 32) = s_result_PE102.read() + 1;
        reg151.range(95, 64) = s_result_PE103.read() + 1;
        reg151.range(127, 96) = s_result_PE103.read() + 1;
        s_result_all.write(reg151);

        reg152.range(31, 0) = s_result_PE104.read() + 1;
        reg152.range(63, 32) = s_result_PE104.read() + 1;
        reg152.range(95, 64) = s_result_PE105.read() + 1;
        reg152.range(127, 96) = s_result_PE105.read() + 1;
        s_result_all.write(reg152);

        reg153.range(31, 0) = s_result_PE106.read() + 1;
        reg153.range(63, 32) = s_result_PE106.read() + 1;
        reg153.range(95, 64) = s_result_PE107.read() + 1;
        reg153.range(127, 96) = s_result_PE107.read() + 1;
        s_result_all.write(reg153);

        reg154.range(31, 0) = s_result_PE108.read() + 1;
        reg154.range(63, 32) = s_result_PE108.read() + 1;
        reg154.range(95, 64) = s_result_PE109.read() + 1;
        reg154.range(127, 96) = s_result_PE109.read() + 1;
        s_result_all.write(reg154);

        reg155.range(31, 0) = s_result_PE110.read() + 1;
        reg155.range(63, 32) = s_result_PE110.read() + 1;
        reg155.range(95, 64) = s_result_PE111.read() + 1;
        reg155.range(127, 96) = s_result_PE111.read() + 1;
        s_result_all.write(reg155);

        reg156.range(31, 0) = s_result_PE112.read() + 1;
        reg156.range(63, 32) = s_result_PE112.read() + 1;
        reg156.range(95, 64) = s_result_PE113.read() + 1;
        reg156.range(127, 96) = s_result_PE113.read() + 1;
        s_result_all.write(reg156);

        reg157.range(31, 0) = s_result_PE114.read() + 1;
        reg157.range(63, 32) = s_result_PE114.read() + 1;
        reg157.range(95, 64) = s_result_PE115.read() + 1;
        reg157.range(127, 96) = s_result_PE115.read() + 1;
        s_result_all.write(reg157);

        reg158.range(31, 0) = s_result_PE116.read() + 1;
        reg158.range(63, 32) = s_result_PE116.read() + 1;
        reg158.range(95, 64) = s_result_PE117.read() + 1;
        reg158.range(127, 96) = s_result_PE117.read() + 1;
        s_result_all.write(reg158);

        reg159.range(31, 0) = s_result_PE118.read() + 1;
        reg159.range(63, 32) = s_result_PE118.read() + 1;
        reg159.range(95, 64) = s_result_PE119.read() + 1;
        reg159.range(127, 96) = s_result_PE119.read() + 1;
        s_result_all.write(reg159);

        reg160.range(31, 0) = s_result_PE120.read() + 1;
        reg160.range(63, 32) = s_result_PE120.read() + 1;
        reg160.range(95, 64) = s_result_PE121.read() + 1;
        reg160.range(127, 96) = s_result_PE121.read() + 1;
        s_result_all.write(reg160);

        reg161.range(31, 0) = s_result_PE122.read() + 1;
        reg161.range(63, 32) = s_result_PE122.read() + 1;
        reg161.range(95, 64) = s_result_PE123.read() + 1;
        reg161.range(127, 96) = s_result_PE123.read() + 1;
        s_result_all.write(reg161);

        reg162.range(31, 0) = s_result_PE124.read() + 1;
        reg162.range(63, 32) = s_result_PE124.read() + 1;
        reg162.range(95, 64) = s_result_PE125.read() + 1;
        reg162.range(127, 96) = s_result_PE125.read() + 1;
        s_result_all.write(reg162);

        reg163.range(31, 0) = s_result_PE126.read() + 1;
        reg163.range(63, 32) = s_result_PE126.read() + 1;
        reg163.range(95, 64) = s_result_PE127.read() + 1;
        reg163.range(127, 96) = s_result_PE127.read() + 1;
        s_result_all.write(reg163);

        reg164.range(31, 0) = s_result_PE128.read() + 1;
        reg164.range(63, 32) = s_result_PE128.read() + 1;
        reg164.range(95, 64) = s_result_PE129.read() + 1;
        reg164.range(127, 96) = s_result_PE129.read() + 1;
        s_result_all.write(reg164);

        reg165.range(31, 0) = s_result_PE130.read() + 1;
        reg165.range(63, 32) = s_result_PE130.read() + 1;
        reg165.range(95, 64) = s_result_PE131.read() + 1;
        reg165.range(127, 96) = s_result_PE131.read() + 1;
        s_result_all.write(reg165);

        reg166.range(31, 0) = s_result_PE132.read() + 1;
        reg166.range(63, 32) = s_result_PE132.read() + 1;
        reg166.range(95, 64) = s_result_PE133.read() + 1;
        reg166.range(127, 96) = s_result_PE133.read() + 1;
        s_result_all.write(reg166);

        reg167.range(31, 0) = s_result_PE134.read() + 1;
        reg167.range(63, 32) = s_result_PE134.read() + 1;
        reg167.range(95, 64) = s_result_PE135.read() + 1;
        reg167.range(127, 96) = s_result_PE135.read() + 1;
        s_result_all.write(reg167);

        reg168.range(31, 0) = s_result_PE136.read() + 1;
        reg168.range(63, 32) = s_result_PE136.read() + 1;
        reg168.range(95, 64) = s_result_PE137.read() + 1;
        reg168.range(127, 96) = s_result_PE137.read() + 1;
        s_result_all.write(reg168);

        reg169.range(31, 0) = s_result_PE138.read() + 1;
        reg169.range(63, 32) = s_result_PE138.read() + 1;
        reg169.range(95, 64) = s_result_PE139.read() + 1;
        reg169.range(127, 96) = s_result_PE139.read() + 1;
        s_result_all.write(reg169);

        reg170.range(31, 0) = s_result_PE140.read() + 1;
        reg170.range(63, 32) = s_result_PE140.read() + 1;
        reg170.range(95, 64) = s_result_PE141.read() + 1;
        reg170.range(127, 96) = s_result_PE141.read() + 1;
        s_result_all.write(reg170);

        reg171.range(31, 0) = s_result_PE142.read() + 1;
        reg171.range(63, 32) = s_result_PE142.read() + 1;
        reg171.range(95, 64) = s_result_PE143.read() + 1;
        reg171.range(127, 96) = s_result_PE143.read() + 1;
        s_result_all.write(reg171);

        reg172.range(31, 0) = s_result_PE144.read() + 1;
        reg172.range(63, 32) = s_result_PE144.read() + 1;
        reg172.range(95, 64) = s_result_PE145.read() + 1;
        reg172.range(127, 96) = s_result_PE145.read() + 1;
        s_result_all.write(reg172);

        reg173.range(31, 0) = s_result_PE146.read() + 1;
        reg173.range(63, 32) = s_result_PE146.read() + 1;
        reg173.range(95, 64) = s_result_PE147.read() + 1;
        reg173.range(127, 96) = s_result_PE147.read() + 1;
        s_result_all.write(reg173);

        reg174.range(31, 0) = s_result_PE148.read() + 1;
        reg174.range(63, 32) = s_result_PE148.read() + 1;
        reg174.range(95, 64) = s_result_PE149.read() + 1;
        reg174.range(127, 96) = s_result_PE149.read() + 1;
        s_result_all.write(reg174);

        reg175.range(31, 0) = s_result_PE150.read() + 1;
        reg175.range(63, 32) = s_result_PE150.read() + 1;
        reg175.range(95, 64) = s_result_PE151.read() + 1;
        reg175.range(127, 96) = s_result_PE151.read() + 1;
        s_result_all.write(reg175);

        reg176.range(31, 0) = s_result_PE152.read() + 1;
        reg176.range(63, 32) = s_result_PE152.read() + 1;
        reg176.range(95, 64) = s_result_PE153.read() + 1;
        reg176.range(127, 96) = s_result_PE153.read() + 1;
        s_result_all.write(reg176);

        reg177.range(31, 0) = s_result_PE154.read() + 1;
        reg177.range(63, 32) = s_result_PE154.read() + 1;
        reg177.range(95, 64) = s_result_PE155.read() + 1;
        reg177.range(127, 96) = s_result_PE155.read() + 1;
        s_result_all.write(reg177);

        reg178.range(31, 0) = s_result_PE156.read() + 1;
        reg178.range(63, 32) = s_result_PE156.read() + 1;
        reg178.range(95, 64) = s_result_PE157.read() + 1;
        reg178.range(127, 96) = s_result_PE157.read() + 1;
        s_result_all.write(reg178);

        reg179.range(31, 0) = s_result_PE158.read() + 1;
        reg179.range(63, 32) = s_result_PE158.read() + 1;
        reg179.range(95, 64) = s_result_PE159.read() + 1;
        reg179.range(127, 96) = s_result_PE159.read() + 1;
        s_result_all.write(reg179);

        reg180.range(31, 0) = s_result_PE160.read() + 1;
        reg180.range(63, 32) = s_result_PE160.read() + 1;
        reg180.range(95, 64) = s_result_PE161.read() + 1;
        reg180.range(127, 96) = s_result_PE161.read() + 1;
        s_result_all.write(reg180);

        reg181.range(31, 0) = s_result_PE162.read() + 1;
        reg181.range(63, 32) = s_result_PE162.read() + 1;
        reg181.range(95, 64) = s_result_PE163.read() + 1;
        reg181.range(127, 96) = s_result_PE163.read() + 1;
        s_result_all.write(reg181);

        reg182.range(31, 0) = s_result_PE164.read() + 1;
        reg182.range(63, 32) = s_result_PE164.read() + 1;
        reg182.range(95, 64) = s_result_PE165.read() + 1;
        reg182.range(127, 96) = s_result_PE165.read() + 1;
        s_result_all.write(reg182);

        reg183.range(31, 0) = s_result_PE166.read() + 1;
        reg183.range(63, 32) = s_result_PE166.read() + 1;
        reg183.range(95, 64) = s_result_PE167.read() + 1;
        reg183.range(127, 96) = s_result_PE167.read() + 1;
        s_result_all.write(reg183);

        reg184.range(31, 0) = s_result_PE168.read() + 1;
        reg184.range(63, 32) = s_result_PE168.read() + 1;
        reg184.range(95, 64) = s_result_PE169.read() + 1;
        reg184.range(127, 96) = s_result_PE169.read() + 1;
        s_result_all.write(reg184);

        reg185.range(31, 0) = s_result_PE170.read() + 1;
        reg185.range(63, 32) = s_result_PE170.read() + 1;
        reg185.range(95, 64) = s_result_PE171.read() + 1;
        reg185.range(127, 96) = s_result_PE171.read() + 1;
        s_result_all.write(reg185);

        reg186.range(31, 0) = s_result_PE172.read() + 1;
        reg186.range(63, 32) = s_result_PE172.read() + 1;
        reg186.range(95, 64) = s_result_PE173.read() + 1;
        reg186.range(127, 96) = s_result_PE173.read() + 1;
        s_result_all.write(reg186);

        reg187.range(31, 0) = s_result_PE174.read() + 1;
        reg187.range(63, 32) = s_result_PE174.read() + 1;
        reg187.range(95, 64) = s_result_PE175.read() + 1;
        reg187.range(127, 96) = s_result_PE175.read() + 1;
        s_result_all.write(reg187);

        reg188.range(31, 0) = s_result_PE176.read() + 1;
        reg188.range(63, 32) = s_result_PE176.read() + 1;
        reg188.range(95, 64) = s_result_PE177.read() + 1;
        reg188.range(127, 96) = s_result_PE177.read() + 1;
        s_result_all.write(reg188);

        reg189.range(31, 0) = s_result_PE178.read() + 1;
        reg189.range(63, 32) = s_result_PE178.read() + 1;
        reg189.range(95, 64) = s_result_PE179.read() + 1;
        reg189.range(127, 96) = s_result_PE179.read() + 1;
        s_result_all.write(reg189);

        reg190.range(31, 0) = s_result_PE180.read() + 1;
        reg190.range(63, 32) = s_result_PE180.read() + 1;
        reg190.range(95, 64) = s_result_PE181.read() + 1;
        reg190.range(127, 96) = s_result_PE181.read() + 1;
        s_result_all.write(reg190);

        reg191.range(31, 0) = s_result_PE182.read() + 1;
        reg191.range(63, 32) = s_result_PE182.read() + 1;
        reg191.range(95, 64) = s_result_PE183.read() + 1;
        reg191.range(127, 96) = s_result_PE183.read() + 1;
        s_result_all.write(reg191);

        reg192.range(31, 0) = s_result_PE184.read() + 1;
        reg192.range(63, 32) = s_result_PE184.read() + 1;
        reg192.range(95, 64) = s_result_PE185.read() + 1;
        reg192.range(127, 96) = s_result_PE185.read() + 1;
        s_result_all.write(reg192);

        reg193.range(31, 0) = s_result_PE186.read() + 1;
        reg193.range(63, 32) = s_result_PE186.read() + 1;
        reg193.range(95, 64) = s_result_PE187.read() + 1;
        reg193.range(127, 96) = s_result_PE187.read() + 1;
        s_result_all.write(reg193);

        reg194.range(31, 0) = s_result_PE188.read() + 1;
        reg194.range(63, 32) = s_result_PE188.read() + 1;
        reg194.range(95, 64) = s_result_PE189.read() + 1;
        reg194.range(127, 96) = s_result_PE189.read() + 1;
        s_result_all.write(reg194);

        reg195.range(31, 0) = s_result_PE190.read() + 1;
        reg195.range(63, 32) = s_result_PE190.read() + 1;
        reg195.range(95, 64) = s_result_PE191.read() + 1;
        reg195.range(127, 96) = s_result_PE191.read() + 1;
        s_result_all.write(reg195);

        reg196.range(31, 0) = s_result_PE192.read() + 1;
        reg196.range(63, 32) = s_result_PE192.read() + 1;
        reg196.range(95, 64) = s_result_PE193.read() + 1;
        reg196.range(127, 96) = s_result_PE193.read() + 1;
        s_result_all.write(reg196);

        reg197.range(31, 0) = s_result_PE194.read() + 1;
        reg197.range(63, 32) = s_result_PE194.read() + 1;
        reg197.range(95, 64) = s_result_PE195.read() + 1;
        reg197.range(127, 96) = s_result_PE195.read() + 1;
        s_result_all.write(reg197);

        reg198.range(31, 0) = s_result_PE196.read() + 1;
        reg198.range(63, 32) = s_result_PE196.read() + 1;
        reg198.range(95, 64) = s_result_PE197.read() + 1;
        reg198.range(127, 96) = s_result_PE197.read() + 1;
        s_result_all.write(reg198);

        reg199.range(31, 0) = s_result_PE198.read() + 1;
        reg199.range(63, 32) = s_result_PE198.read() + 1;
        reg199.range(95, 64) = s_result_PE199.read() + 1;
        reg199.range(127, 96) = s_result_PE199.read() + 1;
        s_result_all.write(reg199);

        reg200.range(31, 0) = s_result_PE200.read() + 1;
        reg200.range(63, 32) = s_result_PE200.read() + 1;
        reg200.range(95, 64) = s_result_PE201.read() + 1;
        reg200.range(127, 96) = s_result_PE201.read() + 1;
        s_result_all.write(reg200);

        reg201.range(31, 0) = s_result_PE202.read() + 1;
        reg201.range(63, 32) = s_result_PE202.read() + 1;
        reg201.range(95, 64) = s_result_PE203.read() + 1;
        reg201.range(127, 96) = s_result_PE203.read() + 1;
        s_result_all.write(reg201);

        reg202.range(31, 0) = s_result_PE204.read() + 1;
        reg202.range(63, 32) = s_result_PE204.read() + 1;
        reg202.range(95, 64) = s_result_PE205.read() + 1;
        reg202.range(127, 96) = s_result_PE205.read() + 1;
        s_result_all.write(reg202);

        reg203.range(31, 0) = s_result_PE206.read() + 1;
        reg203.range(63, 32) = s_result_PE206.read() + 1;
        reg203.range(95, 64) = s_result_PE207.read() + 1;
        reg203.range(127, 96) = s_result_PE207.read() + 1;
        s_result_all.write(reg203);

        reg204.range(31, 0) = s_result_PE208.read() + 1;
        reg204.range(63, 32) = s_result_PE208.read() + 1;
        reg204.range(95, 64) = s_result_PE209.read() + 1;
        reg204.range(127, 96) = s_result_PE209.read() + 1;
        s_result_all.write(reg204);

        reg205.range(31, 0) = s_result_PE210.read() + 1;
        reg205.range(63, 32) = s_result_PE210.read() + 1;
        reg205.range(95, 64) = s_result_PE211.read() + 1;
        reg205.range(127, 96) = s_result_PE211.read() + 1;
        s_result_all.write(reg205);

        reg206.range(31, 0) = s_result_PE212.read() + 1;
        reg206.range(63, 32) = s_result_PE212.read() + 1;
        reg206.range(95, 64) = s_result_PE213.read() + 1;
        reg206.range(127, 96) = s_result_PE213.read() + 1;
        s_result_all.write(reg206);

        reg207.range(31, 0) = s_result_PE214.read() + 1;
        reg207.range(63, 32) = s_result_PE214.read() + 1;
        reg207.range(95, 64) = s_result_PE215.read() + 1;
        reg207.range(127, 96) = s_result_PE215.read() + 1;
        s_result_all.write(reg207);

        reg208.range(31, 0) = s_result_PE216.read() + 1;
        reg208.range(63, 32) = s_result_PE216.read() + 1;
        reg208.range(95, 64) = s_result_PE217.read() + 1;
        reg208.range(127, 96) = s_result_PE217.read() + 1;
        s_result_all.write(reg208);

        reg209.range(31, 0) = s_result_PE218.read() + 1;
        reg209.range(63, 32) = s_result_PE218.read() + 1;
        reg209.range(95, 64) = s_result_PE219.read() + 1;
        reg209.range(127, 96) = s_result_PE219.read() + 1;
        s_result_all.write(reg209);

        reg210.range(31, 0) = s_result_PE220.read() + 1;
        reg210.range(63, 32) = s_result_PE220.read() + 1;
        reg210.range(95, 64) = s_result_PE221.read() + 1;
        reg210.range(127, 96) = s_result_PE221.read() + 1;
        s_result_all.write(reg210);

        reg211.range(31, 0) = s_result_PE222.read() + 1;
        reg211.range(63, 32) = s_result_PE222.read() + 1;
        reg211.range(95, 64) = s_result_PE223.read() + 1;
        reg211.range(127, 96) = s_result_PE223.read() + 1;
        s_result_all.write(reg211);

        reg212.range(31, 0) = s_result_PE224.read() + 1;
        reg212.range(63, 32) = s_result_PE224.read() + 1;
        reg212.range(95, 64) = s_result_PE225.read() + 1;
        reg212.range(127, 96) = s_result_PE225.read() + 1;
        s_result_all.write(reg212);

        reg213.range(31, 0) = s_result_PE226.read() + 1;
        reg213.range(63, 32) = s_result_PE226.read() + 1;
        reg213.range(95, 64) = s_result_PE227.read() + 1;
        reg213.range(127, 96) = s_result_PE227.read() + 1;
        s_result_all.write(reg213);

        reg214.range(31, 0) = s_result_PE228.read() + 1;
        reg214.range(63, 32) = s_result_PE228.read() + 1;
        reg214.range(95, 64) = s_result_PE229.read() + 1;
        reg214.range(127, 96) = s_result_PE229.read() + 1;
        s_result_all.write(reg214);

        reg215.range(31, 0) = s_result_PE230.read() + 1;
        reg215.range(63, 32) = s_result_PE230.read() + 1;
        reg215.range(95, 64) = s_result_PE231.read() + 1;
        reg215.range(127, 96) = s_result_PE231.read() + 1;
        s_result_all.write(reg215);

        reg216.range(31, 0) = s_result_PE232.read() + 1;
        reg216.range(63, 32) = s_result_PE232.read() + 1;
        reg216.range(95, 64) = s_result_PE233.read() + 1;
        reg216.range(127, 96) = s_result_PE233.read() + 1;
        s_result_all.write(reg216);

        reg217.range(31, 0) = s_result_PE234.read() + 1;
        reg217.range(63, 32) = s_result_PE234.read() + 1;
        reg217.range(95, 64) = s_result_PE235.read() + 1;
        reg217.range(127, 96) = s_result_PE235.read() + 1;
        s_result_all.write(reg217);

        reg218.range(31, 0) = s_result_PE236.read() + 1;
        reg218.range(63, 32) = s_result_PE236.read() + 1;
        reg218.range(95, 64) = s_result_PE237.read() + 1;
        reg218.range(127, 96) = s_result_PE237.read() + 1;
        s_result_all.write(reg218);

        reg219.range(31, 0) = s_result_PE238.read() + 1;
        reg219.range(63, 32) = s_result_PE238.read() + 1;
        reg219.range(95, 64) = s_result_PE239.read() + 1;
        reg219.range(127, 96) = s_result_PE239.read() + 1;
        s_result_all.write(reg219);

        reg220.range(31, 0) = s_result_PE240.read() + 1;
        reg220.range(63, 32) = s_result_PE240.read() + 1;
        reg220.range(95, 64) = s_result_PE241.read() + 1;
        reg220.range(127, 96) = s_result_PE241.read() + 1;
        s_result_all.write(reg220);

        reg221.range(31, 0) = s_result_PE242.read() + 1;
        reg221.range(63, 32) = s_result_PE242.read() + 1;
        reg221.range(95, 64) = s_result_PE243.read() + 1;
        reg221.range(127, 96) = s_result_PE243.read() + 1;
        s_result_all.write(reg221);

        reg222.range(31, 0) = s_result_PE244.read() + 1;
        reg222.range(63, 32) = s_result_PE244.read() + 1;
        reg222.range(95, 64) = s_result_PE245.read() + 1;
        reg222.range(127, 96) = s_result_PE245.read() + 1;
        s_result_all.write(reg222);

        reg223.range(31, 0) = s_result_PE246.read() + 1;
        reg223.range(63, 32) = s_result_PE246.read() + 1;
        reg223.range(95, 64) = s_result_PE247.read() + 1;
        reg223.range(127, 96) = s_result_PE247.read() + 1;
        s_result_all.write(reg223);

        reg224.range(31, 0) = s_result_PE248.read() + 1;
        reg224.range(63, 32) = s_result_PE248.read() + 1;
        reg224.range(95, 64) = s_result_PE249.read() + 1;
        reg224.range(127, 96) = s_result_PE249.read() + 1;
        s_result_all.write(reg224);

        reg225.range(31, 0) = s_result_PE250.read() + 1;
        reg225.range(63, 32) = s_result_PE250.read() + 1;
        reg225.range(95, 64) = s_result_PE251.read() + 1;
        reg225.range(127, 96) = s_result_PE251.read() + 1;
        s_result_all.write(reg225);

        reg226.range(31, 0) = s_result_PE252.read() + 1;
        reg226.range(63, 32) = s_result_PE252.read() + 1;
        reg226.range(95, 64) = s_result_PE253.read() + 1;
        reg226.range(127, 96) = s_result_PE253.read() + 1;
        s_result_all.write(reg226);

        reg227.range(31, 0) = s_result_PE254.read() + 1;
        reg227.range(63, 32) = s_result_PE254.read() + 1;
        reg227.range(95, 64) = s_result_PE255.read() + 1;
        reg227.range(127, 96) = s_result_PE255.read() + 1;
        s_result_all.write(reg227);

        reg228.range(31, 0) = s_result_PE256.read() + 1;
        reg228.range(63, 32) = s_result_PE256.read() + 1;
        reg228.range(95, 64) = s_result_PE257.read() + 1;
        reg228.range(127, 96) = s_result_PE257.read() + 1;
        s_result_all.write(reg228);

        reg229.range(31, 0) = s_result_PE258.read() + 1;
        reg229.range(63, 32) = s_result_PE258.read() + 1;
        reg229.range(95, 64) = s_result_PE259.read() + 1;
        reg229.range(127, 96) = s_result_PE259.read() + 1;
        s_result_all.write(reg229);

        reg230.range(31, 0) = s_result_PE260.read() + 1;
        reg230.range(63, 32) = s_result_PE260.read() + 1;
        reg230.range(95, 64) = s_result_PE261.read() + 1;
        reg230.range(127, 96) = s_result_PE261.read() + 1;
        s_result_all.write(reg230);

        reg231.range(31, 0) = s_result_PE262.read() + 1;
        reg231.range(63, 32) = s_result_PE262.read() + 1;
        reg231.range(95, 64) = s_result_PE263.read() + 1;
        reg231.range(127, 96) = s_result_PE263.read() + 1;
        s_result_all.write(reg231);

        reg232.range(31, 0) = s_result_PE264.read() + 1;
        reg232.range(63, 32) = s_result_PE264.read() + 1;
        reg232.range(95, 64) = s_result_PE265.read() + 1;
        reg232.range(127, 96) = s_result_PE265.read() + 1;
        s_result_all.write(reg232);

        reg233.range(31, 0) = s_result_PE266.read() + 1;
        reg233.range(63, 32) = s_result_PE266.read() + 1;
        reg233.range(95, 64) = s_result_PE267.read() + 1;
        reg233.range(127, 96) = s_result_PE267.read() + 1;
        s_result_all.write(reg233);

        reg234.range(31, 0) = s_result_PE268.read() + 1;
        reg234.range(63, 32) = s_result_PE268.read() + 1;
        reg234.range(95, 64) = s_result_PE269.read() + 1;
        reg234.range(127, 96) = s_result_PE269.read() + 1;
        s_result_all.write(reg234);

        reg235.range(31, 0) = s_result_PE270.read() + 1;
        reg235.range(63, 32) = s_result_PE270.read() + 1;
        reg235.range(95, 64) = s_result_PE271.read() + 1;
        reg235.range(127, 96) = s_result_PE271.read() + 1;
        s_result_all.write(reg235);

        reg236.range(31, 0) = s_result_PE272.read() + 1;
        reg236.range(63, 32) = s_result_PE272.read() + 1;
        reg236.range(95, 64) = s_result_PE273.read() + 1;
        reg236.range(127, 96) = s_result_PE273.read() + 1;
        s_result_all.write(reg236);

        reg237.range(31, 0) = s_result_PE274.read() + 1;
        reg237.range(63, 32) = s_result_PE274.read() + 1;
        reg237.range(95, 64) = s_result_PE275.read() + 1;
        reg237.range(127, 96) = s_result_PE275.read() + 1;
        s_result_all.write(reg237);

        reg238.range(31, 0) = s_result_PE276.read() + 1;
        reg238.range(63, 32) = s_result_PE276.read() + 1;
        reg238.range(95, 64) = s_result_PE277.read() + 1;
        reg238.range(127, 96) = s_result_PE277.read() + 1;
        s_result_all.write(reg238);

        reg239.range(31, 0) = s_result_PE278.read() + 1;
        reg239.range(63, 32) = s_result_PE278.read() + 1;
        reg239.range(95, 64) = s_result_PE279.read() + 1;
        reg239.range(127, 96) = s_result_PE279.read() + 1;
        s_result_all.write(reg239);

        reg240.range(31, 0) = s_result_PE280.read() + 1;
        reg240.range(63, 32) = s_result_PE280.read() + 1;
        reg240.range(95, 64) = s_result_PE281.read() + 1;
        reg240.range(127, 96) = s_result_PE281.read() + 1;
        s_result_all.write(reg240);

        reg241.range(31, 0) = s_result_PE282.read() + 1;
        reg241.range(63, 32) = s_result_PE282.read() + 1;
        reg241.range(95, 64) = s_result_PE283.read() + 1;
        reg241.range(127, 96) = s_result_PE283.read() + 1;
        s_result_all.write(reg241);

        reg242.range(31, 0) = s_result_PE284.read() + 1;
        reg242.range(63, 32) = s_result_PE284.read() + 1;
        reg242.range(95, 64) = s_result_PE285.read() + 1;
        reg242.range(127, 96) = s_result_PE285.read() + 1;
        s_result_all.write(reg242);

        reg243.range(31, 0) = s_result_PE286.read() + 1;
        reg243.range(63, 32) = s_result_PE286.read() + 1;
        reg243.range(95, 64) = s_result_PE287.read() + 1;
        reg243.range(127, 96) = s_result_PE287.read() + 1;
        s_result_all.write(reg243);

        reg244.range(31, 0) = s_result_PE288.read() + 1;
        reg244.range(63, 32) = s_result_PE288.read() + 1;
        reg244.range(95, 64) = s_result_PE289.read() + 1;
        reg244.range(127, 96) = s_result_PE289.read() + 1;
        s_result_all.write(reg244);

        reg245.range(31, 0) = s_result_PE290.read() + 1;
        reg245.range(63, 32) = s_result_PE290.read() + 1;
        reg245.range(95, 64) = s_result_PE291.read() + 1;
        reg245.range(127, 96) = s_result_PE291.read() + 1;
        s_result_all.write(reg245);

        reg246.range(31, 0) = s_result_PE292.read() + 1;
        reg246.range(63, 32) = s_result_PE292.read() + 1;
        reg246.range(95, 64) = s_result_PE293.read() + 1;
        reg246.range(127, 96) = s_result_PE293.read() + 1;
        s_result_all.write(reg246);

        reg247.range(31, 0) = s_result_PE294.read() + 1;
        reg247.range(63, 32) = s_result_PE294.read() + 1;
        reg247.range(95, 64) = s_result_PE295.read() + 1;
        reg247.range(127, 96) = s_result_PE295.read() + 1;
        s_result_all.write(reg247);

        reg248.range(31, 0) = s_result_PE296.read() + 1;
        reg248.range(63, 32) = s_result_PE296.read() + 1;
        reg248.range(95, 64) = s_result_PE297.read() + 1;
        reg248.range(127, 96) = s_result_PE297.read() + 1;
        s_result_all.write(reg248);

        reg249.range(31, 0) = s_result_PE298.read() + 1;
        reg249.range(63, 32) = s_result_PE298.read() + 1;
        reg249.range(95, 64) = s_result_PE299.read() + 1;
        reg249.range(127, 96) = s_result_PE299.read() + 1;
        s_result_all.write(reg249);

        reg250.range(31, 0) = s_result_PE300.read() + 1;
        reg250.range(63, 32) = s_result_PE300.read() + 1;
        reg250.range(95, 64) = s_result_PE301.read() + 1;
        reg250.range(127, 96) = s_result_PE301.read() + 1;
        s_result_all.write(reg250);

        reg251.range(31, 0) = s_result_PE302.read() + 1;
        reg251.range(63, 32) = s_result_PE302.read() + 1;
        reg251.range(95, 64) = s_result_PE303.read() + 1;
        reg251.range(127, 96) = s_result_PE303.read() + 1;
        s_result_all.write(reg251);

        reg252.range(31, 0) = s_result_PE304.read() + 1;
        reg252.range(63, 32) = s_result_PE304.read() + 1;
        reg252.range(95, 64) = s_result_PE305.read() + 1;
        reg252.range(127, 96) = s_result_PE305.read() + 1;
        s_result_all.write(reg252);

        reg253.range(31, 0) = s_result_PE306.read() + 1;
        reg253.range(63, 32) = s_result_PE306.read() + 1;
        reg253.range(95, 64) = s_result_PE307.read() + 1;
        reg253.range(127, 96) = s_result_PE307.read() + 1;
        s_result_all.write(reg253);

        reg254.range(31, 0) = s_result_PE308.read() + 1;
        reg254.range(63, 32) = s_result_PE308.read() + 1;
        reg254.range(95, 64) = s_result_PE309.read() + 1;
        reg254.range(127, 96) = s_result_PE309.read() + 1;
        s_result_all.write(reg254);

        reg255.range(31, 0) = s_result_PE310.read() + 1;
        reg255.range(63, 32) = s_result_PE310.read() + 1;
        reg255.range(95, 64) = s_result_PE311.read() + 1;
        reg255.range(127, 96) = s_result_PE311.read() + 1;
        s_result_all.write(reg255);
    }
}

void dataTransform(hls::stream<W_TYPE> & s_result_all, hls::stream<ap_uint<512> > & s_data_out){

    // s_result_all is 128 bits
    // s_data_in is 512 bits

    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        for (int i = 0; i < HIDDEN_SIZE1 / 4 / 4; i++){
            #pragma HLS pipeline II=1
            ap_uint<512> s_data;
            s_data(127, 0) = s_result_all.read();
            s_data(255, 128) = s_result_all.read();
            s_data(383, 256) = s_result_all.read();
            s_data(511, 384) = s_result_all.read();

            s_data_out.write(s_data);
        }

    }
}
