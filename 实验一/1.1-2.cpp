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
typedef struct LNode{
    Elemtype data;
    struct LNode *next;
    int length;
}LNode,*LinkList;

//int listcnt=1;
void InitList(LinkList &L) {
    L = new LNode;
    L->next = NULL;
    L->length = 0;
}
void Print(LinkList L) {
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
void Input(LinkList &L,int n){
	LinkList r=L;
	L->length=n;
	for(int i=0;i<n;i++){
		LinkList p=new LNode;
		cin>>p->data;
		p->next=NULL;
        r->next=p;
        r=p;
	}	
	//Print(L); 
}
void MergeList(LinkList &La,LinkList &Lb,LinkList &Lc){
    LinkList pa=La->next;
    LinkList pb=Lb->next;
    LinkList pc;
    Lc=pc=La;
    Lc->next=NULL;
    while(pa || pb){
        LinkList q;
        if(!pa){
        	q=pb;
        	pb=pb->next;
		}
		else if(!pb){
			q=pa;
			pa=pa->next;
		}
		else if(pa->data<=pb->data){
           q=pa;
           pa=pa->next;
        }
        else{
           q=pb;
           pb=pb->next;
        }
        q->next=Lc->next;
        Lc->next=q;
    }
    delete Lb;	
	Print(Lc);
}
int main(){
    int n1,n2;
    while(cin>>n1>>n2){
    	if(n1==0&&n2==0) break;
		LinkList L1,L2,L3;
		InitList(L1);
    	InitList(L2);
    	Input(L1,n1);
    	Input(L2,n2);
    	MergeList(L1,L2,L3);
	}
	return 0;
	
}
