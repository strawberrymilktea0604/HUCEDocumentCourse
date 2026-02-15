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
    Node* front;
    Node* rear;
};

Node* CreateNode(int val)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->Val = val;
    p->Link = NULL;
    return p;
}

Queue CreateQueue()
{
    Queue Q;
    Q.front = NULL;
    Q.rear = NULL;
    return Q;
}

bool isEmpty(Queue Q)
{
    if (Q.front == NULL && Q.rear == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Add(Queue& Q, int val)
{
    Node* newNode = CreateNode(val);

    if (isEmpty(Q))
    {
        //đang rỗng
        Q.front = newNode;
        Q.rear = newNode;
    }
    else
    {
        Q.rear->Link = newNode;
        Q.rear = newNode;
    }
}

Node* Get(Queue& Q)
{
    if (isEmpty(Q))
    {
        cout << "Hang doi dang rong" << endl;
        return NULL;
    }
    else
    {
        Node* nodeFront = Q.front;
        Q.front = Q.front->Link; //DỊch con trỏ front sang phần tử tiếp theo
        return nodeFront;
    }
}

void Print(Queue Q)
{
    if (isEmpty(Q))
    {
        cout << "Hang doi dang rong" << endl;
    }
    else
    {
        Node* p = Q.front;
        cout << "Q = front <-- {";
        while (p != NULL)
        {
            cout << p->Val;
            //kiểm tra xem đã phải là phần tử cuối cùng chưa
            if (p->Link != NULL)
            {
                cout << ",";
            }
            p = p->Link;
        }

        cout << "} <-- rear" << endl;
    }
}

int Count_Node_of_Queue(Queue Q)
{
    if (isEmpty(Q))
    {
        return 0;
    }
    else
    {
        Node* p = Q.front;
        int count = 0;
        while (p != NULL)
        {
            count++;
            p = p->Link;
        }

        return count;
    }
}

void Edit(Queue& Q, int edit_index, int edit_val)
//edit_index là vị trí của phần tử cần sửa tính từ front và đếm từ 0
//edit_val là giá trị mới cần thay vào vị trí edit_index
{
    if (isEmpty(Q))
    {
        cout << "Hang doi dang rong nen khong sua duoc phan tu" << endl;
    }
    else
    {
        //hang doi co phan tu
        int count = Count_Node_of_Queue(Q);
        if (edit_index >= 0 && edit_index < count)
        {
            Node* p = Q.front;
            //edit_index hợp lệ
            for (int i = 0; i < edit_index; i++)
            {
                p = p->Link;
            }
            p->Val = edit_val;
            cout << "Sua phan tu thanh cong" << endl;
        }
        else
        {
            //edit_index không hợp lệ
            cout << "Vi tri cua phan tu can sua khong hop le" << endl;
        }
    }
}

void Del(Queue& Q, int del_index)
//del_index là vị trí của phần tử cần sửa tính từ front và đếm từ 0
//del_val là giá trị mới cần thay vào vị trí del_index
{
    if (isEmpty(Q))
    {
        cout << "Hang doi dang rong nen khong xoa duoc phan tu" << endl;
    }
    else
    {
        //hang doi co phan tu
        int count = Count_Node_of_Queue(Q);
        if (del_index >= 0 && del_index < count)
        {
            Node* p = Q.front;
            //del_index hợp lệ
            for (int i = 0; i < del_index -1; i++)
            {
                p = p->Link;
            }

            //p đang trỏ vào phần tử đứng trước phần tử cần xóa
            Node* q = p->Link;
            p->Link = p->Link->Link;
            //p->Link = q->Link;
            free(q);
            cout << "Xoa phan tu thanh cong" << endl;
        }
        else
        {
            //del_index không hợp lệ
            cout << "Vi tri cua phan tu can xoa khong hop le" << endl;
        }
    }
}

int main()
{
    string mn = "------------------------------------------ \n CHUONG TRINH XU LY HANG DOI VOI CON TRO \n Chuc nang he thong: \n 0. Thoat \n 1. Them \n 2. Lay phan tu \n 3. Sua phan tu \n 4. Xoa phan tu \n 5. In ra \n 6. Dem so luong phan tu trong hang doi hien tai \n Lua chon cua ban: ";

    Queue Q = CreateQueue();
    Node* firstNode = NULL;

    int edit_index = -1;
    int edit_val;
    int del_index = -1;
    int choice = -1;
    while (choice != 0)
    {
        cout << mn;
        cin >> choice;
        switch (choice)
        {
        case 1:
            //thêm phần tử
            cout << "Moi nhap vao gia tri cua phan tu moi: ";
            int tg;
            cin >> tg;
            Add(Q, tg);
            break;

        case 2:
            //Lấy phần tử ra khỏi Queue
            firstNode = Get(Q);
            cout << "Phan tu o dau front cua hang doi hien tai: " << firstNode->Val << endl;
            free(firstNode);
            break;

        case 3:
            cout << "Moi nhap vao vi tri cua phan tu can sua dem tu front va dem tu 0: ";            
            cin >> edit_index;
            cout << "Moi nhap vao gia tri moi cua phan tu can sua: ";
            cin >> edit_val;

            Edit(Q, edit_index, edit_val);
            break;

        case 4:
            cout << "Moi nhap vao vi tri cua phan tu can xoa dem tu front va dem tu 0: ";
            cin >> del_index;

            Del(Q, del_index);
            break;

        case 5: 
            //in ra
            Print(Q);
            break;

        case 6:
            //đếm số lượng phần tử
            cout << "So luong phan tu hien tai cua hang doi: " << Count_Node_of_Queue(Q) << endl;
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
