//����������ṹ 
template<class ElemType>
struct BTNode
{
    ElemType         data;        //���ֵ
    BTNode<ElemType> *lchild;    //���ӽ��ָ��
    BTNode<ElemType> *rchild;    //�Һ��ӽ��ָ��
};
