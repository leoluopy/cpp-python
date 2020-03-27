import example
import cv2

ret = example.add(1, 2)
print(ret)

ret = example.pass_string("../test")
print(ret)

ims = cv2.imread("./1.png")
example.mat_show_in_cv(ims)

ret = example.pass_string_return_mat("./1.png")
print(ret)
print(ret.shape)

print ("--------------")
ret = example.pass_string_return_numpy("string to numpy")
print (ret)
print (ret.shape)
