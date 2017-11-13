#include<iostream>
#include<cstring>
#include<map>
using namespace std;
int main(){
	char str[200];
	while(cin>>str){
		if(str[0]=='0') break;
		map<char,int> m;
		for(int i=48;i<=57;i++)
			m.insert(pair<char,int>((char)i,0));
		for(int i=65;i<=90;i++)
			m.insert(pair<char,int>((char)i,0));
		for(int i=0;i<strlen(str);i++)
			if(m.count(str[i]))
				m[str[i]]++;
		for (map<char, int>::iterator it = m.begin(); it != m.end(); it++)
			if(it->second)
				cout <<it->first<<':'<<it->second<<endl;
	}
	return 0;
}
