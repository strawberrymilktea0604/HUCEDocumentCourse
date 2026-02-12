#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct VatTu {
    string ten;
    double tien;
};

int main() {
    ifstream f_in("input.txt");
    ofstream f_out("Output.txt");

    if (!f_in || !f_out) return 0;

    vector<VatTu> ds;
    string tenTemp;
    double gia, sl;

    // Nhập dữ liệu và đẩy vào vector
    while (getline(f_in, tenTemp)) {
        f_in >> gia >> sl;
        f_in.ignore();
        ds.push_back({tenTemp, gia * sl});
    }

    // Tìm vị trí min (duyệt ngược hoặc dùng <= để lấy phần tử cuối)
    int idxMin = 0;
    for (int i = 0; i < ds.size(); ++i) {
        // Ghi file danh sách
        f_out << (i + 1) << "  " << ds[i].ten << "  " << ds[i].tien << endl;

        // Cập nhật min
        if (ds[i].tien <= ds[idxMin].tien) {
            idxMin = i;
        }
    }

    f_out << "Vat tu cuoi cung ton it tien nhat la " << ds[idxMin].ten << endl;

    return 0;
}
