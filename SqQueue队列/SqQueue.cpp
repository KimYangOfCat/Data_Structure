#include <iostream>
using namespace std;
#include"SqQueue.h"

int main()
{
	SqQueue<char> s(10);
	char c;
	cout<<"---------(1)��ʼ��ѭ�����У��Ӽ�������5���ַ���ӣ����Ƿ�Ϊ��----------"<<endl<<endl;
	cout<<"���������Ԫ����ӣ�"<<endl;
	for(int i=1;i<=5;i++)
	{
		cout<<"�������"<<i<<"��Ԫ����ӣ�";
		cin>>c;
		s.Append(c);
	}
	
	cout<<"��ʱ�Ķ��п����ж�һ�£�"<<endl;
	if(s.Length())
	{
		cout<<"��ʱ�Ķ��в��գ�����Ϊ��"<<s.Length()<<",   ��ʱ���дӶ�ͷ����β��˳��Ϊ:";
		s.Traverse();
	}
	else
		cout<<"��ʱ�Ķ���Ϊ�գ���"<<endl;

	cout<<endl<<endl;
	cout<<"---------(2)��MAXSIZE��Ϊ5�������1��Ԫ�أ��ж�������----------"<<endl<<endl;
	cout<<"�������һ��Ԫ�أ�";
	cin>>c;
	s.Append(c);
	cout<<"��ʱ���дӶ�ͷ����β��˳��Ϊ:";
	s.Traverse();

	cout<<endl<<endl;
	cout<<"---------(3)�ٳ����������ַ����ж��Ƿ�Ϊ�գ������ʱ������Ԫ�صĸ���-------"<<endl<<endl;
	cout<<"���ӵ�һ��Ԫ��Ϊ��"<<s.GetHead()<<endl;
	s.Remove();
	cout<<"���ӵ�һ��Ԫ��Ϊ��"<<s.GetHead()<<endl;
	s.Remove();
	cout<<"���ӵ�һ��Ԫ��Ϊ��"<<s.GetHead()<<endl;
	s.Remove();
	cout<<"��������Ԫ�أ���ʱ�Ķ���Ϊ�������ж�һ��:"<<endl;
	if(s.Length())
	{
		cout<<"��ʱ�Ķ��в��գ�����Ϊ��"<<s.Length()<<",   ��ʱ���дӶ�ͷ����β��˳��Ϊ:";
		s.Traverse();
	}
	else
		cout<<"��ʱ�Ķ���Ϊ�գ���"<<endl;
	
	cout<<endl<<endl;
	cout<<"---------(4)����������ַ��������������----------"<<endl<<endl;
	cin>>c;
	s.Append(c);
	cin>>c;
	s.Append(c);
	cout<<"�������Ԫ�غ󣬴�ʱ�Ķ���Ϊ��";
	s.Traverse();
	return 0;
}