#include <Eigen/Dense>
#include <pybind11/embed.h> // everything needed for embedding
#include <iostream>

#include<pybind11/eigen.h>
using Eigen::MatrixXd;
namespace py = pybind11;


#include <opencv2/opencv.hpp>
using cv::Mat ;


int main()
{
    const char* imagename = "test_im.jpg";

    //从文件中读入图像
    cv::Mat img = cv::imread(imagename,1);
    int height = img.rows;
    int width = img.cols;
    printf("w:%d,h:%d\n",width,height);


    if(img.empty())
    {
        fprintf(stderr, "Can not load image %s\n", imagename);
        return -1;
    }
    cv::imshow("image", img);
    cv::waitKey(1000);
    try
    {
    //        Py_SetProgramName("PYTHON");
        py::scoped_interpreter guard{};

        py::module py_test = py::module::import("py_test");

        MatrixXd m_b(height,width);
        MatrixXd m_g(height,width);
        MatrixXd m_r(height,width);
        for(int h = 0 ; h < img.rows ; ++ h)
        {
            for(int w = 0 ; w < img.cols / 2 ; ++ w)
            {
                m_b(h , w) = img.at<cv::Vec3b>(h , w)[0] ;
                m_g(h , w) = img.at<cv::Vec3b>(h , w)[1] ;
                m_r(h , w) = img.at<cv::Vec3b>(h , w)[2] ;
            }
        }

        py_test.attr("probe_mat")(m_b,m_g,m_r);

    }
    catch (std::exception ex)
    {
      std::cout << "ERROR   : " << ex.what() << std::endl;
    }
    return 1;
}
