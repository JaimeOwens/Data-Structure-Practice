#include<iostream>
using namespace std;
int MidNumber(int a[],int b[],int n){
	int start1=0,end1=n-1;
	int start2=0,end2=n-1;
	while(start1!=end1||start2!=end2){
		int m1=(start1+end1)/2;
		int m2=(start2+end2)/2;
		if(a[m1]==b[m2]){
			return a[m1];
		}
		else if(a[m1]<b[m2]){
			if((start1+end1)%2==0){
				start1=m1;
				end2=m2;
			}
			else{
				start1=m1+1;
				end2=m2;
			}
		}
		else{
			if((start1+end1)%2==0){
				end1=m1;
				start2=m2;
			}
			else{
				end1=m1;
				start2=m2+1;
			}
		}	
	}
	return a[start1]<b[start2]?a[start1]:b[start2];
}
int main(){
	int n;
	while(cin>>n){
		if(n==0) break;
		int a[100],b[100];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		cout<<MidNumber(a,b,n)<<endl;
	} 
	return 0;
}
