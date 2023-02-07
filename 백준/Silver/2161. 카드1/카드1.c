#include <stdio.h>
#define MAX 1001

int queue[MAX];
int front, rear;

void init(void) {
    front = rear = 0;
}

void enque(int n) {
    queue[rear] = n;
    rear = ++rear % MAX;
}

int deque(void) {
    int n = queue[front];
    front = ++front % MAX;
    return n;
}

int main(void) {

    int n;
    scanf("%d", &n);

    init();

    for (int i = 1; i <= n; i++)
        enque(i);

    while (front != rear) {
        printf("%d ", deque());
        enque(deque());
    }

    return 0;
}