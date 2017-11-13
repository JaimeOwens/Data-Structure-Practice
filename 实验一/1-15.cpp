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
    bool flag;
}Node, *List;
void InitList(List &L) {
    L = new Node;
    L->next = NULL;
    L->length = 0;
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
int sum=0;
void Expensive(List L){
	float max=-1;
	List s=L;
	while (s->next!=NULL){
		s = s->next;
        if(s->price>max)
        	max=s->price;
	}
	while (L->next!=NULL){
		L = L->next;
        if(L->price==max){
        	L->flag=true;
        	sum++;
		}        	
	}
}
void Print(List L) {
    //if (!L) return ERROR;
    //printf("%d\n", L->length);
    cout<<sum<<endl;
    while (L->next!=NULL){
		L = L->next;
    	if(L->flag==true)
        	printf("%s %s %.2f\n", L->num, L->name, L->price);
	}
}
int main() {
    List L;
    InitList(L);
    Input(L);
    Expensive(L);
    Print(L);
    return 0;
}

