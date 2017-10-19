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
    int no;
    struct Node *next;
}Node, *List;
void InitList(List &L) {
    L = new Node;
    L->next = NULL;
}
void Input(List &L) {
	List r=L;
	int n;
	cin>>n;
    for(int i=1;i<=n;i++){
    	List p=new Node;
        scanf("%s%s%f", p->num, p->name, &p->price);
        p->no=i;
        p->next=NULL;
    	r->next=p;
        r=p;
    }
}
void Find_index(List L){
	int index;
	cin>>index;
	int target=false;
	//index--;
	//List p=L;
	/*while(p->next!=NULL){ 
		p=p->next;
		if(p->no==index){
			cout<<p->num<<' '<<p->name<<' '<<p->price;
			break;
		} 
	}*/
	while(L->next!=NULL){ 
		L=L->next;
		if(L->no==index){
			cout<<L->num<<' '<<L->name<<' ';
			printf("%.2f\n",L->price);
			target=true;
			break;
		} 
	}
	if(!target)
		cout<<"no"<<endl;
}
int main(){
    List L;
    InitList(L);
    Input(L);
    int n;
    cin>>n;
    while(n--)
    	Find_index(L);
    //Print(L);
    //system("pause");
    return 0;
}

