#include <iostream>
#include "LinkList.h"
using namespace std;


 //打印函数，应用于遍历中的访问函数 
void Print(const int &c)
{
   cout << c << "  ";
}

/*/ 建立线性表 
void Create(List<int>*lx, int k,char c)
{
    int e;
    if (k > 0)
	{
        cout<<"请依次输入"<< k << "个" << c << "表中的数据元数：" << endl;  
        for (int i = 1;i <= k; i++)
		{
            cin >> e;
            lx->TailInsert(e);
        }    
    }
}
*/

void main(){
    LinkList<int> la;
	int m;

	
	cout<<"1. 请输入表长："<<endl;
	cin>>m;
//	Create(&la,m,'A');
	cout<<"请依次输入表中的数据元素："<<endl;
	for(int i=0;i<m;i++)
	{
		int e;
		cin>>e;
		la.TailInsert(e);
	}
	cout<<"创建好的链表长度为："<<m<<endl;
	cout<<"创建好的链表中的数据元素为："<<endl;
	la.Traverse(Print);
	cout<<endl;


	cout<<"2. 元素定位。请输入一个待查找的数据元素值："<<endl;
	int n;
	cin>>n;
	la.LocateElem(n);
	if (la.LocateElem(n)==0)
		cout<<"找不到"<<endl;
	else
		cout<<"找到了"<<endl;
	cout<<endl;
    

	cout<<"3. 在指定位置插入元素："<<endl;
	int r,s;
	cout<<"请输入待插入元素的位置："<<endl;
	cin>>r;
	cout<<"请输入待插入元素的值："<<endl;
	cin>>s;
	la.Insert(s,r);
	cout<<"插入新的元素后，链表现在为："<<endl;
	la.Traverse(Print);
	cout<<endl;


	cout<<"4. 请输入待删除结点的位置："<<endl;
	int t,u;
	cin>>t;
	la.Delete(u,t);
	cout<<"删除指定结点后，得到的链表为："<<endl;
	la.Traverse(Print);
	cout<<endl;


	cout<<"5. 单链表逆置。"<<endl;
	la.Inverse();
	cout<<"逆置后的单链表为：";
	la.Traverse(Print);
    cout<<endl;

	cout<<"6. 删除单链表中的相同元素"<<endl;
	la.LinkDel();
	cout<<"删除相同元素后得到的单链表为：";
	la.Traverse(Print);
	cout<<endl;



}