//
// Created by jaime on 17-9-21.
//

#include <iostream>
using namespace std;
typedef float Elemtype;
typedef int Status;
#define OK 1;
#define ERROR 0;
#define OVERFLOW -2;
typedef struct LNode{
    Elemtype data;
    struct LNode *next;
    //int length;
}LNode,*LinkList;

int listcnt=1;
void InitList(LinkList &L){
    L=new LNode;
    L->next=NULL;
    //L->length=0;

}

void MakeList(LinkList &L){
    LinkList r=L;
    int length;
    cout<<"Input the length of List"<<listcnt<<':'<<endl;
    cin>>length;
    cout<<"Input elements of List"<<listcnt<<" in ascending order:"<<endl;
    for(int i=0;i<length;i++){
        LinkList p=new LNode;
        cin>>p->data;
        p->next=NULL;
        r->next=p;
        r=p;
    }
    listcnt++;
}

void Print(LinkList L){
    //cout<<"The result:"<<endl;
    LinkList p=L->next;
    while(p){
        cout<<p->data<<' ';
        p=p->next;
    }
    cout<<endl;
}
void Decompose(LinkList &La,LinkList &Lb,LinkList &Lc){
    Lb->next=NULL;
    Lc->next=NULL;
    LinkList p=La->next;
    while(p){
        LinkList t=p->next;//保存p的后继结点
        if(p->data<0){
            p->next=Lb->next;
            Lb->next=p;
        }
        else{
            p->next=Lc->next;
            Lc->next=p;
        }
        p=t;
    }//前插法
}

int main() {
    LinkList La,Lb,Lc;
    InitList(La);
    InitList(Lb);
    InitList(Lc);
    MakeList(La);
    Decompose(La,Lb,Lc);
    cout << "The elements those smaller than zero:" << endl;
    Print(Lb);
    cout << "The elements those not smaller than zero:" << endl;
    Print(Lc);
    //cout<<Lb->next->data<<endl;
    //cout<<Lc->next->data<<endl;
    return 0;
}
