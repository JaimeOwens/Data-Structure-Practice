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
	//Print(L);	
}
void Distinct(List &head){
	struct Node *p,*q,*s;
	p = head->next;
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
    //return head;
}
void Merge(List &La,List &Lb,List &Lc){
	List pa=La->next;
	List pb=Lb->next;
	List pc;
	Lc=pc=La;
	while(pa&&pb){
		if(pa->data<pb->data){
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else if(pa->data>pb->data){
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
		else{
			pc->next=pa;
			pc=pa;
			pa=pa->next;
			List q=pb->next;
			delete pb;
			pb=q;
		}		
	}
	pc->next=pa?pa:pb;
	delete Lb;
}
int main(){
	int n1,n2;
	while(cin>>n1>>n2){
		if(n1==0||n2==0)
			break;
		List La;
		List Lb;
		List Lc;
		InitList(La);
		InitList(Lb);
		InitList(Lc); 
		Input(La,n1);
		Input(Lb,n2);
		Merge(La,Lb,Lc);
		//Print(Lc);
		Distinct(Lc);
		Print(Lc);
	}
	return 0; 
}

 
