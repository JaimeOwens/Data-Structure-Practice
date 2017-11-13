//
// Created by jaime on 17-9-21.
//
#include <iostream>
using namespace std;
typedef float Elemtype;
typedef int Status;
#define OK 
#define ERROR 0;
#define OVERFLOW -2;
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
void DiffList(List &La,List &Lb){
	List pa=La->next;
    List pb=Lb->next;
    List pc=La;
    pc=La;
    while(pa&&pb){
        //List q;
        if(pa->data==pb->data){
        	pc->next=pa->next;
        	List u=pa;
        	pa=pa->next;
        	delete u;
		}
		else if(pa->data<pb->data){
			pc=pa;
			pa=pa->next;
		}
		else pb=pb->next;
	}
    delete Lb;
}
int Count(List L){
	int sum=0;
	while(L->next){
		L=L->next;
		sum++;
	}
	return sum;
}
int main(){
    int n1,n2;
    while(cin>>n1>>n2){
    	if(n1==0&&n2==0)
    		break;
		List L1,L2,L3;
		InitList(L1);
    	InitList(L2);
    	Input(L1,n1);
		Input(L2,n2); 
    	DiffList(L1,L2);
    	Print(L1);
    	int sum=Count(L1);
    	cout<<sum<<endl;
	}
    return 0;
}
