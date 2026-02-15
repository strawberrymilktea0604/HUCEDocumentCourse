#include <bits/stdc++.h>
using namespace std;

// Khai báo cấu trúc cạnh và biến toàn cục
struct canh{
    int x, y, w;
};

const int maxn = 1001;
int sz[maxn], parent[maxn], n, m;
vector<canh> dscanh;


// Hàm tìm đại diện (root) của tập hợp chứa đỉnh u (với Path Compression)
int find(int u){
    if(u == parent[u]) return u;
    else return parent[u] = find(parent[u]);
}


// Hàm hợp nhất (union) hai tập hợp chứa u và v (với Union by Size)
bool Union(int u, int v){
    u = find(u);
    v = find(v);
   
    if(u == v) return false; // cùng tập hợp -> tạo chu trình
   
    // Union by Size: Gộp tập hợp nhỏ hơn vào tập hợp lớn hơn
    if(sz[u] < sz[v]) swap(u, v);
   
    sz[u] += sz[v];
    parent[v] = u;
    return true;
}


// Hàm nhập dữ liệu và khởi tạo DSU 
void nhap(){
    cout << " nhap so n so dinh va m so canh : ";
    cin >> n >> m;
    // Đọc m cạnh và lưu vào dscanh
    for(int i = 1; i <= m; i++){
        int x, y, w; cin >> x >> y >> w;
        dscanh.push_back({x, y, w});
    }
    // Khởi tạo DSU
    for(int i = 1; i <= n; i++){
        sz[i] = 1;
        parent[i] = i;
    }
}


// Hàm thuật toán Kruskal
void kruskal(){
    // sort danh sach canh theo trong so tang dan
    sort(begin(dscanh), end(dscanh), [](canh a, canh b)->bool{
        return a.w < b.w;
    });
   
    int ans = 0; // tổng trọng số của cây khung nhỏ nhất
    vector<canh> tree; // tập hợp các cạnh thuộc cây khung
   
    for(int i = 0; i < m; i++){
        // Dừng lại khi đã có n-1 cạnh trong cây khung
        if(tree.size() == n - 1) break;
       
        // Cạnh hiện tại
        canh current_edge = dscanh[i];
       
        // Kiểm tra và hợp nhất (nếu không tạo chu trình)
        if(Union(current_edge.x, current_edge.y)){
            tree.push_back(current_edge);
            ans += current_edge.w;
        }
    }
   
    // In kết quả
    if(tree.size() < n - 1){
        cout << "Do thi khong lien thong !\n";
    }
    else{
        cout << "Do dai cay bao trum la : " << ans << endl;
        cout << "Cac canh cua cay bao trum la : "<< endl;
        for(auto it : tree){
            cout <<"Dinh "<< it.x << " voi dinh " << it.y << " co trong so la " << it.w << endl;
        }
    }
}




int main(){
    
    nhap();
    kruskal();
   
    return 0;
}
