#include <iostream>
#define MAX_VERTEX_NUM 20 //最大顶点个数

template <class VertexType>
class ALGraph
{ public:
    ALGraph(int m);   //构造函数
    int Locate(VertexType a);      //定位顶点在图中的位置，若顶点不在图中则返回-1，否则返回顶点的位序
	int FirstAdjVertex(VertexType a); //计算顶点的第一个邻接点位置
	int NextAdjVertex(VertexType a, VertexType b);//计算顶点a相对于顶点b 的下一个邻接点位置


	//本节课的程序练习部分,此处是三个待完善函数的函数声明，请根据函数声明，完成类体外部函数的实现。
	//以下函数请自行补充完整

    int Create();//利用输入的顶点信息和边信息 创建无向图	
	int InsertEdge(VertexType a, VertexType b); //向图中两个顶点间插入一条边     
    int FindDegree(VertexType a); //计算顶点的度





  private://数据成员

    int numVertices;     // 顶点个数
    int numEdges;        // 边或弧的条数
    VertexType vertices[MAX_VERTEX_NUM]; // 顶点信息，对无权图，
    int adjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //边(弧)信息
};




//构造函数，构造含m个顶点的无向图，默认 初始化的无向图只有顶点，没有边
template<class VertexType>
ALGraph<VertexType>::ALGraph(int m)  
{
   numVertices=m;
       for(int i=0;i<m;i++)
           for(int j=0;j<m;j++)
              adjMatrix[i][j]=0;
}

//定位顶点在图中的位置，若顶点不在图中则返回-1，否则返回顶点的位序
template<class VertexType>
int ALGraph<VertexType>::Locate(VertexType a)
{
    for(int i=0;i<numVertices;i++)
	{
		if(vertices[i]==a) 
			return i;
	}
	return -1;
}

//计算顶点a的第一个邻接点的位置
template<class VertexType>
int ALGraph<VertexType>::FirstAdjVertex(VertexType a)
{
    int i=Locate(a);
    if(i==-1) return -1;
	for(int j=0;j<numVertices;j++)
	{
           if(adjMatrix[i][j]!=0)
		   return j;
	}
	return -1;
}

//计算顶点a相对于顶点b 的下一个邻接点位置
template<class VertexType>
int  ALGraph<VertexType>::NextAdjVertex(VertexType a, VertexType b)
{
    int i=Locate(a);
	int j=Locate(b);
	if(i==-1||j==-1) return -1;
	for(int m=j+1;m<numVertices;m++)
		if(adjMatrix[i][m]==1)
			return m;
	return -1;

}


template<class VertexType>
int ALGraph<VertexType>::Create()    //利用用户在键盘上输入的边、顶点  创建无向图
{
  	cout<<"各顶点录入（用空格或回车分隔）："<<endl;
	for(int s=0;s<numVertices;s++)
	{
      //补充完整该部分程序，其功能是将接收到的顶点信息依次录入到vertices数组
	cin>>vertices[s];

	}	         
    cout<<"请输入图中边数："<<endl;
	int edgenum;
	cin>>edgenum;
	cout<<"各边录入：输入该边相关联的顶点值（用空格或回车分隔）："<<endl;
	for(int t=0;t<edgenum;t++)
	{
		VertexType a,b;
		cin>>a>>b;
	
		//补充完整该部分程序，其功能是接收到的a、b顶点间的边信息存入到邻接矩阵adjMatrix中，
		//若用户输入的顶点不在图中，函数返回-1，图无法创建。若两个顶点在图中则实现两点之间边的插入

		if(Locate(a)==-1||Locate(b)==-1)
			return -1;
		else
			adjMatrix[Locate(a)][Locate(b)]=1;

	}

    return 1;  
}


//在函数指定顶点a和b之间插入边。若插入成功返回1，若两点之间的边已经存在返回0，若顶点信息不合法返回-1。
template<class VertexType>
int ALGraph<VertexType>::InsertEdge(VertexType a, VertexType b)
{
    int i=Locate(a);
	int j=Locate(b);
	//补充完整该程序，实现上述功能
	if(i==-1||j==-1) 
		return -1;

	if(adjMatrix[i][j]==1)
		return 0;
	else
		adjMatrix[i][j]=1;

   return 1;
}



//计算顶点a的度。若顶点a存在于图中，则给出顶点a的度，若不存在该顶点，返回-1。
template<class VertexType>
int ALGraph<VertexType>::FindDegree(VertexType a)  
{
	int i=Locate(a);
	int j=FirstAdjVertex(a);
	int n=0;
	
	if(i==-1||j==-1) 
		return -1;
	else
		n++;
		while(NextAdjVertex(i,j)!=-1){
			if(NextAdjVertex(i,j)!=-1)
				n++;
			j=NextAdjVertex(i,j);
			
		}
	return n;

}


