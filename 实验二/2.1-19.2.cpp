#include <stdio.h>
#define N 100
/*字符串长度计算函数*/
int len(char ch[]){
    int i=0;
    while (ch[i]!='\0'){                 
          i++;                   
    }            
    return i;
}
/*字符串打印函数*/
void chPrint(char ch[]){
     printf("%s\n",ch);                 
}
/*字符串插入字符串函数*/
int chIns(char ch[],char ch1[],int k){
     int i;
     int len_ch=len(ch);
     int len_ch1=len(ch1);
     if (k>len_ch) {
        printf("插入的位置大于第一个字符串的长度，程序退出!");
        return -1;            
     }
     else {
         for (i=len_ch+len_ch1-1;i>=k+len_ch1;i--){
             ch[i]=ch[i-len_ch1];       /*移动字符将要插入的位置空出来*/
         }
         for (i=0;i<len_ch1;i++){
             ch[k+i]=ch1[i];     /*插入字符串*/                       
         }
         ch[len_ch+len_ch1]='\0';  /*设置字符结束符*/
         return 1;
     }               
}
int main(){
    
    int k,ins; 
	while(scanf("%d",&k)&&k){
		char a[N],b[N];
    	scanf("%s",a);
    	scanf(" %s",b);
    	ins=chIns(a,b,k-1);  /*ins用来接收插入函数的返回值，判断是否执行了插入操作*/
    	if (ins==1) {
        	chPrint(a);
    	}
    	getchar();
	}
    return 0;
}
