
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

struct RetStruct_t {
    float tl_x = -1.0;
    float tl_y = -1.0;
    float br_x = -1.0;
    float br_y = -1.0;
    float score = -1.0;
    float p1_x = -1.0;
    float p1_y = -1.0;
};

py::array_t<double> pass_string_return_numpy(char *str) {
    printf("input : %s\n", str);

//    std::vector<double> vec;
//    vec.push_back(6.7);
//    vec.push_back(6.7);
//    vec.push_back(7.7);
//    vec.push_back(6.7);
//    vec.push_back(9.7);

    std::vector<RetStruct_t> vec;
    RetStruct_t tmpRet;
    tmpRet.tl_x = 9.3;
    tmpRet.br_x = 8.3;
    tmpRet.br_y = 67.3;

    tmpRet.p1_y = 3.3;
    vec.push_back(tmpRet);
    tmpRet.tl_x = 5.5;
    tmpRet.p1_x = 2.4;

    vec.push_back(tmpRet);

    py::array_t<double> arY({(int) (vec.size()), 7});
    py::buffer_info buf3 = arY.request(); // acquire buffer info

    double *ptr3 = (double *) buf3.ptr;

    for (int i = 0; i < vec.size(); i++) {
        ptr3[i * 7] = vec[i].tl_x;
        ptr3[i * 7 + 1] = vec[i].tl_y;
        ptr3[i * 7 + 2] = vec[i].br_x;
        ptr3[i * 7 + 3] = vec[i].br_y;
        ptr3[i * 7 + 4] = vec[i].score;
        ptr3[i * 7 + 5] = vec[i].p1_x;
        ptr3[i * 7 + 6] = vec[i].p1_y;
    }


    return arY;
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

int mat_show_in_cv(py::array_t<unsigned char> &img) {
    if (img.ndim() != 3) {
        throw std::runtime_error("RGB image must has 3 channels!");
    } else {
        printf(" dim check passed \n");
    }
    printf("input shape: %d %d %d", img.shape()[0], img.shape()[1], img.shape()[2]);
    auto imgNumpy = img.unchecked<3>();

    cv::Mat im = cv::Mat(img.shape()[0], img.shape()[1], CV_8UC3);
    for (int row = 0; row < im.rows; row++) {
        for (int col = 0; col < im.cols; col++) {
            im.at<cv::Vec3b>(row, col)[0] = static_cast<int>(imgNumpy(row, col, 0));
            im.at<cv::Vec3b>(row, col)[1] = static_cast<int>(imgNumpy(row, col, 1));
            im.at<cv::Vec3b>(row, col)[2] = static_cast<int>(imgNumpy(row, col, 2));
//            printf("%d \n", im.at<cv::Vec3b>(row, col)[0]);
        }
    }
    cv::imshow("xxxx", im);
    cv::waitKey(0);


    return 88;
}

PYBIND11_MODULE(example, m
) {
// optional module docstring
    m.

            doc() = "pybind11 example plugin";

// expose add function, and add keyword arguments and default arguments
    m.def("add", &add, "A function which adds two numbers", py::arg("i") = 1, py::arg("j") = 2);
    m.def("pass_string", &pass_string, "A function which pass string", py::arg("str") = "expstring");
    m.def("pass_string_return_mat", &pass_string_return_mat, "A function which pass string return mat",
          py::arg("str") = "expstring");
    m.def("pass_string_return_numpy", &pass_string_return_numpy, "A function which pass string return numpy",
          py::arg("str") = "expstringNumpy");

    m.def("mat_show_in_cv", &mat_show_in_cv, "A function which pass mat and show");


// exporting variables
    m.attr("the_answer") = 42;
    py::object world = py::cast("World");
    m.attr("what") =
            world;
}



