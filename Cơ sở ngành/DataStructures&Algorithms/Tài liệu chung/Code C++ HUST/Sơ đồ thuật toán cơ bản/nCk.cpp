#include<bits/stdc++.h>

using namespace std;

// Sử dụng đệ quy có nhớ

int m[100][100];

int C(int k, int n) {
    if (k == 0 || k == n)    
        m[k][n] = 1;
    else{
        if(m[k][n] == -1)
            m[k][n] = C(k-1, n-1) + C(k, n-1);
    }
    return m[k][n]; 
}

int main(int argc, const char** argv) {
    int k, n;
    cin >> k >> n;
    
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 100; j++)
            m[i][j] = -1;   
    
    cout << C(k, n);
}
