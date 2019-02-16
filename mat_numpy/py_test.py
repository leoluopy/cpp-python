from pylab import *
import numpy as np
def test_mat(m):
    print("Inside python m = \n ", m)
    m[0, 0] = 10
    m[1, 1] = 99

    print("shape:{}".format(m.shape))
    print("line:{}".format(m[0]))
    print("line:{}".format(m[1]))
    return m


def probe_mat(m0,m1,m2):
    print("Inside python m0 = \n ", m0)
    m0 = np.expand_dims(m0, 2)
    m1 = np.expand_dims(m1, 2)
    m2 = np.expand_dims(m2, 2)
    im = np.concatenate((m0,m1,m2),2)
    imshow(im)
    show()
    return im


def add(i, j):
    print("adding in python : {}".format(i + j))
    return (i + j)


if __name__ == '__main__':
    m = [[0,50],[60,80]]
    probe_mat(m,m,m)