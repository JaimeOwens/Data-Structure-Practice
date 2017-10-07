//
// Created by lenovo on 2017/10/7.
//

#ifndef LINKSTACK_LINKSTACK_H
#define LINKSTACK_LINKSTACK_H
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int status;
typedef int ElemType;
#include<iostream>
using namespace std;
typedef struct Node{
    ElemType data;
    struct Node *next;
}Node,*LinkStack;
status InitLinkStack(LinkStack &s){
    s=NULL;
    return OK;
}
status push(LinkStack &s,ElemType e){
    LinkStack p=new Node;
    p->data=e;
    p->next=s;
    s=p;
    return OK;
}
status pop(LinkStack &s,ElemType &e){
    if(s==NULL) return ERROR;
    e=s->data;
    LinkStack p=s;
    s=s->next;
    delete p;
    return OK;
}
ElemType gettop(LinkStack &s){
    if(s!=NULL) return s->data;
    else exit(ERROR);
}

#endif //LINKSTACK_LINKSTACK_H
