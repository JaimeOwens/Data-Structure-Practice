#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int m;
	while(cin>>m){
		if(m==0) break;
		int a[200],p[200],n[200];
		int p_cnt=0,n_cnt=0;
		for(int i=0;i<m;i++){
			int temp;
			scanf("%d",&temp);
			if(temp>0){
				p[p_cnt]=temp;
				p_cnt++;
			} 
			if(temp<0||temp==0){
				n[n_cnt]=temp;
				n_cnt++;
			} 	
		} 
		int i=0;
		for(int j=0;j<p_cnt;j++) a[i++]=p[j];
		for(int j=0;j<n_cnt;j++) a[i++]=n[j];
		for(int i=0;i<m-1;i++) cout<<a[i]<<' ';
		cout<<a[m-1]<<endl;
	}
	return 0;
} 
