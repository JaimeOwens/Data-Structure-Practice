#include<iostream>
using namespace std;
template<class T>
class Queue{
private:	
	int maxSize;
	int front;
	int rear;
	int *queue;
	bool tag;
public:
	Queue(int size);
	~Queue(){delete []queue;}
	void Clear();
	bool EnQueue(const T item);
	bool DeQueue(T &item);
	bool GetFront(T &item);
	void disPlay();	
};
template<class T>
Queue<T>::Queue(int size){
	maxSize=size;
	queue=new T[maxSize];
	front=rear=0;
	tag=0;
}
template<class T>
void Queue<T>::Clear(){
	front=rear;
	tag=0;
}
template<class T>
bool Queue<T>::EnQueue(const T item){
	if(rear==front&&tag){
		//cout<<"FULL"<<endl;
		return false;
	}
	queue[rear] = item;
    rear = (rear + 1) % maxSize;
    tag = 1;
    return true;
}
template<class T>
bool Queue<T>::DeQueue(T &item){
	if(rear==front&&!tag){
		//cout<<"EMPTY"<<endl;
		return false;
	}
	item=queue[front];
	front=(front+1)%maxSize;
	tag=0;
	return true;
}
template<class T>
bool Queue<T>::GetFront(T &item){
	if(rear==front&&!tag){
		//cout<<"EMPTY"<<endl;
		return false;
	}
	item=queue[front];
	return true;
}
template<class T>
void Queue<T>::disPlay(){
	if(rear==front&&!tag){
		//cout<<"EMPTY"<<endl;
		return ; 
	}
	if(front==rear&&tag!=0){
		for(int i=0;i<maxSize-1;i++)
			cout<<queue[i]<<' ';
		cout<<queue[maxSize-1]<<endl;
	}
	for(int i=front;;i=(i+1)%maxSize){
		if(i==rear) break;
		if(i==rear-1) cout<<queue[i]<<endl;
		else cout<<queue[i]<<' ';
	}
	//cout<<endl;
}
int main() {
    int n;
    while(cin>>n){
    	if(n==0) break;
    	Queue<int> q(n);
    	int temp;
    	for(int i=0;i<n;i++){
    		cin>>temp;
    		q.EnQueue(temp);
		}
    	q.disPlay();	
	}
    return 0;
}
