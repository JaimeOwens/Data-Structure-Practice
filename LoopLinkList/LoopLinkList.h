//
// Created by Jaime on 2017/10/6.
//

#ifndef LOOPLINKLIST_LOOPLINKLIST_H
#define LOOPLINKLIST_LOOPLINKLIST_H

#include <iostream>
#include <cstdio>
using namespace std;
template <typename ElemType>
class LoopLinkList{
public:
    struct Item{
        friend class LoopLinkList<ElemType>;
        private:
            ElemType m_elem;
            Item *m_pNext;
        public:
            Item(const ElemType &e,Item *pNext):m_elem(e),m_pNext(pNext){};
            ElemType getElem() const{ return m_elem; }
            Item *getNext() const { return m_pNext;}
            void setElem(const ElemType &e){ m_elem=e; }
            void setNext(Item *p){ m_pNext=p; }
    };
    //////////////////////////////////////////////////////
    typedef typename LoopLinkList<ElemType> Type;
    typedef Item ItemType;
    /////////////////////////////////////////////////////
    LoopLinkList();
    LoopLinkList(const LoopLinkList *rhs);
    LoopLinkList &operator =(const LoopLinkList &rhs);
    void InsertHead(const ElemType &e);
    void InsertTail(const ElemType &e);
    void InsertNext(Item *p,const ElemType &e);
    void DeleteHead();
    void DeleteTail(Item * pPre=NULL);
    void DeleteItem(Item *p,Item *pPre=NULL);
    void DeleteItem(const ElemType &e);
    void DeleteAll();
    Item *getTail()const ;
    bool isEmpty()const ;
    bool isOneItem()const ;
    void dump() const;//debug
private:
    Item *m_pTail;
    ////////////////////////////////////////////////////
    Item *newItem(const ElemType &e,Item *pNext=NULL);
    void ChangeAfterInsertFirstItem(Item *p);
    void DeleteOnlyOne();
    Item *FindPreItem(Item *p);
    void copy(const LoopLinkList &rhs);
};
#endif //LOOPLINKLIST_LOOPLINKLIST_H
