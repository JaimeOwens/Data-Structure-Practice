#include<iostream>
using namespace std;
typedef struct{
	string number;
	string name;
	float price;
}BOOK;
typedef struct LNode{
	BOOK data;
	struct LNode *next; 
}LNode,*LinkList;
void InitList(LinkList &L){
	L=new LNode;
	L->next=NULL;
} 
void Print(LinkList L){
	LinkList p=L->next;
	while(p!=NULL){
		cout<<p->data.number<<" "<<p->data.name<<" ";
		printf("%.2f\n",p->data.price);
		p=p->next;
	}
}
void Input(LinkList &L){
	int n;
	cin>>n;
	LinkList r;
	LinkList p;
	r=L;
	while(n--){
		p=new LNode;
		cin>>p->data.number>>p->data.name>>p->data.price;
		p->next=NULL;
		r->next=p;
		r=p;
	}
}
void Find(LinkList L){
	int m;
	cin>>m;
	while(m!=0){
		LinkList LL;
		LL=new LNode;
		LL->next=NULL;
		LinkList p=LL;
		int n=0;
		string name;
		cin>>name;
		LinkList q=L->next;
		while(q!=NULL){
			if(q->data.name==name){
				n++;
				LinkList m=new LNode;
				m->data=q->data;
				m->next=NULL;
				p->next=m;
				p=p->next;
			}
			q=q->next;
		}
		if(n!=0){
			cout<<n<<endl;
			Print(LL);
		}
		else
			cout<<"no"<<endl;
		m--;
	}
}
int main(){
	LinkList L;
	InitList(L);
	Input(L);
	Find(L);
	return 0;
}

