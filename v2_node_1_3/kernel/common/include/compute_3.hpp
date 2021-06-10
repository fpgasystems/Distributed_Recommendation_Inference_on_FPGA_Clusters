#include <hls_stream.h>
#include "constants_3.hpp"

void load_access_idx(
    hls::stream<int>& s_idx_buffer_HBM0, hls::stream<int>& s_idx_buffer_HBM1, 
    hls::stream<int>& s_idx_buffer_HBM2, hls::stream<int>& s_idx_buffer_HBM3, 
    hls::stream<int>& s_idx_buffer_HBM4, hls::stream<int>& s_idx_buffer_HBM5, 
    hls::stream<int>& s_idx_buffer_HBM6, hls::stream<int>& s_idx_buffer_HBM7, 
    hls::stream<int>& s_idx_buffer_HBM8, hls::stream<int>& s_idx_buffer_HBM9, 
    hls::stream<int>& s_idx_buffer_HBM10, hls::stream<int>& s_idx_buffer_HBM11, 
    hls::stream<int>& s_idx_buffer_HBM12, hls::stream<int>& s_idx_buffer_HBM13, 
    hls::stream<int>& s_idx_buffer_HBM14, hls::stream<int>& s_idx_buffer_HBM15, 
    hls::stream<int>& s_idx_buffer_HBM16, hls::stream<int>& s_idx_buffer_HBM17, 
    hls::stream<int>& s_idx_buffer_HBM18, hls::stream<int>& s_idx_buffer_HBM19, 
    hls::stream<int>& s_idx_buffer_HBM20, hls::stream<int>& s_idx_buffer_HBM21, 
    hls::stream<int>& s_idx_buffer_HBM22, hls::stream<int>& s_idx_buffer_HBM23, 
    hls::stream<int>& s_idx_buffer_HBM24, hls::stream<int>& s_idx_buffer_HBM25, 
    hls::stream<int>& s_idx_buffer_HBM26, hls::stream<int>& s_idx_buffer_HBM27);

template<
    const int START_ADDR_0, const int AXI_PADDED_SIZE_0, 
    const int START_ADDR_1, const int AXI_PADDED_SIZE_1>
void load_single_embedding_2_tables(
    hls::stream<int>& s_idx_buffer, const t_axi* table_RAM, 
    hls::stream<t_axi>& s_embedding_buffer);
    
template<typename T, const int VECTOR_LENGTH>
void int_to_wide(
    hls::stream<T>& s_embedding_buffer, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide);

void gather_embeddings(
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM0, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM1, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM2, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM3, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM4, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM5, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM6, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM7, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM8, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM9, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM10, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM11, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM12, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM13, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM14, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM15, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM16, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM17, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM18, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM19, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM20, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM21, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM22, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM23, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM24, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM25, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM26, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM27, 
    hls::stream<W_TYPE>& s_feature_in
);

template<const int FEATURE_SIZE, const int ROW_PER_PE>
void matmul_PE_UNROLL8(
    hls::stream<W_TYPE>& s_feature_PE,
    hls::stream<D_TYPE>& s_result_PE);

template<const int FEATURE_SIZE, const int ROW_PER_PE>
void init_weights(W_TYPE* weights_transpose); 

template<const int FEATURE_SIZE>
void replicate_feature_512PEs_200PE(
    hls::stream<W_TYPE>& s_feature_in, 
    hls::stream<W_TYPE>& s_embedding_table,
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
    hls::stream<W_TYPE>& s_feature_PE198, hls::stream<W_TYPE>& s_feature_PE199
);
    
template<const int ROW_PER_PE>
void gather_results_512PEs_200PE(
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
    hls::stream<W_TYPE>& s_result_all);

void dataTransform(hls::stream<W_TYPE>& s_embedding_table, hls::stream<W_TYPE> & s_result_all, hls::stream<ap_uint<512> > & s_data_in);

void dataTransform_writeResult(hls::stream<W_TYPE>& s_embedding_table, hls::stream<W_TYPE> & s_result_all, hls::stream<ap_uint<512> > & s_data_in, D_TYPE results_out[HIDDEN_SIZE1_PARTIAL]);


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

const int depth_s_embedding_buffer_wide_HBM0 = VECTOR_SIZE_HBM_BANK_0 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM1 = VECTOR_SIZE_HBM_BANK_1 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM2 = VECTOR_SIZE_HBM_BANK_2 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM3 = VECTOR_SIZE_HBM_BANK_3 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM4 = VECTOR_SIZE_HBM_BANK_4 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM5 = VECTOR_SIZE_HBM_BANK_5 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM6 = VECTOR_SIZE_HBM_BANK_6 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM7 = VECTOR_SIZE_HBM_BANK_7 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM8 = VECTOR_SIZE_HBM_BANK_8 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM9 = VECTOR_SIZE_HBM_BANK_9 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM10 = VECTOR_SIZE_HBM_BANK_10 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM11 = VECTOR_SIZE_HBM_BANK_11 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM12 = VECTOR_SIZE_HBM_BANK_12 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM13 = VECTOR_SIZE_HBM_BANK_13 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM14 = VECTOR_SIZE_HBM_BANK_14 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM15 = VECTOR_SIZE_HBM_BANK_15 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM16 = VECTOR_SIZE_HBM_BANK_16 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM17 = VECTOR_SIZE_HBM_BANK_17 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM18 = VECTOR_SIZE_HBM_BANK_18 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM19 = VECTOR_SIZE_HBM_BANK_19 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM20 = VECTOR_SIZE_HBM_BANK_20 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM21 = VECTOR_SIZE_HBM_BANK_21 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM22 = VECTOR_SIZE_HBM_BANK_22 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM23 = VECTOR_SIZE_HBM_BANK_23 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM24 = VECTOR_SIZE_HBM_BANK_24 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM25 = VECTOR_SIZE_HBM_BANK_25 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM26 = VECTOR_SIZE_HBM_BANK_26 * FIFO_BATCH_SIZE / INTS_PER_W;
const int depth_s_embedding_buffer_wide_HBM27 = VECTOR_SIZE_HBM_BANK_27 * FIFO_BATCH_SIZE / INTS_PER_W;


