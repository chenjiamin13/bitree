#define _CRT_SECURE_NO_WARNINGS
#include "linkqueue.h"
#include <stdio.h>
#include <stdlib.h>

//1.����һ���յĶ���
linkqueue_t* createEmptyLinkQueue()
{
    linkqueue_t* p = (linkqueue_t*)malloc(sizeof(linkqueue_t));
    if (NULL == p)
    {
        perror("createEmptyLinkQueue p malloc failed");
        return NULL;
    }
    //���������ͷ�ڵ�ռ䣬��rear��front��ָ��ͷ���
    p->front = p->rear = (linkqueue_list_t)malloc(sizeof(linkqueue_node_t));
    if (NULL == p->rear)
    {
        perror("p->rear malloc failed");
        return NULL;
    }
    p->rear->next = NULL;//������p->front->next = NULL;
    return p;
}
//2.���� data�������е�����
int inLinkQueue(linkqueue_t* p, datatype_linkqueue data)
{
    //1.����һ���µĽڵ㣬�������漴�����������
    linkqueue_list_t pnew = (linkqueue_list_t)malloc(sizeof(linkqueue_node_t));
    if (NULL == pnew)
    {
        perror("inLinkQueue pnew malloc failed");
        return -1;
    }
    //2.�����е����ݷ��뵽�µĽڵ���
    pnew->data = data;
    pnew->next = NULL;
    //3.���½ڵ������ӵ������β��
    p->rear->next = pnew;//�½ڵ����ӵ������β
    p->rear = pnew;//rear�ƶ�����Ϊrear��Զָ��ǰ�����β
    return 0;
}
//3.���� 
datatype_linkqueue outLinkQueue(linkqueue_t* p)
{
    linkqueue_list_t pdel = NULL;//ָ��ɾ���Ľڵ�
    //1.�ݴ��ж�
    if (isEmptyLinkQueue(p))
    {
        printf("isEmptyLinkQueue !!\n");
        return NULL;
    }
    //2.��������
    //(1)����pdelָ�򼴽���ɾ���Ľڵ����frontָ��Ľڵ㣬����ÿ��ɾ���Ķ���frontָ����Ǹ��ڵ�
    pdel = p->front;
    //(2)��front����ƶ�һ��λ��
    p->front = p->front->next;
    //(3)�ͷű�ɾ���ڵ�
    free(pdel);
    pdel = NULL;
    //(4)�����ݳ���
    return p->front->data;
}
//4.�ж϶����Ƿ�Ϊ��
int isEmptyLinkQueue(linkqueue_t* p)
{
    return p->front == p->rear;
}
//5.����г��ȵĺ���
int lengthLinkQueue(linkqueue_t* p)
{
    int len = 0;
    linkqueue_list_t h = p->front;//�������ͷָ�뱣��ĵ�ַ��h,���ֱ����front���󳤶�֮����Ҳ��������ͷ����h���ƶ�����front���ƶ�
    //�󳤶ȣ��൱�ڱ�����ͷ�ĵ�������
    while (h->next != NULL)
    {
        h = h->next;
        len++;
    }
    return len;
}
//6.��ն���
void clearLinkQueue(linkqueue_t* p)
{
    while (!isEmptyLinkQueue(p))//ֻҪ��Ϊ�գ��ͳ���
        outLinkQueue(p);
}