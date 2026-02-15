#include<bits/stdc++.h>

using namespace std;

int n;
int x[100]; // x[i] = v: con hậu ở trên hàng v cột i

bool check(int v, int k){
    // kiểm tra xem v có gán cho được x[k] không
    // Con hậu có thể ở trên hàng v cột k không? x[k] = v?
    for (int i = 1; i < k; i++){
        if (x[i] == v) return false;
        if (x[i] + i == v + k) return false;
        if (x[i] - i == v - k) return false;
    }
    return true;
}

void Print(){
    for (int i = 1; i <= n; i++){
        cout << x[i] << " ";
    }
    cout << endl;
    cout << "----------" << endl;
}
void TRY(int k){
    for (int v = 1; v <= n; v++){
        if (check(v, k)){
            x[k] = v;
            if (k == n) Print();
            else TRY(k+1);
        }
    }
}

int main(int argc, const char** argv) {
    cin >> n;
    TRY(1);
    return 0;
}