#include"baitaplon.h"
#include<iostream>
#include<string>
#include<string.h>
#include<iomanip>
#include<fstream>
#include<cstring>
#include<regex>
#define MAX 100

void title() {
	cout << "\n\t";
	cout << left << setw(4) << "STT" << setw(16) << "Ten ho gia dinh"
	<< left << setw(21) << "Luong dien tieu thu";
	for (int i =1; i <= 12; i++) {
		string month = "Thang " + to_string(i);
		cout << left << setw(9) << month;
	}
	cout << "\n";
	cout << "\t---------------------------------------------------------------------\n";
}

void menu() {
	cout << "\t\t QUAN LY DIEN TIEU THU GIA DINH CUA PHUONG\n";
	cout << "\t\t********************************************\n";
	cout << "\t\t**Moi ban lua chon.                       **\n";
	cout << "\t\t**1. Them ho gia dinh                     **\n";
	cout << "\t\t**2. Xem danh sach ho gia dinh            **\n";
	cout << "\t\t**3. Tim kiem ho gia dinh trong danh sach **\n";
	cout << "\t\t**4. Xoa ho gia dinh trong danh sach      **\n";
	cout << "\t\t**5. Thong ke                             **\n";
	cout << "\t\t**6. Luu va xuat file danh sach           **\n";
	cout << "\t\t**7. Tai file danh sach da luu            **\n";
	cout << "\t\t**0. Thoat chuong trinh                   **\n";
	cout << "\t\t********************************************\n\n";
	cout << "\t\tLua chon cua ban la: ";
}

void themHogiadinh(QLDTT &ten, int n) {
    regex dieukienten {R"(^[a-zA-Z]+([ ]?[a-zA-Z])*$)"};
	cin.ignore();
	cout << "Nhap ten ho gia dinh: ";
	getline(cin, ten.tenhogiadinh);
	while(!(regex_match(ten.tenhogiadinh, dieukienten))) {
        cout << "Ho va ten khong hop le! Nhap lai!\n";
        cin.clear();
        cin.ignore();
	    cout << "Nhap ten ho gia dinh: ";
        getline(cin, ten.tenhogiadinh);
	}
	cout << "Nhap tien dien: ";
	cin >> ten.tiendien;
	while(ten.tiendien <= 1000) {
        cin.clear();
        cin.ignore();
        cout << "Tien dien khong hop le! Nhap lai!\n";
        cout << "Nhap tien dien: ";
	    cin >> ten.tiendien;
	}
	for (int i = 0; i < 12; i++) {
		cout << "Nhap so dien thang thu " << i + 1 << ": ";
		cin >> ten.luongdientieuthu[i];
		while(ten.luongdientieuthu[i] <= 0) {
            cin.clear();
            cin.ignore();
            cout << "So dien tieu thu khong hop le! Nhap lai!\n";
            cout << "Nhap so dien thang thu " << i + 1 << ": ";
		    cin >> ten.luongdientieuthu[i];
		}
	}
	tinhdoanhthu(ten);
	cout << "\n--Them ho gia dinh thanh cong.--\n\n";
	}

void thongtinHogiadinh(QLDTT &ten) {
	//dung cho viec xem danh sach
	cout << left << setw(23) << ten.tenhogiadinh << left << setw(17)
	<< ten.tiendien;
		for (int j=0; j<12; j++) {
			cout << left << setw(9) << ten.luongdientieuthu[j];
		}
}

void danhsachHogiadinh(QLDTT arr[], int n) {
	if (n > 0) {
		cout << "\t\t\t\tDANH SACH QUAN LY DIEN TIEU THU\n";
		title();
		for (int i = 0; i < n; i++) {
			cout << "\t" << left << setw(4) << i+1;
			thongtinHogiadinh(arr[i]);
			cout << "\n";
		}
		cout << "\t---------------------------------------------------------------------\n";
	} else {
		cout << "\n--Chua co du lieu.--\n\n";
	}
}

string lower(string str){
    char mang[str.length()+1];
    for(int k=0;k<sizeof(mang);k++){
            //truyen string vao mang char va in thuong
        mang[k]=tolower(str[k]);//
    }

    return mang;
}

void timHogiadinh(QLDTT arr[], int n) {
	string name_find;
	cout << "\n\tNhap ho gia dinh ban can tim: ";
	cin.ignore();
	getline(cin, name_find);
	bool f = true;
	if (&f) {
		cout << "\n\t--Danh sach ho gia dinh theo tu khoa ban tim: \'"
		<< name_find << "\':\t--" << endl;
		title();
		for (int i =0; i < n; i++) {
			if (string(lower(arr[i].tenhogiadinh)).find(string(lower(name_find))) <= 100) {
				cout << "\t" << left << setw(4) << i+1;
				thongtinHogiadinh(arr[i]);
				cout << endl;
				f = false;
			}
		}
	}

	if(f) {
		cout << "\n\t--Tu khoa ban tim khong co trong danh sach nay.\n\n" << endl;
	}
}

