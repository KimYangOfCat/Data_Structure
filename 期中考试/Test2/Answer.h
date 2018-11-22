
// 在链表linkList的末尾插入新的元素e
template<class ElemType>
bool LinkList<ElemType>::TailInsert(const ElemType &e)
{
	LinkNode<ElemType> *q;
	q = new LinkNode<ElemType> ;
    q->data = e;
    tail->next = q;						 
    tail = q;
    tail->next = NULL;
    ++len;								
	return true;

}


// 在单链表中删除第i个数据元素并用数据变量e返回其值（i的合法值为1≤i≤Len）
template<class ElemType>
bool LinkList<ElemType>::OrderDelete(ElemType &e,int i) 
{
	if (i<1 || i>len)   
        return false;					
    LinkNode<ElemType> *p,*q;
    int k = 1;
    p = head;
    while(k < i)
	{
        p = p->next;
        k++; 
    }
    q = p->next;   
    p->next = q->next;	   
    if (q == tail)
        tail = p;
    e = q->data;  
    delete q;
    --len;								
    return true;

}



