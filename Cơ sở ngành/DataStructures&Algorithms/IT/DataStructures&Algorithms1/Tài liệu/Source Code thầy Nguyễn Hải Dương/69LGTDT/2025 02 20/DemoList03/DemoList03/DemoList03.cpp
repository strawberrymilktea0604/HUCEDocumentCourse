// DemoList03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct KieuSV
{
    string MSSV;
    string HoTen;
};


void Add(KieuSV A[10], string mssv, string hoten, int add_index)
{
    A[add_index].MSSV = mssv;
    A[add_index].HoTen = hoten;
}

void Print(KieuSV A[10], int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << "Thong tin SV thu " << (i + 1) << ": " << endl;
        cout << " - MSSV: " << A[i].MSSV << endl;
        cout << " - HoTen: " << A[i].HoTen << endl;
    }
}

void Insert(KieuSV A[10])
{
    int count = 0;
    cout << "Moi nhap vao so luong sinh vien cua danh sach: ";
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        cout << "Moi nhap vao thong tin sinh vien thu " << (i + 1) << ": " << endl;
        cout << " - Nhap vao MSSV:";
        cin >> A[i].MSSV;
        cout << " - Nhap vao Ho ten:";
        cin >> A[i].HoTen;
    }
}

int main()
{
    //List - danh sách: tương đương như Array
    KieuSV A[10];
    /*A[0].MSSV = "1";
    A[0].HoTen = "Nguyen Van A";*/

    //Add(A, "1", "Nguyen Van A", 0);

    /*A[1].MSSV = "2";
    A[1].HoTen = "Nguyen Thi B";*/

    //Add(A, "2", "Nguyen Thi B", 1);

    Insert(A);
    
    /*for (int i = 0; i < 2; i++)
    {
        cout << "Thong tin SV thu " << (i + 1) << ": " << endl;
        cout << " - MSSV: " << A[i].MSSV << endl;
        cout << " - HoTen: " << A[i].HoTen << endl;
    }*/

    Print(A, 2);



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
