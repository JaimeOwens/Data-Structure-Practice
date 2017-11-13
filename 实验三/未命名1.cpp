#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef struct HTNode{
	int no;
	int weight;
	int parent;
	int lchild;
	int rchild;
	//bool flag;
	HTNode(int n,int w,int p,int l,int r){
		no=n;
		weight=w;
		parent=p;
		lchild=l;
		rchild=r;
	}
}HTNode,*HuffmanTree;
typedef char **HuffmanCode;
typedef struct{
	char word;
	char *code;
}LNode,*List;	
void Select(HuffmanTree &HT,int num,int &s1,int &s2){
	int i,max=10010,max2=10010;
	for(i=1;i<=num;i++){
		if(HT[i].parent==0&&HT[i].weight<max){
			s2=s1;
			max2=max;
			max=HT[i].weight;
			s1=HT[i].no;
		}
		else if(HT[i].parent==0&&HT[i].weight<max2){
			max2=HT[i].weight;
			s2=HT[i].no;
		}
	}
}
void CreateTreeandCode(HuffmanTree &HT,HuffmanCode &HC,int n,int *w){
	int i,c,start;
	int f,s1,s2;
	char *cd;
	HuffmanTree p;
	if(n<=1) return;
	int m=n*2-1;
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode)); 
	for(p=HT+1,i=1;i<=n;i++,p++,w++)
		*p=HTNode(i,*w,0,0,0);
	for(;i<=m;i++,p++)
		*p=HTNode(i,0,0,0,0);	
	for(i=n+1;i<=m;i++){
		Select(HT,i-1,s1,s2);
		HT[s1].parent=HT[s2].parent=i;
		HT[i].lchild=s1;;
		HT[i].rchild=s2;
		//cout<<s1<<' '<<s2<<endl;
		//cout<<HT[i].lchild<<' '<<HT[i].rchild<<endl; 
		HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
	HC=(HuffmanCode)malloc((n+1)*sizeof(char *));
	cd=(char *)malloc(n*sizeof(char));
	cd[n-1]='\0';
	for(i=1;i<=n;i++){
		start=n-1;
		c=i,f=HT[i].parent;
		while(f!=0){
			--start; 
			if(HT[f].lchild==c) cd[start]='0';
			else cd[start]='1';
			c=f,f=HT[f].parent;
		}
		HC[i]=(char *)malloc((n-start)*sizeof(char));
		strcpy(HC[i],&cd[start]);
	}
	free(cd);
}
/*void Translate(List ArrayList,char *s1,char *s2,int n){
	int i,j,k=0;
	int num=0;
	for(i=1;i<=n;i++){
		int len=strlen(ArrayList[i].code);
		//cout<<len<<endl;
		for(j=0;j<len;){
			if(s1[k]==ArrayList[i].code[j]){ j++,k++; }
			else{ k-=j;break; }
		}
		if(j==len){
			s2[num++]=ArrayList[i].word;
			i=0;
		}
	}
	for(i=0;i<num;i++)
		cout<<s2[i];
	cout<<endl;
}*/
void MakeTranscode(char *code,List ArrayList,int n){
	for(int i=0;i<strlen(code);i++){
		for(int j=1;j<=n;j++){
			if(code[i]==ArrayList[j].word){
				printf("%s",ArrayList[j].code);
			}
		}
	}
	cout<<endl;
} 
int Locate(char c,char *s,int *num){
	int j=0;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]==c){
			(*(num+i))++;
			j=1;
		}
	}
	return j;
}
int main(){
	//char *transcode_result=(char*)malloc(sizeof(char));
	//char *transcode=(char*)malloc(100*sizeof(char));
	char *code=(char *)malloc(100*sizeof(char));
	while(cin>>code){	
		if(code[0]=='0') break;
		HuffmanTree HT;
		HuffmanCode HC;
		List ArrayList;
		ArrayList=(List)malloc(26*sizeof(LNode));
		int i,num;
		int len=3;
		int j=0,k=0;
		char *s=(char *)malloc(len*sizeof(char));
		int *w=(int *)malloc(len*sizeof(int));
		for(i=0;code[i]!='\0';i++){
			if(!Locate(code[i],s,w)){
				if(j>=len){
					s=(char*)realloc(s,10*sizeof(char));
					w=(int*)realloc(w,10*sizeof(int));
					len+=10;
				}
				s[j]=code[i];
				w[j]=1;
				j++;
			}
		} 
		for(i=0;s[i]!='\0';i++)
			cout<<s[i]<<':'<<w[i]<<' ';
		cout<<endl;
		CreateTreeandCode(HT,HC,j,w);
		for(i=1;i<=j*2-1;i++)
			printf("%d %d %d %d %d\n",HT[i].no,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
		for(i=1;i<=j;i++){
			ArrayList[i].word=s[i-1];
			ArrayList[i].code=HC[i];
			printf("%c:%s ",ArrayList[i].word,ArrayList[i].code);		
		}
		cout<<endl;
		MakeTranscode(code,ArrayList,j);
	}
	return 0;	
}

