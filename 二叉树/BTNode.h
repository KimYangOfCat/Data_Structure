//二叉链表结点结构 
template<class ElemType>
struct BTNode
{
    ElemType         data;        //结点值
    BTNode<ElemType> *lchild;    //左孩子结点指针
    BTNode<ElemType> *rchild;    //右孩子结点指针
};
