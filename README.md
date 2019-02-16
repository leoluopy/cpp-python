# cpp-python
> 这是一个比较完整的cpp 和python 的高效并简洁的相互调用例子，
cpp invoke python / python invoke cpp


* 平台ubuntu16.04


### install flow of pybind11
```
git clone https://github.com/pybind/pybind11 
ip install pytest
sudo apt-get install python-dev python3-dev cmake python3.5-dev
```

```angularjs
mkdir build
cd build
cmake ..
make check -j 4
sudo make install
```
## For python invoke cpp 
> it is used always as you are accelerating the application
### building command
```angularjs
g++ -O3 -Wall -shared -std=c++11 -fPIC -I /home/leo/.pyenv/versions/anaconda3-5.2.0/include/python3.6m/ `python3 -m pybind11 --includes` example.cpp -o example`python3-config --extension-suffix`
python exp.py
```
or you can use cmake
```angularjs
mkdir build
cd build
cmake ..
make
mv example.so ../
python exp.py
```
> note the Python.h path sould be included


## For cpp invoke python
```angularjs
cd cpp_python
mkdir build
cd build ; cmake ../ ; make
mv cpp_python ../ 
cd ../
./cpp_python
``` 

### 参考文章：
https://blog.csdn.net/fitzzhang/article/details/78988682
https://pybind11.readthedocs.io/en/stable/index.html
https://pybind11.readthedocs.io/en/stable/basics.html#creating-bindings-for-a-simple-function