#include<iostream> 
#include<string> 
#include<fstream>
#include<cctype>

using namespace std; 

typedef struct Sinhvien Sinhvien;
typedef struct Monhoc Monhoc;

struct Sinhvien {
	string tensv; 
	string mondky[10];
	int somon;
};
struct Monhoc {
	string tenmon; 
	int tinchi; 
};

void dinhdangten(string& s);

void kiemtradinhdang(int& a, string c);

void nhapmonhoc(Monhoc mon[10], int m);

void nhapsinhvien(Sinhvien sv[], Monhoc mon[], int n, int m);

void xoaSinhVien(Sinhvien sv[20], int& n);

void themSinhvien(Sinhvien sv[20], int& n);

void timkiemsinhvientheoten(Sinhvien sv[], int n);	

void xuat_terminal(Sinhvien sv[20], Monhoc mon[10], int& n, int& m  );

void xuat_file(Sinhvien sv[20], Monhoc mon[10], int& n, int& m);