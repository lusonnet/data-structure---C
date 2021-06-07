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