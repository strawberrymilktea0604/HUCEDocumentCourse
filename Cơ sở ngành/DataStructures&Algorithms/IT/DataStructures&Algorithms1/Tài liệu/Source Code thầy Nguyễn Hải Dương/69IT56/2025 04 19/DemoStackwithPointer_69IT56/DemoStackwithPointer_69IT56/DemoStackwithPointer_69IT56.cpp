// DemoStackwithPointer_69IT56.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Node {
	int  Val;
	Node* Link;
};

struct Stack {
	Node* top;
	/*int count;*/
};

//hàm dùng để khởi tạo 1 phần tử mới
Node* CreateNode(int value)
{
	Node* new_Node = (Node*)malloc(sizeof(Node));
	//int* p = (int*)malloc(sizeof(int));
	new_Node->Val = value;
	new_Node->Link = NULL;
	return new_Node;
}

//hàm dùng để khởi tạo 1 Stack
Stack CreateStack()
{
	Stack S;
	S.top = NULL;
	return S;
}

//hàm kiểm tra xem stack có đang rỗng không
bool isEmpty(Stack S)
{
	if (S.top == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}

	//return S.top == NULL;
}

//hàm dùng để thêm phần tử vào stack
void Add(int val, Stack& S)
{
	if (isEmpty(S))
	{
		//Trường hợp ngăn xếp đang rỗng
		//B1: Khởi tạo phần tử
		Node* tg = CreateNode(val);
		//B2: Trỏ Top vào phần tử vừa được khởi tạo
		S.top = tg;

		//S.top = CreateNode(val);
	}
	else
	{
		//trường hợp ngăn xếp đang có phần tử
		//B1: Khởi tạo phần tử mới
		Node* tg = CreateNode(val);
		//B2: Lấy phần Link của Node mới trỏ về S.top hiện tại
		tg->Link = S.top;
		//B3: Trỏ top của ngăn xếp hiện tại vào phần tử mới
		S.top = tg;
	}
}

void Print(Stack S)
{
	if (isEmpty(S))
	{
		//ngăn xếp đang rỗng
		cout << "Ngan xep chua co phan tu nao" << endl;
	}
	else
	{
		Node* p = S.top;
		cout << "S = top <-- {";
		while (p != NULL)
		{
			cout << p->Val;
			//kiểm tra xem đã là phần tử cuối cùng của ngăn xếp chưa
			if (p->Link != NULL)
			{
				cout << ",";
			}			
			p = p->Link;
		}
		cout << "}" << endl;

		//p->Link = p->Link->Link;
	}
}

//hàm lấy ra phần tử của Ngăn xếp
Node* Get(Stack& S)
{
	if (isEmpty(S))
	{
		cout << "Ngan xep dang rong" << endl;
	}
	else
	{
		//B1: Lấy phần tử ở đỉnh của ngăn xếp
		Node* tg = S.top;
		//B2: Dịch S.top về phần tử ngay bên dưới của nó
		S.top = S.top->Link;
		//B3: return phần tử ở đỉnh của ngăn xếp ra khỏi hàm
		return tg;
	}
}

int main()
{
	Stack S = CreateStack();
	string mn = "************************************* \n CHUONG TRINH XU LY NGAN XEP VOI CON TRO \n Danh sach chuc nang \n 0. Thoat \n 1. Them \n 2. In ra \n 3. Lay phan tu \n Lua chon cua ban: ";

	int choice = -1;
	while (choice != 0)
	{
		cout << mn;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Moi nhap vao gia tri cua phan tu can them moi: ";
			int tg;
			cin >> tg;
			Add(tg, S);
			break;

		case 2:
			Print(S);
			break;

		case 3:
			Node * node_Top = Get(S);
			cout << "Phan tu o dinh cua Ngan xep: " << node_Top->Val << endl;
			//Chú ý: Bạn cần free phần tử node_Top sau khi xử lý xong để giải phóng bộ nhớ của nó
			free(node_Top);
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