void load_access_idx(
    hls::stream<int>& s_idx_buffer_HBM0, hls::stream<int>& s_idx_buffer_HBM1, 
    hls::stream<int>& s_idx_buffer_HBM2, hls::stream<int>& s_idx_buffer_HBM3, 
    hls::stream<int>& s_idx_buffer_HBM4, hls::stream<int>& s_idx_buffer_HBM5, 
    hls::stream<int>& s_idx_buffer_HBM6, hls::stream<int>& s_idx_buffer_HBM7, 
    hls::stream<int>& s_idx_buffer_HBM8, hls::stream<int>& s_idx_buffer_HBM9, 
    hls::stream<int>& s_idx_buffer_HBM10, hls::stream<int>& s_idx_buffer_HBM11, 
    hls::stream<int>& s_idx_buffer_HBM12, hls::stream<int>& s_idx_buffer_HBM13, 
    hls::stream<int>& s_idx_buffer_HBM14, hls::stream<int>& s_idx_buffer_HBM15, 
    hls::stream<int>& s_idx_buffer_HBM16, hls::stream<int>& s_idx_buffer_HBM17, 
    hls::stream<int>& s_idx_buffer_HBM18, hls::stream<int>& s_idx_buffer_HBM19, 
    hls::stream<int>& s_idx_buffer_HBM20, hls::stream<int>& s_idx_buffer_HBM21, 
    hls::stream<int>& s_idx_buffer_HBM22, hls::stream<int>& s_idx_buffer_HBM23, 
    hls::stream<int>& s_idx_buffer_HBM24, hls::stream<int>& s_idx_buffer_HBM25, 
    hls::stream<int>& s_idx_buffer_HBM26, hls::stream<int>& s_idx_buffer_HBM27) { 

    int idx_HBM0, idx_HBM1, idx_HBM2, idx_HBM3, 
        idx_HBM4, idx_HBM5, idx_HBM6, idx_HBM7, 
        idx_HBM8, idx_HBM9, idx_HBM10, idx_HBM11, 
        idx_HBM12, idx_HBM13, idx_HBM14, idx_HBM15, 
        idx_HBM16, idx_HBM17, idx_HBM18, idx_HBM19, 
        idx_HBM20, idx_HBM21, idx_HBM22, idx_HBM23, 
        idx_HBM24, idx_HBM25, idx_HBM26, idx_HBM27;

    // batch = 32
    int idx_random[] = {3, 99, 38, 72, 29, 57, 1, 72, 36, 76, 35, 50, 37, 57, 
        13, 66, 26, 70, 41, 93, 48, 82, 44, 78, 25, 52, 3, 92, 36, 56, 46, 88};

    for (int i = 0; i < BATCH_NUM; i++) {
        
        for (int j = 0; j < BATCH_SIZE; j++) {
            #pragma HLS pipeline II=1

            int idx = idx_random[j];

            s_idx_buffer_HBM0.write(idx);
            s_idx_buffer_HBM1.write(idx);
            s_idx_buffer_HBM2.write(idx);
            s_idx_buffer_HBM3.write(idx);
            s_idx_buffer_HBM4.write(idx);
            s_idx_buffer_HBM5.write(idx);
            s_idx_buffer_HBM6.write(idx);
            s_idx_buffer_HBM7.write(idx);
            s_idx_buffer_HBM8.write(idx);
            s_idx_buffer_HBM9.write(idx);
            s_idx_buffer_HBM10.write(idx);
            s_idx_buffer_HBM11.write(idx);
            s_idx_buffer_HBM12.write(idx);
            s_idx_buffer_HBM13.write(idx);
            s_idx_buffer_HBM14.write(idx);
            s_idx_buffer_HBM15.write(idx);
            s_idx_buffer_HBM16.write(idx);
            s_idx_buffer_HBM17.write(idx);
            s_idx_buffer_HBM18.write(idx);
            s_idx_buffer_HBM19.write(idx);
            s_idx_buffer_HBM20.write(idx);
            s_idx_buffer_HBM21.write(idx);
            s_idx_buffer_HBM22.write(idx);
            s_idx_buffer_HBM23.write(idx);
            s_idx_buffer_HBM24.write(idx);
            s_idx_buffer_HBM25.write(idx);
            s_idx_buffer_HBM26.write(idx);
            s_idx_buffer_HBM27.write(idx);
        }
    }
}

template<
    const int START_ADDR_0, const int AXI_PADDED_SIZE_0, 
    const int START_ADDR_1, const int AXI_PADDED_SIZE_1>
void load_single_embedding_2_tables(
    hls::stream<int>& s_idx_buffer, const t_axi* table_RAM, 
    hls::stream<t_axi>& s_embedding_buffer) {
#pragma HLS INLINE off

    // 8 < data size <= 16, load 2 times
    for (int i = 0; i < BATCH_NUM * BATCH_SIZE; i++) {
        #pragma HLS LOOP_TRIPCOUNT min=trip_count_item_num max=trip_count_item_num

        int idx =  s_idx_buffer.read();

        int base_addr_0 = START_ADDR_0 + idx * AXI_PADDED_SIZE_0;
        for (int j = 0; j < AXI_PADDED_SIZE_0; j++) {
            #pragma HLS pipeline II=1
            s_embedding_buffer.write(table_RAM[base_addr_0 + j]);
        }
        int base_addr_1 = START_ADDR_1 + idx * AXI_PADDED_SIZE_1;
        for (int j = 0; j < AXI_PADDED_SIZE_1; j++) {
            #pragma HLS pipeline II=1
            s_embedding_buffer.write(table_RAM[base_addr_1 + j]);
        }
    }
}


template<typename T, const int VECTOR_LENGTH>
void int_to_wide(
    hls::stream<T>& s_embedding_buffer, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide) {
#pragma HLS inline off

    for (int i = 0; i < BATCH_NUM * BATCH_SIZE; i++) {
        #pragma HLS LOOP_TRIPCOUNT min=trip_count_item_num max=trip_count_item_num

        for (int j = 0; j < VECTOR_LENGTH / INTS_PER_W; j++) {
            #pragma HLS pipeline II=8
            W_TYPE reg;
            reg.range(31, 0) = s_embedding_buffer.read();
            reg.range(63, 32) = s_embedding_buffer.read();
            reg.range(95, 64) = s_embedding_buffer.read();
            reg.range(127, 96) = s_embedding_buffer.read();

            reg.range(159, 128) = s_embedding_buffer.read();
            reg.range(191, 160) = s_embedding_buffer.read();
            reg.range(223, 192) = s_embedding_buffer.read();
            reg.range(255, 224) = s_embedding_buffer.read();

            s_embedding_buffer_wide.write(reg);
        }
    }
}

