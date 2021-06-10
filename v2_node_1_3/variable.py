for i in range(200):
    for j in range(4):
	print("    hls::stream<W_TYPE> s_feature1_PE",str(i),"_",str(j),";",sep='')
	print("    hls::stream<D_TYPE> s_result1_PE",str(i),"_",str(j),";",sep='')
	print("#pragma HLS stream variable=s_feature1_PE",str(i),"_",str(j)," depth=2",sep='')
	print("#pragma HLS stream variable=s_result1_PE",str(i),"_",str(j)," depth=2",sep='')
    print("")
