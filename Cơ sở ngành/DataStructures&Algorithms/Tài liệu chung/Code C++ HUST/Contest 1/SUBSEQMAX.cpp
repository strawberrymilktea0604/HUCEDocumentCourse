#include <iostream>
#define N 1000001

using namespace std;

int a[N];
int n;
int s[N];
void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

int MaxSUBSEQUENCE(){
    s[1] = a[1];
    int ans = s[1];
    for (int i = 2; i <= n; i++){
        if (s[i-1] > 0){
            s[i] = s[i-1] + a[i];
        }else{
            s[i] = a[i];
        }

        if (ans < s[i]){
            ans = s[i];
        }
    }
    return ans;
}

int main(int argc, const char** argv) {
    input();
    cout << MaxSUBSEQUENCE();
    return 0;
}