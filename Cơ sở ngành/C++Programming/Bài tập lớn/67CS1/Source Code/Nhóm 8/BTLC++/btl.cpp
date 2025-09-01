#include"btl.h"


void in(QLKS a)
{
	cout << setw(2)<<dem++<< setw(20)<<a.ten_khach_hang<<setw(15)<<a.ma_phong<< setw(15)<<a.nam_sinh<<setw(15);
	cout<<a.gia_tien<<setw(15)<<a.so_ngay_thue<<setw(15) <<endl;
}
	
	
void nhap(QLKS &a)
{
	cout << "-Nhap ten nguoi thue : "; 
	cin.ignore();
	getline(cin, a.ten_khach_hang);		   			
		
	while(a.ten_khach_hang[1]==' ')
	{
		a.ten_khach_hang.erase(1,1);
	}
	
	while(a.ten_khach_hang[a.ten_khach_hang.length()]==' ')
	{
		a.ten_khach_hang.erase(a.ten_khach_hang.length()-1,1);
	}
	
	int i =0;
	while(i< a.ten_khach_hang.length())
	{
		if(a.ten_khach_hang[i] == ' ' && a.ten_khach_hang[i+1] == ' ')
	{
		a.ten_khach_hang.erase(i,1);
	}
		else
		{
			i++;
		}
	}
		
	for(int i =0; i< a.ten_khach_hang.length(); i++)
	{
	  	a.ten_khach_hang[i]= tolower(a.ten_khach_hang[i]);
	}
	
	if(a.ten_khach_hang[0] != ' ')
	{
		a.ten_khach_hang[0] = toupper(a.ten_khach_hang[0]);
	}
	for(int i =0; i<a.ten_khach_hang.length();i++)
	{
		if(a.ten_khach_hang[i] ==' ' && a.ten_khach_hang[i+1] != ' ')
		{
			a.ten_khach_hang[i+1] =toupper(a.ten_khach_hang[i+1]);
		}
	}
		
		
	cout << "-Nhap ma phong : "; 
	cin >> a.ma_phong;
		
		
	do
	{
		cout << "-Nhap nam sinh nguoi thue (1900 - 2023) : "; 
		cin>> a.nam_sinh;
			
		if(a.nam_sinh <1900||a.nam_sinh>2023||a.nam_sinh != (int)a.nam_sinh)
		{
			cout << "Moi ban nhap lai ! "<<endl;
		}
	
	}while(a.nam_sinh <1900||a.nam_sinh>2023 || a.nam_sinh != (int)a.nam_sinh);
			
	
	do
	{
		cout << "-Nhap gia tien thue 1 ngay : "; 
		cin >> a.gia_tien;
		
		if(a.gia_tien<0)
		{
			cout << "Moi ban nhap lai !"<< endl;
		}
	}while(a.gia_tien<0);	
		
		
	do
	{
		cout << "-Nhap so ngay khach thue : "; 
		cin >> a.so_ngay_thue;
		if(a.so_ngay_thue < 0)
		{
			cout << "Moi ban nhap lai ! "<<endl;	
		}
	}while(a.so_ngay_thue < 0);
		
}	


void title()
{
	cout << setw(2)<<"STT"<< setw(20)<<"TEN KHACH HANG"<<setw(15)<<"MA PHONG"<< setw(15)<<"NAM SINH"<<setw(15)<<"GIA TIEN"<<setw(15);
	cout<<"SO NGAY THUE" <<setw(15)<<endl;
}


void inDanhSach (QLKS a[], int n)
{	
	if(n>0)
	{	
	
		cout <<"\t\t\tTHONG TIN DANH SACH PHONG THUE.\n\n";
		title();
		for(int i = 0; i< n ;i++)
		{
			in(a[i]);
		}
	}
	else
		cout << "-Chua co thong tin !\n";
	
}

