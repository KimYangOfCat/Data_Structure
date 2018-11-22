#include <iostream>
#include "LinkList.h"
using namespace std;


 //��ӡ������Ӧ���ڱ����еķ��ʺ��� 
void Print(const int &c)
{
   cout << c << "  ";
}

/*/ �������Ա� 
void Create(List<int>*lx, int k,char c)
{
    int e;
    if (k > 0)
	{
        cout<<"����������"<< k << "��" << c << "���е�����Ԫ����" << endl;  
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

	
	cout<<"1. ���������"<<endl;
	cin>>m;
//	Create(&la,m,'A');
	cout<<"������������е�����Ԫ�أ�"<<endl;
	for(int i=0;i<m;i++)
	{
		int e;
		cin>>e;
		la.TailInsert(e);
	}
	cout<<"�����õ�������Ϊ��"<<m<<endl;
	cout<<"�����õ������е�����Ԫ��Ϊ��"<<endl;
	la.Traverse(Print);
	cout<<endl;


	cout<<"2. Ԫ�ض�λ��������һ�������ҵ�����Ԫ��ֵ��"<<endl;
	int n;
	cin>>n;
	la.LocateElem(n);
	if (la.LocateElem(n)==0)
		cout<<"�Ҳ���"<<endl;
	else
		cout<<"�ҵ���"<<endl;
	cout<<endl;
    

	cout<<"3. ��ָ��λ�ò���Ԫ�أ�"<<endl;
	int r,s;
	cout<<"�����������Ԫ�ص�λ�ã�"<<endl;
	cin>>r;
	cout<<"�����������Ԫ�ص�ֵ��"<<endl;
	cin>>s;
	la.Insert(s,r);
	cout<<"�����µ�Ԫ�غ���������Ϊ��"<<endl;
	la.Traverse(Print);
	cout<<endl;


	cout<<"4. �������ɾ������λ�ã�"<<endl;
	int t,u;
	cin>>t;
	la.Delete(u,t);
	cout<<"ɾ��ָ�����󣬵õ�������Ϊ��"<<endl;
	la.Traverse(Print);
	cout<<endl;


	cout<<"5. ���������á�"<<endl;
	la.Inverse();
	cout<<"���ú�ĵ�����Ϊ��";
	la.Traverse(Print);
    cout<<endl;

	cout<<"6. ɾ���������е���ͬԪ��"<<endl;
	la.LinkDel();
	cout<<"ɾ����ͬԪ�غ�õ��ĵ�����Ϊ��";
	la.Traverse(Print);
	cout<<endl;



}