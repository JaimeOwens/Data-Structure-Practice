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
    q->prior->next=p;//p��ǰ����ǰ��֮���Ϊp  
    p->prior=q->prior;//p��ǰ��ָ����ǰ����ǰ����  
    q->next=p->next;//��p��ǰ���ĺ��Ϊp�ĺ�̡�  
    q->prior=p;//p����ǰ������  
    p->next->prior=q;//p�ĺ�̵�ǰ��ָ��ԭp��ǰ��  
    p->next=q;//p�ĺ��ָ����ԭ����ǰ��  
  
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