void gather_embeddings(
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM0, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM1, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM2, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM3, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM4, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM5, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM6, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM7, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM8, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM9, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM10, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM11, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM12, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM13, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM14, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM15, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM16, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM17, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM18, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM19, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM20, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM21, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM22, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM23, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM24, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM25, 
    hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM26, hls::stream<W_TYPE>& s_embedding_buffer_wide_HBM27, 
    hls::stream<W_TYPE>& s_feature_in
) {
#pragma HLS inline off

    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_0 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM0.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_1 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM1.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_2 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM2.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_3 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM3.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_4 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM4.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_5 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM5.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_6 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM6.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_7 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM7.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_8 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM8.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_9 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM9.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_10 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM10.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_11 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM11.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_12 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM12.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_13 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM13.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_14 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM14.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_15 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM15.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_16 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM16.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_17 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM17.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_18 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM18.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_19 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM19.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_20 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM20.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_21 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM21.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_22 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM22.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_23 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM23.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_24 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM24.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_25 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM25.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_26 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM26.read());
        }
        for (int i = 0; i < VECTOR_SIZE_HBM_BANK_27 / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            s_feature_in.write(s_embedding_buffer_wide_HBM27.read());
        }
    }
}

template<const int FEATURE_SIZE>
void replicate_feature_512PEs_200PE(
    hls::stream<W_TYPE>& s_feature_in, 
    hls::stream<W_TYPE>& s_embedding_table,
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
    hls::stream<W_TYPE>& s_feature_PE198, hls::stream<W_TYPE>& s_feature_PE199
) {

    for (int i = 0; i < BATCH_NUM * BATCH_SIZE * FEATURE_SIZE / INTS_PER_W; i++) {
        #pragma HLS pipeline II=1

        W_TYPE reg = s_feature_in.read();

        s_embedding_table.write(reg);

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
    }
}

template<const int FEATURE_SIZE, const int ROW_PER_PE>
void matmul_PE_UNROLL8(
    hls::stream<W_TYPE>& s_feature_PE,
    hls::stream<D_TYPE>& s_result_PE) {
#pragma HLS inline off
    // store weights to local at the beginning
    // transpose the weights as well -> e.g., 
    //     orginal weights (row_size, COL_PER_PE)
    //     now: (COL_PER_PE, row_size)
    // so that the dot product is more natural -> 
    //     feature x row0, feature x row1, ...
    W_TYPE weights_transpose_local[ROW_PER_PE * FEATURE_SIZE / INTS_PER_W];
    W_TYPE feature_local[FEATURE_SIZE / INTS_PER_W];
#pragma HLS resource variable=weights_transpose_local core=RAM_2P_URAM

    init_weights<FEATURE_SIZE, ROW_PER_PE>(weights_transpose_local);

    item_loop:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        // read 
        read_loop:
        for (int i = 0; i < FEATURE_SIZE / INTS_PER_W; i++) {
            #pragma HLS pipeline II=1
            feature_local[i] = s_feature_PE.read();
        }
        // compute and write
        row_loop:
        for (int result_idx = 0; result_idx < ROW_PER_PE; result_idx++) {
            
            D_TYPE result = 0;
            dot_product:
            // NOTE: manually unroll 2 here
            for (int d = 0; d < FEATURE_SIZE / INTS_PER_W / 2; d++) {
                // #pragma HLS unroll factor=4
                for (int i = 0; i < 2; i++){
                    #pragma HLS pipeline II=1
                    ap_int<128> reg_f_0 = feature_local[2 * d].range(128*i+127, 128*i);
                    ap_int<128> reg_f_1 = feature_local[2 * d + 1].range(128*i+127, 128*i);;
                    ap_int<128> reg_w_0 = weights_transpose_local[
                        result_idx * FEATURE_SIZE / INTS_PER_W + 2 * d].range(128*i+127, 128*i);;
                    ap_int<128> reg_w_1 = weights_transpose_local[
                        result_idx * FEATURE_SIZE / INTS_PER_W + 2 * d + 1].range(128*i+127, 128*i);;

                    D_TYPE f_0_0 = reg_f_0.range(31, 0);   
                    D_TYPE f_0_1 = reg_f_0.range(63, 32); 
                    D_TYPE f_0_2 = reg_f_0.range(95, 64);   
                    D_TYPE f_0_3 = reg_f_0.range(127, 96);  

                    D_TYPE f_1_0 = reg_f_1.range(31, 0);   
                    D_TYPE f_1_1 = reg_f_1.range(63, 32); 
                    D_TYPE f_1_2 = reg_f_1.range(95, 64);   
                    D_TYPE f_1_3 = reg_f_1.range(127, 96);  

                    D_TYPE w_0_0 = reg_w_0.range(31, 0);   
                    D_TYPE w_0_1 = reg_w_0.range(63, 32); 
                    D_TYPE w_0_2 = reg_w_0.range(95, 64);   
                    D_TYPE w_0_3 = reg_w_0.range(127, 96);  

                    D_TYPE w_1_0 = reg_w_1.range(31, 0);   
                    D_TYPE w_1_1 = reg_w_1.range(63, 32); 
                    D_TYPE w_1_2 = reg_w_1.range(95, 64);   
                    D_TYPE w_1_3 = reg_w_1.range(127, 96);  

                    result += 
                        f_0_0  * w_0_0  + f_0_1  * w_0_1  + 
                        f_0_2  * w_0_2  + f_0_3  * w_0_3  +
                        f_1_0  * w_1_0  + f_1_1  * w_1_1  + 
                        f_1_2  * w_1_2  + f_1_3  * w_1_3;
                }
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
            reg_even.range(31, 0)   = row_template_even[INTS_PER_W * i];
            reg_even.range(63, 32)  = row_template_even[INTS_PER_W * i + 1];
            reg_even.range(95, 64)  = row_template_even[INTS_PER_W * i + 2];
            reg_even.range(127, 96) = row_template_even[INTS_PER_W * i + 3];

            reg_even.range(159, 128) = row_template_even[INTS_PER_W * i + 4];
            reg_even.range(191, 160) = row_template_even[INTS_PER_W * i + 5];
            reg_even.range(223, 192) = row_template_even[INTS_PER_W * i + 6];
            reg_even.range(255, 224) = row_template_even[INTS_PER_W * i + 7];

            reg_odd.range(31, 0)   = row_template_odd[INTS_PER_W * i];
            reg_odd.range(63, 32)  = row_template_odd[INTS_PER_W * i + 1];
            reg_odd.range(95, 64)  = row_template_odd[INTS_PER_W * i + 2];
            reg_odd.range(127, 96) = row_template_odd[INTS_PER_W * i + 3];

            reg_odd.range(159, 128) = row_template_odd[INTS_PER_W * i + 4];
            reg_odd.range(191, 160) = row_template_odd[INTS_PER_W * i + 5];
            reg_odd.range(223, 192) = row_template_odd[INTS_PER_W * i + 6];
            reg_odd.range(255, 224) = row_template_odd[INTS_PER_W * i + 7];

            weights_transpose_local[2 * row * INPUT_SIZE / INTS_PER_W + i] = reg_even;
            weights_transpose_local[(2 * row + 1) * INPUT_SIZE / INTS_PER_W + i] = reg_odd;
        }
    }
}


