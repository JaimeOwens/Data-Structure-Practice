#include<cstring>
#include<iostream>
using namespace std;
typedef struct{
	char c;
	int weight;
}Alphabet;
typedef struct{
	int weight;
	int parent;
	int lchild;
	int rchild;
}HTNode,*HuffmanTree;
typedef char** HuffmanCode;
Alphabet letter[26];
int Calculate(string s){
	int num=0;
	for(int i=0;i<26;i++){
		letter[i].c=97+i;
		letter[i].weight=0;
	}
	int index=0;
	for(int i=0;i<s.length();i++){
		index=s[i]-97;
		letter[index].c=s[i];
		letter[index].weight++;
	}
	for(int i=0;i<26;i++)
		if(letter[i].weight!=0)
			letter[num++]=letter[i];
	for(int i=0;i<num-1;i++)
		cout<<letter[i].c<<':'<<letter[i].weight<<' '; 
	cout<<letter[num-1].c<<':'<<letter[num-1].weight<<endl;
	return num;
}
int Select(HuffmanTree &HT,int m){
	int min;
	for(int i=1;i<=m;i++)
		if(HT[i].parent==0){ min=i;break; }
	for(int i=1;i<=m;i++)
		if(HT[i].weight==0&&HT[i].weight<HT[min].weight)
			min=i;
	return min;			
}
void CreateHuffmanTree(HuffmanTree &HT,int n,int num){
	if(n<=1) return;
	int m=2*n-1;
	HT=new HTNode[m+11];
	for(int i=0;i<m;i++)
		HT[i+1].parent=HT[i+1].lchild=HT[i+1].rchild=0;
	for(int i=0;i<num;i++)
		HT[i+1].weight=letter[i].weight;
	for(int i=num+1;i<=2*num-1;i++){
		int index1,index2;
		index1=Select(HT,i-1);
		HT[index1].parent=i;
		index2=Select(HT,i-1);
		HT[index2].parent=i;
		HT[i].lchild=index1;
		HT[i].rchild=index2;
		HT[i].weight=HT[index1].weight+HT[index2].weight;
	}	
}
void Print(HuffmanTree &HT,int num){
	for(int i=1;i<=2*num-1;i++)
		cout << i <<' '<< HT[i].weight <<' '<< HT[i].parent <<' '<< HT[i].lchild <<' '<< HT[i].rchild << endl;
}
void CodingHuffmanTree(HuffmanTree &HT,HuffmanCode &HC,int n){
	char *cd;
	int start,c,f;
	cd=new char[n];
	cd[n-1]='\0';
	HC=new char*[n+1];
	for(int i=1;i<=n;i++){
		start=n-1;
		c=i;
		f=HT[i].parent;
		while(f!=0){
			--start;
			if(HT[f].lchild==c)
				cd[start]='0';
			else
				cd[start]='1';
			c=f;
			f=HT[f].parent;	
		}
		HC[i]=new char[n-start];
		strcpy(HC[i],&cd[start]);
	}
	int i;
	for(i=1;i<=n-1;i++)
		cout<<letter[i-1].c<<':'<<HC[i]<<' ';
	cout << letter[i - 1].c <<':'<< HC[i] << endl;	
	delete cd;
}
string t;
void Output(HuffmanTree HT,HuffmanCode HC,string s,int n){
	t.clear();
	for(int j=0;j<s.length();j++)
		for(int i=1;i<=n;i++)
			if(s[j]==letter[i-1].c){
				cout<<HC[i];
				t+=HC[i];
			}
	cout << endl;		
}
void Translate(HuffmanTree HT,HuffmanCode HC,string s,int n){
	if(n==1) cout<<letter[0].c<<endl;
	else{
		int j=0;
		int index=2*n-1;
		while(j<t.length()){
			if(t[j]=='0') index=HT[index].lchild;
			if(t[j]=='1') index=HT[index].rchild;
			if(!HT[index].lchild&&!HT[index].rchild){
				cout<<letter[index-1].c;
				index=2*n-1;
			}
			j++;
		}
	}
	cout<<endl;
}
int main(){
	while(1){
		HuffmanTree HT;
		HuffmanCode HC;
		string s;
		int num;
		cin>>s;
		if(s=="0") break;
		num=Calculate(s);
		CreateHuffmanTree(HT,num,num);
		Print(HT,num);
		CodingHuffmanTree(HT,HC,num);
		Output(HT,HC,s,num);
		Translate(HT,HC,s,num);	
	}
	return 0;
}
