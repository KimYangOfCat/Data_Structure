#ifndef __BINARYTREE_H
#define __BINARYTREE_H
#include "SqStack.h"
#include "SqQueue.h"
#include "BTNode.h"
using namespace std;


//����������    
template<class ElemType>
class BinaryTree
{
public:
    BinaryTree():m_root(NULL){} // ���캯��	
	~BinaryTree(){_Destroy(m_root);}   //��������
	BinaryTree(const BinaryTree &rhs){m_root = _Copy (rhs.m_root);}//��������
	BinaryTree& operator=(const BinaryTree &rhs);  //��ֵ����  
	void Exchange(){_Exchange(m_root);}   //������������  
	int CountOdd(){return _CountOdd(m_root);}  //����������е�����������
	int CountNum(){return _CountNum(m_root);}  //����������еĽ�����
	int CountLeaf(){return _CountLeaf(m_root);}  //�������������Ҷ������
    void Create1(ElemType ch[],const ElemType &endChar);//�����������������ֵ�ķ�ʽ�����������Ľӿں���
    void Create2(ElemType ch1[],ElemType ch2[],int ); //�Զ����������������������������Ľӿں���
    void Clear(){_Destroy(m_root);}//�ÿն�����
    bool IsEmpty() const{return m_root == NULL;}//�ж϶������Ƿ�Ϊ��
    BTNode<ElemType>* Root() const{return m_root;} //���ظ�����ָ��
    BTNode<ElemType>* Locate(ElemType &e){return _Locate (m_root, e);}//���ض�����T��Ԫ��ֵΪe�Ľ���ָ��
    int Depth(){return _Depth(m_root);}  // ����������
    BTNode<ElemType>* Parent(BTNode<ElemType> *p){return _Parent(m_root, p);}//���ؽ���˫�׽��  
    BTNode<ElemType>* LeftChild(BTNode<ElemType> *p){return p->lchild;}//���ؽ������ӽ��   
    BTNode<ElemType>* RightChild(BTNode<ElemType> *p){return p->rchild;}//���ؽ����Һ��ӽ��    
    BTNode<ElemType>* LeftSibling (BTNode<ElemType> *p);//���ؽ������ֵܽ��     
    BTNode<ElemType>* RightSibling (BTNode<ElemType> *p); //���ؽ������ֵܽ��            
    void PreorderTraverse (void (*visit)(const ElemType &));  //����ݹ�����������Ľӿں���                                                                    
    void PreorderTraverseNonRecursive (void (*visit)(const ElemType &));//����ǵݹ�����������Ľӿں���     
    void InorderTraverse (void (*visit)(const ElemType &));  //����ݹ�����������Ľӿں���        
    void PostorderTraverse (void (*visit)(const ElemType &));  //����ݹ�����������Ľӿں���   	
	void PreoderTraverseNonRecursive(void (*visit)(const ElemType &));//����ǵݹ�����������Ľӿں���		                                                     
    void InorderTraverseNonRecursive (void (*visit)(const ElemType &));//����ǵݹ�����������Ľӿں���                                                                            
    void LevelTraverse (void (*visit)(const ElemType &e)); //�������������     
    bool InsertChild(BTNode<ElemType> *p,const int &, BinaryTree<char> &);//����������    
    void DeleteChild (BTNode<ElemType> *p, int which);     //������ɾ��       


private:         //˽�����ݳ�Ա
    BTNode<ElemType> *m_root;                            //�����������ָ��

    void _Exchange(BTNode<ElemType> *);     //������������ÿ��������������
    int _CountLeaf(BTNode<ElemType> *);             //�������������Ҷ������
    int _CountOdd(BTNode<ElemType> *);             //����������н��ֵΪ�����Ľ�����
	int _CountNum(BTNode<ElemType> *);      //����������еĽ�����
    BTNode<ElemType>* _Copy( BTNode<ElemType>* );    //���ƶ�����  
    void _Create1(BTNode<ElemType>* &, ElemType ch[],const ElemType &,int &);//���������������ֵ�ķ�ʽ����������     
    void _Create2(BTNode<ElemType> * &,ElemType ch1[],ElemType ch2[],int ,int ,int &); //��֪�����������������������������򣬽���������T                                                                                                         
    void _Destroy(BTNode<ElemType>* &);                //���ٶ����� 
    int _Depth(BTNode<ElemType>* );                    // ������������     
    BTNode<ElemType>* _Locate(BTNode<ElemType>*, const ElemType &);// ���ض�������Ԫ��ֵΪe�Ľ���ָ��    
    BTNode<ElemType>* _Parent (BTNode<ElemType>*, BTNode<ElemType>*);//����e����˫�׽��ָ��                                                      
    void _PreorderTraverse(BTNode<ElemType>* ,void (*visit)(const ElemType &e));//����ݹ����������    
    void _InorderTraverse(BTNode<ElemType>* ,void (*visit)(const ElemType &e));//����ݹ����������    
    void _PostorderTraverse(BTNode<ElemType>* ,void (*visit)(const ElemType &e));//����ݹ����������
};





