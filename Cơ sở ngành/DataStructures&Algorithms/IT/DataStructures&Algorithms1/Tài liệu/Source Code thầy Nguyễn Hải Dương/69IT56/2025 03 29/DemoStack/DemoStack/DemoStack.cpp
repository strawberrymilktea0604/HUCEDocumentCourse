// DemoStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

////tạo biến toàn cục
//int S[100];
//int top = -1;
//
//bool isEmpty()
//{
//	if (top <0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}

//không khai báo biến toàn cục
bool isEmpty(int top)
{
	if (top < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isFull(int top, int size_of_Stack)
{
	if (top < size_of_Stack - 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Push(int S[], int &top, int new_val, int size_of_Stack)
{
	if (isEmpty(top))
	{
		S[0] = new_val; top = 0;
	}
	else
	{
		if (isFull(top, size_of_Stack))
		{
			cout << "Ngan xep da day, khong the them phan tu duoc nua" << endl;
		}
		else
		{
			top++;
			S[top] = new_val;
		}		
	}
}

void Print(int S[], int top)
{
	//sử dụng tính linh động của mảng để in
	//chứ không tuân thủ theo quy tắc tương tác của Ngăn xếp
	
	cout << "S = {";
	for (int i = 0; i <= top; i++)
	{
		cout << S[i];
		//nếu chưa phải là phần tử cuối cùng thì in ra dấu , ngăn cách giữa các phần tử
		if (i < top)
		{
			cout << ",";
		}
	}
	cout << "} <-- top" << endl;
}

int main()
{
	int S[100];
	int size_of_Stack = 0;
	int top = -1;
	cout << "Nhap vao so phan tu lon nhat cua ngan xep [1-100]: ";
	cin >> size_of_Stack;
	if (size_of_Stack < 1 || size_of_Stack > 100)
	{
		cout << "May dinh hack ah? " << endl;
	}
	else
	{
		//trường hợp size of stack hợp lệ
		//thêm phần tử
		for (int i = 0; i < size_of_Stack; i++)
		{
			int tg = 0;
			cout << "Moi nhap vao gia tri cua phan tu thu " << (i + 1) << ": ";
			cin >> tg;
			Push(S, top, tg, size_of_Stack);
		}
		
		cout << "Ngan xep vua nhap: ";
		Print(S, top);
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
