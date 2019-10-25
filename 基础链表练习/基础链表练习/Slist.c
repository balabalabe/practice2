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
	//cur!=NULLѭ���ߵ����һ�����(NULL)
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

    //(ͷ��)����һ���½ڵ�node,��ʹnode��nextָ��ԭ���ĵ�һ�����,fristָ��node
	SListNode *node = BuySListNode(data);
	node->next = list->first;
	list->first = node;
}

void SListPopFront(SList *list)
{
	assert(list);	// û������
	assert(list->first != NULL);	// ���������������ǿյ�

	//(ͷɾ)������һ����ʱ��������ԭ����ͷ���,Ȼ��ı�ͷ����ָ��,ʹ��ָ����һ��,����ͷ�ԭ����ͷ���
	//***1.���������ʱ����ֱ�Ӹı���ָ��Ļ��ͻᵼ��ԭ����ͷ�����Ϊû��ָ�������޷��ͷ�***
	//***2.������ͷ��ٸı�ָ��Ļ��ᵼ�º�����㶪ʧ,�Ҳ�����***
	SListNode *old_first = list->first;
	list->first = list->first->next;
	free(old_first);
}

void SListPushBack(SList *list, SLDataType data)
{
	assert(list != NULL);

	if (list->first == NULL) {
		// ����Ϊ��
		SListPushFront(list, data);
		return;
	}

	// �������Ѿ��н������
	// �����һ�����
	SListNode *lastone = list->first;
	//***�����lastoneд�������Ŀ�����ӳ���������,���д��forѭ���еĻ�����ѭ������Զ�����***
	for (; lastone->next != NULL; lastone = lastone->next) {
	}
	// lastone �������һ���ǿս��

	// ����ռ�
	SListNode *node = BuySListNode(data);
	lastone->next = node;
	//(β��)������һ�����nodeȻ�������nextָ���,Ȼ��ʹԭ�������е����һ�����ָ��node
}

void SListPopBack(SList *list)
{
	assert(list != NULL);
	assert(list->first != NULL);	// 0 �����ʱ

	if (list->first->next == NULL) {
		// 1 �����ʱ��ͷɾ
		SListPopFront(list);
		return;
	}

	// ͨ����� >= 2 ��
	SListNode *cur;
	//ѭ��cur->next->next�����ҵ�����ĵ����ڶ����ǿս��
	for (cur = list->first; cur->next->next != NULL; cur = cur->next) {
	}
	// cur ���ǵ����ڶ����ǿս��
	free(cur->next);
	cur->next = NULL;
	//***ע��,����Ҫ���ͷ�����cur��nextָ��NULL,�����ָ����ͷŵĻ����Ҳ���cur����һ�����***
}

SListNode * SListFind(SList *list, SLDataType data)
{
	for (SListNode *cur = list->first; cur != NULL; cur = cur->next) {
		if (cur->data == data) {
			return cur;
		}
	}

	// û�ҵ�
	return NULL;
}

void SListInsertAfter(SListNode *pos, SLDataType data)
{
	//��pos�������һ�����
	SListNode *node = BuySListNode(data);
	node->next = pos->next;
	pos->next = node;
}

void SListEraseAfter(SListNode *pos)
{
	//ɾ��pos�����һ�����
	SListNode *next = pos->next->next;
	free(pos->next);
	pos->next = next;
}

void SListRemove(SList *list, SLDataType data)
{
	// �ص����ҵ� data �������ǰһ�����
	// previous	prev

	SListNode *prev = NULL;
	SListNode *cur = list->first;

	while (cur != NULL && cur->data != data) {
		prev = cur;
		cur = cur->next;
	}

	// cur == NULL ��ʾû�ҵ�
	// cur != NULL && prev != NULL
	// cur ����Ҫɾ�Ľ�㣬ͬʱ prev ����Ҫɾ��ǰһ�����
	// cur != NULL && prev == NULL ͷɾ
	if (cur == NULL) {
		return;
	}

	if (prev == NULL) {
		SListPopFront(list);
		return;
	}

	//***����Ҫ�������õ���ʱ������������ֿ���,��Ϊprev��next��Ȼָ����cur��next,����
	//cur��ָ�򲻱�,��Ȼ��ָ��ԭ���,���Բ���Ҫ��ʱ��������ԭ�����ڴ�Ҳ�ܰ�cur�Ľ���ͷŵ�***
	prev->next = cur->next;
	free(cur);
	//�ٸ�����,frist->A->B->C->D->NULL
	//prevָ��A,curָ��B,��Ȼ������prev��nextֱ��ָ����C(A->C���߼��Ͽ���B�Ѿ���ʧ�˲����ⲻҪ��)
	//��ΪҪ�ͷŵ��ڴ���cur��,��cur����ָ��B
}

void SListPrint(SList *list)
{
	for (SListNode *cur = list->first; cur != NULL; cur = cur->next) {
		printf("%d --> ", cur->data);
	}
	printf("NULL\n");
}

SListNode* SListFindBackNumber(SListNode *head,unsigned int k){
	//����ָ��������ҵ�����K�����
	SListNode *fast = head;
	SListNode *slow = head;
	while (head != NULL && k != 0){
		fast = fast->next;
		k--;
	}
	//TODO:��Ҫ�����������,��ͷ���Ϊ��ʱ,k������ʱ
	while (fast->next != NULL){
		fast = fast->next;
		slow = slow->next;
	}
	return slow->data;
}

void SListDeleDuplication(SListNode* head){
	//������������ɾ����ͬ�Ľ��
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
	//����������� 1 2 3 3 4 4 5
	//1 2 3 3 4 4
	//2 2 2 2 2 2
	//2 2 2 2 2 3

}