template<const int ROW_PER_PE>
void gather_results_512PEs_200PE(
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
    hls::stream<W_TYPE>& s_result_all) {
     
    for_each_item:
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        #pragma HLS pipeline II=50  // write 1 result_all per CC

        W_TYPE reg0, reg1, reg2, reg3, reg4, reg5, reg6, reg7, 
            reg8, reg9, reg10, reg11, reg12, reg13, reg14, reg15, 
            reg16, reg17, reg18, reg19, reg20, reg21, reg22, reg23, 
            reg24, reg25, reg26, reg27, reg28, reg29, reg30, reg31, 
            reg32, reg33, reg34, reg35, reg36, reg37, reg38, reg39, 
            reg40, reg41, reg42, reg43, reg44, reg45, reg46, reg47, 
            reg48, reg49;

        reg0.range(31, 0) = s_result_PE0.read() + 1;
        reg0.range(63, 32) = s_result_PE0.read() + 1;
        reg0.range(95, 64) = s_result_PE1.read() + 1;
        reg0.range(127, 96) = s_result_PE1.read() + 1;
        reg0.range(159, 128) = s_result_PE2.read() + 1;
        reg0.range(191, 160) = s_result_PE2.read() + 1;
        reg0.range(223, 192) = s_result_PE3.read() + 1;
        reg0.range(255, 224) = s_result_PE3.read() + 1;
        s_result_all.write(reg0);

        reg1.range(31, 0) = s_result_PE4.read() + 1;
        reg1.range(63, 32) = s_result_PE4.read() + 1;
        reg1.range(95, 64) = s_result_PE5.read() + 1;
        reg1.range(127, 96) = s_result_PE5.read() + 1;
        reg1.range(159, 128) = s_result_PE6.read() + 1;
        reg1.range(191, 160) = s_result_PE6.read() + 1;
        reg1.range(223, 192) = s_result_PE7.read() + 1;
        reg1.range(255, 224) = s_result_PE7.read() + 1;
        s_result_all.write(reg1);

        reg2.range(31, 0) = s_result_PE8.read() + 1;
        reg2.range(63, 32) = s_result_PE8.read() + 1;
        reg2.range(95, 64) = s_result_PE9.read() + 1;
        reg2.range(127, 96) = s_result_PE9.read() + 1;
        reg2.range(159, 128) = s_result_PE10.read() + 1;
        reg2.range(191, 160) = s_result_PE10.read() + 1;
        reg2.range(223, 192) = s_result_PE11.read() + 1;
        reg2.range(255, 224) = s_result_PE11.read() + 1;
        s_result_all.write(reg2);

        reg3.range(31, 0) = s_result_PE12.read() + 1;
        reg3.range(63, 32) = s_result_PE12.read() + 1;
        reg3.range(95, 64) = s_result_PE13.read() + 1;
        reg3.range(127, 96) = s_result_PE13.read() + 1;
        reg3.range(159, 128) = s_result_PE14.read() + 1;
        reg3.range(191, 160) = s_result_PE14.read() + 1;
        reg3.range(223, 192) = s_result_PE15.read() + 1;
        reg3.range(255, 224) = s_result_PE15.read() + 1;
        s_result_all.write(reg3);

        reg4.range(31, 0) = s_result_PE16.read() + 1;
        reg4.range(63, 32) = s_result_PE16.read() + 1;
        reg4.range(95, 64) = s_result_PE17.read() + 1;
        reg4.range(127, 96) = s_result_PE17.read() + 1;
        reg4.range(159, 128) = s_result_PE18.read() + 1;
        reg4.range(191, 160) = s_result_PE18.read() + 1;
        reg4.range(223, 192) = s_result_PE19.read() + 1;
        reg4.range(255, 224) = s_result_PE19.read() + 1;
        s_result_all.write(reg4);

        reg5.range(31, 0) = s_result_PE20.read() + 1;
        reg5.range(63, 32) = s_result_PE20.read() + 1;
        reg5.range(95, 64) = s_result_PE21.read() + 1;
        reg5.range(127, 96) = s_result_PE21.read() + 1;
        reg5.range(159, 128) = s_result_PE22.read() + 1;
        reg5.range(191, 160) = s_result_PE22.read() + 1;
        reg5.range(223, 192) = s_result_PE23.read() + 1;
        reg5.range(255, 224) = s_result_PE23.read() + 1;
        s_result_all.write(reg5);

        reg6.range(31, 0) = s_result_PE24.read() + 1;
        reg6.range(63, 32) = s_result_PE24.read() + 1;
        reg6.range(95, 64) = s_result_PE25.read() + 1;
        reg6.range(127, 96) = s_result_PE25.read() + 1;
        reg6.range(159, 128) = s_result_PE26.read() + 1;
        reg6.range(191, 160) = s_result_PE26.read() + 1;
        reg6.range(223, 192) = s_result_PE27.read() + 1;
        reg6.range(255, 224) = s_result_PE27.read() + 1;
        s_result_all.write(reg6);

        reg7.range(31, 0) = s_result_PE28.read() + 1;
        reg7.range(63, 32) = s_result_PE28.read() + 1;
        reg7.range(95, 64) = s_result_PE29.read() + 1;
        reg7.range(127, 96) = s_result_PE29.read() + 1;
        reg7.range(159, 128) = s_result_PE30.read() + 1;
        reg7.range(191, 160) = s_result_PE30.read() + 1;
        reg7.range(223, 192) = s_result_PE31.read() + 1;
        reg7.range(255, 224) = s_result_PE31.read() + 1;
        s_result_all.write(reg7);

        reg8.range(31, 0) = s_result_PE32.read() + 1;
        reg8.range(63, 32) = s_result_PE32.read() + 1;
        reg8.range(95, 64) = s_result_PE33.read() + 1;
        reg8.range(127, 96) = s_result_PE33.read() + 1;
        reg8.range(159, 128) = s_result_PE34.read() + 1;
        reg8.range(191, 160) = s_result_PE34.read() + 1;
        reg8.range(223, 192) = s_result_PE35.read() + 1;
        reg8.range(255, 224) = s_result_PE35.read() + 1;
        s_result_all.write(reg8);

        reg9.range(31, 0) = s_result_PE36.read() + 1;
        reg9.range(63, 32) = s_result_PE36.read() + 1;
        reg9.range(95, 64) = s_result_PE37.read() + 1;
        reg9.range(127, 96) = s_result_PE37.read() + 1;
        reg9.range(159, 128) = s_result_PE38.read() + 1;
        reg9.range(191, 160) = s_result_PE38.read() + 1;
        reg9.range(223, 192) = s_result_PE39.read() + 1;
        reg9.range(255, 224) = s_result_PE39.read() + 1;
        s_result_all.write(reg9);

        reg10.range(31, 0) = s_result_PE40.read() + 1;
        reg10.range(63, 32) = s_result_PE40.read() + 1;
        reg10.range(95, 64) = s_result_PE41.read() + 1;
        reg10.range(127, 96) = s_result_PE41.read() + 1;
        reg10.range(159, 128) = s_result_PE42.read() + 1;
        reg10.range(191, 160) = s_result_PE42.read() + 1;
        reg10.range(223, 192) = s_result_PE43.read() + 1;
        reg10.range(255, 224) = s_result_PE43.read() + 1;
        s_result_all.write(reg10);

        reg11.range(31, 0) = s_result_PE44.read() + 1;
        reg11.range(63, 32) = s_result_PE44.read() + 1;
        reg11.range(95, 64) = s_result_PE45.read() + 1;
        reg11.range(127, 96) = s_result_PE45.read() + 1;
        reg11.range(159, 128) = s_result_PE46.read() + 1;
        reg11.range(191, 160) = s_result_PE46.read() + 1;
        reg11.range(223, 192) = s_result_PE47.read() + 1;
        reg11.range(255, 224) = s_result_PE47.read() + 1;
        s_result_all.write(reg11);

        reg12.range(31, 0) = s_result_PE48.read() + 1;
        reg12.range(63, 32) = s_result_PE48.read() + 1;
        reg12.range(95, 64) = s_result_PE49.read() + 1;
        reg12.range(127, 96) = s_result_PE49.read() + 1;
        reg12.range(159, 128) = s_result_PE50.read() + 1;
        reg12.range(191, 160) = s_result_PE50.read() + 1;
        reg12.range(223, 192) = s_result_PE51.read() + 1;
        reg12.range(255, 224) = s_result_PE51.read() + 1;
        s_result_all.write(reg12);

        reg13.range(31, 0) = s_result_PE52.read() + 1;
        reg13.range(63, 32) = s_result_PE52.read() + 1;
        reg13.range(95, 64) = s_result_PE53.read() + 1;
        reg13.range(127, 96) = s_result_PE53.read() + 1;
        reg13.range(159, 128) = s_result_PE54.read() + 1;
        reg13.range(191, 160) = s_result_PE54.read() + 1;
        reg13.range(223, 192) = s_result_PE55.read() + 1;
        reg13.range(255, 224) = s_result_PE55.read() + 1;
        s_result_all.write(reg13);

        reg14.range(31, 0) = s_result_PE56.read() + 1;
        reg14.range(63, 32) = s_result_PE56.read() + 1;
        reg14.range(95, 64) = s_result_PE57.read() + 1;
        reg14.range(127, 96) = s_result_PE57.read() + 1;
        reg14.range(159, 128) = s_result_PE58.read() + 1;
        reg14.range(191, 160) = s_result_PE58.read() + 1;
        reg14.range(223, 192) = s_result_PE59.read() + 1;
        reg14.range(255, 224) = s_result_PE59.read() + 1;
        s_result_all.write(reg14);

        reg15.range(31, 0) = s_result_PE60.read() + 1;
        reg15.range(63, 32) = s_result_PE60.read() + 1;
        reg15.range(95, 64) = s_result_PE61.read() + 1;
        reg15.range(127, 96) = s_result_PE61.read() + 1;
        reg15.range(159, 128) = s_result_PE62.read() + 1;
        reg15.range(191, 160) = s_result_PE62.read() + 1;
        reg15.range(223, 192) = s_result_PE63.read() + 1;
        reg15.range(255, 224) = s_result_PE63.read() + 1;
        s_result_all.write(reg15);

        reg16.range(31, 0) = s_result_PE64.read() + 1;
        reg16.range(63, 32) = s_result_PE64.read() + 1;
        reg16.range(95, 64) = s_result_PE65.read() + 1;
        reg16.range(127, 96) = s_result_PE65.read() + 1;
        reg16.range(159, 128) = s_result_PE66.read() + 1;
        reg16.range(191, 160) = s_result_PE66.read() + 1;
        reg16.range(223, 192) = s_result_PE67.read() + 1;
        reg16.range(255, 224) = s_result_PE67.read() + 1;
        s_result_all.write(reg16);

        reg17.range(31, 0) = s_result_PE68.read() + 1;
        reg17.range(63, 32) = s_result_PE68.read() + 1;
        reg17.range(95, 64) = s_result_PE69.read() + 1;
        reg17.range(127, 96) = s_result_PE69.read() + 1;
        reg17.range(159, 128) = s_result_PE70.read() + 1;
        reg17.range(191, 160) = s_result_PE70.read() + 1;
        reg17.range(223, 192) = s_result_PE71.read() + 1;
        reg17.range(255, 224) = s_result_PE71.read() + 1;
        s_result_all.write(reg17);

        reg18.range(31, 0) = s_result_PE72.read() + 1;
        reg18.range(63, 32) = s_result_PE72.read() + 1;
        reg18.range(95, 64) = s_result_PE73.read() + 1;
        reg18.range(127, 96) = s_result_PE73.read() + 1;
        reg18.range(159, 128) = s_result_PE74.read() + 1;
        reg18.range(191, 160) = s_result_PE74.read() + 1;
        reg18.range(223, 192) = s_result_PE75.read() + 1;
        reg18.range(255, 224) = s_result_PE75.read() + 1;
        s_result_all.write(reg18);

        reg19.range(31, 0) = s_result_PE76.read() + 1;
        reg19.range(63, 32) = s_result_PE76.read() + 1;
        reg19.range(95, 64) = s_result_PE77.read() + 1;
        reg19.range(127, 96) = s_result_PE77.read() + 1;
        reg19.range(159, 128) = s_result_PE78.read() + 1;
        reg19.range(191, 160) = s_result_PE78.read() + 1;
        reg19.range(223, 192) = s_result_PE79.read() + 1;
        reg19.range(255, 224) = s_result_PE79.read() + 1;
        s_result_all.write(reg19);

        reg20.range(31, 0) = s_result_PE80.read() + 1;
        reg20.range(63, 32) = s_result_PE80.read() + 1;
        reg20.range(95, 64) = s_result_PE81.read() + 1;
        reg20.range(127, 96) = s_result_PE81.read() + 1;
        reg20.range(159, 128) = s_result_PE82.read() + 1;
        reg20.range(191, 160) = s_result_PE82.read() + 1;
        reg20.range(223, 192) = s_result_PE83.read() + 1;
        reg20.range(255, 224) = s_result_PE83.read() + 1;
        s_result_all.write(reg20);

        reg21.range(31, 0) = s_result_PE84.read() + 1;
        reg21.range(63, 32) = s_result_PE84.read() + 1;
        reg21.range(95, 64) = s_result_PE85.read() + 1;
        reg21.range(127, 96) = s_result_PE85.read() + 1;
        reg21.range(159, 128) = s_result_PE86.read() + 1;
        reg21.range(191, 160) = s_result_PE86.read() + 1;
        reg21.range(223, 192) = s_result_PE87.read() + 1;
        reg21.range(255, 224) = s_result_PE87.read() + 1;
        s_result_all.write(reg21);

        reg22.range(31, 0) = s_result_PE88.read() + 1;
        reg22.range(63, 32) = s_result_PE88.read() + 1;
        reg22.range(95, 64) = s_result_PE89.read() + 1;
        reg22.range(127, 96) = s_result_PE89.read() + 1;
        reg22.range(159, 128) = s_result_PE90.read() + 1;
        reg22.range(191, 160) = s_result_PE90.read() + 1;
        reg22.range(223, 192) = s_result_PE91.read() + 1;
        reg22.range(255, 224) = s_result_PE91.read() + 1;
        s_result_all.write(reg22);

        reg23.range(31, 0) = s_result_PE92.read() + 1;
        reg23.range(63, 32) = s_result_PE92.read() + 1;
        reg23.range(95, 64) = s_result_PE93.read() + 1;
        reg23.range(127, 96) = s_result_PE93.read() + 1;
        reg23.range(159, 128) = s_result_PE94.read() + 1;
        reg23.range(191, 160) = s_result_PE94.read() + 1;
        reg23.range(223, 192) = s_result_PE95.read() + 1;
        reg23.range(255, 224) = s_result_PE95.read() + 1;
        s_result_all.write(reg23);

        reg24.range(31, 0) = s_result_PE96.read() + 1;
        reg24.range(63, 32) = s_result_PE96.read() + 1;
        reg24.range(95, 64) = s_result_PE97.read() + 1;
        reg24.range(127, 96) = s_result_PE97.read() + 1;
        reg24.range(159, 128) = s_result_PE98.read() + 1;
        reg24.range(191, 160) = s_result_PE98.read() + 1;
        reg24.range(223, 192) = s_result_PE99.read() + 1;
        reg24.range(255, 224) = s_result_PE99.read() + 1;
        s_result_all.write(reg24);

        reg25.range(31, 0) = s_result_PE100.read() + 1;
        reg25.range(63, 32) = s_result_PE100.read() + 1;
        reg25.range(95, 64) = s_result_PE101.read() + 1;
        reg25.range(127, 96) = s_result_PE101.read() + 1;
        reg25.range(159, 128) = s_result_PE102.read() + 1;
        reg25.range(191, 160) = s_result_PE102.read() + 1;
        reg25.range(223, 192) = s_result_PE103.read() + 1;
        reg25.range(255, 224) = s_result_PE103.read() + 1;
        s_result_all.write(reg25);

        reg26.range(31, 0) = s_result_PE104.read() + 1;
        reg26.range(63, 32) = s_result_PE104.read() + 1;
        reg26.range(95, 64) = s_result_PE105.read() + 1;
        reg26.range(127, 96) = s_result_PE105.read() + 1;
        reg26.range(159, 128) = s_result_PE106.read() + 1;
        reg26.range(191, 160) = s_result_PE106.read() + 1;
        reg26.range(223, 192) = s_result_PE107.read() + 1;
        reg26.range(255, 224) = s_result_PE107.read() + 1;
        s_result_all.write(reg26);

        reg27.range(31, 0) = s_result_PE108.read() + 1;
        reg27.range(63, 32) = s_result_PE108.read() + 1;
        reg27.range(95, 64) = s_result_PE109.read() + 1;
        reg27.range(127, 96) = s_result_PE109.read() + 1;
        reg27.range(159, 128) = s_result_PE110.read() + 1;
        reg27.range(191, 160) = s_result_PE110.read() + 1;
        reg27.range(223, 192) = s_result_PE111.read() + 1;
        reg27.range(255, 224) = s_result_PE111.read() + 1;
        s_result_all.write(reg27);

        reg28.range(31, 0) = s_result_PE112.read() + 1;
        reg28.range(63, 32) = s_result_PE112.read() + 1;
        reg28.range(95, 64) = s_result_PE113.read() + 1;
        reg28.range(127, 96) = s_result_PE113.read() + 1;
        reg28.range(159, 128) = s_result_PE114.read() + 1;
        reg28.range(191, 160) = s_result_PE114.read() + 1;
        reg28.range(223, 192) = s_result_PE115.read() + 1;
        reg28.range(255, 224) = s_result_PE115.read() + 1;
        s_result_all.write(reg28);

        reg29.range(31, 0) = s_result_PE116.read() + 1;
        reg29.range(63, 32) = s_result_PE116.read() + 1;
        reg29.range(95, 64) = s_result_PE117.read() + 1;
        reg29.range(127, 96) = s_result_PE117.read() + 1;
        reg29.range(159, 128) = s_result_PE118.read() + 1;
        reg29.range(191, 160) = s_result_PE118.read() + 1;
        reg29.range(223, 192) = s_result_PE119.read() + 1;
        reg29.range(255, 224) = s_result_PE119.read() + 1;
        s_result_all.write(reg29);

        reg30.range(31, 0) = s_result_PE120.read() + 1;
        reg30.range(63, 32) = s_result_PE120.read() + 1;
        reg30.range(95, 64) = s_result_PE121.read() + 1;
        reg30.range(127, 96) = s_result_PE121.read() + 1;
        reg30.range(159, 128) = s_result_PE122.read() + 1;
        reg30.range(191, 160) = s_result_PE122.read() + 1;
        reg30.range(223, 192) = s_result_PE123.read() + 1;
        reg30.range(255, 224) = s_result_PE123.read() + 1;
        s_result_all.write(reg30);

        reg31.range(31, 0) = s_result_PE124.read() + 1;
        reg31.range(63, 32) = s_result_PE124.read() + 1;
        reg31.range(95, 64) = s_result_PE125.read() + 1;
        reg31.range(127, 96) = s_result_PE125.read() + 1;
        reg31.range(159, 128) = s_result_PE126.read() + 1;
        reg31.range(191, 160) = s_result_PE126.read() + 1;
        reg31.range(223, 192) = s_result_PE127.read() + 1;
        reg31.range(255, 224) = s_result_PE127.read() + 1;
        s_result_all.write(reg31);

        reg32.range(31, 0) = s_result_PE128.read() + 1;
        reg32.range(63, 32) = s_result_PE128.read() + 1;
        reg32.range(95, 64) = s_result_PE129.read() + 1;
        reg32.range(127, 96) = s_result_PE129.read() + 1;
        reg32.range(159, 128) = s_result_PE130.read() + 1;
        reg32.range(191, 160) = s_result_PE130.read() + 1;
        reg32.range(223, 192) = s_result_PE131.read() + 1;
        reg32.range(255, 224) = s_result_PE131.read() + 1;
        s_result_all.write(reg32);

        reg33.range(31, 0) = s_result_PE132.read() + 1;
        reg33.range(63, 32) = s_result_PE132.read() + 1;
        reg33.range(95, 64) = s_result_PE133.read() + 1;
        reg33.range(127, 96) = s_result_PE133.read() + 1;
        reg33.range(159, 128) = s_result_PE134.read() + 1;
        reg33.range(191, 160) = s_result_PE134.read() + 1;
        reg33.range(223, 192) = s_result_PE135.read() + 1;
        reg33.range(255, 224) = s_result_PE135.read() + 1;
        s_result_all.write(reg33);

        reg34.range(31, 0) = s_result_PE136.read() + 1;
        reg34.range(63, 32) = s_result_PE136.read() + 1;
        reg34.range(95, 64) = s_result_PE137.read() + 1;
        reg34.range(127, 96) = s_result_PE137.read() + 1;
        reg34.range(159, 128) = s_result_PE138.read() + 1;
        reg34.range(191, 160) = s_result_PE138.read() + 1;
        reg34.range(223, 192) = s_result_PE139.read() + 1;
        reg34.range(255, 224) = s_result_PE139.read() + 1;
        s_result_all.write(reg34);

        reg35.range(31, 0) = s_result_PE140.read() + 1;
        reg35.range(63, 32) = s_result_PE140.read() + 1;
        reg35.range(95, 64) = s_result_PE141.read() + 1;
        reg35.range(127, 96) = s_result_PE141.read() + 1;
        reg35.range(159, 128) = s_result_PE142.read() + 1;
        reg35.range(191, 160) = s_result_PE142.read() + 1;
        reg35.range(223, 192) = s_result_PE143.read() + 1;
        reg35.range(255, 224) = s_result_PE143.read() + 1;
        s_result_all.write(reg35);

        reg36.range(31, 0) = s_result_PE144.read() + 1;
        reg36.range(63, 32) = s_result_PE144.read() + 1;
        reg36.range(95, 64) = s_result_PE145.read() + 1;
        reg36.range(127, 96) = s_result_PE145.read() + 1;
        reg36.range(159, 128) = s_result_PE146.read() + 1;
        reg36.range(191, 160) = s_result_PE146.read() + 1;
        reg36.range(223, 192) = s_result_PE147.read() + 1;
        reg36.range(255, 224) = s_result_PE147.read() + 1;
        s_result_all.write(reg36);

        reg37.range(31, 0) = s_result_PE148.read() + 1;
        reg37.range(63, 32) = s_result_PE148.read() + 1;
        reg37.range(95, 64) = s_result_PE149.read() + 1;
        reg37.range(127, 96) = s_result_PE149.read() + 1;
        reg37.range(159, 128) = s_result_PE150.read() + 1;
        reg37.range(191, 160) = s_result_PE150.read() + 1;
        reg37.range(223, 192) = s_result_PE151.read() + 1;
        reg37.range(255, 224) = s_result_PE151.read() + 1;
        s_result_all.write(reg37);

        reg38.range(31, 0) = s_result_PE152.read() + 1;
        reg38.range(63, 32) = s_result_PE152.read() + 1;
        reg38.range(95, 64) = s_result_PE153.read() + 1;
        reg38.range(127, 96) = s_result_PE153.read() + 1;
        reg38.range(159, 128) = s_result_PE154.read() + 1;
        reg38.range(191, 160) = s_result_PE154.read() + 1;
        reg38.range(223, 192) = s_result_PE155.read() + 1;
        reg38.range(255, 224) = s_result_PE155.read() + 1;
        s_result_all.write(reg38);

        reg39.range(31, 0) = s_result_PE156.read() + 1;
        reg39.range(63, 32) = s_result_PE156.read() + 1;
        reg39.range(95, 64) = s_result_PE157.read() + 1;
        reg39.range(127, 96) = s_result_PE157.read() + 1;
        reg39.range(159, 128) = s_result_PE158.read() + 1;
        reg39.range(191, 160) = s_result_PE158.read() + 1;
        reg39.range(223, 192) = s_result_PE159.read() + 1;
        reg39.range(255, 224) = s_result_PE159.read() + 1;
        s_result_all.write(reg39);

        reg40.range(31, 0) = s_result_PE160.read() + 1;
        reg40.range(63, 32) = s_result_PE160.read() + 1;
        reg40.range(95, 64) = s_result_PE161.read() + 1;
        reg40.range(127, 96) = s_result_PE161.read() + 1;
        reg40.range(159, 128) = s_result_PE162.read() + 1;
        reg40.range(191, 160) = s_result_PE162.read() + 1;
        reg40.range(223, 192) = s_result_PE163.read() + 1;
        reg40.range(255, 224) = s_result_PE163.read() + 1;
        s_result_all.write(reg40);

        reg41.range(31, 0) = s_result_PE164.read() + 1;
        reg41.range(63, 32) = s_result_PE164.read() + 1;
        reg41.range(95, 64) = s_result_PE165.read() + 1;
        reg41.range(127, 96) = s_result_PE165.read() + 1;
        reg41.range(159, 128) = s_result_PE166.read() + 1;
        reg41.range(191, 160) = s_result_PE166.read() + 1;
        reg41.range(223, 192) = s_result_PE167.read() + 1;
        reg41.range(255, 224) = s_result_PE167.read() + 1;
        s_result_all.write(reg41);

        reg42.range(31, 0) = s_result_PE168.read() + 1;
        reg42.range(63, 32) = s_result_PE168.read() + 1;
        reg42.range(95, 64) = s_result_PE169.read() + 1;
        reg42.range(127, 96) = s_result_PE169.read() + 1;
        reg42.range(159, 128) = s_result_PE170.read() + 1;
        reg42.range(191, 160) = s_result_PE170.read() + 1;
        reg42.range(223, 192) = s_result_PE171.read() + 1;
        reg42.range(255, 224) = s_result_PE171.read() + 1;
        s_result_all.write(reg42);

        reg43.range(31, 0) = s_result_PE172.read() + 1;
        reg43.range(63, 32) = s_result_PE172.read() + 1;
        reg43.range(95, 64) = s_result_PE173.read() + 1;
        reg43.range(127, 96) = s_result_PE173.read() + 1;
        reg43.range(159, 128) = s_result_PE174.read() + 1;
        reg43.range(191, 160) = s_result_PE174.read() + 1;
        reg43.range(223, 192) = s_result_PE175.read() + 1;
        reg43.range(255, 224) = s_result_PE175.read() + 1;
        s_result_all.write(reg43);

        reg44.range(31, 0) = s_result_PE176.read() + 1;
        reg44.range(63, 32) = s_result_PE176.read() + 1;
        reg44.range(95, 64) = s_result_PE177.read() + 1;
        reg44.range(127, 96) = s_result_PE177.read() + 1;
        reg44.range(159, 128) = s_result_PE178.read() + 1;
        reg44.range(191, 160) = s_result_PE178.read() + 1;
        reg44.range(223, 192) = s_result_PE179.read() + 1;
        reg44.range(255, 224) = s_result_PE179.read() + 1;
        s_result_all.write(reg44);

        reg45.range(31, 0) = s_result_PE180.read() + 1;
        reg45.range(63, 32) = s_result_PE180.read() + 1;
        reg45.range(95, 64) = s_result_PE181.read() + 1;
        reg45.range(127, 96) = s_result_PE181.read() + 1;
        reg45.range(159, 128) = s_result_PE182.read() + 1;
        reg45.range(191, 160) = s_result_PE182.read() + 1;
        reg45.range(223, 192) = s_result_PE183.read() + 1;
        reg45.range(255, 224) = s_result_PE183.read() + 1;
        s_result_all.write(reg45);

        reg46.range(31, 0) = s_result_PE184.read() + 1;
        reg46.range(63, 32) = s_result_PE184.read() + 1;
        reg46.range(95, 64) = s_result_PE185.read() + 1;
        reg46.range(127, 96) = s_result_PE185.read() + 1;
        reg46.range(159, 128) = s_result_PE186.read() + 1;
        reg46.range(191, 160) = s_result_PE186.read() + 1;
        reg46.range(223, 192) = s_result_PE187.read() + 1;
        reg46.range(255, 224) = s_result_PE187.read() + 1;
        s_result_all.write(reg46);

        reg47.range(31, 0) = s_result_PE188.read() + 1;
        reg47.range(63, 32) = s_result_PE188.read() + 1;
        reg47.range(95, 64) = s_result_PE189.read() + 1;
        reg47.range(127, 96) = s_result_PE189.read() + 1;
        reg47.range(159, 128) = s_result_PE190.read() + 1;
        reg47.range(191, 160) = s_result_PE190.read() + 1;
        reg47.range(223, 192) = s_result_PE191.read() + 1;
        reg47.range(255, 224) = s_result_PE191.read() + 1;
        s_result_all.write(reg47);

        reg48.range(31, 0) = s_result_PE192.read() + 1;
        reg48.range(63, 32) = s_result_PE192.read() + 1;
        reg48.range(95, 64) = s_result_PE193.read() + 1;
        reg48.range(127, 96) = s_result_PE193.read() + 1;
        reg48.range(159, 128) = s_result_PE194.read() + 1;
        reg48.range(191, 160) = s_result_PE194.read() + 1;
        reg48.range(223, 192) = s_result_PE195.read() + 1;
        reg48.range(255, 224) = s_result_PE195.read() + 1;
        s_result_all.write(reg48);

        reg49.range(31, 0) = s_result_PE196.read() + 1;
        reg49.range(63, 32) = s_result_PE196.read() + 1;
        reg49.range(95, 64) = s_result_PE197.read() + 1;
        reg49.range(127, 96) = s_result_PE197.read() + 1;
        reg49.range(159, 128) = s_result_PE198.read() + 1;
        reg49.range(191, 160) = s_result_PE198.read() + 1;
        reg49.range(223, 192) = s_result_PE199.read() + 1;
        reg49.range(255, 224) = s_result_PE199.read() + 1;
        s_result_all.write(reg49);
    }
}

