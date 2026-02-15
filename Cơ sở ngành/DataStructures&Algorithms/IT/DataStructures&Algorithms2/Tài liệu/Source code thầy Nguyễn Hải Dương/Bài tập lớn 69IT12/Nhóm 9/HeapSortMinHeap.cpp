#include <iostream>
using namespace std;

void heapifyMin(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[smallest] > arr[left])
        smallest = left;
    if (right < n && arr[smallest] > arr[right])
        smallest = right;
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[i], arr[0]);
        heapifyMin(arr, i, 0);
    }
}


int main() {
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Nhap " << n << " so nguyen: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    heapSort(arr, n);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

