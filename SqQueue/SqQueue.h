//
// Created by jaime on 17-10-8.
//

#ifndef SQQUEUE_SQQUEUE_H
#define SQQUEUE_SQQUEUE_H
typedef int status;
typedef int ElemType;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
const int MAXSIZE=10;
#include <iostream>
using namespace std;
typedef struct{
    ElemType *base;
    int front;
    int rear;
}SqQueue;
status InitQueue(SqQueue &q){
    q.base=new ElemType[MAXSIZE];
    if(!q.base) return ERROR;
    q.front=q.rear=0;
    return OK;
}
int GetLength(SqQueue q){
    return(q.front-q.rear+MAXSIZE)%MAXSIZE;
}
status push(SqQueue &q,ElemType e){
    if((q.rear+1)%MAXSIZE==q.front)
        return ERROR;
    q.base[q.rear]=e;
    q.rear=(q.rear+1)%MAXSIZE;
    return OK;
}
status pop(SqQueue &q,ElemType &e){
    if(q.rear==q.front) return ERROR;
    e=q.base[q.front];
    q.front=(q.front+1)%MAXSIZE;
    //delete e;
    return OK;
}
int GetElem(SqQueue q,ElemType e){
    int index=0;
    while(q.base[index]!=e){
        index++;
    }
    return index+1;
}
void Print(SqQueue q){
    int index=q.front;
    while(index<q.rear){
        cout<<q.base[index]<<' ';
        index++;
    }
    cout<<endl;
}
#endif //SQQUEUE_SQQUEUE_H
