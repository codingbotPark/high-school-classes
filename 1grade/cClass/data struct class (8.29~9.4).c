// 8.29~9.4
// ��ũ�� ����Ʈ���� node�� [����|������] �� ������ �̷�����ִ�
// 
// �� ��ũ�� ����Ʈ�� �迭�� ���������
// 
// �迭�� �ε����� �ְ� ���� �޸𸮿��� �ٷ� ���� ��ġ�ϰ� �ִ�	  
// ������ �ε����� ���� �ٷ� ��ġ�� ã�ư� �� �ִ�
// 
// ��ũ�� ����Ʈ�� �ּҰ� �ֱ� ������ ������ �� ���� �ּҸ� �ٲ��ָ� �ȴ�
// 
// �� �迭�� ������ �� �ð����⵵�� ����
// ��ũ�� ����Ʈ�� ���� ������ �� �ð����⵵�� ����
// 
// ��ũ�� ����Ʈ���� head�� ��ũ�� ����Ʈ�� �� ���� ����Ű�µ� 
// �� head�� ���ٸ� ����Ǿ��� �� �ٸ� ������ �ʿ��ϱ� ������ �ʿ��ϴ�
// 
// -> (��������)�� ������ ����ü ��������� �����ϱ� ���� ���ȴ�
// �� ���������� ������� �ʴ��ٸ� (*����Ű�� ����).������������ �� ����Ѵ�
// 
// �迭�� ��ũ�帮��Ʈ�� �����
// 
// �迭
// 
// ���� 
// �׸� ������ ������ �����ϴ�
// 
// ����
// ũ�Ⱑ �������ִ�(�迭�� ũ�⸦ �����ؾ���)
// �޸� �� ���̸� �����ؼ� �迭�� ũ�Ⱑ Ŭ �� ��ü�� ���� �޸𸮸� �Ҵ���� ���ϴ� ��찡 �ִ�
// ������ �����ϴ�(�߰��� �� ����, ���� ��)
// 
// ��ũ�帮��Ʈ
// 
// ����
// ������ �����ϴ�(������ ���� �����ϸ� �ȴ�)
// 
// ����
// �׸� ������ ���� �ɸ���
// ���������� ������ �޸𸮿� ��ġ���� �ʴ´�
// ���� �����͸� ���� �޸� ���� ����
// 
// 
// 
// ����ü�� ����߾��µ�
// ���ȼ� ������ �־���
//
// �̸� Ŭ������ Ȱ���ؼ� �ذ��ߴ�
// Ŭ������ �����̺�����, �ۺ����� ���� ������ �ִ�
// 
// ����ü�� ����Ű���� ����ü �����͸� ����Ѵ�


//8.30
//���� ��ũ ����Ʈ
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//calloc, malloc �� ������ ���� Ȯ��

typedef struct NODE ND; 
struct NODE {//���� ����Ʈ�� ��� ����ü
	struct NODE* next;	//����
	int data;
};

int main()
{
	struct NODE* head = malloc(sizeof(struct NODE));	//�Ӹ� ��� ����
	//ND* head = malloc(sizeof(ND))

	struct NODE* node1 = malloc(sizeof(struct NODE));
	head->next = node1;
	node1->data = 10;

	struct NODE* node2 = malloc(sizeof (struct NODE));	//�� ��° ��� ����	
	node1->next = node2;	//ù ��° ��� ������ �� ��° ���
	node2->data = 20;	//ù ��° ��忡 10����
		
	node2->next = NULL;	//�� ���� ��� ������ ��尡 ����

	struct NODE* curr = head -> next;	//���� ����Ʈ ��ȸ�� �����Ϳ� ù ��° ����� �ּ� ����
	while(curr != NULL)	//�����Ͱ� NULL�� �ƴ� �� ��� �ݺ�
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}

	free(node2);
	free(node1);
	free(head);
}
//�׽�Ʈ
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE ND;
struct NODE {
	struct NODE* next;
	int data;
};

