// DemoStackWithPointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

//định nghĩa cấu trúc của 1 phần tử
struct Node
{
    int Value;
    Node* Back;
};
//định nghĩa cấu trúc của Stack
struct Stack
{
    Node* Top;
    //int max_size;
    //int count;
};

Node* CreateNode(int val)
{
    Node* new_Node = (Node*)malloc(sizeof(Node));
    new_Node->Value = val;
    new_Node->Back = NULL;
    return new_Node;
}

Stack CreateStack()
{
    Stack S;
    S.Top = NULL;
    return S;
}

//hàm kiểm tra trạng thái của stack
bool isEmpty(Stack S)
{
    if (S.Top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//bool isFull(Stack S)
//{
//    if (S.count >= S.max_size)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}

//tạo các hàm tương tác với stack
void Push(Stack& S, int val)
{
    //kiểm tra xem stack có đang rỗng không
    if (isEmpty(S))
    {
        //trường hợp Stack đang rỗng
        Node* new_Node = CreateNode(val);
        S.Top = new_Node;
    }
    else
    {
        //trường hợp Stack đã có phần tử
        //B1: Khởi tạo phần tử mới
        Node* new_Node = CreateNode(val);
        //B2: Trỏ link của phần tử mới về TOp hiện tại
        new_Node->Back = S.Top;
        //B3: Trỏ top về phần tử mới
        S.Top = new_Node;
    }
}

void Print(Stack S)
{
    if (isEmpty(S))
    {
        cout << "Ngan xep dang rong" << endl;
    }
    else
    {
        cout << "Ngan xep hien tai: S = Top ->> {";
        Node* p = S.Top;
        while (p != NULL)
        {
            cout << p->Value;
            //kiểm tra xem đã gặp phần tử gần cuối chưa?
            if (p->Back != NULL)
            {
                cout << ",";
            }
            //dịch con trỏ p sang phần tử tiếp theo
            p = p->Back;
        }
        cout << "}" << endl;

    }
}

int main()
{
    Stack S = CreateStack();
    //in ra stack ban đầu
    Print(S);

    //Thêm mới phần tử có giá trị = 1 vào stack;
    Push(S, 1);
    //in lại stack
    Print(S);

    //Tiếp tục thêm các phần tử khác vào stack
    Push(S,2);
    Push(S,3);
    Push(S,4);
    Push(S,5);
    //in lại stack
    Print(S);
}
