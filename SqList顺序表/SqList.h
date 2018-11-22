template <class ElemType>
class SqList 
{
public:
	SqList(int);									//构造函数
	SqList(const SqList<ElemType>&);				//复制构造函数
	~SqList();										//析构函数
	void Produce(int);								//产生函数
	void Clear();									//清空函数
													/*************************************************************/
	bool Search(const ElemType& t, int& n);			//查找函数
	ElemType GetElem(int i) const;					//找第i个元素的值
	bool SetElem(ElemType e, int i);					//修改第i个元素的值
	int LocateElem(const ElemType &);				//查找元素位置
	int LocatePrior(const ElemType &);				//查找前一个元素
	int LocateNext(const ElemType &);				//查找下一个元素
	bool Insert(const ElemType& r, int n);			//插入函数
	bool Delete(const int& n);						//删除函数
													/*************************************************************/
	ElemType Read(int n);							//读函数
	bool Write(const ElemType& r, int n);			//写函数
													/*************************************************************/
	void Traverse();								//遍历函数
													/*************************************************************/
	void SizeExtender();							//扩展函数
	void Inversion();								//倒置函数
	void Order();									//排序函数
	SqList<ElemType> Combine(const SqList<ElemType> &A);	//合并函数
															/*************************************************************/
private:
	int length;										//顺序表长度
	int size;										//顺序表空间大小
	ElemType* elem;									//顺序表空间的基地址指针
	void CopyFrom(const SqList<ElemType>&);			//复制函数
};
//构造函数
template <class ElemType>
SqList<ElemType>::SqList(int m) {					//m传递创建空间的大小数值
	length = 0;
	size = m;
	//创建空间把地址传给elem
	if (size == 0)
		elem = NULL;
	else {
		elem = new ElemType[size];

	}
}

/*****-----将顺序表清空-----*****/
template<class ElemType>
void SqList<ElemType>::Clear()
{
	len = 0;
}

/*****-----顺序表已存在，返回第i个数据元素的值-----*****/
template<class ElemType>
ElemType SqList<ElemType>::GetElem(int i) const
{
	if (i<1 || i>length)
		return false;
	int e = elem[i - 1];
	return e;
}
/*****-----顺序表已存在，修改第i个数据元素的值-----*****/
template<class ElemType>
bool SqList<ElemType>::SetElem(ElemType e, int i)
{
	if (i<1 || i>length)
		return false;
	elem[i - 1] = e;
	return true;
}

//析构函数
template <class ElemType>
SqList<ElemType>::~SqList() {
	delete[] elem;
	cout << "Destructor called!" << endl;
}
//复制构造函数
template <class ElemType>
SqList<ElemType>::SqList(const SqList<ElemType>& r) {
	//三项复制初始化
	length = r.length;
	size = r.size;
	elem = new ElemType[size];
	CopyFrom(r);
}
//CopyFrom函数
template <class ElemType>
void SqList<ElemType>::CopyFrom(const SqList<ElemType>& r) {
	for (int i = 0; i<length; i++)
		//复制结点值
		*(elem + i) = *(r.elem + i);
}

/*****-----求符合条件的元素的位置-----*****/
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

/*****-----求符合条件的元素的位置的前驱-----*****/
template<class ElemType>
int SqList<ElemType>::LocatePrior(const ElemType &e)
{
	int k = LocateElem(e);
	if (k>1)
		return k - 1;
	return 0;
}

/*****-----求符合条件的元素的位置的后继-----*****/
template<class ElemType>
int SqList<ElemType>::LocateNext(const ElemType &e)
{
	int k = LocateElem(e);
	if (k >= 1 && k<length)
		return k + 1;
	return 0;
}


/******************************************************/

//查找函数(功能:根据所输入的数值得到相应的位置)
template <class ElemType>
bool SqList<ElemType>::Search(const ElemType& t, int& n) {
	for (int i = 0; i<length; i++)
		//遍历查找,一旦找到便记录下位置并返回true
		if (*(elem + i) == t) {
			n = i + 1;
			return true;
		}
		else;
		//整个顺序表遍历完也没找到,返回flase
		return false;
}
//插入函数(功能:向顺序表插入一个新的数值,插入位置为提供位置(提供现有位置)的前一个位置)
template <class ElemType>
bool SqList<ElemType>::Insert(const ElemType& r, int n) {
	if (n <= 0 || n >= length + 2)
		return false;
	else {
		//判断空间是否已满,满则扩容
		SizeExtender();
		length++;
		//移动插入位置后面的所有数据,让它们向后移动一格
		for (int i = length; i >= n + 1; i--)
			*(elem + i - 1) = *(elem + i - 2);
		//插入提供结点值
		*(elem + n - 1) = r;
		return true;
	}
}
//删除函数(功能:删除指定位置的结点)
template <class ElemType>
bool SqList<ElemType>::Delete(const int& n) {
	if (n >= 1 && n <= length) {
		for (int i = n; i<length; i++)
			//自n位置依次向前覆盖
			*(elem + i - 1) = *(elem + i);
		length--;
		return true;
	}
	else return false;
}

/******************************************************/

//读函数
template <class ElemType>
ElemType SqList<ElemType>::Read(int n) {
	return *(elem + n - 1);
}
//写函数(功能:向指定位置覆盖提供的数据)
template <class ElemType>
bool SqList<ElemType>::Write(const ElemType& r, int n) {
	if (n >= 1 && n <= length) {
		*(elem + n - 1) = r;
		return true;
	}
	else return false;
}

/******************************************************/

//显示函数
template <class ElemType>
void SqList<ElemType>::Traverse() {
	cout << "此顺序表的结点值如下:" << endl;
	for (int i = 0; i<length; i++)
		cout << *(elem + i) << ' ';
	cout << endl;
}

/******************************************************/

//扩展函数(功能:判断空间是否填满,如果填满则进行扩充)
template <class ElemType>
void SqList<ElemType>::SizeExtender() {
	if (length == size) {
		//设置一个比原来更大的新空间
		ElemType *p = new ElemType[size + 10];
		//以此把结点值赋给新空间
		for (int i = 0; i<length; i++)
			*(p + i) = *(elem + i);
		//删除旧空间
		delete[] elem;
		//让elem指向新空间
		elem = p;
		//让p指向NULL
		p = NULL;
		//修改size值为现有空间大小值
		size = size + 10;
	}
}
//倒置函数(功能:将顺序表里面的数据倒置)
template <class ElemType>
void SqList<ElemType>::Inversion() {
	ElemType exchange;
	for (int i = 0; i<length / 2; i++) {
		exchange = elem[i];
		elem[i] = elem[length - i - 1];
		elem[length - i - 1] = exchange;
	}
}
//排序函数(功能:将顺序表中的数据从小到大排序)
template <class ElemType>
void SqList<ElemType>::Order() {
	//气泡排序
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
	ElemType* c;//将两个顺序表中的值按从小到大顺序合并到c数组中
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
		//调用扩展函数,判断空间是否足够,不够则增加
		SizeExtender();
		elem[i] = c[i];
	}

	return *this;
}
/******************************************************/

