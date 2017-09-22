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
void Intersection(LinkList &La,LinkList &Lb,LinkList &Lc){
    LinkList pa=La->next;
    LinkList pb=Lb->next;
    LinkList pc,t;
    Lc=pc=La;
    while(pa&&pb){
        if(pa->data==pb->data){
            pc->next=pa;
            pc=pa;
            pa=pa->next;
            t=pb;
            pb=pb->next;
            delete t;
        }
        else if(pa->data>pb->data){
            t=pb;
            pb=pb->next;
            delete t;
        }
        else{
            t=pa;
            pa=pa->next;
            delete t;
        }
    }
    while(pa){
        t=pa;
        pa=pa->next;
        delete t;
    }
    while(pb){
        t=pb;
        pb=pb->next;
        delete t;
    }
    pc->next=NULL;
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
    Intersection(L1,L2,L3);
    Print(L3);
    return 0;
}