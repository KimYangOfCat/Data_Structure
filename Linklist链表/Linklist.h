#ifndef _LinkLIST_
#define _LINKLIST_

#include "list.h"
#include "LinkNode.h"

// ���嵥������
template <class ElemType>
class LinkList: public List<ElemType>
{
public:
    LinkList();
	LinkList(const LinkList<ElemType>&);
    ~LinkList();
    bool IsEmpty()const {return len <= 0;}
    int  Length()const {return len;} 
    void Clear();  
    bool GetElem (ElemType&,int) const;
    bool SetElem( const ElemType&,int);
    int LocateElem(const ElemType&) const;
    int LocatePrior(const ElemType&) const;
    int LocateNext(const ElemType&) const ;
    bool Insert(const ElemType&, int);
    bool TailInsert(const ElemType&);
    bool Delete(ElemType&,int);
    void Traverse(void(*visit)(const ElemType&)) const;
    void Inverse();       //���������е�Ԫ�ؾ͵�����
    void LinkDel();       //ɾ�������ظ���㺯��
    LinkList<ElemType> operator=(const LinkList<ElemType>&);
    
private:
    int len;    
	void CopyFrom(const LinkList<ElemType>&);
    LinkNode<ElemType> *head;
    LinkNode<ElemType> *tail;
};


// ���캯��
template<class ElemType>
LinkList<ElemType>::LinkList()
{
    len = 0;
    head = tail = new LinkNode<ElemType> ;
    head->next = NULL;
}   


// ��������
template<class ElemType>
LinkList<ElemType>::LinkList(const LinkList<ElemType> &r)
{
	CopyFrom(r);				
}


// ��������
template <class ElemType>
LinkList<ElemType>::~LinkList( )
{
	Clear();					
	delete head;
}


// ��յ������� 
template <class ElemType>
void LinkList<ElemType>::Clear()
{
    LinkNode<ElemType> *p = head->next, *q;
    while (p) 
	{
        q = p->next;
        delete p;
        p = q;
    }

    tail = head;
	head->next = NULL;
    len = 0;  
}


// �޸ĵ������i����������Ԫ��ֵ
template <class ElemType> 
bool LinkList<ElemType>::SetElem(const ElemType &e, int i)
{
    if (i < 1 || i > len)  
        return false;

	LinkNode<ElemType> *p = head->next;

	int k = 1;
    while (k < i) 
	{
        p = p->next;
        k++;
    }
    p->data = e;

    return true;
}


// ��õ������i����������Ԫ��ֵ
template<class ElemType>     
bool LinkList<ElemType>::GetElem(ElemType &e, int i) const
{
    if (i < 1 || i > len)  
        return false;

    LinkNode<ElemType> *p = head->next;
    int k = 1;
    while (k < i)
	{
        p = p->next;
        k++;
	}
    e = p->data;

    return true;
}

 
// �����Ҫ��Ľ���ڵ������е�λ��
template<class ElemType>     
int LinkList<ElemType>::LocateElem(const ElemType &e) const
{
    int i = 1;
    LinkNode<ElemType> *p = head->next;

    while(p && p->data != e)
	{
        i++;
        p = p->next;
    }

    if (p) 
        return i;

    return 0;
}


// �����Ҫ��Ľ���ڵ������е�λ�õ�ǰ��
template<class ElemType>     
int LinkList<ElemType>::LocatePrior(const ElemType &e) const
{
    int i = LocateElem(e);
    if (i > 1) 
        return i - 1;
	else
		return 0;
}


// �����Ҫ��Ľ���ڵ������е�λ�õĺ��
template<class ElemType>     
int LinkList<ElemType>::LocateNext(const ElemType &e) const
{

    int i = LocateElem (e);
    if (i >= 1 && i < len) 
        return i + 1;
    return 0;
}


// �ڵ������в���һ�����
template<class ElemType>
bool LinkList<ElemType>::Insert(const ElemType &e, int i)
{
 
    LinkNode<ElemType> *p, *q;
    int k = 1;

    if (i<1 || i>len+1) 
        return false;					

    q = new LinkNode<ElemType> ;
    q->data = e;

    p = head ;
    while (k < i)					
    { 
        p = p->next;
        k++;
    } 
    q->next = p->next;  
    p->next = q;					 

    ++len;								
    return true;
}


// �ڵ������β����һ�����
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


// ɾ���������е�i�����
template<class ElemType>
bool LinkList<ElemType>::Delete(ElemType &e,int i) 
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
    p->next = q->next;					//q��Ϊ��Ҫɾ���Ľ��   
    if (q == tail)
        tail = p;
    e = q->data;  
    delete q;

    --len;								
    return true;
}


// �Ե���������б���
template<class ElemType>
void LinkList<ElemType>::Traverse(void(*visit)(const ElemType &e)) const
{
    LinkNode<ElemType> *p = head->next;
    while (p)
	{
       visit(p->data);
       p = p->next;
    }
 }


// ��ֵ�����=������
template<class ElemType>
LinkList<ElemType> LinkList<ElemType>::operator=(const LinkList<ElemType> &r)
{
	Clear();
	CopyFrom(r);
	return *this;
}


// ��������
template <class ElemType>
void LinkList<ElemType>::CopyFrom(const LinkList<ElemType> &r)
{
	len = 0;
	head = tail = new LinkNode<ElemType>;
	head->next = NULL;
    LinkNode<ElemType> *p = r.head->next;
    while (p)
	{
       TailInsert(p->data);
       p = p->next;
    }
};


// ���������е�Ԫ�ؾ͵�����
template <class ElemType>
void LinkList<ElemType>::Inverse()
{
   LinkNode<ElemType>  *p, *q, *s;
   p=head->next;
   q=p->next;
   while(p&&q)
   {
	   s=q->next;
	   q->next=p;
	   p=q;
	   q=s;
   }
   tail=head->next;
   tail->next =NULL;
   head->next=p;
};






//ɾ���������������ظ��Ľ��(����һ��)
template <class ElemType>
void LinkList<ElemType>::LinkDel()
{
	//��pָ��ָ���һ����Ч���
	LinkNode<ElemType> *p=head->next;
	//pָ����ָ����λ��:����λ�ñ���(���������Q��Ϊ���ܵ���ɾ������)
	int locationP=1;
	while(p)
	{
		LinkNode<ElemType> *q=p->next;
		int e,locationQ=locationP+1;
		while(q)
		{
			bool mark=0;
			if(p->data==q->data)
			{
				//���q����һ����㲻��NULL�Ļ�,������ָ����һ�����
				q=q->next;
				mark=1;
				//ɾ���ظ��Ľ��(λ��ΪlocationQ)
				Delete(e,locationQ);
			}
			if(!mark)
			{
				q=q->next;
				//qָ����ָ����λ��(��qͬ��)
				locationQ++;
			}
		}
		p=p->next;
		locationP++;
	}
}

#endif