void dataTransform(hls::stream<W_TYPE>& s_embedding_table, hls::stream<W_TYPE> & s_result_all, hls::stream<ap_uint<512> > & s_data_in){

    for_each_item:
    // in these packets, first 55*512 bits represent embedding table
    // last 25*512 bits represent partial result of layer 1
    // 880*32+400*32 = 55*512+25*512 = 80*512
    // for 5000*32 items, need 800,000 packets

    for (int item = 0; item < BATCH_NUM * BATCH_SIZE; item++) {
        for (int i = 0; i < 55; i++){
            #pragma HLS pipeline II=2
            ap_uint<512> s_data;
            s_data(255, 0) = s_embedding_table.read();
            s_data(511, 256) = s_embedding_table.read();

            s_data_in.write(s_data);
        }

        for (int i = 0; i < 25; i++){
            #pragma HLS pipeline II=1
            ap_uint<512> s_data;
            s_data(255, 0) = s_result_all.read();
            s_data(511, 256) = s_result_all.read();

            s_data_in.write(s_data);
        }

    }
}

void dataTransform_writeResult(hls::stream<W_TYPE>& s_embedding_table, hls::stream<W_TYPE> & s_result_all, hls::stream<ap_uint<512> > & s_data_in, D_TYPE results_out[HIDDEN_SIZE1_PARTIAL]){

    ap_uint<512> temp[BATCH_NUM * BATCH_SIZE * HIDDEN_SIZE1_PARTIAL / 4 / 4];
    for_each_item:
    // use 5 packets to send one 880*32 bits and 400*32 bits
    // in each packet, first 11*512 bits represent embedding table
    // last 5*512 bits represent partial result of layer 1
    // 880*32+400*32 = 5*(11*512+5*512)
    int loop1 =  HIDDEN_SIZE1_PARTIAL / 4 / 4 / 5; // loop1 = 5
    for (int item = 0; item < BATCH_NUM * BATCH_SIZE * loop1; item++) {
        for (int i = 0; i < 11; i++){
            #pragma HLS pipeline II=1
            ap_uint<512> s_data;
            s_data(127, 0) = s_embedding_table.read();
            s_data(255, 128) = s_embedding_table.read();
            s_data(383, 256) = s_embedding_table.read();
            s_data(511, 384) = s_embedding_table.read();

            s_data_in.write(s_data);
        }

        for (int i = 0; i < 5; i++){
            #pragma HLS pipeline II=1
            ap_uint<512> s_data;
            s_data(127, 0) = s_result_all.read();
            s_data(255, 128) = s_result_all.read();
            s_data(383, 256) = s_result_all.read();
            s_data(511, 384) = s_result_all.read();

            temp[item * loop1 + i] = s_data;
            s_data_in.write(s_data);
        }

    }

    for (int j = 0; j < HIDDEN_SIZE1_PARTIAL / 4 / 4; j++){
        for (int k = 0; k < 16; k++) {
            #pragma HLS pipeline II=1
            ap_uint<512> s_data_temp = temp[j];
            results_out[16*j+k] = s_data_temp(32*k+31, 32*k);
        }
    }
}