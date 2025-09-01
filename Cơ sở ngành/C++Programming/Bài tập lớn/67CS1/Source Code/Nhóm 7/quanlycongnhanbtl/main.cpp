#include "Header.h" 
#include "Congnhan.cpp"
int main() {

    while (true) { 
        cout << "========================================================"<<endl; 
        cout << "|||Chuc nang quan ly nang suat lao dong cua cong nhan||| " << endl; 
        cout << "========================================================"<<endl; 
        cout << "|||    =========================================     |||"  << endl;
        cout << "|||    ====>Chon chuc nang:                    =     |||" << endl ; 
        cout << "|||    =====>1. Them moi cong nhan.            =     |||" << endl; 
        cout << "|||    ======>2. Xem danh sach cong nhan.      =     |||" << endl; 
        cout << "|||    ========>3. Tim kiem cong nhan.         =     |||" << endl; 
        cout << "|||    ========>4. Xoa cong nhan.              =     |||" << endl; 
        cout << "|||    =======>5. Thong ke.                    =     |||" << endl; 
        cout << "|||    ======>6. Doc File cong nhan.           =     |||" << endl;
        cout << "|||    ====>7. Thoat.                          =     |||" << endl; 
        cout << "|||    =========================================     |||"<<endl;
        cout << "========================================================"<< endl; 

        int chon; 
        cout <<"======> Nhap lua chon : ";
        cin >> chon; 
        
        switch (chon) { 
            case 1: 
                themMoi(); 
         
                break; 
            case 2: 
                xemDanhSach(); 
        
                break; 
            case 3: 
                timKiem(); 
                break; 
            case 4: 
                xoaCongNhan(); 
                break; 
            case 5: 
                thongKe(); 
                break; 
            case 6:
			    Input();
				break; 
            case 7: 
                return 0; 
            default: 
                cout << "Khong chon dung chuc nang." << endl; 
                break; 
        } 

        cout << endl; 
    } 

    return 0; 
}
