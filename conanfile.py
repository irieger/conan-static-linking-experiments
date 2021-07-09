from conans import ConanFile, CMake

class TestDependenciesConan(ConanFile):
    settings = 'cppstd', 'os', 'compiler', 'build_type', 'arch'
    requires = 'gflags/2.2.2', 'glog/0.4.0', 'yaml-cpp/0.6.3', 'eigen/3.3.8', 'ceres-solver/2.0.0', 'openimageio/2.2.7.0'
    generators = 'cmake'
    default_options = {'gflags:shared': False, 'glog:shared': False, 'yaml-cpp:shared': False, 'eigen:MPL2_only': True, 'ceres-solver:shared': False,
        'libtiff:jbig': False}

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
