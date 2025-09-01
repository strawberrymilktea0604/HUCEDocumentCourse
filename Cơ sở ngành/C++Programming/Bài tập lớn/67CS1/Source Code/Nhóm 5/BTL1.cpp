#include<iostream>
#include "QuanLy.cpp"
#include<fstream>
#include<string>
#include<cstring>
#include<stdlib.h.>
using namespace std;

int main(){
	int Max = 100; 
	sanPham sp[Max];
	int n; 
	int m;
	int choice; 
	while (true) {
		show();
		cout << "Moi ban nhap lua chon: ";
		cin >> choice;
		while (cin.fail()){
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Khong hop le. Moi nhap so nguyen: ";
			cin >> choice;
		}
		switch (choice) {
			case 1:{
				system("cls");
				cout << "Ban da chon nhap vao san pham: " << endl;
				cout << "Moi ban nhap so san pham: ";
				cin >> n;
				while (n > Max || n < 0 || cin.fail()){
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Gia tri khong hop le (Do them qua 100 san pham hoac nhap vao so am). \nVui long nhap lai: ";
					cin >> n;
				}
				cout << "Moi ban nhap so ngay ban san pham: ";
				cin >> m; 
				while (m < 0 || cin.fail()){
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Gia tri khong hop le. \nMoi ban nhap lai: ";
					cin >> m;
				}
				nhapSP(sp, n, Max, m); 
//				ofstream file;
//				file.open("C://Users//crist//OneDrive//Desktop//QuanLy1.txt");
//				file << n << "\n";
//				file << m << "\n";
//				for (int i = 0; i < n; i++) {
//					file << sp[i].maSanPham << "\n";
//					file << sp[i].tenSanPham << "\n";
//					file << sp[i].gia << "\n";
//					for (int j = 0; j < m; j++) {
//						file << sp[i].soLuong[j] << " "; 
//					}
//					file << "\n"; 
//				} 
				cout << "_____________________________________\n";
//				file.close(); 
				break;
			}
			case 2:{
//				ifstream file;
//				file.open("C://Users//crist//OneDrive//Desktop//QuanLy1.txt");
//				file >> n;
//				file >> m;
//				for (int i = 0; i < n; i++) {
//				file >> sp[i].maSanPham;
//				file.ignore();
//				getline(file, sp[i].tenSanPham);
//				file >> sp[i].gia;
//					for (int j = 0; j < m; j++) {
//						file >> sp[i].soLuong[j];
//						file.ignore(1);
//					}
//				}
				system("cls");
				cout << "Ban da chon xem toan bo: " << endl;
				cout << endl;
				xemToanBo(sp, n, m);
				cout << "_____________________________________\n";
				break;
			}
			case 3:{
//				ifstream file;
//				file.open("C://Users//crist//OneDrive//Desktop//QuanLy1.txt");
//				file >> n;
//				file >> m;
//				for (int i = 0; i < n; i++) {
//				file >> sp[i].maSanPham;
//				file.ignore();
//				getline(file, sp[i].tenSanPham);
//				file >> sp[i].gia;
//					for (int j = 0; j < m; j++) {
//						file >> sp[i].soLuong[j];
//						file.ignore(1);
//					}
//				}
				system("cls");
				cout << "Ban da chon tim kiem: " << endl;
				timKiem(sp, n, m);
				fflush(stdin);
				cout << "_____________________________________\n";
				break;
			}
			case 4: {
				system("cls");
				cout << "Ban da chon xoa san pham: " << endl;
//				ifstream file;
//				file.open("C://Users//crist//OneDrive//Desktop//QuanLy1.txt");
//				file >> n;
//				file >> m;
//				for (int i = 0; i < n; i++) {
//				file >> sp[i].maSanPham;
//				file.ignore();
//				getline(file, sp[i].tenSanPham);
//				file >> sp[i].gia;
//					for (int j = 0; j < m; j++) {
//						file >> sp[i].soLuong[j];
//						file.ignore(1);
//					}
//				}
				for(int i=0; i<n; i++){
     			   cout << sp[i].tenSanPham << endl;
  				}
//  			file.close();
				xoaSanPham(sp, n);
//				ofstream file1;
//				file1.open("C://Users//crist//OneDrive//Desktop//QuanLy1.txt");
//				for (int i = 0; i < n; i++) {
//					file1 << sp[i].maSanPham << "\n";
//					file1 << sp[i].tenSanPham << "\n";
//					file1 << sp[i].gia << "\n";
//					for (int j = 0; j < m; j++) {
//						file1 << sp[i].soLuong[j] << " "; 
//				}
//				file1 << "\n"; 
//				} 
//				file1.close();
				cout << "_____________________________________\n";
				break;
			}
			case 5: {
//				ifstream file;
//				file.open("C://Users//crist//OneDrive//Desktop//QuanLy1.txt");
//				file >> n;
//				file >> m;
//				for (int i = 0; i < n; i++) {
//				file >> sp[i].maSanPham;
//				file.ignore();
//				getline(file, sp[i].tenSanPham);
//				file >> sp[i].gia;
//					for (int j = 0; j < m; j++) {
//						file >> sp[i].soLuong[j];
//						file.ignore(1);
//					}
//				}
				system("cls");
				cout << "Ban da chon thong ke doanh thu: " << endl;
				thongKe(sp, n, m);
				cout << "_____________________________________\n";
				break;
			}
			case 6: {
				system("cls");
				int nNew;
				int mNew;
				cout << "Nhap so san pham ban muon them: ";
				cin >> nNew;
				cout << "Nhap so ngay ban san pham: ";
				cin >> mNew;
				if (mNew > m){
					m = mNew;
				}
				while ((n + nNew) >= Max || cin.fail()){
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Them qua so san pham cho phep: ";
					cin >> nNew;
				}
				themSP(sp, n, nNew, mNew);
				break;
			}
			case 7:
				system("cls");
				cout << "Dang thoat chuong trinh!";
				return false;
				break;
			default:
				cout << "Khong co lua chon." << endl;
		} 
	} 
}
