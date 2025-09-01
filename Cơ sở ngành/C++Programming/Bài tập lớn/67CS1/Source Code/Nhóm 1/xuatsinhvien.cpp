#include "thuvien.h"

void dinhdangten(string& s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    while (s[0] == ' ') {
        if (s[0] == ' ') {
            s.erase(s.begin());
        }
    }
    for (int i = 0 ; i < s.length()  ; i++) {
        if (s[i] == ' ' && s[i+1] == ' ') {
            s.erase(s.begin() + i) ;
            i--; 
        }
    }
    s[0] = toupper(s[0]);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            s[i+1] = toupper(s[i+1]); 
        }
    }
}

void xuat_terminal(Sinhvien sv[20], Monhoc mon[10], int& n, int& m  ) {
    for (int i = 0 ; i < n ; i++ ){
        cout << "\t\t============================================" ;
        cout << "\n\t\t\t\tSinh vien thu " << i + 1 << "\n" ;
        dinhdangten(sv[i].tensv);
        cout <<"\t\t" <<sv[i].tensv << endl;
        for (int j = 0 ; j < sv[i].somon ; j++){
                cout << "\n\t\tMon dang ki :" ;
                cout << sv[i].mondky[j] << " ";
            for (int k = 0 ; k < m ; k++ ){
                if (sv[i].mondky[j] == mon[k].tenmon){
                    cout << mon[k].tinchi << " tin chi ." << endl ;
                }
            }
        }
    }
}

void xuat_file(Sinhvien sv[20], Monhoc mon[10], int& n, int& m) {
	ofstream f;
	f.open("sinhvien.txt", ios_base::out);
	for (int i = 0; i < n; i++) {
        dinhdangten(sv[i].tensv);
		f << sv[i].tensv << endl;;
		for (int j = 0; j < sv[i].somon; j++) {
			f << sv[i].mondky[j] << " ";
			for (int z = 0; z < m; z++) {
				if (sv[i].mondky[j] == mon[z].tenmon) {
					f << mon[z].tinchi << endl;
				}
			}
		}
	}
	f.close();
}