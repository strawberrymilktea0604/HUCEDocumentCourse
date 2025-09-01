#include <stdio.h>
#include <string.h>
 
struct SinhVien{
    char name[100];
    char quequan[100];
    int namsinh;
    float d_toan, d_ly, d_hoa;
    float dtb; 
};
 
void nhap(int &n, SinhVien A[]){
    printf("Nhap so sinh vien ");
    scanf("%d", &n);
     
    for(int i = 0;i <n; i++){
        printf("\nSinh vien thu %d: \n", i+1);
        printf(" Nhap ten: ");
        fflush(stdin);
        gets(A[i].name);
         
        printf(" Nhap que quan: ");
        gets(A[i].quequan);
         
        printf(" Nhap Nam sinh: ");
        scanf("%d", &A[i].namsinh);
         
        printf(" Nhap diem toan: ");
        scanf("%f", &A[i].d_toan);
             
        printf(" Nhap diem ly: ");
        scanf("%f", &A[i].d_ly);
             
        printf(" Nhap diem hoa: ");
        scanf("%f", &A[i].d_hoa);
         
        A[i].dtb = (A[i].d_toan + A[i].d_ly + A[i].d_hoa) / 3;
    }
}
 
void xuat(int n,  SinhVien A[]){
    printf("\n%-15s %-15s %-10s  %-10s  %-10s  %-10s %-10s","Ten sinh vien","Que quan","Nam sinh", "Diem toan", "Diem ly", "Diem hoa", "Diem tb");
    for(int i = 0;i <n; i++){
        printf("\n%-15s %-15s %-10d  %-10.1f  %-10.1f %-10.1f %-10.1f", A[i].name,A[i].quequan, A[i].namsinh, A[i].d_toan, A[i].d_ly, A[i].d_hoa, A[i].dtb);
    }
}
 
void timKiem(int n, SinhVien A[]){
    printf("Nhap ten sinh vien can tim: ");
    char name[100];
    fflush(stdin);
    gets(name);
     
    bool  check = false;
    for(int i = 0; i< n; i++){
        if(stricmp(A[i].name, name) == 0){
            check = true;
            printf("\n%-15s %-15s %-10d  %-10.1f  %-10.1f %-10.1f %-10.1f", A[i].name,A[i].quequan, A[i].namsinh, A[i].d_toan, A[i].d_ly, A[i].d_hoa, A[i].dtb);
        }
    }
    if(check == false){
        printf(" =>Khong tim thay sinh vien nao");
    }
}
 
void sapXep(int n, SinhVien A[]){
    for(int i = 0; i<n-1;i++){
        for(int j = i+1;j<n;j++){
            if(strcmp(A[i].name, A[j].name) == 1){
                SinhVien temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    xuat(n, A);
}
 
void demYeuTbKhaGioi(int n, SinhVien A[]){
    int yeu = 0, tb = 0, kha = 0, gioi = 0;
     
    for(int i = 0; i<n;i++){
        if(A[i].dtb < 5) yeu++;
        else if(A[i].dtb < 6.5) tb++;
        else if(A[i].dtb < 8) kha++;
        else gioi++;
    }
    printf("\nSo sinh vien yeu la: %d", yeu);
    printf("\nSo sinh vien trung binh la: %d", tb);
    printf("\nSo sinh vien kha la: %d", kha);
    printf("\nSo sinh vien gioi la: %d", gioi);
}
 
int main()
{
    int n = 0;
    SinhVien listSV[100];
     
    printf("\n---------------NHAP-------------------\n");
    nhap(n, listSV);
     
    int chon = 1;
     
    while(chon != 0){
        printf("\n\n---------------------------------------------------------------------------\n");
        printf("1. Nhap lai\n");
        printf("2. Xuat DS sinh vien\n");
        printf("3. Tim kiem Sinh vien\n");
        printf("4. Sap xep DS Sinh Vien\n");
        printf("5. Dem so hoc sinh yeu, trung binh, kha,  gio\n");
        printf("0. Thoat\n");
        printf("---------------------------------------------------------------------------\n");
        printf(" Chon: ");
        scanf("%d", &chon);
         
        switch(chon){
            case 1:
                printf("\n---------------NHAP-------------------\n");
                nhap(n, listSV);
                break;
            case 2:
                printf("\n---------------XUAT-------------------\n");
                xuat(n, listSV);
                break;
            case 3:
                printf("\n---------------TIM KIEM-------------------\n");
                timKiem(n, listSV);
                break;
            case 4:
                printf("\n---------------SAP XEPSINH VIEN THEO TEN-------------------\n");
                sapXep(n, listSV);
                break;
            case 5:
                printf("\n---------------DEM HOC LUC SINH VIEN-------------------\n");
                demYeuTbKhaGioi(n, listSV);
                break;
        }
    }
}
