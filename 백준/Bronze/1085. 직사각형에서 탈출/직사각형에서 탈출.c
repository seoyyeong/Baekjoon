#include <stdio.h>

int main(void) {

    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    
    int w_min = (w - x < x - 0) ? w - x : x - 0;
    int h_min = (h - y < y - 0) ? h - y : y - 0;

    printf("%d", (w_min < h_min) ? w_min : h_min);

    return 0;
}