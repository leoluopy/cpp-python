
cmake_minimum_required(VERSION 2.8.12)
project(example)

include_directories(/home/leo/.pyenv/versions/anaconda3-5.2.0/include/python3.6m/)
include_directories(/usr/include/eigen3/)
link_directories(/home/leo/.pyenv/versions/anaconda3-5.2.0/lib/)
link_directories(/usr/local/lib/)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(test_mat test_mat.cpp)
target_link_libraries(test_mat python3.6m)


add_executable(show_mat show_mat.cpp)
target_link_libraries(show_mat  opencv_core opencv_highgui opencv_imgproc opencv_imgcodecs )
