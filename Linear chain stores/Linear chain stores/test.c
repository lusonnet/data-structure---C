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
	struct DulNode* prior;//前驱指针
	struct DulNode* next;//后继指针
}DulNode,*DuLinlList;

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

int ListInsert(LinkList *L, int i, ElemType e)//插入
{
	LinkList p ,s;
	p = *L;
	int j = 0;//从头结点开始
	while (p && j < i - 1)//p指向第i-1个结点，寻找第i-1个结点
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

int ListDelete(LinkList* L, int i, ElemType* e)//删除
{
	LinkList p ,q;
	p = *L;
	int j = 1;
	while (p->next && j < i - 1)//这里为什么不是P的原因：取值范围，插入最多只能插入到最后一个结点前，如果它的下一个指向为空，则超了取值范围。
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i - 1)
		return 0;
	q = p->next;//保存地址
	p->next = q->next;
	*e = q->data;//保存数据
	free(q);
	return 1;
}

int InsertBefore(LinkList *L,int n)//前插法
{
	LinkList p;
	int i;//计数器
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;//建立带头结点的单链表
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));//生成新结点
		printf("输入新结点的数据域：%d\n");
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
	r = *L;//r为指向尾结点的变量
	for (i = 0; i < n; i++)
	{
		p = (Node*)malloc(sizeof(Node));//生成新结点
		printf("输入新结点的数据域：%d\n");
		scanf("%d", p->data);
		r->next = p;//将新结点赋予指向尾结点的变量
		r = p;//将新结点定义为表尾终端结点
	}
	r->next = NULL;//终止链表
}
int main()
{

}