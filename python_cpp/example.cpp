
#include <pybind11/pybind11.h>
#include <pybind11/detail/common.h>
namespace py = pybind11;

int add(int i, int j)
{
    printf(" this is exmaple of python invoke cpp , always used in accelerating python application\n");
    return i + j;
}


int pass_string(char *str)
{
    printf("%s\n",str);
    return 0;
}



PYBIND11_MODULE(example, m)
{
    // optional module docstring
    m.doc() = "pybind11 example plugin";
    // expose add function, and add keyword arguments and default arguments
    m.def("add", &add, "A function which adds two numbers", py::arg("i")=1, py::arg("j")=2);
    m.def("pass_string", &pass_string, "A function which pass string", py::arg("str")="expstring");

    // exporting variables
    m.attr("the_answer") = 42;
    py::object world = py::cast("World");
    m.attr("what") = world;
}



