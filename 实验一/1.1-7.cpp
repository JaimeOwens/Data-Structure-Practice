#include<iostream>
typedef int Status;
typedef int Elemtype;
#define ERROR -1
#define OK 1
#define OVERFLOW -2
const int MAXSIZE=100;
using namespace std;
typedef struct Node{
    Elemtype data;
    struct Node *next;
    int length;
}Node,*List;
void InitList(List &L) {
    L = new Node;
    L->next = NULL;
    L->length = 0;
}
void Input(List &L,int n){
	List r=L;
	L->length=n;
	for(int i=0;i<n;i++){
		List p=new Node;
		cin>>p->data;
		p->next=NULL;
        r->next=p;
        r=p;
	}
	//Print(L);	
}
void Print(List L) {
    //L=L->next;
	while(L->next){
		L = L->next;
        if(L->next)
			cout<<L->data<<' ';
		else 
			cout<<L->data;	
	}
	cout<<endl;
}
void Reverse(List &La,List &Lb){
	List pa=La; 
	List pb=Lb;
	while(pa->next){
		pa=pa->next;
		List t=new Node;
		t->data=pa->data;
		t->next=pb->next;
		pb->next=t;
	}  
}
int main(){
	int n;
	while(cin>>n){
		if(n==0) break;
		List La;
		List Lb;
		InitList(La);
		InitList(Lb); 
		Input(La,n);
		Reverse(La,Lb);
		Print(Lb);
	}
	return 0; 
}

 
