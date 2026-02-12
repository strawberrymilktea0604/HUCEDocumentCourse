#include <iostream>
#include <vector>

using namespace std;

// Dùng const tham chiếu để tránh copy dữ liệu, tăng tốc độ
void nhapMaTran(vector<vector<int>> &N, int f, int w) {
    cout << "Nhap gia tri cho ma tran:\n";
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> N[i][j];
        }
    }
}

void xuatVectorB(const vector<vector<int>> &N, int f, int w) {
    vector<int> B(w, 0); // Tự động gán bằng 0

    // TỐI ƯU QUAN TRỌNG:
    // Duyệt theo dòng (i) trước, cột (j) sau.
    // Điều này tận dụng việc dữ liệu mảng C++ nằm liền kề nhau trong bộ nhớ.
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < w; ++j) {
            B[j] += N[i][j];
        }
    }

    cout << "Vecto B (tong moi cot): ";
    for (int x : B) { // Range-based for loop (C++11)
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int f, w;
    cout << "Nhap so hang f: ";
    cin >> f;
    cout << "Nhap so cot w: ";
    cin >> w;

    // Cấp phát động vector 2 chiều f hàng, w cột
    vector<vector<int>> N(f, vector<int>(w));

    nhapMaTran(N, f, w);
    xuatVectorB(N, f, w);

    return 0;
}
