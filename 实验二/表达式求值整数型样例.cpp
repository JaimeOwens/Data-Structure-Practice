#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
#define MAXSIZE 100  
    
typedef struct oprd{  
    double data[MAXSIZE];  
    int top;  
}OPRD;  
   
typedef struct optr{  
  
    char data[MAXSIZE];  
    int top;  
  
}OPTR;  
 
#define InitStack(StackType, stack) \  
{   \  
    *stack = (StackType *)malloc(sizeof(StackType));    \  
    *stack->top = -1;    \  
}  
  
 
#define EmptyStack(stack)   \  
(   \  
    stack->top == -1 \  
)  
  
 
#define FullStack(stack)    \  
(   \  
    stack->top == MAXSIZE - 1    \  
)  
    
#define PushStack(stack, value) \  
{   \  
    if (!FullStack(stack)){ \  
        stack->top++;    \  
        stack->data[stack->top] = value;  \  
    }   \  
    else{   \  
        exit(-1);   \  
    }   \  
}  
    
#define PopStack(stack, value)  \  
{   \  
    if (!EmptyStack(stack)){    \  
        *value = stack->data[stack->top]; \  
        stack->top--;    \  
    }   \  
    else{   \  
        exit(-1);   \  
    }   \  
}  
  
#define GetStackTop(stack, value)   \  
{   \  
    if (!EmptyStack(stack)){    \  
        *value = stack->data[stack->top]; \  
    }   \  
    else{   \  
       	exit(-1);  \
    }   \  
}  
 
char compare(char ch, char top)  
{  
    switch(ch){  
        case '+':  
        case '-':  
            if (top == '+' || top == '-' || top == '*' || top == '/')  
                return '<';  
            else  
                return '>'; 
            break;  
        case '*':  
        case '/':  
            if (top == '*' || top == '/')  
                return '<';  
            else  
                return '>';  
            break;  
        case '(':  
            if(top == ')'){  
                exit(-1);  
            }  
            return '>';  
            break;  
        case ')':  
            if (top == '(')  
                return '=';  
            else if(top == '#'){  
                exit(-1);  
            }  
            else{  
                return '<';  
            }  
            break;  
        case '#':  
            return '<';  
    }  
}  
   
double CalculateExp(void)  
{  
    double result, tempNum1, tempNum2;  
    double data = 0, expn;  
    char ch, topSign, point = 'n', num = 'n';  
    OPTR *sign;  
    OPRD *number;  
  
    InitStack(OPTR, &sign);  
    InitStack(OPRD, &number);  
    PushStack(sign, '#');   
    ch = getchar();  
    if(ch=='=')	return -10010;
    	
    GetStackTop(sign, &topSign);  
    while(ch != '#' || topSign != '#'){  
        if ('0' <= ch && ch <= '9' || ch == '.'){  
            if (ch == '.' && point == 'y'){    
                exit(-1);  
            }  
            else if (ch == '.' && point == 'n'){  
                point = 'y';  
                expn = 0.1;  
            }  
            else{  
                if (point == 'y'){  
                    data = data + expn * (ch - '0');  
                    expn *= 0.1;  
                }  
                else{  
                    data = data * 10 + (ch - '0');  
                }  
                num = 'y';  
            }  
            ch = getchar();  
        }  
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == '#'){  
            if (num == 'y'){  
                PushStack(number, data);  
                num = 'n';  point = 'n';  
                data = 0;  
            }  
            GetStackTop(sign, &topSign);  
            switch(compare(ch, topSign)){  
                case '<':       
                    PopStack(sign, &topSign);  
                    PopStack(number, &tempNum1);  
                    PopStack(number, &tempNum2);  
                    switch(topSign){  
                        case '+':   result = tempNum1 + tempNum2;   break;  
                        case '-':   result = tempNum2 - tempNum1;   break;  
                        case '*':   result = tempNum1 * tempNum2;   break;  
                        case '/':   result = tempNum2 / tempNum1;   break;  
                    }  
                    PushStack(number, result);  
                    break;  
                case '>':        
                    PushStack(sign, ch);  
                    ch = getchar();  
                    break;  
                case '=':       
                    PopStack(sign, &topSign);  
                    ch = getchar();  
                    break;  
            }  
        }  
        else if (ch =='='){  
            ch = '#';  
        }  
        else{    
            exit(-1);  
        }  
        GetStackTop(sign, &topSign);  
    }  
    PopStack(number, &result);   
    if (!EmptyStack(number)){  
        exit(-1);  
    }    
    getchar();
    return result;  
}  
  
int main(void)  
{  	
	while(1){
    	double temp=CalculateExp();
		if(temp==-10010) break;
		printf("%.2lf\n",temp);
	}
    return 0;  
}  
