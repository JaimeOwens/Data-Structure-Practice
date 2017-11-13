#include<iostream>
#include<cstring>
#include<cstdlib>
#define maxsize 200
#define OK 1
#define ERROR -1
#define OVERFLOW -2 
using namespace std;
typedef int status;

//typedef double Elemtype2;
typedef struct StackOp{
	char data[maxsize];
	int top;
}StackOp;
typedef struct StackNum{
	double data[maxsize];
	int top;
}StackNum;
//多种类型的栈可以共用操作 
#define InitStack(StackType,stack)	\
{	\
	*stack=(StackType*)malloc(sizeof(StackType));	\
	*stack->top=-1;	\
}
#define EmptyStack(stack){	\
	stack->top==-1;	\
} 
#define FullStack(stack){	\
	stack->top=maxsize-1;	\
} 
#define Push(stack,elem)	\
{	\
	if(!FullStack(stack)){	\
		stack->top++;		\
		stack->data[stack->top]=elem;	\
	}						\
	else exit(OVERFLOW);	\
}
#define Pop(stack,elem){	\
	if(!EmptyStack(stack)){	\
		*elem=stack->data[stack->top];	\
		stack->top--;		\
	}						\
	else exit(ERROR);		\
}
#define GetTop(stack,elem){	\
	if(!EmptyStack(stack)){	\
		*elem=stack->data[stack->top];	\
	}						\
	else exit(ERROR);		\
}
char Compare(char ch,char top){
	switch(ch){
		case '+'://??
		case '-':
			if(top=='+'||top=='-'||top=='*'||top=='/')
				return '<';
			else return '>';
			break;
		case '*'://???
		case '/':
			if(top=='*'||top=='/')
				return '<';
			else return '>';
			break;
		case '(':
			if(top == ')')	exit(ERROR);  
            return '>';  
            break;  
		case ')':  
            if (top == '(')  
                return '=';  
            else if(top == '#') exit(ERROR);   
            else return '<';
			break;   
        case '#':
			return '<';        
	}
}
double Calculate(){
	double result,num1,num2;
	double data=0,expn;
	char ch,topOp,flag=false,num=false;
	StackOp st_op;
	StackNum st_num;
	InitStack(StackOp,&st_op);
	InitStack(StackNum,&st_num);
	Push(st_op,'#');
	ch=getchar;
	if(strcmp(ch,'=')==0) return -10010;
	GetTop(st_op,&topOp);
	while(ch!='#'||topOp!='#'){
		if('0'<=ch||ch>='9'||ch=='.'){
			if (ch == '.' &&flag==true)	exit(ERROR); 
			else if(ch=='.'&&flag==false){
				flag=true;
				expn=0.1;
			}
			else{
				if(flag=true){
					data=data+expn*(ch-'0');
					expn*=0.1;
				}
				else{
					data=data*10+(ch-'0');
				}
				num=true;
			}
			ch=getchar();
		} 
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == '#'){
			if(num==true){
				Push(st_num,data);
				num=false,flag=false;
				data=0;
			}
			GetTop(st_op,&topOp);
			switch(Compare(ch,topSign)){
				case '<':
					Pop(st_op,&topOp);
					Pop(st_num,&num1);
					Pop(st_num,&num2);
					switch(topOp){
						switch(topSign){ 
							case '+': result = num2 + num1; break; 
							case '-': result = num2 - num1; break; 
							case '*': result = num2 * num1; break; 
							case '/': result = num2 / num1; break; 
						}
					}
				case '>':
					Push(st_op,ch);
					ch=getchar();
					break;	
				case '=': 
					Pop(st_op,&topOp);
					ch=getchar();
					break;	
			}
		}
		else if(ch=='=') ch='#';
		else GetTop(st_op,&topOp);
	}
	Pop(st_num,&result);
	if(!EmptyStack(number)) exit(ERROR);
	return result;
}
int main(){
	while(1){
		double temp=Calculate();
		if(temp=-10010) break;
		printf(".2lf\n",temp);
	}
	return 0;
} 

