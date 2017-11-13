#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
#include <string>  
#include <stack>  
#include<algorithm>  
#define MAXN 1000  
using namespace std; 
stack<char> s;
char *transfExp(char *exp){
	char tempStr[1000];
	int i=0,j=0;
	while(exp[i]!='\0'){
		if(exp[i]>='0'&&exp[i]<='9')
			tempStr[j++]=exp[i];
		else if(exp[i]=='(')
			s.push(exp[i]);
		else if(exp[i]==')'){
			while(!s.empty()){
				if(s.top()=='('){
					s.pop();
					break;
				}
				else{
					tempStr[j++]=s.top();
					s.pop();
				}
			}
		}
		else if(exp[i]=='+'||exp[i]=='-'){
			while(!s.empty()){
				char ch=s.top();
				if(ch == '+'||ch == '-'||ch == '/'||ch == '*')  
                {  
                   tempStr[j++] = s.top();  
                   s.pop();  
                }  
                else  break; 
			}
			s.push(exp[i]);  
		}
		else if(exp[i] == '*' || exp[i] == '/')  //类似于扫描到+- 只是如果栈中有=-运算符就不用出栈  因为运算符优先级比较小  
        {  
            while(s.empty() == false)  
            {  
                char ch = s.top();  
                if(ch == '/' || ch=='*')  
                {  
                    tempStr[j++] = s.top();  
                   	s.pop();  
                }  
                else  break;  
            }  
            s.push(exp[i]);  
        }  
        i++; 
	}
	while(!s.empty()){
		tempStr[j++] = s.top();  
        s.pop(); 
	}
	return tempStr;
}

