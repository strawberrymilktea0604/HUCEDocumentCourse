#include<bits/stdc++.h>

using namespace std;

int x[7]; // I C T H U S K
bool mark[10];
int N;
int ans = 0;
int check(){
    // ICT − K62 + HUST = N
    int result = (x[0]*100 + x[1]*10 + x[2]) - (x[6]*100 + 62) + (x[3]*1000 + x[4]*100 + x[5]*10 + x[2]);
    if (result == N)
        return 1;
    return 0;
}

void TRY(int k){
    for (int i = 1; i <= 9; i++){
        if(!mark[i]){
            x[k] = i;
            mark[i] = true;
            if (k == 6)
                ans += check();
            else
                TRY(k+1);
            mark[i] = false;
        }
    }
}

int main(int argc, const char** argv) {
    cin >> N;
    for (int i = 1; i <= 9; i++){
        mark[i] = false;
    }
    TRY(0);
    cout << ans;
    return 0;
}