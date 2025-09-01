#include<iostream>
#include<string>
#include<string.h>
#include<iomanip>
#include<fstream>
#include<cstring>
#include<cctype>
#include<regex>
#include "quanli.h"

//ham nhap thong tin cua nguyen lieu
void nhapThongTinNguyenLieu(NguyenLieu &NL){
	cin.ignore();
	cout<<"nhap ten nguyen lieu : ";
	getline(cin,NL.tennguyenlieu);
	cout<<"nhap so luong cua nguyen lieu nay : ";
	cin>>NL.soluong;
	cout<<"nhap gia tien cua loai nguyen lieu nay : ";
	cin>>NL.giatien;

}
//ham giup nhap danh sach cac nguyen lieu
void nhapDanhSachNguyenLieu(NguyenLieu ds[] , int n ){
	for(int i = 0; i < n ;i ++){
		cout<<"nhap nguyen lieu thu "<<(i + 1)<<" : "<<endl;
		nhapThongTinNguyenLieu(ds[i]);
	}
}
//ham nhap thong tin cua ngay lam viec
void nhapNgayLamViec(NgayLamViec &nlv){
	cin.ignore();
	cout<<"nhap vao ngay trong thang : ";
	cin>>nlv.ngay;
	cout<<"nhap vao thang lam viec : ";
    cin>>nlv.thang;
    cout<<"nhap vao so luong nguyen lieu trong ngay "<<nlv.ngay<<" thang "<<nlv.thang<<" : ";
    cin>>nlv.sonl;
    int x = nlv.sonl;
    nhapDanhSachNguyenLieu(nlv.NL,x);
}
//ham giup nhap danh sach ngay lam viec
void nhapDanhSachNgayLamViec(NgayLamViec ds[] ,int n){
	for(int i = 0; i < n; i++){
		cout<<"Nhap thong tin ngay lam viec thu "<<(i+1)<<endl;;
		nhapNgayLamViec(ds[i]);
}
}
//ham tinh chi phi
float tongChiPhiNgay(NgayLamViec &nlv){
	float tong = 0;
	for(int i = 0; i < nlv.sonl; i++){
		tong += nlv.NL[i].giatien * nlv.NL[i].soluong;
	}
	return tong;
}

//ham xuat ra man hinh thong tin ngay lam viec
void xuatNgayLamViec(NgayLamViec &nlv){
    cout<<"Ngay "<<nlv.ngay<<" Thang "<<nlv.thang<<endl;
    cout<<"So luong nguyen lieu trong ngay "<<nlv.sonl<<" : "<<endl;
    for(int i = 0; i < nlv.sonl ; i++){
        cout<<"Ten Nguyen Lieu : "<<nlv.NL[i].tennguyenlieu<<endl;
        cout<<"So Luong : "<<nlv.NL[i].soluong<<endl;
    }
    float chiphi = tongChiPhiNgay(nlv);
    cout<<"Tong tien nguyen lieu trong ngay lam viec : "<<chiphi<<endl;
}

//ham xuat ra man hinh danh sach nhung ngay lam viec
void xuatThongTinNgayLamViec(NgayLamViec ds[] , int n){
	if(n > 0 ){
		cout<<"\t\t\t\t\t\t\t DANH SACH THONG TIN VE NGAY LAM VIEC \n";
		for(int i = 0; i < n; i++){
			cout<<"\t "<<left<<setw(4)<< i+1;
			xuatNgayLamViec(ds[i]);
			cout<<"\n";
		}
		cout<<"\n\t---------------------------------------";
	}else{
		cout<<"\n Chua Co Thong Tin Nao Ve Ngay Lam Viec ! \n";
	}
}
//ham tim kiem thong tin ngay lam viec theo ngay va thang da duoc truyen thong tin
void timKiemTheoNgayLamViec(NgayLamViec ds[], int n) {
    cout << "Tim Kiem Theo Ngay Lam Viec" << endl;
    cout << "Nhap vao ngay can tim: ";
    int ngays, thangs;
    NgayLamViec nlvcantim;
    cin >> ngays;
    cout << "Nhap vao thang can tim: ";
    cin >> thangs;

    //Kiem tra tinh hop le cua ngay va thang
    bool hopLe = true;
    if (ngays < 1 || ngays > 31) {
        hopLe = false;
    }
    else if (thangs < 1 || thangs > 12) {
        hopLe = false;
    }
    else if (thangs == 2) {
        if (ngays > 28) {
            hopLe = false;
        }
    }
    else if (thangs == 4 || thangs == 6 || thangs == 9 || thangs == 11) {
        if (ngays > 30) {
            hopLe = false;
        }
    }
    if (!hopLe) {
        cout << "Ngay hoac thang khong hop le! Hay nhap lai." << endl;
        return;
    }
    //so sanh ngay lam viec
	for(int i = 0; i < n; i++){
		if(ds[i].ngay == ngays  && ds[i].thang == thangs){
			nlvcantim = ds[i];
			xuatNgayLamViec(nlvcantim);
			break;
		}
		else{
			cout<<"Khong tim thay thong tin ngay lam viec nay ! ";
		}
	}

}
//ham thong ke chi phi mua nguyen lieu
void thongKeChiPhi(NgayLamViec ds[], int n){
    double max_Cp = ds[0].chiphi;
    int index_max = 0;
    //duyet mang va so sanh
    for(int i = 0; i < n; i++){
    	if(max_Cp < ds[i].chiphi){
    		max_Cp = ds[i].chiphi;
    		index_max = i;
		}
	}
	int max_NL = ds[0].sonl;
	int index_maxNL = 0;
	for(int j = 0; j < ds[j].sonl; j++){
		if(max_NL < ds[j].sonl){
			max_NL = ds[j].sonl;
			index_maxNL = j;
		}
	}
	cout<<"ngay ton nhieu chi phi nhat la ngay  "<<ds[index_max].ngay<<" thang "<<ds[index_max].thang<<endl;
	cout<<"ngay co nhieu nguyen lieu nhat la ngay "<<ds[index_maxNL].ngay<<" thang "<<ds[index_max].thang<<endl;

}


