void tinhdoanhthu(QLDTT &ten) {
	for (int i = 0; i < 12; i++) {
		ten.tongdienluongtieuthu += ten.luongdientieuthu[i];
	}
	ten.doanhthu = ten.tongdienluongtieuthu * ten.tiendien;
}

void thongke(QLDTT arr[], int n) {
	int max_dt = arr[0].doanhthu;
	//ho gia dinh phai tra nhieu tien dien nhat
	int index_max_dt = 0;
	for (int i = 1; i < n; i++) {
		if (max_dt < arr[i].doanhthu) {
			max_dt = arr[i].doanhthu;
			index_max_dt = i;
		}
	}
	int max_tieuthu = arr[0].tongdienluongtieuthu;
	//ho gia dinh su dung nhieu dien nhat
	int index_max_tieuthu = 0;
	for (int q = 0; q < n; q++) {
		if (max_tieuthu < arr[q].tongdienluongtieuthu) {
			max_tieuthu = arr[q].tongdienluongtieuthu;
			index_max_tieuthu = q;
		}
	}
	cout << "\n\tCo " << n << " ho gia dinh trong phuong.\n\t Trong do: \n";
	cout << "\tNha " << arr[index_max_dt].tenhogiadinh << " tra nhieu tien dien nhat: " << max_dt << "VND\n";
	cout << "\tNha " << arr[index_max_tieuthu].tenhogiadinh << " su dung nhieu dien nhat: " << max_tieuthu << "kWh (so)\n";
}

void xoaHogiadinh(QLDTT arr[], int &n) {
	if (n == 0) {
		cout << "\n\t--Chua co du lieu.--\n\n";
	} else {
		int stt;
		int found = 0;
		cout << "\n\tNhap so thu tu cua ho gia dinh ma ban muon xoa: ";
		cin >> stt;
		while(stt == 0) {
            cout << "Lua chon khong hop le. Thu lai!";
            cin.clear();
            cin.ignore();
            cout << "\n\tNhap so thu tu cua ho gia dinh ma ban muon xoa: ";
		    cin >> stt;
		}
		for (int i = 0; i < n; i++) {
            if(i + 1 == stt) {
                found++;
                for(int j = i; j < n; j++) {
                    arr[j] = arr[j+1];
                }
            }
		}
		if(found == 0) {
            cout << "Ho gia dinh do khong ton tai!\n";
		}
		else{
            n--;
            cout << "\n\t--Ho gia dinh ma ban nhap da xoa thanh cong.--";
		}
	}
}

void luufile(QLDTT qldl[], int n, string filename) {
	ofstream output;
	output.open(filename);
	output << " ";
	for (int i = 0; i < n ; i++) {
		output << qldl[i].tenhogiadinh << endl << qldl[i].tiendien;
		for (int j = 0; j < 12; j++) {
			output << " " << qldl[i].luongdientieuthu[j];
		}
		output << "\n";
	}
	output.close();
	cout << "\n\t--Da luu vao file.\n\n";
}

void loadfile(QLDTT qldl[], int &n, string filename) {
	ifstream input;
	input.open(filename);
	if(!input.is_open()) {
		cout << "File khong the mo do khong ton tai.\n";
		n = 0;
		return;
	}
	int count = 0;
	while(!input.eof()) {
		string name;
		regex dieukienten {R"(^[a-zA-Z]+([ ]?[a-zA-Z])*$)"};
		input.ignore();
		getline(input, name);
		if (name == " ") {
			break;
		} else {
			qldl[count].tenhogiadinh = name;
			if(!(regex_match(qldl[count].tenhogiadinh, dieukienten))) {
               cout << "Trong file co doi tuong co ho va ten khong hop le. Thu lai!\n";
               getline(input, name);
			   continue;
			}
			else {
                input >> qldl[count].tiendien;
			    if (qldl[count].tiendien <= 1000) {
			        cout << "Trong file co tien dien khong hop le. Thu lai!\n";
                    getline(input, name);
                    continue;
			    }
			    else {
                    for (int i = 0; i < 12; i++) {
                    input >> qldl[count].luongdientieuthu[i];
				    if(qldl[count].luongdientieuthu[i] <= 0) {
                           cout << "Trong file co so dien tieu thu khong hop le. Thu lai!\n";
                           getline(input, name);
                           break;
				}
			}
			    }
			}
			tinhdoanhthu(qldl[count]);
			count++;
		}
	}
	input.close();
	cout << "\n\t--Tai file len thanh cong.--";
	n = count;
}
