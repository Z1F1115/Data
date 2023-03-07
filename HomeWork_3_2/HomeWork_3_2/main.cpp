#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#define OK 1
#define ERROP 0
#define MAXSIZE 20  //最多存储的学生人数


typedef struct{
	char number[20];//学号
	char name[20];//名字
	int fraction;//分数
}Student;

typedef Student ElemType;

typedef struct{
	ElemType data[MAXSIZE];
	int length;
}SqList;

//建立顺序表
void CreateList(SqList *& L)
{
	strcpy(L->data[0].number , "123456789");
	strcpy(L->data[0].name , "张三");
	L->data[0].fraction = 90;
	strcpy(L->data[1].number , "123456788");
	strcpy(L->data[1].name , "李四");
	L->data[1].fraction = 80;
	strcpy(L->data[2].number , "123456787");
	strcpy(L->data[2].name , "王五");
	L->data[2].fraction = 70;
	L->length = 3;
}

//初始化
void InitList(SqList * &L)
{
	L = new SqList;
	//L = (SqList *)malloc(sizeof(SqList));
	L->length = 0;
}

//显示表格内容
void Display(SqList *&L)
{
	int j = 0;
	printf("学号       姓名  成绩\n");
	for (j = 0; j < L->length; j++)
		printf("%s  %s  %d\n",L->data[j].number,L->data[j].name,L->data[j].fraction);
	printf("-----------有%d名学生-------------\n",L->length);
	printf("---------------------------------\n");
}

void Content(ElemType &e)
{
	printf("输入学生的学号:>");
	scanf("%s",e.number);
	printf("输入学生的姓名:>");
	scanf("%s", e.name);
	printf("输入学生的成绩:>");
	scanf("%d",&e.fraction);
}

//插入
bool ListInsert(SqList*& L, int i,ElemType e)
{
	int j = 0;
	if (i <= 0 || i > L->length + 1 || i > MAXSIZE){
		printf("超出可插入的范围\n");
		return false;
	}
	Content(e);//输入插入学生的信息
	for (j = L->length; j >= i; j--)
		L->data[j ] = L->data[j-1];
	/*printf("输入你要插入学生的学号:>");
	scanf("%s", L.data[j].number);
	printf("输入你要插入学生的姓名:>");
	scanf("%s", L.data[j].name);
	printf("输入你要插入学生的成绩:>");
	scanf("%d", &L.data[j].fraction);
	*/
	strcpy(L->data[j].number, e.number);
	strcpy(L->data[j].name, e.name);
	L->data[j].fraction = e.fraction;

	printf("插入成功\n");
	L->length++;

	return true;
}

//删除
bool ListDelete(SqList*& L, int i)
{
	int j = 0;
	if (i <= 0 || i > L->length || i > MAXSIZE){
		printf("超出可删除的范围\n");
		return false;
	}
	for (j = i; j <= L->length ; j++ )
		L->data[ j-1 ] = L->data[j];
	L->length--;
	printf("删除成功\n");

	return true;
}

//修改
bool ListAmend(SqList*& L,int i,ElemType e)
{
	int j = 0;
	if (i <= 0 || i > L->length || i > MAXSIZE){
		printf("超出可修改的范围\n");
		return false;
	}
	/*printf("输入你要修改学生的学号:>");
	scanf("%s", L.data[i-1].number);
	printf("输入你要修改学生的姓名:>");
	scanf("%s", L.data[i-1].name);
	printf("输入你要修改学生的成绩:>");
	scanf("%d", &L.data[i-1].fraction);
	*/
	Content(e);//输入修改学生的信息
	strcpy(L->data[i-1].number, e.number);
	strcpy(L->data[i-1].name, e.name);
	L->data[i-1].fraction = e.fraction;
	printf("修改成功\n");

	return true;
}

////判断表是否为空
//bool ListEmpty(SqList L)
//{
//
//}
//

void menu()
{
	printf("*********************************\n");
	printf("*********************************\n");
	printf("*********  1.查看学生表  ********\n");
	printf("*********  2.插入学生    ********\n");
	printf("*********  3.删除学生    ********\n");
	printf("*********  4.修改学生表  ********\n");
	printf("*********  5.输入名字查询学生  **\n");
	printf("*********  0.退出        ********\n");
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
		printf("请选择你的操作:>");
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
			printf("请输入要插入到第几行:>");
			scanf("%d",&n);
			ListInsert(L,n,e);
			break;
		case 3:
			system("cls");
			Display(L);
			printf("请输入要删除第几行:>");
			scanf("%d",&n);
			ListDelete(L,n);
			break;
		case 4:
			system("cls");
			Display(L);
			printf("请输入要修改第几行:>");
			scanf("%d",&n);
			ListAmend(L,n,e);
			break;
		case 5:
			system("cls");
			printf("有空在写\n");
			break;
		case 0:
			system("cls");
			printf("*********  退出学生表  ********\n");
			break;
		default:
			system("cls");
			printf("没有此项选择，请重新选择:>\n");
		}
	} while (i);
	
	return 0;
}
