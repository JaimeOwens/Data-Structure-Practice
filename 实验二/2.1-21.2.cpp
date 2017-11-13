#include<iostream>  
#include<cstdlib>
#include<cstring>
using namespace std;  
void sort(int *a, int len)  
{  
        int i;  
        int dataLen = 1;  
        for(int j=len-1; j>=0; j--)  
                if(a[j] >= 0)  
                {  
                        i = j;  
                        break;  
                }  
  
        while(i > 0)  
        {  
                while(i>0 && a[i-1] >= 0)  
                {  
                        i--;  
                        dataLen++;  
                }  
                if(i == 0)  break; 
                int temp = a[i-1];  
                memcpy(&a[i-1], &a[i], dataLen*sizeof(int));
                a[i+dataLen-1] = temp;  
                i--;  
        }  
}  
int main()  
{  
   	int len;
   	while(cin>>len){
   		if(len==0) break;
   		int *a;
   		a=(int *)malloc(sizeof(int)*len);
   		for(int i=0;i<len;i++)
   			cin>>a[i];
		sort(a,len);  
        for(int i=0; i<len-1; i++)  
            cout<<a[i]<<' ';
		cout<<a[len-1]<<endl;	   
	}
    return 0;     
} 
