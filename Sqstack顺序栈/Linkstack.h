template <class ElemType>

struct LinkNode  //链栈节点
{
	ElemType data;
	LinkNode<ElemType> *next;
};

template <class ElemType> //链栈类
class LinkStack
{
public:
	LinkStack();
	~LinkStack();
	void Clear();
	bool Empty() const;
	int Length() const;
	ElemType  & Top() const;
	void Push(const ElemType &);
	void Pop();

private:
	LinkNode<ElemType> *top;
};

//栈初始化；构造函数，构造一个空的链栈
template <class ElemType>
LinkStack< ElemType>::LinkStack()
{
	top = NULL;
}

//销毁栈
template <class ElemType>
LinkStack <ElemType >::~LinkStack()
{
	Clear();
}

//清空栈
template <class ElemType>
void  LinkStack<ElemType>::Clear()
{
	LinkNode<ElemType>*p;
	while (top)   //依次释放链表中的所有节点
	{
		p = top;
		top = top->next;
		delete p;
	}
}

//判栈空；若栈为空，则返回ture，否则返回false
template <class ElemType>
bool LinkStack <ElemType>::Empty() const
{
	return top == NULL;
}
//求长度；返回栈中元素个数；
template <class ElemType>
int LinkStack <ElemType>::Length() const
{
	int i = 0;
	LinkNode <ElemType> *p = top;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

//取栈顶元素的值；先决条件是栈不空
template <class ElemType>
ElemType & LinkStack<ElemType>::Top()const
{
	return top->data;
}

//入栈
template <class ElemType>
void LinkStack <ElemType>::Push(const ElemType &e)
{
	LinkNode <ElemType> *p;
	p = new LinkNode<ElemType>;
	p->data = e;
	p->next = top;
	top = p;

}

//出栈
template <class ElemType>
void LinkStack <ElemType>::Pop()
{
	LinkNode<ElemType>*p = top;
	top = top->next;
	delete p;
}