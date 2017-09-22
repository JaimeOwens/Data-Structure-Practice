/*
#include <iostream>
using namespace std;
typedef float Elemtype;
typedef int Status;
#define OK 1
#define ERROR 0;
#define OVERFLOW -2;
typedef struct LNode{
    Elemtype data;
    struct LNode *next;
    int length;
}LNode,*LinkList;

Status InitList(LinkList &L){
    L=new LNode;
    L->next=NULL;
    L->length=0;
    return OK;
}
Status Insert(LinkList &L,int i,Elemtype e){
    LinkList p=L;
    int j=0;
    while(p&&j<i-1){
        p=p->next;
        j++;
    }
    if(!p||j>i-1)
        return ERROR;
    LinkList s=new LNode;
    s->data=e;
    s->next=p->next;
    p->next=s;
    L->length++;
    return OK;
}
Status MakeHead(LinkList &L,Elemtype e) {
    if (L->length != 0)
        return ERROR;
    L->data = e;
    L = L->next;
    L->length++;
    return OK;
}
int listcnt=1;
void Input(LinkList &L){
    int cnt=1,length;
    Elemtype t;
    cout<<"Input the length of List"<<listcnt<<':'<<endl;
    cin>>length;
    cout<<"Input elements of List"<<listcnt<<" in acsending order:"<<endl;
    while(length--){
        cin>>t;
        if(cnt==1){
            L->next->data=t;
            L->length++;
            cnt++;
        }
        else Insert(L,cnt++,t);
    }
    listcnt++;
}
void Merge(LinkList &la,LinkList &lb,LinkList &lc){
    LinkList pa=la->next;
    LinkList pb=lb->next;
    lc=la;
    LinkList pc=lc;
    while(pa&&pb){
        if(pa->data<=pb->data){
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }
        else{
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
    }
    pc->next=pa?pa:pb;
    delete lb;

}
void Print(LinkList L){
    LinkList p=L->next;
    while(!p){
        cout<<p->data<<' ';
        p=p->next;
    }
}
int main(){
    LinkList L1,L2;
    InitList(L1);
    InitList(L2);
    Input(L1);
    Input(L2);
    LinkList L3;
    Merge(L1,L2,L3);
    Print(L3);
    return 0;
}
*/

