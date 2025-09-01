
#include "function.cpp"


int main(){
	int choice ;
	int sokhachhang = 0;
	do{
	displayMenu();
	cout << "Nhap lua chon cua ban : ";
	cin >> choice ;
	switch (choice ){

		case 1:
			Nhapkh(sokhachhang,khachhang);
			break;
		case 2:
			xemds(sokhachhang,khachhang);
			break;
		case 3:
			sua(sokhachhang,khachhang);
			break;
		case 4:
			timkiem(sokhachhang,khachhang);
			break;
		case 5:
			thongke(sokhachhang,khachhang);
			break;
		case 6:
			read("input1.txt",sokhachhang,khachhang);
			break;
		case 7: 
			write(sokhachhang,khachhang);
			break;
	
		default: 
			cout << "Nhap khong hop le! vui long nhap lai \n";
		}
	}
	while(choice != 0);
	cout << "Da thoat!"<<endl;
	return 0;
}
