template <class ElemType>
class SqList 
{
public:
	SqList(int);									//���캯��
	SqList(const SqList<ElemType>&);				//���ƹ��캯��
	~SqList();										//��������
	void Produce(int);								//��������
	void Clear();									//��պ���
													/*************************************************************/
	bool Search(const ElemType& t, int& n);			//���Һ���
	ElemType GetElem(int i) const;					//�ҵ�i��Ԫ�ص�ֵ
	bool SetElem(ElemType e, int i);					//�޸ĵ�i��Ԫ�ص�ֵ
	int LocateElem(const ElemType &);				//����Ԫ��λ��
	int LocatePrior(const ElemType &);				//����ǰһ��Ԫ��
	int LocateNext(const ElemType &);				//������һ��Ԫ��
	bool Insert(const ElemType& r, int n);			//���뺯��
	bool Delete(const int& n);						//ɾ������
													/*************************************************************/
	ElemType Read(int n);							//������
	bool Write(const ElemType& r, int n);			//д����
													/*************************************************************/
	void Traverse();								//��������
													/*************************************************************/
	void SizeExtender();							//��չ����
	void Inversion();								//���ú���
	void Order();									//������
	SqList<ElemType> Combine(const SqList<ElemType> &A);	//�ϲ�����
															/*************************************************************/
private:
	int length;										//˳�����
	int size;										//˳���ռ��С
	ElemType* elem;									//˳���ռ�Ļ���ַָ��
	void CopyFrom(const SqList<ElemType>&);			//���ƺ���
};
//���캯��
template <class ElemType>
SqList<ElemType>::SqList(int m) {					//m���ݴ����ռ�Ĵ�С��ֵ
	length = 0;
	size = m;
	//�����ռ�ѵ�ַ����elem
	if (size == 0)
		elem = NULL;
	else {
		elem = new ElemType[size];

	}
}

/*****-----��˳������-----*****/
template<class ElemType>
void SqList<ElemType>::Clear()
{
	len = 0;
}

/*****-----˳����Ѵ��ڣ����ص�i������Ԫ�ص�ֵ-----*****/
template<class ElemType>
ElemType SqList<ElemType>::GetElem(int i) const
{
	if (i<1 || i>length)
		return false;
	int e = elem[i - 1];
	return e;
}
/*****-----˳����Ѵ��ڣ��޸ĵ�i������Ԫ�ص�ֵ-----*****/
template<class ElemType>
bool SqList<ElemType>::SetElem(ElemType e, int i)
{
	if (i<1 || i>length)
		return false;
	elem[i - 1] = e;
	return true;
}

//��������
template <class ElemType>
SqList<ElemType>::~SqList() {
	delete[] elem;
	cout << "Destructor called!" << endl;
}
//���ƹ��캯��
template <class ElemType>
SqList<ElemType>::SqList(const SqList<ElemType>& r) {
	//����Ƴ�ʼ��
	length = r.length;
	size = r.size;
	elem = new ElemType[size];
	CopyFrom(r);
}
//CopyFrom����
template <class ElemType>
void SqList<ElemType>::CopyFrom(const SqList<ElemType>& r) {
	for (int i = 0; i<length; i++)
		//���ƽ��ֵ
		*(elem + i) = *(r.elem + i);
}

/*****-----�����������Ԫ�ص�λ��-----*****/
template<class ElemType>
int SqList<ElemType>::LocateElem(const ElemType &e)
{
	ElemType *p = elem;
	int i = 1;
	while (i <= length && *p != e)
	{
		p++;
		i++;
	}
	if (i <= length)
		return i;
	else
		return 0;
}

/*****-----�����������Ԫ�ص�λ�õ�ǰ��-----*****/
template<class ElemType>
int SqList<ElemType>::LocatePrior(const ElemType &e)
{
	int k = LocateElem(e);
	if (k>1)
		return k - 1;
	return 0;
}

/*****-----�����������Ԫ�ص�λ�õĺ��-----*****/
template<class ElemType>
int SqList<ElemType>::LocateNext(const ElemType &e)
{
	int k = LocateElem(e);
	if (k >= 1 && k<length)
		return k + 1;
	return 0;
}


/******************************************************/

