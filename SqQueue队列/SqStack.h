#ifndef _SQSTACK_H_
#define _SQSTACK_H_

//����˳��ջ��
template <class ElemType>//����һ����ģ��
class SqStack
{
public:
	 //˳��ջ��ĸ���Ա����
	SqStack(int m);     
	~SqStack(); 
   	void Clear(); 
	bool Empty() const; 
   	int Length() const; 
   	ElemType & Top() const;
   	void Push(const ElemType &e);
   	void Pop();
    void Traverse1();    //����ӷ���, ����ָ�����ջ�и�Ԫ��;
	void Traverse2();    //����ӷ���, �����±����ջ�и�Ԫ��;

private:		          //˳��ջ������ݳ�Ա
    ElemType *m_base;     //����ַָ��
    int m_top;            //ջ��ָ��
    int m_size;           //�����ռ��С
};

//���캯��������m������˳��ռ䣬����һ���յ�˳��ջ��
template <class ElemType>
SqStack <ElemType>::SqStack(int m)
{
	m_top = 0;
	m_base = new ElemType[m];
	m_size = m;
}//SqStack

//������������ջ�ṹ���١�
template <class ElemType>
SqStack <ElemType>::~SqStack()
{
	if (!m_base) delete[] m_base;
}//~SqStack

//���ջ��
template <class ElemType>
void SqStack <ElemType>::Clear()
{
	m_top = 0;
}//Clear

//��ջ�Ƿ�Ϊ�գ���Ϊ�գ��򷵻�true�����򷵻�false��
template <class ElemType>
bool SqStack <ElemType>::Empty() const
{
	return m_top == 0;
}//Empty

//��ջ�ĳ��ȡ�
template <class ElemType>
int SqStack <ElemType>::Length() const
{
	return m_top;
}//Length

//ȡջ��Ԫ�ص�ֵ���Ⱦ�������ջ���ա�
template <class ElemType>
ElemType & SqStack <ElemType>::Top() const
{
	return m_base[m_top-1];
}//Top

//��ջ����ջ����������չ�ռ䡣����e��ջ����
template <class ElemType>
void SqStack <ElemType>::Push(const ElemType &e)
{
    if(m_top >= m_size){			//��ջ��������չ�ռ䡣 
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

//��ջ������ջ��Ԫ�ء��Ⱦ�������ջ�ǿա�
template <class ElemType>
void SqStack <ElemType>::Pop()
{
	m_top--;
}//Pop

template <class ElemType>
void SqStack<ElemType>::Traverse1(){  //����ָ��ʵ�ֱ���
	ElemType *p;
	p=m_base;

	for(int i=0;i<Length();i++)
	{
		cout<<*p;
		p++;
	}
}


template <class ElemType>
void SqStack<ElemType>::Traverse2(){   //�����±�ʵ�ֱ���
   for(int m=0;m<m_top;m++)
	   cout<<m_base[m];
}



#endif
