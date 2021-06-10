#pragma once
#include <ap_int.h>

//////////////////////////////   TEMPLATE START  //////////////////////////////

#define AXI_WIDTH_PLRAM 32
#define AXI_WIDTH_HBM 32
#define AXI_WIDTH_DDR 32

#define INT_BITS 32
#define INTS_PER_AXI_PLRAM 1
#define INTS_PER_AXI_HBM 1
#define INTS_PER_AXI_DDR 1

#define PLRAM_BANK_NUM 4
#define HBM_BANK_NUM 32
#define DDR_BANK 2

#define TABLE_NUM 68

// #define ACCESS_IDX_SIZE 42
// #define PADDED_ACCESS_IDX_SIZE 42
// #define AXI_PADDED_ACCESS_IDX_SIZE 42

#define TABLE_NUM_HBM 64
#define TABLE_NUM_DDR 4
//#define TABLE_NUM_PLRAM 16

/////////////////////////   HBM   ///////////////////////// 
// alignment of tables to HBM: 
// table 0 ~ 27 -> HBM 0 ~ 27
// table 32 ~ 59 -> HBM 0 ~ 27

#define DATA_SIZE_HBM_0 8
#define PADDED_SIZE_HBM_0 8
#define AXI_PADDED_SIZE_HBM_0 8
#define TABLE_SIZE_HBM_0 50000
#define DATA_SIZE_HBM_1 16
#define PADDED_SIZE_HBM_1 16
#define AXI_PADDED_SIZE_HBM_1 16
#define TABLE_SIZE_HBM_1 50000
#define DATA_SIZE_HBM_2 16
#define PADDED_SIZE_HBM_2 16
#define AXI_PADDED_SIZE_HBM_2 16
#define TABLE_SIZE_HBM_2 50000
#define DATA_SIZE_HBM_3 16
#define PADDED_SIZE_HBM_3 16
#define AXI_PADDED_SIZE_HBM_3 16
#define TABLE_SIZE_HBM_3 50000
#define DATA_SIZE_HBM_4 16
#define PADDED_SIZE_HBM_4 16
#define AXI_PADDED_SIZE_HBM_4 16
#define TABLE_SIZE_HBM_4 50000
#define DATA_SIZE_HBM_5 16
#define PADDED_SIZE_HBM_5 16
#define AXI_PADDED_SIZE_HBM_5 16
#define TABLE_SIZE_HBM_5 50000
#define DATA_SIZE_HBM_6 16
#define PADDED_SIZE_HBM_6 16
#define AXI_PADDED_SIZE_HBM_6 16
#define TABLE_SIZE_HBM_6 50000
#define DATA_SIZE_HBM_7 16
#define PADDED_SIZE_HBM_7 16
#define AXI_PADDED_SIZE_HBM_7 16
#define TABLE_SIZE_HBM_7 50000
#define DATA_SIZE_HBM_8 16
#define PADDED_SIZE_HBM_8 16
#define AXI_PADDED_SIZE_HBM_8 16
#define TABLE_SIZE_HBM_8 50000
#define DATA_SIZE_HBM_9 16
#define PADDED_SIZE_HBM_9 16
#define AXI_PADDED_SIZE_HBM_9 16
#define TABLE_SIZE_HBM_9 50000
#define DATA_SIZE_HBM_10 16
#define PADDED_SIZE_HBM_10 16
#define AXI_PADDED_SIZE_HBM_10 16
#define TABLE_SIZE_HBM_10 50000
#define DATA_SIZE_HBM_11 16
#define PADDED_SIZE_HBM_11 16
#define AXI_PADDED_SIZE_HBM_11 16
#define TABLE_SIZE_HBM_11 50000
#define DATA_SIZE_HBM_12 16
#define PADDED_SIZE_HBM_12 16
#define AXI_PADDED_SIZE_HBM_12 16
#define TABLE_SIZE_HBM_12 50000
#define DATA_SIZE_HBM_13 16
#define PADDED_SIZE_HBM_13 16
#define AXI_PADDED_SIZE_HBM_13 16
#define TABLE_SIZE_HBM_13 50000
#define DATA_SIZE_HBM_14 16
#define PADDED_SIZE_HBM_14 16
#define AXI_PADDED_SIZE_HBM_14 16
#define TABLE_SIZE_HBM_14 50000
#define DATA_SIZE_HBM_15 16
#define PADDED_SIZE_HBM_15 16
#define AXI_PADDED_SIZE_HBM_15 16
#define TABLE_SIZE_HBM_15 50000
#define DATA_SIZE_HBM_16 16
#define PADDED_SIZE_HBM_16 16
#define AXI_PADDED_SIZE_HBM_16 16
#define TABLE_SIZE_HBM_16 50000
#define DATA_SIZE_HBM_17 16
#define PADDED_SIZE_HBM_17 16
#define AXI_PADDED_SIZE_HBM_17 16
#define TABLE_SIZE_HBM_17 50000
#define DATA_SIZE_HBM_18 16
#define PADDED_SIZE_HBM_18 16
#define AXI_PADDED_SIZE_HBM_18 16
#define TABLE_SIZE_HBM_18 50000
#define DATA_SIZE_HBM_19 16
#define PADDED_SIZE_HBM_19 16
#define AXI_PADDED_SIZE_HBM_19 16
#define TABLE_SIZE_HBM_19 50000
#define DATA_SIZE_HBM_20 16
#define PADDED_SIZE_HBM_20 16
#define AXI_PADDED_SIZE_HBM_20 16
#define TABLE_SIZE_HBM_20 50000
#define DATA_SIZE_HBM_21 16
#define PADDED_SIZE_HBM_21 16
#define AXI_PADDED_SIZE_HBM_21 16
#define TABLE_SIZE_HBM_21 50000
#define DATA_SIZE_HBM_22 16
#define PADDED_SIZE_HBM_22 16
#define AXI_PADDED_SIZE_HBM_22 16
#define TABLE_SIZE_HBM_22 50000
#define DATA_SIZE_HBM_23 16
#define PADDED_SIZE_HBM_23 16
#define AXI_PADDED_SIZE_HBM_23 16
#define TABLE_SIZE_HBM_23 50000
#define DATA_SIZE_HBM_24 16
#define PADDED_SIZE_HBM_24 16
#define AXI_PADDED_SIZE_HBM_24 16
#define TABLE_SIZE_HBM_24 50000
#define DATA_SIZE_HBM_25 16
#define PADDED_SIZE_HBM_25 16
#define AXI_PADDED_SIZE_HBM_25 16
#define TABLE_SIZE_HBM_25 50000
#define DATA_SIZE_HBM_26 16
#define PADDED_SIZE_HBM_26 16
#define AXI_PADDED_SIZE_HBM_26 16
#define TABLE_SIZE_HBM_26 50000
#define DATA_SIZE_HBM_27 16
#define PADDED_SIZE_HBM_27 16
#define AXI_PADDED_SIZE_HBM_27 16
#define TABLE_SIZE_HBM_27 50000
//#define DATA_SIZE_HBM_28 8
//#define PADDED_SIZE_HBM_28 8
//#define AXI_PADDED_SIZE_HBM_28 8
//#define TABLE_SIZE_HBM_28 50000
//#define DATA_SIZE_HBM_29 8
//#define PADDED_SIZE_HBM_29 8
//#define AXI_PADDED_SIZE_HBM_29 8
//#define TABLE_SIZE_HBM_29 50000
//#define DATA_SIZE_HBM_30 8
//#define PADDED_SIZE_HBM_30 8
//#define AXI_PADDED_SIZE_HBM_30 8
//#define TABLE_SIZE_HBM_30 50000
//#define DATA_SIZE_HBM_31 8
//#define PADDED_SIZE_HBM_31 8
//#define AXI_PADDED_SIZE_HBM_31 8
//#define TABLE_SIZE_HBM_31 50000
#define DATA_SIZE_HBM_32 8
#define PADDED_SIZE_HBM_32 8
#define AXI_PADDED_SIZE_HBM_32 8
#define TABLE_SIZE_HBM_32 50000
#define DATA_SIZE_HBM_33 16
#define PADDED_SIZE_HBM_33 16
#define AXI_PADDED_SIZE_HBM_33 16
#define TABLE_SIZE_HBM_33 50000
#define DATA_SIZE_HBM_34 16
#define PADDED_SIZE_HBM_34 16
#define AXI_PADDED_SIZE_HBM_34 16
#define TABLE_SIZE_HBM_34 50000
#define DATA_SIZE_HBM_35 16
#define PADDED_SIZE_HBM_35 16
#define AXI_PADDED_SIZE_HBM_35 16
#define TABLE_SIZE_HBM_35 50000
#define DATA_SIZE_HBM_36 16
#define PADDED_SIZE_HBM_36 16
#define AXI_PADDED_SIZE_HBM_36 16
#define TABLE_SIZE_HBM_36 50000
#define DATA_SIZE_HBM_37 16
#define PADDED_SIZE_HBM_37 16
#define AXI_PADDED_SIZE_HBM_37 16
#define TABLE_SIZE_HBM_37 50000
#define DATA_SIZE_HBM_38 16
#define PADDED_SIZE_HBM_38 16
#define AXI_PADDED_SIZE_HBM_38 16
#define TABLE_SIZE_HBM_38 50000
#define DATA_SIZE_HBM_39 16
#define PADDED_SIZE_HBM_39 16
#define AXI_PADDED_SIZE_HBM_39 16
#define TABLE_SIZE_HBM_39 50000
#define DATA_SIZE_HBM_40 16
#define PADDED_SIZE_HBM_40 16
#define AXI_PADDED_SIZE_HBM_40 16
#define TABLE_SIZE_HBM_40 50000
#define DATA_SIZE_HBM_41 16
#define PADDED_SIZE_HBM_41 16
#define AXI_PADDED_SIZE_HBM_41 16
#define TABLE_SIZE_HBM_41 50000
#define DATA_SIZE_HBM_42 16
#define PADDED_SIZE_HBM_42 16
#define AXI_PADDED_SIZE_HBM_42 16
#define TABLE_SIZE_HBM_42 50000
#define DATA_SIZE_HBM_43 16
#define PADDED_SIZE_HBM_43 16
#define AXI_PADDED_SIZE_HBM_43 16
#define TABLE_SIZE_HBM_43 50000
#define DATA_SIZE_HBM_44 16
#define PADDED_SIZE_HBM_44 16
#define AXI_PADDED_SIZE_HBM_44 16
#define TABLE_SIZE_HBM_44 50000
#define DATA_SIZE_HBM_45 16
#define PADDED_SIZE_HBM_45 16
#define AXI_PADDED_SIZE_HBM_45 16
#define TABLE_SIZE_HBM_45 50000
#define DATA_SIZE_HBM_46 16
#define PADDED_SIZE_HBM_46 16
#define AXI_PADDED_SIZE_HBM_46 16
#define TABLE_SIZE_HBM_46 50000
#define DATA_SIZE_HBM_47 16
#define PADDED_SIZE_HBM_47 16
#define AXI_PADDED_SIZE_HBM_47 16
#define TABLE_SIZE_HBM_47 50000
#define DATA_SIZE_HBM_48 16
#define PADDED_SIZE_HBM_48 16
#define AXI_PADDED_SIZE_HBM_48 16
#define TABLE_SIZE_HBM_48 50000
#define DATA_SIZE_HBM_49 16
#define PADDED_SIZE_HBM_49 16
#define AXI_PADDED_SIZE_HBM_49 16
#define TABLE_SIZE_HBM_49 50000
#define DATA_SIZE_HBM_50 16
#define PADDED_SIZE_HBM_50 16
#define AXI_PADDED_SIZE_HBM_50 16
#define TABLE_SIZE_HBM_50 50000
#define DATA_SIZE_HBM_51 16
#define PADDED_SIZE_HBM_51 16
#define AXI_PADDED_SIZE_HBM_51 16
#define TABLE_SIZE_HBM_51 50000
#define DATA_SIZE_HBM_52 16
#define PADDED_SIZE_HBM_52 16
#define AXI_PADDED_SIZE_HBM_52 16
#define TABLE_SIZE_HBM_52 50000
#define DATA_SIZE_HBM_53 16
#define PADDED_SIZE_HBM_53 16
#define AXI_PADDED_SIZE_HBM_53 16
#define TABLE_SIZE_HBM_53 50000
#define DATA_SIZE_HBM_54 16
#define PADDED_SIZE_HBM_54 16
#define AXI_PADDED_SIZE_HBM_54 16
#define TABLE_SIZE_HBM_54 50000
#define DATA_SIZE_HBM_55 16
#define PADDED_SIZE_HBM_55 16
#define AXI_PADDED_SIZE_HBM_55 16
#define TABLE_SIZE_HBM_55 50000
#define DATA_SIZE_HBM_56 16
#define PADDED_SIZE_HBM_56 16
#define AXI_PADDED_SIZE_HBM_56 16
#define TABLE_SIZE_HBM_56 50000
#define DATA_SIZE_HBM_57 16
#define PADDED_SIZE_HBM_57 16
#define AXI_PADDED_SIZE_HBM_57 16
#define TABLE_SIZE_HBM_57 50000
#define DATA_SIZE_HBM_58 16
#define PADDED_SIZE_HBM_58 16
#define AXI_PADDED_SIZE_HBM_58 16
#define TABLE_SIZE_HBM_58 50000
#define DATA_SIZE_HBM_59 16
#define PADDED_SIZE_HBM_59 16
#define AXI_PADDED_SIZE_HBM_59 16
#define TABLE_SIZE_HBM_59 50000
//#define DATA_SIZE_HBM_60 16
//#define PADDED_SIZE_HBM_60 16
//#define AXI_PADDED_SIZE_HBM_60 16
//#define TABLE_SIZE_HBM_60 50000
//#define DATA_SIZE_HBM_61 16
//#define PADDED_SIZE_HBM_61 16
//#define AXI_PADDED_SIZE_HBM_61 16
//#define TABLE_SIZE_HBM_61 50000
//#define DATA_SIZE_HBM_62 16
//#define PADDED_SIZE_HBM_62 16
//#define AXI_PADDED_SIZE_HBM_62 16
//#define TABLE_SIZE_HBM_62 50000
//#define DATA_SIZE_HBM_63 16
//#define PADDED_SIZE_HBM_63 16
//#define AXI_PADDED_SIZE_HBM_63 16
//#define TABLE_SIZE_HBM_63 50000

