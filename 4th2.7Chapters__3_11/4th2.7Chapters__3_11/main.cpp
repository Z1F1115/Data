#include "LinkNode.h"

void MergeList_L(LinkNode*& La, LinkNode*& Lb, LinkNode*& Lc) {
	LinkNode* pa, * pb, * pc;
	pa = La->next;
	pb = Lb->next;
	pc = Lc = La;
	while (pa &&pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	delete Lb;
}
//时间复杂度O(ListLength(La)+ListLength(Lb))
//空间复杂度O(1)

int main() {
	int a[] = { 1,2,3,5,7,9 };
	int b[] = { 2,4,6,8,10 };
	int sza = sizeof(a) / sizeof(a[0]);
	int szb = sizeof(b) / sizeof(b[0]);
	LinkNode* La;
	LinkNode* Lb;
	InitList(La);
	InitList(Lb);	

	CreateListR(La, a, sza);
	CreateListR(Lb, b, szb);

	LinkNode* Lc;
	InitList(Lc);
	MergeList_L(La, Lb, Lc);
	DispList(Lc);

	return 0;
}