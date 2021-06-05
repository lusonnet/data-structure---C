#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef int DataType;//һ�Ǳ��������͵��������ã����ǽ����п���Ҫ�ı��������ͣ�������߾��ȣ�
typedef struct
{
	int length;
	DataType data[MAX];// //����һ��DataType���͵�����
}SqList;

int InitList(SqList* L)//��ʼ��
{
	//L = (SqList*)malloc(sizeof(SqList));//���ٿռ�
	L->length = 0;
	return 0;
}

int ListEmpty(SqList L)//�ж��Ƿ�Ϊ�ձ�
{
	if (L.length == 0)
		return 1;
	else
		return 0;
}

int ClearList(SqList* L)//������Ա�
{
	L->length = 0;
	return 0;
}

int getData(SqList* L, int i, DataType* e)//Ѱ�ҵ�i��Ԫ��
{
	if (L->length == 0 || i<1 || i>L->length)
		return 0;
	else
		*e = L->data[i - 1];//Ѱ�ҵ�i��Ԫ�أ��±�Ϊi-1
	return 1;//�ҵ���
}

int ListInsert(SqList *L, int i, DataType e)//��i������e
{
	int k;
	if (L->length == MAX)
	{
		printf("˳�������\n");
		return 0;
	}
	if (i<0 || i>L->length + 1)
	{
		printf("����λ�ò��Ϸ�\n");
		return 0;
	}
	for (k = L->length - 1; k >= i - 1; k--)
	{
		L->data[k + 1] = L->data[k];//i֮��Ԫ������ƶ�
	}
	L->data[i - 1] = e;//����e
	++L->length;
	return 1;
}

int ListDelete(SqList* L, int i, DataType* e)
{
	int k;
	if (i<1 || i>L->length)
		return 0;//ɾ��λ�ò���ȷ
	if (L->length == 0)
		return 0;//�ձ�
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
	printf("��ʼ�����:%d\n", L.length);

	for (j = 1; j <= 5; j++)
		i = ListInsert(&L, 1, j);
	printf("��ͷ��������1��5֮��");
	ListTraverse(L);
	printf("����������ֺ��:%d\n", L.length);

	i = ListTraverse(L);
	printf("��ʱ���Ƿ�Ϊ�գ�1�����ǣ�0����񣩣�%d\n", i);

	i = ClearList(&L);
	printf("\n��ձ�󣬱�Ϊ%d\n", L.length);
	printf("��ʱ���Ƿ�Ϊ�գ�1�����ǣ�0����񣩣�%d\n", i);
	for (j = 1; j <= 5; j++)
	{
		i = ListInsert(&L, j, j);
	}
	printf("��β����������ֺ�:");
	ListTraverse(L);
	printf("����������ֺ��Ϊ:%d\n", L.length);
	getData(&L, 3, &e);
	printf("�����������ǣ�%d\n", e);

	i = ListDelete(&L, 2, &e);
	printf("ɾ���ڶ������ݺ�Ϊ:");
	ListTraverse(L);
	printf("��ɾ����������:%d\n", e);

	i = L.length;
	printf("������Ҫɾ�������ݵ����:");
	scanf("%d", &k);
	if (k > i || k <= 0)
		printf("λ�ò���\n");
	else
	{
		i = ListDelete(&L, k, &e);
		printf("ɾ����%d�����ֵ�ֵΪ%d,ɾ�����Ϊ", k, e);
		ListTraverse(L);

	}
	return 0;
}