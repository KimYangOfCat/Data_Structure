template<class ElemType>
class Sqstack
{
public:
	Sqstack(int m);//���캯��
	~Sqstack();//��������
	void Clear();//���ջ
	bool Empty() const;//��ջ��
	int Length() const;//�󳤶�
	ElemType &Top() const;//ȡջ��Ԫ��
	void Push(const ElemType &e);//��ջ
	void Pop();//��ջ
private:
	ElemType *m_base;//����ָ��
	int m_top;//ջ��ָ��
	int m_size;//�����ռ��С
};

//���캯��������m���ڵ��˳��ռ䣬����һ����˳��ջ
template<class ElemType>
Sqstack<ElemType>::Sqstack(int m)
{
	m_top = 0;
	m_base = new ElemType[m];
	m_size = m;
}

//������������ջ�ṹ����
template<class ElemType>
Sqstack <ElemType>::~Sqstack()
{
	if (m_base != NULL) delete[] m_base;
}

//���ջ
template <class ElemType>
void Sqstack <ElemType>::Clear()
{
	m_top = 0;
}

//��ջ�գ���ջΪ�գ��򷵻�true,���򷵻�false
template <class ElemType>
bool Sqstack<ElemType>::Empty() const
{
	return m_top ==NULL;
}

// �󳤶ȣ���ջ��Ԫ�ظ���
template <class ElemType>
int Sqstack <ElemType>::Length() const
{
	return m_top;
}

//ȡջ��Ԫ��ֵ���Ⱦ�������ջ����
template <class ElemType>
ElemType & Sqstack <ElemType>::Top() const
{
	return m_base[m_top - 1];
}

//��ջ����ջ����������չ�ռ䣬����e��ջ��
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

//��ջ
template <class ElemType>
void Sqstack<ElemType>::Pop()
{
	m_top--;
}