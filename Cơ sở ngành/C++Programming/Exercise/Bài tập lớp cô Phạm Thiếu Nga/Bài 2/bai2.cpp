#include<iostream>
#include<string> 
#include<fstream>

using namespace std;

int main() {
	//Mo file 
	
	ifstream data("tinhthanh.txt");
	
	if (data.fail()) {
		cout << "Khong mo duoc file!";
		return 1; 
	} 
	
	//Tao vong lap de nhan du lieu dau vao 
	
	string line;
	int lines = 0; 
	
	while(!data.eof()) {
	    getline(data, line); 
	    cout << line << endl; 
		lines++;
	}
	
	
	data.close();  
	
	cout << "Co tat ca " << lines << " tinh thanh" << endl;
	system("pause"); 
	return 0; 
} 
