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
Elemtype Max(List L){
	Elemtype max=-0x7f; 
	while(L->next){
		L=L->next;
		if(L->data>max)
			max=L->data;	
	}
	return max;
}
int main(){
	int n;
	while(cin>>n){
		if(n==0) break;
		List L1;
    	InitList(L1);
    	Input(L1,n);
    	cout<<Max(L1)<<endl;
	}
    return 0;
}
