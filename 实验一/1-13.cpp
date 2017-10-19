#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
typedef int Status;
#define OK 1
#define ERROR -1;
#define OVERFLOW -2;
const int MAXSIZE = 500;
typedef struct Node {
	string num;
	string name;
	int length;
	float price;
	struct Node *next;
}Node, *List;
void InitList(List &L) {
	L = new Node;
	L->next = NULL;
	L->length = 0;
}
void Print(List L) {
	//if (!L) return ERROR;
	printf("%d\n", L->length);
	while (L->next != NULL) {
		L = L->next;
		//printf("%s %s %.2f\n", L->num, L->name, L->price);	
		cout<<L->num<<' '<<L->name<<' ';
		printf("%.2f\n",L->price);
	}
}
void Input(List &L) {
	//if (!L) return ERROR;
	List r=L;
    while (1) {
    	List p=new Node;
       	cin>>p->num>>p->name>>p->price;
        if (p->num[0] == '0'&&p->name[0] == '0'&&p->price == 0) {
            break;
        }
        else {
            p->next=NULL;
            r->next=p;
            r=p;
            L->length++;
        }
    } 
} 
float Average(List L){
	float aver=0.0;
	int sum=0;
	while(L->next!=NULL){
		L=L->next;
		aver+=L->price;
		sum++;
		cout<<aver<<' '<<sum<<endl;
	}	
	aver/=(sum*1.0);
	return aver;
}
Status Change(List &L){
	float aver=Average(L); 
	List p=L;
	while(p->next!=NULL){
		p=p->next;
		if(p->price>=aver)
			p->price*=1.1;
		else 
			p->price*=1.2;
	}
}

int main() {
	List L;
	InitList(L);
	Input(L);
	Change(L);
	Print(L);
	return 0;
}

