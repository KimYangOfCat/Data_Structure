template <class ElemType>
class SqList
{
public:
	SqList(int m = 0);
	~SqList();
	bool Append(const ElemType &);
	void Traverse(void (*visit)(const ElemType &)) const;
	void Create(int);
	void Sort();
    int SeqSearch(const ElemType &) const;
	int BinarySearch(const ElemType &) const;
	//新声明的三个函数
	bool Insert(const ElemType &, int);
	bool Delete(ElemType &, int);
	int  Search(const ElemType) const;
private:
	int len;
	int size;
	ElemType *elem;
};

template <class ElemType>
SqList<ElemType>::SqList(int m)
{
	len = 0;
	if (m == 0)
		elem = NULL;
	else
		elem = new ElemType[m+1];
	size = m+1;
}

template <class ElemType>
SqList<ElemType>::~SqList()
{ 
	delete[] elem;
}

template<class ElemType>
bool SqList<ElemType>::Append(const ElemType &e)
{
	ElemType *newbase;
	if (len >= size)
	{   
		newbase = new ElemType[size + 10];
		if (!newbase)
			return false;
		for(int j = 0; j < len; j++) 
			newbase[j] = elem[j];
		delete[] elem;
		elem = newbase;
		size += 10;
	}
	elem[len++] = e;
	return true;
}

template <class ElemType>
void SqList<ElemType>::Traverse(void (*visit)(const ElemType &e)) const
{ 
	ElemType *p = elem;
	for (int i = 0; i < len; i++)
		visit(*p++);
}
#include "Answer.h"