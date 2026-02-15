#include <iostream>

using namespace std;

void input(int a[], int n){
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

bool ArrayEquality(int a[], int n, int b[], int m){
    if (n != m){
        return false;
    }else{
        for (int i = 0; i < n; i++){
            if (a[i] != b[i]){
                return false;
                break;
            }
        }
        return true;
    }
}


int main(int argc, const char** argv) {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++){
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        input(a, n);
        input(b, m);

        cout << ArrayEquality(a, n, b, m) << endl;
    }
    return 0;
}