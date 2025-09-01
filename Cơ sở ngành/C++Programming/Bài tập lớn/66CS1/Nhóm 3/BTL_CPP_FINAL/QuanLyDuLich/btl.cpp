#include "btl.h"

void title() {
    cout << "\n\t";
    cout << left << setw(4) << "STT" << left << setw(15) << "Ten dia diem" << left << setw(10) << "Gia tien";
    for (int i=1; i<=12; i++) {
        string month = "T" + to_string(i);
        cout << left << setw(8) << month;
    }
    cout << "\n";
    cout << "\t--------------------------------------------------------------------------------------------------------------------------------\n";
}

void menu() {
    cout << "\n\t\t CHUONG TRINH QUAN LI DIA DIEM DU LICH\n";
    cout << "\t\t****************************************\n";
    cout << "\t\t** 1. Them dia diem du lich           **\n";
    cout << "\t\t** 2. Xem danh sach dia diem du lich  **\n";
    cout << "\t\t** 3. Tim kiem dia diem du lich       **\n";
    cout << "\t\t** 4. Xoa dia diem du lich            **\n";
    cout << "\t\t** 5. Thong ke                        **\n";
    cout << "\t\t** 6. Luu danh sach dia diem ra file  **\n";
    cout << "\t\t** 7. Load file da luu                **\n";
    cout << "\t\t** 0. Thoat chuong trinh.             **\n";
    cout << "\t\t****************************************\n\n";
    cout << "\t\t->Enter select: ";
}

void themDiaDiem(QLDL &diadiem, int n) {
    cin.ignore();
    cout << "Nhap ten dia diem: ";
    getline(cin, diadiem.ten);
    cout << "Nhap gia tien: ";
    cin >> diadiem.gia_tien;
    for (int i=0; i<12; i++) {
        cout << "Nhap so khach thang thu " << i+1 << ": ";
        cin >> diadiem.so_khach[i];
    }
    tinhDoanhThu(diadiem);
    cout << "\n-Ban da them dia diem thanh cong\n\n";
}

void thongTinDiaDiem(QLDL &diadiem) {
    cout << left << setw(15) << diadiem.ten << left << setw(10) << diadiem.gia_tien;
        for (int j=0; j<12; j++) {
            cout << left << setw(8) << diadiem.so_khach[j];
        }
}

void danhSachDiaDiem(QLDL arr[], int n) {
    if (n>0) {
        cout <<"\t\t\t\t\t\t\tDANH SACH QUAN LI DIA DIEM DU LICH\n";
        title();
        for (int i=0; i<n; i++) {
            cout << "\t" << left << setw(4) << i+1;
            thongTinDiaDiem(arr[i]);
            cout << "\n";
        }
        cout << "\n\t--------------------------------------------------------------------------------------------------------------------------------\n";
    } else {
        cout << "\n-Hien chua co dia diem nao.\n\n";
    }
}

string lower(string str){
    char mang[str.length()+1];
    for(int k=0;k<sizeof(mang);k++){
            //truyen string vao mang char va in thuong
        mang[k]=tolower(str[k]);//
    }

    return mang;
}

void timDiaDiem(QLDL arr[], int n) {
    string name_find;
    cout << "\n\tNhap ten dia diem can tim: ";
    cin.ignore();
    getline(cin, name_find);
    bool myboolean=true;
    if(&myboolean){
        cout << "\n\t-Ket qua tim kiem voi tu khoa \'" << name_find << "\':" << endl;
        title();
        for (int i=0; i<n; i++) {
            if (string(lower(arr[i].ten)).find(string(lower(name_find)))<=100) {
                cout << "\t" << left << setw(4) << i+1;
                thongTinDiaDiem(arr[i]);
                cout << endl;
                myboolean=false;
            }
        }
    }
    if(myboolean){
        cout<<"\n\t-Khong tim thay dia diem ban can.\n\n"<<endl;
    }
}

void tinhDoanhThu(QLDL &diadiem) {
    for (int i=0; i<12; i++) {
        diadiem.tong_so_khach += diadiem.so_khach[i];
    }
    diadiem.doanh_thu = diadiem.tong_so_khach * diadiem.gia_tien;
}

void thongKe(QLDL arr[], int n) {
    int max_dt = arr[0].doanh_thu;
    int index_max_dt = 0;
    for (int i=1; i<n; i++) {
        if (max_dt < arr[i].doanh_thu) {
            max_dt = arr[i].doanh_thu;
            index_max_dt = i;
        }
    }
    int max_khach = arr[0].tong_so_khach;
    int index_max_khach = 0;
    for (int q=0; q<n; q++) {
        if (max_khach < arr[q].tong_so_khach) {
            max_khach = arr[q].tong_so_khach;
            index_max_khach = q;
        }
    }
    cout << "\n\tCo tat ca " << n << " dia diem du lich.\n\tTrong do: \n";
    cout << "\t Dia diem co doanh thu cao nhat: " << arr[index_max_dt].ten << " (" << max_dt << " VND)\n";
    cout << "\t Dia diem dong khach nhat: " << arr[index_max_khach].ten << " (" << max_khach << " khach du lich)\n\n";
}

void xoaDiaDiem(QLDL arr[], int &n) {
    if (n == 0) {
        cout << "\n\t-Hien chua co dia diem nao.\n\n";
    } else {
        int stt;
        cout << "\n\tNhap stt dia diem ban muon xoa: "; cin >> stt;
        for (int i=stt-1; i<n-1; i++) {
            arr[i] = arr[i+1];
        }
        --n;
        cout << "\n\t-Da xoa dia diem thanh cong!\n\n";
    }
}

void luuFile(QLDL qldl[], int n, string filename) {
    ofstream out_file;
    out_file.open("output.txt");
    out_file << "\n";
    for (int i=0; i<n; i++) {
        out_file << qldl[i].ten << endl << qldl[i].gia_tien;
        for (int j=0; j<12; j++) {
            out_file << " " << qldl[i].so_khach[j];
        }
        out_file << "\n";
    }
    out_file.close();
    cout << "\n\t-Da luu vao file DATA.txt\n\n";
}


void loadFile(QLDL qldl[], int &n, string filename) {
    ifstream in_file;
    in_file.open("DATA.txt");
    if(!in_file.is_open()) {
        cout << "Khong mo duoc file!\n";
        n = 0;
        return;
    }
    int count = 0;
    while(!in_file.eof()) {
        string name;
        in_file.ignore();
        getline(in_file, name);
        if (name=="") {
            break;
        } else {
            qldl[count].ten = name;
            in_file >> qldl[count].gia_tien;
            for (int i=0; i<12; i++) {
                in_file >> qldl[count].so_khach[i];
            }
            tinhDoanhThu(qldl[count]);
            count++;
        }
    }
    in_file.close();
    cout << "\n\t-Da load du lieu thanh cong.\n\n";
    n = count;
}





