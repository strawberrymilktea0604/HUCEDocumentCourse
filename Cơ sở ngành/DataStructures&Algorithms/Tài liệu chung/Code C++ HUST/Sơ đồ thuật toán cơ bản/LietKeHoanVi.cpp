#include<bits/stdc++.h>
#define N 20

using namespace std;

int x[N], m[N];
int n;

void Print(){
    for (int i = 1; i <= n; i++){
        cout << x[i];
    }
    cout << endl;
}

void TRY(int i){
    for (int v = 1; v <= n; v++){
        if (!m[v]){
            x[i] = v;
            m[v] = 1;
            // Đánh dấu m[v] = 1 (0) nếu v đã xuất hiện (chưa xuất hiện)
            if (i == n) Print();
            else TRY(i+1);
            m[v] = 0; // Khôi phục
        }
    }
}

int main(int argc, const char** argv) {
    cin >> n;
    for (int v = 1; v <= n; v++){
        m[v] = 0;
    }
    TRY(1);
    return 0;
}