#define BURST_SIZE_HBM 16

#define ADDR_AXI_HBM_0 0
#define ADDR_AXI_HBM_1 0
#define ADDR_AXI_HBM_2 0
#define ADDR_AXI_HBM_3 0
#define ADDR_AXI_HBM_4 0
#define ADDR_AXI_HBM_5 0
#define ADDR_AXI_HBM_6 0
#define ADDR_AXI_HBM_7 0
#define ADDR_AXI_HBM_8 0
#define ADDR_AXI_HBM_9 0
#define ADDR_AXI_HBM_10 0
#define ADDR_AXI_HBM_11 0
#define ADDR_AXI_HBM_12 0
#define ADDR_AXI_HBM_13 0
#define ADDR_AXI_HBM_14 0
#define ADDR_AXI_HBM_15 0
#define ADDR_AXI_HBM_16 0
#define ADDR_AXI_HBM_17 0
#define ADDR_AXI_HBM_18 0
#define ADDR_AXI_HBM_19 0
#define ADDR_AXI_HBM_20 0
#define ADDR_AXI_HBM_21 0
#define ADDR_AXI_HBM_22 0
#define ADDR_AXI_HBM_23 0
#define ADDR_AXI_HBM_24 0
#define ADDR_AXI_HBM_25 0
#define ADDR_AXI_HBM_26 0
#define ADDR_AXI_HBM_27 0
//#define ADDR_AXI_HBM_28 0
//#define ADDR_AXI_HBM_29 0
//#define ADDR_AXI_HBM_30 0
//#define ADDR_AXI_HBM_31 0
#define ADDR_AXI_HBM_32 400000
#define ADDR_AXI_HBM_33 800000
#define ADDR_AXI_HBM_34 800000
#define ADDR_AXI_HBM_35 800000
#define ADDR_AXI_HBM_36 800000
#define ADDR_AXI_HBM_37 800000
#define ADDR_AXI_HBM_38 800000
#define ADDR_AXI_HBM_39 800000
#define ADDR_AXI_HBM_40 800000
#define ADDR_AXI_HBM_41 800000
#define ADDR_AXI_HBM_42 800000
#define ADDR_AXI_HBM_43 800000
#define ADDR_AXI_HBM_44 800000
#define ADDR_AXI_HBM_45 800000
#define ADDR_AXI_HBM_46 800000
#define ADDR_AXI_HBM_47 800000
#define ADDR_AXI_HBM_48 800000
#define ADDR_AXI_HBM_49 800000
#define ADDR_AXI_HBM_50 800000
#define ADDR_AXI_HBM_51 800000
#define ADDR_AXI_HBM_52 800000
#define ADDR_AXI_HBM_53 800000
#define ADDR_AXI_HBM_54 800000
#define ADDR_AXI_HBM_55 800000
#define ADDR_AXI_HBM_56 800000
#define ADDR_AXI_HBM_57 800000
#define ADDR_AXI_HBM_58 800000
#define ADDR_AXI_HBM_59 800000
//#define ADDR_AXI_HBM_60 400000
//#define ADDR_AXI_HBM_61 400000
//#define ADDR_AXI_HBM_62 400000
//#define ADDR_AXI_HBM_63 400000

