#include<bits/stdc++.h>

using namespace std;

const int MAX = 100010;

vector<vector<int> > Graph;
int n, m;
bool mark[MAX];

void inputData(){
    cin >> n >> m;
    Graph.resize(n+1);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
}

void DFS(int u){
    mark[u] = true;
    for (int v : Graph[u]){
        if (!mark[v]) DFS(v);
    }
}

int main(int argc, const char** argv) {
    inputData();
    memset(mark, false, sizeof(mark));
    int result = 0;
    for (int i = 1; i <= n; i++){
        if (!mark[i]){
            DFS(i);
            result++;
        }
    }
    cout << result;
    return 0;
}
