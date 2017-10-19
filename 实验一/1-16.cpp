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
void Input(List &L) {
    //if (!L) return ERROR;
	List r=L;
	int n;
	cin>>n;
	while(n--){
    	List p=new Node;
        //scanf("%s%s%f", p->num, p->name, &p->price);
        cin>>p->num>>p->name>>p->price;
        p->next=NULL;
        r->next=p;
        r=p;
    }
}
int Find2(List L,string target){
	int sum=0;
	//cout<<target<<endl;
	while(L->next!=NULL){
		L=L->next;	
		if(target==L->name){
			sum++;
		}
	}
	return sum;
}
void Find(List L){
	int n;
	cin>>n;
	while(n--){
		string target;
		cin>>target;
		int sum=Find2(L,target);
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

