#include "SqList.h"

//���Ա�ĺϲ����ϲ���û������
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
//ʱ�临�Ӷ�O(ListLength(La)*ListLength(Lb))

//�����ĺϲ�
void MergeList_Sq(SqList *La, SqList *Lb, SqList*& Lc) {
	ElemType* pa = La->data;
	ElemType* pb = Lb->data;
	Lc->length = La->length + Lb->length;
	Lc->data = new ElemType[Lc->length];
	ElemType* pc = Lc->data;
	ElemType* pa_last = La->data + La->length - 1;
	ElemType* pb_last = Lb->data + Lb->length - 1;
	while (pa <= pa_last && pb <= pb_last) {
		if (*pa <= *pb) *pc++ = *pa++;
		else *pc++ = *pb++;
	}
	while (pa <= pa_last) *pc++ = *pa++;
	while (pb <= pb_last) *pc++ = *pb++;
}
//ʱ�临�Ӷ�O(ListLength(La)+ListLength(Lb))
//�ռ临�Ӷ�O(ListLength(La)+ListLength(Lb))

int main()
{
	int a[] = { 1,2,3,5,7,9 };
	int b[] = { 2,4,6,8,10 };
	int sza = sizeof(a) / sizeof(a[0]);
	int szb = sizeof(b) / sizeof(b[0]);
	SqList* La;
	SqList* Lb;
	CreateList(La, a, sza);
	CreateList(Lb, b, szb);

	//���Ա�ĺϲ����ϲ���û������
	Union(La,Lb);

	//�����ĺϲ�
	SqList* Lc;
	MergeList_Sq(La, Lb, Lc);

	DispList(Lc);

	return 0;
}