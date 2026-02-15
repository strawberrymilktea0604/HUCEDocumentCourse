// DemoSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void Print(int A[], int n)
{
	cout << "A = {";
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
	int n = 8;
	//int A[8] = { 5,2,8,9,1,2,0,5 };
	//int A[8] = { 2,0,8,5,1,8,2,9 };
	int A[8] = { 0,1,2,2,5,5,8,9 };
	cout << "Mang ban dau: ";
	Print(A, n);

	////Thuật toán sắp xếp chọn tăng dần
	//for (int i = 0; i < n-1; i++)
	//{
	//	for (int j = i+1; j < n; j++)
	//	{
	//		if (A[i] > A[j])
	//		{
	//			int tg = A[i];
	//			A[i] = A[j];
	//			A[j] = tg;
	//		}
	//	}
	//}

	//Thuật toán sắp xếp nổi bọt tăng dần
	int counti = 0;
	int countj = 0;
	for (int i = 0; i < n; i++)
	{
		int isSorted = true;
		for (int j = 0; j < n-i-1; j++)
		{
			if (A[j] > A[j + 1]) {
				int tg = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tg;
				isSorted = false;
			}
			countj++;
		}
		if (isSorted)
		{
			break;
		}
		counti++;
	}

	cout << "Mang sau khi sap xep tang dan: ";
	Print(A, n);

	cout << "So lan lap i: " << counti << endl;
	cout << "So lan lap j: " << countj << endl;
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
