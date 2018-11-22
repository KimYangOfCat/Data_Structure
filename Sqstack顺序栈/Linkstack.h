template <class ElemType>

struct LinkNode  //��ջ�ڵ�
{
	ElemType data;
	LinkNode<ElemType> *next;
};

template <class ElemType> //��ջ��
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

//ջ��ʼ�������캯��������һ���յ���ջ
template <class ElemType>
LinkStack< ElemType>::LinkStack()
{
	top = NULL;
}

//����ջ
template <class ElemType>
LinkStack <ElemType >::~LinkStack()
{
	Clear();
}

//���ջ
template <class ElemType>
void  LinkStack<ElemType>::Clear()
{
	LinkNode<ElemType>*p;
	while (top)   //�����ͷ������е����нڵ�
	{
		p = top;
		top = top->next;
		delete p;
	}
}

//��ջ�գ���ջΪ�գ��򷵻�ture�����򷵻�false
template <class ElemType>
bool LinkStack <ElemType>::Empty() const
{
	return top == NULL;
}
//�󳤶ȣ�����ջ��Ԫ�ظ�����
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

//ȡջ��Ԫ�ص�ֵ���Ⱦ�������ջ����
template <class ElemType>
ElemType & LinkStack<ElemType>::Top()const
{
	return top->data;
}

//��ջ
template <class ElemType>
void LinkStack <ElemType>::Push(const ElemType &e)
{
	LinkNode <ElemType> *p;
	p = new LinkNode<ElemType>;
	p->data = e;
	p->next = top;
	top = p;

}

//��ջ
template <class ElemType>
void LinkStack <ElemType>::Pop()
{
	LinkNode<ElemType>*p = top;
	top = top->next;
	delete p;
}