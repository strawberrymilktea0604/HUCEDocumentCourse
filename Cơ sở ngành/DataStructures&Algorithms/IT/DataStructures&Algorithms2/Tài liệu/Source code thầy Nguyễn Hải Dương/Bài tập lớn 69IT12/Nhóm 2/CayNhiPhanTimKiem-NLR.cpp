#include <iostream>
using namespace std;

struct node //Khai bao cau truc node
{
    int data; // Du lieu cua node (So nguyen)
    struct node *Trai;
    struct node *Phai;
};

typedef struct node NODE; // Doi ten struct node = NODE
typedef NODE* TREE; // Doi ten NODE* = TREE

void KhoiTaoCay(TREE &t) //Khoi tao cay
{
    t = NULL; //Cay rong
}

void ThemPhanTuVaoCay(TREE &t, int x) //Them phan tu vao cay
{
    if (t == NULL) //Neu cay khong ton tai phan tu
    {
        NODE *p = new NODE;
        p->data = x; //Them du lieu x vao data
        p->Trai = NULL;
        p->Phai = NULL;
        t = p; //p chinh la node goc <=> x chinh la node goc
    }
    else //Neu cay ton tai phan tu
    {
        if (t->data > x) //Nho hon phan tu goc
        {
            ThemPhanTuVaoCay(t->Trai, x); //Duyet them vao ben trai
        }
        else if (t->data < x) //Lon hon phan tu goc 
        {
            ThemPhanTuVaoCay(t->Phai, x); //Duyet them vao ben phai
        }
    }
}

void DuyetNLR(TREE t) //Duyet theo cach NLR (Node Left Right)
{
    if (t != NULL)
    {
        cout << t->data << " ";
        DuyetNLR(t->Trai);
        DuyetNLR(t->Phai);
    }
}

void DuyetLNR(TREE t) //Duyet theo cach LNR (Left Node Right)
{
    if (t != NULL)
    {
        DuyetLNR(t->Trai);
        cout << t->data << " ";
        DuyetLNR(t->Phai);
    }
}

void DuyetLRN(TREE t) //Duyet theo cach LRN (Left Right Node)
{
    if (t != NULL)
    {
        DuyetLRN(t->Trai);
        DuyetLRN(t->Phai);
        cout << t->data << " ";
    }
}

NODE *TimKiemPhanTu(TREE t, int x) //Tim kiem phan tu trong cay
{
    while (t != NULL)
    {
        if (t->data == x)
        return t; //Tim thay gia tri
        else if (t->data > x) t = t->Trai; //Tim kiem o ben trai
        else t = t->Phai; //Tim kiem o ben phai
    }
    return NULL;
}

void NodeTheMang(TREE &X, TREE &Y)
{
    if (Y->Trai != NULL) //Tim node trai nhat
    {
        NodeTheMang(X, Y->Trai);
    }
    else //Tim duoc node trai nhat
    {
        X->data = Y->data; //Cap nhat data cua node can xoa chinh la data cua node the mang
        X = Y; //Cho node X (node se bi xoa) tro den node the mang Y 
        X = Y->Phai; //Cap nhat lai moi lien ket cho node cha cua node the mang lai la NULL
    }
}

void XoaPhanTu(TREE &t, int x) //Xoa phan tu trong cay
{
    if (t == NULL)
    return;
    if (x < t->data)
    XoaPhanTu(t->Trai, x); //Duyet sang trai cua cay
    else if (x > t ->data)
    XoaPhanTu(t->Phai, x); //Duyet sang trai cua phai
    else //Da tim ra phan tu can xoa
    {
        NODE *X = t; //Node can xoa
        if (t->Trai == NULL) //Neu node co cay con phai
        {
            t = t->Phai; //Tro den cay con phai
        }
        else if (t->Phai == NULL) //Neu node co cay con trai
        {
            t = t->Trai; ////Tro den cay con trai
        }
        else
        {
            //Tim node trai nhat cua cay con phai
            NODE *Y = t->Phai; //Node Y la node the mang cho node can xoa
            NodeTheMang(X, Y);
        }
        delete X; //Xoa
    }
}

void Menu(TREE &t) //Khoi tao Menu
{
    while (true)
    {
        system("cls");
        cout << "\n==========MENU==========";
        cout << "\n1. Nhap du lieu";
        cout << "\n2. Duyet du lieu kieu LRN";
        cout << "\n3. Duyet du lieu kieu LNR";
        cout << "\n4. Duyet du lieu kieu NLR";
        cout << "\n5. Tim kiem du lieu";
        cout << "\n6. Xoa du lieu";
        cout << "\n0. Ket thuc";
        cout << "\n========================\n";

        int luachon; 
        cout << "Nhap lua chon: ";
        cin >> luachon;
        if (luachon < 0 || luachon > 6)
        {
            cout << "Nhap lua chon khong hop le!!";
            system("pause");
        }
        else if (luachon == 1)
        {
            int x;
            cout << "\nNhap mot so nguyen: ";
            cin >> x;
            ThemPhanTuVaoCay(t, x);
        }
        else if (luachon == 2)
        {
            cout << "\nDuyet theo cay LRN: \n";
            DuyetLRN(t);
            system("pause");
        }
        else if (luachon == 3)
        {
            cout << "\nDuyet theo cay LNR: \n";
            DuyetLNR(t);
            system("pause");
        }
        else if (luachon == 4)
        {
            cout << "\nDuyet theo cay NLR: \n";
            DuyetNLR(t);
            system("pause");
        }
        else if (luachon == 5)
        {
            int x;
            cout << "Gia tri can tim: ";
            cin >> x;
            NODE *kq = TimKiemPhanTu(t, x);
            if (kq != NULL)
            cout << "Tim thay gia tri '" << x << "' trong cay nhi phan\n";
            else
            cout << "Khong tim thay gia tri can tim\n";
            system("pause");
        }
        else if (luachon == 6)
        {
            int x;
            cout << "Nhap gia tri can xoa: ";
            cin >> x;
            XoaPhanTu(t, x);
        }
        else
        {
            break;
        }
    }
}

int main()
{
    TREE t;
    KhoiTaoCay(t);
    Menu(t);
    DuyetNLR(t);
    DuyetLRN(t);
    DuyetLNR(t);
    int x;
    XoaPhanTu(t, x);
    TimKiemPhanTu(t, x);
    return 0;
}