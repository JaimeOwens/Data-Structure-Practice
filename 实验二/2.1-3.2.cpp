#include<iostream>
#define ERROR -1
#define OK 1
#define OVERFLOW -2 
using namespace std;
const int MAXSIZE=1000;
typedef int Status;
typedef int SElemType;
void InOutStack(int s[],int n){
	int top=0,x;
	for(int i=0;i<n;i++){
		cin>>x;
		if(x!=-1){
			if(top==MAXSIZE-1){
				cout<<"PUSH ERROR"<<endl;
				return;
			}
			else s[++top]=x;
		}
		else{
			if(top==0){
				cout<<"POP ERROR"<<endl;
				return;
			}
			else cout<<s[top--]<<endl;	
		}
	}
} 
int main(){
	int n;
	while(cin>>n){
		if(n==0) break;
		int s[MAXSIZE];
		InOutStack(s,n);
	}
	return 0;
}
