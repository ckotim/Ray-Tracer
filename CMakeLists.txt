cmake_minimum_required(VERSION 3.6)
project (Ray-Tracer)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES src/math/Point.cpp src/math/Vector.cpp src/math/Matrix.cpp)
add_library(core ${SOURCE_FILES})
add_executable(modeltoworld src/Main.cpp)
add_executable(modeltoworld_test test/Main.cpp test/Test.cpp)

target_link_libraries(modeltoworld core)
target_link_libraries(modeltoworld_test core gtest gtest_main)