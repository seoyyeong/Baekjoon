#include <stdio.h>


int find_room(int h, int w, int n) {

    int a = 0;
    for (int i = 1; i <= w; i++) {
        for (int j = 100; j <= h * 100; j += 100) {
            if ((n - 1) == a) return j+i;
            a++;
        }
    }

}


int main(void) {

    int t, h, w, n;
    
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d %d %d", &h, &w, &n);
        printf("%d\n", find_room(h, w, n));
    }

    return 0;
}