// DemoQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

//khởi tạo biến toàn cục
int Q[100];
int front = -1;
int rear = -1;
int size_of_Queue = 0;

bool isEmpty()
{
	if (front == -1 && rear == -1)
	{
		//đang rỗng
		return true;
	}
	else
	{
		return false;
	}
}

bool isFull()
{
	if (rear < size_of_Queue - 1)
	{
		//chưa full
		return false;
	}
	else
	{
		return true;
	}
}

void Add(int new_val)
{
	if (isEmpty())
	{
		//queue đang rỗng
		Q[0] = new_val;
		front = 0;
		rear = 0;
	}
	else
	{
		//queue đã có phần tử
		if (isFull())
		{
			//queue đã đầy
			cout << "Hang doi da day. KHONG the them duoc nua" << endl;
		}
		else
		{
			//trường hợp chưa đầy
			rear++;
			Q[rear] = new_val;
		}
	}
}

//Hàm lấy phần tử ra khỏi Queue
int Get()
{
	if (isEmpty())
	{
		cout << "Hang doi khong con phan tu nao nua" << endl;
	}
	else
	{
		//trương hợp hàng đợi còn phần tử
		int tg = Q[0];
		//đẩy các phần tử phía sau lên trước 1 vị trí
		for (int i = 0; i < rear; i++)
		{
			Q[i] = Q[i + 1];
		}
		rear--;

		return tg;
	}
}

void Print()
{
	//chú ý: Tương tự như phần demo Stack
	if (isEmpty())
	{
		cout << "Hang doi dang rong" << endl;
	}
	else
	{
		cout << "Q = front <-- {";
		for (int i = 0; i <= rear; i++)
		{
			cout << Q[i];
			if (i < rear)
			{
				cout << ",";
			}
		}
		cout << "} <-- rear" << endl;
	}	
}


int main()
{
	cout << "Moi nhap vao so phan tu lon nhat cua Hang doi [1-100]: ";
	cin >> size_of_Queue;
	if (size_of_Queue < 1 || size_of_Queue > 100)
	{
		cout << "Ban dung hach toi" << endl;
	}
	else
	{
		string mn = "***************************\n Moi chon chuc nag: \n 0. Thoat \n 1. Them phan tu \n 2. In ra \n 3. Lay phan tu ra khoi hang doi \n Lua chon cua ban: ";
		int choice = 100;
		int new_val = 0;
		while (choice != 0)
		{
			cout << mn;
			cin >> choice;

			switch (choice)
			{
			case 1:
				//người dùng chọn chức năng thêm phần tử
				cout << "Moi nhap phan tu can them vao hang doi: ";
				cin >> new_val;
				Add(new_val);
				break;
			case 2:
				Print();
				break;
			case 3:
				cout << "Phan tu vua lay ra khoi hang doi: " << Get() <<endl;
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
