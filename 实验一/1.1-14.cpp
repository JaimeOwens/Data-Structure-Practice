#include<iostream>
typedef char Elemtype;
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
			cout<<L->data<<' ';
		else 
			cout<<L->data;	
	}
	cout<<endl;
}
void Input(List &L,int n){
	List r=L;
	L->length=n;
	for(int i=0;i<n;i++){
		List p=new Node;
		cin>>p->data;
		p->next=NULL;
        r->next=p;
        r=p;
	}
	//Print(L);	
}
void FindCommon(List L1,List L2){
	int len1=L1->length,len2=L2->length;
	List p,q;
	p=L1;
	//Print(p);
	q=L2;
	//Print(q);
	for(p=L1;len1>len2;len1--)
		p=p->next;
	for(q=L2;len1<len2;len2--)
		q=q->next;
	//Print(p);
	//Print(q);
	while(p->next&&q->next->data!=p->next->data)
		p=p->next,q=q->next;
	//Print(p);
	//Print(q);
	cout<<p->next->data<<endl;	 
}
int main(){
	int n1,n2;
	while(cin>>n1>>n2){
		if(n1==0||n2==0)
			break;
		List La;
		List Lb;
		InitList(La);
		InitList(Lb);
		Input(La,n1);
		Input(Lb,n2);
		FindCommon(La,Lb);
	}
	return 0; 
}

 
