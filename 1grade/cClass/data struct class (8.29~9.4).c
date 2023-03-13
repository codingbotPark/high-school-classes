// 8.29~9.4
// 링크드 리스트에서 node는 [정수|포인터] 의 구조로 이루어져있다
// 
// 이 링크드 리스트와 배열의 장단점에는
// 
// 배열은 인덱스가 있고 실제 메모리에도 바로 옆에 위치하고 있다	  
// 때문에 인덱스를 통해 바로 위치를 찾아갈 수 있다
// 
// 링크드 리스트는 주소가 있기 때문에 삭제를 할 때는 주소만 바꿔주면 된다
// 
// 즉 배열은 접근할 때 시간복잡도가 좋다
// 링크드 리스트는 값을 변경할 때 시간복잡도가 좋다
// 
// 링크드 리스트에서 head는 링크드 리스트의 맨 앞을 가르키는데 
// 이 head가 없다면 변경되었을 때 다른 과정이 필요하기 때문에 필요하다
// 
// -> (간접참조)는 포인터 구조체 멤버변수에 접근하기 위해 사용된다
// 이 간접참조를 사용하지 않느다면 (*가르키는 변수).가르켜진변수 를 써야한다
// 
// 배열과 링크드리스트의 장단점
// 
// 배열
// 
// 장점 
// 항목 접근이 빠르고 일정하다
// 
// 단점
// 크기가 고정돼있다(배열의 크기를 지정해야함)
// 메모리 한 덩이를 차지해서 배열의 크기가 클 때 전체를 위한 메모리를 할당받지 못하는 경우가 있다
// 삽입이 복잡하다(중간에 값 삽입, 삭제 등)
// 
// 링크드리스트
// 
// 장점
// 삽입이 간단하다(포인터 값만 변경하면 된다)
// 
// 단점
// 항목 접근이 오래 걸린다
// 물리적으로 인접한 메모리에 위치하지 않는다
// 참조 포인터를 위한 메모리 공간 낭비
// 
// 
// 
// 구조체를 사용했었는데
// 보안성 문제가 있었다
//
// 이를 클레스를 활용해서 해결했다
// 클래스는 프라이빗영역, 퍼블릭영역 등의 개념이 있다
// 
// 구조체를 가르키려면 구조체 포인터를 사용한다


//8.30
//연결 링크 리스트
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//calloc, malloc 은 동적인 공간 확보

typedef struct NODE ND; 
struct NODE {//연결 리스트의 노드 구조체
	struct NODE* next;	//다음
	int data;
};

int main()
{
	struct NODE* head = malloc(sizeof(struct NODE));	//머리 노드 생성
	//ND* head = malloc(sizeof(ND))

	struct NODE* node1 = malloc(sizeof(struct NODE));
	head->next = node1;
	node1->data = 10;

	struct NODE* node2 = malloc(sizeof (struct NODE));	//두 번째 노드 생성	
	node1->next = node2;	//첫 번째 노드 다음은 두 번째 노드
	node2->data = 20;	//첫 번째 노드에 10저장
		
	node2->next = NULL;	//두 번쨰 노드 다음은 노드가 없음

	struct NODE* curr = head -> next;	//연결 리스트 순회용 포인터에 첫 번째 노드의 주소 저장
	while(curr != NULL)	//포인터가 NULL이 아닐 때 계속 반복
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}

	free(node2);
	free(node1);
	free(head);
}
//테스트
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
//연결리스트.c 파일
#include <stdio.h>
#include <stdlib.h>
#include "연결리스트.h"


void ListInit(List* plist) {
	//리스트 초기화, Dummy Node 생성
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
	//plist->head 더미 노드
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
		//함수포인터 리턴값은 0 또는 1, 
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


//연결리스트.h파일
#ifndef _D_LINKED_LIST_H
#define _D_LINKED_LIST_H
#include <stdio.h>

#define TRUE 1
#define FALSE 0
typedef int LData;//리스트 데이터 L Data
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

//연결리스트정렬메인.c파일
#include <stdio.h>
#include "연결리스트.h"

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

	printf("현재 데이터의 수 : %d \n", LCount(&list));

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