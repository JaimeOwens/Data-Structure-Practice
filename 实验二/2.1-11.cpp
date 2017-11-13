#include<iostream>
using namespace std;
typedef struct Node{
	int data;
	struct Node *next;
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
		t->next=NULL;
		p->next=t;
		p=t;
	}
}
int Max(List L){
	if(!L->next) return L->data;
	else{
		int max=Max(L->next);
		return L->data>=max?L->data:max;
	}
} 
int main(){
	int n;
	while(cin>>n){
		if(n==0) break;
		List L;
		InitList(L);
		Input(L,n);	
		L=L->next;
		//cout<<L->data;
		cout<<Max(L)<<endl;
	}
	return 0;
}
