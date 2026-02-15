// DemoQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

bool isEmpty(int rear)
{
	if (rear == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isFull(int rear, int n)
{
	if (rear < n)
	{
		return false;
	}

	return true;
}

void Add(int Q[], int& front, int& rear, int new_val, int n)
{
	if (isEmpty(rear))
	{
		//trường hợp Q đang rỗng
		front = 0;
		rear = 0;
		Q[0] = new_val;
	}
	else
	{
		//trường hợp Q đang không rỗng
		if (isFull(rear, n))
		{
			cout << "Hang doi da day" << endl;
		}
		else
		{
			rear++;
			Q[rear] = new_val;
		}
		
	}
}

int Get(int Q[], int& rear)
{
	if (isEmpty(rear))
	{
		//rỗng
		cout << "Hang doi dang rong" << endl;
	}
	else
	{
		//có phần tử
		int tg = Q[0];

		//đẩy các phần tử phía sau lên trước
		for (int i = 0; i < rear; i++)
		{
			Q[i] = Q[i + 1];
		}
		//giảm rear đi 1
		rear--;

		return tg;
	}
}

void Print(int Q[], int rear)
{
	if (isEmpty(rear))
	{
		//rỗng
		cout << "Hang doi dang rong" << endl;
	}
	else
	{
		cout << "Q= front<-- {";
		for (int i = 0; i <= rear; i++)
		{
			cout << Q[i];
			if (i < rear)
			{
				cout << ",";
			}
		}
		cout << "} <--rear" << endl;
	}
	
}

void Edit(int Q[],int &front, int &rear, int edit_val, int edit_index)
{
	if (isEmpty(rear))
	{
		cout << "Hang doi dang rong" << endl;
	}
	else
	{
		//hang doi co phan tu
		if (edit_index >=0 && edit_index <= rear)
		{
			//hợp lệ
			int B[100];
			int old_rear = rear;
			for (int i = 0; i <= old_rear; i++)
			{				
				B[i] = Get(Q, rear);
				if (i == edit_index)
				{
					B[i] = edit_val;
				}
			}

			for (int i = 0; i <= old_rear; i++)
			{
				Add(Q, front, rear, B[i], old_rear);
			}
		}
		else
		{
			cout << "Vi tri can sua khong hop le" << endl;
		}
	}

}


int main()
{
	int Q[100];
	int front = -1;
	int rear = -1;

	int n = 0; //chứa số lượng phần tử lớn nhất mà người dùng muốn sử dụng.

	cout << "Nhap vao so luong phan tu lon nhat cua Hang doi [1-100]: ";
	cin >> n;
	if (n < 1 || n>100)
	{
		cout << "So vua nhap khong hop le" << endl;
	}
	else
	{
		//n đã hợp lệ
		string mn = "\n***********************\n Moi chon chuc nang: \n 0. Thoat \n 1. Them moi \n 2. In \n 3. Lay phan tu ra khoi hang doi \n 4. Sua \nLua chon cua ban: ";

		int choice = 100;
		int new_value = 0;
		int edit_index = -1;
		int edit_val = 0;



		while (choice > 0)
		{
			cout << mn;
			cin >> choice;
			switch (choice)
			{
			case 1:
				//thêm mới phần tử
				cout << "Moi nhap vao phan tu can them moi: ";
				cin >> new_value;
				Add(Q, front, rear, new_value, n);
				break;
			case 2:
				//in hàng đợi
				Print(Q, rear);
				break;

			case 3:
				cout << "Phan tu vua duoc lay ra la: " << Get(Q, rear) << endl;
				break;

			case 4:
				cout << "Nhap vao vi tri can sua: ";
				cin >> edit_index;

				cout << "Nhap vao gia tri moi: ";
				cin >> edit_val;

				Edit(Q, front, rear, edit_val, edit_index);
				break;

			}
		}
		cout << "Ban chon sai chuc nang" << endl;
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
