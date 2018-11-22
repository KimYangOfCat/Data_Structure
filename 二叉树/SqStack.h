#ifndef _SQSTACK_H_
#define _SQSTACK_H_

//定义顺序栈类
template <class ElemType>//声明一个类模板
class SqStack
{
public:
	 //顺序栈类的各成员函数
	SqStack(int m);     
	~SqStack(); 
   	void Clear(); 
	bool Empty() const; 
   	int Length() const; 
   	ElemType & Top() const;
   	void Push(const ElemType &e);
   	void Pop();
    void Traverse1();    //新添加方法, 利用指针遍历栈中各元素;
	void Traverse2();    //新添加方法, 利用下标遍历栈中各元素;

private:		          //顺序栈类的数据成员
    ElemType *m_base;     //基地址指针
    int m_top;            //栈顶指针
    int m_size;           //向量空间大小
};

//构造函数，分配m个结点的顺序空间，构造一个空的顺序栈。
template <class ElemType>
SqStack <ElemType>::SqStack(int m)
{
	m_top = 0;
	m_base = new ElemType[m];
	m_size = m;
}//SqStack

//析构函数，将栈结构销毁。
template <class ElemType>
SqStack <ElemType>::~SqStack()
{
	if (!m_base) delete[] m_base;
}//~SqStack

//清空栈。
template <class ElemType>
void SqStack <ElemType>::Clear()
{
	m_top = 0;
}//Clear

//判栈是否为空，若为空，则返回true，否则返回false。
template <class ElemType>
bool SqStack <ElemType>::Empty() const
{
	return m_top == 0;
}//Empty

//求栈的长度。
template <class ElemType>
int SqStack <ElemType>::Length() const
{
	return m_top;
}//Length

//取栈顶元素的值。先决条件是栈不空。
template <class ElemType>
ElemType & SqStack <ElemType>::Top() const
{
	return m_base[m_top-1];
}//Top

//入栈，若栈满，则先扩展空间。插入e到栈顶。
template <class ElemType>
void SqStack <ElemType>::Push(const ElemType &e)
{
    if(m_top >= m_size){			//若栈满，则扩展空间。 
		ElemType *newbase;
        newbase = new ElemType[m_size + 10];
        for(int j = 0; j < m_top; j++) 
            newbase[j] = m_base[j];   
        delete[] m_base;
        m_base = newbase;
		m_size += 10;
    }
	m_base[m_top] = e;
	m_top+=1;
}//Push

//出栈，弹出栈顶元素。先决条件是栈非空。
template <class ElemType>
void SqStack <ElemType>::Pop()
{
	m_top--;
}//Pop

template <class ElemType>
void SqStack<ElemType>::Traverse1(){  //利用指针实现遍历
	ElemType *p;
	p=m_base;

	for(int i=0;i<Length();i++)
	{
		cout<<*p;
		p++;
	}
}


template <class ElemType>
void SqStack<ElemType>::Traverse2(){   //利用下标实现遍历
   for(int m=0;m<m_top;m++)
	   cout<<m_base[m];
}



#endif
