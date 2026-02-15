#include<bits/stdc++.h>

using namespace std;

const int MAX = 100010;

int n, m;
vector<vector<int> > Graph;
int color[MAX]; // 1 : red, 2 : blue

void inputData(){
    cin >> n >> m;
    Graph.resize(n+1);

    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) color[i] = 0;
}

bool solve(){
    queue<int> q;
    q.push(1);
    color[1] = 1;

    while (!q.empty()){
        int u = q.front(); 
        q.pop();

        for (int v : Graph[u]){
            if (color[v] == 0){
                q.push(v);
                if (color[u] == 1){
                    color[v] = 2;
                }else if (color[u] == 2){
                    color[v] = 1;
                }
            }else{
                if (color[v] == color[u]) return false;
            }
        }
    }

    return true;
}

int main(int argc, const char** argv) {
    inputData();

    if (solve()) cout << "1";
    else cout << "0";

    return 0;
}