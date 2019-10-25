#pragma once

// 单向 + 不循环 + 不带头

typedef int SLDataType;

typedef struct SListNode {
	SLDataType	data;
	struct SListNode *next;
}	SListNode;

typedef struct SList {
	struct SListNode *first;
}	SList;

// 初始化/销毁
void SListInit(SList *list);
void SListDestroy(SList *list);

// 增 删 查 改
// 头插
void SListPushFront(SList *list, SLDataType data);

// 头删
void SListPopFront(SList *list);

// 尾插
void SListPushBack(SList *list, SLDataType data);

// 尾删
void SListPopBack(SList *list);

// 查找
// NULL 表示没找到
SListNode * SListFind(SList *list, SLDataType data);

// 在 pos 这个结点后面插入新结点
void SListInsertAfter(SListNode *pos, SLDataType data);

// pos 不是最后一个结点
// 删除 pos 这个结点后面的结点
void SListEraseAfter(SListNode *pos);

// 删除第一个遇到的 data 结点
void SListRemove(SList *list, SLDataType data);

// 打印
void SListPrint(SList *list);

// 找到倒数第k个结点
SListNode* SListFindBackNumber(SListNode *head, unsigned int k);