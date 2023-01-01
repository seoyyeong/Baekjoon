#include <stdio.h>
#include <stdlib.h>

int* arr;

void init_room(int h, int w) {

    arr = (int*)malloc(sizeof(int) * (h * w));
    int a = 0;
    for (int i = 1; i <= w; i++) {
        for (int j = 100; j <= h * 100; j += 100) {
            arr[a] = j + i;
            a++;
        }
    }

}


int main(void) {

    int t, h, w, n;
    
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d %d %d", &h, &w, &n);
        init_room(h, w);
        printf("%d\n", arr[n-1]);
    }

    return 0;
}