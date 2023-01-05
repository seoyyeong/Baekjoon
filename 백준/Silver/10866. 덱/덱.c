#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
	int key;
	struct node* next;
	struct node* prev;
}node;

node* head, *tail;

void init() {
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	head->prev = head;
	head->next = tail;
	tail->prev = head;
	tail->next = tail;
}

void push_front(int n) {
	node* p, * s;
	s = head->next;
	p = (node*)malloc(sizeof(node));
	p->key = n;

	p->next = s;
	s->prev = p;
	head->next = p;
	p->prev = head;
}

void push_back(int n) {
	node* p, * s;
	s = tail->prev;
	p = (node*)malloc(sizeof(node));
	p->key = n;

	p->prev = s;
	s->next = p;
	p->next = tail;
	tail->prev = p;
}

int size(void) {
	int cnt = 0;
	if (head->next != tail)
	{
		node* s = head;
		while (s->next != tail) {
			s = s->next;
			cnt++;
		}
	}

	return cnt;
}

int empty(void) {
	return head->next == tail;
}

int pop_front(void) {
	int i = -1;
	if (!empty()) {
		node* t = head->next;
		i = t->key;
		head->next = t->next;
		t->next->prev = head;
		free(t);
	}
	return i;
}

int pop_back(void) {
	int i = -1;
	if (!empty()) {
		node* t = tail->prev;
		i = t->key;
		t->prev->next = tail;
		tail->prev = t->prev;
		free(t);
	}
	return i;
}

int front(void) {
	int i = -1;
	if (!empty()) i = head->next->key;
	return i;
}

int back(void) {
	int i = -1;
	if (!empty()) i = tail->prev->key;
	return i;
}

int main(void) {

	int n, k;
	scanf("%d", &n);

	init();

	for (int i = 0; i < n; i++) {
		char s[11];
		scanf("%s", s);
		if (strcmp(s, "push_front") == 0) {
			scanf("%d", &k);
			push_front(k);
		}
		else if (strcmp(s, "push_back") == 0) {
			scanf("%d", &k);
			push_back(k);
		}
		else if (strcmp(s, "pop_front") == 0) printf("%d\n",pop_front());
		else if (strcmp(s, "pop_back") == 0) printf("%d\n", pop_back());
		else if (strcmp(s, "size")==0) printf("%d\n", size());
		else if (strcmp(s, "empty")==0) printf("%d\n",empty());
		else if (strcmp(s, "front")==0) printf("%d\n", front());
		else if (strcmp(s, "back")==0) printf("%d\n", back());
	}

	return 0;
}