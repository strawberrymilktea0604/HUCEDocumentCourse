#include<bits/stdc++.h>

using namespace std;

const int N = 30;
const int INF = 1e9;

int n, m;
int c[N][N];
int x[N];
bool mark[N];
int f = 0; // Độ dài hành trình đã đi được
int f_min = INF; // Độ dài hành trình ngắn nhất tìm thấy
int c_min = INF; // Độ dài nhỏ nhất giữa 2 thành phố

void inputData(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            c[i][j] = INF;
        }
    }
    
    for (int k = 1; k <= m; k++){
        int i, j, d;
        cin >> i >> j >> d;
        // Đi từ i đến j có độ dài = d
        c[i][j] = d;
        if (c[i][j] < c_min) c_min = c[i][j];
    }
}

void updateBest(){ // Cập nhật đường đi ngắn nhất
    if (f + c[x[n]][x[1]] < f_min){
        f_min = f + c[x[n]][x[1]];
    }
}

void TRY(int k){
    // Thử các giá trị cho x[k]
    for (int v = 1; v <= n; v++){
        if (!mark[v]){ // Nếu chưa thăm thành phố v
            x[k] = v;
            f = f + c[x[k-1]][x[k]];
            mark[v] = true;
            
            if (k == n) updateBest();
            else{
                int gk = f + c_min*(n - k + 1);
                if (gk < f_min){
                    // Cận -> Loại bỏ nhánh duyệt thừa
                    TRY(k+1);
                }
            }

            f = f - c[x[k-1]][x[k]];
            mark[v] = false;
        }
    }
}

int main(int argc, const char** argv) {
    inputData();
    for (int v = 1; v <= n; v++){
        mark[v] = false;
    }
    x[1] = 1; // Thành phố xuất phát
    mark[1] = true; // Đã thăm
    TRY(2);
    cout << f_min;

    return 0;
}