#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char ch;
	struct node* prev;
	struct node* next;
}node;

node* head, * tail, * s;

void init(void) {
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	head->ch = 'h';
	tail->ch = 't';
	head->prev = head;
	head->next = tail;
	tail->prev = head;
	tail->next = tail;
	s = head;
}

void move(char c) {
	if (c == '<')
		if (s != head)
			s = s->prev;
	if (c == '>')
		if (s != tail->prev)
			s = s->next;
}

void insert(char c) {
	node* p = (node*)malloc(sizeof(node));
	p->ch = c;

	p->next = s->next;
	s->next->prev = p;
	s->next = p;
	p->prev = s;

	s = s->next;
}

void delete(void) {
	if (s != head) {
		node* d = s;
		s = s->prev;
		s->next = d->next;
		s->next->prev = s;
		free(d);
	}
}

void print(void) {
	node* p = head->next;
	while (p != tail) {
		printf("%c", p->ch);
		p = p->next;
	}
	printf("\n");
}

void delete_all(void) {
	if (head->next != tail) {
		node* d = head->next;
		while (d != tail) {
			node* t = d;
			d = d->next;
			free(t);
		}
		head->prev = head;
		head->next = tail;
		tail->prev = head;
		tail->next = tail;
		s = head;
	}
}

int main(void) {

	int t;
	scanf("%d\n", &t);
	char c;
	init();

	for (int i = 0; i < t; i++) {
		while (1) {
			c = getchar();
			if (c == '\n') break;
			if (c == '<' || c == '>') move(c);
			else if (c == '-') delete();
			else insert(c);
		}
		print();
		delete_all();
	}
    free(head);
    free(tail);
	return 0;
}