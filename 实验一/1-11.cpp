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
void Input(List &L) {
    //if (!L) return ERROR;
	List r=L;
    while (1) {
    	List p=new Node;
        scanf("%s%s%f", p->num, p->name, &p->price);
        if (p->num[0] == '0'&&p->name[0] == '0'&&p->price == 0) {
            break;
        }
        else {
            p->next=NULL;
            r->next=p;
            r=p;
            L->length++;
            //printf("%s %s %.2f\n", L->num, L->name, L->price);
        }
    }
}
void Print(List L) {
    //if (!L) return ERROR;
    printf("%d\n", L->length);
    while (L->next!=NULL){
		L = L->next;
        printf("%s %s %.2f\n", L->num, L->name, L->price);
	}
}
int main() {
    List L;
    InitList(L);
    Input(L);
    Print(L);
    //system("pause");
    return 0;
}

