#include "thuvien.h"

void timkiemsinhvientheoten(Sinhvien sv[], int n) {
	string tenSinhVien;
	cout << "Nhap ten sinh vien can tim kiem: ";
	cin.ignore();
	getline(cin, tenSinhVien);

	bool found = false;
	for (int i = 0; i < n; i++) {
		if (sv[i].tensv == tenSinhVien) {
			cout << "Thong tin sinh vien:" << endl;
			cout << "Ten: " << sv[i].tensv << endl;
			cout << "So mon hoc: " << sv[i].somon << endl;
			cout << "Cac mon hoc da dang ky:" << endl;
			for (int j = 0; j < sv[i].somon; j++) {
				cout << sv[i].mondky[j] << endl;
			}
			found = true;
			break;
		}
	}

	if (!found) {
		cout << "Khong tim thay sinh vien co ten " << tenSinhVien << endl;
	}
}
