//
// Created by lenovo on 2017/10/1.
//

#ifndef DOUBLELINKLIST_DOUBLELINKLIST_H
#define DOUBLELINKLIST_DOUBLELINKLIST_H

#include <iostream>
#include <cstring>
using namespace std;
typedef struct Dnode{
    void *data;
    struct Dnode *pre;
    struct Dnode *next;
}Dnode;

typedef struct Dlist{
    int size;
    void (*destroy)(void *data);
    void (*match)(const void *key1,const void *key2);
    Dnode *head;
    Dnode *tail;
}Dlist;

void Dlist_init(Dlist *List,void (*destroy)(void *data));
void Dlist_destroy(Dlist *list);
int Dlist_insert_pre(Dlist *list,Dnode *node,const void *data);
int Dlist_insert_next(Dlist *list,Dnode *node,const void *data);
int Dlist_remove(Dlist *list,Dnode *node,void **data);

#define Dlist_size(list) ((list)->size)
#define Dlist_head(list) ((list)->head)
#define Dlist_tail(list) ((list)->tail)
#define Dlist_is_head(node) ((node)->pre==NULL?true:false);
#define Dlist_is_tail(node) ((node)->next==NULL?true:false);
#define Dlist_data(node) ((node)->data)
#define Dlist_pre(node) ((node)->pre)
#define Dlist_next(node) ((node)->next)

#endif //DOUBLELINKLIST_DOUBLELINKLIST_H
