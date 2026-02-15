#include <bits/stdc++.h>

using namespace std;
 
int gcd(int x, int y){
    if (y == 0) return x;
    return gcd(y, x%y);
}
 
int pour(int fromCap, int toCap, int d){
    int from = fromCap;
    int to = 0;
    int step = 1;
 
    while (from != d && to != d){
        int temp = min(from, toCap - to);
        to   += temp;
        from -= temp;
        step++;

        if (from == d || to == d) break;
        if (from == 0){
            from = fromCap;
            step++;
        }
        if (to == toCap){
            to = 0;
            step++;
        }
    }
    return step;
}
 
int minSteps(int a, int b, int c){
    if (a > b) swap(a, b); // Đổi chỗ a và b
    if (c > b) return -1;
    if (c % gcd(b, a) != 0) return -1;

    return min(pour(b, a, c), pour(a, b, c)); 
}
 
int main(int argc, const char** argv) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << minSteps(a, b, c);
    return 0;
}