int main()
{
	struct NODE* head = malloc(sizeof(struct NODE));

	struct NODE* node1 = malloc(sizeof(struct NODE));
	head->next = node1;
	node1->data = 10;

	struct NODE* node2 = malloc(sizeof(struct NODE));
	node1->next = node2;
	node2->data = 20;

	node2->next = NULL;

	struct NODE* curr = head->next;
	while (curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}
	
	free(node2);
	free(node1);
	free(head);
}

//9.2
//���Ḯ��Ʈ.c ����
#include <stdio.h>
#include <stdlib.h>
#include "���Ḯ��Ʈ.h"


void ListInit(List* plist) {
	//����Ʈ �ʱ�ȭ, Dummy Node ����
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}


void FInsert(List* plist, LData data) {
	//Front Insert
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = plist->head->next;
	//plist->head ���� ���
	plist->head->next = newNode;
	(plist->numOfData)++;
}


void SInsert(List* plist, LData data) {
	//predecessor, successor
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* pred = plist->head;
	newNode->data = data;
	while (pred->next != NULL &&
		plist->comp(data, pred->next->data) != 0) {
		//�Լ������� ���ϰ��� 0 �Ǵ� 1, 
		pred = pred->next;
	}
	newNode->next = pred->next;
	pred->next = newNode;
	(plist->numOfData)++;
}


void LInsert(List* plist, LData data) {
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}


int LFirst(List* plist, LData* pdata) {
	if (plist->head->next == NULL)
		return FALSE;
	plist->before = plist->head;
	plist->cur = plist->head->next;


	*pdata = plist->cur->data;
	return TRUE;
}


int LNext(List* plist, LData* pdata) {
	if (plist->cur->next == NULL)
		return FALSE;
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}


LData LRemove(List* plist) {
	Node* rpos = plist->cur;
	LData rdata = rpos->data;


	plist->before->next = plist->cur->next;
	plist->cur = plist->before;


	free(rpos);
	(plist->numOfData)--;
	return rdata;
}


int LCount(List* plist) {
	return plist->numOfData;
}


void SetSortRule(List* plist, int (*comp)(LData d1, LData d2)) {
	plist->comp = comp;
}


//���Ḯ��Ʈ.h����
#ifndef _D_LINKED_LIST_H
#define _D_LINKED_LIST_H
#include <stdio.h>

#define TRUE 1
#define FALSE 0
typedef int LData;//����Ʈ ������ L Data
typedef struct _n {
	LData data;
	struct _n* next;
}Node;

typedef struct _linked {
	Node* head;
	Node* cur;
	Node* before;
	int numOfData;
	int (*comp)(LData d1, LData d2);
}LinkedList;

typedef LinkedList List;
void ListInit(List* plist);
void LInsert(List* plist, LData* pdata);
int LFirst(List* plist, LData* pdata);
LData LRemove(List* plist);
int LCount(List* plist);
void setSortRule(List* plist, \
	int (*comp)(LData d1, LData d2));

//���Ḯ��Ʈ���ĸ���.c����
#include <stdio.h>
#include "���Ḯ��Ʈ.h"

int MySort(int n1, int n2) {
	if (n1 < n2) return 0;
	else return 1;
}

int main(void) {
	List list;
	int data;
	ListInit(&list);
	SetSortRule(&list, MySort);

	LInsert(&list, 1); LInsert(&list, 1);
	LInsert(&list, 2); LInsert(&list, 2);
	LInsert(&list, 3); LInsert(&list, 1);
	LInsert(&list, 7); LInsert(&list, 6);

	printf("���� �������� �� : %d \n", LCount(&list));

	if (LFirst(&list, &data)) {
		printf("%d", data);
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	if (LFirst(&list, &data)) {
		if (data == 2)
		{
			LRemove(&list);
		}
		while (LNext(&list, &data)) {
			if (data == 2)
				LRemove(&list);
		}
	}
}