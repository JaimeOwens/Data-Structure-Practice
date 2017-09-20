//
// Created by jaime on 17-9-19.
//
#ifndef LINKLIST_LINKLIST_H
#define LINKLIST_LINKLIST_H

#include <iostream>
using namespace std;
template <class Elemtype>
struct LinkNode{
    Elemtype data;
    LinkNode<Elemtype> *next;
};

template<class Elemtype>
class LinkList{
private:
   LinkNode<Elemtype> *Head;
public:
    LinkList();
    LinkList(const Elemtype&item);
    LinkList(const LinkList&copy);
    LinkList<Elemtype>&operator=(LinkList<Elemtype>&List);
    ~LinkList();
    void CreateList(int length);//创建链表
    void SetHead(LinkList<Elemtype> *p);//创建链表头部的值
    void DestroyList();//销毁链表
    void ClearList();
    int GetLength() const;//链表长度
    bool IsLoop();//链表是否有环
    bool IsEmpty();//链表是否为空
    bool IsPalindrome();//链表是否回文
    bool GetElem(int index,Elemtype &e);//获取元素的值
    void SetHead(LinkNode<Elemtype> *p);//设置首元结点
    LinkNode<Elemtype>* Find(Elemtype &item);// 返回第一个找到的满足该数据元素的结点对应的指针
    LinkNode<Elemtype>* Locate(int pos);//返回第pos个数据元素对于的指针
    bool InsertAt(int index,Elemtype e);//插入元素
    bool RemoveAt(int index,Elemtype &e);//移除元素
    void show() const;//打印链表
    void Sort();//链表排序
    void Reverse();
    void Reverse(int nstart, int nend);//链表逆置
    void LinkSwap(int pos1, int pos2);
    void LinkSwap(LinkNode<Elemtype> * p1, LinkNode<Elemtype> * p2);//交换两个结点内容
    void swap(LinkList<Elemtype> & other);
    void swap(LinkList<Elemtype> & a, LinkList<Elemtype> & b);
};
#endif