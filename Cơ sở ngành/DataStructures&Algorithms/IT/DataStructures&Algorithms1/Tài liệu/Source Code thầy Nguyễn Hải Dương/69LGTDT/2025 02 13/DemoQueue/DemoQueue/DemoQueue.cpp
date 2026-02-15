// DemoQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

bool isEmpty(int front, int rear)
{
    if (front <= rear)
    {
        //hợp lệ
        if (front < 0 && rear < 0)
        {
            return true; //Queue đang rỗng
        }
        else
        {
            return false; //Queue đang có không rỗng
        }
    }
    else
    {
        //không hợp lệ
        cout << "2 bien chay khong hop le";
        return false;
    }    
}


//Cấu trúc khai báo hàm: <Output Datatype> <Funct Name> ( <Parameters> ) { <Process Code> }
void Add(int Q[], int& front, int& rear, int new_val)
{
    //kiểm tra xem Q có đang rỗng hay không
    if (isEmpty(front, rear))
    {
        //Q đang rỗng
        front = 0;
        rear = 0;
        Q[rear] = new_val;
    }
    else
    {
        //Q đang không rỗng
        rear++;
        Q[rear] = new_val;
    }
}

//hàm lấy phần tử từ Queue
int Get(int Q[], int &front, int &rear)
{
    if (isEmpty(front, rear))
    {
        //Queue đang rỗng
        cout << "Queue dang rong" << endl;
        return -32000;
    }
    else
    {
        //Queue có phần tử
        int x = Q[front];
        for (int i = front; i < rear; i++)
        {
            Q[i] = Q[i + 1];
        }
        rear--;
        return x;
    }
}

//Hàm sửa phần tử trong queue
void Edit(int Q[], int &front, int &rear, int edit_index, int new_val)
{
    if (isEmpty(front, rear))
    {
        //trường hợp Q đang rỗng
        cout << "Queue dang rong" << endl;
    }
    else
    {
        //trường hợp Q đang không rỗng
        //kiểm tra tính hợp lệ của các input
        if (edit_index >= front && edit_index <= rear)
        {
            //tạo biến đếm chỉ số để kiểm tra xem có phải là phần tử cần sửa không.
            int count = -1;
            //trường hợp edit_index hợp lệ
            int old_rear = rear;
            for (int i = front; i <= old_rear; i++)
            {
                int x = Get(Q, front, rear);

                //tăng count lên
                count++;
                //kiểm tra xem có phải là phần tử cần sửa không.
                if (count == edit_index)
                {
                    //đúng là phần tử cần sửa thì sửa
                    x = new_val;
                }

                Add(Q, front, rear, x);
            }
        }
        else
        {
            //trường hợp edit_index không hợp lệ
            cout << "Vi tri cua phan tu can sua khong hop le" << endl;
        }
    }
}

//Hàm sửa phần tử trong queue
void Del(int Q[], int& front, int& rear, int del_index)
{
    if (isEmpty(front, rear))
    {
        //trường hợp Q đang rỗng
        cout << "Queue dang rong" << endl;
    }
    else
    {
        //trường hợp Q đang không rỗng
        //kiểm tra tính hợp lệ của các input
        if (del_index >= front && del_index <= rear)
        {
            //tạo biến đếm chỉ số để kiểm tra xem có phải là phần tử cần xóa không.
            int count = -1;
            //trường hợp del_index hợp lệ
            int old_rear = rear;
            for (int i = front; i <= old_rear; i++)
            {
                int x = Get(Q, front, rear);

                //tăng count lên
                count++;
                //kiểm tra xem có phải là phần tử cần xóa không.
                if (!(count == del_index))
                {
                    //Nếu không phải là phần tử cần xóa thì chèn trả vào Q
                    Add(Q, front, rear, x);
                }                
            }
        }
        else
        {
            //trường hợp del_index không hợp lệ
            cout << "Vi tri cua phan tu can xoa khong hop le" << endl;
        }
    }
}

//in ra Queue hiện tại 
void Print(int Q[], int front, int rear)
{
    if (isEmpty(front, rear))
    {
        cout << "Queue dang rong" << endl;
    }
    else
    {
        cout << "Q = front <-- {";
        for (int i = front; i <= rear; i++)
        {
            cout << Q[i] << ",";
        }
        cout << "} <-- rear" << endl;
    }
    
}

int main()
{
    //khởi tạo queue bằng cơ sở mảng
    int Q[10];
    int front = -1, rear = -1; //front và rear ban đầu chưa trỏ vào đâu

    //in ra Queue trong trường hợp rỗng
    Print(Q, front, rear);

    //thêm phần tử vào Queue
    Add(Q, front, rear, 1);
    Add(Q, front, rear, 2);
    Add(Q, front, rear, 3);
    Add(Q, front, rear, 4);

    //in ra Queue trong trường hợp đã có phần tử
    cout << "Queue ban dau: ";
    Print(Q, front, rear);

    //gọi hàm sửa
    Edit(Q, front, rear, 1, 7);

    //in ra Queue sau khi sua phan tu
    cout << "Queue da sua: ";
    Print(Q, front, rear);


    //gọi hàm Xóa
    Del(Q, front, rear, 1);

    //in ra Queue sau khi sua phan tu
    cout << "Queue da xoa: ";
    Print(Q, front, rear);

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
