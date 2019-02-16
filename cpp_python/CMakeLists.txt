
cmake_minimum_required(VERSION 2.8.12)
project(example)

include_directories(/home/leo/.pyenv/versions/anaconda3-5.2.0/include/python3.6m/)
link_directories(/home/leo/.pyenv/versions/anaconda3-5.2.0/lib/)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(cpp_python cpp_python.cpp)
target_link_libraries(cpp_python python3.6m)
