#include "ALGraph_UDG.h"
using namespace std;
#include <iostream>

void main()
{
	//������P158ҳ ����ͼG2Ϊ���������е�������㣬�ֱ��滻Ϊa,b,c,d,e��Ȼ��������²���

	cout<<"������ͼ�ж�������"<<endl;
	int n;
	cin>>n;
	ALGraph<char> G(n);
	char e;
	G.Create();

	//���²���FindDegree������������ 
	cout<<"���ڼ���ָ������Ķȣ����������������Ķ����ֵ��"<<endl;
    cin>>e;
	cout<<"�ö���Ķ�Ϊ��"<<G.FindDegree(e)<<endl;
	

    //���²���InsertEdge������������ 
	cout<<"����ʵ�֡�����������֮�����һ���ߡ���������ñ������������������ֵ��"<<endl;
	char c1,c2;
	cin>>c1>>c2;
	int m=G.InsertEdge(c1,c2);
	switch(m)
	{
	case -1:
		cout<<"������Ϣ�Ƿ�"<<endl;
		break;
	case 0:
		cout<<"�ñ���ͼ���Ѿ�����"<<endl;
		break;
	case 1:
		cout<<"���Ѿ����ɹ�����"<<endl;
		break;
	}
	cout<<"��������"<<c1<<"����Ķ�Ϊ��"<<G.FindDegree(c1)<<endl;



    //���������������������ֺ�����ʵ������ѧϰ

	cout<<"������һ�����㣬�����һ���ڽӵ�λ�ã�"<<endl;
    char c;
	cin>>c;
	cout<<"��һ���ڽӵ�λ�ã�"<<G.FirstAdjVertex(c)<<endl;


    cout<<"����ĳ�����������һ�������һ���ڽӵ��λ�ã��������������ֵ��"<<endl;
	char ch1,ch2;
	cin>>ch1>>ch2;
	cout<<ch1<<"���������"<<ch2<<"�������һ���ڽӵ��λ��Ϊ��"<<G.NextAdjVertex(ch1,ch2)<<endl;





}