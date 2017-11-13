#include<iostream>
#include<cstdlib>
#define OVERFLOW -2
#define ERROR -1
#define OK 1
using namespace std;
typedef int DataType;
typedef int Status;
const int STACK_SIZE=100; 
const int STACK_INCREAMENT=10;
typedef struct{
	DataType *top;
	DataType *base;
	int stacksize;
}Stack;
Status InitStack(Stack &S){
	S.base=(DataType*)malloc(STACK_SIZE*sizeof(DataType));
	if(!S.base) exit(OVERFLOW); 
	S.top=S.base;
	S.stacksize=STACK_SIZE;
	return OK;
} 
Status Destroy(Stack &S){
	S.top=NULL;
	S.stacksize=0;
	free(S.base);
	return OK;
}
Status Clear(Stack &S){
	S.top=S.base;
	return OK;
}
bool Empty(Stack S){
	if(S.top==S.base) return false;	
	else return true;
}
Status GetLength(Stack &S){
	return (S.top-S.base);	
}
DataType GetTop(Stack S,DataType &e){
	if(S.top==S.base)  return 0;
	else return *(S.top-1);					
}
Status Push(Stack &S,DataType e){
	if(S.top-S.base>=STACK_SIZE){
		S.base=(DataType*)realloc(S.base,(S.stacksize+STACK_INCREAMENT)*sizeof(DataType));
		if(!S.base) return ERROR;
		S.top=S.base+STACK_SIZE;
		S.stacksize=S.stacksize+STACK_INCREAMENT; 
	} 
	*S.top=e;
	*S.top++;
	return OK;
}
Status Pop(Stack &S,DataType &e){
	if(S.top==S.base) return ERROR;
	else{
		S.top--;
		e=*S.top;
		return e;
	}
}
Status Print(Stack S){
	if(S.base==NULL) return ERROR;
	if(S.top==S.base) printf("NULL STACK\n");
	DataType *p;
	p=S.top;
	while(p>S.base){
		p--;
		printf("%d ",*p);
	} 
	return OK;
}
int main()  
{  
    Stack S;  
    printf("����һ����ջ����\n");  
    InitStack(S);  
    int i,n ;  
    printf("����ջ�ĳ���:\n");  
    scanf("%d",&n);  
    for (i = 1; i <= n; i++)  
    {  
        printf("����ջ�ĵ�%d��Ԫ��\n",i);  
        ++S.top;  
        scanf("%d",S.top-1);  
    }  
     	printf("������ջ�ǿ�ջ�𣿣�����\n");  
    if (Empty(S) == 1)  
        printf("NO !!!\n");  
    else  
        printf("YES !!!\n");  
    printf("�������ջ�ĳ��ȡ���\n");  
    int m;  
    m =GetLength(S);  
    printf("ջ�ĳ�����:\n");  
    printf("%d\n",m);  
    printf("�������ջ�е�����Ԫ��:\n");  
    Print(S);  
    printf("\n");  
    printf("�������ջ��Ԫ�ء���\n");  
    int e;  
    e = GetTop(S, e);  
    printf("ջ��Ԫ����:\n");  
    printf("%d\n",e);  
    printf("����ջ������Ԫ�ء���\n");  
    printf("������Ҫ�����Ԫ�ص���ֵ:\n");  
    scanf("%d",&e);  
    Push(S,e);  
    printf("����ջ�е�Ԫ����:\n");  
    Print(S);  
    printf("\n");  
    printf("����ջ��ɾ��Ԫ�ء���\n");  
    e = Pop(S,e);  
    printf("��ɾ����Ԫ����:\n");  
    scanf("%d",&e);  
    printf("����ջ�е�Ԫ����:\n");  
    Print(S); 
    printf("\n");  
    printf("�������ջ����\n");  
    Clear(S);  
     printf("����ջ�е�Ԫ����:\n");  
    Print(S);
     printf("��������ջ����\n");  
    if(Destroy==1)  
         printf("����ջ�ɹ�\n");  
    else  
         printf("����ջʧ��\n");  
     printf("ϲ���ɹ�������еĹ���,�Ͼ�����ô˧!!!\n");  
    return 0;  
} 
