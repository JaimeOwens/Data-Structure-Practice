#include <iostream>
#include "SqList.cpp"
using namespace std;
int main(){
    CList <int> C1;
    CList <float> C2;
    cout << "表的初始信息输出测试：" << endl;
    cout<<"C1和C2的初始容量为："<<C1.GetLength()<<'\t'<< C2.GetLength()<<endl;
    cout<<"C1和C2的初始长度为："<<C2.GetSize()<<'\t'<<C2.GetSize()<<endl;
    cout << endl;
    //在表的尾部新增一些元素并显示
    cout << "表元素添加测试：" << endl;
    for (int i = 1; i <= 10; i++)
    {
        C1.AddTail(2 * i);
        C2.AddTail(i*i+0.1);
    }
    cout << "C1所有元素为:\n";
    C1.ShowValues();
    cout << "C2所有元素为:\n";
    C2.ShowValues();
    cout << endl;
    //在表的指定位置插入元素
    cout << "表元素插入测试："<<endl;
    C1.InsertAt(5,11);
    C2.InsertAt(7,22.2);
    cout << "C1所有元素为:\n";
    C1.ShowValues();
    cout << "C2所有元素为:\n";
    C2.ShowValues();
    cout << endl;
    //显示表指定位置的值
    cout << "表元素索引测试："<<endl;
    cout<<"C1和C2索引5对应的节点的值分别为："<<C1.GetAt(5)<<'\t'<<C2.GetAt(5)<<endl;
    cout<<endl;
    //删除表中指定位置的值
    cout << "表元素删除测试：" << endl;
    C1.RemoveAt(3, 2);
    C2.RemoveAt(4);
    cout << "C1所有元素为:\n";
    C1.ShowValues();
    cout << "C2所有元素为:\n";
    C2.ShowValues();
    cout << endl;
    system("pause");
    return 0;
}