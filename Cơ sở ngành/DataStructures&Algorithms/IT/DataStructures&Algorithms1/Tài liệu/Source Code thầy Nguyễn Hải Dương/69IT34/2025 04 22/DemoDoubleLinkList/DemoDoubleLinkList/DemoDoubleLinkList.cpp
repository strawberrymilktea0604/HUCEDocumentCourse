// DemoDoubleLinkList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Node
{
	int Val;
	Node* back;
	Node* next;
};

struct DoubleLinkList
{
	Node* first;
	Node* last;
	//int count;
};

Node* CreateNode(int value)
{
	Node* n = (Node*)malloc(sizeof(Node));
	n->Val = value;
	n->back = NULL;
	n->next = NULL;
	return n;
}

DoubleLinkList CreateList()
{
	DoubleLinkList list;
	list.first = NULL;
	list.last = NULL;

	return list;
}

bool isEmpty(DoubleLinkList L)
{
	if (L.first == NULL && L.last == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//void AddLast(DoubleLinkList& L, int val)
//{
//	//B1: Khởi tạo phần tử
//	Node* newNode = CreateNode(val);
//
//	if (isEmpty(L))
//	{
//		L.first = newNode;
//		L.last = newNode;
//	}
//	else
//	{
//		L.last->next = newNode;
//		newNode->back = L.last;
//		L.last = newNode;
//	}
//}

int Count(DoubleLinkList L)
{
	if (isEmpty(L))
	{
		return 0;
	}
	else
	{
		int count = 0;
		Node* p = L.first;
		while (p != NULL)
		{
			count++;
			p = p->next;
		}

		return count;
	}
}

void Insert(DoubleLinkList& L, int val, int insert_index)
{
	//B1: Khởi tạo phần tử
	Node* newNode = CreateNode(val);

	if (isEmpty(L))
	{
		L.first = newNode;
		L.last = newNode;
	}
	else
	{
		//kiểm tra tính hợp lệ của insert_index
		int count = Count(L);
		if (insert_index >= 0 && insert_index <= count)
		{
			//hợp lệ
			//kiểm tra xem insert_index==0?
			if (insert_index == 0)
			{
				//trường hợp thêm vào đầu của danh sách
				L.first->back = newNode;
				newNode->next = L.first;
				L.first = newNode;
			}
			else
			{
				//kiểm tra xem insert_index==Vị trí cuối cùng của danh sách +1
				if (insert_index == count)
				{
					//AddLast(L, val);
					L.last->next = newNode;
					newNode->back = L.last;
					L.last = newNode;
				}
				else
				{
					//trường hợp chèn vào giữa danh sách
					Node* p = L.first;
					for (int i = 0; i < insert_index - 1; i++)
					{
						p = p->next;
					}
					//chạy hết vòng for thì p đang trỏ vào phần tử đứng trước vị trí cần thêm mới
					p->next->back = newNode;
					newNode->next = p->next;
					p->next = newNode;
					newNode->back = p;
				}
				
			}
			
		}
		else
		{
			cout << "Vi tri can chen phan tu khong hop le" << endl;
		}


	}
}

void Print(DoubleLinkList L)
{
	if (isEmpty(L))
	{
		cout << "Danh sach hien tai dang rong" << endl;
	}
	else
	{
		Node* p = L.first;
		cout << "Danh sach = first <-- {";
		while (p != NULL)
		{
			cout << p->Val;
			if (p->next != NULL)
			{
				cout << ",";
			}
			p = p->next;
		}

		cout << "} --> last" << endl;
	}
}

int main()
{
	string mn = "-------------------------------------------- \n CHUONG TRINH XU LY DANH SACH LIEN KET DOI VOI CON TRO \n 0. Thoat \n 1. Them phan tu vao cuoi danh sach \n 9. In ra \n Lua chon cua ban: ";

	DoubleLinkList L = CreateList();

	int choice = -1;
	int tg;
	int insert_index;
	while (choice != 0)
	{
		cout << mn;
		cin >> choice;

		switch (choice)
		{
		case 1:
			//thêm phần tử vào cuối danh sách
			cout << "Moi nhap vao gia tri cua phan tu can them moi: ";
			cin >> tg;
			cout << "Moi nhap vao vi tri cua phan tu can them moi: ";
			cin >> insert_index;
			Insert(L, tg, insert_index);
			break;

		case 9:
			//in ra
			Print(L);
			break;
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
