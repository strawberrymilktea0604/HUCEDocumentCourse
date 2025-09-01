#include "header.h"

int main() {
    int soSinhVien = 0;
    while (true) {
        menu();
        int luaChon = kiemTraSo();
        switch (luaChon) {
        case 1:
            system("cls");
            nhapSinhVien(soSinhVien, sinhvien);
            break;
        case 2:
            system("cls");
            xemDanhSach(soSinhVien, sinhvien);
            break;
        case 3:
            system("cls");
            suaThongTin(soSinhVien, sinhvien);
            break;
        case 4:
            system("cls");
            xemTimKiem(soSinhVien, sinhvien);
            break;
        case 5:
            system("cls");
            xoaSinhVien(soSinhVien, sinhvien);
            break;
        case 6:
            system("cls");
            thongKe(soSinhVien, sinhvien);
            break;
        case 7:
            system("cls");
            docFile(soSinhVien, sinhvien);
            break;
        case 8:
            system("cls");
            ghiFile(soSinhVien, sinhvien);
            break;
        case 0:
            return 0;
            break;
        default:
            cout << "Vui long nhap lua chon tu 1 den 8:" << endl;
        }
        system("pause");
    }
}