//���������������ֵ�ķ�ʽ�����������Ľӿں���         
template<class ElemType>
void BinaryTree<ElemType>::Create1(ElemType ch[],const ElemType & c)        //ch[]��¼��ͨ�������������У�cΪָ�������ַ�
{
    int i = 0;
    _Create1(m_root, ch, c, i);   // i ��������������ch[]�е�λ��ָʾ������ֵΪ0
} 
//���������������ֵ�ķ�ʽ����������T                                
template<class ElemType>
void BinaryTree<ElemType>::_Create1(BTNode<ElemType> * &T,ElemType ch[],const ElemType &c,int &i)
{                 
     if (ch[i] == c)//cΪ�����������Ա�ʾ��ָ�� 
        T=NULL;
    else{
        T = new BTNode<ElemType>;
        T->data = ch[i];
        _Create1(T->lchild, ch, c, ++i);
        _Create1(T->rchild, ch, c, ++i);
    } 
}


//�Զ����������������������������Ľӿں���
template <class ElemType>
void BinaryTree<ElemType> ::Create2(ElemType ch1[],ElemType ch2[],int n) //n��¼�������еĽ����������������еĳ���
{    int i = 0;
   _Create2( m_root,ch1,ch2,0,n-1,i); //i��ֵΪ0
}
//��֪�����������������������������򣬽���������T                                
template<class ElemType>
void BinaryTree<ElemType> :: _Create2(BTNode<ElemType> * &T,ElemType ch1[],ElemType ch2[],int low,int high,int &k) 
 //��ֵ��,low=0, high=n-1����¼ch2[] �����е�λ���±ꡣk��ֵ��0,k��¼ch1[]�и�����λ���±꣬
{   
    int i;                                              
    if(low > high)              
        T=NULL;                                           
    else{                                                    
        T=new BTNode<ElemType>;                           
        T->data=ch1[k];                               //  ch1[]Ϊ�������У�ch2[]Ϊ�������У�k��¼ch1[]�и�����λ���±�
        for ( i = low;i <= high&&ch2[i] != ch1[k];i++) ;   //  i��¼ch2[]�еĸ�������ڵ�λ���±�
        if(ch2[i] == ch1[k]){ 
            k++;                                                                                      
            _Create2(T->lchild,ch1,ch2,low,i-1,k);     // k��¼��һ������������λ���±�
            _Create2(T->rchild,ch1,ch2,i+1,high,k);             // k��¼��һ������������λ���±�
        }  
    }                                                   
}

//��ֵ����
template<class ElemType>
BinaryTree<ElemType> & BinaryTree<ElemType>::operator=(const BinaryTree &rhs)
{
    if (&rhs == this)
        return *this;
        
    _Destroy (m_root);
    m_root = _Copy ( rhs.m_root);
    return *this;
}

//����������н��ֵΪ�����Ľ�����
template<class ElemType>
int BinaryTree<ElemType>:: _CountOdd(BTNode<ElemType> *T)
{
    
    int sum=0;
	if(T==NULL) return 0;
	else if(T!=NULL && T->data%2==1) sum+=1;
	return sum+_CountOdd(T->lchild)+_CountOdd(T->rchild);     
}

//����������еĽ�����
template<class ElemType>
int BinaryTree<ElemType>:: _CountNum(BTNode<ElemType> *T)
{
	int sum=0;
	if(T==NULL) return 0;
	else sum+=1;
	return sum+_CountNum(T->lchild)+_CountNum(T->rchild);
}

//������������
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

//�������������Ҷ������
template<class ElemType>
int BinaryTree<ElemType>::_CountLeaf(BTNode<ElemType> *T)
{
   if(T==NULL) return 0;
   else if(T->lchild==NULL&&T->rchild==NULL)
	   return 1;
   return _CountLeaf(T->lchild)+_CountLeaf(T->rchild);
   
}

//������������     
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

//���ض�����T�н������ֵܽ��ָ��     
template <class ElemType> 
BTNode<ElemType>* BinaryTree<ElemType>::LeftSibling (BTNode<ElemType> *p)
{
    BTNode<ElemType> *father;
    father = Parent(p);
    if (father && father->rchild == p )
        return father->lchild; 
    return NULL;
} 

 //���ض�����T�н������ֵܽ��ָ��     
