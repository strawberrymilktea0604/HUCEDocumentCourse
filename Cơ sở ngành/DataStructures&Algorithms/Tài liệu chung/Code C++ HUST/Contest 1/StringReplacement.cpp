#include <bits/stdc++.h>

using namespace std;

string StrReplace(string str, char c1, char c2) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == c1){
            str[i] = c2;
        }
    }
    return str;
}
int main(int argc, const char** argv) {
    string str;
    cin >> str;
    char c1, c2;
    cin >> c1 >> c2;
    cout << StrReplace(str, c1, c2);
    return 0;
}