#include<conio.h>
#include<stdio.h>
#include <iostream>
#include <string.h>

using namespace std;


// khai bao cau truc sinh vien 
struct SinhVien{
	int STT;
	char name[100];
	char monhoc[100]; 
	float diemmonhoc;
	float dtb;  
}; 

int main() {
	int n, m;  
    SinhVien sv[100][100];
}  



// ham de nhap thong tin hoc sinh 

void nhap(int &n, int &m, SinhVien sv[]){
	
	printf("Nhap so sinh vien hoc: ");
    scanf("%d", &n);
 
	
	printf("Nhap so mon hoc sinh vien can hoc: ");  
	scanf("%d", &m);
  
	 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			
			
			
			
		printf("Nhap so thu tu sinh vien: "); 
		scanf("%i", &sv[i].STT);
		
		printf("\nSinh vien thu %d: \n", i + 1);
        printf(" Nhap ho va ten: ");
        fflush(stdin);
        gets(sv[i].name);
			
		printf("Nhap ten mon hoc: "); 
		gets(sv[j].monhoc); 
		
		printf("Nhap diem: "); 
		scanf("%f", &sv[j].diemmonhoc);
			
			 
		}
	}
	
	int size;  
	int sum = 0;  
	// ham de tinh diem trung binh cac mon hoc
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < m; j++) {
		sum += sv[j].diemmonhoc;
		sv[i].dtb =  (sv[j].diemmonhoc)/size; 
		}
	}
	}
		
		
	// ham de hien xuat thong tin hoc sinh 
void xuat(int &n, int &m, SinhVien sv[]){
    //xuat ten cot 
    for(int i = 0;i <n; i++){
    	for(int j = 0;j <m; i++){
    printf("\n%-15s %-15s %-10s %-10s","STT", "Ten sinh vien", sv[j].monhoc,  "Diem tb");
}
} 
 
    //in thong tin n sinh viên
    for(int i = 0;i <n; i++){
        printf("\n%-15s %-10.1f %-10.1f",sv[i].STT, sv[i].name, sv[i].diemmonhoc, sv[i].dtb);
    }
}





	
	





 