template <class ElemType> 
BTNode<ElemType>* BinaryTree<ElemType>::RightSibling(BTNode<ElemType> *p)
{
    BTNode<ElemType> *father;
    father = Parent(p);
    if (father && father->lchild == p )
        return father->rchild; 
    return NULL;
}     

// ����ݹ�����������Ľӿں���    
template <class ElemType>
void BinaryTree <ElemType>::PreorderTraverse(void (*visit)(const ElemType &e))
{
    _PreorderTraverse(m_root, visit);
}
//����ݹ����������         
template <class ElemType>
void BinaryTree<ElemType> ::_PreorderTraverse(BTNode<ElemType>* T,void (*visit)(const ElemType &e))
{  
    if (T){
        visit(T->data);
        _PreorderTraverse(T->lchild,visit);
        _PreorderTraverse(T->rchild,visit);
    }  
} 

// ����ݹ�����������Ľӿں���        
template <class ElemType>
void BinaryTree <ElemType>::InorderTraverse(void (*visit)(const ElemType &e))
{
    _InorderTraverse(m_root,visit);
} 
//����ݹ����������     
template <class ElemType>
void BinaryTree<ElemType> ::_InorderTraverse(BTNode<ElemType>* T,void (*visit)(const ElemType &e))
{  
    if (T) {
        _InorderTraverse (T->lchild,visit);
        visit(T->data);
        _InorderTraverse (T->rchild,visit);
    }  
}

//����ݹ�����������Ľӿں���              
template <class ElemType>
void BinaryTree <ElemType>::PostorderTraverse(void (*visit)(const ElemType &e))
{
    _PostorderTraverse(m_root,visit);
}
//����ݹ����������             
template <class ElemType>
void BinaryTree<ElemType> ::_PostorderTraverse(BTNode<ElemType>* T,void (*visit)(const ElemType &e))
{  
    if (T){
        _PostorderTraverse (T->lchild,visit);
        _PostorderTraverse (T->rchild,visit);
        visit (T->data);
    }  
}

//��������������ķǵݹ��㷨(����ջ) 
template <class ElemType>
void BinaryTree<ElemType>::PreoderTraverseNonRecursive(void (*visit)(const ElemType &elem)){
	SqStack<BTnode<ElemType> *> S(5);
	S.Push(m_root);					//��ָ���ջ

	while(!S.Empty()){
		BTnode<ElemType> *p;
		p=S.Top();

		while(p){
			visit(p->Data);
			p=p->Lchild;
			S.Push(p);
		}

		S.Pop();							//��ָ����ջ(���Ҷ�������)

		if(!S.Empty()){
			p=S.Top();
			S.Pop();

			S.Push(p->Rchild);
		}
	}
}
// ��������������ķǵݹ��㷨(����ջ)   
template <class ElemType>
void BinaryTree<ElemType> ::InorderTraverseNonRecursive(void (*visit)(const ElemType &e))
{ 
    SqStack<BTNode<ElemType> *> S;
    S.push (m_root); //��ָ���ջ
    
    while (!S.empty ()) {
        BTNode<ElemType> *p;
        p = S.top ();

        while (p) {
            p = p->lchild;
            S.push(p); // �����ߵ���ͷ
        }
        
        S.pop(); // ��ָ����ջ
        
        if (!S.empty()){ // ���ʽ��,����һ��
            p = S.top ();
            S.pop();
            visit(p->data);
            S.push(p->rchild);
        }
    }
}
// ��α����������ķǵݹ��㷨(���ö���)   
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
    
//whichΪ0ɾ����������p������������whichΪ1ɾ����������p������������
template <class ElemType> 
void BinaryTree<ElemType>::DeleteChild(BTNode<ElemType> *p, int which)
{ 
    if (which == 0)
        _Destroy(p->lchild); 
    else 
        _Destroy(p->rchild);
} 
   
//����һ������ 
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


//���ٶ���������ʽ�Ķ�����T 
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

//���ض�����T��Ԫ��ֵΪe�Ľ���ָ��    
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

//���ض�����T��Ԫ��ֵΪe�Ľ���˫�׽��ָ��     
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


// ����������
// ��ʼ����: ������m_root����,e��m_root��ĳ�����,LRΪ0��1,�Ը��ƶ���ķ�ʽ��õķǿն�����s��m_root���ཻ��������Ϊ��
// �������: ����LRΪ0��1,����sΪT��e���������������e����ԭ��������������Ϊs��������           
template <class ElemType> 
bool BinaryTree<ElemType>::InsertChild(BTNode<ElemType> *p,const int &LR, BinaryTree<char> &r)
{
    BTNode<ElemType>*q,*s;
    if(p){ 
        q = r.Root(); //ȡ��������ָ�� 
        s = _Copy(q);//������
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



   
