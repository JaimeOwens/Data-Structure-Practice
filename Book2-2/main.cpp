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

int listcnt=1;
void InitList(LinkList &L){
	L=new LNode;
	L->next=NULL;
	LinkList r=L;
	cout<<"Input the length of List"<<listcnt<<':'<<endl;
    cin>>L->length;
    cout<<"Input elements of List"<<listcnt<<" in ascending order:"<<endl;
    for(int i=0;i<L->length;i++){
    	LinkList p=new LNode;
    	cin>>p->data;
    	p->next=NULL;
		r->next=p;
		r=p;	
	}
	listcnt++;
}
void MergeList(LinkList &La,LinkList &Lb,LinkList &Lc)
{
    LinkList pa=La->next;
    LinkList pb=Lb->next;
    LinkList pc;
    Lc=pc=La;
    while(pa && pb)
    {
        if(pa->data<pb->data){
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }
        else if(pa->data>pb->data) {
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
        else {
            pc->next=pa;
            pc=pa;
            pa=pa->next;
            LinkList q=pb->next;
            delete pb ;
            pb =q;
        }
    }
    pc->next=pa?pa:pb;
    delete Lb;
}
void Print(LinkList L){
	cout<<"The result:"<<endl; 
    LinkList p=L->next;
    while(p){
        cout<<p->data<<' ';
        p=p->next;
    }
}
int main(){
    LinkList L1,L2,L3;
    InitList(L1);
    InitList(L2);
    MergeList(L1,L2,L3);
    Print(L3);
}
