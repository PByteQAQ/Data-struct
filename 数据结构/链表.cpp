#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct node {
	ElemType data;
	struct node* next;
}Node;

//初化链表
Node* initList()
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	return head;
}
//头插法
Node* inserthead(Node* l, ElemType e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = l->next;
	l->next = p;
	return p;

}
//找到尾节点
Node* gettail(Node* l) {
	Node* p = l;
	while (p->next != NULL) {
		p = p->next;
	}
	return p;
}
//尾插法
Node* inserttail(Node* tail, ElemType e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	tail->next = p;
	p->next = NULL;
	return p;


}
//指定位置插入
int insertnode(Node* l, int pos, ElemType e) {
	Node* p = l;
	int i = 0;
	while (i < pos - 1) {
		p = p->next;
		i++;
		if (p == NULL) {
			return 0;
		}
	}Node* q = (Node*)malloc(sizeof(Node));
	q->data = e;
	q->next = p->next;
	p->next = q;
	return 1;
}
//删除节点
int  deletenode(Node* l, int pos) {
	Node* p = l;
	int i = 0;
	while (i < pos - 1) {
		p = p->next;
		i++;
		if (p == NULL) {
			return 0;
		}
		if (p->next == NULL) {
			printf("要删除的位置错误");
			return 0;
		}
	}
	Node* q = p->next;
	p->next = q->next;
	free(q);
	return 1;
}
//获取链表长度
int listlength(Node* l) {
	int len = 0;
	Node* p = l;
	while (p != NULL) {
		p = p->next;
		len++;
	}
	return len;
}