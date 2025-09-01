#include<iostream>
#include<cstring>
#include "QuanLy1.h"
#include<stdlib.h>

using namespace std;

void xoaKhoangTrangDauCuoi(string &s){
	while (s[0] == ' '){
		s.erase(s.begin() + 0);
	}
	
	while (s[s.length() - 1] == ' '){
		s.erase(s.end() + 0);
	}
}

void xoaKhoangTrangThua(string &s){
	for (int i = 0; i < s.length(); i++){
		if (s[i] == ' ' && s[i + 1] == ' '){
			s.erase(s.begin() + i + 1);
			i--;
		}
	}
}

void xoaKyTuThua(string &s){
	for (int i = 0; i < s.length(); i++){
		if (s[i + 1] == s[i]){
			s.erase(s.begin() + i + 1);
			i--;
		}
	}
}

string chuyenVeKyTuThuong(string s){
	for (int i = 0; i < s.length(); i++){
		if (static_cast<int>(s[i]) >= 65 && static_cast<int>(s[i]) <= 90){
			s[i] = tolower(s[i]);
		}
	}
	return s;
}

void vietHoaChuCaiDau(string &s){
	if (static_cast<int>(s[0]) >= 97 && static_cast<int>(s[0]) <= 122){
		s[0] = toupper(s[0]);
	}
}

void nhapSP(sanPham sp[], int &n, const int Max, int &m){	
	for (int i = 0; i < n; i++){
		cout << "San pham thu " << i + 1 << ": \n";
		cout << endl;
		cout << "Ma san pham: ";
		cin >> sp[i].maSanPham;
		while (cin.fail()){
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Khong hop le. Moi nhap so nguyen: ";
			cin >> sp[i].maSanPham;
		}
		while (sp[i].maSanPham < 0 || cin.fail()){
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Gia tri khong hop le. \nMoi ban nhap lai ma san pham: ";
			cin >> sp[i].maSanPham;
		}
		if (i >= 1){
			for (int j = 0; j < i; j++){
				while (sp[j].maSanPham == sp[i].maSanPham || cin.fail()){
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Ma san pham bi trung hoac nhap sai. Moi ban nhap lai ma: ";
					cin >> sp[i].maSanPham;
					j = 0;
				}
			}
		}
			
		cout << "Ten san pham: ";
		cin.ignore();
		getline(cin, sp[i].tenSanPham);
		xoaKhoangTrangDauCuoi(sp[i].tenSanPham);
		xoaKhoangTrangThua(sp[i].tenSanPham);	
		xoaKyTuThua(sp[i].tenSanPham);
		vietHoaChuCaiDau(sp[i].tenSanPham);
		cout << "Gia san pham: ";
		cin >> sp[i].gia;
		while (sp[i].gia < 0 || cin.fail()){
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Gia tri khong hop le. \nMoi ban nhap lai gia san pham: ";
			cin >> sp[i].gia;
		}
		cout << "____________________________" << endl;
	}
		for (int i = 0; i < n; i++) {	
		cout << "So luong kinh doanh cua " << sp[i].tenSanPham << ": \n";
		for (int j = 0; j < m; j++) {
		cout << "So luong san pham ban duoc trong ngay " << j + 1 << ": ";	
		cin >> sp[i].soLuong[j];
		while (sp[i].soLuong[j] < 0 || cin.fail()){
			cin.clear();
			cin.ignore(100, '\n');
			cout << "So luong khong hop le. Moi nhap lai: ";
			cin >> sp[i].soLuong[j];
		}
		}
	}
}

void themSP(sanPham sp[], int &n, int &nNew, int &mNew){
	for (int i = n; i < (n + nNew); i++){
		cout << "San pham thu " << i + 1 << ": \n";
		cout << endl;
		cout << "Ma san pham: ";
		cin >> sp[i].maSanPham;
		while (cin.fail()){
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Khong hop le. Moi nhap so nguyen: ";
			cin >> sp[i].maSanPham;
		}
		while (sp[i].maSanPham < 0 || cin.fail()){
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Gia tri khong hop le. \nMoi ban nhap lai ma san pham: ";
			cin >> sp[i].maSanPham;
		}
		if (i >= 1){
			for (int j = 0; j < i; j++){
				while (sp[j].maSanPham == sp[i].maSanPham || cin.fail()){
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Ma san pham bi trung hoac nhap sai. Moi ban nhap lai ma: ";
					cin >> sp[i].maSanPham;
					j = 0;
				}
			}
		}
			
		cout << "Ten san pham: ";
		cin.ignore();
		getline(cin, sp[i].tenSanPham);
		xoaKhoangTrangDauCuoi(sp[i].tenSanPham);
		xoaKhoangTrangThua(sp[i].tenSanPham);	
		xoaKyTuThua(sp[i].tenSanPham);
		vietHoaChuCaiDau(sp[i].tenSanPham);
		cout << "Gia san pham: ";
		cin >> sp[i].gia;
		while (sp[i].gia < 0 || cin.fail()){
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Gia tri khong hop le. \nMoi ban nhap lai gia san pham: ";
			cin >> sp[i].gia;
		}
		cout << "____________________________" << endl;
	}
	
	for (int i = n; i < (n + nNew); i++) {	
		cout << "So luong kinh doanh cua " << sp[i].tenSanPham << ": \n";
		for (int j = 0; j < mNew; j++) {
		cout << "So luong san pham ban duoc trong ngay " << j + 1 << ": ";	
		cin >> sp[i].soLuong[j];
		while (sp[i].soLuong[j] < 0 || cin.fail()){
			cin.clear();
			cin.ignore(100, '\n');
			cout << "So luong khong hop le. Moi nhap lai: ";
			cin >> sp[i].soLuong[j];
		}
		}
	}
	
	n = n + nNew;
}

