
```$xslt
sudo apt-get install python-numpy
mkdir -p build ; cd build/ ; cmake ../; make; cd ../
g++ show_mat.cpp -o show_mat -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -L /usr/local/lib/

```


