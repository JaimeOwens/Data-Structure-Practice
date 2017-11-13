#include<iostream>
#include<cstdlib>
using namespace std;
#define OK 1;
#define ERROR -1;
#define OVREFLOW -2; 
typedef int Status;
typedef int SElemType;  
typedef struct{
  	int top[2], bot[2];	//栈顶和栈底指针
   	SElemType *V;	//栈数组
   	int m;	//栈最大可容纳元素个数
}DStack;
void Test(DStack s,int n){
	for(int i=0;i<n;i++)
		cout<<s.V[i]<<' ';
	cout<<endl;
}
Status InitStack(DStack &s,int n){
	s.V=new SElemType[n];
	s.bot[0]=-1;
	s.bot[1]=n;
	s.top[0]=-1;
	s.top[1]=n;
	return OK;
}
Status Push(DStack &s,int i,int e){
	if(s.top[1]-s.top[0]==1)
		return ERROR;
	if(i==0)
		s.V[++s.top[0]]=e;
	else
		s.V[--s.top[1]]=e;
	return OK;
}
int Pop(DStack &s,int i,int e){
	if(s.top[i]==s.bot[i])
		return ERROR;
	if(i==0)
		e=s.V[s.top[0]--];
	else
		e=s.V[s.top[1]++];
	return e;
}
bool isEmpty(DStack s,int i){
	//return (s.top[i]==s.bot[i]);
	if(s.top[i]==s.bot[i])
		return true;
	else
		return false;
}
bool isFull(DStack s){
	//return (s.top[0]+1==s.top[1]);
	if(s.top[0]+1==s.top[1])
		return true;
	else
		return false;
}
int main(){
	int n;
	while(cin>>n){
		if(n==0) break;	
		DStack s;
		InitStack(s,n);
		int e0,e1,d0,d1,temp;
		cin>>e0>>e1>>d0>>d1;
		for(int i=0;i<e0;i++){
			cin>>temp;
			Push(s,0,temp);	
		}
		//Test(s,n);
		for(int i=0;i<e1;i++){
			cin>>temp;
			Push(s,1,temp);
		}
		//Test(s,n);
		if(isFull(s)) cout<<1<<endl;
		else cout<<0<<endl;
		for(int i=0;i<d0;i++){
			int e;
			cout<<Pop(s,0,e)<<' ';
		}
		if(isEmpty(s,0)) cout<<0<<endl;
		else cout<<1<<endl;
		for(int i=0;i<d1;i++){
			int e;
			cout<<Pop(s,1,e)<<' ';
		}
		if(isEmpty(s,1)) cout<<0<<endl;
		else cout<<1<<endl;
	}
	return 0;
}
