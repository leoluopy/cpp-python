from pylab import *
import numpy as np
import cv2

def test_mat(m):
    print("Inside python m = \n ", m)
    m[0, 0] = 10
    m[1, 1] = 99

    print("shape:{}".format(m.shape))
    print("line:{}".format(m[0]))
    print("line:{}".format(m[1]))
    return m


def probe_mat(m0,m1,m2):
    # print("Inside python m0 = \n ", m0)
    m0 = np.expand_dims(m0, 2)
    m1 = np.expand_dims(m1, 2)
    m2 = np.expand_dims(m2, 2)
    im = np.concatenate((m0,m1,m2),2)
    print("shape:{}".format(im.shape))
    imshow(im)
    show()
    return im


def add(i, j):
    print("adding in python : {}".format(i + j))
    return (i + j)


def case1():
    m = [[0,50],[60,80]]
    probe_mat(m,m,m)


def case2():
    im = cv2.imread("test_im.jpg")
    cv2.imshow("w",im)
    cv2.waitKey(0)
    cv2.destroyAllWindows()


if __name__ == '__main__':

    # case1()
    case2()