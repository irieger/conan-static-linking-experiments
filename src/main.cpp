#include <iostream>

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <yaml-cpp/yaml.h>
#include <ceres/ceres.h>

#include <OpenImageIO/imageio.h>
OIIO_NAMESPACE_USING


int main(int argc, char* argv[])
{
	google::InitGoogleLogging(argv[0]);
    FLAGS_alsologtostderr = 1;
    FLAGS_v = 5;

	LOG(INFO) << "Test some library linking!\n";

	{
		YAML::Node node;
		node["test"] = 1.0;
		node["foo"] = "bar";
		LOG(INFO) << "YAML test: " << node;
	}

	{
		ceres::Problem problem;
		ceres::Solver::Summary summary;

		std::cout << "Ceres summary: " << summary.FullReport();
	}

	{
		float img[3] = {0.125, 0.25, 0.5};
		std::string filename = "/tmp/testoutimg.exr";

		auto out = ImageOutput::create(filename);
		if (!out)
			return 1;
        ImageSpec spec(1, 1, 3, TypeDesc::HALF);
        out->open(filename, spec);
        out->write_image(TypeDesc::FLOAT, img);
        out->close();
	}

	LOG(INFO) << "Done!";

	return 0;
}