def test_mat(m):
    print ("Inside python m = \n ",m )
    m[0,0] = 10
    m[1,1] = 99

    print("shape:{}".format(m.shape))
    print("line:{}".format(m[0]))
    print("line:{}".format(m[1]))
    return m