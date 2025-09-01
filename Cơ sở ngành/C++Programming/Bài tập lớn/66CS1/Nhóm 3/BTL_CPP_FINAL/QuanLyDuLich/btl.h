#ifndef BTL_H_INCLUDED
#define BTL_H_INCLUDED

#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cctype>
#define MAX 100

using namespace std;

struct QLDL {
    string ten;
    int so_khach[12];
    int gia_tien;
    int doanh_thu;
    int tong_so_khach;
};

void title();

void menu();

void themDiaDiem(QLDL &diadiem, int n);

void thongTinDiaDiem(QLDL &diadiem);

void danhSachDiaDiem(QLDL arr[], int n);

void timDiaDiem(QLDL arr[], int n);

string lower(string str);

void xoaDiaDiem(QLDL arr[], int &n);

void tinhDoanhThu(QLDL &diadiem);

void thongKe(QLDL arr[], int n);

void luuFile(QLDL qldl[], int n, string filename);

void loadFile(QLDL qldl[], int &n, string filename);

#endif // BTL_H_INCLUDED
