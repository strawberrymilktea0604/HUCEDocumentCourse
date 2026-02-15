#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <climits>
using namespace std;

const int maxn = 1001;

struct canh{
    int x, y, ts;
};

int n, m;
vector<pair<int,int>> A[maxn];
bool used[maxn];

void nhap(){
    cout << "Nhap so dinh va cach:" << endl;
    cin >> n >> m;
    cout << "Nhap vao dinh, dinh ke va trong so: " << endl;
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        A[x].push_back({y, w});
        A[y].push_back({x, w});
    }
    memset(used, false, sizeof(used));
}

void prim(int u){
    vector<canh> MST;
    int d = 0;
    used[u] = true;
    while(MST.size() < n-1){
        int X, Y;
        int w_min = INT_MAX;
        for(int i = 1; i <= n; i++){
            if(used[i] == true){
                for(pair<int,int> it : A[i]){
                    int j = it.first; int trongso = it.second;
                    if(used[j] == false && trongso < w_min){
                        w_min = trongso;
                        X = j; Y = i;
                    }
                }
            }
        }
        MST.push_back({X, Y, w_min});
        used[X] = true;
        d = d + w_min;
    }
    cout << "Duong di ngan nhat la: " << endl << d << endl;
    cout << "Cac canh la: " << endl;
    for(canh e : MST) cout << e.y << " " << e.x <<" "<< e.ts <<endl;
}

int main()
{
    nhap();
    prim(1);


    return 0;
}
