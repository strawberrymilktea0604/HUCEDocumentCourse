#include "header.h"

void menu() {
    system("cls");
    cout << setw(103) << "**************************************************" << endl;
    cout << setw(103) << "****   Chuong trinh quan ly diem sinh vien    ****" << endl;
    cout << setw(103) << "**************************************************" << endl;
    cout << setw(103) << "****      1.Nhap thong tin sinh vien          ****" << endl;
    cout << setw(103) << "****      2.Xem danh sach sinh vien           ****" << endl;
    cout << setw(103) << "****      3.Sua thong tin sinh vien           ****" << endl;
    cout << setw(103) << "****      4.Tim kiem thong tin sinh vien      ****" << endl;
    cout << setw(103) << "****      5.Xoa thong tin sinh vien           ****" << endl;
    cout << setw(103) << "****      6.Thong ke danh sach sinh vien      ****" << endl;
    cout << setw(103) << "****      7.Doc file thong tin sinh vien      ****" << endl;
    cout << setw(103) << "****      8.Luu thong tin sinh vien vao file  ****" << endl;
    cout << setw(103) << "****      0.Thoat chuong trinh                ****" << endl;
    cout << setw(103) << "**************************************************" << endl;
    cout << setw(103) << "**************************************************" << endl;
    cout << "\nVui long nhap lua chon cua ban: " << endl;
}

void nhapSinhVien(int &soSinhVien, SinhVien sinhvien[]) {
    int i = soSinhVien;
    cout << "Nhap so luong sinh vien: ";
    int soLuong = kiemTraSoLuong();
    while (soLuong > 0) {
        cout << "Nhap ten sinh vien thu " << (i + 1) << ": ";
        sinhvien[i].ten = kiemTraTen(); 
        cout << "Nhap ma sinh vien gom 7 chu so (0.......): ";
        sinhvien[i].maSinhVien = kiemTraMaSinhVien(soSinhVien, sinhvien);
        cout << "Nhap ten lop cua sinh vien: ";
        cin.ignore();
        getline(cin, sinhvien[i].lop);
        sinhvien[i].lop = xoaKhoangTrang(sinhvien[i].lop);
        cout << "Nhap so luong mon hoc: ";
        sinhvien[i].soMonHoc = kiemTraSoLuong();
        nhapMonHoc(i, sinhvien);
        cout << endl;
        i++;
        soSinhVien++;
        soLuong--;
    }
    cout << "Nhap du lieu thanh cong!" << endl;
}

void nhapMonHoc(int viTriSV, SinhVien sinhvien[]) {
    for (int i = 0; i < sinhvien[viTriSV].soMonHoc; i++) {
        cout << "Nhap ten mon hoc thu " << (i + 1) << ": ";
        sinhvien[viTriSV].monhoc[i].ten = kiemTraTenMonHoc();
        cout << "Nhap so tin chi: ";
        sinhvien[viTriSV].monhoc[i].tinChi = kiemTraSoLuong();
        nhapDiem(viTriSV, i, sinhvien);
    }
}

void nhapDiem(int viTriSV, int viTriMH, SinhVien sinhvien[]) {
    cout << "Nhap diem thuong xuyen 1: " << endl;
    sinhvien[viTriSV].monhoc[viTriMH].diemTX1 = kiemTraDiem();
    cout << "Nhap diem thuong xuyen 2: " << endl;
    sinhvien[viTriSV].monhoc[viTriMH].diemTX2 = kiemTraDiem();
    cout << "Nhap diem ket thuc mon: " << endl;
    sinhvien[viTriSV].monhoc[viTriMH].diemKT = kiemTraDiem();
    tinhDiem(viTriSV, viTriMH, sinhvien);
    quyDoiDiem(viTriSV, viTriMH, sinhvien);
    tinhGPA(viTriSV, sinhvien);
}

void tinhDiem(int viTriSV, int viTriMH, SinhVien sinhvien[]) {
    // Điểm tổng kết = điểm quá trình / 4 + điểm kết thúc / 2.
    sinhvien[viTriSV].monhoc[viTriMH].diemTK = (sinhvien[viTriSV].monhoc[viTriMH].diemTX1 + sinhvien[viTriSV].monhoc[viTriMH].diemTX2) / 4.0 + sinhvien[viTriSV].monhoc[viTriMH].diemKT / 2.0;
}

