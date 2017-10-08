//
// Created by jaime on 17-10-8.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <iostream>
#define OK 1
#define ERROR -1
#define OVERFLOW -2
using namespace std;
typedef int status;
typedef int Elemtype;
typedef struct Node{
    Elemtype data;
    struct Node *next;
}Node,*Queue;
typedef struct {
    Queue head;
    Queue tail;
}LinkQueue;
status InitQueue(LinkQueue &lq){
    lq.head=lq.tail=new Node;
    lq.head->next=NULL;
    return OK;
}
status push(LinkQueue &q,Elemtype e){
    Queue p=new Node;
    p->data=e;
    p->next=NULL;
    q.tail->next=p;
    q.tail=p;
    return OK;
}
status pop(LinkQueue &q,Elemtype &e){
    if(q.head==q.tail) return ERROR;
    Queue p=q.head->next;
    e=p->data;
    q.head->next=p->next;
    if(q.tail==p) q.tail=q.head;
    delete p;
    return OK;
}
int GetElem(LinkQueue q,Elemtype e){
    int index=0;
    Queue p=q.head;
    while(p!=q.tail){
        if(p->data==e)
            break;
        else{
            index++;
            p=p->next;
        }
    }
    return index;
}
void Print(LinkQueue q){
    Queue p=q.head->next;
    while(p!=NULL){
        cout<<p->data<<' ';
        p=p->next;
    }
    cout<<endl;
}
#endif //QUEUE_QUEUE_H
