#define _CRT_SECURE_NO_WARNINGS 1
/*
ADT ASet
{
	数据对象：D = { di | 0 <= i <= n; n为一个正整数 }

	数据关系：无

	基本运算：
			  CreateSet(&s,a,n);//创建一个集合，s是数据变量名，a是数组，n数组的长度
			  DispSet(s);//输出集合S中的所有元素
			  InSet(s,e);//判断e是否在集合S中，如果在，返回true，否则返回false
			  Add(s1,s2,s3);//求s1和s2的并集，并把结果放在s3
			  Sub(s1,s2,s4);//求s1和s2的差集，并把结果放在s4
			  InterSection(s1,s2,s5);//求s1和s2的交集，并把结果放在s5
}
*/

#include <stdio.h>
#include <string.h>
#define MAXSIZE 100


typedef struct
{
	int data[MAXSIZE];
	int length;
}Set;

//创建集合
void CreateSet(Set &s,int a[],int sz)
{
	int i = 0;
	for (i=0;i<sz;i++)
	{
		s.data[i] = a[i];
	}
	s.length = sz;
}

//输出集合
void DispSet(Set &s)
{
	int i = 0;
	for (i=0;i<s.length;i++)
	{
		printf("%d ", s.data[i]);
	}
	printf("\n");
}

//判断
char InSet(Set &s,int e)
{
	int i = 0;
	for (i = 0; i < s.length; i++)
	{
		if (e == s.data[i])
		{
			return true;
		}
	}
	return false;
}

//求两个集合的并集
void Add(Set& s1, Set& s2, Set& s3)
{
	int i = 0;
	for (i = 0; i < s1.length; i++)
	{
		s3.data[i] = s1.data[i];
	}
	s3.length = s1.length;

	for (i= 0;i<s2.length;i++)
	{
		if (!InSet(s3, s2.data[i]))
		{
			int j = 0;
			int count = 1;
			for (j = s3.length - 1; j > 0; j--)
			{
				if (s3.data[j] > s2.data[i])
				{
					int tmp = s3.data[j];
					s3.data[j] = s2.data[i];
					s3.data[j + 1] = tmp;
					count = 0;
				}
			}
			if (count)
				s3.data[s3.length] = s2.data[i];
			s3.length++;
			/*s3.data[s3.length] = s2.data[i];
			s3.length++;*/
		}
	}
}

//冒泡排序
void sort(Set &s)
{
	int i = 0;
	for (i = 0; i < s.length; i++)
	{
		int j = 0;
		for (j = 0;j<s.length - 1 - i; j++)
		{
			if (s.data[j] > s.data[j + 1])
			{
				int tmp = s.data[j];
				s.data[j] = s.data[j+1];
				s.data[j + 1] = tmp;
			}
		}
	}

}

//求两个集合的差集
//void Sub(Set& s1, Set& s2, Set& s4)
//{
//	int i = 0;
//	for (i = 0; i < s1.length; i++)
//	{
//		s4.data[i] = s1.data[i];
//	}
//	s4.length = s1.length;
//	
//	for (i = 0; i < s2.length; i++)
//	{
//		if (InSet(s4, s2.data[i]))
//		{
//			int j = 0;
//			for (j = 0; j < s4.length; j++)
//			{
//				if (s4.data[j] == s2.data[i])
//				{
//					int n = 0;
//					for (n = 0 + j; n < s4.length; n++)
//					{
//						s4.data[n] = s4.data[n + 1];
//					}
//					s4.length--;
//				}
//			}
//		}
//
//	}
//
//}
//求两个集合的差集
void Sub(Set& s1, Set& s2, Set& s4)
{
	int i = 0;
	int j = 0;
	s4.length = 0;
	for (i = 0; i < s1.length; i++)
	{

		if (!InSet(s2, s1.data[i]))
		{
			s4.data[j] = s1.data[i];
			j++;
			s4.length++;
		}
	}
	for (i = 0; i < s2.length; i++)
	{

		if (!InSet(s1, s2.data[i]))
		{
			s4.data[j] = s2.data[i];
			j++;
			s4.length++;
		}
	}
	sort(s4);
}

//求两个集合的交集
void InterSection(Set &s1, Set &s2, Set &s5)
{
	int i = 0;
	int j = 0;
	s5.length = 0;
	for (i = 0; i < s1.length; i++)
	{
		if (InSet(s2, s1.data[i]))
		{
				s5.data[j] = s1.data[i];
				j++;
				s5.length++;
		}
	}
	sort(s5);
}


int main()
{
	Set s1, s2, s3, s4, s5;
	int a[] = { 1,2,3,4,5,6};
	int b[] = { 2,3,4,5,6,7,8 };
	//int b[] = { 200,199,188,177,166,122,44,33,22,11,1 };
	int sz1 = sizeof(a) / sizeof(a[0]);
	int sz2 = sizeof(b) / sizeof(b[0]);

	//创建集合
	CreateSet(s1, a, sz1);
	CreateSet(s2, b, sz2);

	//输出集合
	printf("s1:");
	DispSet(s1);
	printf("s2:");
	DispSet(s2);

	//判断,如果在就返回true，否则返回false
	int e = 0;
	printf("输入一个数，来判断他是否在集合中:>");
	scanf("%d",&e);
	if (InSet(s1, e))
		printf("%d在s1集合中\n",e);
	else
		printf("%d不在s1集合中\n", e);
	if (InSet(s2, e))
		printf("%d在s2集合中\n", e);
	else
		printf("%d不在s2集合中\n", e);

	//求两个集合的并集,存储的2个集合必须是顺序排列
	printf("s1和s2的并集为:");
	Add(s1, s2, s3);
	DispSet(s3);

	//求两个集合的差集
	printf("s1和s2的差集为:");
	Sub(s1, s2, s4);
	DispSet(s4);

	//求两个集合的交集
	printf("s1和s2的交集为:");
	InterSection(s1,s2,s5);
	DispSet(s5);

	return 0;
}

