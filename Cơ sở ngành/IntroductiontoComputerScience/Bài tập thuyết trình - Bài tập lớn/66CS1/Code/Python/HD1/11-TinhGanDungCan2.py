def f(x):
    return(x*x-2)
l = 1
r = 2
err = 0.0000000001
while (r-l>err):
    m = (l+r)/2
    if (f(m)<0):
        l = m
    elif (f(m)>0):
        r = m
    else:
        print("Căn 2 bằng ", m)
print("Giá trị gần đúng của căn 2 là ", r, "(Sai số < ", err, ")")

