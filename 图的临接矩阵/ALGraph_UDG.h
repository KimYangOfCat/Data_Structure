#include <iostream>
#define MAX_VERTEX_NUM 20 //��󶥵����

template <class VertexType>
class ALGraph
{ public:
    ALGraph(int m);   //���캯��
    int Locate(VertexType a);      //��λ������ͼ�е�λ�ã������㲻��ͼ���򷵻�-1�����򷵻ض����λ��
	int FirstAdjVertex(VertexType a); //���㶥��ĵ�һ���ڽӵ�λ��
	int NextAdjVertex(VertexType a, VertexType b);//���㶥��a����ڶ���b ����һ���ڽӵ�λ��


	//���ڿεĳ�����ϰ����,�˴������������ƺ����ĺ�������������ݺ�����������������ⲿ������ʵ�֡�
	//���º��������в�������

    int Create();//��������Ķ�����Ϣ�ͱ���Ϣ ��������ͼ	
	int InsertEdge(VertexType a, VertexType b); //��ͼ��������������һ����     
    int FindDegree(VertexType a); //���㶥��Ķ�





  private://���ݳ�Ա

    int numVertices;     // �������
    int numEdges;        // �߻򻡵�����
    VertexType vertices[MAX_VERTEX_NUM]; // ������Ϣ������Ȩͼ��
    int adjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //��(��)��Ϣ
};




//���캯�������캬m�����������ͼ��Ĭ�� ��ʼ��������ͼֻ�ж��㣬û�б�
template<class VertexType>
ALGraph<VertexType>::ALGraph(int m)  
{
   numVertices=m;
       for(int i=0;i<m;i++)
           for(int j=0;j<m;j++)
              adjMatrix[i][j]=0;
}

//��λ������ͼ�е�λ�ã������㲻��ͼ���򷵻�-1�����򷵻ض����λ��
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

//���㶥��a�ĵ�һ���ڽӵ��λ��
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

//���㶥��a����ڶ���b ����һ���ڽӵ�λ��
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
int ALGraph<VertexType>::Create()    //�����û��ڼ���������ıߡ�����  ��������ͼ
{
  	cout<<"������¼�루�ÿո��س��ָ�����"<<endl;
	for(int s=0;s<numVertices;s++)
	{
      //���������ò��ֳ����书���ǽ����յ��Ķ�����Ϣ����¼�뵽vertices����
	cin>>vertices[s];

	}	         
    cout<<"������ͼ�б�����"<<endl;
	int edgenum;
	cin>>edgenum;
	cout<<"����¼�룺����ñ�������Ķ���ֵ���ÿո��س��ָ�����"<<endl;
	for(int t=0;t<edgenum;t++)
	{
		VertexType a,b;
		cin>>a>>b;
	
		//���������ò��ֳ����书���ǽ��յ���a��b�����ı���Ϣ���뵽�ڽӾ���adjMatrix�У�
		//���û�����Ķ��㲻��ͼ�У���������-1��ͼ�޷�������������������ͼ����ʵ������֮��ߵĲ���

		if(Locate(a)==-1||Locate(b)==-1)
			return -1;
		else
			adjMatrix[Locate(a)][Locate(b)]=1;

	}

    return 1;  
}


//�ں���ָ������a��b֮�����ߡ�������ɹ�����1��������֮��ı��Ѿ����ڷ���0����������Ϣ���Ϸ�����-1��
template<class VertexType>
int ALGraph<VertexType>::InsertEdge(VertexType a, VertexType b)
{
    int i=Locate(a);
	int j=Locate(b);
	//���������ó���ʵ����������
	if(i==-1||j==-1) 
		return -1;

	if(adjMatrix[i][j]==1)
		return 0;
	else
		adjMatrix[i][j]=1;

   return 1;
}



//���㶥��a�Ķȡ�������a������ͼ�У����������a�Ķȣ��������ڸö��㣬����-1��
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


