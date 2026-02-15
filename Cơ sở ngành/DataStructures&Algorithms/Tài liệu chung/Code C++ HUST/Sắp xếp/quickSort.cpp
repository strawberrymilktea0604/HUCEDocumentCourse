#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;

void swap(int& a, int& b)  {  
    int temp = a;  
    a = b;  
    b = temp;  
} 

void quickSort(int A[], int L, int R) {
    if(L < R){
        int index = (L + R)/2;
        index = partition(A, L, R, index);
        if(L < index) quickSort(A, L, index-1);
        if(index < R) quickSort(A, index+1, R);
    }
}

int partition(int A[], int L, int R, int indexPivot) {
    int pivot = A[indexPivot];
    swap(A[indexPivot], A[R]);
    int storeIndex = L;
    for(int i = L; i <= R-1; i++){
        if(A[i] < pivot){
            swap(A[storeIndex], A[i]);
            storeIndex++;
        }
    }
    swap(A[storeIndex], A[R]);
    return storeIndex;
}

int main(int argc, const char** argv) {
    int N;
    cin >> N;
    int A[MAX];
    for (int i = 1; i <= N; i++){
        cin >> A[i];
    }

    quickSort(A, 1, N+1);

    for (int i = 1; i <= N; i++){
        cout << A[i] << " ";
    }
    return 0;
}