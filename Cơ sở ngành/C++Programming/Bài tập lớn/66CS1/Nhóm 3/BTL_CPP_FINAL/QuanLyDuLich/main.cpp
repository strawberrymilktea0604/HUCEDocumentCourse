/**
DELL INSPIRON-15 HOANG-DINH-VINH-VINH
*/

#include"btl.h"

int main(){
    QLDL qldl[MAX];
    int select, tong_so_dia_diem = 0;
    const string FILENAME = "DATA.txt";
    while (true) {
        menu();
        cin >> select;
        switch (select) {
            case 1:
                themDiaDiem(qldl[tong_so_dia_diem], tong_so_dia_diem);
                tong_so_dia_diem++;
                break;
            case 2:
                danhSachDiaDiem(qldl, tong_so_dia_diem);
                break;
            case 3:
                timDiaDiem(qldl, tong_so_dia_diem);
                break;
            case 4:
                xoaDiaDiem(qldl, tong_so_dia_diem);
                break;
            case 5:
                thongKe(qldl, tong_so_dia_diem);
                break;
            case 6:
                luuFile(qldl, tong_so_dia_diem, FILENAME);
                break;
            case 7:
                loadFile(qldl, tong_so_dia_diem, FILENAME);
                break;
            case 0:
                cout << "\n\t-Da thoat chuong trinh.\n";
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
