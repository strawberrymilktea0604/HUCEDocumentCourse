#include<bits/stdc++.h>

using namespace std;

const int MAX = 1000010;
int a[MAX];
int n, M;

int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = (l + r)/2;
        if (arr[mid] == x) return mid;
        if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1; // Nếu không tìm thấy
}

int main(int argc, const char** argv) {
    cin >> n >> M;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int cnt = 0;
    sort(a, a + n);
    for (int i = 1; i <= n/2; i++){
        if (binarySearch(a, 1, n, M-a[i]) != -1) cnt += 1;
    }
    cout << cnt;
    return 0;
}