#include"baitaplon.h"

int main() {
	QLDTT qldl[MAX];
	int select, tongsohogiadinh = 0;
	const string FILENAME = "nhapdulieu.txt";
	const string fileName = "xuatdulieu.txt";
	while(true) {
		menu();
		cin >> select;
		switch (select) {
			case 1:
				themHogiadinh(qldl[tongsohogiadinh], tongsohogiadinh);
				tongsohogiadinh++;
				break;
			case 2:
				danhsachHogiadinh(qldl, tongsohogiadinh);
				break;
			case 3:
				timHogiadinh(qldl, tongsohogiadinh);
				break;
			case 4:
				xoaHogiadinh(qldl, tongsohogiadinh);
				break;
			case 5:
				thongke(qldl, tongsohogiadinh);
				break;
			case 6:
				luufile(qldl, tongsohogiadinh, fileName);
				break;
			case 7:
				loadfile(qldl, tongsohogiadinh, FILENAME);
				break;
			case 0:
				cout << "\n\t-Da thoat khoi chuong trinh.\n";
				return 0;
			default:
				cout << "\n\tMoi ban nhap lai.\n";
				break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
