#include<iostream>
using namespace std;
typedef int QElemType;
typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct LinkQueue{
	QueuePtr rear;
}LinkQueue;
void InitQueue(LinkQueue &Q){
	Q.rear=Q.rear->next;
	while(Q.rear!=Q.rear->next){
		QueuePtr s=Q.rear->next;
		Q.rear->next=s->next;
		delete s;
	}
}
bool EmptyQueue(LinkQueue Q){
	return Q.rear->next->next==Q.rear->next;
}
void Push(LinkQueue &Q,QElemType e){
	QueuePtr p=new QNode;
	p->data=e;
	p->next=Q.rear->next;
	Q.rear->next=p;
	Q.rear=p;
} 
void Pop(LinkQueue &Q,QElemType e){
	if(Q.rear->next->next==Q.rear)
		return;
	QueuePtr p=Q.rear->next->next;
	e=p->data;
	if(p==Q.rear){
		Q.rear=Q.rear->next;
		Q.rear->next=p->next;
	}
	else
		Q.rear->next->next=p->next;
	delete p;
}
int main(){
	int n1,n2;
	while(cin>>n1>>n2){
		if(n1==0&&n2==0) break;
		LinkQueue Q;
		InitQueue(Q);
		for(int i=0;i<n1;i++){
			QElemType temp;
			cin>>temp;
			Push(Q,temp);
		}
		for(int i=0;i<n2;i++){
			QElemType temp;
			Push(Q,temp);
			cout<<temp<<' ';
		}
		if(EmptyQueue(Q)) cout<<0<<endl;
		else cout<<1<<endl;
	}
	return 0;
}
