


#include "LinkNode.h"

// ��������
template <class ElemType>
class LinkList
{
public:
    LinkList();
    ~LinkList();
    void Clear();  
    void Traverse(void(*visit)(const ElemType&)) const;
   void Reverse(LinkList<ElemType> &);       //ʵ����������ò���
    
    bool TailInsert(const ElemType&);
    bool OrderDelete(ElemType&,int);

    
private:
    int len;    
    LinkNode<ElemType> *head;
    LinkNode<ElemType> *tail;
};



template<class ElemType>
LinkList<ElemType>::LinkList()
{
    len = 0;
    head = tail = new LinkNode<ElemType> ;
    head->next = NULL;
}   

template <class ElemType>
LinkList<ElemType>::~LinkList( )
{
	Clear();			
	delete head;
}

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


//����������
template <class ElemType>
void LinkList<ElemType>::Reverse(LinkList<ElemType> &r)
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
   head->next->next=NULL;
   head->next=p;
}

#include "Answer.h"