#define HBM_BANK0_ROUND 2
#define HBM_BANK1_ROUND 2
#define HBM_BANK2_ROUND 2
#define HBM_BANK3_ROUND 2
#define HBM_BANK4_ROUND 2
#define HBM_BANK5_ROUND 2
#define HBM_BANK6_ROUND 2
#define HBM_BANK7_ROUND 2
#define HBM_BANK8_ROUND 2
#define HBM_BANK9_ROUND 2
#define HBM_BANK10_ROUND 2
#define HBM_BANK11_ROUND 2
#define HBM_BANK12_ROUND 2
#define HBM_BANK13_ROUND 2
#define HBM_BANK14_ROUND 2
#define HBM_BANK15_ROUND 2
#define HBM_BANK16_ROUND 2
#define HBM_BANK17_ROUND 2
#define HBM_BANK18_ROUND 2
#define HBM_BANK19_ROUND 2
#define HBM_BANK20_ROUND 2
#define HBM_BANK21_ROUND 2
#define HBM_BANK22_ROUND 2
#define HBM_BANK23_ROUND 2
#define HBM_BANK24_ROUND 2
#define HBM_BANK25_ROUND 2
#define HBM_BANK26_ROUND 2
#define HBM_BANK27_ROUND 2
//#define HBM_BANK28_ROUND 2
//#define HBM_BANK29_ROUND 2
//#define HBM_BANK30_ROUND 2
//#define HBM_BANK31_ROUND 2

