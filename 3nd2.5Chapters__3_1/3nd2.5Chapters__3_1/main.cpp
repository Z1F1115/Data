#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h> 
////��һ��
//typedef struct student{
//	char num[8];
//	char name[8];
//	int score;
//	struct student* next;
//}Lnode,*LinkList;
//
//�ڶ���
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

//�ͷ����н��--�ݻ�����
//L = L->next;
//��һ���ͷŽ�� 
//C++
//delete p;
//��delete��Ҫ��new��������
//�ڶ����ͷŽ�� 
//C 
//free(p);
//��free(p)��Ҫ��malloc(L)������;
//ѭ���ͷ����н��
//����������L==NULL
//ѭ��������L!=NULL
//���ߣ�L
//

//�������
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

//������ı�
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

//ȡֵ                                
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

//���ң���һ��
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

//���ң��ڶ���
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