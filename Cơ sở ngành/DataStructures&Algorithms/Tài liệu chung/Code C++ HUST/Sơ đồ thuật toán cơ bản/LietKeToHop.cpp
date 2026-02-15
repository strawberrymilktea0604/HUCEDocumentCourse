#include<bits/stdc++.h>
#define N 100

using namespace std;

int x[N];
int k, n;

void Print(){
    for (int i = 1; i <= k; i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

int check(int v, int i){
    return 1;
}

int TRY(int i){
    for (int v = x[i-1] + 1; v <= n-k+i; v++){
        if (check(v, i)){
            x[i] = v;
            if (i == k) Print();
            else TRY(i+1);
        }
    }
}

int main(int argc, const char** argv) {
    cin >> k >> n;
    x[0] = 0;
    TRY(1);
    return 0;
}