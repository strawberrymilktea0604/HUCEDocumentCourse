# Nhập mật khẩu đến khi đúng thì thoát
mat_khau = "123123"
password = input("Nhap mat khau")
while mat_khau != password :
    print("Mat khau khong dung")
    password = input("Nhap lai")
if mat_khau == password :
    print("mat khau chinh xac")