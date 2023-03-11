#include "SqList.h"

//初始化顺序表
void InltList(SqList*& L) {
	L = new SqList;
	L->data = new ElemType[MAXSIZE];
	L->length = 0;
}

//建立顺序表
void CreateList(SqList *&L,ElemType a[],int n){
	int i = 0,k = 0;
	while (i<n){
		L->data[k] = a[i];
		k++;i++;
	}
	L->length = k;
}

//销毁顺序表
void DestroyList(SqList *&L){
	delete L;
}

//判断顺序表是否为空表
//空表，则返回true，否则，返回false；
bool ListEmpty(SqList *L){
	return (L->length == 0);
}

//求顺序表长度
int ListLength(SqList *L){
	return (L->length);
}

//打印顺序表的内容
void DispList(SqList *L){
	int i = 0;
	for(i = 0;i<L->length;i++)
		printf("%d ",L->data[i]);
	printf("\n");
}

//按序号求顺序表中的元素
bool GetElem(SqList *L,int i,ElemType &e){
	if(i<1 || i>L->length)
		return false;
	e = L->data[i-1];
	return true;
}

//查找元素在第几个位置
int LocateElem(SqList *L,ElemType e){
	int i = 0;
	while (i < L->length && L->data[i]!=e)
		i++;
	if (i>=L->length)
		return 0;
	else 
		return i+1;
}

//插入数据元素
bool ListInsert(SqList *&L,int i,ElemType e){
	int j = 0;
	if (i<1 || i>L->length+1 || L->length == MAXSIZE)
		return false;
	i--;
	for (j = L->length;j>i;j--)
		L->data[j] = L->data[j-1];
	L->data[i] = e;
	L->length++;
	return true;
}

//删除数据元素
bool ListDelete(SqList *&L,int i,ElemType &e){
	int j = 0;
	if (i<1 || i>L->length)
		return false;
	i--;
	e = L->data[i];
	for(j=i;j<L->length-1;j++)
		L->data[j]=L->data[j+1];
	L->length--;
	return true;
}

