#include<iostream>
#include<iomanip>


using namespace std; 

struct SinhVien {

    string HovaTen;
    float diem[10];
    float dt, dl, dh, dv, dgdcd, dd, ds, db, da, dc; 
    float dtb;
}

int main() {
    int i;
    SinhVien sv[50];

    string tenmh[10];
    cin.ignore();

    for (i = 0; i < N; i++)
    {
       cout << "Nhap ho va ten sinh vien: ";
       cin.ignore(1);
       getline(cin, sv[i].HovaTen);
       fflush(stdin);
       cout << "Nhap ten mon hoc: "
       getline(cin, sv[i].tenmh);
       cout << "Nhap diem trung binh mon Toan: "
       getline(cin, sv[i].dt);
       cout << "Nhap diem trung binh mon Văn: "
       getline(cin, sv[i].dv);
       cout << "Nhap diem trung binh mon Anh: "
       getline(cin, sv[i].da);
       cout << "Nhap diem trung binh mon Ly: "
       getline(cin, sv[i].dl);
       cout << "Nhap diem trung binh mon Hoa: "
       getline(cin, sv[i].dh);
       cout << "Nhap diem trung binh mon Sinh: "
       getline(cin, sv[i].db);
       cout << "Nhap diem trung binh mon Su: "
       getline(cin, sv[i].ds);
       cout << "Nhap diem trung binh mon Dia: "
       getline(cin, sv[i].dd);
       cout << "Nhap diem trung binh mon GDCD: "
       getline(cin, sv[i].dgdcd);
       cout << "Nhap diem trung binh mon Tin: "
       getline(cin, sv[i].dc);
    }

    void tinhDTB(sv) {
        sv.dtb[i] = (sv[i].dt + sv[i].dv + sv[i].da + sv[i].dl + sv[i].dh + sv[i].db + sv[i].ds + sv[i].dd + sv[i].dgdcd + sv[i].dc)/10 
    }
    

   
}