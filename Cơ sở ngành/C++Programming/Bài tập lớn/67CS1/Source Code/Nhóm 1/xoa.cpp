#include "thuvien.h"

void xoaSinhVien(Sinhvien sv[],int &n){
	int count = 0;
	bool check = true;
	string tenSinhVien;
    int index; index = 0;
    fflush(stdin);
	cout << "Nhap ten sinh vien ban muon xoa: ";
	getline(cin, tenSinhVien);

	while(check) {
		for(int k = 0; k < n; k++) {
		if(sv[k].tensv == tenSinhVien) {
			count = 1;
		}
		}
		if(count != 1){
			cout << "Ten sinh vien khong co trong danh sach" << endl;
			cout << "Nhap lai ten sinh vien ban muon xoa: ";
			getline(cin, tenSinhVien);
		}
		else {
			check = false;
		}
	}

	for(int i = 0; i < n; i++) {
		if(sv[i].tensv == tenSinhVien){
			index = i;
			for (int j = index ; j < n - 1; j++){
				sv[j] = sv[j + 1];
			}
			n--;
		}
	}
    
	for(int i = 0; i < n; i ++){
        cout << sv[i].tensv << endl;
    }
}