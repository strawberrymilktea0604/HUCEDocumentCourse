def tinh_tong(*args):
    tong = 0
    for x in args:
        tong += x
    return tong

print(tinh_tong(1, 2, 3))
print(tinh_tong(5, 10, 15, 20))