void quyDoiDiem(int viTriSV, int viTriMH, SinhVien sinhvien[]) {
    if (sinhvien[viTriSV].monhoc[viTriMH].diemTK >= 8.5 && sinhvien[viTriSV].monhoc[viTriMH].diemTK <= 10) {
        sinhvien[viTriSV].monhoc[viTriMH].diemHe4 = 4.0;
        sinhvien[viTriSV].monhoc[viTriMH].diemChu = 'A';
    }
    else if (sinhvien[viTriSV].monhoc[viTriMH].diemTK >= 8.0 && sinhvien[viTriSV].monhoc[viTriMH].diemTK <= 8.4) {
        sinhvien[viTriSV].monhoc[viTriMH].diemHe4 = 3.5;
        sinhvien[viTriSV].monhoc[viTriMH].diemChu = "B+";
    }
    else if (sinhvien[viTriSV].monhoc[viTriMH].diemTK >= 7.0 && sinhvien[viTriSV].monhoc[viTriMH].diemTK <= 7.9) {
        sinhvien[viTriSV].monhoc[viTriMH].diemHe4 = 3.0;
        sinhvien[viTriSV].monhoc[viTriMH].diemChu = "B";
    }
    else if (sinhvien[viTriSV].monhoc[viTriMH].diemTK >= 6.5 && sinhvien[viTriSV].monhoc[viTriMH].diemTK <= 6.9) {
        sinhvien[viTriSV].monhoc[viTriMH].diemHe4 = 2.5;
        sinhvien[viTriSV].monhoc[viTriMH].diemChu = "C+";
    }
    else if (sinhvien[viTriSV].monhoc[viTriMH].diemTK >= 5.5 && sinhvien[viTriSV].monhoc[viTriMH].diemTK <= 6.4) {
        sinhvien[viTriSV].monhoc[viTriMH].diemHe4 = 2.0;
        sinhvien[viTriSV].monhoc[viTriMH].diemChu = "C";
    }
    else if (sinhvien[viTriSV].monhoc[viTriMH].diemTK >= 5.0 && sinhvien[viTriSV].monhoc[viTriMH].diemTK <= 5.4) {
        sinhvien[viTriSV].monhoc[viTriMH].diemHe4 = 1.5;
        sinhvien[viTriSV].monhoc[viTriMH].diemChu = "D+";
    }
    else if (sinhvien[viTriSV].monhoc[viTriMH].diemTK >= 4.0 && sinhvien[viTriSV].monhoc[viTriMH].diemTK <= 4.9) {
        sinhvien[viTriSV].monhoc[viTriMH].diemHe4 = 1.0;
        sinhvien[viTriSV].monhoc[viTriMH].diemChu = "D";
    }
    else {
        sinhvien[viTriSV].monhoc[viTriMH].diemHe4 = 0;
        sinhvien[viTriSV].monhoc[viTriMH].diemChu = "F";
    }
}

void tinhGPA(int viTriSV, SinhVien sinhvien[]) {
    float tongDiem = 0.0;
    int tongTinChi = 0;
    for (int i = 0; i < sinhvien[viTriSV].soMonHoc; i++) {
        tongTinChi += sinhvien[viTriSV].monhoc[i].tinChi;
        tongDiem += sinhvien[viTriSV].monhoc[i].diemHe4 * sinhvien[viTriSV].monhoc[i].tinChi;
    }
    sinhvien[viTriSV].GPA = tongDiem / tongTinChi;
}

void xemDanhSach(int soSinhVien, SinhVien sinhvien[]) {
    if (sinhvien[0].ten.empty() && sinhvien[0].maSinhVien.empty() && sinhvien[0].lop.empty()) {
        cout << "Danh sach trong!" << endl;
    }
    else {
        for (int i = 0; i < soSinhVien; i++) {
            xemSinhVien(i, sinhvien);
        }
    }
}

void suaThongTin(int soSinhVien, SinhVien sinhvien[]) {
    cout << "Nhap ma sinh vien can sua thong tin: ";
    int viTriSV = timKiem(soSinhVien, sinhvien);
    if (viTriSV == -1) {
        cout << "Khong tim thay thong tin sinh vien co ma sinh vien nay!" << endl;
    }
    else {
        cout << "Nhap ten sinh vien moi: ";
        sinhvien[viTriSV].ten = kiemTraTen();
        cout << "Nhap lop cua sinh vien: ";
        
        cin >> sinhvien[viTriSV].lop;
        sinhvien[viTriSV].lop = xoaKhoangTrang(sinhvien[viTriSV].lop);
        cin.ignore();
        cout << "Nhap so luong mon hoc: ";
        sinhvien[viTriSV].soMonHoc = kiemTraSoLuong();
        nhapMonHoc(viTriSV, sinhvien);
        cout << "Sua thong tin thanh cong!" << endl;
    }
}

