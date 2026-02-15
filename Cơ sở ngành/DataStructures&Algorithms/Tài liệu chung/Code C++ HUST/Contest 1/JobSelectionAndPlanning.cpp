#include<bits/stdc++.h>
 
using namespace std;
 
struct Job{
    int dead;
    int profit; 
};
 
bool comparison(Job a, Job b){
    return (a.profit > b.profit);
}
 
int JobScheduling(Job arr[], int n){
    sort(arr, arr + n, comparison);
 
    int result[n];
    bool slot[n];
 
    for (int i = 0; i < n; i++){
        slot[i] = false;
    }
 
    for (int i = 0; i < n; i++){
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--){
            if (slot[j] == false){
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
 
    int maxJob = 0;
    for (int i = 0; i < n; i++){
        if (slot[i]){
            maxJob += arr[i].profit;
        }
    }
    return maxJob;
}
 
int main(int argc, const char** argv) {
    int n;
    cin >> n;
    Job arr[n+1];
    for (int i = 0; i < n+1; i++){
        cin >> arr[i].dead >> arr[i].profit;
    }
 
    cout << JobScheduling(arr, n+1);
    return 0;
}