#define HBM_BANK0_SIZE 800000
#define HBM_BANK1_SIZE 1600000
#define HBM_BANK2_SIZE 1600000
#define HBM_BANK3_SIZE 1600000
#define HBM_BANK4_SIZE 1600000
#define HBM_BANK5_SIZE 1600000
#define HBM_BANK6_SIZE 1600000
#define HBM_BANK7_SIZE 1600000
#define HBM_BANK8_SIZE 1600000
#define HBM_BANK9_SIZE 1600000
#define HBM_BANK10_SIZE 1600000
#define HBM_BANK11_SIZE 1600000
#define HBM_BANK12_SIZE 1600000
#define HBM_BANK13_SIZE 1600000
#define HBM_BANK14_SIZE 1600000
#define HBM_BANK15_SIZE 1600000
#define HBM_BANK16_SIZE 1600000
#define HBM_BANK17_SIZE 1600000
#define HBM_BANK18_SIZE 1600000
#define HBM_BANK19_SIZE 1600000
#define HBM_BANK20_SIZE 1600000
#define HBM_BANK21_SIZE 1600000
#define HBM_BANK22_SIZE 1600000
#define HBM_BANK23_SIZE 1600000
#define HBM_BANK24_SIZE 1600000
#define HBM_BANK25_SIZE 1600000
#define HBM_BANK26_SIZE 1600000
#define HBM_BANK27_SIZE 1600000
//#define HBM_BANK28_SIZE 1200000
//#define HBM_BANK29_SIZE 1200000
//#define HBM_BANK30_SIZE 1200000
//#define HBM_BANK31_SIZE 1200000

