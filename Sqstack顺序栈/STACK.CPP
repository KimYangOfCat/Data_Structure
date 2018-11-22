#include<iostream>
#include "Sqstack.h"

using namespace std;

//建立栈
void Create(Sqstack<char> *s, int k) {
	char e;
	if (k > 0) {
		cout << "请依次输入" << k << "个表中的数据元素：" << endl;
		for (int i = 1; i <= k; i++) {
			cin >> e;
			s->Push(e);
		}

	}
}

int main(){

	//初始化顺序栈从键盘输入5个字符压入栈，看是否为空。
	int m;
	cout << "1.输入表长：";
	cin >> m;
	Sqstack<char> la(m);
	Create(&la, m);
	cout << "创建好的栈的长度为：" << la.Length()<< endl;
	if (la.Empty())
		cout << "栈为空" << endl;
	else
		cout << "栈非空" << endl;
	
	//出栈两个字符，看栈中输出元素。
	int n;
	cout << "请输入出栈字符个数：";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout<<la.Top();
		la.Pop();
	}

	//再出栈三个字符，判断是否为空。
	int c;
	cout << "请输入出栈字符个数：";
	cin >> c;
	for (int j = 0; j < c; j++)
	{
		cout<<la.Top();
		la.Pop();
	}
	if (la.Empty())
		cout << "栈为空" << endl;
	else
		cout << "栈非空" << endl;

	//利用上面的栈进行数制装换，如10进制装换成8进制
	int a, b,num;
	int e = 0;
	cout << "输入你要转换的数制：";
	cin >> a;
	cout << "输入你想得到的数制：";
	cin >> b;
	cout << "输入你要转换的数：";
	cin >> num;
	Sqstack<int> lb(5);
	if (a > b) {
		while (num > 0)
		{
			lb.Push(num%b);
			num = num / b;
		}
	}
	while (!lb.Empty())
	{
		cout<<lb.Top();
		lb.Pop();
	}
	return 0;
}