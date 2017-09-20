// Created by jaime on 17-9-19.
#include "LinkList.h"
#include <iostream>
using namespace std;
template <class Elemtype>
LinkList<Elemtype>::LinkList() {
    try{
        Head=new LinkNode<Elemtype>;
    }
    catch (const bad_alloc& e){
        cout<<"内存分配失败"<<endl;
        exit(1);
    }
}
template <class Elemtype>
LinkList<Elemtype>::LinkList(const Elemtype &e) {
    try {
        Head=new LinkNode<Elemtype>(e);
    }
    catch (const bad_alloc & e)
    {
        cerr << "分配内存失败!" << endl;
        exit(1);
    }
}
template <class Elemtype>
LinkList<Elemtype>::LinkList(const LinkList&copy){
    LinkNode<Elemtype> *p=copy.Head->next;
    try{
        Head=new LinkNode<Elemtype>;
        LinkNode<Elemtype> *h=Head;
        while(p!=NULL){
            LinkNode<Elemtype>*t=new LinkNode<Elemtype>;
            h->next=t;
            t->data=p->data;
            p=p->next;
            h=h->next;
        }
    }
    catch (const bad_alloc & e)
    {
        cerr << "分配内存失败!" << endl;
        exit(1);
    }
}
template <class Elemtype>
LinkList<Elemtype> &LinkList<Elemtype>::operator=(LinkList<Elemtype> &List) {
    try{
        LinkList<Elemtype> temp(*this);//??
        temp.DestroyList();
        LinkNode<Elemtype> *p=List.Head;
        LinkNode<Elemtype> *h=temp.Head;
        while(p!=NULL){
            LinkNode<Elemtype> *t=new LinkNode<Elemtype>;
            h->next = t;
            t->data = p->data;
            p = p->next;
            h = h->next;
        }
        swap(temp);
        return *this;
    }
    catch (const bad_alloc & e) {
        cerr << "分配内存失败!" << endl;
        return *this;
    }
}
template <class Elemtype>
void LinkList<Elemtype>::~LinkList(){
    DestroyList();
};
template <class Elemtype>
void LinkList<Elemtype>::CreateList(int length) {
    LinkNode<Elemtype> *q=Head;
    cout<<"Input the elements:"<<endl;
    int *nodetemp = new int[length];
    for(size_t i=0;i<length;i++){
        cin>>nodetemp[i];
    }
    for(size_t i=0;i<length;i++){
        try{
            LinkNode<Elemtype> * p = new LinkNode<Elemtype>;
            p->data = nodetemp[i];
            p->next = q->next;
            q->next = p;
            q = q->next;//前插法
        }
        catch (const bad_alloc &e)
        {
            cerr << "分配内存失败!" << endl;
            exit(1);
        }
    }
    delete[] nodetemp;
}
template <class Elemtype>
void LinkList<Elemtype>::DestroyList()
{
    LinkNode<Elemtype> *p = Head;
    LinkNode<Elemtype> *t;
    while (p)
    {
        t = p->next;
        delete p;
        p = t;
    }
}
template <class Elemtype>
void LinkList<Elemtype>::ClearList() {
    LinkNode<Elemtype> *p = Head;

    while (p)
    {
        p->data = NULL;
        p = p->next;
    }
}
template <class Elemtype>
void LinkList<Elemtype>::show() const {
    LinkNode<Elemtype> *p = Head->next;
    while (p)
    {
        cout << p->data << "  ";
        p = p->next;
    }
    cout << endl;
}
template <class Elemtype>
bool LinkList<Elemtype>::IsEmpty(){
    LinkNode<Elemtype> *p = Head->next;
    while (p) {
        if (p->data == NULL){return true;}
        p = p->next;
    }
    return false;
}
template <class Temp>
int LinkList<Temp>::GetLength() const {
    LinkNode<Temp> *p = Head->next;
    int nLink = 0;
    while (p) {
        nLink++;
        p = p->next;
    }
    return nLink;
}
template <class Temp>
bool LinkList<Temp>::GetElem(int pos, Temp &item) {
    LinkNode<Temp> *p = Locate(pos);
    if (p == NULL) {return false;}
    item = p->data;
    return true;
}
template <class Temp>
void LinkList<Temp>::SetHead(LinkNode<Temp> *p) {
    Head->data = p->data;
    Head->next = p->next;
}
template <class Temp>
LinkNode<Temp>* LinkList<Temp>::Find(Temp &item) {
    LinkNode<Temp> *p = Head->next;
    while (p) {
        if (p->data == item) {break;}
        p = p->next;
    }
    return p;
}
template <class Temp>
LinkNode<Temp>* LinkList<Temp>::Locate(int pos) {
    LinkNode<Temp> *p = Head;
    while (pos--) {
        p = p->next;
    }
    return p;
}
template <class Temp>
bool LinkList<Temp>::InsertAt(Temp item, int pos){
    LinkNode<Temp> *p=Locate(pos-1);
    if(p==NULL) return false;
    try{
        LinkNode<Temp> *node = new LinkNode<Temp>(item);
        node->next=p->next;
        p->next=node;
        return true;
    }
    catch (const bad_alloc &e){
        cout << "Error!"<<endl;
        return false;
    }
}
template<class Elemtype>
bool LinkList<Elemtype>::RemoveAt(int index, Elemtype &e) {
    LinkNode<Elemtype> *p=Locate(index-1);
    if(p==NULL||p->next==NULL){ return false; }
    LinkNode<Elemtype> *del=p->next;
    p->next=del->next;
    e=del->data;
    delete del;
    return true;
}
template <class Elemtype>
void LinkList<Elemtype>::Reverse() {
    LinkNode<Elemtype> *pre=Head->next;//首元结点直接后继（a1）
    LinkNode<Elemtype> *curr=pre->next;//a1直接后继（a2）
    LinkNode<Elemtype> *next=NULL;
    Head->next->next=NULL;//a1直接后继被置为空
    while(curr){
        next=curr->next;//a2直接后继
        curr->next=pre;//a2直接后继变为a1
        pre=curr;//首元结点直接后继被赋值为a2
        curr=next;//a1直接后继变为a3
    }
    Head->next=pre;//首元结点直接后继为a2
}
/*
 *
前插法建立反链表
01
	Status ListReverse2(LinkList L)
02
	{
03
	    LinkList current, p;
04

05
	    if (L == NULL)
06
	    {
07
	        return NULL;
08
	    }
09
	    current = L->next;
10
	    while (current->next != NULL)
11
	    {
12
	        p = current->next;
13
	        current->next = p->next;
14
	        p->next = L->next;
15
	        L->next = p;
16
	    }
17
	    return L;

	}
 */
