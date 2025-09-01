#include "header.h"

using namespace std;

int nhapsn() { // ham sua nhap vao k phai so nguyen nhap lai
    int num;
    while (!(cin >> num) ){
        cin.clear();// Khi nhap mot so nguyen tu ban phim nhung nguoi dung nhap mot chuoi ki tu thi cin se gap loi va dat co loi "failbit" de bao hieu cho chuong trinh de xoa het cac co loi nay va co loi khac trong cin , ta dung cin.clear() ham nay xoa het co loi de nhap du lieu tiep theo
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "So luong khong hop le! vui long nhap lai: ";
    }
    return num;
}

string viethoatenrieng(string str) {
    if (str.empty()) return str;// empty ham kiem tra chuoi str co rong hay khong

    str[0] = toupper(str[0]); // toupper la ham chuyen chu thuong thanh chu hoa

    for (int i = 1; i < str.length(); i++) {
        
        if (str[i - 1] == ' ' && isalpha(str[i])) {// isalpha kiem tra ki tu i co phai la chu cai hay khong
            str[i] = toupper(str[i]);
        }
        
        else if (!isalpha(str[i - 1]) && isalpha(str[i])) {
            str[i] = tolower(str[i]);
        }
    }

    return str;
}
string trim(string str) {
	 while (str[0] == ' ') {
	 	str.erase(0,1);
	 }
	 while (str[str.length() - 1] == ' ') {
	 	str.erase(str.length()- 1,1);
	 }
	 int i = 0;
	 while ( i <= str.length()) {
	 	if(str[i] == ' '&& str[i + 1] == ' ') {
	 		str.erase(i,1);
	 	}
	 	else { 
	 		i++;
	 	}
	 } 
	return regex_replace(str, regex("^[ \t\n]+|[ \t\n]+$"), string(""));
}
bool kiemtrasdt(string phone) {
    
    if (phone.length() != 10) {
        return false;
    }
    
    if (phone.at(0) != '0') {
        return false;
    }
 
    if (phone.at(1) != '9') {
        return false;
    }
  
    for (int i = 2; i < phone.length(); i++) {
        if (!isdigit(phone.at(i))) {
            return false;
        }
    }
  
    return true;
}
void nhapsl(int monan_i,int vtrmonan, Khachhang khachhang[] ){
	cout << "Nhap so luong mon an : ";	
	khachhang[monan_i].donhang[vtrmonan].soluong = nhapsn() ;
	

}
void nhapmonan(int monan_i,Khachhang khachhang[]){
	for(int i = 0; i < khachhang[monan_i].somonan;i++) {
		cout << "Nhap ten mon an thu "<< i+1 <<": ";
		cin.ignore();
		getline(cin,khachhang[monan_i].donhang[i].tenmonan);
		khachhang[monan_i].donhang[i].tenmonan = trim(khachhang[monan_i].donhang[i].tenmonan);
		nhapsl(monan_i ,i,khachhang);
	}
}

