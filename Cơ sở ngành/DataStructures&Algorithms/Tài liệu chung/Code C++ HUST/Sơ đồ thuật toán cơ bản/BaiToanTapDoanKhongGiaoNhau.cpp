#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int> > s;
int n;

void inputData(){
    cin >> n;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        s.push_back(make_pair(a, b));
    }
}

bool comp(pair<int, int> x, pair<int, int> y){
    return x.second < y.second;
}

int solve(){
    sort(s.begin(), s.end(), comp);
    int result = 0;
    int last = -1e9; // Tọa độ b của đoạn cuối cùng được lựa chọn
    for (int i = 0; i < n; i++){
        if (s[i].first > last){
            result++;
            last = s[i].second;
        }
    }
    return result;
}

int main(int argc, const char** argv) {
    inputData();
    cout << solve();
    return 0;
}