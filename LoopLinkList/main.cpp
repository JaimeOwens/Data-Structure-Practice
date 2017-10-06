#include <iostream>
#include "LoopLinkList.h"
#include "LoopLinkList.cpp"
using namespace std;
int main(){
    LoopLinkList<int> List;
    List.InsertTail(6);
    List.InsertTail(5);
    LoopLinkList<int>::Item *pTempTail = List.getTail();
    List.InsertHead(4);
    List.InsertHead(7);
    List.InsertHead(3);
    List.InsertHead(8);
    List.dump();
    List.InsertNext(pTempTail,100);
    List.InsertNext(pTempTail,110);
    List.dump();
    List.DeleteItem(pTempTail);
    List.dump();
    LoopLinkList<int> List2;
    List2.InsertHead(14);
    List2.InsertTail(17);
    List2.InsertTail(13);
    List2.InsertHead(18);
    LoopLinkList<int> List3(List2);
    List3.dump();
    LoopLinkList<int> List4;
    List4=List3;
    List4.dump();
    List.DeleteItem(6);
    List.dump();
    List.DeleteHead();
    List.dump();
    List.DeleteItem(5);
    List.dump();
    List.DeleteHead();
    List.dump();
    List.DeleteTail();
    List.dump();
    List.DeleteAll();
    List.dump();
    system("pause");
    return 0;
}