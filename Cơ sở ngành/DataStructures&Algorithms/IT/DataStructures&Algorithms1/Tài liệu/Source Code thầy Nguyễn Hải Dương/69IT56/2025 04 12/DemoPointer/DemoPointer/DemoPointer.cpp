// DemoPointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct PhanTu
{
    int Val; //phần để chứa dữ liệu
    PhanTu* Link; //phần để chứa liên kết đến phần tử bên cạnh
};

int main()
{
    ////khai báo biến bình thường
    //int x = 5;
    //cout << "Gia tri cua x=" << x << endl;
    //cout << "Dia chi vung nho duoc cap phat cho x: " << &x << endl;

    ////khai báo con trỏ
    //int* p = NULL; //p ban đầu không trỏ vào đâu
    //p = &x; //trỏ p vào x
    //cout << "Dia chi cua vung nho ma p dang tro vao: " << p << endl;
    //cout << "Du lieu dang duoc luu tru trong vung nho ma p dang tro vao: " << *p << endl;

    //x = 7;
    //cout << "Du lieu dang duoc luu tru trong vung nho ma p dang tro vao sau khi thay doi gia tri cua x: " << *p << endl;

    //*p = 10;
    //cout << "x moi=" << x << endl;

    //int y = 3;
    //cout << "y ban dau=" << y << endl;

    //p = &y;
    //*p = 11;
    //cout << "y moi=" << y << endl;


    //mảng
    //int A[10]; 
    //A[0] = 1;
    //A[1] = 2;
    //A[2] = 3;
    //cout << "Dia chi vung nho duoc cap phat cho mang A: " << &A << endl;
    //int* p = NULL;
    //p = A; //A thực chất là con trỏ

    //cout << "Du lieu tren vung nho ma p dang tro vao: " << *p << endl;
    //p++;
    //cout << "Du lieu tren vung nho ma p dang tro vao: " << *p << endl;
    //p++;
    //cout << "Du lieu tren vung nho ma p dang tro vao: " << *p << endl;
    //p--;
    //cout << "Du lieu tren vung nho ma p dang tro vao: " << *p << endl;
    //p--;
    //cout << "Du lieu tren vung nho ma p dang tro vao: " << *p << endl;
    //p--;
    //cout << "Du lieu tren vung nho ma p dang tro vao: " << *p << endl;
    ////*p = 10;

    //cấp phát vùng nhớ trống (mới hoàn toàn) cho p
    //int* p = (int*)malloc(sizeof(int)); //malloc cấp phát 1 vùng nhớ có dung lượng đúng bằng 1 int
    //int* p = (int*)calloc(1,sizeof(int)); //calloc cấp phát 1 vùng nhớ có dung lượng = 1 int * số lượng phần tử

    //cấp phát 1 mảng tĩnh cho p
    //p = (int*)malloc(10 * sizeof(int));
    //p = (int*)calloc(10, sizeof(int));

    ////Mảng bán động
    ////tương tác vào từng phần tử tương tự như mảng
    //*p = 0;
    //cout << "A[0]=" << *p <<endl;
    //p++;
    //*p = 1;
    //cout << "A[1]=" << *p << endl;
    //p++;
    //*p = 2;
    //cout << "A[2]=" << *p << endl;
    //p++;
    //*p = 3;
    //cout << "A[3]=" << *p << endl;
    //p++;
    //*p = 4;
    //cout << "A[4]=" << *p << endl;

    //p--;
    //cout << "A[3]=" << *p << endl;

    //mảng động toàn phần
    //đặc trưng: chỉ cấp phát bộ nhớ cho từng phần tử mỗi khi sử dụng

   /* struct SV
    {
        int MSSV;
    };

    SV sv1;
    sv1.MSSV*/

    PhanTu* A0 = NULL;

    //khởi tạo phần tử thứ nhất
    A0 = (PhanTu*)malloc(sizeof(PhanTu));
    A0->Val = 1;
    A0->Link = NULL;

    //khởi tạo phần tử thứ 2
    PhanTu* A1 = (PhanTu*)malloc(sizeof(PhanTu));
    A1->Val = 2;
    A1->Link = NULL;

    //liên kết 2 phần tử với nhau
    A0->Link = A1;

    //khởi tạo phần tử thứ 3
    PhanTu* A2 = (PhanTu*)malloc(sizeof(PhanTu));
    A2->Val = 3;
    A2->Link = NULL;

    //liên kết phần tử thứ 3 vào mảng hiện tại
    A1->Link = A2;

    //in ra mảng
    PhanTu* tg = A0;

    cout << "A = {";
    while (tg != NULL)
    {
        cout << tg->Val << ",";
        tg = tg->Link;
    }
    cout << "}" << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
