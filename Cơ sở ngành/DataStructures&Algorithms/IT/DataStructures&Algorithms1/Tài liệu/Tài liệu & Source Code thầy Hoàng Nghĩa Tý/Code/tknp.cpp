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
			if (a[j] < a[j+1])
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
void tknp(int a[],int n,int x)
{
	int front=0,back=n-1,mid;
	int dem=0;
	while (front<=back)
	{
		mid = front + (back-front)/2;
		if (a[mid] == x)
		{
			for(int i=mid;i>=front;i--)
			{
				if (a[i]==x) cout<<i<<" ";  //dem++;
			}     
			for(int i=mid+1;i<=back;i++)
			{
				if (a[i]==x) cout<<i<<" ";//dem++;
			} 
 			//cout<<dem;
			break;
		}           
		else if (a[mid] > x)
        	front = mid+1;
      	else
        	back = mid-1;
    }
}
int main()
{
	int A[7]={5,2,8,3,7,6,3};
	sxnb(A,7);
	for (int i=0;i<7;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	tknp(A,7,3);
	return 0;
	
}
