# Nhập mật khẩu đến khi đúng thì thoát
mat_khau = "123123"

while True:
    nhap_mat_khau = input("Nhap vao mat khau ")
    if (nhap_mat_khau == mat_khau):
        break

