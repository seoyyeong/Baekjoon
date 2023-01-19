#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2000001

int queue[MAX];
int head, rear;

void init(void) {
	head = rear = 0;
}

void push(int a) {
	queue[rear++] = a;
}

int empty(void) {
	if (head == rear) return 1;
	else return 0;
}

int pop(void) {
	if (empty() == 0) {
		int i = queue[head++];
		return i;
	}
	else return -1;
}

int size(void) {
	return rear - head;
}


int front(void) {
	if (empty() == 0)
		return queue[head];
	else return -1;
}

int back(void) {
	if (empty() == 0)
		return queue[rear-1];
	else return -1;
}

int main(void) {
	int n;
	scanf("%d", &n);
	init();

	for (int i = 0; i < n; i++) {
		int t;
		char s[7];
		scanf("%s", s);
		if (strcmp(s, "push") == 0) {
			scanf("%d", &t);
			push(t);
		}
		else if (strcmp(s, "pop") == 0)
			printf("%d\n", pop());
		else if (strcmp(s, "size") == 0)
			printf("%d\n", size());
		else if (strcmp(s, "empty") == 0)
			printf("%d\n", empty());
		else if (strcmp(s, "front") == 0)
			printf("%d\n", front());
		else
			printf("%d\n", back());
	}

	return 0;
}
