//建立n个结点的顺序表
template <class ElemType> 
void SqList<ElemType>::Create(int n)
{
	int a;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		Append(a);

	}
} 


// 在顺序表的第i个数据元素之前插入新的数据元素e（i的合法值为1≤i≤len+1）。 
template<class ElemType>
bool SqList<ElemType>::Insert(const ElemType &e, int i)
{
	if(i<=0||i>=len+2)
		return false;
	else
	{
		if (len == size) 
		{
	
			ElemType *p = new ElemType[size + 10];
			for (int i = 0; i<len; i++)
			*(p + i) = *(elem + i);
			delete[] elem;
			elem = p;
			p = NULL;
			size = size + 10;
		}
		len++;
		for (int j = len; j >= i + 1; j--)
		*(elem + j - 1) = *(elem + i - 2);
		*(elem + i - 1) = e;
		return true;
	}
}

//函数在顺序表中删除第i个数据元素并用e返回（i的合法值为1≤i≤Len）
template <class ElemType>
bool SqList<ElemType>::Delete(ElemType &e, int i)
{ 
	e=*(elem + i - 1);
	if (i >= 1 && i <= len) {
	for (int j = i; j<len; j++)
	*(elem + j - 1) = *(elem + j);
	len--;
	return true;
	}
	else return false;
}


//确定某元素是否在顺序表中，如果找到返回其位置，否则返回-1。
template<class ElemType>
int SqList<ElemType>::Search(const ElemType e) const
{
	int n=0;
	for (int i = 0; i<len; i++)
	if (*(elem + i) == e) {
	n = i + 1;
	return n;
	}
	else
	return -1;

}
