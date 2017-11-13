#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char str[100];
	while(cin>>str){
		if(str[0]=='0') break;
		int sum=0;
		bool flag=true;
		for(int i=0;i<strlen(str);i++){
			if(str[i]=='I') sum++;
			else sum--;
			if(sum==0&&str[i+1]=='O'){
				cout<<"FALSE"<<endl;
				flag=false;
				break;
			}
		}
		if(flag) cout<<"TRUE"<<endl;
	}
	return 0;
}
