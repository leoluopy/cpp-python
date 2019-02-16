
mkdir -p build ; cd build/ ; cmake ../; make; mv test_mat ../ ; mv show_mat ../ ; cd ../;

g++ show_mat.cpp -o show_mat -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -L /usr/local/lib/


