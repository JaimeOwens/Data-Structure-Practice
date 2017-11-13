#include<iostream>
using namespace std;
typedef int ElemType;
const int MAXSIZE=1000; 
typedef struct{
	ElemType *base;
	int front,rear;
}Queue;
bool InitQueue(Queue &Q){
	Q.base=new ElemType[MAXSIZE];
	if(!Q.base) return false;
	Q.front=Q.rear=0;
	return true;
}
bool EnQueueFront(Queue &Q,ElemType e){
	if(Q.rear==(Q.front-1+MAXSIZE)%MAXSIZE)//full
		return false;
	Q.base[Q.front]=e;
	Q.front=(Q.front-1+MAXSIZE)%MAXSIZE;
	return true;
}
bool EnQueueBack(Queue &Q,ElemType e){
	if(Q.rear==(Q.front-1+MAXSIZE)%MAXSIZE)//full
		return false;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1+MAXSIZE)%MAXSIZE;	
	return true;
}
bool DeQueueBack(Queue &Q,ElemType &e){
	if(Q.rear==Q.front)//empty
		return false;
	Q.rear=(Q.rear-1+MAXSIZE)%MAXSIZE;
	e=Q.base[Q.rear];
	return true;
}
bool DeQueueFront(Queue &Q,ElemType &e){
	if(Q.rear==Q.front)//empty
		return false;
	Q.front=(Q.front+1+MAXSIZE)%MAXSIZE;
	e=Q.base[Q.front];
}
int main(){
	int n;
	while(cin>>n){
		if(n==0) break;
		Queue Q;
		ElemType temp; 
		ElemType ans[200];
		InitQueue(Q);
		for(int i=0;i<n;i++){
			cin>>temp;
			//EnQueueFront(Q,temp);
			EnQueueBack(Q,temp);
		} 
		for(int i=0;i<n-1;i++){
			//DeQueueFront(Q,temp);
			DeQueueBack(Q,temp);
			cout<<temp<<' ';
		}
		//DeQueueFront(Q,temp);
		DeQueueBack(Q,temp);
		cout<<temp<<endl;
	}
	return 0;
}