void xemToanBo(sanPham sp[], int &n, int &m){
	if (n == 0) {
		cout << "Hien khong co san pham. Vui long nhap vao san pham." << endl; 
	} else {
		for (int i = 0; i < n; i++) {
			cout<<"Ma san pham: "<<sp[i].maSanPham<<endl;
			cout<<"Ten san pham: "<<sp[i].tenSanPham<<endl;
			cout<<"Gia san pham: "<<sp[i].gia<<endl;
			for (int j = 0; j < m; j++) {
				if (sp[i].soLuong[j] == 0){
					continue;
				}
				cout << "Ngay " << j + 1 << " ban duoc: ";
				cout<< sp[i].soLuong[j] << endl;
			}
			cout << endl;
		}	
	}
}

void timKiem(sanPham sp[], int &n, int &m) {
	int maSP;
	string tenSP;
	int choice1;
	bool found = false;
	if (n == 0) {
		cout << "Khong co san pham de tim. Vui long nhap vao san pham." << endl;
		return;
	} 	
	cout << "Ban muon tim kiem bang cach nao: " << endl;
	cout << "1. Tim kiem bang ma san pham: " << endl;
	cout << "2. Tim kiem bang ten san pham: " << endl;
	cin >> choice1;
	while (cin.fail()){
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Lua chon khong hop le. Moi nhap lai: ";
		cin >> choice1;
	}
	switch (choice1){
	case 1: {
		cout << "Moi ban nhap ma san pham: " << endl;
		cin >> maSP;
		while (maSP < 0 || cin.fail()){
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Khong hop le. Moi nhap lai: ";
			cin >> maSP;
		}
		for (int i = 0; i < n; i++) {
			if (sp[i].maSanPham == maSP) {
				int sum = 0;
				cout << "Ten san pham: " << sp[i].tenSanPham << endl;
				cout << "Ma san pham: " << sp[i].maSanPham << endl;
				cout << "Gia san pham: " << sp[i].gia << endl;
				cout << "So luong san pham ban duoc: ";
				for (int j = 0; j < m; j++) {
					sum += sp[i].soLuong[j];
				}
				cout << sum << endl;
				found = true;
			}
		}
		if (found == false){
			cout << "Khong tim thay san pham. \n";
		}
		break;
	}
	case 2:{
		cout << "Moi ban nhap ten san pham: " << endl;
		cin.ignore();
		getline(cin, tenSP);
		cout << endl;
		for (int i = 0; i < n; i++) {
			if ((chuyenVeKyTuThuong(sp[i].tenSanPham).find(chuyenVeKyTuThuong(tenSP)) != string::npos) || (chuyenVeKyTuThuong(sp[i].tenSanPham) == chuyenVeKyTuThuong(tenSP))) {
				int sum = 0;
				cout << "Ten san pham: " << sp[i].tenSanPham << endl;
				cout << "Ma san pham: " << sp[i].maSanPham << endl;
				cout << "Gia san pham: " << sp[i].gia << endl;
				cout << "So luong san pham ban duoc: ";
				for (int j = 0; j < m; j++) {
					sum += sp[i].soLuong[j];
				}
				cout << sum << endl;
				found = true;
			}
			cout << endl;
	}
		if (!found){
			cout << "Khong tim thay san pham." << endl;
		}
		break;
	}
	default:
		cout << "Lua chon khong hop le" << endl;
	}
} 

void thongKe(sanPham sp[], int &n, int &m) {
	if (n == 0) {
		cout << "Khong co san pham de thong ke. Vui long nhap vao san pham." << endl;
	} else {
		int tongDoanhThu = 0;
		for (int i = 0; i < n; i++) {
			int sum = 0;
			int tong = 0;
			cout << "Doanh thu cua " << sp[i].tenSanPham << " la: ";
			for (int j = 0; j < m; j++) {
				sum += sp[i].soLuong[j];
			}
			tong = sum*sp[i].gia;
			cout << tong << endl;
			tongDoanhThu += tong;
		}
		cout << "Tong doanh thu cua hang la: " << tongDoanhThu << endl;
	}
}

void xoaSanPham(sanPham sp[], int &n) {	
    if(n == 0){
    	cout << "khong tim thay san pham de xoa." << endl;
    	return;
	}
    string tenSanPham;
    cout << "Nhap ten san pham ma ban muon xoa:";
    cin.ignore();
    getline(cin, tenSanPham);
	fflush(stdin); 
    bool found = false;
    int index = -1;
    for(int i=0; i<n; i++){
        if(chuyenVeKyTuThuong(sp[i].tenSanPham) == chuyenVeKyTuThuong(tenSanPham))
        {
            index = i;
            found = true;
            break;
        }
        continue; 
    }

    if(found){
        for(int i = index; i < n; i++){
            sp[i] = sp[i + 1];
        }
        cout << "Xoa thanh cong san pham." << endl; 
        n--;
    }
    else {
    	cout << "Khong tim thay san pham." << endl; 
	}
}

void show(){
	cout << "_____________________CUA HANG DIEN MAY____________________" << endl;
	cout << "|              1.Nhap thong tin san pham:                |" << endl;
	cout << "|              2.Xem toan bo san pham:                   |" << endl;
	cout << "|              3.Tim kiem san pham:                      |" << endl;
	cout << "|              4.Xoa san pham:                           |" << endl;
	cout << "|              5.Thong ke san pham:                      |" << endl;
	cout << "|              6.Them san pham:                          |" << endl;
	cout << "|              7.Thoat:                                  |" << endl;
	cout << "==========================================================" << endl;
}



