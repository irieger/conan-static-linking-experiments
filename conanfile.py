from conans import ConanFile, CMake

class TestDependenciesConan(ConanFile):
    settings = 'cppstd', 'os', 'compiler', 'build_type', 'arch'
    requires = 'gflags/2.2.2', 'glog/0.4.0', 'openjpeg/2.4.0 '
    generators = 'cmake'
    default_options = {'gflags:shared': False, 'glog:shared': False, 'openjpeg:shared': False}

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
