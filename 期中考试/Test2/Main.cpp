#include <iostream>
#include "LinkList.h"
using namespace std;

void Print(const int &c)
{
   cout << c << "  ";
}


void main(){
    LinkList<int> la;
	int m;

	cout<<"1. 请输入表长："<<endl;
	cin>>m;
    cout<<"请依次输入表中的数据元素："<<endl;
	for(int i=0;i<m;i++)
	{
		int e;
		cin>>e;
		la.TailInsert(e);
	}	
	cout<<"创建好的链表中的数据元素为："<<endl;
	la.Traverse(Print);
	cout<<endl;


	cout<<"2. 请输入待删除结点的位置："<<endl;
	int t,u;
	cin>>t;
	la.OrderDelete(u,t);
	cout<<"删除指定结点后，得到的链表为："<<endl;
	la.Traverse(Print);
	cout<<endl;


	cout<<"3. 单链表逆置。"<<endl;
	la.Reverse(la);
	cout<<"逆置后的单链表为：";
	la.Traverse(Print);
    cout<<endl;

}