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
    printf("构造一个空栈……\n");  
    InitStack(S);  
    int i,n ;  
    printf("输入栈的长度:\n");  
    scanf("%d",&n);  
    for (i = 1; i <= n; i++)  
    {  
        printf("输入栈的第%d个元素\n",i);  
        ++S.top;  
        scanf("%d",S.top-1);  
    }  
     	printf("……本栈是空栈吗？？……\n");  
    if (Empty(S) == 1)  
        printf("NO !!!\n");  
    else  
        printf("YES !!!\n");  
    printf("……求出栈的长度……\n");  
    int m;  
    m =GetLength(S);  
    printf("栈的长度是:\n");  
    printf("%d\n",m);  
    printf("遍历输出栈中的所有元素:\n");  
    Print(S);  
    printf("\n");  
    printf("……输出栈顶元素……\n");  
    int e;  
    e = GetTop(S, e);  
    printf("栈顶元素是:\n");  
    printf("%d\n",e);  
    printf("……栈顶插入元素……\n");  
    printf("请输入要插入的元素的数值:\n");  
    scanf("%d",&e);  
    Push(S,e);  
    printf("现在栈中的元素是:\n");  
    Print(S);  
    printf("\n");  
    printf("……栈顶删除元素……\n");  
    e = Pop(S,e);  
    printf("被删除的元素是:\n");  
    scanf("%d",&e);  
    printf("现在栈中的元素是:\n");  
    Print(S); 
    printf("\n");  
    printf("……清空栈……\n");  
    Clear(S);  
     printf("现在栈中的元素是:\n");  
    Print(S);
     printf("……销毁栈……\n");  
    if(Destroy==1)  
         printf("销毁栈成功\n");  
    else  
         printf("销毁栈失败\n");  
     printf("喜您成功完成所有的功能,毕竟您那么帅!!!\n");  
    return 0;  
} 
