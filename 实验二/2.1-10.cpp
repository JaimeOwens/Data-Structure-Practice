#include<iostream>
#include<stack>
#define FALSE -1
#define TRUE 1
using namespace std;
int Ack(int m,int n){
	stack<int> s;
	s.push(m);
	while(!s.empty()){
		m=s.top();
		s.pop();
		if(!m) n++;
		else if(!n&&m){
			m--;
			n=1;
			s.push(m);
		}
		else{
			n--;
			s.push(m-1);
			s.push(m);
		}
	}
	return n;
}
int main(){
	int m,n;
	while(cin>>m>>n){
		if(m==0&&n==0) break;
		cout<<Ack(m,n)<<endl;
	}
	return 0;
} 
