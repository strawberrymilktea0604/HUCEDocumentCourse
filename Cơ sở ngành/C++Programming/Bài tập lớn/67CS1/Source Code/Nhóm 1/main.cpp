#include<cstring>
#include "thuvien.h"

int main() {
	struct Monhoc mon[10];
	struct Sinhvien sv[20];
	int n; 
	kiemtradinhdang(n, "so sinh vien");
	int m;
	kiemtradinhdang(m, "so mon hoc");
	nhapmonhoc(mon, m); 
	cout << "------------\n";
	nhapsinhvien(sv, mon, n, m);
	cout << "------------\n";
	int luachon; 
	while (luachon != 4) {
		cout << " _________________________Menu______________________________" << endl; 
		cout << "|  1. Them sinh vien                                        |" << endl;
		cout << "|  2. Xoa sinh vien                                         |" << endl; 
		cout << "|  3. Tim kiem sinh vien theo ten                           |" << endl; 
		cout << "|  4. Luu danh sach vao file va dung chuong trinh           |" << endl; 
		cout << "|___________________________________________________________|" << endl; 
		cout << "Nhap lua chon cua ban: "; 
		cin >> luachon;
		switch(luachon) {
			case 1: 
				themSinhvien(sv, n);
				xuat_terminal(sv, mon, n, m);
				cout << endl;
				break;
			case 2: 
				xoaSinhVien(sv, n);
				xuat_terminal(sv, mon, n, m);
				cout << endl;
				break;
			case 3: 
				timkiemsinhvientheoten(sv, n); 
				cout << endl;
				break;
			case 4: 
				xuat_terminal(sv, mon, n, m); // xuất ra terminal
				cout << endl;
				xuat_file(sv, mon, n, m); // xuất ra file 
				break;
		}
	}
	return 0;
}