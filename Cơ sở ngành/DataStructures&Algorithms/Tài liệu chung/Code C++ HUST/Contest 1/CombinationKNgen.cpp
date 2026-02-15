#include<bits/stdc++.h>

using namespace std;

int k, n;
int x[100];
 
void Print(int x[]){
    for (int i = 1; i <= k; i++)
        cout << x[i] << " ";
    cout << endl;
}

void TRY(int i) {
    for (int v = x[i-1]+1; v <= n-k+i; v++){
        x[i] = v;
        if(i == k){
            Print(x);
        }else TRY(i+1);	
    }
}

int main(int argc, const char** argv) {
    cin >> k >> n;
    x[0] = 0;
    TRY(1);
    return 0;
}