//���Һ���(����:�������������ֵ�õ���Ӧ��λ��)
template <class ElemType>
bool SqList<ElemType>::Search(const ElemType& t, int& n) {
	for (int i = 0; i<length; i++)
		//��������,һ���ҵ����¼��λ�ò�����true
		if (*(elem + i) == t) {
			n = i + 1;
			return true;
		}
		else;
		//����˳��������Ҳû�ҵ�,����flase
		return false;
}
//���뺯��(����:��˳������һ���µ���ֵ,����λ��Ϊ�ṩλ��(�ṩ����λ��)��ǰһ��λ��)
template <class ElemType>
bool SqList<ElemType>::Insert(const ElemType& r, int n) {
	if (n <= 0 || n >= length + 2)
		return false;
	else {
		//�жϿռ��Ƿ�����,��������
		SizeExtender();
		length++;
		//�ƶ�����λ�ú������������,����������ƶ�һ��
		for (int i = length; i >= n + 1; i--)
			*(elem + i - 1) = *(elem + i - 2);
		//�����ṩ���ֵ
		*(elem + n - 1) = r;
		return true;
	}
}
//ɾ������(����:ɾ��ָ��λ�õĽ��)
template <class ElemType>
bool SqList<ElemType>::Delete(const int& n) {
	if (n >= 1 && n <= length) {
		for (int i = n; i<length; i++)
			//��nλ��������ǰ����
			*(elem + i - 1) = *(elem + i);
		length--;
		return true;
	}
	else return false;
}

/******************************************************/

//������
template <class ElemType>
ElemType SqList<ElemType>::Read(int n) {
	return *(elem + n - 1);
}
//д����(����:��ָ��λ�ø����ṩ������)
template <class ElemType>
bool SqList<ElemType>::Write(const ElemType& r, int n) {
	if (n >= 1 && n <= length) {
		*(elem + n - 1) = r;
		return true;
	}
	else return false;
}

/******************************************************/

//��ʾ����
template <class ElemType>
void SqList<ElemType>::Traverse() {
	cout << "��˳���Ľ��ֵ����:" << endl;
	for (int i = 0; i<length; i++)
		cout << *(elem + i) << ' ';
	cout << endl;
}

/******************************************************/

//��չ����(����:�жϿռ��Ƿ�����,����������������)
template <class ElemType>
void SqList<ElemType>::SizeExtender() {
	if (length == size) {
		//����һ����ԭ��������¿ռ�
		ElemType *p = new ElemType[size + 10];
		//�Դ˰ѽ��ֵ�����¿ռ�
		for (int i = 0; i<length; i++)
			*(p + i) = *(elem + i);
		//ɾ���ɿռ�
		delete[] elem;
		//��elemָ���¿ռ�
		elem = p;
		//��pָ��NULL
		p = NULL;
		//�޸�sizeֵΪ���пռ��Сֵ
		size = size + 10;
	}
}
//���ú���(����:��˳�����������ݵ���)
template <class ElemType>
void SqList<ElemType>::Inversion() {
	ElemType exchange;
	for (int i = 0; i<length / 2; i++) {
		exchange = elem[i];
		elem[i] = elem[length - i - 1];
		elem[length - i - 1] = exchange;
	}
}
//������(����:��˳����е����ݴ�С��������)
template <class ElemType>
void SqList<ElemType>::Order() {
	//��������
	for (int i = length - 1; i >= 1; i--) {
		for (int j = 0; j<i; j++) {
			if (elem[j]>elem[j + 1]) {
				ElemType exchange;
				exchange = elem[j];
				elem[j] = elem[j + 1];
				elem[j + 1] = exchange;
			}
		}
	}
}

template <class ElemType>
SqList<ElemType> SqList<ElemType>::Combine(const SqList<ElemType>& A)
{
	ElemType* c;//������˳����е�ֵ����С����˳��ϲ���c������
	c = new ElemType[length + A.length];
	int i = 0, j = 0, k = 0;
	while (i<length && j<A.length)
	{
		if (elem[i]>A.elem[j])
			c[k++] = A.elem[j++];
		else
			c[k++] = elem[i++];
	}
	while (i<length)
		c[k++] = elem[i++];
	while (j<A.length)
		c[k++] = A.elem[j++];

	length += A.length;

	for (i = 0; i<length; i++)
	{
		//������չ����,�жϿռ��Ƿ��㹻,����������
		SizeExtender();
		elem[i] = c[i];
	}

	return *this;
}
/******************************************************/

