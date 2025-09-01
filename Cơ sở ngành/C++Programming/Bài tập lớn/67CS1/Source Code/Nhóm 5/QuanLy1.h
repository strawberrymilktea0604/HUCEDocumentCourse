#include<iostream>
#include<string>

using namespace std;
using std::string;

struct sanPham{
 	string tenSanPham;
	int maSanPham;
	int gia;
	int soLuong[100];
};
void xoaKhoangTrangDauCuoi(string&);
void xoaKhoangTrangThua(string&);
void xoaKyTuThua(string&);
void vietHoaChuCaiDau(string&);
string chuyenVeKyTuThuong(string);
void nhapSP(sanPham*, int&, const int, int&);
void themSanPham(sanPham*, int&, int&, int&);
void xemToanBo(sanPham*, int&, int&);
void timKiem(sanPham*, int&, int&);
void thongKe(sanPham*, int&, int&);
void xoaSanPham(sanPham*, int&);
void show();
