#include "BTL.h"

using namespace std;

struct employee
{
string name;
string ID;
string exp;
int ngaycong[12];
};

void passwordUser();
void user();
void xdelete();
void timkiem();
void checkngaycong();
bool checkID(string &checkID);
void xemToanBo();
void nhapdulieu();
void thongke();

const char thong_ke = 'T';
const char ngay_cong = 'W';
const char xoa = 'X';
const char thoat_ham = 'Q';
const char xac_nhan = 'Y';
const int so_ngay_toi_da = 26; 
const int so_ngay_toi_thieu = 0;
const int so_thang = 12;

void passwordUser()
{
    int select;

    do {
        system("cls");
        cout << "\n\t\t\t ----------------------------";
        cout << "\n\t\t\tHE THONG QUAN LI NHAN VIEN";
        cout << "\n\t\t\t ----------------------------";
        cout << "\n\t\t\t1.Thong ke nhan vien";
        cout << "\n\t\t\t2.Them nhan vien";
        cout << "\n\t\t\t3.Xoa nhan vien";
        cout << "\n\t\t\t4.Tim kiem";
        cout << "\n\t\t\t5.Xem toan bo";
        cout << "\n\t\t\t6.Thoat chuong trinh";
        cout << "\n\t\t\tNhap 1 / 2 / 3 / 4 / 5 / 6 : ";
        cin >> select;
        cin.clear();
        fflush(stdin);

        switch(select) {
            case 1:
                thongke();
                break;
            case 2:
                {
                    system("cls");
                    nhapdulieu();
                    break;
                }
            case 3:
                system("cls");
                xdelete();
                break;
            case 4:
                system("cls");
                timkiem();
                break;
            case 5:
                system("cls");
                xemToanBo();
                break;
            case 6:
                {
                    cout << "\n\t\t\t  HE THONG QUAN LI NHAN VIEN";
                    cout << "\n\t\t\t\t----Da tat----\n";
                    exit(0);
                }
            default:
                system("cls");
                break;
        }

    } while(select != 6);
}

void user()
{
    string name_c = "";
    string pass_c = "";
    string name = "";
    string pass = "";
    int count;
    int choice;
    char ch;
    ifstream file("AdminAccount.txt");

    cout << "\n\t\t\t ----------------------------";
    cout << "\n\t\t\tChuong trinh quan li nhan vien";
    cout << "\n\t\t\t ----------------------------";
    cout << "\n\t\t\tNhap [1] de dang nhap hoac nhap [2] de dang ky tai khoan ADMIN ";
    cin >> choice;

    cin.clear();
    fflush(stdin);

    if(choice == 1) {
        system("cls");
        cout << "\n\t\t\t ----------------------------";
        cout << "\n\t\t\tDang nhap tai khoan ADMIN";
        cout << "\n\t\t\t ----------------------------";
        cout << "\n\t\t\tUsername: ";
        cin >> name;
        cout << "\n\t\t\tPassword: ";
        ch = _getch();

        while(ch != 13) {
            pass.push_back(ch);
            cout << '*';
            ch = _getch();
        }

        if(!file)
        {
            cout << "\n\t\t\tChua co tai khoan nao.";
        }
        else
        {
            file >> name_c >> pass_c;
            while(!file.eof()) {
                if(name == name_c && pass == pass_c)
                {
                    count = 1;
                    break;
                }
                file >> name_c >> pass_c;

            }
        file.close();
        }
        if(count == 1) {
            cout << "\n\t\t\tDang nhap thanh cong!";
            passwordUser();
        }
        else {
            cout << "\n\t\t\tTai khoan khong ton tai!\n";
            system("pause");
            system("cls");
            user();
        }
   }
    else if(choice == 2) {
        system("cls");
        cout << "\n\t\t\t ----------------------------";
        cout << "\n\t\t\tDang ky tai khoan ADMIN: ";
        cout << "\n\t\t\t ----------------------------";
        cout << "\n\t\t\tUsername: ";
        cin >> name_c;
        cout << "\n\t\t\tPassword(Chi 4 chu so): ";
        ch = _getch();

        while(ch != 13) {
            pass_c.push_back(ch);
            cout << '*';
            ch = _getch();
        }
        ofstream file("AdminAccount.txt", ios::app);
        file << name_c << " " << pass_c << '\n';
        file.close();
        cout << "\n\t\t\tDang ky moi tai khoan ADMIN thanh cong";
        getch();
        system("cls");
        user();
    }
    else {
        cout << "\n\t\t\tInput khong hop le!";
        cout << "\n\t\t\t ----------------------------";
        user();
    }
}

