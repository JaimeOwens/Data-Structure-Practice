#include <iostream>
#include "Queue.h"
using namespace std;
int main(){
    LinkQueue q;
    Elemtype e;
    InitQueue(q);
    push(q,1);
    push(q,2);
    push(q,3);
    push(q,4);
    push(q,5);
    push(q,6);
    push(q,7);
    Print(q);
    cout<<GetElem(q,7)<<endl;
    pop(q,e);
    cout<<e<<endl;
    Print(q);
    return 0;
}