#include<bits/stdc++.h>
#define N 20

using namespace std;

int x[N];
int n;

int check(int v, int k){
    if (x[k-1] + v < 2) return 1;
    // Tức là số đằng trước là 0 => 0 + 1 = 1 < 2 -> true
    // hoặc số đằng trước là 1 => 1 + 0 = 1 < 2 -> true
    // Nếu số đằng trước là 1 và 1 + 1 = 2 >= 2 -> false
    return 0;
}

void Print(){
    for (int i = 1; i <= n; i++){
        cout << x[i];
    }
    cout << endl;
}

void TRY(int k){
    for (int v = 0; v <= 1; v++){
        if (check(v, k)){
            x[k] = v;
            if (k == n) Print();
            else TRY(k+1);
        }
    }
}

int main(int argc, const char** argv) {
    cin >> n;
    TRY(1);
    return 0;
}