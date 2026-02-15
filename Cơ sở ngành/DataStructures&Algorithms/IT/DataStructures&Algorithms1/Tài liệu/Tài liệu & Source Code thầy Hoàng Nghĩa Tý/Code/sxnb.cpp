#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

void sxnb(int a[], int n)
{
	for (int i = n-1; i >= 1; i--)
	{
		bool swapped= true;
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				swapped = false;
			}
		}
		if (swapped)
		{
			break;
		}
	}
}

int main()
{
	int A[6]={5,2,8,3,7,6};
	sxnb(A,5);
	for (int i=0;i<5;i++)
	{
		cout<<A[i]<<" ";
	}
	return 0;
}
