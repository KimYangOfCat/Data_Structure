template<class ElemType>
class Sqstack
{
public:
	Sqstack(int m);//构造函数
	~Sqstack();//析构函数
	void Clear();//清空栈
	bool Empty() const;//判栈空
	int Length() const;//求长度
	ElemType &Top() const;//取栈顶元素
	void Push(const ElemType &e);//入栈
	void Pop();//出栈
private:
	ElemType *m_base;//基地指针
	int m_top;//栈顶指针
	int m_size;//向量空间大小
};

//构造函数，分配m个节点的顺序空间，构造一个空顺序栈
template<class ElemType>
Sqstack<ElemType>::Sqstack(int m)
{
	m_top = 0;
	m_base = new ElemType[m];
	m_size = m;
}

//析构函数，将栈结构销毁
template<class ElemType>
Sqstack <ElemType>::~Sqstack()
{
	if (m_base != NULL) delete[] m_base;
}

//清空栈
template <class ElemType>
void Sqstack <ElemType>::Clear()
{
	m_top = 0;
}

//判栈空，若栈为空，则返回true,否则返回false
template <class ElemType>
bool Sqstack<ElemType>::Empty() const
{
	return m_top ==NULL;
}

// 求长度，求栈中元素个数
template <class ElemType>
int Sqstack <ElemType>::Length() const
{
	return m_top;
}

//取栈顶元素值，先决条件是栈不空
template <class ElemType>
ElemType & Sqstack <ElemType>::Top() const
{
	return m_base[m_top - 1];
}

//入栈，若栈满，则先扩展空间，插入e到栈顶
template <class ElemType>
void Sqstack <ElemType>::Push(const ElemType &e)
{
	if (m_top >= m_size) {
		ElemType *newbase;
		newbase = new ElemType[m_size + 10];
		for (int j = 0; j < m_top; j++)
			newbase[j] = m_base[j];
		m_base = newbase;
		m_size += 10;
	}
	m_base[m_top++] = e;
}

//出栈
template <class ElemType>
void Sqstack<ElemType>::Pop()
{
	m_top--;
}