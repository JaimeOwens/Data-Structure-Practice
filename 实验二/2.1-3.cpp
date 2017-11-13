#include<iostream>
#define ERROR -1
#define OK 1
#define OVERFLOW -2 
using namespace std;
const int MAXSIZE=1000;
typedef int Status;
typedef int SElemType;
typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}Stack;
Status InitStack(Stack &s,int n){
	s.base=new SElemType[MAXSIZE];
	if(!s.base) return ERROR;
	s.top=s.base;
	s.stacksize=n;
	return OK;
}
Status Push(Stack &s,SElemType e){
	if(s.top-s.base==s.stacksize)
		return ERROR;
	*s.top++=e;
	return OK;
}
Status Pop(Stack &s,SElemType &e){
	if(s.top==s.base) return ERROR;
	e=*--s.top;
	return OK;
}
Status Top(Stack &s){
	if(s.top!=s.base)
		return *(s.top-1);
}
bool isFull(Stack s){
	return (s.top-s.base==s.stacksize);
}
bool isEmpty(Stack s){
	return (s.top==s.base);
}
int main(){
	int n;
	while(cin>>n){
		if(n==0) break;
		Stack s;
		SElemType e;
		InitStack(s,n);
		for(int i=0;i<n;i++){
			cin>>e;
			if(e!=-1){
				if(!isFull(s))
					Push(s,e);
			}
			else{
				if(isEmpty(s)){
					cout<<"POP ERROR"<<endl;
					exit(0);
				}
				else{
					Pop(s,e);
					cout<<e<<endl;
				}
			}
		}
	}
	return 0;
}
