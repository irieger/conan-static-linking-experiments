#include <iostream>

#include <gflags/gflags.h>
#include <glog/logging.h>

#include <openjpeg-2.4/openjpeg.h>

int main(int argc, char* argv[])
{
	google::InitGoogleLogging(argv[0]);
    FLAGS_alsologtostderr = 1;
    FLAGS_v = 5;

	LOG(INFO) << "Test some library linking!\n";

	{
		opj_stream_t* pJP2Stream = NULL;
		opj_codec_t* pJP2Codec = NULL;
		opj_image_t* pJP2Image = NULL;
		opj_dparameters_t jp2dParams;

		pJP2Stream = opj_stream_create_default_file_stream("/home/ingmar/Downloads/zoo1.jp2", OPJ_TRUE);
		if (!pJP2Stream)
		{
		    return 1;
		}
	}

	LOG(INFO) << "Done!";

	return 0;
}
