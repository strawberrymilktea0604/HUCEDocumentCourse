#include<bits/stdc++.h>

using namespace std;

int n;
int x[16];
void Print(){
    for (int i = 1; i <= n; i++){
        cout << x[i];
    }
    cout << endl;
}

void TRY(int k){
  for(int v = 0; v <= 1; v++){
    if(x[k-1] + v < 2){
      x[k] = v;
      if(k == n) Print();
      else TRY(k+1);	
    }
  }
}

int main(int argc, const char** argv) {
    cin >> n;
    x[0] = 0;
    TRY(1);
    return 0;
}