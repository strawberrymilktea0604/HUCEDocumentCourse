// DemoDoubleLinkedListwithPointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Node
{
    int Val;
    Node* Next;
    Node* Back;
};

struct DList
{
    Node* First;
    Node* Last;
    //int Length;
};

//hàm khởi tạo 1 node
Node* CreateNode(int val)
{
    Node* n = (Node*)malloc(sizeof(Node));
    n->Val = val;
    n->Next = NULL;
    n->Back = NULL;
    return n;
}

//hàm khởi tạo danh sách
DList CreateList()
{
    DList D;
    D.First = NULL;
    D.Last = NULL;
    return D;
}

//hàm check empty
bool isEmpty(DList D)
{
    if (D.First == NULL && D.Last == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Count(DList D)
{
    Node* p = D.First;
    int count = 0; //biến đếm số lượng phần tử
    while (p != NULL)
    {
        count++;
        p = p->Next;
    }
    return count;
}

//hàm chèn phần tử mới vào danh sách
//insert_index đếm từ First và tính từ 0
void Insert(DList &D, int val, int insert_index)
{
    Node* newNode = CreateNode(val);

    if (isEmpty(D))
    {
        //trường hợp danh sách đang rỗng
        D.First = newNode;
        D.Last = newNode;
    }
    else
    {
        //trường hợp danh sách đang có phần tử
        if (insert_index <= 0)
        {
            //chèn vào đầu của danh sách
            D.First->Back = newNode;
            newNode->Next = D.First;
            D.First = newNode;
        }
        else
        {
            //cần kiểm tra xem insert_index có lớn hơn số lượng phần tử hiện tại của danh sách không
            int DLength = Count(D);
            if (insert_index < DLength)
            {
                //trường hợp chèn vào giữa của danh sách
                Node* p = D.First;
                //tạo vòng lặp để chuyển tiếp con trỏ p đến vị trí trước vị trí cần chèn
                for (int i = 0; i < insert_index - 1; i++)
                {
                    p = p->Next;
                }
                //sau khi chạy qua vòng for thì p đã đứng tại trí trước vị trí cần chèn
                p->Next->Back = newNode;
                newNode->Next = p->Next;
                p->Next = newNode;
                newNode->Back = p;
            }
            else
            {
                //trường hợp chèn vào cuối của danh sách
                D.Last->Next = newNode;
                newNode->Back = D.Last;
                D.Last = newNode;
            }
        }
    }
}

void Print(DList  D)
{
    Node* p = D.First;
    cout << "Danh sach hien tai: First <--{";
    while (p!=NULL)
    {
        cout << p->Val;
        if (p->Next != NULL)
        {
            cout << ",";
        }
        p = p->Next;
    }
    cout << "} --> Last" << endl;
}

int main()
{
    string mn = "-----------------------------------------------\n CHUONG TRINH XU LY DANH SACH LIEN KET DOI \n 0. Thoat \n 1. Them \n 2. In ra \n Lua chon cua ban: ";
    DList D = CreateList();
    int choice = -1;
    int insert_index = 0;
    int insert_val = 0;
    while (choice != 0)
    {
        cout << mn;
        cin >> choice;
        switch (choice)
        {
        case 1:
            //thêm phần tử
            cout << "Moi nhap vao vi tri cua phan tu can chen: ";
            cin >> insert_index;
            cout << "Moi nhap vao gia tri cua phan tu can chen: ";
            cin >> insert_val;
            Insert(D, insert_val, insert_index);
            break;
        case 2:
            //in ra
            Print(D);
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
