#include<iostream>
using namespace std;
typedef int Elemtype;
#define MAXSIZE 100
typedef struct List{
	int length;
	Elemtype elem[MAXSIZE];
}List;
void Input(List &L,int n){
	L.length=n;
	for(int i=1;i<=n;i++){
		cin>>L.elem[i];
	}
}
void Print(List L){
	for(int i=1;i<=L.length;i++)
		cout<<L.elem[i]<<' ';
	cout<<endl;
}
void DeleteElem(List &L){
	Elemtype e;
	cin>>e;
	
}
int main(){
	int n;
	while(cin>>n){
		if(n==0) break;
		List L;
		Input(L,n);
		DeleteElem(L);
		Print(L);
	} 
	return 0; 
}
