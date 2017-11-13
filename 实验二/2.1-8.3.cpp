#include<iostream>
#define ElemType char 
const int maxsize=200
using namespace std;
typedef struct{
	ElemType data[maxsize];
	int top;
}Stack;
void trans(char *exp,char postexp[]){

}
float compare(char *postexp){
	
}
int main(){
	char exp[maxsize];
	while(cin>>exp){
		if(exp[0]=='0') break;
		char postexp[maxsize],final[axsize];
		trans(exp,postexp);//exp存放中缀表达式,postexp存放后缀表达式
		cout<<compare(postexp);
	}
	return 0;
}


