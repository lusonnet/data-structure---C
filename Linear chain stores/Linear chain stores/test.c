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

int ListLength(LinkList L)//���
{
	int i = 0;
	LinkList p = L->next;//pָ���һ�����
	while (p)//�жϲ����������
	{
		i++;
		p = p->next;//�ƶ�ָ��
	}
	return i;
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

int ClearList(LinkList *L)//���
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

int GetElem(LinkList L,int i, ElemType *e)//��ȡ��i��Ԫ��
{
	LinkList p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)//û���ҵ�
		return 0;
	*e = p->data;//��ȡ�ɹ�
	return 1;
}

int* LocaElem(LinkList L, ElemType* e)//����ֵΪe������Ԫ��,���ص�ַ
{
	LinkList p = L->next;
	while (p && p->data != *e)
		p = p->next;
	return p;
}

int LocateElem(LinkList L, ElemType e)//�������
{
	LinkList p = L->next;
	int j = 1;
	while (p && p->data != e)
	{
		p = p->next;
		j++;
	}
	if (p)
	{
		return j;
	}
	else
		return 0;
}



int main()
{

}