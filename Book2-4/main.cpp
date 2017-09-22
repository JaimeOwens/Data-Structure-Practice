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
void Complementary(LinkList &La,LinkList &Lb,int &sum){
    LinkList pa=La->next;
    LinkList pb=Lb->next;
    LinkList pre=La,t;
    while(pa&&pb){
        if(pa->data==pb->data){
            pre->next=pa->next;
            t=pa;
            pa=pa->next;
            delete t;
        }
        else if(pa->data>pb->data){
            pb=pb->next;
        }
        else{
            pre=pa;
            pa=pa->next;
            sum++;
        }
    }
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
    LinkList L1,L2;
    int sum;
    InitList(L1);
    InitList(L2);
    Complementary(L1,L2,sum);
    cout<<"The number of elements:"<<sum<<endl;
    Print(L1);
    return 0;
}