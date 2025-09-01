#ifndef DIEMDANH_H
#define DIEMDANH_H

#include <iostream>
#include <string>
#include<algorithm>
#include<fstream>
#include<sstream>

using namespace std;

const int MAX_N = 31;
const int MAX_M = 50;

struct SinhVien {
    string hoTen;
    string maSV;
    string ngaySinh;
    string diaChi;
    string dienThoai;
    string email;
};

void nhapDanhSachSV(SinhVien dsSV[], int& n);

void xemDanhSachSV(SinhVien dsSV[], int n);

void diemDanh(SinhVien dsSV[], int n, int**& dd, int& m);

void timKiem(SinhVien dsSV[], int n);

void xoaSinhVien(SinhVien dsSV[], int& n);

void thongKe(const SinhVien dsSV[], int n, int** dd, int m);

void nhapTuFile(const string& tenFile, SinhVien dsSV[], int& n, int**& dd, int& m);

void xuatRaFile(const string& tenFile, const SinhVien dsSV[], int n, const int* const* dd, int m);

bool kiemTraGiaTriDauvao();

bool kiemTraGioiHan(int giaTri, int gioiHanNhoNhat, int gioiHanLonNhat);

#endif