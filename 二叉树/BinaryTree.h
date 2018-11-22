#ifndef __BINARYTREE_H
#define __BINARYTREE_H
#include "SqStack.h"
#include "SqQueue.h"
#include "BTNode.h"
using namespace std;


//二叉链表类    
template<class ElemType>
class BinaryTree
{
public:
    BinaryTree():m_root(NULL){} // 构造函数	
	~BinaryTree(){_Destroy(m_root);}   //析构函数
	BinaryTree(const BinaryTree &rhs){m_root = _Copy (rhs.m_root);}//拷贝构造
	BinaryTree& operator=(const BinaryTree &rhs);  //赋值重载  
	void Exchange(){_Exchange(m_root);}   //交换左右子树  
	int CountOdd(){return _CountOdd(m_root);}  //计算二叉树中的奇数结点个数
	int CountNum(){return _CountNum(m_root);}  //计算二叉树中的结点个数
	int CountLeaf(){return _CountLeaf(m_root);}  //计算二叉树中树叶结点个数
    void Create1(ElemType ch[],const ElemType &endChar);//按以先序次序输入结点值的方式建立二叉树的接口函数
    void Create2(ElemType ch1[],ElemType ch2[],int ); //以二叉树的先序和中序次序建立二叉树的接口函数
    void Clear(){_Destroy(m_root);}//置空二叉树
    bool IsEmpty() const{return m_root == NULL;}//判断二叉树是否为空
    BTNode<ElemType>* Root() const{return m_root;} //返回根结点的指针
    BTNode<ElemType>* Locate(ElemType &e){return _Locate (m_root, e);}//返回二叉树T中元素值为e的结点的指针
    int Depth(){return _Depth(m_root);}  // 求二叉树深度
    BTNode<ElemType>* Parent(BTNode<ElemType> *p){return _Parent(m_root, p);}//返回结点的双亲结点  
    BTNode<ElemType>* LeftChild(BTNode<ElemType> *p){return p->lchild;}//返回结点的左孩子结点   
    BTNode<ElemType>* RightChild(BTNode<ElemType> *p){return p->rchild;}//返回结点的右孩子结点    
    BTNode<ElemType>* LeftSibling (BTNode<ElemType> *p);//返回结点的左兄弟结点     
    BTNode<ElemType>* RightSibling (BTNode<ElemType> *p); //返回结点的右兄弟结点            
    void PreorderTraverse (void (*visit)(const ElemType &));  //先序递归遍历二叉树的接口函数                                                                    
    void PreorderTraverseNonRecursive (void (*visit)(const ElemType &));//先序非递归遍历二叉树的接口函数     
    void InorderTraverse (void (*visit)(const ElemType &));  //中序递归遍历二叉树的接口函数        
    void PostorderTraverse (void (*visit)(const ElemType &));  //后序递归遍历二叉树的接口函数   	
	void PreoderTraverseNonRecursive(void (*visit)(const ElemType &));//先序非递归遍历二叉树的接口函数		                                                     
    void InorderTraverseNonRecursive (void (*visit)(const ElemType &));//中序非递归遍历二叉树的接口函数                                                                            
    void LevelTraverse (void (*visit)(const ElemType &e)); //层序遍历二叉树     
    bool InsertChild(BTNode<ElemType> *p,const int &, BinaryTree<char> &);//有条件插入    
    void DeleteChild (BTNode<ElemType> *p, int which);     //有条件删除       


private:         //私有数据成员
    BTNode<ElemType> *m_root;                            //二叉树根结点指针

