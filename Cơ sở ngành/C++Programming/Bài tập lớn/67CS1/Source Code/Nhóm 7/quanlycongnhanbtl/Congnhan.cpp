
#include "Header.h" 

void nhapThongTin(CongNhan& cn) { 
    
    cout << "Nhap ho va ten cong nhan: ";
    cin.ignore(); 
    getline(cin, cn.hoTen);
    cout << "Nhap so ngay cong: "; 
    cin >> cn.ngayCong; 
    cout << "Nhap so san pham: "; 
    cin >> cn.sanPham; 


}



void themMoi() { 
    if (n == MAXN) { 
        cout << "Vuot qua so luong cong nhan toi da." << endl; 
        return; 
     
	} 
     
    CongNhan cn; 
    nhapThongTin(cn); 
    a[n++] = cn; 
    
    if ( cn.ngayCong < 0 && cn.sanPham < 0 && cn.soLuong < 0 ) {
	
		cout <<"=============================="<<endl;
		cout <<"||| Them khong thanh cong! |||" << endl;
		cout <<"=============================="<< endl;
} else {
      
    cout <<"========================"<<endl;
    cout <<"||| Them thanh cong. |||" << endl;
    cout <<"========================"<<endl;
	       
} 
}



void xemDanhSach() { 
    if (n == 0) { 
        cout << "Chua co cong nhan nao." << endl; 
        return; 
    } 
    cout << "===================="<< endl;
    cout << "Danh sach cong nhan: " << endl; 
    
    for (int i = 0; i < n; i++) { 
     if ( a[i].ngayCong < 0 ) {
     	cout << "==========="<<endl;
     	cout << "!!!Errol!!!" << endl;
     	cout << "===========" << endl;
	 } else if (a[i].sanPham < 0) {
	 
	 cout << "ERROR!" << endl;
    } else {
        cout  <<i +1  << "." <<a[i].hoTen << ", ngay cong: " << a[i].ngayCong <<", san pham: " << a[i].sanPham << endl; 
    } 
  }cout <<"===================" << endl;
} 


void timKiem() { 
    string hoTen; 
    cout << "Nhap ho ten can tim kiem: "; 
    cin.ignore(); 
    getline(cin, hoTen);

    for (int i = 0; i < n; i++) { 
        if (a[i].hoTen == hoTen ) 
		 if (a[i].ngayCong > 0 )
		  if (a[i].sanPham > 0){ 
            cout << "Thong tin cong nhan can tim:" << endl; 
            cout << "Ho ten: " << a[i].hoTen << ", ngay cong: " << a[i].ngayCong << ", san pham: " << a[i].sanPham << endl; 
            return; 
        
		} else { cout << "ERROR!"<<endl;
		}
    } 

    cout << "Khong tim thay cong nhan co ho ten \"" << hoTen << "\"" << endl; 
} 

void xoaCongNhan() { 
    string hoTen; 
    cout << "Nhap ho ten cong nhan can xoa: "; 
    cin.ignore(); 
    getline(cin, hoTen);

    // Tim kiem cong nhan
    for (int i = 0; i < n; i++) { 
        if (a[i].hoTen == hoTen) { 
            // Xoa cong nhan
            for (int j = i + 1; j < n; j++) { 
                a[j - 1] = a[j]; 
            } 
            n--; 
            cout << "Xoa thanh cong." << endl; 
            return; 
        } 
    } 

    cout << "Khong tim thay cong nhan co ho ten \"" << hoTen << "\"" << endl; 
} 

void thongKe() { 
    if (n == 0) { 
        cout << "Chua co cong nhan nao." << endl; 
        return; 
    } 

    int tongSanPham = 0;
	int tongNgayCong = 0; 
    for (int i = 0; i < n; i++) { 
     if (a[i].ngayCong < 0 && a[i].sanPham < 0) 
      {
     	cout << "ERROR!"<< endl;
	 } else {
	 
        tongSanPham += a[i].sanPham; 
        tongNgayCong+= a[i].ngayCong;
    } 
}

    double trungBinh = (double)tongSanPham / (double)tongNgayCong; 

    cout << "So cong nhan: " << n << endl;
	cout<< " Tong ngay cong: "  << tongNgayCong<<endl;
    cout << "Tong san pham: " << tongSanPham  << endl; 
    cout << "Trung binh san pham/ngay cua mot cong nhan: " << trungBinh << endl; 
} 
void Input() {
	ifstream file("input.txt",ios::in); // Mo file input 
	if (!file.is_open()) { // Kiem tra xem file có mo thành công không
    cout << "Khong the mo file.\n";
    return ;
	
	}
	int i  = n;
    
	string line;
	while(!file.eof()) {
		getline(file, a[i].hoTen);
		file >>a[i].ngayCong;
		file >>a[i].sanPham;
		i++;
		
 
	} 
	n++; 
	file.ignore();
	cout << "Doc file thanh cong " << endl;
	
    file.close(); // Ðóng file
}
void Output(){

   
 ofstream fileOut;
    fileOut.open("output.txt", ios::out);
    if (fileOut.fail()) {
        cout << "Loi mo tep.";
        return;
    }
    for (int i = 0; i < n ; i++) {
    	fileOut<<a[i].hoTen << endl;
		fileOut<<a[i].ngayCong<<endl;
		fileOut<<a[i].sanPham<<endl; 
	}
	cout <<fileOut<<endl;
fileOut.close();
}

