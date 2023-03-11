#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

#define MAXSIZE 20

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LinkNode;

//初始化链表
void InitList(LinkNode *&L);
//创建链表--头插
void CreateListF(LinkNode*& L, ElemType a[], int n);
//创建链表--尾插
void CreateListR(LinkNode*& L, ElemType a[], int n);
//销毁链表
void DestroyList(LinkNode *&L);
//判断链表是否为空表
bool ListEmpty(LinkNode *L);
//求链表的长度
int ListLength(LinkNode *L);
//输出链表
void DispList(LinkNode *L);
//按序号求链表中元素
bool GetElem(LinkNode * L,int i,ElemType &e);
//按元素值查找
int LocateElem(LinkNode *L,ElemType e);
//插入数据元素
bool ListInsert(LinkNode *L,int i,ElemType e);
//删除数据元素
bool ListDelete(LinkNode*&L,int i,ElemType &e);