    void _Exchange(BTNode<ElemType> *);     //交换二叉树中每个结点的左右子树
    int _CountLeaf(BTNode<ElemType> *);             //计算二叉树中树叶结点个数
    int _CountOdd(BTNode<ElemType> *);             //计算二叉树中结点值为奇数的结点个数
	int _CountNum(BTNode<ElemType> *);      //计算二叉树中的结点个数
    BTNode<ElemType>* _Copy( BTNode<ElemType>* );    //复制二叉树  
    void _Create1(BTNode<ElemType>* &, ElemType ch[],const ElemType &,int &);//按先序次序输入结点值的方式建立二叉树     
    void _Create2(BTNode<ElemType> * &,ElemType ch1[],ElemType ch2[],int ,int ,int &); //已知二叉树的先序遍历次序及中序遍历次序，建立二叉树T                                                                                                         
    void _Destroy(BTNode<ElemType>* &);                //销毁二叉树 
    int _Depth(BTNode<ElemType>* );                    // 求二叉树的深度     
    BTNode<ElemType>* _Locate(BTNode<ElemType>*, const ElemType &);// 返回二叉树中元素值为e的结点的指针    
    BTNode<ElemType>* _Parent (BTNode<ElemType>*, BTNode<ElemType>*);//返回e结点的双亲结点指针                                                      
    void _PreorderTraverse(BTNode<ElemType>* ,void (*visit)(const ElemType &e));//先序递归遍历二叉树    
    void _InorderTraverse(BTNode<ElemType>* ,void (*visit)(const ElemType &e));//中序递归遍历二叉树    
    void _PostorderTraverse(BTNode<ElemType>* ,void (*visit)(const ElemType &e));//后序递归遍历二叉树
};





//按先序次序输入结点值的方式建立二叉树的接口函数         
template<class ElemType>
void BinaryTree<ElemType>::Create1(ElemType ch[],const ElemType & c)        //ch[]记录变通后的先序遍历序列，c为指定特殊字符
{
    int i = 0;
    _Create1(m_root, ch, c, i);   // i 是先序序列数组ch[]中的位置指示器，初值为0
} 
//按先序次序输入结点值的方式建立二叉树T                                
template<class ElemType>
void BinaryTree<ElemType>::_Create1(BTNode<ElemType> * &T,ElemType ch[],const ElemType &c,int &i)
{                 
     if (ch[i] == c)//c为特殊数据用以标示空指针 
        T=NULL;
    else{
        T = new BTNode<ElemType>;
        T->data = ch[i];
        _Create1(T->lchild, ch, c, ++i);
        _Create1(T->rchild, ch, c, ++i);
    } 
}


//以二叉树的先序和中序次序建立二叉树的接口函数
template <class ElemType>
void BinaryTree<ElemType> ::Create2(ElemType ch1[],ElemType ch2[],int n) //n记录二叉树中的结点个数，即遍历序列的长度
{    int i = 0;
   _Create2( m_root,ch1,ch2,0,n-1,i); //i初值为0
}
//已知二叉树的先序遍历次序及中序遍历次序，建立二叉树T                                
template<class ElemType>
void BinaryTree<ElemType> :: _Create2(BTNode<ElemType> * &T,ElemType ch1[],ElemType ch2[],int low,int high,int &k) 
 //传值后,low=0, high=n-1均记录ch2[] 数组中的位置下标。k初值是0,k记录ch1[]中根结点的位置下标，
{   
    int i;                                              
    if(low > high)              
        T=NULL;                                           
    else{                                                    
        T=new BTNode<ElemType>;                           
        T->data=ch1[k];                               //  ch1[]为先序序列，ch2[]为中序序列，k记录ch1[]中根结点的位置下标
        for ( i = low;i <= high&&ch2[i] != ch1[k];i++) ;   //  i记录ch2[]中的根结点所在的位置下标
        if(ch2[i] == ch1[k]){ 
            k++;                                                                                      
            _Create2(T->lchild,ch1,ch2,low,i-1,k);     // k记录下一个子树根结点的位置下标
            _Create2(T->rchild,ch1,ch2,i+1,high,k);             // k记录下一个子树根结点的位置下标
        }  
    }                                                   
}

//赋值重载
template<class ElemType>
BinaryTree<ElemType> & BinaryTree<ElemType>::operator=(const BinaryTree &rhs)
{
    if (&rhs == this)
        return *this;
        
    _Destroy (m_root);
    m_root = _Copy ( rhs.m_root);
    return *this;
}

//计算二叉树中结点值为奇数的结点个数
template<class ElemType>
int BinaryTree<ElemType>:: _CountOdd(BTNode<ElemType> *T)
{
    
    int sum=0;
	if(T==NULL) return 0;
	else if(T!=NULL && T->data%2==1) sum+=1;
	return sum+_CountOdd(T->lchild)+_CountOdd(T->rchild);     
}

//计算二叉树中的结点个数
template<class ElemType>
int BinaryTree<ElemType>:: _CountNum(BTNode<ElemType> *T)
{
	int sum=0;
	if(T==NULL) return 0;
	else sum+=1;
	return sum+_CountNum(T->lchild)+_CountNum(T->rchild);
}

