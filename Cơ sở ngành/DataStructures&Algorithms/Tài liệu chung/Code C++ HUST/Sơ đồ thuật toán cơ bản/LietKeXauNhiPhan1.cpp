#include<bits/stdc++.h>
#define N 20

using namespace std;

int x[N];
int n;

int check(int v, int k){
    return 1;
}

void Print(){
    for (int i = 1; i <= n; i++){
        printf("%d", x[i]);
    }
    printf("\n");
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
    scanf("%d", &n);
    TRY(1);
    return 0;
}
