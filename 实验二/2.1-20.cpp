#include<iostream>
#include<cstdlib>
#include<set>
using namespace std;
int main(){
	int m,n;
	int a[200][200];
	while(cin>>m>>n){
		if(m==0&&n==0) return 0;
		set<int> s;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				cin>>a[i][j];
		bool flag=true;
		for(int i=0;i<m;i++){	
			for(int j=0;j<n;j++){
				if(s.count(a[i][j])){
					flag=false;
					break;
				} 
				else s.insert(a[i][j]);
			}
			if(!flag) break;
		}
		if(!flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;		
	}
	return 0;
}
