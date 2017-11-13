#include <iostream>
#include<cstring>
using namespace std;
typedef int Status;
#define OK 1
#define ERROR -1
#define OVERFLOW -2
const int MAXSIZE = 500;
typedef struct Node {
    string name;
    char num[20];
    float price;
    struct Node *next;
}Node, *List;
void InitList(List &L) {
    L = new Node;
    L->next = NULL;
}
void Print(List L) {
    while (L!=NULL){
		L = L->next;
        cout<<L->num<<' '<<L->name<<' '<<L->price<<endl;
	}
	cout<<endl;
}
void Input(List &L) {
	int n;
	cin>>n;
	List r=L;
    for(int i=0;i<n;i++){
    	List p=new Node;
        cin>>p->num>>p->name>>p->price;
        p->next=NULL;
        r->next=p;
        r=p;
    }
    Print(L);
}
int Find2(List L,string target){
	int sum=0;
	while(L!=NULL){
		L=L->next;	
		if(target==L->name){
			sum++;
		}
	}
	cout<<sum<<endl;
	return sum;
}
void Find(List L){
	system("pause");
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		string target;
		cin>>target;
		int sum=0;
		sum=Find2(L,target);
		if(sum==0){
			printf("no\n");
		}
		else{
			printf("%d\n",sum);
			while(L->next!=NULL){
				L=L->next;
				if(L->name==target){
					cout<<L->num<<' '<<L->name<<' ';
					printf("%.2f\n",L->price);
				}
			} 
		}
	}
}
int main() {
    List L;
    InitList(L);
    Input(L);
    Find(L);
    return 0;
}

