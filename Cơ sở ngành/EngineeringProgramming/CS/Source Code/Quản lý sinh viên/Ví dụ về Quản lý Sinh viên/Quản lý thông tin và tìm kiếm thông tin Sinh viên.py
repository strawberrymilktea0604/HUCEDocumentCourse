# -*- coding: utf-8 -*-
"""
Created on Tue Jun  6 07:38:53 2023

@author: minhk
"""

class SinhVien:
    def __init__(self, hoten, lop, gioitinh):
        self.hoten = hoten
        self.lop = lop
        self.gioitinh = gioitinh
        
soSinhVien = int(input("Nhap so luong sinh vien: "))
def nhapThongTin():
    list = []
    for i in range(soSinhVien):
        hoten = input("Nhap ho va ten sinh vien thu {}: ")
        lop = input("Nhap ten lop sinh vien: ")
        gioitinh = input("Nhap gioi tinh sinh vien: ")
        list.append(SinhVien)
    return list

def xuatthongtin(list):
    i = 0
    for sinhvien in list:
        print("Thong tin sinh vien thu {}".format(i + 1))
        print("Ho ten: {}".format(sinhvien.hoten))
        print("Lop: {}".format(sinhvien.lop))
        print("Gioi tinh: {}".format(sinhvien.gioitinh))
        i += 1
        
        
def timkiemSinhVienNam(list):
    list2 = []
    for sinhvien in list:
        if sinhvien.gioitinh.lower() == 'nam':
            list2.append(sinhvien)
    return list2


def timkiemTen(list, name):
    list3 = []
    for sinhvien in list:
        list4 = sinhvien.hoten.split()
        if list4[len(list4) - 1].lower() == name:
            list3.append(sinhvien)
    return list3

danhsach = nhapThongTin()
xuatthongtin(danhsach)
danhsachNam = timkiemSinhVienNam(danhsach)
if len(danhsachNam) == 0:
    print("Khong co sinh vien nam")
else:
    print("Danh sach sinh vien nam")
    xuatthongtin(danhsachNam)
    
name = input("Nhap ten sinh vien can tinh kiem: ")
danhsachTen = timkiemTen(danhsach, name)
len()
