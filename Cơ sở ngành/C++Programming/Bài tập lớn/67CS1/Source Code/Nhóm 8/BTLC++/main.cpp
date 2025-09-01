#include"btl.cpp"


int main()
{	
	QLKS a[MAX];
	const string FILENAME = "DATA.txt";

	while(true)
	{
		int lua_chon = show_menu();
		switch(lua_chon)
		{
			case 1:
			//them phong
				nhap(a[n]);
				++n;
				break;
			case 2:
			// xem danh sach so phong da thue
				inDanhSach(a,n);	
				break;
			case 3:
			// tim kiem phong
				timKiemPhong(a, n);	
				break;
			case 4:
			// xoa phong
				xoaPhong(a,n);	
				break;
			case 5:
			// thong ke	
				lietKe(a, n);
				break;
			case 6:
			// luu file	
				luuFile(a,n, FILENAME);
				break;
			case 7:
			// load file
				loadFile(a, n,FILENAME);	
				break;
			case 0:
				cout << "\n\t-Da thoat chuong trinh .\n";
				break;	
			default:
				cout << "\n\t-Moi ban nhap lai.\n";
                break;									
		}
		cout << "\t\t->Ban co muon tiep tuc khong ? (1/0): ";
		double is_continue;
		

		do{
			cin >> is_continue;
			if(is_continue==0)
				break;
				
			if(is_continue!=0&&is_continue!=1)
				cout<<"Nhap lai : ";
				
		}while(is_continue!=0&&is_continue!=1);
		
		if(is_continue==0)
		{
			break;
		}
			
		
	}
	return 0;
}

