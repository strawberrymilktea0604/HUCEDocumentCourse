// DemoList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

//định nghĩa kiểu dữ liệu sinh viên
struct KieuSV
{
    string MSSV;
    string HoTen;
    string NgaySinh;
    int Tuoi;
};

void Add(KieuSV DSSV[100], string mssv, string hoten, string ngaysinh, int tuoi, int add_index)
{
    //Khai báo 1 SV
    KieuSV sv1;
    //Truyền các dữ liệu cho sv1
    sv1.MSSV = mssv;
    sv1.HoTen = hoten;
    sv1.NgaySinh = ngaysinh;
    sv1.Tuoi = tuoi;

    //gán sv1 vào danh sách sinh viên
    DSSV[add_index] = sv1;
}

void Print(KieuSV DSSV[100], int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << "Thong tin sinh vien thu " << (i + 1) << ":" << endl;
        cout << " - MSSV: " << DSSV[i].MSSV << endl;
        cout << " - Ho ten: " << DSSV[i].HoTen << endl;
        cout << " - Ngay sinh: " << DSSV[i].NgaySinh << endl;
        cout << " - Tuoi: " << DSSV[i].Tuoi << endl;
    }
}

int main()
{
    //int A[10];

    //Khai báo 1 danh sách sinh viên với kiểu của sv là KieuSV
    KieuSV DSSV[100];

    ////Khai báo 1 SV
    //KieuSV sv1;
    ////Truyền các dữ liệu cho sv1
    //sv1.MSSV = "123";
    //sv1.HoTen = "Nguyen Van A";
    //sv1.NgaySinh = "01/01/2001";
    //sv1.Tuoi = 24;

    ////gán sv1 vào danh sách sinh viên
    //DSSV[0] = sv1;

    ////Khai báo 1 SV
    //KieuSV sv2;
    ////Truyền các dữ liệu cho sv1
    //sv2.MSSV = "234";
    //sv2.HoTen = "Nguyen Thi B";
    //sv2.NgaySinh = "02/02/2002";
    //sv2.Tuoi = 23;

    ////gán sv1 vào danh sách sinh viên
    //DSSV[1] = sv2;

    Add(DSSV, "123", "Nguyen Van A", "01/01/2001", 24, 0);
    Add(DSSV, "234", "Nguyen Thi B", "02/02/2002", 23, 1);

    cout << "Nhap vao so luong SV: ";
    int count = 0;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cout << "Moi nhap vao thong tin cua sinh vien thu " << (i + 1) << ": " << endl;

        //fflush(stdin);
        string mssv = "";
        cout << "Moi nhap vao MSSV: ";
        cin.ignore();
        getline(cin, mssv);

        fflush(stdin);
        string hoten = "";
        cout << "Moi nhap vao ho ten: ";
        cin.ignore();
        getline(cin, hoten);

        fflush(stdin);
        string ngaysinh = "";
        cout << "Moi nhap vao Ngay sinh: ";
        cin.ignore();
        getline(cin, ngaysinh);

        //fflush(stdin);
        int tuoi = -1;
        cout << "Moi nhap vao tuoi: ";
        cin >> tuoi;

        Add(DSSV, mssv, hoten, ngaysinh, tuoi, i);
    }

    //in ra danh sách sinh viên
    /*for (int i = 0; i < 2; i++)
    {
        cout << "Thong tin sinh vien thu " << (i + 1) << ":" << endl;
        cout << " - MSSV: " << DSSV[i].MSSV << endl;
        cout << " - Ho ten: " << DSSV[i].HoTen << endl;
        cout << " - Ngay sinh: " << DSSV[i].NgaySinh << endl;
        cout << " - Tuoi: " << DSSV[i].Tuoi << endl;
    }*/

    Print(DSSV, count);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
