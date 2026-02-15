// DemoArray2D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    //int A[10][8]; //m=10, n=8

    //cout << "Dia chi co so cua A: " << &A << endl;

    ////tính địa chỉ lưu trữ của A[i,j]
    //int i = 3;
    //int j = 5;

    //cout << "Dia chi luu tru cua phan tu A[" << i << "][" << j << "]: " << &A[i][j];

    int B[2][3];
    B[0][0] = 1;
    B[0][1] = 2;
    B[0][2] = 3;
    B[1][0] = 4;
    B[1][1] = 5;
    B[1][2] = 6;

    //in mảng 2 chiều
    for (int i = 0; i < 2; i++) //for theo hàng
    {
        for (int j = 0; j < 3; j++) //for theo từng phần tử trong hàng
        {
            cout << B[i][j] << " "; //in ra từng phần tử của hàng
        }
        cout << endl; //xuống dòng sau khi in từng hàng
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