void xemSinhVien(int viTriSV, SinhVien sinhvien[]) {
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\tMa sinh vien: " << sinhvien[viTriSV].maSinhVien << endl;
    cout << "\tHo ten: " << sinhvien[viTriSV].ten << endl;
    cout << "\tLop: " << sinhvien[viTriSV].lop << endl;
    for (int i = 0; i < sinhvien[viTriSV].soMonHoc; i++) {
        cout << "\n\tDiem mon " << sinhvien[viTriSV].monhoc[i].ten << endl;
        cout << "\tDiem thuong xuyen 1: " << sinhvien[viTriSV].monhoc[i].diemTX1 << endl;
        cout << "\tDiem thuong xuyen 2: " << sinhvien[viTriSV].monhoc[i].diemTX2 << endl;
        cout << "\tDiem thi ket thuc mon: " << sinhvien[viTriSV].monhoc[i].diemKT << endl;
        cout << "\tDiem tong ket: " << setprecision(2) << sinhvien[viTriSV].monhoc[i].diemTK << endl;
        cout << "\tDiem he 4: " << sinhvien[viTriSV].monhoc[i].diemHe4 << endl;
        cout << "\tDiem chu: " << sinhvien[viTriSV].monhoc[i].diemChu << endl;
    }
    cout << "\tGPA: " << setprecision(2) << sinhvien[viTriSV].GPA << endl;
}

int timKiem(int soSinhVien, SinhVien sinhvien[]) {
    string maSV;
    int viTriSV = -1;
    cin >> maSV;
    cin.ignore();
    for (int i = 0; i < soSinhVien; i++) {
        if (maSV == sinhvien[i].maSinhVien) {
            viTriSV = i;
            break;
        }
    }
    return viTriSV;
}

void xemTimKiem(int soSinhVien, SinhVien sinhvien[]) {
    cout << "Nhap ma sinh vien can tim thong tin: ";
    int viTriSV = timKiem(soSinhVien, sinhvien);
    if (viTriSV == -1) {
        cout << "Khong tim thay thong tin sinh vien co ma sinh vien nay!" << endl;
    }
    else {
        xemSinhVien(viTriSV, sinhvien);
    }
}

void xoaSinhVien(int& soSinhVien, SinhVien sinhvien[]) {
    cout << "Nhap ma sinh vien can xoa thong tin: ";
    int viTriSV = timKiem(soSinhVien, sinhvien);
    if (viTriSV == -1) {
        cout << "Khong tim thay thong tin sinh vien co ma sinh vien nay!" << endl;
    }
    else {
        for (int i = viTriSV; i < soSinhVien - 1; i++) {
            sinhvien[i] = sinhvien[i + 1];
        }
        soSinhVien--;
        cout << "Xoa thong tin sinh vien thanh cong!" << endl;
    }
}

void docFile(int &soSinhVien, SinhVien sinhvien[]) {
    ifstream fileIn;
    fileIn.open("D:\\Workspaces\\C++\\BTL\\data.txt", ios::in);
    if (fileIn.fail()) {
        cout << "Loi mo tep.";
        return;
    }
    int i = soSinhVien;
    while (!fileIn.eof()) {
        getline(fileIn, sinhvien[i].ten);
        fileIn >> sinhvien[i].maSinhVien >> sinhvien[i].lop;
        fileIn >> sinhvien[i].soMonHoc;
        for (int j = 0; j < sinhvien[i].soMonHoc; j++) {
            fileIn.ignore();
            getline(fileIn, sinhvien[i].monhoc[j].ten,'_');
            fileIn >> sinhvien[i].monhoc[j].tinChi;
            fileIn >> sinhvien[i].monhoc[j].diemTX1 >> sinhvien[i].monhoc[j].diemTX2 >> sinhvien[i].monhoc[j].diemKT >> sinhvien[i].monhoc[j].diemTK >> sinhvien[i].monhoc[j].diemHe4 >> sinhvien[i].monhoc[j].diemChu;
        }
        fileIn >> sinhvien[i].GPA;
        fileIn.ignore();
        i++;
        soSinhVien++;
    }
    cout << "Doc file thanh cong." << endl;
    fileIn.close();
}

