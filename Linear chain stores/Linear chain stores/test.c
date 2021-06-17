#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node,*LinkList;

typedef struct DulNode
{
	ElemType data;
	struct DulNode* prior;//ǰ��ָ��
	struct DulNode* next;//���ָ��
}DulNode,*DuLinlList;

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

int ListInsert(LinkList *L, int i, ElemType e)//����
{
	LinkList p ,s;
	p = *L;
	int j = 0;//��ͷ��㿪ʼ
	while (p && j < i - 1)//pָ���i-1����㣬Ѱ�ҵ�i-1�����
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)
		return 0;
	else
	{
		s = (LinkList)malloc(sizeof(Node));
		s->data = e;
		s->next = p->next;
		p->next = s;
	}
	return 1;
}

int ListDelete(LinkList* L, int i, ElemType* e)//ɾ��
{
	LinkList p ,q;
	p = *L;
	int j = 1;
	while (p->next && j < i - 1)//����Ϊʲô����P��ԭ��ȡֵ��Χ���������ֻ�ܲ��뵽���һ�����ǰ�����������һ��ָ��Ϊ�գ�����ȡֵ��Χ��
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i - 1)
		return 0;
	q = p->next;//�����ַ
	p->next = q->next;
	*e = q->data;//��������
	free(q);
	return 1;
}

int InsertBefore(LinkList *L,int n)//ǰ�巨
{
	LinkList p;
	int i;//������
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;//������ͷ���ĵ�����
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));//�����½��
		printf("�����½���������%d\n");
		scanf("%d", p->data);
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

void InsertAfter(LinkList* L, int n)
{
	LinkList p, r;
	int i;
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;//rΪָ��β���ı���
	for (i = 0; i < n; i++)
	{
		p = (Node*)malloc(sizeof(Node));//�����½��
		printf("�����½���������%d\n");
		scanf("%d", p->data);
		r->next = p;//���½�㸳��ָ��β���ı���
		r = p;//���½�㶨��Ϊ��β�ն˽��
	}
	r->next = NULL;//��ֹ����
}
int main()
{

}