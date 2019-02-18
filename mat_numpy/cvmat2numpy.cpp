#include <Eigen/Dense>
#include <pybind11/embed.h> // everything needed for embedding
#include <iostream>

#include<pybind11/eigen.h>
namespace py = pybind11;


#include <opencv2/opencv.hpp>
using cv::Mat ;

typedef Eigen::Matrix<unsigned char,Eigen::Dynamic, Eigen::Dynamic> MatrixU8;

#include <stdio.h>
#include <sys/timeb.h>



int main()
{
//    const char* imagename = "test_im.jpg";
    const char* imagename = "test_im1080.jpg";

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
//    cv::imshow("image", img);
//    cv::waitKey(500);
    try
    {
    //        Py_SetProgramName("PYTHON");
        py::scoped_interpreter guard{};

        py::module py_test = py::module::import("py_test");

        MatrixU8 m_b(height,width);
        MatrixU8 m_g(height,width);
        MatrixU8 m_r(height,width);

        struct timeb t1;
        ftime(&t1);
        std::cout<<"time:"<<t1.time<<"."<<t1.millitm<<std::endl;
        for(int h = 0 ; h < img.rows ; ++ h)
        {
            for(int w = 0 ; w < img.cols ; ++ w)
            {
                m_b(h , w) = img.ptr<cv::Vec3b>(h)[w][0] ;
                m_g(h , w) = img.ptr<cv::Vec3b>(h)[w][1] ;
                m_r(h , w) = img.ptr<cv::Vec3b>(h)[w][2] ;
//                m_b(h , w) = 255 ;
//                m_g(h , w) = 0;
//                m_r(h , w) = 0 ;
//                std::cout << h << " " << w << " " << m_b(h,w) << " ";
//                std::cout << m_g(h,w) << " ";
//                std::cout << m_r(h,w) << " ";
//                std::cout << std::endl;
            }
        }
        ftime(&t1);
        std::cout<<"time:"<<t1.time<<"."<<t1.millitm<<std::endl;
        py_test.attr("probe_mat")(m_b,m_g,m_r);

    }
    catch (std::exception ex)
    {
      std::cout << "ERROR   : " << ex.what() << std::endl;
    }
    return 1;
}
