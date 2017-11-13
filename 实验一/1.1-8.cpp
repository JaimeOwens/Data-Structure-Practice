#include<iostream>
typedef int Elemtype;
using namespace std;
typedef struct Node{
	Elemtype data;
	int length;
	struct Node *next; 
}Node,*List;
void InitList(List &L) {
    L = new Node;
    L->next = NULL;
    L->length = 0;
}
void Print(List L) {
    //L=L->next;
	while(L->next){
		L = L->next;
        if(L->next)
			printf("%d ",L->data);
		else 
			printf("%d\n",L->data);	
	}
}
void Input(List &L,int n){
	List r=L;
	L->length=n;
	for(int i=0;i<n;i++){
		List p=new Node;
		scanf("%d",&p->data);
		p->next=NULL;
        r->next=p;
        r=p;
	}
	//Print(L);	
}
void DeleteinRange(List &L){
	int maxk,mink;
	List p=L->next;
	scanf("%d%d",&mink,&maxk);
	List pre;
	if(p->data>=mink){
		while(p&&p->data<=maxk){
			List q=p->next;
			p->next=q->next;
			delete q;
		}
	}
	else{
		while(p&&p->data<mink){
			pre=p;
			p=p->next;
		}
		while(p&&p->data<=maxk)
			p=p->next;
		List q=pre->next;
		pre->next=p;
		while(q!=p){
			List s=q->next;
			delete q;
			q=s;
		}
	}	
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		if(n==0) break;
		List La;
		InitList(La);
		Input(La,n);
		DeleteinRange(La);
		Print(La);
	}
	return 0; 
}

 
