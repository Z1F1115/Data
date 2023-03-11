#include "LinkNode.h"

//初始化链表
void InitList(LinkNode *&L){
	L = new LinkNode;
	L->next = NULL;
}

//创建链表--头插
void CreateListF(LinkNode*& L, ElemType a[], int n) {
	LinkNode* s;
	L->next = NULL;
	int i = 0;
	for (i = 0; i < n;i++) {
		s = new LinkNode;
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}

//创建链表--尾插
void CreateListR(LinkNode*& L, ElemType a[], int n) {
	LinkNode* s, * r;
	r = L;
	int i = 0;
	for (i = 0; i < n;i++) {
		s = new LinkNode;
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

//销毁链表
void DestroyList(LinkNode *&L){
	LinkNode *pre = L,*p = L->next;
	while (p != NULL){
		delete pre;
		pre = p;
		p = pre->next;
	}
	delete pre;
}

//判断链表是否为空表
bool ListEmpty(LinkNode *L){
	return (L->next == NULL);
}

//求链表的长度
int ListLength(LinkNode *L){
	int n = 0;
	LinkNode *p = L;
	while (p->next != NULL){
		n++;
		p=p->next;
	}
	return (n);
}

//输出链表
void DispList(LinkNode *L){
	LinkNode * p= L->next;
	while (p != NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

//按序号求链表中元素
bool GetElem(LinkNode * L,int i,ElemType &e){
	int j = 0;
	LinkNode*p=L;
	if(j<=0) return false;
	while (j<i && p != NULL){
		j++;
		p=p->next;
	}
	if(p == NULL)
		return false;
	else{
		e=p->data;
		return true;
	}
}

//按元素值查找
int LocateElem(LinkNode *L,ElemType e){
	int i = 1;
	LinkNode *p = L->next;
	while (p!=NULL && p->data != e){
		p=p->next;
		i++;
	}
	if(p== NULL)
		return 0;
	else 
		return i;
}

//插入数据元素
bool ListInsert(LinkNode *L,int i,ElemType e){
	int j= 0;
	LinkNode *p =L,*s;
	if(i<=0) return false;
	while (j<i-1 && p != NULL){
		j++;
		p= p->next;
	}
	if (p == NULL)
		return false;
	else{
		s = new LinkNode;
		s->data= e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}

//删除数据元素
bool ListDelete(LinkNode*&L,int i,ElemType &e){
	int j = 0;
	LinkNode*p = L,*q;
	if (i <= 0) return false;
	while (j<i-1 && p != NULL){
		j++;
		p=p->next;
	}
	if (p==NULL)
		return false;
	else{
		q=p->next;
		if (q== NULL)
			return false;
		e=q->data;
		p->next = q-> next;
		delete q;
		return true;
	}
}
