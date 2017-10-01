#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "DoubleLinkList.h"
#include "DoubleLinkList.cpp"
using namespace std;

typedef struct Cuboid{
    int length;
    int width;
    int height;
}Cuboid;

Cuboid *cube_instance(const int length,const int width,const int height){
    Cuboid *cb_ptr;
    cb_ptr=(Cuboid *)malloc(sizeof(Cuboid));
    if(cb_ptr==NULL) return NULL;
    cb_ptr->length=length;
    cb_ptr->height=height;
    cb_ptr->width=width;
    return cb_ptr;
}
void destory(void *data){
    free(data);
    return ;
}

int main(){
    int i;
    Dlist dlist;
    Dnode *p=NULL;
    Cuboid *cb1_ptr,*cb2_ptr,*cb3_ptr,*cb4_ptr,*cb5_ptr;
    Cuboid *cb_ptr;
    cb1_ptr=cube_instance(1,2,3);
    cb2_ptr=cube_instance(6,10,8);
    cb3_ptr=cube_instance(5,20,30);
    cb4_ptr=cube_instance(17,100,25);
    cb5_ptr=cube_instance(3,6,9);
    void (*p1)(void *data)=destory;

    Dlist_insert_next(&dlist, NULL, (void *)cb1_ptr );  //insert data:cb1
    p = Dlist_head(&dlist); //get the address of the first element
    Dlist_insert_next(&dlist, p , (void *)cb2_ptr );   //insert data:cb2    cb1- cb2
    p = Dlist_next(p);          //pointer to the element containing the data cb2.
    Dlist_insert_pre(&dlist, p, (void *)cb3_ptr );    //insert data:cb3   cb1- cb3- cb2
    Dlist_insert_pre(&dlist, p, (void *)cb4_ptr );    //insert data:cb4   cb1- cb3- cb4- cb2
    p = Dlist_pre(p);          //pointer to the element conatining the data cb4.
    Dlist_insert_pre(&dlist, p, (void *)cb5_ptr );      //insert data:cb5   cb1- cb3- cb5- cb4- cb2

    p=Dlist_head(&dlist);
    p=Dlist_next(p);
    p=Dlist_next(p);
    Dlist_remove(&dlist,p,(void **)&cb_ptr);
    printf("the data of the third element:length=%d,width=%d,height=%d",
        cb_ptr->length,cb_ptr->width,cb_ptr->height);
    destory(cb_ptr);

    printf("After remove the third element:\n");
    p=Dlist_head(&dlist);
    for(i=0;i<Dlist_size(&dlist);i++){
        cb_ptr=(Cuboid *)Dlist_data(p);
        printf("i=%d:",i);
        printf("length = %d, width = %d, height = %d\n",
               cb_ptr->length,
               cb_ptr->width,
               cb_ptr->height);
        p = Dlist_next(p);
    }
    Dlist_destroy(&dlist);
    printf("after destroy the list,its size = %d\n", Dlist_size(&dlist));
    return 0;
}
