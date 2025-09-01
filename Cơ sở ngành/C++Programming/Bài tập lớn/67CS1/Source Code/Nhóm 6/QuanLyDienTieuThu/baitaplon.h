#include<iostream>
#include<string>
#include<string.h>
#include<iomanip>
#include<fstream>
#include<cstring>
#include<regex>
#define MAX 100

using namespace std;

struct QLDTT {
	string tenhogiadinh;
	int luongdientieuthu[12];
	int tiendien;
	int doanhthu;
	int tongdienluongtieuthu;

};

void title();
void menu();
void themHogiadinh(QLDTT &ten, int n);
void thongtinHogiadinh(QLDTT &ten);
void danhsachHogiadinh(QLDTT arr[], int n);
void timHogiadinh(QLDTT arr[], int n);
string lower(string str);
void xoaHogiadinh(QLDTT arr[], int &n);
void tinhdoanhthu(QLDTT &diadiem);
void thongke(QLDTT arr[], int n);
void luufile(QLDTT qldl[], int n, string filename);
void loadfile(QLDTT qldl[], int &n, string filename);
