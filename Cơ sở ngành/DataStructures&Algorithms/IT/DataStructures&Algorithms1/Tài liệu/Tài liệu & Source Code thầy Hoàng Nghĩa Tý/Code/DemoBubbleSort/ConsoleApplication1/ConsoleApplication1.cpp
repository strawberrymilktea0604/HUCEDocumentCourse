// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int A[8];
    A[0] = 6;
    A[1] = 3;
    A[2] = 1;
    A[3] = 7;
    A[4] = 9;
    A[5] = 6;
    A[6] = 2;
    A[7] = 4;

    int n = 8;
    int count_i = 0;

    for (int i = 0; i < n; i++)
    {
        count_i++;
        bool is_sorted = true;

        for (int j = 0; j < n-1-i; j++)
        {
            if (A[j] > A[j+1])
            {
                int tg = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tg;
                is_sorted = false;
            }
        }

        if (is_sorted)
        {
            break;
        }
    }

    cout << "A = {";
    for (int i = 0; i < n; i++)
    {
        cout << A[i];
        if (i <n-1)
        {
            cout << "; ";
        }
    }
    cout << "}" << endl;

    cout << "So lan lap i la: " << count_i;
}