#define VECTOR_SIZE_HBM_BANK_0 16
#define VECTOR_SIZE_HBM_BANK_1 32
#define VECTOR_SIZE_HBM_BANK_2 32
#define VECTOR_SIZE_HBM_BANK_3 32
#define VECTOR_SIZE_HBM_BANK_4 32
#define VECTOR_SIZE_HBM_BANK_5 32
#define VECTOR_SIZE_HBM_BANK_6 32
#define VECTOR_SIZE_HBM_BANK_7 32
#define VECTOR_SIZE_HBM_BANK_8 32
#define VECTOR_SIZE_HBM_BANK_9 32
#define VECTOR_SIZE_HBM_BANK_10 32
#define VECTOR_SIZE_HBM_BANK_11 32
#define VECTOR_SIZE_HBM_BANK_12 32
#define VECTOR_SIZE_HBM_BANK_13 32
#define VECTOR_SIZE_HBM_BANK_14 32
#define VECTOR_SIZE_HBM_BANK_15 32
#define VECTOR_SIZE_HBM_BANK_16 32
#define VECTOR_SIZE_HBM_BANK_17 32
#define VECTOR_SIZE_HBM_BANK_18 32
#define VECTOR_SIZE_HBM_BANK_19 32
#define VECTOR_SIZE_HBM_BANK_20 32
#define VECTOR_SIZE_HBM_BANK_21 32
#define VECTOR_SIZE_HBM_BANK_22 32
#define VECTOR_SIZE_HBM_BANK_23 32
#define VECTOR_SIZE_HBM_BANK_24 32
#define VECTOR_SIZE_HBM_BANK_25 32
#define VECTOR_SIZE_HBM_BANK_26 32
#define VECTOR_SIZE_HBM_BANK_27 32
//#define VECTOR_SIZE_HBM_BANK_28 24
//#define VECTOR_SIZE_HBM_BANK_29 24
//#define VECTOR_SIZE_HBM_BANK_30 24
//#define VECTOR_SIZE_HBM_BANK_31 24

