#include <stdio.h>

int main(void) {
    int n;
    double score[1000];
    double total = 0;
    double max = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%lf", &score[i]);
        if (score[i] > max) {
            max = score[i];
        }
    }
    for (int i = 0; i < n; i++) {
        score[i] = score[i] / max * 100;
        total += score[i];
    }
    printf("%lf", total / n);
    return 0;
}