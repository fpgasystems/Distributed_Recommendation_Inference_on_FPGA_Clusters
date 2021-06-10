#include <hls_stream.h>
#include "constants.hpp"

void recvDataTransform(hls::stream<ap_uint<512> > & s_data_in, hls::stream<W_TYPE> & s_feature_in, hls::stream<W_TYPE> & s_result1_all);

// for layer 2
template<const int FEATURE_SIZE, const int INDEX_ROW_PE>
void matmul_PE_UNROLL8_LAYER2(
    hls::stream<W_TYPE>& s_feature_PE,
    hls::stream<D_TYPE>& s_result_PE);

template<>
void matmul_PE_UNROLL8_LAYER2<HIDDEN_SIZE1, INDEX_EVEN>(
    hls::stream<W_TYPE>& s_feature_PE,
    hls::stream<D_TYPE>& s_result_PE);

template<>
void matmul_PE_UNROLL8_LAYER2<HIDDEN_SIZE1, INDEX_ODD>(
    hls::stream<W_TYPE>& s_feature_PE,
    hls::stream<D_TYPE>& s_result_PE);

template<const int FEATURE_SIZE, const int INDEX_ROW_PE>
void init_weights_layer2(W_TYPE* weights_transpose); 

template<>
void init_weights_layer2<HIDDEN_SIZE1, INDEX_EVEN>(W_TYPE* weights_transpose_local);

template<>
void init_weights_layer2<HIDDEN_SIZE1, INDEX_ODD>(W_TYPE* weights_transpose_local);

template<const int FEATURE_SIZE>
void replicate_feature_512PEs_320PE(
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
    hls::stream<W_TYPE>& s_feature_PE310, hls::stream<W_TYPE>& s_feature_PE311, 
    hls::stream<W_TYPE>& s_feature_PE312, hls::stream<W_TYPE>& s_feature_PE313, 
    hls::stream<W_TYPE>& s_feature_PE314, hls::stream<W_TYPE>& s_feature_PE315, 
    hls::stream<W_TYPE>& s_feature_PE316, hls::stream<W_TYPE>& s_feature_PE317, 
    hls::stream<W_TYPE>& s_feature_PE318, hls::stream<W_TYPE>& s_feature_PE319
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
    hls::stream<W_TYPE>& s_result_all);


void dataTransform(hls::stream<W_TYPE> & s_result_all, hls::stream<W_TYPE> & s_result_partial, hls::stream<ap_uint<512> > & s_data_out);

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


void recvDataTransform(hls::stream<ap_uint<512> > & s_data_in, hls::stream<W_TYPE> & s_feature_in, hls::stream<W_TYPE> & s_result1_all){
    // s_data_in is the whole result of layer 1 from node 2
    // s_feature_in and s_result1_all are the same
    // s_feature_in is used to replicate features
    // s_result1_all is used to transfer the result of layer 1 to node 4
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        for (int i = 0; i < HIDDEN_SIZE1 / 4 / 4; i++){
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

            s_result1_all.write(reg0);
            s_result1_all.write(reg1);
            s_result1_all.write(reg2);
            s_result1_all.write(reg3);
        }

    }
}

template<>
void matmul_PE_UNROLL8_LAYER2<HIDDEN_SIZE1, INDEX_EVEN>(
    hls::stream<W_TYPE>& s_feature_PE,
    hls::stream<D_TYPE>& s_result_PE) {
#pragma HLS inline off
    // store weights to local at the beginning
    // transpose the weights as well -> e.g., 
    //     orginal weights (row_size, COL_PER_PE)
    //     now: (COL_PER_PE, row_size)
    // so that the dot product is more natural -> 
    //     feature x row0, feature x row1, ...

    W_TYPE weights_transpose_local[HIDDEN_SIZE1 / INTS_PER_W];
    W_TYPE feature_local[HIDDEN_SIZE1 / INTS_PER_W];
#pragma HLS resource variable=weights_transpose_local core=RAM_2P_URAM
#pragma HLS resource variable=feature_local core=RAM_2P_URAM

    init_weights_layer2<HIDDEN_SIZE1, INDEX_EVEN>(weights_transpose_local);

    item_loop:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        // read 
        read_loop:
        for (int i = 0; i < HIDDEN_SIZE1 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            feature_local[i] = s_feature_PE.read();
        }
        // compute and write
        
        D_TYPE result = 0;
        dot_product:
        // NOTE: manually unroll 2 here
        for (int d = 0; d < HIDDEN_SIZE1 / INTS_PER_W / 2; d++) {
            // #pragma HLS unroll factor=4
            #pragma HLS pipeline II=1
            // feature[d] * weights_transpose_local[result_idx][d]
            W_TYPE reg_f_0 = feature_local[2 * d];
            W_TYPE reg_f_1 = feature_local[2 * d + 1];
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
            //std::cout << "even weight is " << first_w_0 << second_w_0 << third_w_0 << fourth_w_0 << std::endl;
        }
        std::cout << "even result is " << result << std::endl;
        s_result_PE.write(result);
    }
} 

