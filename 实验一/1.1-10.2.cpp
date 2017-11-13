#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		if(n==0) break;
		int len=n;
		int a[1000];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int temp;
		cin>>temp;
		for(int i=0;i<n;i++)
			if(a[i]==temp){
				for(int j=i;j<len;j++){
					a[j]=a[j+1];
				}
				len--;
				i--;
			}
		for(int i=0;i<len;i++)
			cout<<a[i]<<' ';
		cout<<endl;
	}
	return 0;
} 
