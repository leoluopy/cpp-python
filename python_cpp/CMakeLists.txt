
cmake_minimum_required(VERSION 2.8.12)
project(example)

include_directories(/home/leo/.pyenv/versions/anaconda3-2019.03/pkgs/python-3.7.3-h0371630_0/include/python3.7m/)
include_directories(/usr/include/eigen3/)


find_package(OpenCV  REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


add_library(example SHARED example.cpp)
target_link_libraries(example ${OpenCV_LIBRARIES})
set_target_properties(example PROPERTIES PREFIX "")
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})








