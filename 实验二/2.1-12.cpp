#include<iostream>
using namespace std;
typedef struct Node{
	int data;
	struct Node *next;
	bool number;
}Node,*List;
void InitList(List &L){
	L=new Node;
	L->next=NULL;
}
void Input(List &L,int n){
	List p=L;
	for(int i=0;i<n;i++){
		List t=new Node;
		cin>>t->data;
		t->number=true;
		t->next=NULL;
		p->next=t;
		p=t;
	}
}
float Average(List &L,int n){
	if(!L->next){
		return ((float)L->data/n);
	} 
	else{
		float aver=Average(L->next,n);
		if(!L->number) printf("%.2f\n",aver);
		return aver+((float)L->data/n);
	}
} 
int main(){
	int n;
	while(cin>>n){
		if(n==0) break;
		List L;
		InitList(L);
		Input(L,n);
		Average(L,n);
	}
	return 0;
}
