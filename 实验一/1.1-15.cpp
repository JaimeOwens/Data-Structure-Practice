#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int a[1000000];

typedef struct LNode{
	int num;
	struct LNode *next;
}LNode,*LoopList;
//LoopList p,r,list;
/*利用单向循环链表实现*/
/*void joseph(int n, int m){//n：总人数；m：报数上限
	int i;
	LoopList p,r,list;
	r=new LNode;
	r->next=NULL;
	//list=new LNode;
	//list->next=NULL;
	for(i=1;i<=n;i++){
		p = new LNode;
		p->num=i;
		if(i==1)
			list=p;
		else
			r->next=p;
		r=p;
	}
	p->next=list;//使链表循环
	p=list;//p指向头结点
	r=p;
	while(p->next!=p){
		for(i=1;i<m;i++){
			r=p;
			p=p->next;
		}
		r->next=p->next;
		printf("%d ",p->num);
		delete p;
		p=r->next;
	}
	printf("%d\n",p->num);
}*/
//利用数组实现
void joseph2(int n,int m){//n：总人数；m：报数上限----顺序结构实现
	memset(a,1,sizeof(a));
	//printf("\n%d个人报数，上限为%d \n",n,m);
	int i,j,cnt=1,people=n;
	//printf("出列序列：");
	for(i=1;i<=n;i++){
		if(people>1){
			if(a[i]){
				cnt++;
				if(cnt==m+1){
					a[i]=0;
					printf("%d ",i);
					people--;
					cnt=1;
				}
			}
		}
		else
			break;
		if(i==n)
			i=0;
	}
	for(i=1;i<=n;i++)
		if(a[i]){
			printf("%d\n",i);
			break;
		}
}
//*/
int main(){
	int n,m;
	while(cin>>n>>m){
		if(n==0&&m==0) break;	
		joseph2(n,m);
	}
	return 0;
}
