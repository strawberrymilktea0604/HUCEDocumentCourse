#include<bits/stdc++.h>

using namespace std;

// Tìm kiếm nhị phân
int binarySearch(int a[], int L, int R, int x) {
	if(L <= R) {
		int mid = (L + R)/2;
		if(a[mid] == x )
			return 1 + binarySearch(a, L, mid - 1, x) + binarySearch(a, mid + 1, R, x);
		if(a[mid] > x) 
            return binarySearch(a, L, mid - 1, x);
		if(a[mid] < x) 
            return binarySearch(a, mid + 1, R, x);
		
	}
	else return 0;

}

int Triple(int a[], int n, int K) {
	int ans = 0;
	for(int i = 0; i < n - 2; i++) {
		int sum = K - a[i];
		for(int j = i + 1; j < n - 1; j++) {
			int x = sum - a[j];
			if(binarySearch(a, j + 1, n - 1, x) != 0) 
				ans = ans + binarySearch(a, j + 1, n - 1, x);			
		}
	}
	
    return ans;
}
 
int main(int argc, const char** argv) {
	int n, K;
	cin >> n >> K;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a + n);

	cout << Triple(a, n, K);
	return 0;
}