#include <stdio.h>
#include <string.h>

typedef struct data {
    char name[16];
    int d, m, y;
}data;

int main(void) {

    int n;
    scanf("%d", &n);
    data max, min;
    max.y = 2011, min.y = 1989;

    for (int i = 0; i < n; i++) {
        data t;
        scanf("%s %d %d %d", t.name, &t.d, &t.m, &t.y);
        if (t.y < max.y) {
            memcpy(&max, &t, sizeof(data));
        }
        else if (t.y == max.y) {
            if (t.m < max.m) {
                memcpy(&max, &t, sizeof(data));
            }
            else if (t.m == max.m)
                if(t.d < max.d) {
                    memcpy(&max, &t, sizeof(data));
                }
        }
        if (t.y > min.y) {
            memcpy(&min, &t, sizeof(data));
        }
        else if (t.y == min.y) {
            if (t.m > min.m) {
                memcpy(&min, &t, sizeof(data));
            }
            else if (t.m == min.m)
                if (t.d > min.d) {
                    memcpy(&min, &t, sizeof(data));
                }
        }
    }

    printf("%s\n%s", min.name, max.name);
    return 0;
}
