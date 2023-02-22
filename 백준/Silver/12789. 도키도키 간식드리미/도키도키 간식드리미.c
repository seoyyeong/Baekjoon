#include <stdio.h>

int main(void) {

    int queue[1000], stack[1000];
    int n, m = 1, head = 0, top = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    while (m <= n) {
        if (queue[head] == m) {
            head++;
            m++;
        }
        else if (stack[top] == m) {
            top--;
            m++;
        }
        else {
            if (head == n) {
                printf("Sad");
                return 0;
            }
            stack[++top] = queue[head++];
        }
            
    }
    printf("Nice");
    return 0;
}