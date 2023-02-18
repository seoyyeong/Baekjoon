#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char ch;
	struct node* prev;
	struct node* next;
}node;

node* head, * tail, *p;

void init(void) {
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	head->prev = head;
	tail->prev = head;
	head->next = tail;
	tail->next = head;
}

void push(char c) {
	node* n = (node*)malloc(sizeof(node));
	n->ch = c;
	p->next->prev = n;
	n->next = p->next;
	p->next = n;
	n->prev = p;
	p = n;
}

void pop(void) {
	node* t = p;
	p->next->prev = p->prev;
	p->prev->next = p->next;
	p = p->prev;
	free(t);
}

void del(void) {
	node* d = head->next;
	while (d != tail) {
		node* t = d;
		d = d->next;
		free(t);
	}
	head->next = tail;
	tail->prev = tail;
}

int main(void) {

	int n, cnt = 0;
	char c;
	scanf("%d ", &n);
	init();
	for (int i = 0;i < n;i++) {
		p = head;
		while (1) {
			c = getchar();
			if (c == '\n') 
				break;

			if (p->ch != c)
				push(c);
			else pop();
		}
		if (head->next == tail) 
			cnt++;
		del();
	}

	printf("%d", cnt);
	free(head);
	free(tail);
	return 0;
}
