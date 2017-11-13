#include<iostream>
#include<set>
typedef int Status;
typedef int Elemtype;
#define ERROR -1
#define OK 1
#define OVERFLOW -2
const int MAXSIZE=100;
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
}
void AbsoluteDistinct(List &head){
	struct Node *p,*q,*s;
	p = head;
	while(p->next!=NULL)
	{
   		p=p->next;q=p;
  		while(q->next!=NULL)
  		{
   			if(q->next->data == p->data||q->next->data==-p->data)
   			{
         		s = q->next;
 				q->next = s->next;
 				delete s;
   			}
			else
          		q=q->next;
  		}
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
		AbsoluteDistinct(La);
		Print(La);
	}
	return 0; 
}

 