void ghiFile(int soSinhVien, SinhVien sinhvien[]) {
    ofstream fileOut;
    fileOut.open("D:\\Workspaces\\C++\\BTL\\data.txt", ios::app);
    if (fileOut.fail()) {
        cout << "Loi mo tep.";
        return;
    }
    for (int i = 0; i < soSinhVien; i++) {
        fileOut << sinhvien[i].ten << endl;
        fileOut << sinhvien[i].maSinhVien << " " << sinhvien[i].lop << endl;
        fileOut << sinhvien[i].soMonHoc << endl;
        for (int j = 0; j < sinhvien[i].soMonHoc; j++) {
            fileOut << sinhvien[i].monhoc[j].ten << "_" << sinhvien[i].monhoc[j].tinChi << endl;
            fileOut << sinhvien[i].monhoc[j].diemTX1 << " " << sinhvien[i].monhoc[j].diemTX2 << " " << sinhvien[i].monhoc[j].diemKT << " " << setprecision(2) << sinhvien[i].monhoc[j].diemTK << " " << sinhvien[i].monhoc[j].diemHe4 << " " << sinhvien[i].monhoc[j].diemChu << endl;
        }
        fileOut << setprecision(2) << sinhvien[i].GPA << endl;
    }
    cout << "\nGhi file thanh cong" << endl;
    fileOut.close();
}
void thongKe(int soSinhVien, SinhVien sinhvien[]) {
    double soSV = double(soSinhVien);
    float sumGPA = 0; // Tổng GPA của toàn bộ sinh viên.
    double count1 = 0; // Đếm số lượng sinh viên học lực xuất sắc.
    double count2 = 0; // Đếm số lượng sinh viên học lực giỏi.
    double count3 = 0; // Đếm số lượng sinh viên học lực khá.
    double count4 = 0; // Đếm số lượng sinh viên học lực trung bình.
    double count5 = 0; // Đếm số lượng sinh viên học lực yếu.
    double count6 = 0; // Đếm số lượng sinh viên học lực kém.
    for (int i = 0; i < soSinhVien; i++) {
        sumGPA += sinhvien[i].GPA;
        if (sinhvien[i].GPA >= 3.6 && sinhvien[i].GPA <= 4.0) {
            count1++;
        }
        else if (sinhvien[i].GPA >= 3.2 && sinhvien[i].GPA < 3.6) {
            count2++;
        }
        else if (sinhvien[i].GPA >= 2.5 && sinhvien[i].GPA < 3.2) {
            count3++;
        }else if (sinhvien[i].GPA >= 2.0 && sinhvien[i].GPA < 2.5) {
            count4++;
        }else if (sinhvien[i].GPA >= 1.0 && sinhvien[i].GPA < 2.0) {
            count5++;
        }else if (sinhvien[i].GPA < 1.0) {
            count6++;
        }
    }
    double GPATB = sumGPA / soSinhVien;
    double tiLe1 = count1 / soSV * 100; // Tỉ lệ sinh viên có học lực xuất sắc.
    double tiLe2 = count2 / soSV * 100; // Tỉ lệ sinh viên có học lực giỏi
    double tiLe3 = count3 / soSV * 100; // Tỉ lệ sinh viên có học lực khá.
    double tiLe4 = count4 / soSV * 100; // Tỉ lệ sinh viên có học lực trung bình.
    double tiLe5 = count5 / soSV * 100; // Tỉ lệ sinh viên có học lực yếu.
    double tiLe6 = count6 / soSV * 100; // Tỉ lệ sinh viên có học lực kém.
    cout << "Co " << soSinhVien << " trong danh sach." << endl;
    cout << "GPA trung binh cua danh sach: " << setprecision(2)<< GPATB << endl;
    cout << "Ti le sinh vien co hoc luc xuat sac: " << setprecision(3) << tiLe1 << "%" << endl;
    cout << "Ti le sinh vien co hoc luc gioi: " << setprecision(3) << tiLe2 << "%" << endl;
    cout << "Ti le sinh vien co hoc luc kha: " << setprecision(3) << tiLe3 << "%" << endl;
    cout << "Ti le sinh vien co hoc luc trung binh: " << setprecision(3) << tiLe4 << "%" << endl;
    cout << "Ti le sinh vien co hoc luc yeu: " << setprecision(3) << tiLe5 << "%" << endl;
    cout << "Ti le sinh vien co hoc luc kem: " << setprecision(3) << tiLe6 << "%" << endl;

}

