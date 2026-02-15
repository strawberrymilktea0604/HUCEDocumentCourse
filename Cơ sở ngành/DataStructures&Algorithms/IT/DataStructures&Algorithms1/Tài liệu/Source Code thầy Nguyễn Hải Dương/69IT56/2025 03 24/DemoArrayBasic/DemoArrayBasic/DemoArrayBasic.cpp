// DemoArrayBasic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    int A[10]; //khai báo mảng tĩnh 1 chiều

    cout << "Dia chi cua vung nho luu tru mang A: " << &A <<endl;
    cout << "Dia chi cua A[0]: " << &A[0] <<endl;
    cout << "Dia chi cua A[1]: " << &A[1] <<endl;
    cout << "Dia chi cua A[2]: " << &A[2] <<endl;
    cout << "Dia chi cua A[3]: " << &A[3] <<endl;

    A[0] = 1;
    A[1] = 2;

    A[1] = 0;
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