/////////////////////////   DDR   ///////////////////////// 
// alignment of tables to DDR: 
// table 0 ~ 1 -> DDR 0 ~ 1
// table 2 ~ 3 -> DDR 0 ~ 1

//#define DATA_SIZE_DDR_0 16
//#define PADDED_SIZE_DDR_0 16
//#define AXI_PADDED_SIZE_DDR_0 16
//#define TABLE_SIZE_DDR_0 50000
//#define DATA_SIZE_DDR_1 16
//#define PADDED_SIZE_DDR_1 16
//#define AXI_PADDED_SIZE_DDR_1 16
//#define TABLE_SIZE_DDR_1 50000
//#define DATA_SIZE_DDR_2 32
//#define PADDED_SIZE_DDR_2 32
//#define AXI_PADDED_SIZE_DDR_2 32
//#define TABLE_SIZE_DDR_2 50000
//#define DATA_SIZE_DDR_3 32
//#define PADDED_SIZE_DDR_3 32
//#define AXI_PADDED_SIZE_DDR_3 32
//#define TABLE_SIZE_DDR_3 50000

//#define BURST_SIZE_DDR 32
//
//#define ADDR_AXI_DDR_0 0
//#define ADDR_AXI_DDR_1 0
//#define ADDR_AXI_DDR_2 800000
//#define ADDR_AXI_DDR_3 800000
//
//#define DDR_BANK0_ROUND 2
//#define DDR_BANK1_ROUND 2
//
//#define DDR_BANK0_SIZE 2400000
//#define DDR_BANK1_SIZE 2400000
//
//#define VECTOR_SIZE_DDR_BANK_0 48
//#define VECTOR_SIZE_DDR_BANK_1 48

