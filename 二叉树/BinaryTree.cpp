#include <iostream>
#include "BinaryTree.h"
using namespace std;

void Print(const char &c){
   cout<<c<<"  ";
}

void main(){
    
	cout<<"1. �������������������"<<endl;
	BinaryTree<char> bt1, bt2;
	char ch1[20];
	char ch2[20];
	cout<<"������Ŀ�������������������У�"<<endl;
	cin>>ch1;
	cout<<"������Ŀ�������������������У�"<<endl;
	cin>>ch2;
	/*
	cout<<"Test:����ͨ����������abd##e##cf###���������������:"<<endl;
	bt1.Create1(ch1,'#');
    */

	int n=0;
    while(ch1[n]) 
       n++;
    bt1.Create2(ch1,ch2,n);

	cout<<"�Ե�ǰ�������������������Ϊ��";
	bt1.PreorderTraverse(Print);
	cout<<endl;
	cout<<"�Ե�ǰ�������������������Ϊ��";
	bt1.InorderTraverse(Print);
	cout<<endl;
	cout<<"�Ե�ǰ�������ĺ����������Ϊ��";
	bt1.PostorderTraverse(Print);
	cout<<endl<<endl;
	cout<<"�������Ķ���������Ҷ���ĸ���Ϊ��";
	cout<<bt1.CountLeaf()<<endl<<endl;
	cout<<"�������Ķ������н��ֵΪ�����Ľ�����Ϊ��"<<bt1.CountOdd()<<endl;
	cout<<"�������Ķ������н�����Ϊ��"<<bt1.CountNum()<<endl;



	cout<<"2. ���ָ���������Һ��ӽ��ֵ��"<<endl;
	BTNode<char> *p,*q,*r;
	cout<<"����������ָ���Ľ�㣺"<<endl;
	char e;
	cin>>e;
	p=bt1.Locate(e);
	if(p)
	{
		q=bt1.LeftChild(p);
		if(q)
		{
			cout<<e<<"�������ӽ��ֵΪ��";
			cout<<q->data<<endl;
		}
		else
		{
			cout<<e<<"��������ӽ�㡣"<<endl;
		}

		r=bt1.RightChild(p);
		if(r)
		{
       		cout<<e<<"�����Һ��ӽ��ֵΪ��";
			cout<<r->data<<endl;
		}
	    else
		{
		    cout<<e<<"������Һ��ӽ�㡣"<<endl;
		}
	}
	else
	{
	   cout<<"����Ľ�㲻����!"<<endl;
	}

	cout<<endl<<endl;


	cout<<"3. �������ǰ����������ȡ�"<<endl;
	cout<<bt1.Depth()<<endl;


	cout<<"4. ���������루InsertChild��������ϰ��"<<endl;
	char ch3[20],ch4[20];
	cout<<"����������������������������У�"<<endl;
	cin>>ch3;
	cout<<"����������������������������У�"<<endl;
	cin>>ch4;
	int j=0;
	while(ch3[j])
		j++;
	bt2.Create2(ch3,ch4,j);
	cout<<"�����������λ�ô��Ľ��ֵ��"<<endl;
	char f;
	cin>>f;
    BTNode<char> *s;
	s=bt1.Locate(f);
	if(s)
	{
		cout<<"��ȷ��Ҫ����Ϊ�����������������ı�ʶ��0�����Ϊ��������1�����Ϊ����������"<<endl;
		int LR;
		cin>>LR;
		bt1.InsertChild(s,LR,bt2);
		cout<<"�����Դ�������������������Ϊ��";
		bt1.PreorderTraverse(Print);
		cout<<endl;
	}
	else
	{
		cout<<"����Ľ�㲻����!"<<endl;
	}


}