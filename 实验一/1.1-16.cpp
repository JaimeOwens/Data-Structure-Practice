#include<iostream>
using namespace std;
typedef struct Node{
	int index;
	int power;
}Node;
typedef struct Term{
	Node data;
	struct Term *next;
}Trem,*Expression;
void Print(Expression e){
	e=e->next;
	cout<<e->data->index<<'x^'<<e->data->power; 
	while(e->next){
		e=e->next;
		if(e->data->index>0)
			cout<<'+'<<e->data->index<<'x^'<<e->data->power;
		else
			cout<<e->data->index<<'x^'<<e->data->power; 
	} 
	cout<<endl;
}
void Input(Expression &e,n){
	Expression p=e;
	for(int i=0;i<n;i++){
		int index,power;
		Expression q=new Trem;
		cin>>index>>power;
		q->data->index=index;
		q->data->power=power;
		q->next=NULL;
		p->next=q;
		p=q;
	}
	Print(p);
}
void Sort(Expression &e){
	Expression p,q;
	int index_temp,power_temp;
	for(p=e;p;p=p->next){
		for(q=p->next;q;q=q->next){
			if(p->data->power<q->data->power){
				index_temp=p->data->index;
				p->data->index=q->data->index;
				q->data->index=index_temp;
				power_temp=p->data->power;
				p->data->power=q->data->power;
				q->data->power=power_temp;
			}
		}
	}
}
void Sort(Expression &e){
	Expression q=e->next,p,s;
	e->next=NULL;
	while(q){
		s=q;
		q=q->next;
		p=e;
		while(p->next&&p->next->data->power>=s->data->power)
			p=p->next;
		s->next=p->next;
		p->next=s;
	}
	Print(e);
}
void Add(Expression e1,Expression e2){
	
}
void Sub(Expression e1,Expression e2){
	
}
void Multiply(Expression e1,Expression e2){
	
}
int main(){
	int k;
	cin>>k;
	while(k--){
		int n1,n2;
		cin>>n1>>n2;
		Expression e1,e2;
		InitList(e1,n1);
		InitList(e2,n2);
		Input(e1);
		Input(e2);
		Sort(e1);
		Sort(e2);
		char Operator;
		cin>>Operator;
		switch(Operator){
			case '+':Add(e1,e2);
			case '-':Sub(e1,e2);
			case '*':Multiple(e1,e2);
		} 
	}
	return 0;
}
