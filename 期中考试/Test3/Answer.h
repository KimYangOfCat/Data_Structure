// �ӿں�������Ҫ�޸�
template<class ElemType>
void BinaryTree<ElemType>::Create1(ElemType ch[], const ElemType & c)
{
	int i = 0;
	_Create1(m_root, ch, c, i);
} 

// ���õݹ鷽���������������һ����̬���ӽṹ�洢�Ķ����� 
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

// �ӿں�������Ҫ�޸�    
template <class ElemType>
void BinaryTree <ElemType>::InorderTraverse(void (*visit)(const ElemType &e))
{
	_InorderTraverse(m_root, visit);
} 

// ���õݹ鷽��ʵ�ֶԶ����������������������������е����н��    
template <class ElemType>
void BinaryTree<ElemType> ::_InorderTraverse(BTNode<ElemType>* T,void (*visit)(const ElemType &e))
{  
	if (T) {
        _InorderTraverse (T->lchild,visit);
        visit(T->data);
        _InorderTraverse (T->rchild,visit);
    }  
}

// �ӿں�������Ҫ�޸�
template <class ElemType>
int BinaryTree<ElemType>::Depth()
{
	return _Depth(m_root);
}
