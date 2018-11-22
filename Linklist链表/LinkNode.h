#ifndef _LinkNODE_
#define _LINKNODE_

// ??????????
template <class ElemType>
struct LinkNode
{
    ElemType data;
    LinkNode<ElemType> *next;
};

#endif 
