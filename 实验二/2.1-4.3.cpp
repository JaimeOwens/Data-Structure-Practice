
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
struct Node//ջ�ṹ��
{
	float data;
	struct Node* next;
};

typedef struct Node* Stack;
typedef struct Node* Position;

Stack CreateStack()//����ջ
{
	Position s;
	s = (Position)malloc(sizeof(Node));
	s->next = NULL;
	return s;
}

int IsEmpty(Stack s)//�ж�ջ�Ƿ�Ϊ��
{
	return s->next == NULL;
}

void Pop(Stack s)//����ջ
{
	if (s->next != NULL)
	{
		Position first;
		first = s->next;
		s->next = s->next->next;
		free(first);
	}
}

void Push(float x, Stack s)//ѹ��ջ
{
	Position tempCell = (Position)malloc(sizeof(Node));
	tempCell->data = x;
	tempCell->next = s->next;
	s->next = tempCell;
}

float Top(Stack s)//�鿴ջ��Ԫ��
{
	return s->next->data;
}

int main()
{
	Stack s = CreateStack();
	char str[1000];
	int flag = 0;
	while (scanf("%s", str) != EOF)
	{
		float f;
		if (f=atof(str))
		{
			Push(f, s);
		}
		else
		{
			char ch = str[0];
			float a, b,c;
			if (!IsEmpty(s))
			{
				a = Top(s);
				Pop(s);
			}
			else
			{
				flag = 1;
				break;
			}
			if (!IsEmpty(s))
			{
				b = Top(s);
				Pop(s);
			}
			else
			{
				flag = 1;
				break;
			}
			switch (ch)
			{
			case '+':
				c = a + b;
				break;
			case '-':
				c = a - b;
				break;
			case '/':
				c = a / b;
				break;
			case '*':
				c = a * b;
				break;
			}
			Push(c, s);
		}
	}
	if (flag == 0)
	{
		printf("%.2f\n", s->next->data);
	}
	else
	{
		printf("ERROR\n");
	}
}
