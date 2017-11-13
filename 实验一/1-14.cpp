#include <iostream>
using namespace std;
typedef int Status;
#define OK 1
#define ERROR -1
#define OVERFLOW -2
const int MAXSIZE = 500;
typedef struct Node {
    char name[50];
    char num[20];
    float price;
    int length;
    struct Node *next;
}Node, *List;
void InitList(List &L) {
    L = new Node;
    L->next = NULL;
    L->length = 0;
}
void Print(List L) {
    //printf("%d\n", L->length);
    while (L->next!=NULL){
		L = L->next;
        printf("%s %s %.2f\n", L->num, L->name, L->price);
	}
}
void Input(List &L) {
	cin>>L->length;
	List r=L;
    for(int i=0;i<L->length;i++){
    	List p=new Node;
        scanf("%s%s%f", p->num, p->name, &p->price);
        p->next=NULL;
        r->next=p;
        r=p;
    }
}
void Reverse(List &L){
	List p=L->next;
	L->next=NULL;
	while(p!=NULL){
		List q=p->next;
		p->next=L->next;
		L->next=p;
		p=q;
	}
}
int main() {
    List L;
    InitList(L);
    Input(L);
    Reverse(L);
    Print(L);
    return 0;
}

