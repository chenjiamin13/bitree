#ifndef _BITREE_H_
#define _BITREE_H_
typedef char datatype_tree;
typedef struct tree_node_t
{
    datatype_tree data;//������ 
    struct tree_node_t* lchild;//����ָ��
    struct tree_node_t* rchild;//����ָ��
}bitree_t;

//ǰ�����
void preOrder(bitree_t* r);//r���������ڵ��ָ��
//�������
void inOrder(bitree_t* r);
//�������
void postOrder(bitree_t* r);
//���������� 
//s ������Ǵ�ӡ��ʾ, void (*p)(bitree_t *)����ָ��  r��������
void showBitree(char* s, void (*p)(bitree_t*), bitree_t* r);
//����������,�õݹ麯������
bitree_t* createBitree();
//��α���
void unOrder(bitree_t* r);

#endif