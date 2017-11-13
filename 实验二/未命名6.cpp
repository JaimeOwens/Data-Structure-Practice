#include<iostream>
#include<cstdlib>
#include<cstring>
#define OVERFLOW -2
#define ERROR -1
#define OK 1
using namespace std;
typedef char DataType;
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
DataType Pop(Stack &S){
	if(S.top==S.base) return ERROR;
	else{
		S.top--;
		DataType e=*S.top;
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
	Palindromic(S);
    return 0;  
} 
