#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
	int key;
	struct node* next;
}node;

node* head, * tail;

void init(void) {
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	head->next = tail;
	tail->next = tail;
}

void push(int n) {
	node* p;
	p = (node*)malloc(sizeof(node));
	p->key = n;
	node* s = head;
	while (s->next != tail) {
		s = s->next;
	}
	s->next = p;
	p->next = tail;
}

int pop(void) {
	node* s = head->next;
	int i = s->key;
	if (s == tail) {
		printf("-1\n");
		return -1;
	}
	printf("%d\n", i);
	head->next = head->next->next;
	free(s);
	return i;
}

int size(void) {
	int cnt = 0;
	node* s = head->next;
	while (s != tail) {
		s = s->next;
		cnt++;
	}
	printf("%d\n", cnt);
	return cnt;
}

int empty(void) {
	int i = (head->next == tail) ? 1 : 0;
	return i;
}

void front(void) {
	if (empty()) printf("-1\n");
	else printf("%d\n", head->next->key);
}

void back(void) {
	if (empty()) printf("-1\n");
	else {
		node* s = head;
		while (s->next != tail) {
			s = s->next;
		}
		printf("%d\n", s->key);
	}
}

int main(void) {

	int n, k;
	scanf("%d", &n);

	init();

	for (int i = 0; i < n; i++) {
		char s[6];
		scanf("%s", s);
		if (strcmp(s, "push") == 0) {
			scanf("%d", &k);
			push(k);
		}
		else if (strcmp(s, "pop") == 0) pop();
		else if (strcmp(s, "size")==0) size();
		else if (strcmp(s, "empty")==0) printf("%d\n",empty());
		else if (strcmp(s, "front")==0) front();
		else if (strcmp(s, "back")==0) back();
	}

	return 0;
}