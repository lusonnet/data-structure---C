#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node,*LinkList;

int InitList(LinkList *L)//初始化
{
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	return 1;
}

int ListLength(LinkList L)//求表长
{
	int i = 0;
	LinkList p = L->next;//p指向第一个结点
	while (p)//判断并计算结点个数
	{
		i++;
		p = p->next;//移动指针
	}
	return i;
}

int ListEmpty(LinkList L)//判断是否为空
{
	if (L->next)
		return 0;
	else
		return 1;
}

int DestroyList(LinkList *L)//销毁
{
	LinkList p;
	while (*L)
	{
		p = *L;//让p和L指向相同结点
		L = (*L)->next;//让L指向下一个结点
		free(p);//销毁p 不能free(L) - 会弄断链表
	}
}

int ClearList(LinkList *L)//清空
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

int GetElem(LinkList L,int i, ElemType *e)//获取第i个元素
{
	LinkList p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)//没有找到
		return 0;
	*e = p->data;//获取成功
	return 1;
}

int* LocaElem(LinkList L, ElemType* e)//查找值为e的数据元素,返回地址
{
	LinkList p = L->next;
	while (p && p->data != *e)
		p = p->next;
	return p;
}

int LocateElem(LinkList L, ElemType e)//返回序号
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