//交换左右子树
template<class ElemType>
void BinaryTree<ElemType>::_Exchange(BTNode<ElemType> *T)
{
    if(T==NULL) return;
	else 
	{
		BTNode<ElemType> *p;    
		p=T->lchild;           
		T->lchild=T->rchild;    
		T->rchild=p;            
	}
	_Exchange(T->lchild);
	_Exchange(T->rchild);
}

//计算二叉树中树叶结点个数
template<class ElemType>
int BinaryTree<ElemType>::_CountLeaf(BTNode<ElemType> *T)
{
   if(T==NULL) return 0;
   else if(T->lchild==NULL&&T->rchild==NULL)
	   return 1;
   return _CountLeaf(T->lchild)+_CountLeaf(T->rchild);
   
}

//求二叉树的深度     
template <class ElemType> 
int BinaryTree<ElemType>::_Depth(BTNode<ElemType>* T)
{
    if (!T)
        return 0;

    int h1,h2;
    h1 = _Depth(T->lchild);
    h2 = _Depth(T->rchild);

    return h1 > h2 ? h1 + 1 : h2 + 1;
} 

//返回二叉树T中结点的左兄弟结点指针     
template <class ElemType> 
BTNode<ElemType>* BinaryTree<ElemType>::LeftSibling (BTNode<ElemType> *p)
{
    BTNode<ElemType> *father;
    father = Parent(p);
    if (father && father->rchild == p )
        return father->lchild; 
    return NULL;
} 

 //返回二叉树T中结点的右兄弟结点指针     
template <class ElemType> 
BTNode<ElemType>* BinaryTree<ElemType>::RightSibling(BTNode<ElemType> *p)
{
    BTNode<ElemType> *father;
    father = Parent(p);
    if (father && father->lchild == p )
        return father->rchild; 
    return NULL;
}     

// 先序递归遍历二叉树的接口函数    
template <class ElemType>
void BinaryTree <ElemType>::PreorderTraverse(void (*visit)(const ElemType &e))
{
    _PreorderTraverse(m_root, visit);
}
//先序递归遍历二叉树         
template <class ElemType>
void BinaryTree<ElemType> ::_PreorderTraverse(BTNode<ElemType>* T,void (*visit)(const ElemType &e))
{  
    if (T){
        visit(T->data);
        _PreorderTraverse(T->lchild,visit);
        _PreorderTraverse(T->rchild,visit);
    }  
} 

// 中序递归遍历二叉树的接口函数        
template <class ElemType>
void BinaryTree <ElemType>::InorderTraverse(void (*visit)(const ElemType &e))
{
    _InorderTraverse(m_root,visit);
} 
//中序递归遍历二叉树     
template <class ElemType>
void BinaryTree<ElemType> ::_InorderTraverse(BTNode<ElemType>* T,void (*visit)(const ElemType &e))
{  
    if (T) {
        _InorderTraverse (T->lchild,visit);
        visit(T->data);
        _InorderTraverse (T->rchild,visit);
    }  
}

//后序递归遍历二叉树的接口函数              
template <class ElemType>
void BinaryTree <ElemType>::PostorderTraverse(void (*visit)(const ElemType &e))
{
    _PostorderTraverse(m_root,visit);
}
//后序递归遍历二叉树             
template <class ElemType>
void BinaryTree<ElemType> ::_PostorderTraverse(BTNode<ElemType>* T,void (*visit)(const ElemType &e))
{  
    if (T){
        _PostorderTraverse (T->lchild,visit);
        _PostorderTraverse (T->rchild,visit);
        visit (T->data);
    }  
}

