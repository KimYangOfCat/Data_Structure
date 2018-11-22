#include<stdlib.h>
#include <iostream>
using namespace std;
#include"SqList.h"
int main()
{
	SqList<int> l(20);
	int i, a, m, x;
	cout << "请输入顺序表的长度:" << endl;
	cin >> m;
	//从键盘输入10个整数，产生顺序表，并输入结点值
	for (i = 0; i<m; i++)
	{
		cout << "请输入顺序表中第" << i + 1 << "个元素的值：" << endl;
		cin >> a;
		l.Insert(a, i + 1);
	}
	//遍历建立顺序表，看是否正确
	l.Traverse();
	
	/*从键盘输入1个整数，在顺序表中查找该结点的位置。
	若找到，输出结点的位置；若找不到，则显示"找不到"。
	*/
	cout << "请输入要查找的结点的值:";
	cin >> i;
	cout << "它的位置是";
	if (l.LocateElem(i))
		cout << l.LocateElem(i) << endl;
	else
		cout << -1 << endl;
	

	cout << "请输入顺序表中某个节点的元素值:";
	cin >> i;
	cout << i << "的前驱是";
	if (l.LocatePrior(i))
		cout << l.LocatePrior(i) << endl;
	else
		cout << -1 << endl;
	
	cout << i << "的后继是";
	if (l.LocateNext(i))
		cout << l.LocateNext(i) << endl;
	else
		cout << -1 << endl;
	
	cout << "返回顺序表第三个元素的值，其值为：" << l.GetElem(3) << endl;
	cout << "请将顺序表中第i个位置的元素值修改为x"<<endl;
	cout << "输入i和x:";
	cin >> i;
	cin >> x;
	l.SetElem(x, i);
	cout << "第"<<i<<"个元素修改为" << x <<"后";
	l.Traverse();

	
	cout << "删除第i个位置的元素";
	cin >> i;
	if (l.Delete(i))
	{
		cout << "删除第"<<i<<"个元素后";
		l.Traverse();
	}
	system("pause");

	//（5）完成该顺序表的倒置操作、排序操作、合并操作。
	cout << "完成该顺序表的倒置操作、排序操作、合并操作"<<endl;
	l.Inversion();								//倒置函数
	cout << "*******倒置后**********" << endl;
	l.Traverse();
	l.Order();									//排序函数
	cout << "*******排序后**********" << endl;
	l.Traverse();
	cout << "合并操作";
	SqList<int> l1(20), l2(40);
	for (i = 0; i<m; i++)
	{
		//cout<<"请输入顺序表中第"<<i+1<<"个元素的值："<<endl;
		//cin>>a;
		l1.Insert(i * 10 + 1, i + 1);
	}
	l1.Traverse();
	l1.Combine(l);	//合并函数

	l1.Traverse();
	system("pause");
	return 0;
}