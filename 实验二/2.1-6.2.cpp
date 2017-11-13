#include<iostream>
#include<cstdlib>
#define FALSE -1
#define TRUE 1
using namespace std;
typedef int ElemType;
typedef int Status;
typedef struct LNode{
	ElemType data;
	struct LNode *next; 
}LNode,*LinkList;
typedef LinkList Queue;
Status InitQueue(Queue &rear){
	rear=(Queue)malloc(sizeof(LNode));
	if(!rear) return FALSE;
	rear->next=rear;
	return TRUE;
}
Status Push(Queue &rear,ElemType x){
	Queue head,p;
	head=rear->next;
	p=(Queue)malloc(sizeof(LNode));
	if(!p) return FALSE;
	p->data=x;
	p->next=head;
	rear->next=p;
	rear=p;
	return TRUE;
} 
Status Pop(Queue &rear,ElemType &x){
	Queue head,p;
	head=rear->next;
	if(head==rear) return FALSE;
	p=head->next;
	x=p->data; 
	head->next=p->next;
	delete p;
	return TRUE;
}
int main(){
	int n1,n2;
	while(cin>>n1>>n2){
		if(n1==0&&n2==0) break;
		Queue q;
		InitQueue(q);
		for(int i=0;i<n1;i++){
			ElemType temp;
			cin>>temp;
			Push(q,temp);
			//Pop(q,temp);
			//cout<<temp<<' ';
		}
		for(int i=0;i<n2;i++){
			ElemType temp;
			Pop(q,temp);
			cout<<temp<<' ';
		} 
		if(n1==n2) cout<<0<<endl;
		else cout<<1<<endl;
	}
	return 0;
}

