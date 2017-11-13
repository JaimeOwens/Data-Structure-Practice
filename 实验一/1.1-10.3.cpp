#include<iostream>
using namespace std;
int main(){
	int n;
	while(~scanf("%d",&n)&&n!=0){
		//if(n==0) break;
		int a[500],b[500];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int item,cnt=0;
		cin>>item; 
		for(int i=0;i<n;i++){
			if(a[i]!=item){
				b[cnt]=a[i];
				cnt++;
			}
		}
		for(int i=0;i<cnt;i++)
			cout<<b[i]<<' ';
		cout<<endl;		
	} 
	return 0;
}
