#include "LinkStack.h"
#include <iostream>
using namespace std;
int main(){
    LinkStack s1;
    InitLinkStack(s1);
    push(s1,1);
    push(s1,2);
    push(s1,3);
    push(s1,4);
    push(s1,5);
    ElemType temp;
    pop(s1,temp);
    cout<<gettop(s1)<<' '<<temp<<endl;
    pop(s1,temp);
    cout<<gettop(s1)<<' '<<temp<<endl;
    pop(s1,temp);
    cout<<gettop(s1)<<' '<<temp<<endl;
    pop(s1,temp);
    cout<<gettop(s1)<<' '<<temp<<endl;
    return 0;
}