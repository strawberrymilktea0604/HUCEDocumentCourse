#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

struct NhanVien {
    string ten;
    vector<int> ngay;
    int tong() const { return accumulate(ngay.begin(), ngay.end(), 0); }
};

int main() {
    int n, m;
    cout << "So NV va so thang: "; cin >> n >> m;
    vector<NhanVien> ds(n);

    for (auto &nv : ds) {
        cout << "Ten: "; cin.ignore(); getline(cin, nv.ten);
        nv.ngay.resize(m);
        cout << "Ngay cong: ";
        for (int &x : nv.ngay) cin >> x;
    }

    // Tìm giá trị tổng lớn nhất bằng hàm có sẵn
    int maxVal = (*max_element(ds.begin(), ds.end(),
                               [](const NhanVien& a, const NhanVien& b) { return a.tong() < b.tong(); }
    )).tong();

    cout << "\nTop Nhan vien (" << maxVal << " ngay): \n";
    for (const auto &nv : ds)
        if (nv.tong() == maxVal) cout << nv.ten << endl;

        return 0;
}
