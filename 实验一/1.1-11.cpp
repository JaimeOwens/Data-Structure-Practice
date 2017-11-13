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
void Reverse_Find(List L){
	int temp,cnt=0;
	cin>>temp;
	temp=L->length-temp+1;
	while(L->next){
		L=L->next;
		cnt++;
		if(cnt==temp)
			cout<<L->data<<endl;
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
		Reverse_Find(La);
	}
	return 0; 
}

 
