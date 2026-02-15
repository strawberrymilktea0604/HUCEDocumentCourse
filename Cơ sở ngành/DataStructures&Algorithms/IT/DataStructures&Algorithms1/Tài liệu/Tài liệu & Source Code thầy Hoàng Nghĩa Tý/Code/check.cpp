#include<iostream>
#include <cstdlib>

using namespace std;
struct NODE{
	int data;
	struct NODE *pNext;
};
//typedef struct node NODE;
struct LIST{
	NODE *pHead;
	NODE *pTail;
	
};
//typedef struct list LIST;
NODE *khoitao(int x)
{
    NODE* p = (NODE*)malloc(sizeof(NODE));
	p->data=x;
    p->pNext=NULL;
	return p;
}
void khoitaoList(LIST &l)
{
	l.pHead=NULL;
	l.pTail=NULL;
}
void themvaocuoi(LIST &l,NODE *p)
{
	if(l.pHead==NULL)
	{
		l.pHead=l.pTail=p;
	}
	else
	{
		l.pTail->pNext=p;
		l.pTail=p;
	}
}
void xuatdanhsach(LIST l)
{
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext)
			{
				cout<<k->data<<" ";
			}
}
void demsoluong(LIST &l)
{
	int dem=0;
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext)
	{
		if(k->data==0)
		{
			dem=dem+1;
		}
	}
	cout<<"So luong phan tu 0 xuat hien trong danh sach la : "<<dem<<" lan .";
}
void sapxepgiamdan(LIST &l)
{
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext)
	{
		for(NODE *h=k->pNext;h!=NULL;h=h->pNext)
		{
			if(k->data < h->data)
			{
				int tg=k->data;
				k->data=h->data;
				h->data=tg;
			}
		}
	}
}
void timkiem(LIST l)
{
    int a;
	cout<<"\nNhap vao gia tri cua a : ";
	cin>>a;
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext)
	{
	    if(k->data>a)
		{
		    cout<<k->data<<" ";
		}
	}
}		
	
void Menu(LIST &l)
{
	int luachon;
	while(1)
	{
		cout<<"\n\t\t--------MENU---------";
		cout<<"\n\t1.Nhap vao 1 node .";
		cout<<"\n\t2.Xuat danh sach lien ket .";
		cout<<"\n\t3.Dem phan tu 0 trong danh sach .";
		cout<<"\n\t4.Sap xem theo chieu giam dan .";
		cout<<"\n\t5.Xuat ra danh sach ca node lon hon gia tri cua a .";
		
		cout<<"\n\t0.Thoat .";
		cout<<"\n\t\t---------------------";
		cout<<"\nNhap lua chon cua ban : ";
		cin>>luachon;
		if(luachon==1)
		{
			int x;
			cout<<"\nNhap gia tri cho node : ";
			cin>>x;
			NODE *p=khoitao(x);
			themvaocuoi(l,p);
		}
		else if(luachon==2)
		{
			xuatdanhsach(l);
			
		}
		else if(luachon==3)
		{
			demsoluong(l);
			
		}
		else if(luachon==4)
		{
			sapxepgiamdan(l);
			xuatdanhsach(l);
			
		}
		else if(luachon==5)
		{
			timkiem(l);
			
		}
		else
		{
			break;
		}
	}
}
int main()
{
	LIST l;
	khoitaoList(l);
	Menu(l);
	
}

