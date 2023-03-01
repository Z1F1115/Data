#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h> 
////第一种
//typedef struct student{
//	char num[8];
//	char name[8];
//	int score;
//	struct student* next;
//}Lnode,*LinkList;
//
//第二种
#define ElemType L
#define OK 1
#define Status int
#define ERROR 0

typedef struct {
	char num[8];
	char name[8];
	int score;
}ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;

LNode* p, * q;
int i = 0, j = 0;

/*
Status InitList_L(LinkList &L) {
	L=nex LNode;
	//L=(LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	return OK;
}
*/

//释放所有结点--摧毁链表
//L = L->next;
//第一种释放结点 
//C++
//delete p;
//用delete就要用new来创建；
//第二种释放结点 
//C 
//free(p);
//用free(p)就要用malloc(L)来创建;
//循环释放所有结点
//结束条件：L==NULL
//循环条件：L!=NULL
//或者：L
//

//清空链表
Status ClearLinst(LinkList& L) {
	LNode* p, * q;
	p = L->next;
	while (p) {
		q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL;
	return OK;
}

//求单链表的表长
int ListLength_L(LinkList& L) {
	int i = 0;
	LNode* p, * q;
	p = L->next;
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}

//取值                                
Status GetElem_L(LinkList L, int i, ElemType& e) {
	LNode* p;
	int j = 0;
	p = L->next; j = 1;
	while (p && j < i) {
		p = p->next; ++j;
	}
	if (!p || j > i) return ERROR;
	e = p->data;
	return OK;
}

//查找，第一种
LNode* LocateElem_L1(LinkList L, ElemType e) {
	LNode* p;
	int i = 0;
	p = L->next;

	/*while (p) {
		if (e == p->data) break;
		else {
			p = p->next;
			i++;
		}
	}*/
	//if (NULL == p->next) return ERROR;

	while (p && p->data != e)
		p = p->next;
	return p;
}

//查找，第二种
int LocateElem_L2(LinkList L,Elemtype e) {
	p = L->next; j = 1;
	while (p&&p->data!=e) {
		p = p->next; j++;
	}
	if (p) return j;
	else return 0;
}


int main()
{

	return 0;
}