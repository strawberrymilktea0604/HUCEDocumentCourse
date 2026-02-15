// DemoQueuewithPointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Node
{
    int Val;
    Node* Link;
};

struct Queue
{
    Node* First;
    Node* Last;
    //int max_size;
};

Queue CreateQueue()
{
    Queue q;
    q.First = NULL;
    q.Last = NULL;
    return q;
}

bool isEmpty(Queue q)
{
    if (q.First == NULL && q.Last == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Node* CreateNode(int val)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->Val = val;
    p->Link = NULL;
    return p;
}

void Add(Queue &Q, int val)
{
    if (isEmpty(Q))
    {
        //trường hợp queue đang rỗng
        Node* new_node = CreateNode(val);
        Q.First = new_node;
        Q.Last = new_node;
    }
    else
    {
        //trường hợp queue đã có phần tử
        Node* new_node = CreateNode(val);
        Q.Last->Link = new_node; //Lấy phần Link của Q.Last hiện tại trỏ về phần tử mới
        Q.Last = new_node; //Trỏ Q.Last về phần tử mới được thêm vào queue
    }
}

Node* Get(Queue& Q)
{
    if (isEmpty(Q))
    {
        cout << "Queue dang rong" << endl;
    }
    else
    {
        Node* tg = Q.First;
        Q.First = Q.First->Link;
        return tg;
    }
}

void Print(Queue Q)
{
    if (isEmpty(Q))
    {
        cout << "Queue dang rong" << endl;
    }
    else
    {
        //queue có phần tử
        Node* p = Q.First;
        cout << "Q = First <-- {";
        while (p != NULL)
        {
            cout << p->Val;
            //kiểm tra xem có phải phần tử cuối cùng không
            if (p->Link != NULL)
            {
                cout << ",";
            }
            p = p->Link;
        }
        cout << "} <-- Last" << endl;
    }
}

int main()
{
    Queue Q = CreateQueue();
    string mn = "********************************************* \n Chuong trinh xu ly du lieu voi Hang doi. Moi chon chuc nang: \n 0. Thoat \n 1. Them \n 2. In ra \n 3. Lay phan tu \n Lua chon cua ban: ";
    int choice = -1;
    while (choice != 0)
    {
        cout << mn;
        cin >> choice;
        switch (choice)
        {
        case 1:
            //thêm mới phần tử
            cout << "Moi nhap gia tri phan tu moi: ";
            int tg;
            cin >> tg;
            Add(Q, tg);
            break;
        case 2:
            Print(Q);
            break;

        case 3:
            Node* firstNode = Get(Q);
            cout << "Phan tu vua duoc lay ra khoi Queue: " << firstNode->Val << endl;
            free(firstNode); //dùng để lấy lại vùng nhớ mà phần tử firstNode đang chiếm giữ. Có thể sử dụng lại cho các phần tử tiếp theo
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
