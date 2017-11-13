#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[1000000];

struct LNode{
	int num;
	LNode *next;
};
LNode *p,*r,*list;

/*利用单向循环链表实现*/
void joseph(int n, int m){//n：总人数；m：报数上限
	printf("\n%d个人报数，上限为%d \n",n,m);
	int i;
	//创建链表
	for(i=1;i<=n;i++){
		p = new LNode;
		p->num=i;
		if(list==NULL)
			list=p;
		else
			r->next=p;
		r=p;
	}

	p->next=list;//使链表循环
	p=list;//p指向头结点
	r=p;

	//x循环删除队列中的结点，即出列
	printf("出列者序列：");
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
	printf("\n最后留下的人是：%d\n",p->num);
}

/*选做：利用数组实现*/
void joseph2(int n,int m){//n：总人数；m：报数上限----顺序结构实现
	memset(a,1,sizeof(a));
	printf("\n%d个人报数，上限为%d \n",n,m);
	int i,j,cnt=1,people=n;
	printf("出列序列：");
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
			printf("\n最后留下者：%d\n",i);
			break;
		}
}

int main(){
	joseph(10,4);
	joseph(8,3);
	//joseph2(10,2);
	//joseph2(20,5);
	return 0;
}
