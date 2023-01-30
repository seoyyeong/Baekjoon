#include <stdio.h>
#define MAX 1001

int queue[MAX];
int front, rear;
int n;

void init(void) {
	front = rear = 0;
}

int deque(void) {
	int t = queue[front];
	queue[front] = 0;
	if (t > 0) {
		while (t > 0) {
			front = ++front % MAX;
			if (queue[front] != 0)
				t--;
		}
	}
	else {
		while (t < 0) {
			if (front > 0)
				front = --front % MAX;
			else front = n - 1 + front;
			if (queue[front] != 0)
				t++;
		}
	}
	return front+1;
}


int main(void) {
	scanf("%d", &n);
	init();
	for (int i = 0; i < n; i++)
		scanf("%d", &queue[rear++]);

	printf("%d ", front + 1);

	for (int j = 0; j < n - 1; j++) 
		printf("%d ", deque());

	return 0;
}