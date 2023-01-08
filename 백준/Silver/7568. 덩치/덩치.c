#include <stdio.h>
#include <stdlib.h>

typedef struct member {
    int x;
    int y;
}member;

int main(void) {

    int n, cnt;
    scanf("%d", &n);
    member* arr = (member*)malloc(sizeof(member) * n);
    
    for (int i = 0; i < n; i++)
        scanf("%d%d", &arr[i].x, &arr[i].y);

    for (int i = 0; i < n; i++) {
        cnt = 1;
        for (int j = 0; j < n; j++) {
            if (arr[i].x < arr[j].x && arr[i].y < arr[j].y)
                cnt++;
        }
        printf("%d ", cnt);
    }

    free(arr);
    return 0;
}