// DemoSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


int main()
{
    /*int A[9] = { 7,1,54,7,9,2,1,3,5 };
    int x = 1;*/

    //----------------------------------------------------//
    //      THUẬT TOÁN TÌM KIẾM TUẦN TỰ                   //

    ////Level1: tìm thấy hay không?
    //int count = 0;
    //bool isfound = false;
    //for (int i = 0; i < 9; i++)
    //{
    //    count++;
    //    if (A[i] == x)
    //    {
    //        //tìm thấy
    //        cout << "Tim thay x trong A" << endl;
    //        cout << "So lan lap: " << count << endl;
    //        isfound = true;
    //        break;
    //    }
    //}
    //if (!isfound)
    //{
    //    cout << "Khong ton tai x trong A" << endl;
    //}

    ////Level 2: tìm thấy bao nhiêu?
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
        cout << "Khong ton tai x trong A";
    }*/

    ////Level3: tìm thấy tại ví trí nào?
    //int count = 0;
    //bool isfound = false;
    //for (int i = 0; i < 9; i++)
    //{
    //    count++;
    //    if (A[i] == x)
    //    {
    //        //tìm thấy
    //        cout << "Tim thay x trong A tai vi tri " << i << endl;
    //        
    //        isfound = true;
    //        break;
    //    }
    //}
    //if (!isfound)
    //{
    //    cout << "Khong ton tai x trong A" << endl;
    //}

    //cout << "So lan lap: " << count << endl;

    ////Level 4: Tìm thấy bao nhiêu và tại những vị trí nào?
    //int count = 0;
    //int B[9]; //Dùng để lưu các vị trí tìm thấy x trong A
    ////int j = 0; //lấy j để làm index chạy cho B
    //for (int i = 0; i < 9; i++)
    //{
    //    if (A[i] == x)
    //    {
    //        B[count] = i;
    //        count++;           
    //        //j++;
    //    }
    //}
    //if (count > 0)
    //{
    //    cout << "Tim thay " << count << " x trong A tai cac vi tri: ";
    //    for (int i = 0; i < count; i++)
    //    {
    //        cout << B[i];
    //        if (i < count - 1)
    //        {
    //            cout << ",";
    //        }
    //    }
    //}
    //else
    //{
    //    cout << "Khong ton tai x trong A";
    //}

    //      HẾT THUẬT TOÁN TÌM KIẾM TUẦN TỰ
    //----------------------------------------------------//


    //----------------------------------------------------//
    //      THUẬT TOÁN TÌM KIẾM NHỊ PHÂN                  //
    int A[9] = { 1,1,2,3,5,7,8,9,54 };
    
    int x = 7;

    int L = 0;
    int R = 8;  //(n-1)

    bool isfound = false;
    while (L <= R)
    {
        int M = (L + R) / 2;
        if (A[M] == x)
        {
            cout << "Tim thay x trong A tai vi tri " << M << endl;
            isfound = true;
            break;
        }
        else
        {
            if (A[M] < x)
            {
                //x nằm ở nửa phải
                L = M + 1;
            }
            else
            {
                //x nằm ở nửa trái
                R = M - 1;
            }
        }
    }
    if (!isfound)
    {
        cout << "Khong ton tai x trong A" << endl;
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
