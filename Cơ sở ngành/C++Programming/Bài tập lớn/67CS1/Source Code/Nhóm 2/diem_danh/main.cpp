#include "Header.h"

int main() {
    SinhVien* dsSV = new SinhVien[MAX_N];
    int** dd = new int* [MAX_N];
    for (int i = 0; i < MAX_N; i++) {
        dd[i] = new int[MAX_M]();
    }
    int n = 0; 
    int m = 0; 
    int luaChon;

    do {
        cout << "Menu:" << endl;
        cout << "1. Nhap danh sach sinh vien" << endl;
        cout << "2. Xem danh sach sinh vien" << endl;
        cout << "3. Tim kiem sinh vien theo ma" << endl;
        cout << "4. Xoa sinh vien" << endl;
        cout << "5. Diem danh" << endl;
        cout << "6. Thong ke" << endl;
        cout << "7. Nhap du lieu sinh vien tu file" << endl;
        cout << "8. Xuat du lieu sinh vien ra file" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
        case 0:
            cout << "Cam on ban da su dung chuong trinh!" << endl;
            break;
        case 1:
            nhapDanhSachSV(dsSV, n);
            break;
        case 2:
            xemDanhSachSV(dsSV, n);
            break;
        case 3:
            timKiem(dsSV, n);
            break;
        case 4:
            xoaSinhVien(dsSV, n);
            break;
        case 5:
            diemDanh(dsSV, n, dd, m);
            break;
        case 6:
            thongKe(dsSV, n, dd, m);
            break;
        case 7 : 
            nhapTuFile("dulieu.txt", dsSV, n, dd, m);
            break;
        case 8:
            xuatRaFile("dulieu1.txt", dsSV, n, dd, m);
            break;
        default:
            cout << "Lua chon khong hop le. Vui long nhap lai!" << endl;
            break;
        }
    } while (luaChon != 0);


    for (int i = 0; i < MAX_N; i++) {
        delete[] dd[i];
    }
    delete[] dd;
    delete[] dsSV;

    return 0;
}
