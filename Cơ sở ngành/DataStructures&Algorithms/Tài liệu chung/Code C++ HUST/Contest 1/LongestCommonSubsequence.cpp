#include <bits/stdc++.h>

using namespace std;

const int N = 10001;
int X[N], Y[N];
int n, m;
int S[N][N];  

void inputData(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> X[i];
    }
    for (int j = 1; j <= m; j++){
        cin >> Y[j];
    }
}

int solve(){
    for (int i = 0; i <= n; i++) S[i][0] = 0;
    for (int j = 0; j <= m; j++) S[0][j] = 0;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (X[i] == Y[j]) S[i][j] = S[i-1][j-1] + 1;
            else{
                if (S[i-1][j] > S[i][j-1]) S[i][j] = S[i-1][j];
                else S[i][j] = S[i][j-1];
            }
        }
    }

    return S[n][m];
}

int main(int argc, const char** argv) {
    inputData();
    cout << solve();
    return 0;
}