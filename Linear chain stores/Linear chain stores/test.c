#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node,*LinkList;

int InitList(LinkList *L)//��ʼ��
{
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	return 1;
}

int ListEmpty(LinkList L)//�ж��Ƿ�Ϊ��
{
	if (L->next)
		return 0;
	else
		return 1;
}

int DestroyList(LinkList *L)//����
{
	LinkList p;
	while (*L)
	{
		p = *L;//��p��Lָ����ͬ���
		L = (*L)->next;//��Lָ����һ�����
		free(p);//����p ����free(L) - ��Ū������
	}
}

int ClearList(LinkList *L)
{
	LinkList p, q;
	p = (*L)->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return 1;
}

int CulList()
{

}



int main()
{

}