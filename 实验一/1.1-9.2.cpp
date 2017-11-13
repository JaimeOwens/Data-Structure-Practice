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
    q->prior->next=p;//p��ǰ����ǰ��֮���Ϊp  
    p->prior=q->prior;//p��ǰ��ָ����ǰ����ǰ����  
    q->next=p->next;//��p��ǰ���ĺ��Ϊp�ĺ�̡�  
    q->prior=p;//p����ǰ������  
    p->next->prior=q;//p�ĺ�̵�ǰ��ָ��ԭp��ǰ��  
    p->next=q;//p�ĺ��ָ����ԭ����ǰ��  
  	
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
