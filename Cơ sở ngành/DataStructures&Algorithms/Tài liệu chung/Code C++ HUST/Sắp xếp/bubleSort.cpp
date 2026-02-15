#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;

void bubleSort(int A[], int N) {
    // index tu 1 den N
    int swapped;
    do{
        swapped = 0;
        for(int i = 1; i < N; i++){
            if(A[i] > A[i+1]){
                int tmp = A[i]; 
                A[i] = A[i+1];
                A[i+1] = tmp;
                swapped = 1;
            }
        }
    }while(swapped == 1); 
}

int main(int argc, const char** argv) {
    int N;
    cin >> N;
    int A[MAX];
    for (int i = 1; i <= N; i++){
        cin >> A[i];
    }

    bubleSort(A, N);

    for (int i = 1; i <= N; i++){
        cout << A[i] << " ";
    }
    return 0;
}