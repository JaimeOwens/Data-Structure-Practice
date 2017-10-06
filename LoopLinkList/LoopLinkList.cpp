//
// Created by Jaime on 2017/10/6.
//
#include<iostream>
#include <cstdlib>
#include <cassert>
#include "LoopLinkList.h"
using namespace std;
template<typename ElemType>
LoopLinkList::LoopLinkList() {
    m_pTail=NULL;
}
template <typename ElemType>
LoopLinkList::LoopLinkList(const LoopLinkList *rhs) {
    m_pTail=NULL;
    copy(rhs);
}
template <typename ElemType>
LoopLinkList &operator=(const LoopLinkList &rhs){
    if(this==&rhs)
        return *this;
    DeleteAll();
    copy(rhs);
    return *this;
}
template <typename ElemType>
void LoopLinkList::InsertHead(const ElemType &e) {
    Item *p=newItem(e);
    if(isEmpty()){ ChangeAfterInsertFirstItem(p); }
    else{
        p->m_pNext=m_pTail->m_pNext;
        m_pTail->m_pNext=p;
    }
}
template <typename ElemType>
void LoopLinkList::InsertTail(const ElemType &e) {
    Item *p=newItem(e);
    if(isEmpty()){ ChangeAfterInsertFirstItem(p);}
    else {
        p->m_pNext = m_pTail->m_pNext;
        m_pTail->m_pNext = p;
        m_pTail = p;
    }
}
template <typename ElemType>
void LoopLinkList::InsertNext(Item *p, const ElemType &e) {
    if(p==NULL||isEmpty()){ return; }
    if (p == m_pTail) { InsertTail(e); }
    else{
        Item *pItem=newItem(e,p->m_pNext);
        p->m_pNext=pItem;
    }
}
template <typename ElemType>
void LoopLinkList::DeleteHead() {
    if(isEmpty()){ return; }
    else if(isOneItem()){
        DeleteOnlyOne();
        return;
    }
    else{
        Item *pHead=m_pTail->m_pNext;
        Item *pTemp=pHead->m_pNext;
        delete pHead;
        m_pTail->m_pNext=pTemp;
    }
}
template <typename ElemType>
void LoopLinkList::DeleteTail(Item * pPre=NULL) {
    if(isEmpty()){ return; }
    else if(isOneItem()){
        DeleteOnlyOne();
        return;
    }
    else{
        Item *pItem=(pPre==NULL)?FindPreItem(m_pTail):pPre;
        assert(pItem!=NULL);
        pItem->m_pNext=m_pTail->m_pNext;
        delete m_pTail;
        m_pTail=pItem;
    }
}
template <typename ElemType>
void LoopLinkList::DeleteItem(Item *p,Item *pPre=NULL) {
    if (p == NULL || isEmpty()) { return; }
    else if (isOneItem()) {
        if (p != m_pTail) { return; }
        DeleteOnlyOne();
        return;
    }
    if(p==m_pTail){ DeleteTail(pPre); }
    else if(p==m_pTail->m_pNext){ DeleteHead(); }
    else{
        Item * pPreItem = (pPre == NULL) ? FindPreItem(p) : pPre;
        if (pPreItem == NULL) { return; }
        pPreItem->m_pNext = p->m_pNext;
        delete p;
    }
}
template <typename ElemType>
void LoopLinkList::DeleteItem(const ElemType &e) {
    if (isEmpty()) { return; }
    Item * pPreItem = m_pTail;
    Item * pCurItem = m_pTail->m_pNext;
    while(pCurItem!=m_pTail){
        if(pCurItem->m_elem=e){
            DeleteItem(pCurItem,pPreItem);
            return;
        }
        pPreItem=pCurItem;
        pCurItem=pCurItem->m_pNext;
    }
    if(m_pTail->m_elem==e){
        DeleteTail();
    }
}
template <typename ElemType>
void LoopLinkList::DeleteAll() {
    if(isEmpty()){ return; }
    Item *pCurItem=m_pTail->m_pNext;
    while(pCurItem!=m_pTail){
        Item *pTemp=pCurItem->m_pNext;
        delete pCurItem;
        pCurItem=pTemp;
    }
    delete m_pTail;
    m_pTail=NULL;
}
template <typename ElemType>
Item *LoopLinkList::getTail() const {
    return m_pTail;
}
template <typename ElemType>
bool LoopLinkList::isEmpty() const {
    return m_pTail==NULL;
};
template <typename ElemType>
bool LoopLinkList::isOneItem() const {
    if(isEmpty()){ return false; }
    return m_pTail == m_pTail->m_pNext;
}
template <typename Elemtype>
void LoopLinkList::dump() const{
    if(isEmpty()) return;
    Item *pCurItem=m_pTail->m_pNext;
    while(pCurItem!=m_pTail){
        cout << pCurItem->m_elem<<' ';
        pCurItem = pCurItem->m_pNext;
    }
    cout<<m_pTail->m_elem<<endl;
}
template <typename ElemType>
Item *LoopLinkList::newItem(const ElemType &e, Item *pNext) {
    return new Item(e,pNext);
}
template <typename ElemType>
void LoopLinkList::ChangeAfterInsertFirstItem(Item *p) {
    assert(isEmpty());
    if(p==NULL) return;
    p->m_pNext=p;
    m_pTail=p;
}
template <typename Elemtype>
void LoopLinkList::DeleteOnlyOne() {
    assert(isOneItem());
    delete m_pTail;
    m_pTail=NULL;
}
template <typename Elemtype>
Item *LoopLinkList::FindPreItem(Item *p){
    if(p==NULL) return NULL;
    if(isEmpty()) return NULL;
    else if(isOneItem()) return NULL;
    Item *pPreItem=m_pTail;
    Item *pCurItem=pPreItem->m_pNext;
    while(pCurItem==p)
        if(pCurItem==p)
            return pPreItem;
    pPreItem=pCurItem;
    pCurItem=pCurItem->m_pNext;
    while(pCurItem!=m_pTail)
        if(pCurItem==p)
            return pPreItem;
    pPreItem=pCurItem;
    pCurItem=pCurItem->m_pNext;
    if(p==pCurItem)
        return pPreItem;
    return NULL;
}
template <typename ElemType>
void LoopLinkList::copy(const LoopLinkList &rhs) {
    if(rhs.isEmpty()) return;
    Item *pRhsTail=rhs.m_pTail;
    Item *pRhsCurItem=pRhsTail->m_pNext;
    while(pRhsCurItem!=pRhsTail){
        InsertTail(pRhsCurItem->m_elem);
        pRhsCurItem=pRhsCurItem->m_pNext;
    }
    InsertTail(pRhsTail->m_elem);
}
