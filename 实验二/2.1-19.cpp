#include<iostream>
#include<cstring>
using namespace std;
void Insert(char *s,char *t,int pos){
	int lens=strlen(s),lent=strlen(t);
	int i,s_cnt=0,t_cnt=0;
	char str[200];
	i=0;
	for(;i<pos-1;i++)
		str[i]=s[s_cnt++];
	for(;i<lent+pos-1;i++)
		str[i]=t[t_cnt++];
	for(;i<lens+lent;i++)
		str[i]=s[s_cnt++];	
	for(int i=0;i<strlen(str)-2;i++)
		cout<<str[i];
	cout<<endl;
}
int main(){
	int pos;
	while(cin>>pos){
		if(pos==0) break;
		char s[200],t[200];
		cin>>s;
		cin>>t;
		Insert(s,t,pos);
	}
	return 0; 	
}
