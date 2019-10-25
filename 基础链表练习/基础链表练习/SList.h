#pragma once

// ���� + ��ѭ�� + ����ͷ

typedef int SLDataType;

typedef struct SListNode {
	SLDataType	data;
	struct SListNode *next;
}	SListNode;

typedef struct SList {
	struct SListNode *first;
}	SList;

// ��ʼ��/����
void SListInit(SList *list);
void SListDestroy(SList *list);

// �� ɾ �� ��
// ͷ��
void SListPushFront(SList *list, SLDataType data);

// ͷɾ
void SListPopFront(SList *list);

// β��
void SListPushBack(SList *list, SLDataType data);

// βɾ
void SListPopBack(SList *list);

// ����
// NULL ��ʾû�ҵ�
SListNode * SListFind(SList *list, SLDataType data);

// �� pos �������������½��
void SListInsertAfter(SListNode *pos, SLDataType data);

// pos �������һ�����
// ɾ�� pos ���������Ľ��
void SListEraseAfter(SListNode *pos);

// ɾ����һ�������� data ���
void SListRemove(SList *list, SLDataType data);

// ��ӡ
void SListPrint(SList *list);

// �ҵ�������k�����
SListNode* SListFindBackNumber(SListNode *head, unsigned int k);