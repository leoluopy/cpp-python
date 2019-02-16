

#include <opencv2/opencv.hpp>
#include <pybind11/embed.h>

using namespace std;
using namespace cv;
namespace py = pybind11;

int main(int argc, char* argv[])
{
    const char* imagename = "test_im.jpg";

    //从文件中读入图像
    Mat img = imread(imagename,1);

    //如果读入图像失败
    if(img.empty())
    {
        fprintf(stderr, "Can not load image %s\n", imagename);
        return -1;
    }

    try
    {
    //        Py_SetProgramName("PYTHON");
        py::scoped_interpreter guard{};

        py::module py_test = py::module::import("py_test");
        py::object result = py_test.attr("add")(5,6);
        result = py_test.attr("probe_mat")(img.data);

    }
    catch (std::exception ex)
    {
      std::cout << "ERROR   : " << ex.what() << std::endl;
    }
}
