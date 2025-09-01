#include<iostream>
#include<fstream>

using namespace std; 

int main() {
	{ 
	
	int hang = 5;
	int cot = 5;
	
	int mang2chieu[hang][cot];
	
	//Mo file 
    ifstream data("bai1.txt");  
	
	if(!data.is_open()) {
	cout << "Khong mo duoc file!" << endl;
	return -1;}
	
	//Tao vong lap
	for (int h = 0; h < hang; h++) {
		for (int c = 0; c < cot; c++) {
			data >> mang2chieu[h][c]; 
		}
	}
	 
	for (int h = 0; h < hang; h++) {
		for (int c = 0; c < cot; -c++) {
			cout << mang2chieu[h][c] << "\t"; 
		} 
		cout << endl; 
	}
	
	 
	 } 
	}

 
