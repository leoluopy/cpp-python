
#include <pybind11/pybind11.h>
#include <pybind11/detail/common.h>
#include <pybind11/eigen.h>
#include <opencv2/opencv.hpp>

using cv::Mat;
namespace py = pybind11;

int add(int i, int j) {
    printf(" this is exmaple of python invoke cpp , always used in accelerating python application\n");
    return i + j;
}


int pass_string(char *str) {
    printf("%s\n", str);
    return 0;
}

py::array_t<unsigned char> pass_string_return_mat(char *str) {
    cv::Mat img = cv::imread(str, 1);
    int height = img.rows;
    int width = img.cols;
    printf("w:%d,h:%d\n", width, height);

    int shape[3] = {height, width, 3};
    py::array_t<unsigned char> k(shape, img.data);

    return k;
}


PYBIND11_MODULE(example, m) {
    // optional module docstring
    m.doc() = "pybind11 example plugin";
    // expose add function, and add keyword arguments and default arguments
    m.def("add", &add, "A function which adds two numbers", py::arg("i") = 1, py::arg("j") = 2);
    m.def("pass_string", &pass_string, "A function which pass string", py::arg("str") = "expstring");
    m.def("pass_string_return_mat", &pass_string_return_mat, "A function which pass string return mat", py::arg("str") = "expstring");

    // exporting variables
    m.attr("the_answer") = 42;
    py::object world = py::cast("World");
    m.attr("what") = world;
}



