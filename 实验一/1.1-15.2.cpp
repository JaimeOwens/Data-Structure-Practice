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

/*���õ���ѭ������ʵ��*/
void joseph(int n, int m){//n����������m����������
	printf("\n%d���˱���������Ϊ%d \n",n,m);
	int i;
	//��������
	for(i=1;i<=n;i++){
		p = new LNode;
		p->num=i;
		if(list==NULL)
			list=p;
		else
			r->next=p;
		r=p;
	}

	p->next=list;//ʹ����ѭ��
	p=list;//pָ��ͷ���
	r=p;

	//xѭ��ɾ�������еĽ�㣬������
	printf("���������У�");
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
	printf("\n������µ����ǣ�%d\n",p->num);
}

/*ѡ������������ʵ��*/
void joseph2(int n,int m){//n����������m����������----˳��ṹʵ��
	memset(a,1,sizeof(a));
	printf("\n%d���˱���������Ϊ%d \n",n,m);
	int i,j,cnt=1,people=n;
	printf("�������У�");
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
			printf("\n��������ߣ�%d\n",i);
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