template<>
void matmul_PE_UNROLL8_LAYER2<HIDDEN_SIZE1, INDEX_ODD>(
    hls::stream<W_TYPE>& s_feature_PE,
    hls::stream<D_TYPE>& s_result_PE) {
#pragma HLS inline off
    // store weights to local at the beginning
    // transpose the weights as well -> e.g., 
    //     orginal weights (row_size, COL_PER_PE)
    //     now: (COL_PER_PE, row_size)
    // so that the dot product is more natural -> 
    //     feature x row0, feature x row1, ...
    W_TYPE weights_transpose_local[HIDDEN_SIZE1 / INTS_PER_W];
    W_TYPE feature_local[HIDDEN_SIZE1 / INTS_PER_W];
//#pragma HLS resource variable=weights_transpose_local core=RAM_2P_URAM
//#pragma HLS resource variable=feature_local core=RAM_2P_URAM

    init_weights_layer2<HIDDEN_SIZE1, INDEX_ODD>(weights_transpose_local);

    item_loop:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        // read 
        read_loop:
        for (int i = 0; i < HIDDEN_SIZE1 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            feature_local[i] = s_feature_PE.read();
        }
        // compute and write
        
        D_TYPE result = 0;
        dot_product:
        // NOTE: manually unroll 2 here
        for (int d = 0; d < HIDDEN_SIZE1 / INTS_PER_W / 2; d++) {
            // #pragma HLS unroll factor=4
            #pragma HLS pipeline II=1
            // feature[d] * weights_transpose_local[result_idx][d]
            W_TYPE reg_f_0 = feature_local[2 * d];
            W_TYPE reg_f_1 = feature_local[2 * d + 1];
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
            //std::cout << "odd weight is " << first_w_0 << second_w_0 << third_w_0 << fourth_w_0 << std::endl;
        }
        s_result_PE.write(result);
    }
}