void xdelete()
{
    system("cls");
    string deleteID, checkID, name, exp;
    char choice;
    string getworkday;
    bool found = false;

    cout << "\n\t\t\tNhap ID nhan vien muon xoa: ";
    cin >> deleteID;

    ifstream file1("NhanVien.txt");
    ifstream file2("WorkDay.txt");

    if(!file1)
    {
        cout << "\n\t\t\tKhong co du lieu";
        file1.close();
        file2.close();
    }
    else
    {
        ofstream file3("Record1.txt", ios::app | ios::out);
        ofstream file4("Record2.txt", ios::app | ios::out);

        getline(file1, name);
        getline(file1, checkID);
        getline(file1, exp);
        getline(file2, getworkday);

        while(!file1.eof())
        {

            if(checkID != deleteID)
            {
                file3 << name << "\n" << checkID << "\n" << exp << '\n';
                if(!file2.eof()) file4 << getworkday << '\n';
                getline(file2, getworkday);
            }
            else
            {
                cout << "\n\t\t\tNhan vien: " << name;
                cout << "\n\t\t\tID: " << checkID;
                cout << "\n\t\t\tChuc danh: " << exp;
                cout << "\n\t\t\tDa xoa nhan vien\n";
                getline(file2, getworkday);
                found = true;
            }
            getline(file1, name);
            getline(file1, checkID);
            getline(file1, exp);
        }

        file1.close();
        file2.close();
        file3.close();
        file4.close();
        remove("NhanVien.txt");
        remove("WorkDay.txt");
        rename("Record1.txt", "NhanVien.txt");
        rename("Record2.txt", "WorkDay.txt");
    }
    if(!found)
    {
        cout << "\n\t\t\tKhong co nhan vien nay!\n";
    }
    system("pause");

}

void timkiem()
{
    system("cls");
    string ID;
    string name;
    string exp;
    string checkID;
    ifstream file("NhanVien.txt");

    cout << "\n\t\t\tNhap ID muon tim kiem: ";
    cin >> ID;

    if(!file)
    {
        cout << "\n\t\t\tKHONG CO DU LIEU";
        system("pause");
        return;
    }
    else
    {
        getline(file, name);
        getline(file, checkID);
        getline(file, exp);
        while(!file.eof())
        {
            if(checkID == ID)
            {
                cout << "\n\t\t\t***TIM THAY NHAN VIEN***";
                cout << "\n\t\t\t-HO VA TEN: " << name;
                cout << "\n\t\t\t-ID: " << checkID;
                cout << "\n\t\t\t-CHUC DANH: " << exp << '\n';
                system("pause");
                return;
            }
            getline(file, name);
            getline(file, checkID);
            getline(file, exp);
        }
        file.close();
    }
    cout << "\n\t\t\tKhong tim thay nhan vien.\n";
    system("pause");
}
//Kiem tra so ngay cong cua nhan vien
void checkngaycong()
{
    int check;
    int getID, found = 0;
    int index = 0;
    int ngaycong[so_thang];
    //Neu khong ton tai file thi in ra man hinh
    ifstream file("WorkDay.txt"); //Mo lay du lieu tu file
    if(!file)
    {
        cout << "\n\t\t\tKHONG TON TAI DU LIEU";
        system("pause");
        return;
    }
    else
    {
    cout << "\n\t\t\tNhap ID cua nhan vien can kiem tra: ";
    cout << "\n\n\t\t\tNhap tai day -> ";
    cin >> check;
    file >> getID;
        while(!file.eof())
        {
            if(check == getID)
            {
                found = 1;
                while(!file.eof() && index != so_thang)
                {
                    file >> getID;
                    ngaycong[index] = getID;
                    index++;
                }
            }
            file >> getID;
        }
    }
    file.close();
    system("cls");
    if(found == 0)
    {
        cout << "\n\t\t\t----Khong tim thay nhan vien----\n";
        system("pause");
    }
    else
    {
        cout << "\n\t\t\tID Nhan vien: " << check;
        for(int i = 0; i < so_thang; i++) cout << "\n\t\t -So ngay cong thang " << i + 1 << ": " << ngaycong[i] << '\n';
        system("pause");
    }

}


bool checkID(string &checkID)
{
    string fileID;
    ifstream file("NhanVien.txt");
    if(!file) return true;
    else
    {
        getline(file, fileID);
        while(!file.eof())
        {
            if(checkID == fileID)
                return false;
            getline(file, fileID);
        }
        file.close();
    }
    return true;

}

void xemToanBo()
{
    system("cls");
    string ID, name, exp;
    char choice;
    int index = 1;
    ifstream file("NhanVien.txt");

    if(!file)
    {
        cout << "\n\t\t\tKhong mo duoc file!";
    }
    else
    {
        getline(file, name);
        getline(file, ID);
        getline(file, exp);

        cout << "\n\t\t\tDANH SACH NHAN VIEN HIEN CO: ";
        while(!file.eof())
        {
            cout << "\n\t\t\tSTT: " << index++;
            cout << "\n\t\t\tTen: " << name;
            cout << "\n\t\t\tID: " << ID;
            cout << "\n\t\t\tCong viec hien tai: " << exp;
            cout << "\n\t\t\t---------------------------------------------";

            getline(file, name);
            getline(file, ID);
            getline(file, exp);
        }
    }
    file.close();

    cout << "\n\t\t\tBam [T] de xem o che do thong ke, bam bat ki de thoat.";
    cout << "\n\t\t\t--> ";
    cin >> choice;
    cin.clear();
    fflush(stdin);

    if(toupper(choice) == thong_ke) thongke();
}

