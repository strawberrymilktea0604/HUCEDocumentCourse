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

int main() {
	
	ifstream data("bai4.txt");
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
 
	
	while (!data.eof()) {
		 

	    
		getline(data, hoten);
	    cout << "\n\nHo va ten sinh vien: " << hoten << endl;
	
	    Docfile(data, diemcacmonhoc, soluongmonhoc);

	    cout << "Diem tong ket tung mon hoc cua sinh vien: " << endl; 
	    Xuatmang(diemcacmonhoc, soluongmonhoc);
	    getline(data, hoten); 
	

}

    ofstream ketqua;
	ketqua.open("bai4.txt", ios_base::app);
	
	if (!ketqua.is_open()) {
		cout << "Khong mo duoc file";
		return 1;
	}
	else {
		string hovaten;
		cout << "\nNhap ho va ten sinh vien: " << endl;
		while(getline(cin, hovaten) && hovaten != "") {
			ketqua << endl; 
			ketqua <<  hovaten << endl; 
		}
		
		for(int i = 0; i < soluongmonhoc; i++) {
			cout << "Nhap diem mon hoc thu " << i + 1 << " ";
			cin >>  diemcacmonhoc[i]; 
		}
		for(int i = 0; i < soluongmonhoc; i++) {
			ketqua << diemcacmonhoc[i] << " ";  
		}
       }
 

	
	
	ketqua.close();
	data.close();  
	system("pause"); 
	return 0; 
}
