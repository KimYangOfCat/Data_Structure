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

	cout<<"1. ���������"<<endl;
	cin>>m;
    cout<<"������������е�����Ԫ�أ�"<<endl;
	for(int i=0;i<m;i++)
	{
		int e;
		cin>>e;
		la.TailInsert(e);
	}	
	cout<<"�����õ������е�����Ԫ��Ϊ��"<<endl;
	la.Traverse(Print);
	cout<<endl;


	cout<<"2. �������ɾ������λ�ã�"<<endl;
	int t,u;
	cin>>t;
	la.OrderDelete(u,t);
	cout<<"ɾ��ָ�����󣬵õ�������Ϊ��"<<endl;
	la.Traverse(Print);
	cout<<endl;


	cout<<"3. ���������á�"<<endl;
	la.Reverse(la);
	cout<<"���ú�ĵ�����Ϊ��";
	la.Traverse(Print);
    cout<<endl;

}