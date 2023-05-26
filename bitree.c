#define _CRT_SECURE_NO_WARNINGS
#include "bitree.h"
#include "linkqueue.h"
#include <stdio.h>
#include <stdlib.h>
//ǰ�����
void preOrder(bitree_t* r)//r���������ڵ��ָ��
{
    if (r == NULL)//�ݹ麯���Ľ�������
        return;
    printf("%c ", r->data);//��
    preOrder(r->lchild);//��
    preOrder(r->rchild);//��
}
//�������
void inOrder(bitree_t* r)
{
    if (r == NULL)//�ݹ�Ľ�������
        return;
    inOrder(r->lchild);//��
    printf("%c ", r->data);//��
    inOrder(r->rchild);//��
}
//�������
void postOrder(bitree_t* r)
{
    if (r == NULL)//�ݹ麯���Ľ�������
        return;
    postOrder(r->lchild);//��
    postOrder(r->rchild);//��
    printf("%c ", r->data);//��
}
//���������� 
//s ������Ǵ�ӡ��ʾ, void (*p)(bitree_t *)����ָ��  r��������
void showBitree(char* s, void (*p)(bitree_t*), bitree_t* r)
{
    printf("%s", s);
    p(r);
    printf("\n");
}
//����������,�õݹ麯������
bitree_t* createBitree()
{//root 
//  ABD###CE##F##
    bitree_t* r = NULL;//��������������ĸ��ڵ�
    char ch;
    scanf("%c", &ch);
    if (ch == '#')//������'#'������û�����ӻ�����
        return NULL;
    r = (bitree_t*)malloc(sizeof(bitree_t));
    if (NULL == r)
    {
        perror("r malloc failed");
        return NULL;
    }
    r->data = ch;
    r->lchild = createBitree();
    r->rchild = createBitree();
    return r;
}

//��α���
void unOrder(bitree_t* r)
{
    //1.����һ������,���е���������ָ�����ڵ��ָ��
    linkqueue_t* p = createEmptyLinkQueue();
    if (r != NULL)
        inLinkQueue(p, r);
    //2.ѭ����ӡ
    while (!isEmptyLinkQueue(p))
    {
        r = outLinkQueue(p);
        printf("%c ", r->data);
        if (r->lchild != NULL)//ֻҪ���Ӳ�Ϊ�գ������У�֮����е�ʱ���ӡ
            inLinkQueue(p, r->lchild);
        if (r->rchild != NULL)//ֻҪ���Ӳ�Ϊ�գ������У�֮����е�ʱ���ӡ
            inLinkQueue(p, r->rchild);
    }
}