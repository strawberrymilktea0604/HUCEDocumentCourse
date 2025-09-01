#include"Header.h"



void nhapDanhSachSV(SinhVien dsSV[], int& n) {
    int soLuong;
    cout << "Nhap so luong sinh vien: ";
    cin >> soLuong;
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        cout << "Ho ten: ";
        cin.ignore();
        getline(cin, dsSV[i].hoTen);
        cout << "Ma sinh vien: ";
        getline(cin, dsSV[i].maSV);
        cout << "Ngay sinh: ";
        getline(cin, dsSV[i].ngaySinh);
        cout << "Dia chi: ";
        getline(cin, dsSV[i].diaChi);
        cout << "Dien thoai: ";
        getline(cin, dsSV[i].dienThoai);
        cout << "Email: ";
        getline(cin, dsSV[i].email);
    }
    n+= soLuong;
}

void xemDanhSachSV(SinhVien dsSV[], int n) {
    cout << "Danh sach sinh vien:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Thong tin sinh vien thu " << i + 1 << endl;
        cout << "Ho ten: " << dsSV[i].hoTen << endl;
        cout << "Ma sinh vien: " << dsSV[i].maSV << endl;
        cout << "Ngay sinh: " << dsSV[i].ngaySinh << endl;
        cout << "Dia chi: " << dsSV[i].diaChi << endl;
        cout << "Dien thoai: " << dsSV[i].dienThoai << endl;
        cout << "Email: " << dsSV[i].email << endl;
    }
}

void diemDanh(SinhVien dsSV[], int n, int**& dd, int& m) {
    dd = new int* [n];
    for (int i = 0; i < n; i++) {
        dd[i] = new int[m];
        for (int j = 0; j < m; j++) {
            dd[i][j] = 0;
        }
    }
    int ngay;
    string trangThai;
    string input;
    cout << "Nhap ngay can diem danh (1 - " << m << "): ";
    cin.ignore();
    getline(cin, input);
   

    while (true) {
        stringstream ss(input);
        if (ss >> ngay && kiemTraGioiHan(ngay, 1, m) && ss.eof()) {
            break;
        }
        cout << "Nhap ngay can diem danh (1 - " << m << "): ";
        getline(cin, input);
    }
    for (int i = 0; i < n; i++) {
        cout << "Nhap trang thai diem danh cua sinh vien " << dsSV[i].hoTen << " (" << dsSV[i].maSV << "): ";
        cin >> trangThai;
        transform(trangThai.begin(), trangThai.end(), trangThai.begin(), ::toupper); 
        while (trangThai != "X" && trangThai != "P" && trangThai != "V") {
            cout << "Nhap lai trang thai diem danh cua sinh vien " << dsSV[i].hoTen << " (" << dsSV[i].maSV << "): ";
            cin >> trangThai;
            transform(trangThai.begin(), trangThai.end(), trangThai.begin(), ::toupper);
        }
        if (trangThai == "X") {
            dd[i][ngay - 1] = 1;
        }
        else if (trangThai == "P") {
            dd[i][ngay - 1] = 2;
        }
        else {
            dd[i][ngay - 1] = 3;
        }
    }
}


void timKiem(SinhVien dsSV[], int n) {
    string maSV;
    cout << "Nhap ma sinh vien can tim: ";
    cin >> maSV;
    bool timThay = false;
    for (int i = 0; i < n; i++) {
        if (dsSV[i].maSV == maSV) {
            timThay = true;
            cout << "Thong tin sinh vien:" << endl;
            cout << "Ho ten: " << dsSV[i].hoTen << endl;
            cout << "Ma sinh vien: " << dsSV[i].maSV << endl;
            cout << "Ngay sinh: " << dsSV[i].ngaySinh << endl;
            cout << "Dia chi: " << dsSV[i].diaChi << endl;
            cout << "Dien thoai: " << dsSV[i].dienThoai << endl;
            cout << "Email: " << dsSV[i].email << endl;
        }
    }
    if (!timThay) {
        cout << "Khong tim thay sinh vien co ma " << maSV << endl;
    }
}

void xoaSinhVien(SinhVien dsSV[], int& n) {
    string maSV;
    cout << "Nhap ma sinh vien can xoa: ";
    cin >> maSV;
    bool timThay = false;
    for (int i = 0; i < n; i++) {
        if (dsSV[i].maSV == maSV) {
            timThay = true;
            for (int j = i; j < n - 1; j++) {
                dsSV[j] = dsSV[j + 1];
            }
            n--;
            break;
        }
    }
    if (timThay) {
        cout << "Da xoa sinh vien co ma " << maSV << endl;
    }
    else {
        cout << "Khong tim thay sinh vien co ma " << maSV << endl;
    }
}

void thongKe(const SinhVien dsSV[], int n, int** dd, int m) {
    cout << "Thong ke diem danh:" << endl;
    cout << "MaSV\tHoTen\t";
    for (int i = 0; i < m; i++) {
        cout << "Ngay " << i + 1 << "\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << dsSV[i].maSV << "\t" << dsSV[i].hoTen << "\t";
        for (int j = 0; j < m; j++) {
            if (dd[i][j] == 1) {
                cout << "X\t";
            }
            else if (dd[i][j] == 2) {
                cout << "P\t";
            }
            else {
                cout << "V\t";
            }
        }
        cout << endl;
    }
}

void nhapTuFile(const string& tenFile, SinhVien dsSV[], int& n, int**& dd, int& m) {
    ifstream file(tenFile);
    if (!file) {
        cout << "Khong mo duoc file." << endl;
            return;
    }

    file >> n;
    file >> m;

    for (int i = 0; i < n; i++) {
        file.ignore();
        getline(file, dsSV[i].hoTen); 
        getline(file, dsSV[i].maSV); 
        getline(file, dsSV[i].ngaySinh); 
        getline(file, dsSV[i].diaChi); 
        getline(file, dsSV[i].dienThoai); 
        getline(file, dsSV[i].email); 
    }

    dd = new int* [n];
    for (int i = 0; i < n; i++) {
        dd[i] = new int[m];
        for (int j = 0; j < m; j++) {
            file >> dd[i][j];
        }
    }

    file.close();
}

void xuatRaFile(const string& tenFile, const SinhVien dsSV[], int n, const int* const* dd, int m) {
    ofstream file(tenFile);
    if (!file) {
        cout << "Khong mo duoc file." << endl;
        return;
    }

    file << n << endl;
    file << m << endl;

    for (int i = 0; i < n; i++) {
        file << dsSV[i].hoTen << endl; 
        file << dsSV[i].maSV << endl; 
        file << dsSV[i].ngaySinh << endl; 
        file << dsSV[i].diaChi << endl; 
        file << dsSV[i].dienThoai << endl; 
        file << dsSV[i].email << endl; 
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            file << dd[i][j] << " "; 
        }
        file << endl;
    }

    file.close(); 

}

bool kiemTraGiaTriDauVao() {
    if (cin.peek() == '\n') {
        cin.ignore();
        return true;
    }
    return false;
}

bool kiemTraGioiHan(int giaTri, int gioiHanNhoNhat, int gioiHanLonNhat) {
    return (giaTri >= gioiHanNhoNhat && giaTri <= gioiHanLonNhat);
}
