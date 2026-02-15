#include <bits/stdc++.h>

using namespace std;

int calculate(string s) {
    int res = 0;
    for (int i = 0; i < s.length(); ++i) {
        int temp = s[i];
        if (temp == ' ')
            res += 1;
        else if (temp < 's')
            res += (temp + 2) % 3 + 1;
        else if (temp == 's')
            res += 4;
        else if (temp < 'z')
            res += (temp + 1) % 3 + 1;
        else 
            res += 4;
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(32767, '\n');
    cout << "T = " << T << endl;
    for (int i = 1; i <= T; i++) {
        string str;
        getline(cin, str);
        cout << calculate(str) << endl;
    }
    return 0;
}