/////////////////////////   PLRAM   ///////////////////////// 
// alignment of tables to PLRAM: 
// table 0 ~ 3 -> PLRAM 0 ~ 3
// table 4 ~ 7 -> PLRAM 0 ~ 3
// table 8 ~ 11 -> PLRAM 0 ~ 3
// table 12 ~ 15 -> PLRAM 0 ~ 3

//#define DATA_SIZE_PLRAM_0 8
//#define PADDED_SIZE_PLRAM_0 8
//#define AXI_PADDED_SIZE_PLRAM_0 8
//#define TABLE_SIZE_PLRAM_0 5000
//#define DATA_SIZE_PLRAM_1 8
//#define PADDED_SIZE_PLRAM_1 8
//#define AXI_PADDED_SIZE_PLRAM_1 8
//#define TABLE_SIZE_PLRAM_1 5000
//#define DATA_SIZE_PLRAM_2 8
//#define PADDED_SIZE_PLRAM_2 8
//#define AXI_PADDED_SIZE_PLRAM_2 8
//#define TABLE_SIZE_PLRAM_2 5000
//#define DATA_SIZE_PLRAM_3 8
//#define PADDED_SIZE_PLRAM_3 8
//#define AXI_PADDED_SIZE_PLRAM_3 8
//#define TABLE_SIZE_PLRAM_3 5000
//#define DATA_SIZE_PLRAM_4 8
//#define PADDED_SIZE_PLRAM_4 8
//#define AXI_PADDED_SIZE_PLRAM_4 8
//#define TABLE_SIZE_PLRAM_4 5000
//#define DATA_SIZE_PLRAM_5 8
//#define PADDED_SIZE_PLRAM_5 8
//#define AXI_PADDED_SIZE_PLRAM_5 8
//#define TABLE_SIZE_PLRAM_5 5000
//#define DATA_SIZE_PLRAM_6 8
//#define PADDED_SIZE_PLRAM_6 8
//#define AXI_PADDED_SIZE_PLRAM_6 8
//#define TABLE_SIZE_PLRAM_6 5000
//#define DATA_SIZE_PLRAM_7 8
//#define PADDED_SIZE_PLRAM_7 8
//#define AXI_PADDED_SIZE_PLRAM_7 8
//#define TABLE_SIZE_PLRAM_7 5000
//#define DATA_SIZE_PLRAM_8 8
//#define PADDED_SIZE_PLRAM_8 8
//#define AXI_PADDED_SIZE_PLRAM_8 8
//#define TABLE_SIZE_PLRAM_8 5000
//#define DATA_SIZE_PLRAM_9 8
//#define PADDED_SIZE_PLRAM_9 8
//#define AXI_PADDED_SIZE_PLRAM_9 8
//#define TABLE_SIZE_PLRAM_9 5000
//#define DATA_SIZE_PLRAM_10 8
//#define PADDED_SIZE_PLRAM_10 8
//#define AXI_PADDED_SIZE_PLRAM_10 8
//#define TABLE_SIZE_PLRAM_10 5000
//#define DATA_SIZE_PLRAM_11 8
//#define PADDED_SIZE_PLRAM_11 8
//#define AXI_PADDED_SIZE_PLRAM_11 8
//#define TABLE_SIZE_PLRAM_11 5000
//#define DATA_SIZE_PLRAM_12 8
//#define PADDED_SIZE_PLRAM_12 8
//#define AXI_PADDED_SIZE_PLRAM_12 8
//#define TABLE_SIZE_PLRAM_12 5000
//#define DATA_SIZE_PLRAM_13 8
//#define PADDED_SIZE_PLRAM_13 8
//#define AXI_PADDED_SIZE_PLRAM_13 8
//#define TABLE_SIZE_PLRAM_13 5000
//#define DATA_SIZE_PLRAM_14 8
//#define PADDED_SIZE_PLRAM_14 8
//#define AXI_PADDED_SIZE_PLRAM_14 8
//#define TABLE_SIZE_PLRAM_14 5000
//#define DATA_SIZE_PLRAM_15 8
//#define PADDED_SIZE_PLRAM_15 8
//#define AXI_PADDED_SIZE_PLRAM_15 8
//#define TABLE_SIZE_PLRAM_15 5000
//
//#define BURST_SIZE_PLRAM 8
//
//#define ADDR_AXI_PLRAM_0 0
//#define ADDR_AXI_PLRAM_1 0
//#define ADDR_AXI_PLRAM_2 0
//#define ADDR_AXI_PLRAM_3 0
//#define ADDR_AXI_PLRAM_4 40000
//#define ADDR_AXI_PLRAM_5 40000
//#define ADDR_AXI_PLRAM_6 40000
//#define ADDR_AXI_PLRAM_7 40000
//#define ADDR_AXI_PLRAM_8 80000
//#define ADDR_AXI_PLRAM_9 80000
//#define ADDR_AXI_PLRAM_10 80000
//#define ADDR_AXI_PLRAM_11 80000
//#define ADDR_AXI_PLRAM_12 120000
//#define ADDR_AXI_PLRAM_13 120000
//#define ADDR_AXI_PLRAM_14 120000
//#define ADDR_AXI_PLRAM_15 120000
//
//#define PLRAM_BANK0_ROUND 4
//#define PLRAM_BANK1_ROUND 4
//#define PLRAM_BANK2_ROUND 4
//#define PLRAM_BANK3_ROUND 4
//
//#define PLRAM_BANK0_SIZE 160000
//#define PLRAM_BANK1_SIZE 160000
//#define PLRAM_BANK2_SIZE 160000
//#define PLRAM_BANK3_SIZE 160000
//
//#define VECTOR_SIZE_PLRAM_BANK_0 32
//#define VECTOR_SIZE_PLRAM_BANK_1 32
//#define VECTOR_SIZE_PLRAM_BANK_2 32
//#define VECTOR_SIZE_PLRAM_BANK_3 32

