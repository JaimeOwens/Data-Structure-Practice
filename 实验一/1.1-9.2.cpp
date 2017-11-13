#include<iostream> 
using namespace std;
 typedef struct DLnode{  
    int data;  
    int number;
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
    	if(p->next==L)
    		cout<<p->data<<endl;
    	else
        	printf("%d ",p->data);
        p=p->next;  
    }  
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
		s->number=i;  
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
    while(scanf("%d",&n)&&n!=0){
    	LinkList L;  
    	InitList(L);
		CreateList(L,n);  
   		//TraveList(L);    
    	//struct DLnode *s;  
    	//s=new DLnode;  
    	//scanf("%d",&s->data);
		int temp;  
		scanf("%d",&temp);
    	struct DLnode *p;  
    	p=L->next;  
    	if(temp!=1){
    		while(p!=L){  
        		if(p->number==temp-1){  
            		Change(p); 
            		break;  
        		}
				else p=p->next;  	  
    		} 	
			TraveList(L); 
		}
    	else{
    		int t=p->data;
    		while(p->next!=L){
    			p=p->next;
    			cout<<p->data<<' ';
			}
			cout<<t<<endl;
		}
	}    
   	return 0;
 }  
