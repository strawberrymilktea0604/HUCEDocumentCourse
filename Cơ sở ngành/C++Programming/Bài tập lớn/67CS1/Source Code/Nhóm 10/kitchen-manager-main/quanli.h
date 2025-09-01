#include<iostream>
#include<string>
#include<string.h>
#include<iomanip>
#include<fstream>
#include<cstring>
#include<cctype>
#include<regex>
using namespace std;

// Struct luu tru thông tin ve nguyên lieu
struct NguyenLieu {
    string tennguyenlieu;    //ten nguyen lieu
	int soluong;			 //so luong nguyen lieu
	float giatien;			 //gia tien cua loai nguyen lieu nay

};

// Struct luu tru thông tin ve ngày làm viec
struct NgayLamViec {
   int ngay;                 //ngay
   int thang;				 //thang
   int sonl;				 //so luong nguyen lieu trong ngay
   NguyenLieu NL[31];        //chi tiet ve tung nguyen lieu
   float chiphi; 			 //chi phi
};
void nhapThongTinNguyenLieu(NguyenLieu &NL);
void nhapDanhSachNguyenLieu(NguyenLieu ds[] , int n );
void nhapNgayLamViec(NgayLamViec &nlv);
void nhapDanhSachNgayLamViec(NgayLamViec ds[] ,int n);
void xuatNgayLamViec(NgayLamViec &nlv);
void xuatThongTinNgayLamViec(NgayLamViec ds[] , int n);
void timKiemTheoNgayLamViec(NgayLamViec ds[], int n);
void thongKeChiPhi(NgayLamViec ds[],int n);
float tongChiPhiNgay(NgayLamViec &nlv);