void timKiemPhong(QLKS a[], int n)
{	
	if(n>0)
	{
		string ma_phong ;
		cout <<"-Nhap ma phong thue can tim : "; 
		cin.ignore();
		getline(cin, ma_phong);
		bool found = false;
		for(int i =0; i<n ; i++)
		{
			if(a[i].ma_phong.find(ma_phong) !=string::npos)
			{	
				title();
				in(a[i]);
				found = true;
			}
		}
		if(!found)
		{
			cout <<"-Khong tim thay thong tin vua nhap !\n";
			cout << endl;
		}
	}
	else
		cout << "-Chua co thong tin ! \n";
		cout << endl;
}

void xoaPhong(QLKS a[], int length)
{

	int vt;
	string xoa ;
	cin.ignore();
	cout << "Nhap ten khach hang can xoa : ";
	getline(cin , xoa);
	for(int i =0; i <length; i++)
	{
		if(a[i].ten_khach_hang == xoa)
		{
			vt = i;
			break;	
		}
		else
		{
			cout << "Thong tin khong dung !";
		}
	}
	
	for(int i=vt;i<length;i++)
	{
		a[i]=a[i+1];
    }
	n--;
	cout << endl;
}


void lietKe(QLKS a[], int n)
{	
	if(n>0)
	{
		int res =0;
		for(int i=0; i< n;i++)
		{
			if(a[i].so_ngay_thue > res )
			{
				res = a[i].so_ngay_thue;
			}
		}
		cout << "\t\tDanh sach phong co ngay thue cao nhat :\n";
		for(int i =0; i< n;i++)
		{
			if(res == a[i].so_ngay_thue)
			{	
				title();
				in(a[i]);
			}
		}
		
	}
	else 
		cout <<"\t\tChua co thong tin! \n";
}

int show_menu()
{
	system("cls");
	double lua_chon ;
	cout << "\n\t\t CHUONG TRINH QUAN LI KHACH SAN       \n";
    cout << "\t\t****************************************\n";
    cout << "\t\t** 1. Them phong thue                 **\n";
    cout << "\t\t** 2. Xem danh sach phong thue        **\n";
    cout << "\t\t** 3. Tim kiem phong thue             **\n";
    cout << "\t\t** 4. Xoa thong tin phong thue        **\n";
    cout << "\t\t** 5. Thong ke                        **\n";
    cout << "\t\t** 6. Luu danh sach phong ra file     **\n";
    cout << "\t\t** 7. Load file da luu                **\n";
    cout << "\t\t** 0. Thoat chuong trinh.             **\n";
    cout << "\t\t****************************************\n\n";
    cout << "\t\t->Enter lua_chon: ";
	do{
		cin >> lua_chon; 
		if(lua_chon!=0&&lua_chon!=1&&lua_chon!=2&&lua_chon!=3&&lua_chon!=4&&lua_chon!=5&&lua_chon!=6&&lua_chon!=7)
			cout<<"Nhap lai cac lua chon : ";
	}while(lua_chon!=0&&lua_chon!=1&&lua_chon!=2&&lua_chon!=3&&lua_chon!=4&&lua_chon!=5&&lua_chon!=6&&lua_chon!=7);
		
	
	return lua_chon;

}
void luuFile(QLKS a[], int n, string filename)
{
	ofstream f1;
	f1.open("DATA.txt");
	f1 <<"\n";
	for(int i =0 ; i<n; i++)
	{
		f1 << a[i].ten_khach_hang<<endl;
		f1 << a[i].ma_phong <<" "<<a[i].nam_sinh<< " "<<a[i].gia_tien<<" "<<a[i].so_ngay_thue;
		f1 <<"\n";
	}
	f1.close();
	cout << "\n\t-Da luu vao file DATA.txt\n\n";
	
}

void loadFile(QLKS a[], int &n, string filename) {
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
            a[count].ten_khach_hang = name;
            
            in_file >> a[count].ma_phong;
            in_file >> a[count].nam_sinh;
            in_file >> a[count].gia_tien;
            in_file >> a[count].so_ngay_thue;
           
            count++;
        }
    }
    in_file.close();
    cout << "\n\t-Da load du lieu thanh cong.\n\n";
    n = count;
}

