#include <iostream>
#include "BinaryTree.h"
using namespace std;

void Print(const char &c){
   cout<<c<<"  ";
}

void main(){
    
	cout<<"1. 建立二叉树，并输出。"<<endl;
	BinaryTree<char> bt1, bt2;
	char ch1[20];
	char ch2[20];
	cout<<"请输入目标二叉树的先序遍历序列："<<endl;
	cin>>ch1;
	cout<<"请输入目标二叉树的中序遍历序列："<<endl;
	cin>>ch2;
	/*
	cout<<"Test:按变通的先序序列abd##e##cf###创建二叉树并输出:"<<endl;
	bt1.Create1(ch1,'#');
    */

	int n=0;
    while(ch1[n]) 
       n++;
    bt1.Create2(ch1,ch2,n);

	cout<<"对当前二叉树的先序遍历序列为：";
	bt1.PreorderTraverse(Print);
	cout<<endl;
	cout<<"对当前二叉树的中序遍历序列为：";
	bt1.InorderTraverse(Print);
	cout<<endl;
	cout<<"对当前二叉树的后序遍历序列为：";
	bt1.PostorderTraverse(Print);
	cout<<endl<<endl;
	cout<<"所创建的二叉树中树叶结点的个数为：";
	cout<<bt1.CountLeaf()<<endl<<endl;
	cout<<"所创建的二叉树中结点值为奇数的结点个数为："<<bt1.CountOdd()<<endl;
	cout<<"所创建的二叉树中结点个数为："<<bt1.CountNum()<<endl;



	cout<<"2. 输出指定结点的左、右孩子结点值。"<<endl;
	BTNode<char> *p,*q,*r;
	cout<<"请输入树中指定的结点："<<endl;
	char e;
	cin>>e;
	p=bt1.Locate(e);
	if(p)
	{
		q=bt1.LeftChild(p);
		if(q)
		{
			cout<<e<<"结点的左孩子结点值为：";
			cout<<q->data<<endl;
		}
		else
		{
			cout<<e<<"结点无左孩子结点。"<<endl;
		}

		r=bt1.RightChild(p);
		if(r)
		{
       		cout<<e<<"结点的右孩子结点值为：";
			cout<<r->data<<endl;
		}
	    else
		{
		    cout<<e<<"结点无右孩子结点。"<<endl;
		}
	}
	else
	{
	   cout<<"输入的结点不存在!"<<endl;
	}

	cout<<endl<<endl;


	cout<<"3. 请输出当前二叉树的深度。"<<endl;
	cout<<bt1.Depth()<<endl;


	cout<<"4. 有条件插入（InsertChild操作）练习。"<<endl;
	char ch3[20],ch4[20];
	cout<<"请输入待插入二叉树的先序遍历序列："<<endl;
	cin>>ch3;
	cout<<"请输入待插入二叉树的中序遍历序列："<<endl;
	cin>>ch4;
	int j=0;
	while(ch3[j])
		j++;
	bt2.Create2(ch3,ch4,j);
	cout<<"请输入待插入位置处的结点值："<<endl;
	char f;
	cin>>f;
    BTNode<char> *s;
	s=bt1.Locate(f);
	if(s)
	{
		cout<<"请确定要插入为左子树还是右子树的标识（0代表插为左子树，1代表插为右子树）："<<endl;
		int LR;
		cin>>LR;
		bt1.InsertChild(s,LR,bt2);
		cout<<"插入后，源二叉树的先序遍历序列为：";
		bt1.PreorderTraverse(Print);
		cout<<endl;
	}
	else
	{
		cout<<"输入的结点不存在!"<<endl;
	}


}