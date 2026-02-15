// DemoDataType.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    //các kiểu dữ liệu nguyên thủy
    int x1; //dạng số nguyên, khoảng biểu diễn số từ -2^16 đến 2^16-1
    float x2; //dạng số thập phân
    double x3; //dạng số thực
    char x4; //dạng ký tự
    string x5; //dạng chuỗi
    //....

    //các CTDL nâng cao: Sử dụng các kiểu dữ liệu nguyên thủy như 1 thành phần trong CTDL nâng cao
    //Array, Stack, Queue, List

    //Array
    int A[100]; //khai báo mảng
    //truy cập vào các phần tử của mảng bằng cách sử dụng chỉ số i
    A[0] = 1;
    A[1] = 2;

    cout << "A[0] = " << A[0] <<endl;
    cout << "A[1] = " << A[1] <<endl;

    /*cout << "Dia chi cua A[0]: " << &A[0]<<endl;
    cout << "Dia chi cua A[1]: " << &A[1]<<endl;
    cout << "Dia chi cua A[2]: " << &A[2]<<endl;*/

    //Array truy cập vào phần tử bất kỳ thông qua chỉ số i chạy trong khoảng [0:n-1] (với n là số phần tử của mảng)
    //câu lệnh lặp: for, while
    /*for (int i = 0; i < 100; i++)
    {
        cout << "Dia chi cua A[" << i << "]: " << &A[i] << endl;
    }*/

    int i = 0;
    while (i<100)
    {
        cout << "Dia chi cua A[" << i << "]: " << &A[i] << endl;
        i = i + 1;
        //i++;
    }

    /*do
    {

    } while (true);*/

    //for nên sử dụng khi biết trước số lần lặp
    //while nên sử dụng khi chưa biết trước số lần lặp.
    //while do: kiểm tra trước sau đó mới thực hiện công việc
    //do while: làm trước sau đó mới kiểm tra điều kiện


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