int kiemTraKyTu(string str) {
    bool check1 = false; // Biến check1 lưu trữ giá trị kiểm tra sô trong chuỗi str.
    bool check2 = false; // Biến check1 lưu trữ giá trị kiểm tra ký tự đặc biệt trong chuỗi str.
    for (char c : str) {
        if (isdigit(c)) {
            check1 = true;
        }
        else if (!isalpha(c) && !isspace(c)) {
            check2 = true;
        }
    }
    if (check1 && check2) {
        return 2;
    }
    else if (check1) {
        return 0;
    }
    else if (check2) {
        return -1;
    }
    return 1;
}

string xoaKhoangTrang(string &str) {
    while (str[0] == ' ') {
        str.erase(0,1);
    }
    while (str[str.length() - 1] == ' ') {
        str.pop_back();
    }
    int i = 0;
    while (i < str.length()) {
        if (str[i] == ' ' && str[i+1] == ' ') {
            str.erase(i, 1);
        }
        else {
            i++;
        }
    }
    return str;
}

string inHoa(string &str) {
    str = xoaKhoangTrang(str);
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z' && str[i] != ' ') {
            str[i] += 32;
        }
    }
    str[0] -=32;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ' && str[i + 1] != ' ' && !isdigit(str[i + 1])) {
            str[i + 1] -= 32;
        }
    }
    return str;
}

string kiemTraTen() {
    string str;
    while (true) {
        getline(cin, str);
        if (kiemTraKyTu(str) == 0) {
            cout << "Ten khong duoc chua ky tu so! Vui long nhap lai: ";
        }
        else if (kiemTraKyTu(str) == -1) {
            cout << "Ten khong duoc chua ky dac biet! Vui long nhap lai: ";
        }
        else if (kiemTraKyTu(str) == 2) {
            cout << "Ten khong duoc chua ky so va ky tu dac biet! Vui long nhap lai: ";
        } 
        else {
            str = inHoa(str);
            return str;
        }
    }
}

string kiemTraTenMonHoc() {
    string str;
    while (true) {
        getline(cin, str);
        if (kiemTraKyTu(str) == -1) {
            cout << "Ten mon hoc khong duoc chua ky tu dac biet! Vui long nhap lai: ";
        }
        else {
            return inHoa(str);
        }
    }
}

int kiemTraSo() {
    while (true) {
        bool check = 1;
        int max = 2000000; // Chương trình nhận đầu vào là số nguyên tối đa bằng 2 triệu;
        string str;
        getline(cin, str);
        str = xoaKhoangTrang(str);
        for (int i = 0; i < str.length(); i++) {
            if (!isdigit(str[i])) {
                check = 0;
                break;
            }
        }
        if (check == 1) {
            if (stoi(str) > max) {
                 cout << "Gia tri qua lon! Vui long nhap lai:" << endl;
            }
            else if (stoi(str) < 0) {
                cout << "Nhap gia tri sai! Vui long nhap lai:" << endl;
            }
            else {
                return stoi(str);
            }           
        }
        else {
            cout << "Nhap gia tri sai! Vui long nhap lai: " << endl;
        }
        
    }
}

int kiemTraSoLuong() {
    int temp;
    while (true) {
        temp = kiemTraSo();
        if (temp == 0) {
            cout << "So luong phai lon hon 0! Vui long nhap lai: ";
        }
        else {
            return temp;
        }
    }
    
}

string kiemTraMaSinhVien(int soSinhVien, SinhVien sinhvien[]) {
    regex rg("^[0]([0-9]){6}");
    string str;
    bool check = false;
    while (true) {
        cin >> str;
        if (regex_match(str, rg)) {
            check = true;
            if (soSinhVien == 0) {
                return str;
            }
            else {
                for (int i = 0; i < soSinhVien; i++) {
                    if (str == sinhvien[i].maSinhVien) {
                        cout << "Ma sinh vien da ton tai! Vui long nhap lai: ";
                        check = false;
                        break;
                    }
                }
            }
        }
        else cout << "Ma sinh vien khong dung dinh dang! Vui long nhap lai: ";
        if (check == true) {
            return str;
        }
    }
}


double kiemTraDiem() {
    while (true) {
        bool check = 1;
        string str;
        getline(cin, str);
        str = xoaKhoangTrang(str);
        for (int i = 0; i < str.length(); i++) {
            if (isdigit(str[i]) || str[i] == '.') {
                continue;
            }
            else {
                check = 0;
                break;
            }
        }
        if (check == 1) {
            if (stod(str) < 0 || stod(str) > 10) {
                check = 0;
            }     
            else {
                return stod(str);
            }     
        }
        else {
            cout << "Nhap gia tri sai! Vui long nhap lai: " << endl;
        }
        
    }
}