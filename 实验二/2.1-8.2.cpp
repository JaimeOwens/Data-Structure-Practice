#include<iostream>
typedef int ElemType;
const int MAXSIZE=500;
using namespace std;
typedef struct {
	ElemType *base;
	int front;
	int rear;
}Queue;
bool InitQueue(Queue &Q){
	Q.base=new ElemType[MAXSIZE];
	if(!Q.base) return false;
	Q.front=Q.rear=0;
	return true;
}
bool EnQueue(Queue &Q,ElemType e){
	if(Q.rear==(Q.front-1+MAXSIZE)%MAXSIZE)
		return false;
	Q.base[Q.front]=e;
	Q.front=(Q.front-1+MAXSIZE)%MAXSIZE;
	return true;
}
bool DeQueue(Queue &Q,ElemType &e){
	if(Q.front==Q.rear) return false;
	e=Q.base[Q.rear];
	Q.rear=(Q.rear-1+MAXSIZE)%MAXSIZE;
	return true;
}
int main(){
	int n;
	while(cin>>n){
		if(n==0) break;
		Queue Q;
		ElemType temp; 
		InitQueue(Q);
		for(int i=0;i<n;i++){
			cin>>temp;
			EnQueue(Q,temp);
		} 
		for(int i=0;i<n;i++){
			DeQueue(Q,temp);
			cout<<temp<<' ';
		}
		cout<<endl;
	}
	return 0;
}
