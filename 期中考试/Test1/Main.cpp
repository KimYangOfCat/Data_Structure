#include <iostream>
#include "SqList.h"
using namespace std;


  //��ӡ������Ӧ���ڱ����еķ��ʺ��� 
void Print(const int &c)
{
   cout << c << "  ";
}


void main()
{    
   
    cout<<"1.����˳���"<<endl;    
    int n;
    cout << "�����������A�ĳ��ȣ�" << endl;
    cin >> n;
    SqList<int> la(n);
    la.Create(n);
    cout << endl;
    la.Traverse(Print);
    cout<<endl;

    cout<<"2. ��˳�����Ԫ�ؽ��в���ɾ��������"<<endl;
    la.Insert(30, 5);
    cout << "�������֮�����Ա�";
    la.Traverse(Print);
    cout << endl;

    int temp;
    la.Delete(temp, 7);
    cout << "ɾ������֮�����Ա�";
    la.Traverse(Print);
    cout << endl;


    cout<<"3. ��˳�����ָ��Ԫ�ؽ��в��ң�"<<endl;
    cout<<"����������ҵ�Ԫ��ֵ��"<<endl;
    int e;
    cin>>e;
    int i=la.Search(e);
    if(i!=-1)
	cout<<"������Ԫ�ص�λ��Ϊ��"<<i+1<<endl;
	else 
	cout<<"������Ԫ�ز������ڸ�˳����С�"<<endl;
}
