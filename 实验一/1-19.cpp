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
	//int no;
    int length;
    struct Node *next;
}Node, *List;
void InitList(List &L) {
    L = new Node;
    L->next = NULL;
    L->length = 0;
}
void Input(List &L) {
	List r=L;
	cin>>L->length;
    for(int i=1;i<=L->length;i++){
    	List p=new Node;
        scanf("%s%s%f", p->num, p->name, &p->price);
        //p->no=i;
        p->next=NULL;
    	r->next=p;
        r=p;
    }
}
void Print(List L) {
    //printf("%d\n", L->length);
    while (L->next!=NULL){
		L = L->next;
        printf("%s %s %.2f\n", L->num, L->name,L->price);
	}
}
Status Delete(List &L){
	int index;
	cin>>index;
	List p=L;
	int j=0;
	while(p->next&&j<index-1){
		p=p->next;
		j++;
	}
	if(!p->next||(j>index-1)) return ERROR;	
	List q=p->next;
	p->next=q->next;
	delete q;
	return OK;
}
int main() {
    List L;
    InitList(L);
    Input(L);
    if(Delete(L)==-1) cout<<"no"<<endl;
    else Print(L);
    //system("pause");
    return 0;
}

