from conans import ConanFile, CMake

class TestDependenciesConan(ConanFile):
    settings = 'cppstd', 'os', 'compiler', 'build_type', 'arch'
    requires = (
        'gflags/2.2.2',
        'glog/0.4.0',
        'yaml-cpp/0.6.3',
        'eigen/3.3.8',
        'ceres-solver/2.0.0',
        'opencolorio/2.1.0',
        'openimageio/2.3.7.2'
    )
    generators = 'cmake'
    default_options = {
        '*:shared': False,
        '*:visibility': 'hidden',
        'eigen:MPL2_only': True,
        'ceres-solver:use_eigen_sparse': False,
        'libtiff:jbig': False,
        'openimageio:with_ffmpeg': False, 'openimageio:with_ptex': False, 'openimageio:with_opencv': False
    }

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
