#include<iostream>
#includem=<math.h>
using namespace std;

//Nhap so luong vao mang
void Nhap(int a[], int n) {
     for (int n = 0; i < n; i++)
     cout << " a[ " << i + 1 << " = "; 
     cin >> a[i];
     }
     }
     
//Xuat du lieu ra man hinh 
void Xuat(int[] a, int n) {
     for (int i = 0; i < n; i++) {
         cout << a[i] << "  ";
         }
         }
         
// Tong so phan tu lon hon 20
int Tong(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 20) {
                 sum+= a[i];
                 }
                 }
                 return 0;
                 } 
                 
// Dem so  
int Demso (int a[], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
                 tong+= a[i];
                 }
                 
                 float tb = (float)sum/ n;
                 int dem = 0
                 for (int i = 0; i < n; i++) {
                     if (a[i] > tb) {
                              dem++;
                              cout << a[i] << " ";
                              }
                              }
                               
                 return 0;
                 }
                 
int main() {
    int a[1000]; int n;
    cout << "Nhap so luong phan tu: "; cin >> n;
    Nhap(a, n);
    cout << endl << "Day so vua nhap: " ;
    Xuat(a, n);
    cout << "Tong so phan tu co gia tri lon hon 20 la: " << Tong(a, n);
    cout << "Ta dem duoc gia tri la: " << Demso(a, n); 
    return 0;
}