#include<stdlib.h>
#include <iostream>
using namespace std;
#include"SqList.h"
int main()
{
	SqList<int> l(20);
	int i, a, m, x;
	cout << "������˳���ĳ���:" << endl;
	cin >> m;
	//�Ӽ�������10������������˳�����������ֵ
	for (i = 0; i<m; i++)
	{
		cout << "������˳����е�" << i + 1 << "��Ԫ�ص�ֵ��" << endl;
		cin >> a;
		l.Insert(a, i + 1);
	}
	//��������˳������Ƿ���ȷ
	l.Traverse();
	
	/*�Ӽ�������1����������˳����в��Ҹý���λ�á�
	���ҵ����������λ�ã����Ҳ���������ʾ"�Ҳ���"��
	*/
	cout << "������Ҫ���ҵĽ���ֵ:";
	cin >> i;
	cout << "����λ����";
	if (l.LocateElem(i))
		cout << l.LocateElem(i) << endl;
	else
		cout << -1 << endl;
	

	cout << "������˳�����ĳ���ڵ��Ԫ��ֵ:";
	cin >> i;
	cout << i << "��ǰ����";
	if (l.LocatePrior(i))
		cout << l.LocatePrior(i) << endl;
	else
		cout << -1 << endl;
	
	cout << i << "�ĺ����";
	if (l.LocateNext(i))
		cout << l.LocateNext(i) << endl;
	else
		cout << -1 << endl;
	
	cout << "����˳��������Ԫ�ص�ֵ����ֵΪ��" << l.GetElem(3) << endl;
	cout << "�뽫˳����е�i��λ�õ�Ԫ��ֵ�޸�Ϊx"<<endl;
	cout << "����i��x:";
	cin >> i;
	cin >> x;
	l.SetElem(x, i);
	cout << "��"<<i<<"��Ԫ���޸�Ϊ" << x <<"��";
	l.Traverse();

	
	cout << "ɾ����i��λ�õ�Ԫ��";
	cin >> i;
	if (l.Delete(i))
	{
		cout << "ɾ����"<<i<<"��Ԫ�غ�";
		l.Traverse();
	}
	system("pause");

	//��5����ɸ�˳���ĵ��ò���������������ϲ�������
	cout << "��ɸ�˳���ĵ��ò���������������ϲ�����"<<endl;
	l.Inversion();								//���ú���
	cout << "*******���ú�**********" << endl;
	l.Traverse();
	l.Order();									//������
	cout << "*******�����**********" << endl;
	l.Traverse();
	cout << "�ϲ�����";
	SqList<int> l1(20), l2(40);
	for (i = 0; i<m; i++)
	{
		//cout<<"������˳����е�"<<i+1<<"��Ԫ�ص�ֵ��"<<endl;
		//cin>>a;
		l1.Insert(i * 10 + 1, i + 1);
	}
	l1.Traverse();
	l1.Combine(l);	//�ϲ�����

	l1.Traverse();
	system("pause");
	return 0;
}