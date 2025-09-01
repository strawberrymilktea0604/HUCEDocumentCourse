#include<iostream>
#include<string>
#include<string.h>
#include<iomanip>
#include<fstream>
#include<cstring>
#include<cctype>
#include<regex>
#include "quanli.h"

using namespace std;

int main() {
	regex pattern("^[1-9]$|^1[0-9]$|^2[0-9]$|^3[0-1]$");
    char out;
    int key;
    bool hopli = false;
    bool keyboard = false;
    int x;
    string input;
    do{
    	cout<<"Nhap vao so ngay lam viec : ";
    	cin>>input;
   		if(regex_match(input,pattern)){
    		cout<<"Ngay Lam Viec Hop Le , Hay Tiep Tuc !"<<endl;
		}else{
			cout<<"Ngay Lam Viec Khong Hop Le , Vui Long Nhap Dung !"<<endl;
			hopli = true;
		}
	}while(hopli);
	int ngayLamViec = stoi(input);
    NgayLamViec danhsach[31];
    do {
        cout << "**********************************************\n";
        cout << "**       CHUONG TRINH QUAN LI BEP AN        **\n";
        cout << "**  1.Nhap Vao Thong Tin                    **\n";
        cout << "**  2.Xuat Danh Sach Ngay Lam Viec          **\n";
        cout << "**  3.Tim Kiem Thong Tin Ngay Lam Viec      **\n";
        cout << "**  4.Thong Ke Chi Phi Ngay Lam Viec        **\n";
        cout << "**  5.Exit Program                          **\n";
        cout << "----------------------------------------------\n";
        cout << "----------Moi Ban Nhap Lua Chon---------------\n";
        cin >> key;

        switch (key) {
            case 1:
                cout << "\nBan da chon nhap vao thong tin!" << endl;
                nhapDanhSachNgayLamViec(danhsach, ngayLamViec);
                cout << "\nBan da nhap xong!" << endl;
                keyboard = true;
                break;
            case 2:
                if (keyboard) {
                    cout << "\nBan da chon xuat danh sach thong tin cac ngay lam viec!" << endl;
                    xuatThongTinNgayLamViec(danhsach, ngayLamViec);
                } else {
                    cout << "\nNhap vao thong tin truoc!" << endl;
                }
                break;
            case 3:
                cout << "\nBan da chon tim kiem theo ngay lam viec!" << endl;
                if (keyboard) {
                    timKiemTheoNgayLamViec(danhsach, ngayLamViec);
                } else {
                    cout << "\nNhap vao thong tin truoc!" << endl;
                }
                break;
            case 4:
                cout << "\nBan da chon xem thong ke chi phi!" << endl;
                if (keyboard) {
                    thongKeChiPhi(danhsach, ngayLamViec);
                } else {
                    cout << "\nNhap vao thong tin truoc!" << endl;
                }
                break;
            case 5:
                cout << "\nBan da chon thoat chuong trinh!" << endl;
                return 0;
            default:
                cout << "\nKhong co lua chon nay"<<endl;
                break;
			}
		cout<<"Ban co muon thoat chuong trinh ? (Y/N) :";
		cin>>out;
		if(out == 'y' || out == 'Y'){
			cout<<"Ban da chon thoat chuong trinh ! "<<endl;
			break;
		}
	}while(out == 'n' || out == 'N');
		return 0;
	}

