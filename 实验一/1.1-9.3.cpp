#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct Dnode{
	int data;
	struct Dnode *next;
	struct Dnode *pre;
}Dnode,*Dlist;
void InitList(Dlist &DL){
	DL=new Dnode;
	DL->pre=NULL;
	DL->next=NULL; 
}
void Input(Dlist &DL,int n){
	Dlist r=DL;
	r->pre=NULL;
	for(int i=0;i<n;i++){
		Dlist p=new Dnode;
		cin>>p->data;
		p->next=NULL;
		p->pre=r;
		r->next=p;
		r=p;
	}
	r->next=NULL;
}
void Print(Dlist DL){
	while(DL->next){
		DL=DL->next;
		cout<<DL->data<<' ';
	}
	cout<<endl;
}
void Swap(Dlist DL){
	Dlist q,p,t;
	int index,i=0;
	cin>>index;
	t=DL->next;
	while(i<index-1){
		q=t;
		t=t->next;
		p=t;
	}
	q=p->pre;
	q->pre->next=p;
	p->pre=q->pre;
	q->next=p->next;
	q->pre=p;
	p->next->pre=q;
	p->next=q;
}
int main(){
	int n;
	while(cin>>n){
		if(n==0) break;
		Dlist DL;
		InitList(DL);
		Input(DL,n);
		//Print(DL);
		Swap(DL);
		Print(DL);
	}
	return 0;
}
