#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
using namespace std;
typedef int Status;
#define OK 1
#define ERROR -1
#define OVERFLOW -2
const int MAXSIZE = 500;
typedef struct Node {
	string name;
    string num;
    float price;
	int no;
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
        cin>>p->num>>p->name>>p->price;
        p->no=i;
        p->next=NULL;
    	r->next=p;
        r=p;
    }
}
int sum=0;
void Print(List L) {
    printf("%d\n", L->length-sum);
    while (L->next!=NULL){
		L = L->next;
		cout<<L->num<<' '<<L->name<<' ';
        printf("%.2f\n",L->price);
	}
}

struct Node *Distinct(struct Node *head)
{
    struct Node *p,*q,*s;
	p = head->next;
	while(p->next!=NULL)
	{
   		q=p;
  		while(q->next!=NULL)
  		{
   			if(q->next->num == p->num)
   			{
         		s = q->next;
 				q->next = s->next;
 				free(s);
 				sum++;
   			}
			else
          		q=q->next;
  		}
		p=p->next;
	}
    return head;
}

/*void Insert(List &temp,string num,string name,float price){
	List r=temp;
    List p=new Node;
    while(r->next!=NULL)
    	r=r->next;
    r=r->next;
    p->num=num;
    p->name=name;
    p->price=price;
    p->next=NULL;
    r->next=p;
    r->length++;
	r=p;	
}
void Distinct(List &L){
	set<string> s;
	//List t;
	//InitList(t);
	List p=L;
	List temp;
	InitList(temp);
	//vector<Node> v;
	while(p->next!=NULL){
		p=p->next;
		s.insert(p->num);
		if(s.count(p->num)==1);
		else{
			Insert(temp,p->num,p->name,p->price);
		}	
	}
	Print(temp);
}
void Distinct(List L){
	List p=L;
	while(p->next!=NULL){
		p=p->next;
		string target=p->num;
		List t=p;
		t=t->next;
		while(t->next!=NULL){
			if(t->num==target){
				List q=t->next;
				t->next=q->next;
				delete q;
				L->length--;
				Print(L);
			}
			t=t->next;	
		}
	}
}*/ 
/*void Print2(vector<List> v){
	vector<List>:: iterator it;
	for(it=v.begin();it!=v.end();it++)
		cout<<*it->num<<' '<<*it->name;
}*/
 
int main() {
    List L;
    InitList(L);
    Input(L);
    vector<List> v;
    Distinct(L);
    Print(L);
    //system("pause");
    return 0;
}

