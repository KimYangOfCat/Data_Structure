
// ������linkList��ĩβ�����µ�Ԫ��e
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


// �ڵ�������ɾ����i������Ԫ�ز������ݱ���e������ֵ��i�ĺϷ�ֵΪ1��i��Len��
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



