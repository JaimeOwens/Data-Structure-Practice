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
void Input(List &L) {
	//if (!L) return ERROR;
	while (1) {
		List p = new Node;
		//scanf("%s%s%f", p->num, p->name, &p->price);
		cin >> p->num >> p->name >> p->price;
		if (p->num=="0"&&p->name=="0"&&p->price == 0) {
			break;
		}
		else {
			p->next = L->next;
			L->next = p;
			L->length++;
		}
	}
} 
Status Sort(List &L){
	if(L==NULL||L->next==NULL) return ERROR;
	List h=L->next;    // 原链表
    L->next=NULL;      // 新空表
    List s=NULL,p=NULL;
    while(h)
    {
        // 从原链表中取下结点s
        s=h;  h=h->next;
        // 在新表中查找插入位置
        p=L;
        while (p->next && p->next->price>=s->price)
        	p=p->next;
        // 在p之后插入s
        s->next=p->next;
        p->next=s;
    }
	return OK;
} 
void Print(List L) {
	while (L->next != NULL) {
		L = L->next;
		//printf("%s %s %.2f\n", L->num, L->name, L->price);	
		cout<<L->num<<' '<<L->name<<' ';
		printf("%.2f\n",L->price);
	}
}
int main() {
	List L;
	InitList(L);
	Input(L);
	Sort(L);
	Print(L);
	return 0;
}

