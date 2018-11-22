#ifndef _LinkNODE_
#define _LINKNODE_

// 单链表结点类
template <class ElemType>
struct LinkNode
{
    ElemType data;
    LinkNode<ElemType> *next;
};

#endif 
