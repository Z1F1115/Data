#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#define ElemType int

typedef struct Node {
	ElemType data;
	struct Node* next;
}LinkNode;

//��ʼ������
void InitList(LinkNode *&L) {
	L = new LinkNode;//������̬����
	L->next = NULL;//�ú��ָ���
}
//ʱ�临�Ӷ�O��1��
//�ռ临�Ӷ�O��1��

//��������--β��
void CreateListR(LinkNode*& L, ElemType a[], int sz){
	int i = 0;
	LinkNode* P,*S;//S��Ϊ�������ݽ��
	P = L;//PΪʼ��ָ��β���
	for (i = 0; i < sz; i++) {
		S = new LinkNode;//����S�Ķ�̬����
		S->data = a[i];//��S��������
		P->next = S;//��β���ָ��S
		P = S;//�ƶ�P������Ϊ�µ�β���
	}
	P->next = NULL;//��β���ָ���
}
//ʱ�临�Ӷ�O��sz��
//�ռ临�Ӷ�O��1��

//�����nλ������
int GetData(LinkNode* L, int n){
	int i = 0;
	LinkNode* P;//����һ��P��ָ��ϼ�������
	P = L->next;//��Pָ��ϼ��ĵ�һ������
	//�ж�P�ǲ������һ������
	if (P->next == NULL)
		return -1;

	//��ѭ������Pָ����Ҫ�ҵ�λ��
	for (i = 1; i < n; i++)
		P = P->next;//P�����һλ

	//����Pָ�������
	return P->data;
}
//ʱ�临�Ӷ�O��n��
//�ռ临�Ӷ�O��1��

//��LA��LB�ĺϼ�����LC�����
void UnionList(LinkNode* LA, LinkNode* LB, LinkNode*& LC){
	LinkNode* pc, * pa, * pb;
	pa = LA->next;//��paָ��LA��ͷ�����һ������Ϊͷ�����û�����ݵģ�
	pb = LB->next;//��pbָ��LB��ͷ�����һ��
	pc = LC = LA;//����LCָ��LA��LC��Ϊ���ϣ���pcָ��LC�����ƶ�

	//���pa����pb��һ���ǿգ�ѭ������
	while (pa && pb) {
		//�ж�pa��pb�����ݴ�С��˭С�Ͱ�˭����ƶ�
		if (pa->data <= pb->data) {
			pc->next = pa;//pc->nextָ��pa
			pc = pa;//�ƶ�pc
			pa = pa->next;//�ƶ�pa
		}
		else {
			pc->next = pb;//pc->nextָ��pb
			pc = pb;//�ƶ�pc
			pb = pb->next;//�ƶ�pb
		}
	}
	//ʣ�µ�ֱ�ӷ���pc����
	pc->next = pa ? pa : pb;
}
//ʱ�临�Ӷ�O��LA�ĳ���+LB�ĳ��ȣ�
//�ռ临�Ӷ�O��1��

int main(){
	LinkNode* La, * Lb;
	int arr1[5] = { 0 };
	int arr2[5] = { 0 };
	int i = 0;
	int ret = 0;

	printf("�����һ����������:>");
	for (i = 0; i < 5; i++)
		scanf("%d",&arr1[i]);

	printf("����ڶ�����������:>");
	for (i = 0; i < 5; i++)
		scanf("%d", &arr2[i]);
	
	//��ʼ������
	InitList(La);
	InitList(Lb);

	//���������������Ϊ������������β��
	CreateListR(La,arr1,5);
	CreateListR(Lb,arr2,5);

	//����һ��Lc���������La��Lb�ĺϼ�
	LinkNode* Lc;
	
	//���La��Lb�ĺϼ�����Lc���������
	UnionList(La, Lb, Lc);

	//���2��������м�λ
	int sz = sizeof(arr1) / sizeof(arr1[0]) + sizeof(arr2) / sizeof(arr2[0]);
	
	//����м���
	ret = GetData(Lc,sz/2);
	//�жϷ���ֵ
	if (-1 == ret)
		printf("�Ҳ�����λ��\n");
	else
		printf("��λ����:>%d\n",ret);

	return 0;
}