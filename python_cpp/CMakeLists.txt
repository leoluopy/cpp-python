
cmake_minimum_required(VERSION 2.8.12)
project(example)

include_directories(/home/leo/.pyenv/versions/anaconda3-5.2.0/include/python3.6m/)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(example SHARED example.cpp)
set_target_properties(example PROPERTIES PREFIX "")