template<class Elemtype>
void LinkList<Elemtype>::Reverse(int nstart, int nend) {
    LinkNode<Elemtype>* start=Locate(nstart-1);
    LinkNode<Elemtype>* end=Locate(nend);
    LinkNode<Elemtype>* pre=Locate(nstart);
    LinkNode<Elemtype>* curr=pre->next;
    LinkNode<Elemtype>* next=NULL;
    pre->next=end->next;
    while(pre!=end){
        next=curr-> next;
        curr->next=pre;
        pre=curr;
        curr=next;
    }
    start->next=pre;
}
template <class Elemtype>
void LinkList<Elemtype>::LinkSwap(int pos1, int pos2) {
    LinkNode<Elemtype>* p1=Locate(pos1);
    LinkNode<Elemtype>* p2=Locate(pos2);
    Elemtype t=p1->data;
    p1->data=p2->data;
    p2->data=t;
}
template <class Elemtype>
void LinkList<Elemtype>::LinkSwap(LinkNode<Elemtype> *p1, LinkNode<Elemtype> *p2) {
    Elemtype t = p1->data;
    p1->data = p2->data;
    p2->data = t;
}
template<class Temp>
void LinkList<Temp>::Sort(){
    LinkNode<Temp> *p=Head;
    for (int i = 1; i <GetLength() ; ++i) {
        p=Locate(1);
        for(int j=1;j<=GetLength();j++)
            if(p->data>(p->next->data))
                LinkSwap(p,p->data);
        p=p->next;
    }
}
template <class Elemtype>
bool LinkList<Elemtype>::IsLoop(){
    LinkNode *slow=Head;
    LinkNode *fast=Head;
    while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}
template<class Temp>
bool LinkList<Temp>::IsPalindrome()
{
    int len = GetLength();
    if (len % 2 == 0)
    {
        Reverse((len / 2) + 1, len);
        LinkNode<Temp> *p1 = Locate(1);
        LinkNode<Temp> *p2 = Locate((len / 2) + 1);
        while (p2->next != NULL)
        {
            if (p1->data != p2->data)
            {
                return false;
            }
            p2 = p2->next;
            p1 = p1->next;
        }
        return true;
    }
    else
    {
        Reverse((len / 2) + 2, len);
        LinkNode<Temp> *p1 = Locate(1);
        LinkNode<Temp> *p2 = Locate((len / 2) + 2);
        while (p2->next != NULL)
        {
            if (p1->data != p2->data)
            {
                return false;
            }
            p2 = p2->next;
            p1 = p1->next;
        }
        return true;
    }
}
template <class Elemtype>
void LinkList<Elemtype>::swap(LinkList<Elemtype> &other) {
    using std::swap;
    swap(Head,other.Head);
}
template<typename Temp>
void swap(LinkList<Temp> & a, LinkList<Temp> & b)
{
    a.swap(b);
}

#endif