// Khai bao ham nguyen mau
#pragma once
#include <iostream>
#include <fstream>
#include <string> 
 using namespace std;
  
const int MAXN = 1000; // Gioi han so cong nhan

struct CongNhan { 
    string hoTen;
    float ngayCong; 
    float sanPham;
    int soLuong; 

 
};

int n; // So cong nhan hien tai 
 CongNhan a[MAXN];


void nhapThongTin(CongNhan& cn);
void nhapSoLuong();
void themMoi();
void xemDanhSach();
void timKiem();
void xoaCongNhan();
void thongKe();
void Input();
void Output(); 
