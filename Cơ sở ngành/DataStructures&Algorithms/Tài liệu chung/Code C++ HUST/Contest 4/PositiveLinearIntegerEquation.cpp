#include<bits/stdc++.h>

using namespace std;

int n, M;
int a[20];
int x[20];
int T = 0, R = 0;
int res = 0;

void inputData(){
    cin >> n >> M;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

bool check(int v, int k){
    if (k < n) return true;
    
    if (T + a[n]*v == M) return true;
    else return false;
} 

void solution(){
    res += 1;
}

void TRY(int k){
    // Thử tất cả giá trị cho x[k]
    for (int v = 1; v <= (M-T-R)/a[k]; v++){
        if (check(v, k)){
            x[k] = v;
            T = T + a[k]*x[k];
            R = R - a[k+1];

            if (k == n) solution();
            else TRY(k+1);

            T = T - a[k]*x[k];
            R = R + a[k+1];
        }
    }
}

int main(int argc, const char** argv) {
    inputData();
    for (int i = 2; i <= n; i++){
        R = R + a[i];
    }
    TRY(1);
    cout << res;
    return 0;
}