template<>
void init_weights_layer2<HIDDEN_SIZE1, INDEX_EVEN>(W_TYPE* weights_transpose_local) {
    // same as the host side, len = 1024
    D_TYPE row_template_even[HIDDEN_SIZE1] = 
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
void init_weights_layer2<HIDDEN_SIZE1, INDEX_ODD>(W_TYPE* weights_transpose_local) {
    // same as the host side, len = 1024

    D_TYPE row_template_odd[HIDDEN_SIZE1] = 
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
    hls::stream<W_TYPE>& s_feature_PE310, hls::stream<W_TYPE>& s_feature_PE311, 
    hls::stream<W_TYPE>& s_feature_PE312, hls::stream<W_TYPE>& s_feature_PE313, 
    hls::stream<W_TYPE>& s_feature_PE314, hls::stream<W_TYPE>& s_feature_PE315, 
    hls::stream<W_TYPE>& s_feature_PE316, hls::stream<W_TYPE>& s_feature_PE317, 
    hls::stream<W_TYPE>& s_feature_PE318, hls::stream<W_TYPE>& s_feature_PE319
) {
        for (int i = 0; i < BATCH_NUM * BATCH_SIZE * FEATURE_SIZE / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1

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
            s_feature_PE312.write(reg);
            s_feature_PE313.write(reg);
            s_feature_PE314.write(reg);
            s_feature_PE315.write(reg);
            s_feature_PE316.write(reg);
            s_feature_PE317.write(reg);
            s_feature_PE318.write(reg);
            s_feature_PE319.write(reg);
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
    hls::stream<W_TYPE>& s_result_all)
{
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
            reg72, reg73, reg74, reg75, reg76, reg77, reg78, reg79;

        reg0.range(31, 0) = s_result_PE0.read() + 1;
        reg0.range(63, 32) = s_result_PE1.read() + 1;
        reg0.range(95, 64) = s_result_PE2.read() + 1;
        reg0.range(127, 96) = s_result_PE3.read() + 1;
        s_result_all.write(reg0);

        reg1.range(31, 0) = s_result_PE4.read() + 1;
        reg1.range(63, 32) = s_result_PE5.read() + 1;
        reg1.range(95, 64) = s_result_PE6.read() + 1;
        reg1.range(127, 96) = s_result_PE7.read() + 1;
        s_result_all.write(reg1);

        reg2.range(31, 0) = s_result_PE8.read() + 1;
        reg2.range(63, 32) = s_result_PE9.read() + 1;
        reg2.range(95, 64) = s_result_PE10.read() + 1;
        reg2.range(127, 96) = s_result_PE11.read() + 1;
        s_result_all.write(reg2);

        reg3.range(31, 0) = s_result_PE12.read() + 1;
        reg3.range(63, 32) = s_result_PE13.read() + 1;
        reg3.range(95, 64) = s_result_PE14.read() + 1;
        reg3.range(127, 96) = s_result_PE15.read() + 1;
        s_result_all.write(reg3);

        reg4.range(31, 0) = s_result_PE16.read() + 1;
        reg4.range(63, 32) = s_result_PE17.read() + 1;
        reg4.range(95, 64) = s_result_PE18.read() + 1;
        reg4.range(127, 96) = s_result_PE19.read() + 1;
        s_result_all.write(reg4);

        reg5.range(31, 0) = s_result_PE20.read() + 1;
        reg5.range(63, 32) = s_result_PE21.read() + 1;
        reg5.range(95, 64) = s_result_PE22.read() + 1;
        reg5.range(127, 96) = s_result_PE23.read() + 1;
        s_result_all.write(reg5);

        reg6.range(31, 0) = s_result_PE24.read() + 1;
        reg6.range(63, 32) = s_result_PE25.read() + 1;
        reg6.range(95, 64) = s_result_PE26.read() + 1;
        reg6.range(127, 96) = s_result_PE27.read() + 1;
        s_result_all.write(reg6);

        reg7.range(31, 0) = s_result_PE28.read() + 1;
        reg7.range(63, 32) = s_result_PE29.read() + 1;
        reg7.range(95, 64) = s_result_PE30.read() + 1;
        reg7.range(127, 96) = s_result_PE31.read() + 1;
        s_result_all.write(reg7);

        reg8.range(31, 0) = s_result_PE32.read() + 1;
        reg8.range(63, 32) = s_result_PE33.read() + 1;
        reg8.range(95, 64) = s_result_PE34.read() + 1;
        reg8.range(127, 96) = s_result_PE35.read() + 1;
        s_result_all.write(reg8);

        reg9.range(31, 0) = s_result_PE36.read() + 1;
        reg9.range(63, 32) = s_result_PE37.read() + 1;
        reg9.range(95, 64) = s_result_PE38.read() + 1;
        reg9.range(127, 96) = s_result_PE39.read() + 1;
        s_result_all.write(reg9);

        reg10.range(31, 0) = s_result_PE40.read() + 1;
        reg10.range(63, 32) = s_result_PE41.read() + 1;
        reg10.range(95, 64) = s_result_PE42.read() + 1;
        reg10.range(127, 96) = s_result_PE43.read() + 1;
        s_result_all.write(reg10);

        reg11.range(31, 0) = s_result_PE44.read() + 1;
        reg11.range(63, 32) = s_result_PE45.read() + 1;
        reg11.range(95, 64) = s_result_PE46.read() + 1;
        reg11.range(127, 96) = s_result_PE47.read() + 1;
        s_result_all.write(reg11);

        reg12.range(31, 0) = s_result_PE48.read() + 1;
        reg12.range(63, 32) = s_result_PE49.read() + 1;
        reg12.range(95, 64) = s_result_PE50.read() + 1;
        reg12.range(127, 96) = s_result_PE51.read() + 1;
        s_result_all.write(reg12);

        reg13.range(31, 0) = s_result_PE52.read() + 1;
        reg13.range(63, 32) = s_result_PE53.read() + 1;
        reg13.range(95, 64) = s_result_PE54.read() + 1;
        reg13.range(127, 96) = s_result_PE55.read() + 1;
        s_result_all.write(reg13);

        reg14.range(31, 0) = s_result_PE56.read() + 1;
        reg14.range(63, 32) = s_result_PE57.read() + 1;
        reg14.range(95, 64) = s_result_PE58.read() + 1;
        reg14.range(127, 96) = s_result_PE59.read() + 1;
        s_result_all.write(reg14);

        reg15.range(31, 0) = s_result_PE60.read() + 1;
        reg15.range(63, 32) = s_result_PE61.read() + 1;
        reg15.range(95, 64) = s_result_PE62.read() + 1;
        reg15.range(127, 96) = s_result_PE63.read() + 1;
        s_result_all.write(reg15);

        reg16.range(31, 0) = s_result_PE64.read() + 1;
        reg16.range(63, 32) = s_result_PE65.read() + 1;
        reg16.range(95, 64) = s_result_PE66.read() + 1;
        reg16.range(127, 96) = s_result_PE67.read() + 1;
        s_result_all.write(reg16);

        reg17.range(31, 0) = s_result_PE68.read() + 1;
        reg17.range(63, 32) = s_result_PE69.read() + 1;
        reg17.range(95, 64) = s_result_PE70.read() + 1;
        reg17.range(127, 96) = s_result_PE71.read() + 1;
        s_result_all.write(reg17);

        reg18.range(31, 0) = s_result_PE72.read() + 1;
        reg18.range(63, 32) = s_result_PE73.read() + 1;
        reg18.range(95, 64) = s_result_PE74.read() + 1;
        reg18.range(127, 96) = s_result_PE75.read() + 1;
        s_result_all.write(reg18);

        reg19.range(31, 0) = s_result_PE76.read() + 1;
        reg19.range(63, 32) = s_result_PE77.read() + 1;
        reg19.range(95, 64) = s_result_PE78.read() + 1;
        reg19.range(127, 96) = s_result_PE79.read() + 1;
        s_result_all.write(reg19);

        reg20.range(31, 0) = s_result_PE80.read() + 1;
        reg20.range(63, 32) = s_result_PE81.read() + 1;
        reg20.range(95, 64) = s_result_PE82.read() + 1;
        reg20.range(127, 96) = s_result_PE83.read() + 1;
        s_result_all.write(reg20);

        reg21.range(31, 0) = s_result_PE84.read() + 1;
        reg21.range(63, 32) = s_result_PE85.read() + 1;
        reg21.range(95, 64) = s_result_PE86.read() + 1;
        reg21.range(127, 96) = s_result_PE87.read() + 1;
        s_result_all.write(reg21);

        reg22.range(31, 0) = s_result_PE88.read() + 1;
        reg22.range(63, 32) = s_result_PE89.read() + 1;
        reg22.range(95, 64) = s_result_PE90.read() + 1;
        reg22.range(127, 96) = s_result_PE91.read() + 1;
        s_result_all.write(reg22);

        reg23.range(31, 0) = s_result_PE92.read() + 1;
        reg23.range(63, 32) = s_result_PE93.read() + 1;
        reg23.range(95, 64) = s_result_PE94.read() + 1;
        reg23.range(127, 96) = s_result_PE95.read() + 1;
        s_result_all.write(reg23);

        reg24.range(31, 0) = s_result_PE96.read() + 1;
        reg24.range(63, 32) = s_result_PE97.read() + 1;
        reg24.range(95, 64) = s_result_PE98.read() + 1;
        reg24.range(127, 96) = s_result_PE99.read() + 1;
        s_result_all.write(reg24);

        reg25.range(31, 0) = s_result_PE100.read() + 1;
        reg25.range(63, 32) = s_result_PE101.read() + 1;
        reg25.range(95, 64) = s_result_PE102.read() + 1;
        reg25.range(127, 96) = s_result_PE103.read() + 1;
        s_result_all.write(reg25);

        reg26.range(31, 0) = s_result_PE104.read() + 1;
        reg26.range(63, 32) = s_result_PE105.read() + 1;
        reg26.range(95, 64) = s_result_PE106.read() + 1;
        reg26.range(127, 96) = s_result_PE107.read() + 1;
        s_result_all.write(reg26);

        reg27.range(31, 0) = s_result_PE108.read() + 1;
        reg27.range(63, 32) = s_result_PE109.read() + 1;
        reg27.range(95, 64) = s_result_PE110.read() + 1;
        reg27.range(127, 96) = s_result_PE111.read() + 1;
        s_result_all.write(reg27);

        reg28.range(31, 0) = s_result_PE112.read() + 1;
        reg28.range(63, 32) = s_result_PE113.read() + 1;
        reg28.range(95, 64) = s_result_PE114.read() + 1;
        reg28.range(127, 96) = s_result_PE115.read() + 1;
        s_result_all.write(reg28);

        reg29.range(31, 0) = s_result_PE116.read() + 1;
        reg29.range(63, 32) = s_result_PE117.read() + 1;
        reg29.range(95, 64) = s_result_PE118.read() + 1;
        reg29.range(127, 96) = s_result_PE119.read() + 1;
        s_result_all.write(reg29);

        reg30.range(31, 0) = s_result_PE120.read() + 1;
        reg30.range(63, 32) = s_result_PE121.read() + 1;
        reg30.range(95, 64) = s_result_PE122.read() + 1;
        reg30.range(127, 96) = s_result_PE123.read() + 1;
        s_result_all.write(reg30);

        reg31.range(31, 0) = s_result_PE124.read() + 1;
        reg31.range(63, 32) = s_result_PE125.read() + 1;
        reg31.range(95, 64) = s_result_PE126.read() + 1;
        reg31.range(127, 96) = s_result_PE127.read() + 1;
        s_result_all.write(reg31);

        reg32.range(31, 0) = s_result_PE128.read() + 1;
        reg32.range(63, 32) = s_result_PE129.read() + 1;
        reg32.range(95, 64) = s_result_PE130.read() + 1;
        reg32.range(127, 96) = s_result_PE131.read() + 1;
        s_result_all.write(reg32);

        reg33.range(31, 0) = s_result_PE132.read() + 1;
        reg33.range(63, 32) = s_result_PE133.read() + 1;
        reg33.range(95, 64) = s_result_PE134.read() + 1;
        reg33.range(127, 96) = s_result_PE135.read() + 1;
        s_result_all.write(reg33);

        reg34.range(31, 0) = s_result_PE136.read() + 1;
        reg34.range(63, 32) = s_result_PE137.read() + 1;
        reg34.range(95, 64) = s_result_PE138.read() + 1;
        reg34.range(127, 96) = s_result_PE139.read() + 1;
        s_result_all.write(reg34);

        reg35.range(31, 0) = s_result_PE140.read() + 1;
        reg35.range(63, 32) = s_result_PE141.read() + 1;
        reg35.range(95, 64) = s_result_PE142.read() + 1;
        reg35.range(127, 96) = s_result_PE143.read() + 1;
        s_result_all.write(reg35);

        reg36.range(31, 0) = s_result_PE144.read() + 1;
        reg36.range(63, 32) = s_result_PE145.read() + 1;
        reg36.range(95, 64) = s_result_PE146.read() + 1;
        reg36.range(127, 96) = s_result_PE147.read() + 1;
        s_result_all.write(reg36);

        reg37.range(31, 0) = s_result_PE148.read() + 1;
        reg37.range(63, 32) = s_result_PE149.read() + 1;
        reg37.range(95, 64) = s_result_PE150.read() + 1;
        reg37.range(127, 96) = s_result_PE151.read() + 1;
        s_result_all.write(reg37);

        reg38.range(31, 0) = s_result_PE152.read() + 1;
        reg38.range(63, 32) = s_result_PE153.read() + 1;
        reg38.range(95, 64) = s_result_PE154.read() + 1;
        reg38.range(127, 96) = s_result_PE155.read() + 1;
        s_result_all.write(reg38);

        reg39.range(31, 0) = s_result_PE156.read() + 1;
        reg39.range(63, 32) = s_result_PE157.read() + 1;
        reg39.range(95, 64) = s_result_PE158.read() + 1;
        reg39.range(127, 96) = s_result_PE159.read() + 1;
        s_result_all.write(reg39);

        reg40.range(31, 0) = s_result_PE160.read() + 1;
        reg40.range(63, 32) = s_result_PE161.read() + 1;
        reg40.range(95, 64) = s_result_PE162.read() + 1;
        reg40.range(127, 96) = s_result_PE163.read() + 1;
        s_result_all.write(reg40);

        reg41.range(31, 0) = s_result_PE164.read() + 1;
        reg41.range(63, 32) = s_result_PE165.read() + 1;
        reg41.range(95, 64) = s_result_PE166.read() + 1;
        reg41.range(127, 96) = s_result_PE167.read() + 1;
        s_result_all.write(reg41);

        reg42.range(31, 0) = s_result_PE168.read() + 1;
        reg42.range(63, 32) = s_result_PE169.read() + 1;
        reg42.range(95, 64) = s_result_PE170.read() + 1;
        reg42.range(127, 96) = s_result_PE171.read() + 1;
        s_result_all.write(reg42);

        reg43.range(31, 0) = s_result_PE172.read() + 1;
        reg43.range(63, 32) = s_result_PE173.read() + 1;
        reg43.range(95, 64) = s_result_PE174.read() + 1;
        reg43.range(127, 96) = s_result_PE175.read() + 1;
        s_result_all.write(reg43);

        reg44.range(31, 0) = s_result_PE176.read() + 1;
        reg44.range(63, 32) = s_result_PE177.read() + 1;
        reg44.range(95, 64) = s_result_PE178.read() + 1;
        reg44.range(127, 96) = s_result_PE179.read() + 1;
        s_result_all.write(reg44);

        reg45.range(31, 0) = s_result_PE180.read() + 1;
        reg45.range(63, 32) = s_result_PE181.read() + 1;
        reg45.range(95, 64) = s_result_PE182.read() + 1;
        reg45.range(127, 96) = s_result_PE183.read() + 1;
        s_result_all.write(reg45);

        reg46.range(31, 0) = s_result_PE184.read() + 1;
        reg46.range(63, 32) = s_result_PE185.read() + 1;
        reg46.range(95, 64) = s_result_PE186.read() + 1;
        reg46.range(127, 96) = s_result_PE187.read() + 1;
        s_result_all.write(reg46);

        reg47.range(31, 0) = s_result_PE188.read() + 1;
        reg47.range(63, 32) = s_result_PE189.read() + 1;
        reg47.range(95, 64) = s_result_PE190.read() + 1;
        reg47.range(127, 96) = s_result_PE191.read() + 1;
        s_result_all.write(reg47);

        reg48.range(31, 0) = s_result_PE192.read() + 1;
        reg48.range(63, 32) = s_result_PE193.read() + 1;
        reg48.range(95, 64) = s_result_PE194.read() + 1;
        reg48.range(127, 96) = s_result_PE195.read() + 1;
        s_result_all.write(reg48);

        reg49.range(31, 0) = s_result_PE196.read() + 1;
        reg49.range(63, 32) = s_result_PE197.read() + 1;
        reg49.range(95, 64) = s_result_PE198.read() + 1;
        reg49.range(127, 96) = s_result_PE199.read() + 1;
        s_result_all.write(reg49);

        reg50.range(31, 0) = s_result_PE200.read() + 1;
        reg50.range(63, 32) = s_result_PE201.read() + 1;
        reg50.range(95, 64) = s_result_PE202.read() + 1;
        reg50.range(127, 96) = s_result_PE203.read() + 1;
        s_result_all.write(reg50);

        reg51.range(31, 0) = s_result_PE204.read() + 1;
        reg51.range(63, 32) = s_result_PE205.read() + 1;
        reg51.range(95, 64) = s_result_PE206.read() + 1;
        reg51.range(127, 96) = s_result_PE207.read() + 1;
        s_result_all.write(reg51);

        reg52.range(31, 0) = s_result_PE208.read() + 1;
        reg52.range(63, 32) = s_result_PE209.read() + 1;
        reg52.range(95, 64) = s_result_PE210.read() + 1;
        reg52.range(127, 96) = s_result_PE211.read() + 1;
        s_result_all.write(reg52);

        reg53.range(31, 0) = s_result_PE212.read() + 1;
        reg53.range(63, 32) = s_result_PE213.read() + 1;
        reg53.range(95, 64) = s_result_PE214.read() + 1;
        reg53.range(127, 96) = s_result_PE215.read() + 1;
        s_result_all.write(reg53);

        reg54.range(31, 0) = s_result_PE216.read() + 1;
        reg54.range(63, 32) = s_result_PE217.read() + 1;
        reg54.range(95, 64) = s_result_PE218.read() + 1;
        reg54.range(127, 96) = s_result_PE219.read() + 1;
        s_result_all.write(reg54);

        reg55.range(31, 0) = s_result_PE220.read() + 1;
        reg55.range(63, 32) = s_result_PE221.read() + 1;
        reg55.range(95, 64) = s_result_PE222.read() + 1;
        reg55.range(127, 96) = s_result_PE223.read() + 1;
        s_result_all.write(reg55);

        reg56.range(31, 0) = s_result_PE224.read() + 1;
        reg56.range(63, 32) = s_result_PE225.read() + 1;
        reg56.range(95, 64) = s_result_PE226.read() + 1;
        reg56.range(127, 96) = s_result_PE227.read() + 1;
        s_result_all.write(reg56);

        reg57.range(31, 0) = s_result_PE228.read() + 1;
        reg57.range(63, 32) = s_result_PE229.read() + 1;
        reg57.range(95, 64) = s_result_PE230.read() + 1;
        reg57.range(127, 96) = s_result_PE231.read() + 1;
        s_result_all.write(reg57);

        reg58.range(31, 0) = s_result_PE232.read() + 1;
        reg58.range(63, 32) = s_result_PE233.read() + 1;
        reg58.range(95, 64) = s_result_PE234.read() + 1;
        reg58.range(127, 96) = s_result_PE235.read() + 1;
        s_result_all.write(reg58);

        reg59.range(31, 0) = s_result_PE236.read() + 1;
        reg59.range(63, 32) = s_result_PE237.read() + 1;
        reg59.range(95, 64) = s_result_PE238.read() + 1;
        reg59.range(127, 96) = s_result_PE239.read() + 1;
        s_result_all.write(reg59);

        reg60.range(31, 0) = s_result_PE240.read() + 1;
        reg60.range(63, 32) = s_result_PE241.read() + 1;
        reg60.range(95, 64) = s_result_PE242.read() + 1;
        reg60.range(127, 96) = s_result_PE243.read() + 1;
        s_result_all.write(reg60);

        reg61.range(31, 0) = s_result_PE244.read() + 1;
        reg61.range(63, 32) = s_result_PE245.read() + 1;
        reg61.range(95, 64) = s_result_PE246.read() + 1;
        reg61.range(127, 96) = s_result_PE247.read() + 1;
        s_result_all.write(reg61);

        reg62.range(31, 0) = s_result_PE248.read() + 1;
        reg62.range(63, 32) = s_result_PE249.read() + 1;
        reg62.range(95, 64) = s_result_PE250.read() + 1;
        reg62.range(127, 96) = s_result_PE251.read() + 1;
        s_result_all.write(reg62);

        reg63.range(31, 0) = s_result_PE252.read() + 1;
        reg63.range(63, 32) = s_result_PE253.read() + 1;
        reg63.range(95, 64) = s_result_PE254.read() + 1;
        reg63.range(127, 96) = s_result_PE255.read() + 1;
        s_result_all.write(reg63);

        reg64.range(31, 0) = s_result_PE256.read() + 1;
        reg64.range(63, 32) = s_result_PE257.read() + 1;
        reg64.range(95, 64) = s_result_PE258.read() + 1;
        reg64.range(127, 96) = s_result_PE259.read() + 1;
        s_result_all.write(reg64);

        reg65.range(31, 0) = s_result_PE260.read() + 1;
        reg65.range(63, 32) = s_result_PE261.read() + 1;
        reg65.range(95, 64) = s_result_PE262.read() + 1;
        reg65.range(127, 96) = s_result_PE263.read() + 1;
        s_result_all.write(reg65);

        reg66.range(31, 0) = s_result_PE264.read() + 1;
        reg66.range(63, 32) = s_result_PE265.read() + 1;
        reg66.range(95, 64) = s_result_PE266.read() + 1;
        reg66.range(127, 96) = s_result_PE267.read() + 1;
        s_result_all.write(reg66);

        reg67.range(31, 0) = s_result_PE268.read() + 1;
        reg67.range(63, 32) = s_result_PE269.read() + 1;
        reg67.range(95, 64) = s_result_PE270.read() + 1;
        reg67.range(127, 96) = s_result_PE271.read() + 1;
        s_result_all.write(reg67);

        reg68.range(31, 0) = s_result_PE272.read() + 1;
        reg68.range(63, 32) = s_result_PE273.read() + 1;
        reg68.range(95, 64) = s_result_PE274.read() + 1;
        reg68.range(127, 96) = s_result_PE275.read() + 1;
        s_result_all.write(reg68);

        reg69.range(31, 0) = s_result_PE276.read() + 1;
        reg69.range(63, 32) = s_result_PE277.read() + 1;
        reg69.range(95, 64) = s_result_PE278.read() + 1;
        reg69.range(127, 96) = s_result_PE279.read() + 1;
        s_result_all.write(reg69);

        reg70.range(31, 0) = s_result_PE280.read() + 1;
        reg70.range(63, 32) = s_result_PE281.read() + 1;
        reg70.range(95, 64) = s_result_PE282.read() + 1;
        reg70.range(127, 96) = s_result_PE283.read() + 1;
        s_result_all.write(reg70);

        reg71.range(31, 0) = s_result_PE284.read() + 1;
        reg71.range(63, 32) = s_result_PE285.read() + 1;
        reg71.range(95, 64) = s_result_PE286.read() + 1;
        reg71.range(127, 96) = s_result_PE287.read() + 1;
        s_result_all.write(reg71);

        reg72.range(31, 0) = s_result_PE288.read() + 1;
        reg72.range(63, 32) = s_result_PE289.read() + 1;
        reg72.range(95, 64) = s_result_PE290.read() + 1;
        reg72.range(127, 96) = s_result_PE291.read() + 1;
        s_result_all.write(reg72);

        reg73.range(31, 0) = s_result_PE292.read() + 1;
        reg73.range(63, 32) = s_result_PE293.read() + 1;
        reg73.range(95, 64) = s_result_PE294.read() + 1;
        reg73.range(127, 96) = s_result_PE295.read() + 1;
        s_result_all.write(reg73);

        reg74.range(31, 0) = s_result_PE296.read() + 1;
        reg74.range(63, 32) = s_result_PE297.read() + 1;
        reg74.range(95, 64) = s_result_PE298.read() + 1;
        reg74.range(127, 96) = s_result_PE299.read() + 1;
        s_result_all.write(reg74);

        reg75.range(31, 0) = s_result_PE300.read() + 1;
        reg75.range(63, 32) = s_result_PE301.read() + 1;
        reg75.range(95, 64) = s_result_PE302.read() + 1;
        reg75.range(127, 96) = s_result_PE303.read() + 1;
        s_result_all.write(reg75);

        reg76.range(31, 0) = s_result_PE304.read() + 1;
        reg76.range(63, 32) = s_result_PE305.read() + 1;
        reg76.range(95, 64) = s_result_PE306.read() + 1;
        reg76.range(127, 96) = s_result_PE307.read() + 1;
        s_result_all.write(reg76);

        reg77.range(31, 0) = s_result_PE308.read() + 1;
        reg77.range(63, 32) = s_result_PE309.read() + 1;
        reg77.range(95, 64) = s_result_PE310.read() + 1;
        reg77.range(127, 96) = s_result_PE311.read() + 1;
        s_result_all.write(reg77);

        reg78.range(31, 0) = s_result_PE312.read() + 1;
        reg78.range(63, 32) = s_result_PE313.read() + 1;
        reg78.range(95, 64) = s_result_PE314.read() + 1;
        reg78.range(127, 96) = s_result_PE315.read() + 1;
        s_result_all.write(reg78);

        reg79.range(31, 0) = s_result_PE316.read() + 1;
        reg79.range(63, 32) = s_result_PE317.read() + 1;
        reg79.range(95, 64) = s_result_PE318.read() + 1;
        reg79.range(127, 96) = s_result_PE319.read() + 1;
        s_result_all.write(reg79);
    }
}


void dataTransform(hls::stream<W_TYPE> & s_result_all, hls::stream<W_TYPE> & s_result_partial, hls::stream<ap_uint<512> > & s_data_out){
    // every 6 packets
    // 1024*32 bits + 320*32 = 64*512 + 20*512 bits valid
    // the first 4 packets 4*16*512 bits is full result of layer 1
    // the last 2 packets 2*16*512 bits is the partial result of layer 2 in node 2
    // redundant bits are discarded
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        for (int i = 0; i < 6 * 16; i++){
            #pragma HLS pipeline II=1
            ap_uint<512> s_data;

            if (i < 4 * 16){
                s_data(127, 0) = s_result_all.read();
                s_data(255, 128) = s_result_all.read();
                s_data(383, 256) = s_result_all.read();
                s_data(511, 384) = s_result_all.read();
            }
            else if (i < (4*16 + 20)){
                s_data(127, 0) = s_result_partial.read();
                s_data(255, 128) = s_result_partial.read();
                s_data(383, 256) = s_result_partial.read();
                s_data(511, 384) = s_result_partial.read();
            }
            else {
                // the last 12*512 bits would be discarded in node 4
                s_data(127, 0) = 0x00000000000000000000000000000000;
                s_data(255, 128) = 0x00000000000000000000000000000000;
                s_data(383, 256) = 0x00000000000000000000000000000000;
                s_data(511, 384) = 0x00000000000000000000000000000000;
            }

            s_data_out.write(s_data);
        }

    }
}