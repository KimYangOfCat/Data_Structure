template<class ElemType>
struct BTNode
{
	ElemType         data;
	BTNode<ElemType> *lchild;
	BTNode<ElemType> *rchild;
};

template<class ElemType>
class BinaryTree
{
public:
	BinaryTree():m_root(NULL){}
	~BinaryTree() 
	{
		_Destroy(m_root);
	}

	void Create1(ElemType ch[], const ElemType &endChar);
	void PreorderTraverse (void (*visit)(const ElemType &)); 
	void InorderTraverse (void (*visit)(const ElemType &));
	void PostorderTraverse (void (*visit)(const ElemType &));
	int Depth();
private:
	BTNode<ElemType> *m_root;
	void _Destroy(BTNode<ElemType>* &); 

	void _Create1(BTNode<ElemType>* &,ElemType ch[],const ElemType &,int &);
	void _PreorderTraverse(BTNode<ElemType>* ,void (*visit)(const ElemType &e));
	void _InorderTraverse(BTNode<ElemType>* ,void (*visit)(const ElemType &e));
	void _PostorderTraverse(BTNode<ElemType>* ,void (*visit)(const ElemType &e));
	int _Depth(BTNode<char>*); 
};

template <class ElemType>
void BinaryTree<ElemType>::_Destroy(BTNode<ElemType>* &T)
{
	if (T)
	{
		_Destroy (T->lchild);
		_Destroy (T->rchild);
		delete T;
	}
	T = NULL;  
} 

template <class ElemType>
void BinaryTree <ElemType>::PreorderTraverse(void (*visit)(const ElemType &e))
{
	_PreorderTraverse(m_root, visit);
}
   
template <class ElemType>
void BinaryTree<ElemType> ::_PreorderTraverse(BTNode<ElemType>* T,void (*visit)(const ElemType &e))
{  
	if (T)
	{
		visit(T->data);
		_PreorderTraverse(T->lchild,visit);
		_PreorderTraverse(T->rchild,visit);
	}  
} 

#include "answer.h"