void nhapdulieu()
{
    system("cls");
    char ch;
    employee emp;
    fstream file;
    regex pattern("[0-9]{4}");
    regex pattern2("([A-Z][a-z]+\\s[A-Z][a-z]+(\\s[A-Z][a-z]+)*)+");
	
    file.open("NhanVien.txt" , ios::app | ios::out);
    cout << "\n\t\t\tNhap ten nhan vien (Ho dem va Ten): ";
    getline(cin, emp.name);
    while(!regex_match(emp.name, pattern2))
        {
            cout << "\n\t\t\tTen khong hop le, vui long nhap lai: ";
            getline(cin, emp.name);
        }
    cout << "\n\t\t\tNhap ID[4 chu so]: ";
    cin >> emp.ID;
    while(!checkID(emp.ID) || !regex_match(emp.ID, pattern))
    {
        if(!checkID(emp.ID)) cout << "\n\t\t\tTrung lap ID, vui long nhap lai: ";
        else if (!regex_match(emp.ID, pattern)) cout << "\n\t\t\tSai dinh dang ID, vui long nhap lai: ";
        cin >> emp.ID;
    }

    cin.ignore();
    cout << "\n\t\t\tNhap chuc danh nhan vien: ";
    getline(cin, emp.exp);
    file << emp.name << "\n" << emp.ID << "\n" << emp.exp << "\n";
    cout << "\n\t\t\t------------------------------------------------------\n";
    file.close();

    system("cls");
    system("pause");

    cout << "-------------------------------------------NHAP NGAY CONG----------------------------------------------\n";
    int temp;
    int index = 0;

	file.open("WorkDay.txt", ios::app | ios::out);
    cout << "\n\t\t\tBan dang nhap ngay cong cho nhan vien: " << emp.name;
    cout << "\n\t\t\t---------------------------------------------";

    for(int j = 0 ; j < so_thang; j++) {
        cout << "\n\t\t\tNhap ngay cong thang thu " << j + 1 << ": ";
        cin >> temp;
        cout << "\n\t\t\t---------------------------------------------";

        while(temp > so_ngay_toi_da || temp < so_ngay_toi_thieu || cin.fail())
        {
            cout << "\n\t\t\tNgay cong khong hop le!\n\t\t\tNhap lai: ";
            cin.clear();
            fflush(stdin);
            cin >> temp;
        }
        emp.ngaycong[j] = temp;
    }
    file << emp.ID << ' ' << emp.ngaycong[0] << ' ' << emp.ngaycong[1] << ' ' << emp.ngaycong[2] << ' ' << emp.ngaycong[3] << ' ' << emp.ngaycong[4] << ' ' << emp.ngaycong[5] << ' ' << emp.ngaycong[6] << ' ' << emp.ngaycong[7] << ' ' << emp.ngaycong[8] << ' ' << emp.ngaycong[9] << ' ' << emp.ngaycong[10] << ' ' << emp.ngaycong[11] << '\n';
	file.close();

    cout << "\n\t\t\tTiep tuc nhap [Y] hoac bam phim bat ki de thoat: ";
    cin >> ch;
    cin.ignore();

    if(toupper(ch) == xac_nhan) nhapdulieu();
    else return;

	system("cls");
}

void thongke()
{
    system("cls");
    int stt = 1;
    string name = "";
    string ID = "";
    string exp = "";
    char ch;
    //Mo file NhanVien.txt de lay thong tin
    ifstream file("NhanVien.txt");
    cout << setw(40) << "---DU LIEU THONG KE---" << setw(55) << "\n\n";
    if(!file)
    {
        cout << "\n\t\t\t---KHONG CO DU LIEU---\n";
        system("pause");
        return;
    }
    //Lap bang du lieu thong ke
    else
    {
        getline(file, name);
        file >> ID;
        file.ignore();
        getline(file, exp);
        cout << setfill(' ');
        cout << "----------------------------------------------------------------------\n";
        cout << setw(3) << "STT" << setw(4)<< '\t' << "ID" << setw(12) << "\t " <<  "Ho Ten" << setw(10) << "\t" << "Chuc danh" << "\n" ;
        cout << "----------------------------------------------------------------------\n";
            while(!file.eof())
            {
                cout << setw(1) << stt++ << setw(4) << '\t' << ID << setw(12) << '\t'  <<  name << setw(10) << "\t" << exp << "\n";
                getline(file, name);
                file >> ID;
                file.ignore();
                getline(file, exp);
            }
        cout << "----------------------------------------------------------------------\n";
        file.close();
    }

    cout << "\n\t\t\tBam [W] de kiem tra ngay cong cua nhan vien, bam [X] de xoa nhan vien hoac bam [Q] de thoat";
    cout << "\n\t\t\tNhap tai day: ";
    cin >> ch;
    cin.clear();
    fflush(stdin);

    if(toupper(ch) == thoat_ham) return;
    else if(toupper(ch) == ngay_cong) checkngaycong();
    else if(toupper(ch) == xoa) xdelete();
    else
    {
        cout << "\n\t\t\tVui long chi nhap [W] [X] va [Q]\n ";
        system("pause");
        return;
    }
    cin.ignore();
    thongke();
}
