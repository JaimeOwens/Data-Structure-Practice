#include<cstdio>  
#define MAX 100  
 typedef struct DLnode{  
    int data;  
    struct DLnode *prior;  
    struct DLnode *next;  
 }DLnode,*LinkList;  
   
 int InitList(LinkList &L){  
    L=new DLnode;  
    L->next=L;  
    L->prior=L;  
    return 1;  
 }  
   
 void TraveList(LinkList L){  
    struct DLnode *p;  
    p=L->next;  
    while(p!=L){  
        printf("%d ",p->data);  
        p=p->next;  
    }  
    printf("\n");  
 }  
   
 int ListLength(LinkList &L){  
    struct DLnode *p;  
    int length=0;  
    while(p){  
        ++length;  
        p=p->next;  
    }  
    return length;  
 }  
   
 void CreateList(LinkList &L,int &n){  
    L=new DLnode;  
    L->next=L;  
    L->prior=L;  
    struct DLnode *p;  
    p=L;  
    for(int i=0;i<n;i++){  
        struct DLnode *s;  
        s=new DLnode;  
        scanf("%d",&s->data);  
        p->next=s;  
        s->next=L;  
        s->prior=p;  
        p=s;  
    }  
 }  
  
void Change(LinkList p){  
    struct DLnode *q;  
    q=p->prior;  
    q->prior->next=p;//p的前驱的前驱之后继为p  
    p->prior=q->prior;//p的前驱指向其前驱的前驱。  
    q->next=p->next;//∥p的前驱的后继为p的后继。  
    q->prior=p;//p与其前驱交换  
    p->next->prior=q;//p的后继的前驱指向原p的前驱  
    p->next=q;//p的后继指向其原来的前驱  
  
}  
   
 int main(){  
    int n;  
    while(~scanf("%d",&n)){
    	if(n==0) break;
		LinkList L;  
    	CreateList(L,n);  
    	//struct DLnode *s;  
    	//s=new DLnode;  
    	//scanf("%d",&s->data);
		int temp;
		scanf("%d",&temp);  
    	struct DLnode *p;  
    	p=L->next;
		int i=0  ;
    	while(p!=L){  
    		i++;
        	if(i==temp){  
            	Change(p);  
            	break;  
        	}
            p=p->next;    
    	}  
    	TraveList(L);  
	}
    return 0;
 }  

