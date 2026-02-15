#include <iostream>
using namespace std;
void heapify(int a[], int n, int i)
{
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest = i;
	if (left < n && a[left] > a[largest])
	{
		largest = left;
	}
	if (right < n && a[right] > a[largest])
	{
		largest = right;
	}
	if (largest != i)
	{
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}
void heapsort(int a[], int n)
	{
		for (int i = n / 2 - 1; i >= 0; i--)
		{
			heapify(a, n, i);
		}
		for (int i = n - 1; i >= 0; i--)
		{
			swap(a[i], a[0]);
			heapify(a, i, 0);
		}

	}

int main() 
{
	int n;
	cout << "Nhap kich thuoc mang : ";
	cin >> n;
	int* array = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu o vi tri " << i << " : ";
		cin >> array[i];
	}
	cout << "Mang ban da nhap la : ";
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
	heapsort(array, n);
	cout << "Mang sau khi thuc hien heapsort : ";
	for (int i = 0; i < n; i++)
	{
		cout<< array[i] << " ";
	}
}



