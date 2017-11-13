#include<iostream>
#include<cstring>
using namespace std;
void virus(char a[],char b[]){
	lena=strlen(a),lenb=strlen(b);
	for(int i=lena,j=0;j<lena;j++)
		a[i++]=a[j];
	a[2*lena-1]='\0';
	cout<<a<<endl;
	for(int i=0;i<lena;i++){
		for(int j=0;j<lena;j++)
			
	} 
} 
int main(){
	while(1){
		char a[100],b[300];
		cin>>a>>b;
		if(a[0]=='0'&&b[0]=='0') break;
		virus(a,b);
	}
	return 0;
}
