#include <stdio.h>
#define N 100
/*�ַ������ȼ��㺯��*/
int len(char ch[]){
    int i=0;
    while (ch[i]!='\0'){                 
          i++;                   
    }            
    return i;
}
/*�ַ�����ӡ����*/
void chPrint(char ch[]){
     printf("%s\n",ch);                 
}
/*�ַ��������ַ�������*/
int chIns(char ch[],char ch1[],int k){
     int i;
     int len_ch=len(ch);
     int len_ch1=len(ch1);
     if (k>len_ch) {
        printf("�����λ�ô��ڵ�һ���ַ����ĳ��ȣ������˳�!");
        return -1;            
     }
     else {
         for (i=len_ch+len_ch1-1;i>=k+len_ch1;i--){
             ch[i]=ch[i-len_ch1];       /*�ƶ��ַ���Ҫ�����λ�ÿճ���*/
         }
         for (i=0;i<len_ch1;i++){
             ch[k+i]=ch1[i];     /*�����ַ���*/                       
         }
         ch[len_ch+len_ch1]='\0';  /*�����ַ�������*/
         return 1;
     }               
}
int main(){
    
    int k,ins; 
	while(scanf("%d",&k)&&k){
		char a[N],b[N];
    	scanf("%s",a);
    	scanf(" %s",b);
    	ins=chIns(a,b,k-1);  /*ins�������ղ��뺯���ķ���ֵ���ж��Ƿ�ִ���˲������*/
    	if (ins==1) {
        	chPrint(a);
    	}
    	getchar();
	}
    return 0;
}
