#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#define ElemType int

typedef struct Node {
	ElemType data;
	struct Node* next;
}LinkNode;

//初始化链表
void InitList(LinkNode *&L) {
	L = new LinkNode;//创建动态分配
	L->next = NULL;//让后继指向空
}
//时间复杂度O（1）
//空间复杂度O（1）

//创建链表--尾插
void CreateListR(LinkNode*& L, ElemType a[], int sz){
	int i = 0;
	LinkNode* P,*S;//S作为插入数据结点
	P = L;//P为始终指向尾结点
	for (i = 0; i < sz; i++) {
		S = new LinkNode;//创建S的动态分配
		S->data = a[i];//给S分配内容
		P->next = S;//把尾结点指向S
		P = S;//移动P，让他为新的尾结点
	}
	P->next = NULL;//让尾结点指向空
}
//时间复杂度O（sz）
//空间复杂度O（1）

//求出第n位的内容
int GetData(LinkNode* L, int n){
	int i = 0;
	LinkNode* P;//创建一个P来指向合集的内容
	P = L->next;//让P指向合集的第一个内容
	//判断P是不是最后一个数组
	if (P->next == NULL)
		return -1;

	//用循环，让P指向你要找到位置
	for (i = 1; i < n; i++)
		P = P->next;//P向后移一位

	//返回P指向的内容
	return P->data;
}
//时间复杂度O（n）
//空间复杂度O（1）

//求LA和LB的合集，用LC来存放
void UnionList(LinkNode* LA, LinkNode* LB, LinkNode*& LC){
	LinkNode* pc, * pa, * pb;
	pa = LA->next;//用pa指向LA的头结点下一个（因为头结点是没有内容的）
	pb = LB->next;//用pb指向LB的头结点下一个
	pc = LC = LA;//先用LC指向LA，LC作为集合，用pc指向LC，来移动

	//如果pa或者pb有一个是空，循环结束
	while (pa && pb) {
		//判断pa和pb的内容大小，谁小就把谁向后移动
		if (pa->data <= pb->data) {
			pc->next = pa;//pc->next指向pa
			pc = pa;//移动pc
			pa = pa->next;//移动pa
		}
		else {
			pc->next = pb;//pc->next指向pb
			pc = pb;//移动pc
			pb = pb->next;//移动pb
		}
	}
	//剩下的直接放在pc后面
	pc->next = pa ? pa : pb;
}
//时间复杂度O（LA的长度+LB的长度）
//空间复杂度O（1）

int main(){
	LinkNode* La, * Lb;
	int arr1[5] = { 0 };
	int arr2[5] = { 0 };
	int i = 0;
	int ret = 0;

	printf("输入第一组升序数组:>");
	for (i = 0; i < 5; i++)
		scanf("%d",&arr1[i]);

	printf("输入第二组升序数组:>");
	for (i = 0; i < 5; i++)
		scanf("%d", &arr2[i]);
	
	//初始化链表
	InitList(La);
	InitList(Lb);

	//创建带结点链表，因为是升序，所以用尾插
	CreateListR(La,arr1,5);
	CreateListR(Lb,arr2,5);

	//创建一个Lc链表来存放La，Lb的合集
	LinkNode* Lc;
	
	//求出La和Lb的合集，用Lc链表来存放
	UnionList(La, Lb, Lc);

	//求出2个数组的中间位
	int sz = sizeof(arr1) / sizeof(arr1[0]) + sizeof(arr2) / sizeof(arr2[0]);
	
	//获得中间数
	ret = GetData(Lc,sz/2);
	//判断返回值
	if (-1 == ret)
		printf("找不到中位数\n");
	else
		printf("中位数是:>%d\n",ret);

	return 0;
}