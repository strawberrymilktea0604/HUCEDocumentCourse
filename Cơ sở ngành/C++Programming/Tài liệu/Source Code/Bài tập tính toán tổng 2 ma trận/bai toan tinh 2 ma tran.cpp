#include<iostream>

using namespace std;


int main() {
	int a, b, c, d;
	int arr1[100][100];
	int arr2[100][100]; 
	int arr3[100][100];  
	
	// nhap ma tran 1
	cout << "Nhap so cot ma tran 1: ";
	cin >> a;
	
	cout << "Nhap so hang ma tran 1: ";
	cin >> b; 	
	
	// nhap ma tran 2 
	cout << "Nhap so cot ma tran 2: ";
	cin >> c;
	
	cout << "Nhap so hang ma tran 2: ";
	cin >> d;
	
	// ta se kiem tra dieu kien cua ma tran co bang nhau hay khong
	
	if (a != c || b != d) {
		cout << "Hai ma tran khong bang nhau ve kich co";
		exit(0); 
	} 
	
	// nhap phan tu ma tran 1 
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			printf("Nhap phan tu arr1[%d][%d]: ", i, j); 
			cin >>  arr1[i][j]; 
		}
	} 
	
	// nhap phan tu ma tran 2 
	
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < d; j++) {
			printf("Nhap phan tu arr2[%d][%d]: ", i, j);
			cin >>  arr2[i][j]; 
		}	
		
	}
	
	
	
	
	
	int sum = 0;
	// tinh 2 ma tran  
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			arr3[i][j] = arr1[i][j] + arr2[i][j];  
		}
	}
	
	// hien thi ket qua
	cout << "Tong 2 ma tran la: "; 
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			printf("%d\t", arr3[i][j]); 
		}
		printf("\n");   
	} 
	 
    return 0; 	 
	
	
} 


 
