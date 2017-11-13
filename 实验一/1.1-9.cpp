#include<iostream>
#include<cstdlib>

using namespace std;
typedef int ElemType;
const int MAXSIZE=100;

typedef struct Node  
{  
    int data;  
    struct Node *pNext;  
    struct Node *pPre;  
}NODE, *pNODE;

pNODE CreateDbLinkList(void){
	int i, length = 0, data = 0;  
    pNODE pTail = NULL, p_new = NULL;  
    pNODE pHead = (pNODE)malloc(sizeof(NODE));  
    if (NULL == pHead)  {  
        //printf("ÄÚ´æ·ÖÅäÊ§°Ü£¡\n");  
        exit(EXIT_FAILURE);  
    }  
    pHead->data = 0;  
    pHead->pPre = NULL;  
    pHead->pNext = NULL;  
    pTail = pHead;
	cin>>length;
	for(int i=0;i<length;i++){
		p_new = (pNODE)malloc(sizeof(NODE));  
        if (NULL == p_new)  
        {  
            //printf("ÄÚ´æ·ÖÅäÊ§°Ü£¡\n");  
            exit(EXIT_FAILURE);  
        }  
        int data;
        scanf("%d", &data);  
        p_new->data = data;  
        p_new->pNext = NULL;  
        p_new->pPre = pTail;  
        pTail->pNext = p_new;  
        pTail = p_new;  
	} 
    return pHead;
}
void SwapDbLinkList(pNODE p){
	pNODE q=p->pPre;
	q->pPre->pNext=p;
	p->pPre=q->pPre;
	q->pNext=p->pNext;
	q->pPre=p;
	p->pNext->pPre=q;
	p->pNext=q;
} 
void PrintDbLinkList(pNODE pHead){
	pNODE p=pHead->pNext;
	while(p!=NULL){
		cout<<p->data<<' ';
		p=p->pNext;
	}
	cout<<endl;
}
void FindDbLinkList(pNODE pHead){
	int index;
	cin>>index;
	int sum=0;
	while(pHead->pNext){
		sum++;
		if(sum==index)
			SwapDbLinkList(pHead);
		pHead=pHead->pNext;	
	} 
}
int main(){
	pNODE L=CreateDbLinkList();
	FindDbLinkList(L);
	//SwapDBLinkList(L);
	PrintDbLinkList(L);
	return 0;
} 

