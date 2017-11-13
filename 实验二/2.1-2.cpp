#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
bool Plalindrome(char str[]){
	bool flag=true;
	stack<char> s;
	int len=strlen(str);
	for(int i=0;i<len/2;i++)
		s.push(str[i]);
	if(!len%2){
		for(int i=len/2;i<len;i++){
			char c=s.top();
			if(str[i]!=c){
				flag=false;
				break;
			}
			s.pop();	
		}
	}
	else{
		for(int i=(len+1)/2;i<len;i++){
			char c=s.top();
			if(str[i]!=c){
				flag=false;
				break;
			}
			s.pop();
		}
	}
	return flag;
}
int main(){
	char str[100];
	bool flag;
	while(cin>>str){
		if(str[0]=='0') break;
		if(Plalindrome(str))
			cout<<"YES"<<endl;
		else 
			cout<<"NO"<<endl;
	}
	return 0;
}
