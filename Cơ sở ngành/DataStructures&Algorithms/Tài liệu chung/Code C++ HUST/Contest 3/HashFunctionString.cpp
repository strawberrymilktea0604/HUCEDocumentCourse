#include<bits/stdc++.h>

using namespace std;

int n, M;

int HFS(string s){
    int m = s.length();
    int h = 0;
    for (int i = 0; i < m; i++){
        h = h*256 + s[i];
        h %= M;
    }
    return h;
}

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> M;
    string str;
    for (int i = 0; i < n; i++){
        cin >> str;
        cout << HFS(str) << endl;
    }
    return 0;
}