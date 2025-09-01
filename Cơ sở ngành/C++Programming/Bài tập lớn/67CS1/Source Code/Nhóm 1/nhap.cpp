#include "thuvien.h"

void kiemtradinhdang(int& a, string c) {
	float b; a = 0;
	while (a <= 0 ) { 
		while (a == static_cast<int>(a)) {
			cout << "Nhap " << c << ": ";
			cin >> b;
			if (b == static_cast<int>(b)) {
				a = static_cast<int>(b);
				break;
			}
			else {
				cout << "Nhap sai dinh dang. Yeu cau nhap lai \n";
			}
		}
		if (a > 0) {
			break; 
		} else {
			cout << "Nhap sai dinh dang. Yeu cau nhap lai \n";
		}
	}
}

void nhapmonhoc(Monhoc mon[10], int m) {
	float tientinchi;
	cout << "Nhap tien 1 tin chi: ";
	cin >> tientinchi;
	for (int i = 0; i < m; i++) {
		fflush(stdin);
		cout << "Nhap ten mon hoc thu " << i + 1 << ": ";
		getline(cin, mon[i].tenmon);
		kiemtradinhdang(mon[i].tinchi, "so tin chi");
	}
}

void nhapsinhvien(Sinhvien sv[], Monhoc mon[], int n, int m) {
	for (int x = 0; x < n; x++) {
        fflush(stdin) ;
		cout << "Nhap ten sinh vien thu " << x + 1 << ": ";
		getline(cin, sv[x].tensv);
		sv[x].somon = m+1; 
		while (sv[x].somon > m) {
			kiemtradinhdang(sv[x].somon, "so mon dang ky");
			if (sv[x].somon <= m) { 
				break; 
			} else {
				cout << "So mon ban nhap lon hon so mon hien co. Yeu cau nhap lai." << endl;
			}
		}
		for (int j = 0; j < sv[x].somon; j++) {
            //fflush(stdin);
			int x = 0;
			while (x == 0) {
            	fflush(stdin);
				cout << "Mon " << j + 1 << ": ";
				getline(cin, sv[x].mondky[j]);
				int x = 0;
				for (int i = 0; i < m; i++) {
					if (sv[x].mondky[j] == mon[i].tenmon) x += 1;
				}
				if (x != 0) {
					break; 
				} else {
					cout << "Mon hoc ban chon khong co trong danh sach. Yeu cau nhap lai." << endl; 
				}
			}
		}
	}
}