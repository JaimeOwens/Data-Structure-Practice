#include<iostream>
#include<stack> 
using namespace std;
int main(){
	int n;
	while(cin>>n){
		if(n==0) break;
		stack<int> s;
		for(int i=0;i<n;i++){
			int temp;
			cin>>temp;
			if(temp!=-1)
				s.push(temp);
			else{
				if(!s.empty()){
					int t=s.top();
					cout<<t<<endl;
					s.pop();
				}
				else{
					cout<<"POP ERROR\n";
					break;
				}
			}
		}
	}
	return 0;
} 
