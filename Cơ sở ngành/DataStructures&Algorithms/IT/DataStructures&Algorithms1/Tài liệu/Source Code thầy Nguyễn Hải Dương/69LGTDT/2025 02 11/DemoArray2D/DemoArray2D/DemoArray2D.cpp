// DemoArray2D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void Sua(int A[10][10], int new_val, int col_index, int row_index)
{
	if (col_index >= 0 && col_index <= 10)
	{ 
		if (row_index >= 0 && row_index <= 10)
		{
			//trường hợp index hợp lệ
			A[row_index][col_index] = new_val;
			return;
		}
	}

	cout << "Vi tri phan tu can chen khong hop le" << endl;
}

void ThemPhanTuLanLuot(int A[10][10])
{
	int num_col = 0;
	int num_row = 0;

	cout << "Nhap vao so hang: ";
	cin >> num_row;
	cout << "Nhap vao so cot: ";
	cin >> num_col;
	
	if (num_row >= 0 && num_row <= 10)
	{
		if (num_col >= 0 && num_col <= 10)
		{
			//trường hợp index hợp lệ
			for (int i = 0; i < num_row; i++)
			{
				for (int j = 0; j < num_col; j++)
				{
					cout << "Nhap vao A[" << i << "][" << j << "]: ";
					int x;
					cin >> x;
					A[i][j] = x;
				}
			}

			return;
		}
	}

	cout << "So luong hang/cot khong hop le" << endl;
}

void In(int A[10][10], int num_col, int num_row)
{
	for (int i = 0; i < num_row; i++)
	{
		for (int j = 0; j < num_col; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
    int A[10][10];

	//them phan tu
	ThemPhanTuLanLuot(A);

	//in ra
	In(A, 4, 3);

	//Sửa
	Sua(A, 7, 1, 2);

	//in ra
	cout << "Sau khi sua phan tu: " << endl;
	In(A, 4, 3);
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
