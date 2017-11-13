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
void Resolve(List &LA,List &LB,List &LC){  
    struct Node *pa,*pb,*pc;  
    pa=LA->next;  
    LB=new Node;  
    LC=new Node;//要生成两个新的头结点！！！   
    //LB=LC=LA;//不能这样写，这样写最后输出的LB和LChi一样的表，居然会一样？？为什么？？   
    pb=LB;  
    pc=LC;  
    struct Node *p;  
    p=pa;  
    while(pa){  
        if(pa->data>0){  
            pb->next=pa;  
            pa=pa->next;  
            pb=pb->next;  
            pb->next=NULL;  
        }else if(pa->data<0){  
            pc->next=pa;  
            pa=pa->next;  
            pc=pc->next;  
            pc->next=NULL;  
        }  
    }  
}  
int main(){
    
    int n;
    while(cin>>n){
    	if(n==0) break;
		List L1,L2,L3;
    	InitList(L1);
    	InitList(L2);
    	InitList(L3);
    	Input(L1,n);
    	Resolve(L1,L2,L3);
    	Print(L3);
    	Print(L2);
	}
    return 0;
}
