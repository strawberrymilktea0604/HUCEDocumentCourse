#include "thuvien.h"

void themSinhvien(Sinhvien sv[20], int& n) {
    int choice;
	while (true) {
		cout << "Ban co muon them sinh vien khong? (1: Co, 0: Khong) ";
		cin >> choice;
		if (choice == 1) {
			n++;
			cout << "Nhap thong tin cho sinh vien thu " << n << ":" << endl;
			cout << "Nhap ten sinh vien: ";
			cin.ignore();
			getline(cin, sv[n-1].tensv);
			kiemtradinhdang(sv[n-1].somon, "so mon dang ky");
			for (int j = 0; j < sv[n-1].somon; j++) {
				cout << "Mon " << j + 1 << ": ";
				cin.ignore();
				getline(cin, sv[n-1].mondky[j]);
			}
		}
		else if (choice == 0) {
			break;
		}
		else {
			cout << "Nhap sai lua chon. Vui long nhap lai!" << endl;
		}
	}
}