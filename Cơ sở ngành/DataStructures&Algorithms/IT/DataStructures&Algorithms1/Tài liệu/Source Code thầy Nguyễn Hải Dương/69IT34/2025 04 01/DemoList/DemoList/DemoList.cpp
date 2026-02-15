// DemoList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;
//dùng cơ sở mảng để khai báo danh sách

//Khai báo 1 kiểu dữ liệu bằng struct
struct SV
{
    int mssv;
    string hoten;
    string ngaysinh;
};

bool isEmpty(int last_index)
{
    if (last_index<0)
    {
        //danh sách đang rỗng
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(int last_index, int size_of_List)
{
    if (last_index < size_of_List)
    {
        //chưa full
        return false;
    }
    else
    {
        return true;
    }
}

void Add(SV DSSV[],int &last_index, SV new_sv, int size_of_List)
{
    if (isEmpty(last_index))
    {
        DSSV[0] = new_sv;
        last_index = 0;
    }
    else
    {
        if (isFull(last_index, size_of_List))
        {
            //dssv đã đầy 
            cout << "Danh sanh da day" << endl;
        }
        else
        {
            last_index++;
            DSSV[last_index] = new_sv;
        }
        
    }
}

void Print(SV DSSV[], int last_index)
{
    for (int i = 0; i <= last_index; i++)
    {
        cout << "Thong tin sv thu " << (i+1) << ": " << endl;
        cout << " - MSSV: " << DSSV[i].mssv << endl;
        cout << " - Ho ten: " << DSSV[i].hoten << endl;
        cout << " - Ngay sinh: " << DSSV[i].ngaysinh << endl;
    }
}


int main()
{
    //SV sv1;
    //sv1.mssv = 123;
    //sv1.hoten = "nguyen van a";
    //sv1.ngaysinh = "01/01/2001";

    ////in thông tin sv1
    //cout << "Thong tin sv1: " << endl;
    //cout << "- MSSV: " << sv1.mssv;
    //cout << "- Ho ten: " << sv1.hoten;
    //cout << "- Ngay sinh: " << sv1.ngaysinh;

    ////khai báo danh sách sinh viên
    //SV DSSV[100];

    ////khởi tạo 3 sv ban đầu
    //for (int i = 0; i < 3; i++)
    //{
    //    SV sv;
    //    sv.mssv = i + 1;
    //    sv.hoten = "Ho ten co dinh";
    //    sv.ngaysinh = "01/01/2001";

    //    DSSV[i] = sv;
    //}

    ////in danh sách sinh viên
    //for (int i = 0; i < 3; i++)
    //{
    //    cout << "SV1: MSSV: " << DSSV[i].mssv << "; Ho ten: " << DSSV[i].hoten << "; Ngay sinh: " << DSSV[i].ngaysinh << endl;
    //}

    SV DSSV[100];
    int last_index = -1;
    int size_of_list = 0;


    cout << "Nhap vao so luong sv lon nhat cua DSSV [1-100]: ";
    cin >> size_of_list;
    if (size_of_list < 1 || size_of_list > 100)
    {
        cout << "Vui long nhap gia tri nam trong khoang [1-100]" << endl;
    }
    else
    {
        string mn = "************************* \n Moi chon chuc nang \n 0. Thoat \n 1. Them \n 2. In \n Lua chon cua ban: ";
        int choice = -1;
        SV new_sv;
        while (choice != 0)
        {
            cout << mn;
            cin >> choice;
            switch (choice)
            {
            case 1: 
                cout << "Moi nhap MSSV: ";
                cin >> new_sv.mssv;
                cout << "Moi nhap Ho ten: "; 
                cin >> new_sv.hoten;
                cout << "Moi nhap Ngay sinh: ";
                cin >> new_sv.ngaysinh;
                Add(DSSV, last_index, new_sv, size_of_list);
                break;
            case 2:
                Print(DSSV, last_index);
                break;

            }
        }
    }
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
