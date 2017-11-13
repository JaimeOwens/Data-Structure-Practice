#include<iostream>
#include<cstring> 
using namespace std;
void Reverse(char *str){
	char temp=*str;
	int len=strlen(str);
	*str=*(str+len-1);
	*(str+len-1)='\0';
	if(strlen(str)>1)
		Reverse(str+1);
	*(str+len-1)=temp;
}
int main(){
	char str[200];
	while(cin>>str){
		if(str[0]=='0') break;
		Reverse(str);
		cout<<str<<endl;
	}
	return 0;
}
