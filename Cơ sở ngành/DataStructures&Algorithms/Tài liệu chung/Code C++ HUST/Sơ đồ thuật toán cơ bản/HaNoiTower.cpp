#include<bits/stdc++.h>

using namespace std;

int cnt;
void move(int n, char A, char B, char C){
    if (n == 1){
        cnt += 1;
        cout << "Step " << cnt << ": ";
        cout << "Move from " << A << " to " << B << endl;
    }
    else{
        move(n-1, A, C, B);
        move(1, A, B, C);
        move(n-1, C, B, A);
    }
}

int main(int argc, const char** argv) {
    cnt = 0;
    int n;
    cin >> n;
    move(n, 'A', 'B', 'C');
    return 0;
}