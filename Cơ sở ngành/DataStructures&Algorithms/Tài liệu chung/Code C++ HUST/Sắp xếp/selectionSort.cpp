#include<bits/stdc++.h>

using namespace std;

const int MAX = 1000;

void selectionSort(int A[], int N) {
    // index tu 1 -> N
    for (int k = 1; k <= N; k++){
        int min = k;
        for (int j = k+1; j <= N; j++){
            if(A[min] > A[j]) min = j;
        }
        int tmp = A[min]; 
        A[min] = A[k]; 
        A[k] = tmp;
    }
}

int main(int argc, const char** argv) {
    int N;
    cin >> N;
    int A[MAX];
    for (int i = 1; i <= N; i++){
        cin >> A[i];
    }

    selectionSort(A, N);

    for (int i = 1; i <= N; i++){
        cout << A[i] << " ";
    }
    return 0;
}



