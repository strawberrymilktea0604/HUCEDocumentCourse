#include<bits/stdc++.h>

using namespace std;

const int MAX = 30;

int n;
int Bool[MAX] = {0};//Đánh dấu chưa có phần tử nào sử dụng hết
int A[MAX]; //Lưu hoán vị vào mảng A
 
void solution() {
    for (int i = 1; i <= n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}
 
void TRY(int k) {
    for (int i = 1; i <= n; i++) {
        //Kiểm tra nếu phần tử chưa được chọn thì sẽ đánh dấu
        if (!Bool[i]) {
            A[k] = i; // Lưu một phần tử vào hoán vị
            Bool[i] = 1;//Đánh dấu đã dùng

            if (k == n){ //Kiểm tra nếu đã chứa một hoán vị thì xuất
                solution();
            } else TRY(k + 1);

            Bool[i] = 0;
        }
    }
}
 
int main(int argc, const char** argv) {
    cin >> n;
    TRY(1);
    return 0;
}