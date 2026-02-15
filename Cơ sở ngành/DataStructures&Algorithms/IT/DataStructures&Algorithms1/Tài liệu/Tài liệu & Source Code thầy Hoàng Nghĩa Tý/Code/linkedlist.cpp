#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

struct NODE
{
	int data;
	int next;
};

struct LIST
{
	NODE n[100];
	NODE head;
	NODE tail;
	int count;
};

void CreateLIST(LIST &L)
{
	L.count=0;
}

NODE CreateNODE(int data,int next)
{
	NODE p;
	p.data=data;
	p.next=next;
	return p;
}

void AddNODE(LIST &l,NODE p)
{
	l.count++;
	l.n[l.count-1].data=p.data;
	l.n[l.count-1].next=p.next;
}

void Output(LIST l)
{
	for(int i=0;i<l.count;i++)
	{
		cout<<l.n[i].data<<" "<<l.n[i].next<<endl;
	}
}

int main()
{
	LIST l;
	CreateLIST(l);
	NODE p=CreateNODE(5,1);
	AddNODE(l,p);
	Output(l);
	cout<<endl;
	NODE p1=CreateNODE(6,2);
	AddNODE(l,p1);
	Output(l);
	NODE p2=CreateNODE(7,3);
	AddNODE(l,p2);
	Output(l);
	return 0;
}
