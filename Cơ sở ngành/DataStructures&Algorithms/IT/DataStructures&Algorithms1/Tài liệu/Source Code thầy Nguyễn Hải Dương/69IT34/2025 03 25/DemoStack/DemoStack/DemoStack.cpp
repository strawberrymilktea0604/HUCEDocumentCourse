// DemoStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

bool isEmpty(int top)
{
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isFull(int top, int size) //coi size là số lượng phần tử của Stack
{
	if (top < size - 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void push(int S[], int &top, int new_val)
{
	if (isEmpty(top))
	{
		//trường hợp Stack đang rỗng
		S[0] = new_val;
		top = 0;
	}
	else
	{
		top++;
		S[top] = new_val;
	}
}

int pop(int S[], int& top)
{
	if (isEmpty(top))
	{
		cout << "Ngan xep dang rong" << endl;
	}
	else
	{
		int tg = S[top];
		//câu lệnh S[top] = 0 có cũng được, không cũng được, Stack vẫn chạy bình thường.
		S[top] = 0; //reset giá trị của phần tử ở top hiện tại về 0
		top--;
		return tg;
	}
}

void Print(int S[], int top)
{//chú ý: Do sử dụng cơ sở mảng để cài đặt ngăn xếp nên hàm in này sử dụng chỉ số của mảng để in cho thuận tiện hơn.
	if (isEmpty(top))
	{
		cout << "Ngan xep dang rong" << endl;
	}
	else
	{
		cout << "Ngan xep hien tai: S={";
		for (int i = 0; i <= top; i++)
		{
			cout << S[i];
			if (i < top)
			{
				cout << ",";
			}
		}
		cout << "} <-- Top" << endl;
	}	
}

int main()
{
	int S[100];
	int top = -1;
	int size = 0; //số lượng phần tử lớn nhất mà stack có thể chứa được.

	cout << "Nhap vao so luong phan tu lon nhat cua Stack [1-100]: ";
	cin >> size;
	if (size < 1 || size > 100)
	{
		//tham số người dùng nhập vào không hợp lệ
		cout << "Ban dinh hack ah?" << endl;
	}
	else
	{
		//tham số người dùng nhập vào hợp lệ
		cout << "Ban muon nhap vao bao nhieu phan tu?";
		int n = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int tg = 0;
			cout << "Moi nhap vao phan tu thu " << (i + 1) << ": ";
			cin >> tg;

			push(S, top, tg);
		}

		Print(S, top);

		//lấy phần tử ra khỏi stack.
		cout << "Phan tu o dinh hien tai cua ngan xep: " << pop(S, top) << endl;
		cout << "Ngan xep con lai: " << endl;
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
