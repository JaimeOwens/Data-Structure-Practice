#include<string.h>
#include<string>
using namespace std;
#include<iostream>
typedef struct         
{
	char c;
	int weight;
}Alphabet;  //存放字母权值的结构体
typedef struct
{
	int weight;
	int parent, lchild, rchild;
}HTNode, *HuffmanTree;
Alphabet letter[26];
int Calculate(string s) // 统计各个字母的个数
{
	int num = 0;
	int i = 0;
	for (; i<26; i++)
	{
		letter[i].c = 97 + i; //a的ASCII为97 
		letter[i].weight = 0;
	}
	int xia = 0, j;   //下标为xia  
	for (j = 0; j<s.length(); j++)
	{
		xia = s[j] - 97;
		letter[xia].c = s[j];
		letter[xia].weight++;
	}
	for (i = 0; i<26; i++)
	{
		if (letter[i].weight != 0)
		{
			letter[num] = letter[i];
			num++;
		}
	}
	for (i = 0; i<num - 1; i++)
	{
		cout << letter[i].c << ":" << letter[i].weight << " ";
	}
	cout << letter[num - 1].c << ":" << letter[num - 1].weight << endl;
	return	num;
}

int Select(HuffmanTree &HT, int m)   // 挑选权值较小的值
{
	int min;
	for (int i = 1; i <= m; i++)
	{
		if (HT[i].parent == 0)
		{
			min = i;
			break;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		if (HT[i].parent == 0 && HT[i].weight<HT[min].weight)
			min = i;
	}
	return min;
}
void CreateHuffmanTree(HuffmanTree &HT, int n,int num)//创建哈弗曼树
{
	if (n <= 1)
		return;
	int m = 2 * n - 1;
	HT = new HTNode[m + 11];
	for (int i = 0; i<m; i++)
	{
		HT[i + 1].parent = HT[i + 1].lchild = HT[i + 1].rchild = 0;
	}
	for (int i = 0; i<num; i++)
	{
		HT[i + 1].weight = letter[i].weight;
	}
	//初始化工作结束
	for (int i = num + 1; i <= 2 * num - 1; i++)
	{
		int index1, index2;
		index1 = Select(HT, i - 1);
		HT[index1].parent = i;
		index2 = Select(HT, i - 1);
		HT[index2].parent = i;
		HT[i].lchild = index1;
		HT[i].rchild = index2;
		HT[i].weight = HT[index1].weight + HT[index2].weight;
	}
}
void Output(HuffmanTree &HT, int num)  //输出哈弗曼树的HT终态
{
	for (int i = 1; i <= 2 * num - 1; i++)
	{
		cout << i << " " << HT[i].weight << " " << HT[i].parent << " " << HT[i].lchild << " " << HT[i].rchild << endl;
	}
}
typedef char** HuffmanCode;   
void CodingHuffmanTree(HuffmanTree &HT, HuffmanCode &HC, int n)//从叶子节点到根，求每个字母的哈夫曼编码存到表
{
	char *cd;
	int start, c, f;
	cd = new char[n];
	cd[n - 1] = '\0';
	HC = new char*[n + 1];
	for (int i = 1; i <= n; ++i)
	{
		start = n - 1;
		c = i;
		f = HT[i].parent;
		while (f != 0)
		{
			--start;
			if (HT[f].lchild == c)
				cd[start] = '0';
			else
				cd[start] = '1';
			c = f;
			f = HT[f].parent;
		}
		HC[i] = new char[n - start];
		strcpy(HC[i], &cd[start]);
	}
	int i = 1;
	for (; i <= n - 1; i++)
	{
		cout << letter[i - 1].c << ":" << HC[i] << " ";
	}
	cout << letter[i - 1].c << ":" << HC[i] << endl;
	delete cd;
}
string t;  //设置安放编码的字符串；
void Output2(HuffmanTree HT, HuffmanCode HC, string s, int n) // 输出
{
	t.clear();
	for (int j = 0; j<s.length(); j++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (s[j] == letter[i - 1].c)
			{
				cout << HC[i];
				t += HC[i];
			}
		}
	}
	cout << endl;
}
void Translate(HuffmanTree HT, HuffmanCode HC, int n, string s)  //给哈夫曼编码解码
{
	if (n == 1)
		cout << letter[0].c << endl;
	else
	{
		int j = 0;
		int xia = 2 * n - 1;
		while (j<t.length())
		{
			if (t[j] == '0')
			{
				xia = HT[xia].lchild;
			}
			if (t[j] == '1')
			{
				xia = HT[xia].rchild;
			}
			if (!HT[xia].lchild&&!HT[xia].rchild)
			{
				cout << letter[xia - 1].c;
				xia = 2 * n - 1;
			}
			j++;
		}
	}
	cout<<endl;
}
int main()
{
	while (1)
	{
		HuffmanTree T;
		HuffmanCode HC;
		string s;
		int num;
		cin >> s;
		if (s == "0")
			break;
		num=Calculate(s);
		CreateHuffmanTree(T, num,num);
		Output(T, num);
		CodingHuffmanTree(T, HC, num);
		Output2(T, HC, s, num);
		Translate(T, HC, num, s);
	}
	return	0;
}
