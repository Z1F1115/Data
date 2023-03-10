#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

#define MAXSIZE 20

typedef int ElemType;

typedef struct {
	ElemType *data;
	int length;
}SqList;

//建立顺序表
void CreateList(SqList *&L,ElemType a[],int n);
//初始化顺序表
void InltList(SqList *&L);
//销毁顺序表
void DestroyList(SqList *&L);
//判断顺序表是否为空表
bool ListEmpty(SqList *L);//空表，则返回true，否则，返回false；
//求顺序表长度
int ListLength(SqList *L);
//打印顺序表的内容
void DispList(SqList *L);
//按序号求顺序表中的元素
bool GetElem(SqList *L,int i,ElemType &e);
//查找元素在第几个位置
int LocateElem(SqList *L,ElemType e);
//插入数据元素
bool ListInsert(SqList *&L,int i,ElemType e);
//删除数据元素
bool ListDelete(SqList *&L,int i,ElemType &e);
