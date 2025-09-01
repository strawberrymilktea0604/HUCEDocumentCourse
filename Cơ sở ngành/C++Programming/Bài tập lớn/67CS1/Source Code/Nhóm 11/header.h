#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include <cctype>
#include <limits>
#include <regex>
using namespace std;

const int songay = 20;//so ngay trong thang nha hang phuc vu
struct Donhang{
	string tenmonan;
	int soluong;
};
struct Khachhang{
	string  tenkh;
	string sdt;
	int somonan;
	Donhang donhang[20];	
};
Khachhang khachhang[20];
int nhapsn() ;
string viethoatenrieng(string str);
string trim(string str);
bool kiemtrasdt(string phone);
void nhapsl(int monan_i,int vtrmonan, Khachhang khachhang[] );
void nhapmonan(int monan_i,Khachhang khachhang[]);
void Nhapkh(int &sokhachhang ,Khachhang khachhang[] );
void xemdon(int vt,Khachhang khachhang[]);
void xemds(int sokhachhang , Khachhang khachhang[]);
int timvt(int sokhachhang , Khachhang khachhang[]);
void sua(int sokhachhang , Khachhang khachhang[]);
void timkiem(int sokhachhang , Khachhang khachhang[]) ;
void thongke(int sokhachhang , Khachhang khachhang[]);
void read(string filename,int& sokhachhang , Khachhang khachhang[]);
void write(int sokhachhang , Khachhang khachhang[]);
void displayMenu();
