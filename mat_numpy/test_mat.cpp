#include <Eigen/Dense>
#include <pybind11/embed.h> // everything needed for embedding
#include <iostream>

#include<pybind11/eigen.h>
using Eigen::MatrixXd;
namespace py = pybind11;

int main()
{
  try
  {
//        Py_SetProgramName("PYTHON");
        py::scoped_interpreter guard{};

        py::module py_test = py::module::import("py_test");

        MatrixXd m(2,2);
        m(0,0) = 1;
        m(1,0) = 2;
        m(0,1) = 3;
        m(1,1) = 4;

        py::object result = py_test.attr("test_mat")(m);

        MatrixXd res = result.cast<MatrixXd>();
        std::cout << "In c++ \n" << res << std::endl;
  }
  catch (std::exception ex)
  {
      std::cout << "ERROR   : " << ex.what() << std::endl;
  }
  return 1;
}
