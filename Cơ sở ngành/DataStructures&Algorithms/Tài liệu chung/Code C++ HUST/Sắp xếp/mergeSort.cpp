#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;

void mergeSort(int A[], int L, int R) {
    if (L < R){
        int M = (L + R)/2;
        mergeSort(A, L, M);
        mergeSort(A, M+1, R);
        merge(A, L, M, R);
    }
}

void merge(int A[], int &L, int &M, int &R) {
    // tron 2 day da sap A[L..M] va A[M+1..R]
    int i = L; 
    int j = M+1;
    int TA[MAX];
    for (int k = L; k <= R; k++){
        if (i > M){ 
            TA[k] = A[j]; 
            j++;
        }else if (j > R){
            TA[k] = A[i]; 
            i++;
        }else{
            if (A[i] < A[j]){
                TA[k] = A[i]; 
                i++;
            }else {
                TA[k] = A[j]; 
                j++;
            }
        }	
    }
    for(int k = L; k <= R; k++){
        A[k] = TA[k];
    }
}



int main(int argc, const char** argv) {
    int N;
    cin >> N;
    int A[MAX];
    for (int i = 1; i <= N; i++){
        cin >> A[i];
    }

    mergeSort(A, N);

    for (int i = 1; i <= N; i++){
        cout << A[i] << " ";
    }
    return 0;
}