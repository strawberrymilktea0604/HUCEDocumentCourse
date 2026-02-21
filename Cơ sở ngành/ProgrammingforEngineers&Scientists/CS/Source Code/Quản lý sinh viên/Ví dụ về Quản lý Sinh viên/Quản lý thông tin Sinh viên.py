class SinhVien:
    def __init__(self, hoten, lop, gioitinh):
        self.hoten = hoten
        self.lop = lop
        self.gioitinh = gioitinh
        
soSinhVien = int(input("Nhập số lượng sinh viên : "))
def nhapThongTin():
    list = []
    for i in range(soSinhVien):
        hoten = input("Nhập họ tên sinh viên thứ {} : ".format(i+1))
        lop = input("Nhập tên lớp sinh viên {} : ".format(hoten))
        gioitinh = input("Nhập giới tính sinh viên {} : ".format(hoten))
        sinhvien = SinhVien(hoten, lop, gioitinh)
        list.append(sinhvien)
    return list

def xuatThongTin(list):
    i = 0
    for sinhvien in list:
        print("Thông tin sinh viên thứ {}".format(i+1))
        print("Họ tên : {}".format(sinhvien.hoten))
        print("Lớp : {}".format(sinhvien.lop))
        print("Giới tính : {}".format(sinhvien.gioitinh))
        i += 1
        
def timKiemSinhVienNam(list):
    list2 = []
    for sinhvien in list:
        if sinhvien.gioitinh.lower() == 'nam':
            list2.append(sinhvien)
    return list2

def timKiemTen(list, name):
    list3 = []
    for sinhvien in list:
        list4 = sinhvien.hoten.split()
        if list4[len(list4) - 1].lower() == name:
            list3.append(sinhvien)
    return list3

danhSach = nhapThongTin()
xuatThongTin(danhSach)
danhSachNam = timKiemSinhVienNam(danhSach)
if len(danhSachNam) == 0:
    print("\nKhông có sinh viên nào giới tính nam trong danh sách")
else:
    print("\nDanh sách các sinh viên nam")
    xuatThongTin(danhSachNam)
name = input("\nNhập tên sinh viên cần tìm kiếm : ")
danhSachTen = timKiemTen(danhSach, name)
if len(danhSachTen) == 0:
    print("\nKhông có sinh viên nào tên {} trong danh sách".format(name))
else:
    print("\nDanh sách các sinh viên có tên {}".format(name))
    xuatThongTin(danhSachTen)