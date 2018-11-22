#include "ALGraph_UDG.h"
using namespace std;
#include <iostream>

void main()
{
	//以书中P158页 无向图G2为例，将其中的五个顶点，分别替换为a,b,c,d,e。然后进行如下操作

	cout<<"请输入图中顶点数："<<endl;
	int n;
	cin>>n;
	ALGraph<char> G(n);
	char e;
	G.Create();

	//以下测试FindDegree函数的输出结果 
	cout<<"现在计算指定顶点的度，请输入待计算度数的顶点的值："<<endl;
    cin>>e;
	cout<<"该顶点的度为："<<G.FindDegree(e)<<endl;
	

    //以下测试InsertEdge函数的输出结果 
	cout<<"现在实现“在两个顶点之间插入一条边”，请输入该边所关联的两个顶点的值："<<endl;
	char c1,c2;
	cin>>c1>>c2;
	int m=G.InsertEdge(c1,c2);
	switch(m)
	{
	case -1:
		cout<<"顶点信息非法"<<endl;
		break;
	case 0:
		cout<<"该边在图中已经存在"<<endl;
		break;
	case 1:
		cout<<"边已经被成功插入"<<endl;
		break;
	}
	cout<<"顶点插入后"<<c1<<"顶点的度为："<<G.FindDegree(c1)<<endl;



    //测试其他函数，这两部分函数的实现自行学习

	cout<<"请输入一个顶点，求其第一个邻接点位置："<<endl;
    char c;
	cin>>c;
	cout<<"第一个邻接点位置："<<G.FirstAdjVertex(c)<<endl;


    cout<<"计算某顶点相对于另一顶点的下一个邻接点的位置，请输入两顶点的值："<<endl;
	char ch1,ch2;
	cin>>ch1>>ch2;
	cout<<ch1<<"顶点相对于"<<ch2<<"顶点的下一个邻接点的位置为："<<G.NextAdjVertex(ch1,ch2)<<endl;





}