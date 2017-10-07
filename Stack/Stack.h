//
// Created by lenovo on 2017/10/7.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <iostream>
#define MAXSIZE 100
#define OVERFLOW -2
#define OK 1
#define ERROR 0
using namespace std;
typedef int status;
typedef int ElemType;
typedef struct{
    ElemType *base;
    ElemType *top;
    int size;
}Stack;
status InitStack(Stack &s){
    s.base=new ElemType[MAXSIZE];
    if(!s.base) exit(OVERFLOW);
    s.top=s.base;
    s.size=MAXSIZE;
    return OK;
}
status push(Stack &s,ElemType e){
    if(s.top-s.base==s.size) exit(ERROR);
    *s.top++=e;
    return OK;
}
status pop(Stack &s,ElemType &e){
    if(s.top==s.base) exit(ERROR);
    e=*--s.top;
    return OK;
}
ElemType gettop(Stack &s){
    if(s.top==s.base) exit(ERROR);
    return *(s.top-1);
}
#endif //STACK_STACK_H
