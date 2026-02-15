#include<bits/stdc++.h>

using namespace std;

const long long MAX = 100010;

struct Graph{
    long long ui;
    long long vi;
    long long wi;
};

long long n, m;
vector<Graph> listWi;

void inputData(){
    cin >> n >> m;
    listWi.resize(m+1);

    for(long long i = 0; i < m; i++){
        cin >> listWi[i].ui >> listWi[i].vi >> listWi[i].wi;
    }
}

/*datastructure disjolong long-set*/
long long r[MAX]; // rank
long long p[MAX]; // parent of node

void makeSet(long long x){
    p[x] = x;
    r[x] = 0;
}

void unionSet(long long x, long long y){
    if (r[x] > r[y]) p[y] = x;
    else{
        p[x] = y;
        if (r[x] == r[y]) r[y] += 1;
    }
}

long long findSet(long long x){
    while (p[x] != x){
        x = p[x];
    }
    return p[x];
}
/*end datastructure*/

bool cmp(Graph a, Graph b){
    return a.wi < b.wi;
}

long long SOLVE(){
    sort(listWi.begin(), listWi.end(), cmp);
    for (long long i = 1; i <= n; i++) makeSet(i);
    long long ans = 0;

    for (Graph v : listWi){
        long long pu = findSet(v.ui);
        long long pv = findSet(v.vi);
        if (pu != pv){
            ans += v.wi;
            unionSet(pu, pv);
        }
    }
    return ans;
}

int main(int argc, const char** argv) {
    inputData();
    cout << SOLVE();
    return 0;
}