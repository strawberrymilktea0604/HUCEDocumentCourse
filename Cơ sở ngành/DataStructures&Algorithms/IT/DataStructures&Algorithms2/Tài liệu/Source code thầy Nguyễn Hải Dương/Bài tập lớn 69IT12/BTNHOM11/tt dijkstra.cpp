#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 100001;
int n, m, s = -1, t = -1;
vector<pair<int, int>> adj[maxn];//danh sach ke
const int INF = 1e9;
int pre[maxn];

void nhap(){
    cout << "Nhap so luong dinh: ";
    cin >> n;
    cout << "Nhap so luong canh: ";
    cin >> m;
    cout << "Nhap canh va trong so (u v w):\n";
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        if(x < 1 || x > n || y < 1 || y > n){
            cout << "Canh khong hop le, bo qua!\n";
            continue;
        }
        adj[x].push_back({y, w});
        //adj[y].push_back({x, w});
    }
}

void dijkstra(int s, int t){
    //mang luu khoang cach duog di
    vector<ll> d(n + 1, INF);
    d[s] = 0;
    pre[s] = s;
    //hang doi uu tien
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;//Q luc nay se luu (khoang cach va dinh)
    Q.push({0, s});
    while(!Q.empty()){
        auto [kc, u] = Q.top();
        Q.pop();
        if(kc > d[u]) continue;
        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                Q.push({d[v], v});
                pre[v] = u;//truoc v la u
            }
        }
    }
    if(d[t] == INF){
        cout << "Khong co duong di tu " << s << " den " << t << "!\n";
        return;
    }
    cout << "Do dai duong di ngan nhat = " << d[t] << endl;
    vector<int> path;
    while(true){
        path.push_back(t);
        if(t == s) break;
        t = pre[t];
    }
    reverse(begin(path), end(path));
    cout << "Duong di: ";
    for(int x : path) cout << x << ' ';
    cout << endl;
}

int main() {
    nhap();

    while (true) {
        cout << "\n1. Chay Dijkstra voi s, t hien tai\n";
        cout << "2. Nhap diem bat dau/ket thuc\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";

        int chon;
        cin >> chon;

        if (chon == 0) break;
        if (chon == 1) {
            if(s == -1 || t == -1){
                cout << "Ban chua nhap diem bat dau/ket thuc!\n";
            } else {
                dijkstra(s, t);
            }
        } else if (chon == 2) {
            do {
                cout << "Nhap dinh bat dau: ";
                cin >> s;
            } while(s < 1 || s > n);
            do {
                cout << "Nhap dinh muon den: ";
                cin >> t;
            } while(t < 1 || t > n);
            dijkstra(s, t);
        } else {
            cout << "Lua chon khong hop le!\n";
        }
    }


    return 0;
}