//void Nhapkh(int &sokhachhang ,Khachhang khachhang[] ) {
//	int soluongkh;
//	int i = sokhachhang ;
//	cout << "Nhap so luong khach hang : ";
//	soluongkh = nhapsn();
//	while(soluongkh > 0){
//		cout << "Nhap ten khach hang thu "<< i+1 <<": ";
//		cin.ignore();
//		getline(cin,khachhang[i].tenkh);
//		khachhang[i].tenkh = viethoatenrieng(khachhang[i].tenkh);
//		khachhang[i].tenkh = trim(khachhang[i].tenkh);
//		do{
//	
//			cout << "Nhap so dien thoai (yeu cau 09...<10 so>): ";
//			getline(cin,khachhang[i].sdt);
//			
//			if(!kiemtrasdt(khachhang[i].sdt)) {
//				cout << "So dien thoai sai! vui long nhap lai!"<<endl;
//			}
//		}while(!kiemtrasdt(khachhang[i].sdt));
//		
//		cout << "Nhap so mon an : ";
//		khachhang[i].somonan = nhapsn();
//		
//		nhapmonan(i,khachhang);
//		cout << endl;
//		i++;
//		sokhachhang++;
//		soluongkh--;
//		
//	}
//	cout << "Nhap du lieu hoan thanh!" << endl;
//}
void Nhapkh(int *sokhachhang ,Khachhang khachhang[] ) {
	int soluongkh;
	int i = *(sokhachhang );
	cout << "Nhap so luong khach hang : ";
	soluongkh = nhapsn();
	while(soluongkh > 0){
		cout << "Nhap ten khach hang thu "<< i+1 <<": ";
		cin.ignore();
		getline(cin,khachhang[i].tenkh);
		khachhang[i].tenkh = viethoatenrieng(khachhang[i].tenkh);
		khachhang[i].tenkh = trim(khachhang[i].tenkh);
		do{
	
			cout << "Nhap so dien thoai (yeu cau 09...<10 so>): ";
			getline(cin,khachhang[i].sdt);
			
			if(!kiemtrasdt(khachhang[i].sdt)) {
				cout << "So dien thoai sai! vui long nhap lai!"<<endl;
			}
		}while(!kiemtrasdt(khachhang[i].sdt));
		
		cout << "Nhap so mon an : ";
		khachhang[i].somonan = nhapsn();
		
		nhapmonan(i,khachhang);
		cout << endl;
		i++;
		*(sokhachhang++);
		soluongkh--;
		
	}
	cout << "Nhap du lieu hoan thanh!" << endl;
}
void xemdon(int vt,Khachhang khachhang[]){
	cout << "===============================\n";
	cout << "ten khach hang : "<< khachhang[vt].tenkh << endl;
	cout << "So dien thoai : "<<khachhang[vt].sdt<<endl;
	for(int i = 0; i <khachhang[vt].somonan; i++){
		cout << "Ten mon an : "<< khachhang[vt].donhang[i].tenmonan << endl;
		cout << "So luong : "<< khachhang[vt].donhang[i].soluong <<endl;
	}
}
void xemds(int sokhachhang , Khachhang khachhang[]){
	for(int i = 0; i < sokhachhang ;i++ ){
		xemdon(i,khachhang);
	}
}
int timvt(int sokhachhang , Khachhang khachhang[]){//ham tim vi tri khach
	string ten;
	int vitri = -1;
	cin.ignore();
	getline(cin,ten);

	for(int i = 0; i < sokhachhang; i++){
		
		if(khachhang[i].tenkh == ten){
			vitri = i;
			break;
		}
	} 
	return vitri;
}
void sua(int sokhachhang , Khachhang khachhang[]){
	cout << "Nhap ten khach hang can sua thong tin : ";
	int vitri = timvt(sokhachhang , khachhang);
	if (vitri == -1){
		cout << "Khong tim thay thong tin khach hang!"<<endl;
	}
	else
	{
		cout << "Nhap so dien thoai moi : ";
		getline(cin,khachhang[vitri].sdt);
		kiemtrasdt(khachhang[vitri].sdt);
		
		cout << "Nhap so luong mon an moi : ";
		cin >> khachhang[vitri].somonan;
		cout << "\t\tNhap thong tin mon an \n";
		nhapmonan(vitri,khachhang);
		cout << "Nhap du lieu thang cong!" <<endl;
		
	}
	
}
void timkiem(int sokhachhang , Khachhang khachhang[]) {
	string ten;
	cout << "Nhap ten khach hang can tim kiem thong tin (ten khach hang chu cai dau can viet hoa ): ";
	cin >> ten;
	cin.ignore();
	for(int i =0; i< sokhachhang ; i++){
		if(khachhang[i].tenkh == ten ){
			xemdon(i,khachhang);
		}
	}
} 
void thongke(int sokhachhang , Khachhang khachhang[]){
	int tongsl = 0;
	int slTB = 0;
	for(int i = 0; i < sokhachhang ; i++) {
		for(int j = 0; j < khachhang[i].somonan ; j++) {
			tongsl += khachhang[i].donhang[j].soluong;
		}
	}
	slTB = tongsl / songay;
	cout << "Tong so luong mon an khach dat trong  "<< songay <<" ngay la: "<< tongsl <<endl;
	cout << "Trung binh ngay ban duoc la: " << slTB <<endl;
}
void read(string filename,int *&sokhachhang , Khachhang khachhang[]){
	ifstream fileIn;
	fileIn.open("C:\\Users\\Admin\\Downloads\\BTL1(3F)\\input1.txt",ios::in);
	if(fileIn.fail()) {
		cout << "Khong mo duoc tep!";
		return;
	}	
	int i = *sokhachhang;
	
	while(!fileIn.eof()){
	
		getline(fileIn,khachhang[i].tenkh,':');
		khachhang[i].tenkh = viethoatenrieng(khachhang[i].tenkh);
		khachhang[i].tenkh = trim(khachhang[i].tenkh);
		fileIn >> khachhang[i].sdt; 

		fileIn >> khachhang[i].somonan;

		for(int j = 0; j < khachhang[i].somonan ; j++){
			
			getline(fileIn,khachhang[i].donhang[j].tenmonan,':');
			fileIn >> khachhang[i].donhang[j].soluong;
			fileIn.ignore();
		}
		i++;
		sokhachhang++;	
	}
	cout << "Doc du lieu thanh cong!"<<endl;
	fileIn.close();
}
void write(int sokhachhang , Khachhang khachhang[]){
	fstream fileOut;
	fileOut.open("C:\\Users\\Admin\\Downloads\\BTL1(3F)\\output1.txt",ios::app);
	for(int i = 0; i < sokhachhang ; i++){
		khachhang[i].tenkh = viethoatenrieng(khachhang[i].tenkh);
		khachhang[i].tenkh = trim(khachhang[i].tenkh);
		
		fileOut << "Ten khach hang : " << khachhang[i].tenkh << "\t so dien thoai KH : " << khachhang[i].sdt <<endl;
		fileOut << "So mon an da dat " << khachhang[i].somonan <<endl;
		for(int j = 0; j < khachhang[i].somonan ; j++) {
			fileOut << "Ten mon an : "<<khachhang[i].donhang[j].tenmonan << "\t" <<khachhang[i].donhang[j].soluong <<endl;
		}
	}
	cout << "Ghi du lieu thanh cong!"<<endl;
	fileOut.close();
}
void displayMenu(){
	cout << "\t\t===============================================\n";
	cout << "\t\t1.Nhap don hang dat mon an \n";
	cout << "\t\t2.Xem danh sach don hang da dat\n";
	cout << "\t\t3.Sua mon an trong danh sach don hang\n";
	cout << "\t\t4.Tim kiem don hang da dat trong danh sach don hang\n";
	cout << "\t\t5.Thong ke don hang da dat \n";
	cout << "\t\t6.Doc du lieu tu file \n";
	cout << "\t\t7.Ghi du lieu ra file \n";
	cout << "\t\t0.de thoat!\n";
	cout << "\t\t===============================================\n";
}

