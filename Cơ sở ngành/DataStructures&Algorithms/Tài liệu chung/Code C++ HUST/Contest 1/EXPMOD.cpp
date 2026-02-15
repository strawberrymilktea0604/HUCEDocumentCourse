/* // Cách 1
#include<bits/stdc++.h>

using namespace std;

unsigned long long power(unsigned long long x, unsigned long long y, int p){
    unsigned long long res = 1; 
    x = x % p;
 
    while (y > 0) {
        if (y & 1){
            res = (res * x) % p;
        }
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

int main(int argc, const char** argv) {
    const int MOD = 1e9 + 7;
    unsigned long long a;
    string b;
    cin >> a >> b;
    unsigned long long remainderB = 0;

    // Sử dụng định lý Fermat nhỏ
    for (int i = 0; i < b.length(); i++){
        remainderB = (remainderB * 10 + b[i] - '0') % (MOD - 1);
    }
    cout << power(a, remainderB, MOD);
    return 0;
}
*/

// Cách 2
#include<bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;

unsigned long long sqr(unsigned long long x) {
    return x*x;
}
 
unsigned long long power(unsigned long long a, unsigned long long b) {
    if (b == 0) return 1 % MOD;
    else
        if (b % 2 == 0)
            return sqr(power(a, b/2)) % MOD;
        else    
            return a * (sqr(power(a, b/2)) % MOD) % MOD;
}
 
int main(int argc, const char** argv) {
    unsigned long long a, b;
    cin >> a >> b;
    a %= MOD;
    b %= MOD-1;
    cout << power(a, b);
    return 0;
}
