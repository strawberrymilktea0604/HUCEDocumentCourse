// DemoPointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    /*int x = 5;
    cout << "Dia chi cua x: " << &x << endl;

    int* p = &x;
    cout << "Gia tri cua p: " << p << endl;

    cout << "Gia tri cua x=" << x << endl;
    cout << "Du lieu luu tru trong vung nho ma p dang tro vao: " << *p << endl;

    int A[5];
    cout << "Dia chi cua A: " << &A << endl;
    p = A;
    cout << "Gia tri cua p: " << p << endl;

    A[0] = 1;
    A[1] = 2;
    A[2] = 3;
    A[3] = 7;

    cout << "A[0]=" << A[0] << endl;
    cout << "*p = " << *p << endl;

    p++;
    cout << "*p = " << *p << endl;
    p++;
    cout << "*p = " << *p << endl; 
    p--;
    cout << "*p = " << *p << endl;*/

    //int* p = (int*)malloc(sizeof(int));
    int* p = (int*)calloc(1, sizeof(int));

    cout << "Gia tri cua p: " << p << endl;
    cout << "Du lieu duoc luu tru tren vung nho ma p dang tro vao: " << *p << endl;


    //sử dụng con trỏ để xử lý 1 mảng tĩnh
    p = (int*)malloc(5 * sizeof(int));
    //p = (int*)calloc(5, sizeof(int));

    int* q = p;

    cout << "Dia chi cua A[0]: " << p << endl;
    //gán giá trị cho A[0]
    *p = 1;
    cout << "A[0]=" << *p <<endl;
    p++;
    *p = 2;

    cout << "A[1]=" << *p << endl;

    p++;
    *p = 3;

    cout << "A[2]=" << *p << endl;

    p--;
    cout << "A[1]=" << *p << endl; 
    p--;
    cout << "A[0]=" << *p << endl; 
    p--;
    cout << "A[-1]=" << *p << endl;

    p = q;
    cout << "A[0]=" << *p << endl;
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
