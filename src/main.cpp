#include <iostream>

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <yaml-cpp/yaml.h>
#include <ceres/ceres.h>


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

	return 0;
}