//����n������˳���
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


// ��˳���ĵ�i������Ԫ��֮ǰ�����µ�����Ԫ��e��i�ĺϷ�ֵΪ1��i��len+1���� 
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

//������˳�����ɾ����i������Ԫ�ز���e���أ�i�ĺϷ�ֵΪ1��i��Len��
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


//ȷ��ĳԪ���Ƿ���˳����У�����ҵ�������λ�ã����򷵻�-1��
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
