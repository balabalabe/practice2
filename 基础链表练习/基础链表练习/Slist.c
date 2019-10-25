#include "SList.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

void SListInit(SList *list)
{
	assert(list != NULL);
	list->first = NULL;
}


void SListDestroy(SList *list)
{
	SListNode *next;
	//cur!=NULL循环走到最后一个结点(NULL)
	for (SListNode *cur = list->first; cur != NULL; cur = next) {
		next = cur->next;
		free(cur);
	}
	
	list->first = NULL;
}

SListNode * BuySListNode(SLDataType data)
{
	SListNode *node = (SListNode *)malloc(sizeof(SListNode));
	assert(node != NULL);
	node->data = data;
	node->next = NULL;

	return node;
}

void SListPushFront(SList *list, SLDataType data)
{
	assert(list != NULL);

    //(头插)创建一个新节点node,并使node的next指向原来的第一个结点,frist指向node
	SListNode *node = BuySListNode(data);
	node->next = list->first;
	list->first = node;
}

void SListPopFront(SList *list)
{
	assert(list);	// 没有链表
	assert(list->first != NULL);	// 有链表，但是链表是空的

	//(头删)首先用一个临时变量保存原来的头结点,然后改变头结点的指向,使其指向下一个,最后释放原来的头结点
	//***1.如果不用临时变量直接改变其指向的话就会导致原来的头结点因为没有指向所以无法释放***
	//***2.如果先释放再改变指向的话会导致后续结点丢失,找不到了***
	SListNode *old_first = list->first;
	list->first = list->first->next;
	free(old_first);
}

void SListPushBack(SList *list, SLDataType data)
{
	assert(list != NULL);

	if (list->first == NULL) {
		// 链表为空
		SListPushFront(list, data);
		return;
	}

	// 链表中已经有结点的情况
	// 找最后一个结点
	SListNode *lastone = list->first;
	//***这里把lastone写在外面的目的是延长其作用域,如果写在for循环中的话出了循环后会自动销毁***
	for (; lastone->next != NULL; lastone = lastone->next) {
	}
	// lastone 就是最后一个非空结点

	// 申请空间
	SListNode *node = BuySListNode(data);
	lastone->next = node;
	//(尾插)先申请一个结点node然后令结点的next指向空,然后使原来链表中的最后一个结点指向node
}

void SListPopBack(SList *list)
{
	assert(list != NULL);
	assert(list->first != NULL);	// 0 个结点时

	if (list->first->next == NULL) {
		// 1 个结点时用头删
		SListPopFront(list);
		return;
	}

	// 通常情况 >= 2 个
	SListNode *cur;
	//循环cur->next->next用于找到链表的倒数第二个非空结点
	for (cur = list->first; cur->next->next != NULL; cur = cur->next) {
	}
	// cur 就是倒数第二个非空结点
	free(cur->next);
	cur->next = NULL;
	//***注意,这里要先释放再令cur的next指向NULL,如果先指向后释放的话会找不到cur的下一个结点***
}

SListNode * SListFind(SList *list, SLDataType data)
{
	for (SListNode *cur = list->first; cur != NULL; cur = cur->next) {
		if (cur->data == data) {
			return cur;
		}
	}

	// 没找到
	return NULL;
}

void SListInsertAfter(SListNode *pos, SLDataType data)
{
	//在pos后面插入一个结点
	SListNode *node = BuySListNode(data);
	node->next = pos->next;
	pos->next = node;
}

void SListEraseAfter(SListNode *pos)
{
	//删除pos后面的一个结点
	SListNode *next = pos->next->next;
	free(pos->next);
	pos->next = next;
}

void SListRemove(SList *list, SLDataType data)
{
	// 重点是找到 data 这个结点的前一个结点
	// previous	prev

	SListNode *prev = NULL;
	SListNode *cur = list->first;

	while (cur != NULL && cur->data != data) {
		prev = cur;
		cur = cur->next;
	}

	// cur == NULL 表示没找到
	// cur != NULL && prev != NULL
	// cur 就是要删的结点，同时 prev 就是要删的前一个结点
	// cur != NULL && prev == NULL 头删
	if (cur == NULL) {
		return;
	}

	if (prev == NULL) {
		SListPopFront(list);
		return;
	}

	//***这里要和上面用到临时变量的情况区分开来,因为prev的next虽然指向了cur的next,但是
	//cur的指向不变,仍然是指向原结点,所以不需要临时变量保存原来的内存也能把cur的结点释放掉***
	prev->next = cur->next;
	free(cur);
	//举个例子,frist->A->B->C->D->NULL
	//prev指向A,cur指向B,虽然我们令prev的next直接指向了C(A->C从逻辑上看似B已经丢失了不过这不要紧)
	//因为要释放的内存是cur的,而cur还是指向B
}

void SListPrint(SList *list)
{
	for (SListNode *cur = list->first; cur != NULL; cur = cur->next) {
		printf("%d --> ", cur->data);
	}
	printf("NULL\n");
}

SListNode* SListFindBackNumber(SListNode *head,unsigned int k){
	//快慢指针遍历法找倒数第K个结点
	SListNode *fast = head;
	SListNode *slow = head;
	while (head != NULL && k != 0){
		fast = fast->next;
		k--;
	}
	//TODO:还要考虑特殊情况,当头结点为空时,k比链表长时
	while (fast->next != NULL){
		fast = fast->next;
		slow = slow->next;
	}
	return slow->data;
}

void SListDeleDuplication(SListNode* head){
	//在有序链表中删除相同的结点
	if (head == NULL){
		return NULL;
	}
	SListNode* p0 = NULL;
	SListNode* p1 = head;
	SListNode* p2 = head->next;


	/*SListNode *deleteDuplication(SList *plist)
	{
		if (plist->head == NULL)
			return NULL;

		SListNode *p0 = NULL;
		SListNode *p1 = plist->head;
		SListNode *p2 = plist->head->next;

		while (p2 != NULL)
		{
			if (p1->data != p2->data)
			{
				p0 = p1; p1 = p2; p2 = p2->next;
			}
			else
			{
				while (p2 != NULL && p2->data == p1->data)
				{
					p2 = p2->next;
				}
				if (p2 == NULL)
				{
					if (p0 != NULL)
						p0->next = p2;
					else
						return NULL;
					break;
				}

				if (p0 != NULL)
				{
					p0->next = p2;
				}
				else
				{
					plist->head = p2;
				}

				p1 = p2;
				p2 = p2->next;
			}

		}
	}*/
	//四种特殊情况 1 2 3 3 4 4 5
	//1 2 3 3 4 4
	//2 2 2 2 2 2
	//2 2 2 2 2 3

}