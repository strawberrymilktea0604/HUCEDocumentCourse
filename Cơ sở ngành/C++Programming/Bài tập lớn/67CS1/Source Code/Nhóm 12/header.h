#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <regex>

using namespace std;

struct MonHoc {
    string ten;
    int tinChi;
    float diemTX1;
    float diemTX2;
    float diemKT;
    float diemTK;
    float diemHe4;
    string diemChu;
};

struct SinhVien {
    string ten;
    string maSinhVien;
    string lop;
    float GPA;
    int soMonHoc;
    MonHoc monhoc[100];
}; SinhVien sinhvien[100];

void menu();
void nhapSinhVien(int&, SinhVien[]);
void nhapMonHoc(int, SinhVien[]);
void nhapDiem(int, int, SinhVien[]);
void tinhDiem(int, int, SinhVien[]);
void quyDoiDiem(int, int, SinhVien[]);
void tinhGPA(int, SinhVien[]);
void xemDanhSach(int, SinhVien[]);
void suaThongTin(int, SinhVien[]);
void xemSinhVien(int, SinhVien[]);
int timKiem(int, SinhVien[]);
void xemTimKiem(int, SinhVien[]);
void xoaSinhVien(int&, SinhVien[]);
void docFile(int&, SinhVien[]);
void ghiFile(int, SinhVien[]);
void thongKe(int, SinhVien[]);
string kiemTraTen();
int kiemTraKyTu(string);
string inHoa(string&);
string xoaKhoangTrang(string&);
string kiemTraTenMonHoc();
int kiemTraSo();
int kiemTraSoLuong();
string kiemTraMaSinhVien(int, SinhVien[]);
double kiemTraDiem();
string xoaKhoangTrang(string&);
string inHoa(string&);
