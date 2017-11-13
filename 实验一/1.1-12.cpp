#include<iostream>
typedef int Elemtype;
using namespace std;
typedef struct Node{
	Elemtype data;
	int length;
	struct Node *next;
	bool negative; 
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
		if(L->negative)
			cout<<'-'<<L->data<<' ';
		else
			cout<<L->data<<' ';
	}
	cout<<endl;
}
void Input(List &L,int n){
	List r=L;
	L->length=n;
	for(int i=0;i<n;i++){
		List p=new Node;
		cin>>p->data;
		if(p->data<0)
			p->negative=true;
		else
			p->negative=false;
		p->next=NULL;
        r->next=p;
        r=p;
	}
	Print(L);	
}
void AbsoluteValue(List &L){
	while(L->next){
		L=L->next;
		if(L->negative)
			L->data=-L->data;
		Print(L);
	}
}
void AbsoluteValueDelete(List &L){
	List p,q,s;
	p = L->next;
	while(p->next!=NULL)
	{
   		q=p;
  		while(q->next!=NULL)
  		{
   			if(q->next->data == p->data)
   			{
         		s = q->next;
 				q->next = s->next;
 				delete s;
   			}
			else
          		q=q->next;
  		}
		p=p->next;
	}
}
int main(){
	int n1,n2;
	while(cin>>n1){
		if(n1==0)
			break;
		List La;
		InitList(La);
		Input(La,n1);
		AbsoluteValue(La);
		//AbsoluteValueDelete(La);
		//Print(La);
	}
	return 0; 
}

 
