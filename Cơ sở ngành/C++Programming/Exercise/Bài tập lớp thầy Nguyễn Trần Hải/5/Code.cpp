#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct NhanVien {
    string ten, chucVu;
    int tuoi;
};

// Hàm tiện ích để đọc 1 nhân viên từ file
bool docMotNV(ifstream &in, NhanVien &nv) {
    if (getline(in, nv.ten) && getline(in, nv.chucVu) && (in >> nv.tuoi)) {
        in.ignore(); // Bỏ qua ký tự xuống dòng sau khi nhập tuổi
        return true;
    }
    return false;
}

void nhapDuLieu() {
    ofstream file("nhanvien.txt", ios::app);
    if (!file) return;

    int n;
    cout << "So luong NV them: "; cin >> n; cin.ignore();
    while (n--) {
        NhanVien nv;
        cout << "  Ten: "; getline(cin, nv.ten);
        cout << "  Chuc vu: "; getline(cin, nv.chucVu);
        cout << "  Tuoi: "; cin >> nv.tuoi; cin.ignore();
        file << nv.ten << endl << nv.chucVu << endl << nv.tuoi << endl;
    }
    cout << "=> Da luu xong!\n";
}

void xemDuLieu() {
    ifstream file("nhanvien.txt");
    NhanVien nv;
    int i = 1;
    cout << "\n--- DANH SACH NHAN VIEN ---\n";
    while (docMotNV(file, nv)) {
        cout << i++ << ". " << nv.ten << " - " << nv.chucVu << " - " << nv.tuoi << " tuoi\n";
    }
    file.close();
}

void timKiem() {
    ifstream file("nhanvien.txt");
    string tenTim;
    cout << "Nhap ten can tim: "; cin.ignore(); getline(cin, tenTim);

    NhanVien nv;
    bool found = false;
    while (docMotNV(file, nv)) {
        if (nv.ten == tenTim) {
            cout << "=> Tim thay: " << nv.ten << " (" << nv.chucVu << ", " << nv.tuoi << ")\n";
            found = true;
        }
    }
    if (!found) cout << "Khong tim thay nhan vien nay!\n";
}

void xoaNhanVien() {
    // Bước 1: Đọc toàn bộ file vào RAM
    vector<NhanVien> ds;
    ifstream fileIn("nhanvien.txt");
    NhanVien nv;
    while (docMotNV(fileIn, nv)) ds.push_back(nv);
    fileIn.close();

    // Bước 2: Nhập tên xóa
    string tenXoa;
    cout << "Nhap ten can xoa: "; cin.ignore(); getline(cin, tenXoa);

    // Bước 3: Ghi lại file (trừ người bị xóa)
    ofstream fileOut("nhanvien.txt"); // Mở chế độ ghi đè (truncate)
    bool daXoa = false;
    for (const auto &item : ds) {
        // Chỉ xóa người đầu tiên tìm thấy trùng tên
        if (item.ten == tenXoa && !daXoa) {
            daXoa = true;
            continue;
        }
        fileOut << item.ten << endl << item.chucVu << endl << item.tuoi << endl;
    }

    if (daXoa) cout << "=> Da xoa thanh cong!\n";
    else cout << "=> Khong tim thay ten de xoa.\n";
}

void xoaTatCa() {
    ofstream("nhanvien.txt"); // Mở file mà không làm gì -> xóa trắng nội dung
    cout << "=> Da xoa sach du lieu!\n";
}

int main() {
    int chon;
    do {
        cout << "\n1.Nhap  2.Xem  3.Tim  4.Xoa 1 NV  5.Xoa Het  0.Thoat\nChon: ";
        cin >> chon;
        switch (chon) {
            case 1: nhapDuLieu(); break;
            case 2: xemDuLieu(); break;
            case 3: timKiem(); break;
            case 4: xoaNhanVien(); break;
            case 5: xoaTatCa(); break;
            case 0: return 0;
            default: cout << "Sai lenh!\n";
        }
    } while (true);
}
