

#c++
```
#include<pybind11/stl.h>
#include<vector>
#include<list>
#include<array>
#include<map>
#include<set>

/*
file:///D:/pybind11-master/docs/.build/html/advanced/cast/stl.html
*/

namespace py = pybind11;

std::vector<float> vec_add(std::vector<float>& a, std::vector<float>& b) {

    std::vector<float> out;
    assert(a.size() == b.size());
    for (int i = 0; i < a.size(); i++)
    {
        out.push_back(a[i] + b[i]);
    }

    return out;

}

std::array<float, 20> vec_sin(std::array<float, 20>& x) {
    std::array<float, 20> out;
    for (int i = 0; i < x.size(); i++)
    {
        out[i] = sinf(i);
    }
    return out;
}

std::map<std::string, int> get_map(std::vector<std::string>& keys, std::vector<int> values) {

    std::map<std::string, int> out;

    for (int i = 0; i < keys.size(); i++)
    {
        out.insert({ keys[i], values[i] });
    }

    return out;
}

std::set<std::string> get_set(std::vector<std::string>& values) {

    std::set<std::string> out;
    for (auto& i:values)
    {
        out.insert(i);
    }

    return out;
}

PYBIND11_MODULE(stl_demo, m) {

    m.doc() = "This is a simple demo using C++ STL";

    m.def("vec_add", &vec_add, py::return_value_policy::reference);
    m.def("vec_sin", &vec_sin, py::return_value_policy::reference);
    m.def("get_map", &get_map, py::return_value_policy::reference);
    m.def("get_set", &get_set, py::return_value_policy::reference);

}
```

#Python
```
import demo7.stl_demo as stl
import numpy as np


# C++ std::vector
# python list
var1 = stl.vec_add([1, 3, 5, 7, 9, 11], [9, 7, 5, 4, 3, 1])
print(var1)

var2 = stl.vec_sin(np.linspace(0, np.pi*2, num=20).tolist())
print(var2)

# C++ std::map
# python dict
var3 = stl.get_map(['apple', 'banana', 'melon', 'orange'], [1, 2, 3, 4])
print(type(var3))
print(var3)

# C++ std::set
# python set
var4 = stl.get_set(['a', 'd', 'f', 'asd', 'a', 'A', 'BB', 'b'])
print(type(var4))
print(var4)


```



