#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char key;
	struct node* prev, * next;
}node;

node* head, *tail, *p;

void init(void) {
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	head->prev = head;
	head->next = tail;
	tail->prev = head;
	tail->next = tail;
	p = head;
}

void left(void) {
	if (p != head) {
		p = p->prev;
	}
}

void right(void) {
	if (p != tail->prev) {
		p = p->next;
	}
}

void del(void) {
	if (p!=head) {
		node* t = p;
		p = p->prev;
		p->next = t->next;
		t->next->prev = p;
		free(t);
	}
}

void insert(char c) {
	node* n = (node*)malloc(sizeof(node));
	n->key = c;
	n->prev = p;
	n->next = p->next;
	p->next->prev = n;
	p->next = n;
	p = n;
}

void del_all(void) {
	node* d = head->next;
	while (d != tail) {
		node* t = d;
		d = d->next;
		free(t);
	}
	free(head);
	free(tail);
}

void print(void) {
	node* s = head->next;
	while (s != tail) {
		printf("%c", s->key);
		s = s->next;
	}
}

int main(void) {

	int m;
	char c;
	init();

	while ((c = getchar()) != '\n') 
		insert(c);

	scanf("%d\n", &m);

	for (int i = 0; i < m; i++) {
		scanf("%c", &c);
		if (c == 'P') {
			scanf(" %c", &c);
			insert(c);
			getchar();
		}
		else if (c == 'L') {
			left();
			getchar();
		}
		else if (c == 'D') {
			right();
			getchar();
		}
		else {
			del();
			getchar();
		}
	}
	print();
	del_all();
	return 0;
}