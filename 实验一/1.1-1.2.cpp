#include <cstdio>  
#include <cstdlib> 
#include <iostream> 
using namespace std;
typedef int ElementType;  
typedef struct Node *PtrToNode;  
struct Node {  
    ElementType Data;  
    PtrToNode   Next;  
};  
typedef PtrToNode List;  

List Read(int n)  
{  
    List L=(List)malloc(sizeof(PtrToNode)); 
    L->Next = NULL;     
    if(n)   
    {  
        List r=L;    
        for(int i=0;i<n;i++)   
        {  
            List p=(List)malloc(sizeof(struct Node));  
            scanf("%d",&(p->Data));   
            r->Next = p;  
            r = p;  
        }  
        r->Next = NULL;           
    }  
    return L;  
}  
  
void Print( List L )  
{  
   	List p=L; 
   	while(p->Next){
   		p=p->Next;
   		printf("%d ",p->Data);
   	}   
   	printf("\n");  
}  

List Merge( List L1, List L2 ) 
{  
    List pa,pb,pc,L;  
    L = (List)malloc(sizeof(struct Node));  
    pa=L1->Next;  
    pb=L2->Next;  
    pc = L;  
    while(pa && pb)  
    {  
        if(pa->Data<=pb->Data)  
        {  
            pc->Next = pa;  
            pc = pa;  
            if(pa->Data==pb->Data)
				pb=pb->Next; 
			pa = pa->Next; 
        }  
        else
        {  
            pc->Next = pb;  
            pc = pb;  
            pb = pb->Next;  
        }  
    }  
    pc->Next = pa ? pa : pb;  
    L1->Next = NULL;  
    L2->Next = NULL;  
    return L;  
}  

void Check(List &L){
	List p=L->Next;
	while(p->Next){
		if(p->Data==p->Next->Data){
			List t=p->Next;
			p->Next=t->Next;
			delete t; 
			continue;
		} 
		p=p->Next;
		//Print(L);
	}
}
int main()  
{  
	int n1,n2;
	while(~scanf("%d%d",&n1,&n2)){
		if(n1==0&&n2==0) break;
		List L1 = Read(n1);  
    	List L2 = Read(n2);  
    	List L = Merge(L1, L2);
		Check(L);
		Print(L);  
	}  
    return 0;  
}  
  

