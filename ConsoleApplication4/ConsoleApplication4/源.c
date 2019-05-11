//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <malloc.h>
//
//typedef struct BTree {
//	char data;
//	struct BTree *lChild;
//	struct BTree *rChild;
//} BinTree;
//
//BinTree *CreateTree(BinTree *p) {
//	char ch;
//	scanf("%c", &ch);
//	if (ch == '#') return NULL;
//	p = (BinTree *)malloc(sizeof(BinTree));
//	p->data = ch;
//	p->lChild = CreateTree(p->lChild);
//	p->rChild = CreateTree(p->rChild);
//	return p;
//}
//
//int SumLeaf(BinTree *T) {
//	int sum = 0, m, n;
//	if (T) {
//		if ((!T->lChild) && (!T->rChild))
//			sum++;
//		m = SumLeaf(T->lChild);
//		n = SumLeaf(T->rChild);
//		sum += m + n;
//	}
//	return sum;
//}
//
//void QianXu(BinTree *T) {
//	if (T) {
//		printf("%c, ", T->data);
//		QianXu(T->lChild);
//		QianXu(T->rChild);
//	}
//}
//
//void ZhongXu(BinTree *T) {
//	if (T) {
//		ZhongXu(T->lChild);
//		printf("%c,", T->data);
//		ZhongXu(T->rChild);
//	}
//}
//
//void HouXu(BinTree *T) {
//	if (T) {
//		HouXu(T->lChild);
//		HouXu(T->rChild);
//		printf("%c,", T->data);
//	}
//}
//
//int Depth(BinTree *T) {
//	int dep = 0, depl, depr;
//	if (!T) dep = 0;
//	else {
//		depl = Depth(T->lChild);
//		depr = Depth(T->rChild);
//		dep = 1 + (depl>depr ? depl : depr);
//	}
//	return dep;
//}
//
//void FreeTree(BinTree *T) {
//	if (T) {
//		FreeTree(T->lChild);
//		FreeTree(T->rChild);
//		free(T);
//	}
//}
//
//int main() {
//	BinTree *Tree = NULL;
//	Tree = CreateTree(Tree);
//	//Ç°Ðò±éÀú
//	printf("QianXu Traversal:");
//	QianXu(Tree);
//	printf("\nZhongXu Traversal:");
//	ZhongXu(Tree);
//	printf("\nHouXu Traversal:");
//	HouXu(Tree);
//
//	printf("\nLeaf's number:%d\n", SumLeaf(Tree));
//	printf("Tree's Depth:%d", Depth(Tree));
//
//	FreeTree(Tree);
//	return 0;
//}
