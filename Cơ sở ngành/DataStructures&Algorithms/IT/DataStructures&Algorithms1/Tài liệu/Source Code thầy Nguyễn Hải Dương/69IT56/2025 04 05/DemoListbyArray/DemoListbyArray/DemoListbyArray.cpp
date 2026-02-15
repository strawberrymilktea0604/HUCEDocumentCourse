// DemoListbyArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

//định nghĩa kiểu dữ liệu có tên là SV
struct SV
{
	string MSSV;
	string HoTen;
	string DiaChi;
};
bool isEmpty(int count)
{
	if (count <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isFull(int count)
{
	if (count >= 100)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Add(SV DSSV[], int& count)
{
	if (isEmpty(count))
	{
		SV sv;
		cout << "Moi nhap thong tin sinh vien: " << endl;
		cout << " - MSSV: ";
		getline(cin, sv.MSSV);
		cout << " - Ho ten: ";
		getline(cin, sv.HoTen);
		cout << " - Dia chi: ";
		getline(cin, sv.DiaChi);

		DSSV[0] = sv;
		count++;
	}
	else
	{
		if (isFull(count))
		{
			cout << "Danh sach da day" << endl;
		}
		else
		{
			SV sv;
			cout << "Moi nhap thong tin sinh vien: " << endl;
			cout << " - MSSV: ";
			getline(cin, sv.MSSV);
			cout << " - Ho ten: ";
			getline(cin, sv.HoTen);
			cout << " - Dia chi: ";
			getline(cin, sv.DiaChi);

			DSSV[count] = sv;
			count++;
		}
	}
}

void Print(SV DSSV[], int count)
{
	if (isEmpty(count))
	{
		cout << "Danh sach sinh vien chua co sinh vien nao" << endl;
	}
	else
	{
		cout << "Danh sach sinh vien hien tai (si so: " << count << "sv):" << endl;
		for (int i = 0; i < count; i++)
		{
			cout << "Thong tin SV thu " << (i + 1) << ": " << endl;
			cout << " - MSSV: " << DSSV[i].MSSV << endl;
			cout << " - Ho ten: " << DSSV[i].HoTen << endl;
			cout << " - Dia chi: " << DSSV[i].DiaChi << endl;
		}
	}
	
}

int main()
{
	////Demo về struct
	//SV x;
	//x.MSSV = 123;
	//x.HoTen = "Nguyen Van A";
	//x.DiaChi = "Ninh Binh";
	//
	//cout << "Thong tin SV: " << endl;
	//cout << " - MSSV: " << x.MSSV << endl;
	//cout << " - Ho ten: " << x.HoTen << endl;
	//cout << " - Dia chi: " << x.DiaChi << endl;

	//SV DSSV[10];

	//for (int i = 0; i < 3; i++)
	//{
	//	cout << "Nhap vao thong tin sinh vien thu " << (i + 1) << ":" << endl;
	//	cout << " - MSSV: ";
	//	getline(cin, DSSV[i].MSSV);
	//	cout << " - Ho ten: ";
	//	getline(cin, DSSV[i].HoTen);
	//	cout << " - Dia chi: ";
	//	getline(cin, DSSV[i].DiaChi);
	//}

	////in ra 
	//for (int i = 0; i < 3; i++)
	//{
	//	cout << "Thong tin SV thu " << (i+1) << ": " << endl;
	//	cout << " - MSSV: " << DSSV[i].MSSV << endl;
	//	cout << " - Ho ten: " << DSSV[i].HoTen << endl;
	//	cout << " - Dia chi: " << DSSV[i].DiaChi << endl;
	//}

	//Tạo chương trình quản lý sinh viên
	SV DSSV[100];
	int count = 0; //chứa số lượng sinh viên trong dssv

	string mn = "------------------------------------------ \n CHUONG TRINH QUAN LY SINH VIEN \n Moi chon chuc nang \n 0. Thoat \n 1. Them Sinh sinh \n 2. In Danh sach sinh vien \n Lua chon cua ban: ";
	string choice = "- 1";
	while (choice != "0")
	{
		cout << mn;
		getline(cin, choice);		

		if (choice == "1")
		{
			Add(DSSV, count);
		}
		else
		{
			if (choice == "2")
			{
				Print(DSSV, count);
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