//先序遍历二叉树的非递归算法(利用栈) 
template <class ElemType>
void BinaryTree<ElemType>::PreoderTraverseNonRecursive(void (*visit)(const ElemType &elem)){
	SqStack<BTnode<ElemType> *> S(5);
	S.Push(m_root);					//根指针进栈

	while(!S.Empty()){
		BTnode<ElemType> *p;
		p=S.Top();

		while(p){
			visit(p->Data);
			p=p->Lchild;
			S.Push(p);
		}

		S.Pop();							//空指针退栈(左右都在这退)

		if(!S.Empty()){
			p=S.Top();
			S.Pop();

			S.Push(p->Rchild);
		}
	}
}
// 中序遍历二叉树的非递归算法(利用栈)   
template <class ElemType>
void BinaryTree<ElemType> ::InorderTraverseNonRecursive(void (*visit)(const ElemType &e))
{ 
    SqStack<BTNode<ElemType> *> S;
    S.push (m_root); //根指针进栈
    
    while (!S.empty ()) {
        BTNode<ElemType> *p;
        p = S.top ();

        while (p) {
            p = p->lchild;
            S.push(p); // 向左走到尽头
        }
        
        S.pop(); // 空指针退栈
        
        if (!S.empty()){ // 访问结点,向右一步
            p = S.top ();
            S.pop();
            visit(p->data);
            S.push(p->rchild);
        }
    }
}
// 层次遍历二叉树的非递归算法(利用队列)   
template <class ElemType>
void BinaryTree<ElemType> ::LevelTraverse(void (*visit)(const ElemType &e)){
    SqQueue<BTNode<ElemType> *> Q;
    
    if (m_root)
        Q.push (m_root);
        
    while (!Q.empty ()){
        BTNode<ElemType> *p;
        p = Q.front ();
        Q.pop ();

        visit (p->data);
        if (p->lchild)
            Q.push (p->lchild);
        if (p->rchild)
            Q.push (p->rchild);
    }
}
    
//which为0删除二叉树中p结点的左子树；which为1删除二叉树中p结点的右子树；
template <class ElemType> 
void BinaryTree<ElemType>::DeleteChild(BTNode<ElemType> *p, int which)
{ 
    if (which == 0)
        _Destroy(p->lchild); 
    else 
        _Destroy(p->rchild);
} 
   
//复制一棵子树 
template <class ElemType>
BTNode<ElemType>* BinaryTree<ElemType>::_Copy( BTNode<ElemType>* T)
{  
    if (T == NULL)    
        return NULL;
        
    BTNode<ElemType> *p; 
    p = new BTNode<ElemType>;
    p->data = T->data;
    p->lchild = _Copy(T->lchild);
    p->rchild = _Copy(T->rchild);
    return p;  
}


//销毁二叉链表形式的二叉树T 
template <class ElemType>
void BinaryTree<ElemType>::_Destroy(BTNode<ElemType>* &T)
{
    if (T){
        _Destroy (T->lchild);
        _Destroy (T->rchild);
        delete T;
    }
    T = NULL;  
} 

//返回二叉树T中元素值为e的结点的指针    
template <class ElemType>
BTNode<ElemType>* BinaryTree<ElemType>::_Locate(BTNode<ElemType>* bt,const ElemType &e)
{
    if(!bt || bt->data == e)
        return bt;
        
    BTNode<ElemType> *q;
    q = _Locate(bt->lchild, e);
    if (q) 
        return q;
    q = _Locate(bt->rchild, e);
    return q;
}

//返回二叉树T中元素值为e的结点的双亲结点指针     
template <class ElemType>
BTNode<ElemType>* BinaryTree<ElemType>::_Parent(BTNode<ElemType>* T, BTNode<ElemType>* p)
{
    if (T == NULL || T == p)
        return NULL;
        
    if (T->lchild == p || T->rchild==p) 
        return T;
            
    BTNode<ElemType> *q;
    q = _Parent(T->lchild, p);
    if (q) 
        return q;
    q = _Parent(T->rchild,p);
    return q;
}


// 有条件插入
// 初始条件: 二叉树m_root存在,e是m_root中某个结点,LR为0或1,以复制对象的方式获得的非空二叉树s与m_root不相交且右子树为空
// 操作结果: 根据LR为0或1,插入s为T中e结点的左或右子树。e结点的原有左或右子树则成为s的右子树           
template <class ElemType> 
bool BinaryTree<ElemType>::InsertChild(BTNode<ElemType> *p,const int &LR, BinaryTree<char> &r)
{
    BTNode<ElemType>*q,*s;
    if(p){ 
        q = r.Root(); //取对象根结点指针 
        s = _Copy(q);//对象复制
        if (LR == 0){
            s->rchild = p->lchild;
            p->lchild = s;
        }else{
            s->rchild = p->rchild;
            p->rchild = s;
        }
        return true;
    }
    return false;
} 
#endif



   
