// 接口函数，不要修改
template<class ElemType>
void BinaryTree<ElemType>::Create1(ElemType ch[], const ElemType & c)
{
	int i = 0;
	_Create1(m_root, ch, c, i);
} 

// 利用递归方法和先序遍历创建一个动态链接结构存储的二叉树 
template<class ElemType>
void BinaryTree<ElemType>::_Create1(BTNode<ElemType> * &T, ElemType ch[], const ElemType &c, int &i)
{                 
	if (ch[i] == c)
        T=NULL;
    else{
        T = new BTNode<ElemType>;
        T->data = ch[i];
        _Create1(T->lchild, ch, c, ++i);
        _Create1(T->rchild, ch, c, ++i);
    } 

}

// 接口函数，不要修改    
template <class ElemType>
void BinaryTree <ElemType>::InorderTraverse(void (*visit)(const ElemType &e))
{
	_InorderTraverse(m_root, visit);
} 

// 利用递归方法实现对二叉树的中序遍历，并输出二叉树中的所有结点    
template <class ElemType>
void BinaryTree<ElemType> ::_InorderTraverse(BTNode<ElemType>* T,void (*visit)(const ElemType &e))
{  
	if (T) {
        _InorderTraverse (T->lchild,visit);
        visit(T->data);
        _InorderTraverse (T->rchild,visit);
    }  
}

// 接口函数，不要修改
template <class ElemType>
int BinaryTree<ElemType>::Depth()
{
	return _Depth(m_root);
}
