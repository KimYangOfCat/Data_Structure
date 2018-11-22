#include <iostream>
#include "SqList.h"
using namespace std;


  //打印函数，应用于遍历中的访问函数 
void Print(const int &c)
{
   cout << c << "  ";
}


void main()
{    
   
    cout<<"1.创建顺序表："<<endl;    
    int n;
    cout << "请输入有序表A的长度：" << endl;
    cin >> n;
    SqList<int> la(n);
    la.Create(n);
    cout << endl;
    la.Traverse(Print);
    cout<<endl;

    cout<<"2. 对顺序表中元素进行插入删除操作："<<endl;
    la.Insert(30, 5);
    cout << "插入操作之后线性表：";
    la.Traverse(Print);
    cout << endl;

    int temp;
    la.Delete(temp, 7);
    cout << "删除操作之后线性表：";
    la.Traverse(Print);
    cout << endl;


    cout<<"3. 对顺序表中指定元素进行查找："<<endl;
    cout<<"请输入待查找的元素值："<<endl;
    int e;
    cin>>e;
    int i=la.Search(e);
    if(i!=-1)
	cout<<"待查找元素的位置为："<<i+1<<endl;
	else 
	cout<<"待查找元素不存在于该顺序表中。"<<endl;
}
