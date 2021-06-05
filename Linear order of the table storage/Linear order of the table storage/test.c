#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef int DataType;//一是表明该类型的特殊作用，二是将来有可能要改变这种类型（比如提高精度）
typedef struct
{
	int length;
	DataType data[MAX];// //定义一个DataType类型的数组
}SqList;

int InitList(SqList* L)//初始化
{
	//L = (SqList*)malloc(sizeof(SqList));//开辟空间
	L->length = 0;
	return 0;
}

int ListEmpty(SqList L)//判断是否为空表
{
	if (L.length == 0)
		return 1;
	else
		return 0;
}

int ClearList(SqList* L)//清空线性表
{
	L->length = 0;
	return 0;
}

int getData(SqList* L, int i, DataType* e)//寻找第i个元素
{
	if (L->length == 0 || i<1 || i>L->length)
		return 0;
	else
		*e = L->data[i - 1];//寻找第i个元素，下标为i-1
	return 1;//找到了
}

int ListInsert(SqList *L, int i, DataType e)//在i处插入e
{
	int k;
	if (L->length == MAX)
	{
		printf("顺序表已满\n");
		return 0;
	}
	if (i<0 || i>L->length + 1)
	{
		printf("插入位置不合法\n");
		return 0;
	}
	for (k = L->length - 1; k >= i - 1; k--)
	{
		L->data[k + 1] = L->data[k];//i之后元素向后移动
	}
	L->data[i - 1] = e;//插入e
	++L->length;
	return 1;
}

int ListDelete(SqList* L, int i, DataType* e)
{
	int k;
	if (i<1 || i>L->length)
		return 0;//删除位置不正确
	if (L->length == 0)
		return 0;//空表
	*e = L->data[i - 1];
	if (i <= L->length)
	{
		for (k = i; k < L->length; k++)
			L->data[k - 1] = L->data[k];
	}
	L->length--;
	return 0;
}

int ListTraverse(SqList L)
{
	int i;
	for (i = 0; i <= L.length - 1; i++)
	{
		printf("%3d", L.data[i]);
	}
	printf("\n");
	return 1;
}


int main()
{
	int i, j, k;
	SqList L;
	DataType e;
	i = InitList(&L);
	printf("初始化后表长:%d\n", L.length);

	for (j = 1; j <= 5; j++)
		i = ListInsert(&L, 1, j);
	printf("表头插入数字1到5之后：");
	ListTraverse(L);
	printf("插入五个数字后表长:%d\n", L.length);

	i = ListTraverse(L);
	printf("此时表是否为空（1代表是，0代表否）：%d\n", i);

	i = ClearList(&L);
	printf("\n清空表后，表长为%d\n", L.length);
	printf("此时表是否为空（1代表是，0代表否）：%d\n", i);
	for (j = 1; j <= 5; j++)
	{
		i = ListInsert(&L, j, j);
	}
	printf("表尾插入五个数字后:");
	ListTraverse(L);
	printf("插入五个数字后表长为:%d\n", L.length);
	getData(&L, 3, &e);
	printf("第三个数字是：%d\n", e);

	i = ListDelete(&L, 2, &e);
	printf("删除第二个数据后为:");
	ListTraverse(L);
	printf("被删除的数字是:%d\n", e);

	i = L.length;
	printf("输入想要删除的数据的序号:");
	scanf("%d", &k);
	if (k > i || k <= 0)
		printf("位置不对\n");
	else
	{
		i = ListDelete(&L, k, &e);
		printf("删除第%d个数字的值为%d,删除后表为", k, e);
		ListTraverse(L);

	}
	return 0;
}