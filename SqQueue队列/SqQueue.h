template<class ElemType>
class SqQueue
{
	private:
		ElemType *m_base;
		int m_front;
		int m_rear;
		int m_size;
	public:
		SqQueue(int m);
		~SqQueue();
		void Clear();
		bool IsEmpty();
		int Length();
		ElemType GetHead();
		ElemType GetLast();
		void Append(ElemType e);
		void Remove();
		void Traverse();
};

/*****-----构造函数-----*****/
template<class ElemType>
SqQueue<ElemType>::SqQueue(int m)
{
	m_front=m_rear=0;
	m_base=new ElemType[m];
	m_size=m;
}

/*****-----析构函数-----*****/
template<class ElemType>
SqQueue<ElemType>::~SqQueue()
{
	delete[] m_base;
}

/*****-----清空队列-----*****/
template<class ElemType>
void SqQueue<ElemType>::Clear()
{
	m_front=m_rear=0;
}

/*****-----判断循环队列是否为空-----*****/
template<class ElemType>
bool SqQueue<ElemType>::IsEmpty()
{
	return m_front==m_rear;
}

/*****-----求循环队列的真实长度-----*****/
template<class ElemType>
int SqQueue<ElemType>::Length()
{
	return (m_rear-m_front+m_size)%m_size;
}

/*****-----取队头元素-----*****/
template<class ElemType>
ElemType SqQueue<ElemType>::GetHead()
{
	return m_base[m_front];
}

/*****-----取队尾元素-----*****/
template<class ElemType>
ElemType SqQueue<ElemType>::GetLast()
{
	return m_base[(m_rear-1+m_size)%m_size];
}

/*****-----入队-----*****/
template<class ElemType>
void SqQueue<ElemType>::Append(ElemType e)
{
	if(m_front==(m_rear+1)%m_size)
	{
		ElemType *newbase;
		newbase=new ElemType[m_size+10];

		int i,k;
		for(i=m_front,k=0;(m_rear-i+m_size)%m_size>0;i=(i+1)%m_size,k++)
			newbase[k]=m_base[i];
		
		delete[] m_base;
		m_base=newbase;
		m_front=0;
		m_rear=k;
		m_size+=10;
	}
	m_base[m_rear]=e;
	m_rear=(m_rear+1)%m_size;
}

/*****-----出队-----*****/
template<class ElemType>
void SqQueue<ElemType>::Remove()
{
	m_front=(m_front+1)%m_size;
}

/*****-----对循环队列进行遍历-----*****/
template<class ElemType>
void SqQueue<ElemType>::Traverse()
{
	for(int j=m_front;(m_rear-j+m_size)%m_size>0;j=(j+1)%m_size)
		cout<<m_base[j]<<" ";
	cout<<endl;
}

