// DemoSelectionSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void Print(int A[], int n)
{
	cout << "A={";
	for (int i = 0; i < n; i++)
	{
		cout << A[i];
		if (i < n-1)
		{
			cout << ",";
		}
	}
	cout << "}" << endl;
}

int main()
{
    //int A[8] = { 2,1,0,9,3,5,7,7 }; //n=8
    int A[8] = {  0, 1, 2, 3, 5, 7, 7, 9 }; //n=8

	cout << "Mang ban dau: ";
	Print(A, 8);

 //   //thuật toán sắp xếp chọn tăng dần
	//for (int i = 0; i < 7; i++)
	//{
	//	for (int j = i+1; j < 8; j++)
	//	{
	//		if (A[i] > A[j])
	//		{
	//			//thuật toán đổi chỗ
	//			int tg = A[i];
	//			A[i] = A[j];
	//			A[j] = tg;
	//		}
	//	}
	//}

	//Thuật toán sắp xếp nổi bọt tăng dần
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		bool isSorted = true;
		for (int j = 0; j < 7 - i; j++)
		{
			if (A[j] > A[j+1])
			{
				//thuật toán đổi chỗ
				int tg = A[j];
				A[j] = A[j+1];
				A[j+1] = tg;
				isSorted = false;
			}
			count++;
		}

		if (isSorted)
		{
			break;
		}
	}

	//in ra
	cout << "Mang sau khi sap xep: ";
	Print(A, 8);

	cout << "So lan lap: " << count << endl;
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
