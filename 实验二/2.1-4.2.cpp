#include<iostream>
#include<cstring>
using namespace std;
bool Judge(char str[]){
	int i=0,j=0,k=0;
	while(str[i]!='\0'){
		switch(str[i]){
			case 'I':j++;break;
			case 'O':k++;
			if(k>j) return false;
		}
		i++;
	}
	if(k!=j) return false;
	else return true;
}
int main(){
	char str[100];
	while(cin>>str){
		if(str[0]=='0') break;
		if(Judge(str)) cout<<"TRUE"<<endl;
		else cout<<"FALSE"<<endl;
	}
	return 0;
}
