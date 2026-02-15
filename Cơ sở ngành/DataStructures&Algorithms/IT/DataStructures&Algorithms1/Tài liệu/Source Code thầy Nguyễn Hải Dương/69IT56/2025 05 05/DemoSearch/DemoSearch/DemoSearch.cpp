// DemoSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    int A[9] = { 1,4,3,11,15,43,12,8,4 };

    int x = 4;
    //********************************************************//
    //              THUẬT TOÁN TÌM KIẾM TUẦN TỰ               //
    
    //Level1: tìm thấy hay không?
    int count_i = 0;
    /*bool is_found = false;
    for (int i = 0; i < 9; i++)
    {
        count_i++;
        if (A[i] == x)
        {
            cout << "Tim thay x trong A" << endl; 
            is_found = true;
            break;
        }
    }
    if (!is_found)
    {
        cout << "Khong tim thay x trong A" << endl;
    }
    cout << "So vong lap: " << count_i << endl;*/

    //Level 2: Tìm thấy bao nhiêu
    /*int count = 0;
    for (int i = 0; i < 9; i++)
    {
        if (A[i] == x)
        {
            count++;
        }
    }
    if (count > 0)
    {
        cout << "Tim thay " << count << " x trong A" << endl;
    }
    else
    {
        cout << "Khong tim thay x trong A" << endl;
    }*/

    //Level 3: Tìm thấy tại ví trí nào?
    /*bool is_found = false;
    for (int i = 0; i < 9; i++)
    {
        count_i++;
        if (A[i] == x)
        {
            cout << "Tim thay x trong A tai vi tri " << i << endl;
            is_found = true;
            break;
        }
    }
    if (!is_found)
    {
        cout << "Khong tim thay x trong A" << endl;
    }
    cout << "So vong lap: " << count_i << endl;*/


    //Level 4: Tìm thấy bao nhiêu và tại các vị trí nào?
    //int count = 0;
    int B[9]; //dùng để lưu các vị trí tìm thấy x trong A
    int j = 0; //j là index chạy theo mảng B, đồng thời j cũng chính là số lượng phần tử thỏa mãn điều kiện tìm kiếm trong A
    for (int i = 0; i < 9; i++)
    {
        if (A[i] == x)
        {
            //count++;
            B[j] = i;
            j++;
        }
    }

    if (j > 0)
    {
        //tìm thấy
        cout << "Tim thay " << j << " x trong A tai cac vi tri: ";
        for (int i = 0; i < j; i++)
        {
            cout << B[i];
            if (i < j-1)
            {
                cout << ",";
            }
        }
        cout << endl;
    }
    else
    {
        cout << "Khong tim thay x trong A" << endl;
    }

    //              HẾT THUẬT TOÁN TÌM KIẾM TUẦN TỰ             //
    //**********************************************************//

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
