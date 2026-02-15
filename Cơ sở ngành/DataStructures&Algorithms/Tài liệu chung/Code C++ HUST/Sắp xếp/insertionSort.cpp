#include<bits/stdc++.h>

using namespace std;

const int MAX = 1000;

void insertionSort(int A[], int N) {
    // index tu 1 -> N
    for(int k = 2; k <= N; k++){
        int last = A[k];
        int j = k;
        while(j > 1 && A[j-1] > last){
            A[j] = A[j-1];
            j--;
        }
        A[j] = last;
    }
}

int main(int argc, const char** argv) {
    int N;
    cin >> N;
    int A[MAX];
    for (int i = 1; i <= N; i++){
        cin >> A[i];
    }

    insertionSort(A, N);

    for (int i = 1; i <= N; i++){
        cout << A[i] << " ";
    }
    return 0;
}