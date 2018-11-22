#ifndef _LinkLIST_
#define _LINKLIST_

#include "list.h"
#include "LinkNode.h"

// 定义单链表类
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
    void Inverse();       //将单链表中的元素就地逆置
    void LinkDel();       //删除所有重复结点函数
    LinkList<ElemType> operator=(const LinkList<ElemType>&);
    
private:
    int len;    
	void CopyFrom(const LinkList<ElemType>&);
    LinkNode<ElemType> *head;
    LinkNode<ElemType> *tail;
};


// 构造函数
template<class ElemType>
LinkList<ElemType>::LinkList()
{
    len = 0;
    head = tail = new LinkNode<ElemType> ;
    head->next = NULL;
}   


// 单链表复制
template<class ElemType>
LinkList<ElemType>::LinkList(const LinkList<ElemType> &r)
{
	CopyFrom(r);				
}


// 析构函数
template <class ElemType>
LinkList<ElemType>::~LinkList( )
{
	Clear();					
	delete head;
}


// 清空单链表类 
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


// 修改单链表第i个结点的数据元素值
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


// 获得单链表第i个结点的数据元素值
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

 
// 求符合要求的结点在单链表中的位置
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


// 求符合要求的结点在单链表中的位置的前驱
template<class ElemType>     
int LinkList<ElemType>::LocatePrior(const ElemType &e) const
{
    int i = LocateElem(e);
    if (i > 1) 
        return i - 1;
	else
		return 0;
}


// 求符合要求的结点在单链表中的位置的后继
template<class ElemType>     
int LinkList<ElemType>::LocateNext(const ElemType &e) const
{

    int i = LocateElem (e);
    if (i >= 1 && i < len) 
        return i + 1;
    return 0;
}


// 在单链表中插入一个结点
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


// 在单链表表尾插入一个结点
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


// 删除单链表中第i个结点
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
    p->next = q->next;					//q即为所要删除的结点   
    if (q == tail)
        tail = p;
    e = q->data;  
    delete q;

    --len;								
    return true;
}


// 对单链表类进行遍历
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


// 赋值运算符=的重载
template<class ElemType>
LinkList<ElemType> LinkList<ElemType>::operator=(const LinkList<ElemType> &r)
{
	Clear();
	CopyFrom(r);
	return *this;
}


// 拷贝函数
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


// 将单链表中的元素就地逆置
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






//删除单链表中所有重复的结点(保留一个)
template <class ElemType>
void LinkList<ElemType>::LinkDel()
{
	//让p指针指向第一个有效结点
	LinkNode<ElemType> *p=head->next;
	//p指针所指结点的位置:设置位置变量(包括下面的Q是为了能调用删除函数)
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
				//如果q的下一个结点不是NULL的话,则让它指向下一个结点
				q=q->next;
				mark=1;
				//删除重复的结点(位置为locationQ)
				Delete(e,locationQ);
			}
			if(!mark)
			{
				q=q->next;
				//q指针所指结点的位置(与q同步)
				locationQ++;
			}
		}
		p=p->next;
		locationP++;
	}
}

#endif


