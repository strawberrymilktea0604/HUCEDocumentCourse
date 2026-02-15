/*#include<bits/stdc++.h>

using namespace std;

typedef struct TArc{
    int node; // other end-point
    int weight; // weight
    struct TArc* next;
}Arc;

const int MAX = 100010;
const int INF = 1E9;

int n, m;
Arc* A[MAX]; // A[v] is the pointer to the first node in the adjacent list of v
int s, t;
// data structure for Dijkstra Algorithm
int d[MAX], p[MAX];
bool visited[MAX]; // visited[v] = true means that the shortest path

// insert an element to the first position of a linked list head by h
Arc* insert(int _node, int _weight, Arc* h){
    Arc* p = new Arc();
    p->node = _node;
    p->weight = _weight;
    p->next = h;
    return p;
}

void inputData(){
    cin >> n >> m;
    for (int u = 1; u <= n; u++) A[u] = NULL;
    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        // add new arc to the adjacent list of u
        A[u] = insert(v, w, A[u]);
    }
    cin >> s >> t;
}

void printGraph(){
    for (int v = 1; v <= n; v++){
        cout << "A[" << v << "]: ";
        for (Arc* p = A[v]; p != NULL; p = p->next){
            cout << "(" << p->node << ", " << p->weight << ") ";
        }
        cout << endl;
    }
}

int selectMin(){
    // return the node having smallest value of d in the non-visited set
    int minD = INF;
    int sel = -1;
    for (int v = 1; v <= n; v++){
        if (!visited[v]){
            if (d[v] < minD){
                minD = d[v];
                sel = v;
            }
        }
    }
    return sel;
}

void Dijkstra(){
    // initialization
    for (int v = 1; v <= n; v++){
        d[v] = INF;
        p[v] = -1;
        visited[v] = false;
    }
    for (Arc* p = A[s]; p != NULL; p = p->next){
        int v = p->node;
        int w = p->weight;
        d[v] = w;
    }
    d[s] = 0;
    visited[s] = true;

    // loop
    while (1){
        int u = selectMin();
        if (u == -1) break;
        if (u == t) break;
        visited[u] = true; // shortest path from s to u is found, d[u] is visited
        for (Arc* p = A[u]; p != NULL; p = p->next){
            int v = p->node;
            int w = p->weight;
            if (!visited[v]){
                if (d[v] > d[u] + w){
                    d[v] = d[u] + w;
                }
            }
        }
    }

    if (d[t] == INF) cout << "-1";
    else cout << d[t];

}

int main(int argc, const char** argv) {
    inputData();
    printGraph();
    Dijkstra();
    return 0;
}
*/

#include<bits/stdc++.h>

using namespace std;

const long long MAX = 100010;

struct comp{
    bool operator() (pair<long long, long long> a, pair<long long, long long> b){
        return a.second > b.second;
    }
};

long long n, m;
vector< vector<pair<long long, long long> > > Graph;
long long s, t;

void inputData(){
    cin >> n >> m;
    Graph.resize(n+1);
    for (long long i = 0; i < m; i++){
        long long u, v, w;
        cin >> u >> v >> w;
        Graph[u].push_back({v, w});
    }

    cin >> s >> t;
}

long long DijkstraAlgorithm(){
    priority_queue<pair<long long, long long>, vector< pair<long long, long long> >, comp> q;
    long long dist[MAX];

    for (long long i = 1; i <= n; i++){
        dist[i] = 1e9;
    }
    dist[s] = 0;
    for (long long i = 1; i <= n; i++){
        q.push({i, dist[i]});
    }

    // dijkstra algorithm
    while (!q.empty()){
        pair<long long, long long> x = q.top(); 
        q.pop();
        long long x_point = x.first;

        for (auto v : Graph[x_point]){
            long long v_point = v.first;
            long long v_dist = v.second;

            if (dist[v_point] > dist[x_point] + v_dist){
                dist[v_point] = dist[x_point] + v_dist;
                q.push({v_point, dist[v_point]});
            }
        }
    }

    return dist[t];
}

int main(int argc, const char** argv) {
    inputData();
    cout << DijkstraAlgorithm();
    return 0;
}
