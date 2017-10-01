//
// Created by lenovo on 2017/10/1.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "DoubleLinkList.h"
using namespace std;

void Dlist_init(Dlist *List,void (*destroy)(void *data)){
    List->size=0;
    List->destroy=destroy;
    List->head=NULL;
    List->tail=NULL;

    return ;
}
void Dlist_destroy(Dlist *list){
    void *data;
    while(Dlist_size(list)>0){
        if(Dlist_remove(list,Dlist_tail(list),(void **)&data)==0&&list->destroy!=NULL){
            list->destroy(data);
        }
    }
    memset(list,0,sizeof(Dlist));
    return ;
}
int Dlist_insert_pre(Dlist *list,Dnode *node,const void *data){
    Dnode *newnode;
    if(node==NULL&&Dlist_size(list)!=0) return -1;
    newnode=(Dnode *)malloc(sizeof(Dnode));
    if(newnode==NULL) return -1;
    newnode->data=(void *)data;
    if(Dlist_size(list)==0){
        list->head=newnode;
        list->tail=newnode;
        newnode->pre=NULL;
        newnode->next=NULL;
    }
    else{
        newnode->next=node;
        newnode->pre=node->pre;
        if(node->pre=NULL) list->head=newnode;
        else node->pre->next=newnode;
        node->pre=newnode;
    }
    list->size++;
}
int Dlist_insert_next(Dlist *list,Dnode *node,const void *data){
    Dnode *newnode;
    if(node==NULL&&Dlist_size(list)!=0) return -1;
    newnode=(Dnode *)malloc(sizeof(Dnode));
    if(newnode==NULL) return -1;
    newnode->data=(void *)data;
    if(Dlist_size(list)==0){
        newnode->pre=NULL;
        newnode->next=NULL;
        list->head=newnode;
        list->tail=newnode;
    }
    else{
        newnode->pre=node;
        newnode->next=node->next;
        if(node->next=NULL) list->tail=newnode;
        else node->next->pre=newnode;
        node->next=newnode;
    }
    list->size++;
    return 0;
}
int Dlist_remove(Dlist *list,Dnode *node,void **data){
    if(node==NULL||Dlist_size(list)==0) return -1;
    *data=node->data;
    if(node==list->head){
        list->head=node->next;
        if(list->head==NULL) list->tail=NULL;
        else node->next->pre=NULL;
    }
    else{
        node->pre->next=node->next;
        if(node->next==NULL) list->tail=node->pre;
        else node->next->pre=node->pre;
    }
    free(node);
    list->size--;
    return 0;
}
