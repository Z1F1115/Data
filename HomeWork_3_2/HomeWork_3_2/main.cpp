#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#define OK 1
#define ERROP 0
#define MAXSIZE 20  //���洢��ѧ������


typedef struct{
	char number[20];//ѧ��
	char name[20];//����
	int fraction;//����
}Student;

typedef Student ElemType;

typedef struct{
	ElemType data[MAXSIZE];
	int length;
}SqList;

//����˳���
void CreateList(SqList *& L)
{
	strcpy(L->data[0].number , "123456789");
	strcpy(L->data[0].name , "����");
	L->data[0].fraction = 90;
	strcpy(L->data[1].number , "123456788");
	strcpy(L->data[1].name , "����");
	L->data[1].fraction = 80;
	strcpy(L->data[2].number , "123456787");
	strcpy(L->data[2].name , "����");
	L->data[2].fraction = 70;
	L->length = 3;
}

//��ʼ��
void InitList(SqList * &L)
{
	L = new SqList;
	//L = (SqList *)malloc(sizeof(SqList));
	L->length = 0;
}

//��ʾ�������
void Display(SqList *&L)
{
	int j = 0;
	printf("ѧ��       ����  �ɼ�\n");
	for (j = 0; j < L->length; j++)
		printf("%s  %s  %d\n",L->data[j].number,L->data[j].name,L->data[j].fraction);
	printf("-----------��%d��ѧ��-------------\n",L->length);
	printf("---------------------------------\n");
}

void Content(ElemType &e)
{
	printf("����ѧ����ѧ��:>");
	scanf("%s",e.number);
	printf("����ѧ��������:>");
	scanf("%s", e.name);
	printf("����ѧ���ĳɼ�:>");
	scanf("%d",&e.fraction);
}

//����
bool ListInsert(SqList*& L, int i,ElemType e)
{
	int j = 0;
	if (i <= 0 || i > L->length + 1 || i > MAXSIZE){
		printf("�����ɲ���ķ�Χ\n");
		return false;
	}
	Content(e);//�������ѧ������Ϣ
	for (j = L->length; j >= i; j--)
		L->data[j ] = L->data[j-1];
	/*printf("������Ҫ����ѧ����ѧ��:>");
	scanf("%s", L.data[j].number);
	printf("������Ҫ����ѧ��������:>");
	scanf("%s", L.data[j].name);
	printf("������Ҫ����ѧ���ĳɼ�:>");
	scanf("%d", &L.data[j].fraction);
	*/
	strcpy(L->data[j].number, e.number);
	strcpy(L->data[j].name, e.name);
	L->data[j].fraction = e.fraction;

	printf("����ɹ�\n");
	L->length++;

	return true;
}

//ɾ��
bool ListDelete(SqList*& L, int i)
{
	int j = 0;
	if (i <= 0 || i > L->length || i > MAXSIZE){
		printf("������ɾ���ķ�Χ\n");
		return false;
	}
	for (j = i; j <= L->length ; j++ )
		L->data[ j-1 ] = L->data[j];
	L->length--;
	printf("ɾ���ɹ�\n");

	return true;
}

//�޸�
bool ListAmend(SqList*& L,int i,ElemType e)
{
	int j = 0;
	if (i <= 0 || i > L->length || i > MAXSIZE){
		printf("�������޸ĵķ�Χ\n");
		return false;
	}
	/*printf("������Ҫ�޸�ѧ����ѧ��:>");
	scanf("%s", L.data[i-1].number);
	printf("������Ҫ�޸�ѧ��������:>");
	scanf("%s", L.data[i-1].name);
	printf("������Ҫ�޸�ѧ���ĳɼ�:>");
	scanf("%d", &L.data[i-1].fraction);
	*/
	Content(e);//�����޸�ѧ������Ϣ
	strcpy(L->data[i-1].number, e.number);
	strcpy(L->data[i-1].name, e.name);
	L->data[i-1].fraction = e.fraction;
	printf("�޸ĳɹ�\n");

	return true;
}

////�жϱ��Ƿ�Ϊ��
//bool ListEmpty(SqList L)
//{
//
//}
//

void menu()
{
	printf("*********************************\n");
	printf("*********************************\n");
	printf("*********  1.�鿴ѧ����  ********\n");
	printf("*********  2.����ѧ��    ********\n");
	printf("*********  3.ɾ��ѧ��    ********\n");
	printf("*********  4.�޸�ѧ����  ********\n");
	printf("*********  5.�������ֲ�ѯѧ��  **\n");
	printf("*********  0.�˳�        ********\n");
	printf("*********************************\n");
	printf("*********************************\n");

}

int main()
{
	int i = 0;
	int n = 0;
	SqList *L;
	InitList(L);
	CreateList(L);
	ElemType e = {0};
	do
	{
		menu();
		printf("��ѡ����Ĳ���:>");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			system("cls");
			Display(L);
			break;
		case 2:
			system("cls");
			Display(L);
			printf("������Ҫ���뵽�ڼ���:>");
			scanf("%d",&n);
			ListInsert(L,n,e);
			break;
		case 3:
			system("cls");
			Display(L);
			printf("������Ҫɾ���ڼ���:>");
			scanf("%d",&n);
			ListDelete(L,n);
			break;
		case 4:
			system("cls");
			Display(L);
			printf("������Ҫ�޸ĵڼ���:>");
			scanf("%d",&n);
			ListAmend(L,n,e);
			break;
		case 5:
			system("cls");
			printf("�п���д\n");
			break;
		case 0:
			system("cls");
			printf("*********  �˳�ѧ����  ********\n");
			break;
		default:
			system("cls");
			printf("û�д���ѡ��������ѡ��:>\n");
		}
	} while (i);
	
	return 0;
}
