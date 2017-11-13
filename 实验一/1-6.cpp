#include<iostream>
#include <cstring>
using namespace std;
#define OVERFLOW -2
const int MAXSIZE=20000;
typedef int Status;
typedef struct{
    char name[50];
    char num[20];
    float value;
}Book;
typedef struct{
    Book *elem;
    int length;
}SqList;

void InitList(SqList &L){
    L.elem=new Book[MAXSIZE];
    if(!L.elem) exit(OVERFLOW);
    L.length=0;
}
void Input(SqList &L){
    cin>>L.length;
    for(int i=0;i<L.length;i++)
    	scanf("%s%s%f",L.elem[i].num,L.elem[i].name,&L.elem[i].value);
}
/*

void Find(SqList &L){
	int n,i;
	scanf("%d\n",&n);
	char target[20][50];
	int arr[250]={0};
	for(int j=0;j<n;j++)
		scanf("%s",target[j]);
	for(int j=0;j<n;j++){
		bool flag2=false;
		int sum=0;
		for(i=0;i<L.length;i++)
			if(strcmp(L.elem[i].name,target[j])==0){
				sum++;
				flag2=true;
			}
		for(i=0;i<L.length;i++)		
			if(strcmp(L.elem[i].name,target[j])==0){
				printf("%d\n",sum);
				printf("%s %s %.2f\n",L.elem[i].num,L.elem[i].name,L.elem[i].value);
				break;
			}
		if(!flag2){ printf("no\n");}
	}
}*/
void Find(SqList &L){
	int n,i;
	scanf("%d\n",&n);
	while(n--){
		char target[50];
		scanf("%s",target);
		bool flag2=false;
		int sum=0;
		for(i=0;i<L.length;i++)
			if(strcmp(L.elem[i].name,target)==0){
				sum++;
				//flag2=true;
			}
		if(sum==0){ printf("no\n");continue;}
		printf("%d\n",sum);
		for(i=0;i<L.length;i++)		
			if(strcmp(L.elem[i].name,target)==0){
				printf("%s %s %.2f\n",L.elem[i].num,L.elem[i].name,L.elem[i].value);
			}
	}
}
int main(){
    SqList L;
    float average=0;
    InitList(L);
    Input(L);
    Find(L);
    return 0;
}
