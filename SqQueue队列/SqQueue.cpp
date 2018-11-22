#include <iostream>
using namespace std;
#include"SqQueue.h"

int main()
{
	SqQueue<char> s(10);
	char c;
	cout<<"---------(1)初始化循环队列，从键盘输入5个字符入队，看是否为空----------"<<endl<<endl;
	cout<<"请输入五个元素入队："<<endl;
	for(int i=1;i<=5;i++)
	{
		cout<<"请输入第"<<i<<"个元素入队：";
		cin>>c;
		s.Append(c);
	}
	
	cout<<"此时的队列空吗？判断一下！"<<endl;
	if(s.Length())
	{
		cout<<"此时的队列不空，长度为："<<s.Length()<<",   此时队列从队头到队尾的顺序为:";
		s.Traverse();
	}
	else
		cout<<"此时的队列为空！！"<<endl;

	cout<<endl<<endl;
	cout<<"---------(2)若MAXSIZE设为5，再入队1个元素，判断输出情况----------"<<endl<<endl;
	cout<<"请在入队一个元素：";
	cin>>c;
	s.Append(c);
	cout<<"此时队列从对头到队尾的顺序为:";
	s.Traverse();

	cout<<endl<<endl;
	cout<<"---------(3)再出队列三个字符，判断是否为空，输出此时队列中元素的个数-------"<<endl<<endl;
	cout<<"出队第一个元素为："<<s.GetHead()<<endl;
	s.Remove();
	cout<<"出队第一个元素为："<<s.GetHead()<<endl;
	s.Remove();
	cout<<"出队第一个元素为："<<s.GetHead()<<endl;
	s.Remove();
	cout<<"出队三个元素，此时的队列为空吗？请判断一下:"<<endl;
	if(s.Length())
	{
		cout<<"此时的队列不空，长度为："<<s.Length()<<",   此时队列从队头到队尾的顺序为:";
		s.Traverse();
	}
	else
		cout<<"此时的队列为空！！"<<endl;
	
	cout<<endl<<endl;
	cout<<"---------(4)再入队两个字符，输出出队序列----------"<<endl<<endl;
	cin>>c;
	s.Append(c);
	cin>>c;
	s.Append(c);
	cout<<"入队两个元素后，此时的队列为：";
	s.Traverse();
	return 0;
}