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

	// {
	// 	float img[3] = {0.125, 0.25, 0.5};
	// 	std::string filename = "/tmp/testoutimg.exr";

	// 	auto out = ImageOutput::create(filename);
	// 	if (!out)
	// 		return 1;
 //        ImageSpec spec(1, 1, 3, TypeDesc::HALF);
 //        out->open(filename, spec);
 //        out->write_image(TypeDesc::FLOAT, img);
 //        out->close();
	// }
	{
		opj_stream_t* pJP2Stream = NULL;
		opj_codec_t* pJP2Codec = NULL;
		opj_image_t* pJP2Image = NULL;
		opj_dparameters_t jp2dParams;

		// opj_codestream_index_t *pJP2CodeStreamIndex = opj_get_cstr_index(pJP2Codec);
		// opj_codestream_info_v2_t *pJP2CodeStreamInfo = opj_get_cstr_info(pJP2Codec);

		pJP2Stream = opj_stream_create_default_file_stream("/home/ingmar/Downloads/zoo1.jp2", OPJ_TRUE);
		if (!pJP2Stream)
		{
		    // pFileInfo->ErrorCode = ERR_OPEN;
		    return 1;
		}
	}

	LOG(INFO) << "Done!";

	return 0;
}