//////////////////////////////   TEMPLATE END  //////////////////////////////


typedef ap_int<AXI_WIDTH_HBM> t_hbm;
typedef ap_int<AXI_WIDTH_DDR> t_ddr;
typedef ap_int<AXI_WIDTH_PLRAM> t_plram;

typedef int t_axi;

typedef int D_TYPE;
typedef ap_int<128> W_TYPE;  // weights / feature width
// typedef ap_int<256> FIFO_TYPE;  // stream width

#define INTS_PER_W 4 // 64 bit = 2 x 32 bit int
// #define INTS_PER_FIFO 8

//#define INPUT_SIZE 880

#define HIDDEN_SIZE1 1024
//#define HIDDEN_SIZE2_PARTIAL 192
#define HIDDEN_SIZE2 512
#define HIDDEN_SIZE3 256
#define OUTPUT_SIZE 1

//#define PE_NUM1 128
#define PE_NUM2 512
#define PE_NUM3 256
#define PE_NUM_OUT 1

#define INDEX_EVEN 0
#define INDEX_ODD 1
// This row means after transpose it is row, before is col
//#define ROW_PER_PE1 (HIDDEN_SIZE1 / PE_NUM1) // 1024 / 128 = 8
#define ROW_PER_PE2 (HIDDEN_SIZE2 / PE_NUM2) // 512 / 512 = 1
#define ROW_PER_PE3 (HIDDEN_SIZE3 / PE_NUM3) // 256 / 256 = 1
#define ROW_PER_PE_OUT (OUTPUT_SIZE / PE_NUM_OUT) // 1 / 1 = 1

#define FIFO_BATCH_SIZE 8   // cache 8 batches at max in FIFO
//#define BATCH_SIZE 32
#define BATCH_SIZE 32
//#define BATCH_NUM 2
#define BATCH_NUM 5000
//#define BATCH_NUM 5000 // NOTE! load access idx to BRAM!
