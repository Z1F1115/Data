#include "SqList.h"

//线性表的合并（合并后没有排序）
void Union(SqList *& La, SqList * Lb) {
	int La_len = ListLength(La);
	int Lb_len = ListLength(Lb);
	int i = 0;
	int e = 0;
	for (i = 1; i <= Lb_len; i++) {
		GetElem(Lb, i, e);
		if (!LocateElem(La, e)) ListInsert(La, ++La_len, e);
	}
}
//时间复杂度O(ListLength(La)*ListLength(Lb))

//有序表的合并
void MergeList_Sq(SqList *La, SqList *Lb, SqList*& Lc) {
	ElemType* pa = La->data;
	ElemType* pb = Lb->data;
	Lc = new SqList;
	Lc->length = La->length + Lb->length;
	Lc->data = new ElemType[Lc->length];
	ElemType* pc = Lc->data;
	ElemType* pa_last = La->data + La->length - 1;
	ElemType* pb_last = Lb->data + Lb->length - 1;
	while (pa <= pa_last && pb <= pb_last) {
		if (*pa < *pb) *pc++ = *pa++;
		else if (*pa == *pb) {
			*pc = *pa;
			pc++;
			pa++;
			pb++;
			Lc->length--;
		}
		else *pc++ = *pb++;
	}
	while (pa <= pa_last) *pc++ = *pa++;
	while (pb <= pb_last) *pc++ = *pb++;
}
//时间复杂度O(ListLength(La)+ListLength(Lb))
//空间复杂度O(ListLength(La)+ListLength(Lb))

int main()
{
	int a[] = { 1,2,3,5,7,9 };
	int b[] = { 2,4,6,8,10 };
	int sza = sizeof(a) / sizeof(a[0]);
	int szb = sizeof(b) / sizeof(b[0]);
	SqList* La;
	SqList* Lb;
	InltList(La);
	InltList(Lb);
	CreateList(La, a, sza);
	CreateList(Lb, b, szb);

	//线性表的合并（合并后没有排序）
	//Union(La,Lb);
	//DispList(La);

	//有序表的合并
	SqList* Lc;
	MergeList_Sq(La, Lb, Lc);
	DispList(Lc);

	return 0;
}