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
		else if(exp[i] == '*' || exp[i] == '/')  //������ɨ�赽+- ֻ�����ջ����=-������Ͳ��ó�ջ  ��Ϊ��������ȼ��Ƚ�С  
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

