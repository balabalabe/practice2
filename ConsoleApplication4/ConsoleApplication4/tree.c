//#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct BiTNode
//{
//	char data;
//	struct BiTNode *lchild, *rchild;
//}BiTNode, *BiTree;
//void PreOrderTraverse(BiTree T)//���������������
//{
//	if (T == NULL)
//		return;
//	printf("%c ", T->data);
//	PreOrderTraverse(T->lchild);
//	PreOrderTraverse(T->rchild);
//}
//void InOrderTraverse(BiTree T)//���������������
//{
//	if (T == NULL)
//		return;
//	InOrderTraverse(T->lchild);
//	printf("%c ", T->data);
//	InOrderTraverse(T->rchild);
//}
//void PostOrderTraverse(BiTree T)//�������
//{
//	if (T == NULL)
//		return;
//	PostOrderTraverse(T->lchild);
//	PostOrderTraverse(T->rchild);
//	printf("%c ", T->data);
//}
//void CreateBiTree(BiTree *T)
//{
//	char ch;
//	scanf("%c", &ch);
//	if (ch == '#')
//		*T = NULL;
//	else
//	{
//		*T = (BiTree)malloc(sizeof(BiTNode));
//		if (!*T)
//			exit(-1);
//		(*T)->data = ch;
//		CreateBiTree(&(*T)->lchild);
//		CreateBiTree(&(*T)->rchild);
//	}
//}
//int main()
//{
//	BiTree T;
//	CreateBiTree(&T);
//	PreOrderTraverse(T);
//	InOrderTraverse(T);
//	PostOrderTraverse(T);
//	return 0;
//}