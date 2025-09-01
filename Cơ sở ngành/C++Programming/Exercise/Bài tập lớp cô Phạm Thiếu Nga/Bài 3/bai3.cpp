#include<iostream>
#include<string> 
#include<fstream>


using namespace std;

//ham doc du lieu tu file
void Docfile(ifstream& data, float diemcacmonhoc[], int soluongmonhoc) {
	for (int i = 0; i < soluongmonhoc; i++) {
		data >>  diemcacmonhoc[i];
	}
	
}

//ham xuat mang 
void Xuatmang(float diemcacmonhoc[], int soluongmonhoc) {
	for (int i = 0; i < soluongmonhoc; i++) {
		cout <<  diemcacmonhoc[i] << " ";
	}
	
}

//ham dem so luong diem be hon 5.5
int soluong(float diemcacmonhoc[], int soluongmonhoc) {
	int dem = 0;
	for(int i = 0; i < soluongmonhoc; i++) {
		if(diemcacmonhoc[i] < 5.5 ) {
			dem++;
		}
	}
	cout << dem << endl;
	return 0;
 }
int main() {
	ifstream data("bai3.txt");
	float diemcacmonhoc[100];
	int soluongmonhoc = 0;
	string hoten;
	if (data.fail()) {
		cout << "Khong mo duoc file!";
		return 1; 
	}
	data >>  soluongmonhoc;
	cout << "So mon hoc sinh vien can phai hoc: " << soluongmonhoc;
	getline(data, hoten);
	ofstream ketqua;
	ketqua.open("outputbai3.txt");
	while (!data.eof()) {
		getline(data, hoten);
	    cout << "\n\nHo va ten sinh vien: " << hoten << endl;
	    ketqua << "\nHo va ten sinh vien: " << hoten << endl; 
	
	    Docfile(data, diemcacmonhoc, soluongmonhoc);

	    cout << "Diem tong ket tung mon hoc cua sinh vien: " << endl; 
	    Xuatmang(diemcacmonhoc, soluongmonhoc);
	    getline(data, hoten);
	    ketqua << "Diem tong ket tung mon hoc cua sinh vien: " << endl; 
	    for (int i = 0; i < soluongmonhoc; i++) {
		    ketqua <<  diemcacmonhoc[i] << " ";
	}
	    cout << "\nSo diem be hon 5.5 cua sinh vien la: ";  
	    soluong(diemcacmonhoc, soluongmonhoc);
} 
	ketqua.close();
	data.close();  
	system("pause"); 
	return 0; 
}
