cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(cmake-conan-test)


# Init Conan basics if initialised
set(CONAN_CMAKE_FILE_INCLUE_PATH "${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
if(EXISTS ${CONAN_CMAKE_FILE_INCLUE_PATH})
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup(TARGETS)
else()
    message(FATAL_ERROR "Warning, conanbuildinfo.cmake not found!")
endif()


# Trying to get boost linked
set(other_flags "${other_flags} -fvisibility-inlines-hidden")
set(other_flags "${other_flags} -fvisibility=hidden")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${other_flags}")


add_executable(main-demo src/main.cpp)
target_compile_features(main-demo PRIVATE cxx_std_17)
target_link_libraries(main-demo PRIVATE "CONAN_PKG::gflags" "CONAN_PKG::glog" "CONAN_PKG::eigen" "CONAN_PKG::yaml-cpp" "CONAN_PKG::ceres-solver" "CONAN_PKG::openimageio")
