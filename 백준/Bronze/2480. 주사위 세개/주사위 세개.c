#include <stdio.h>


int main(void) {

    int i, j, k, sum;
    scanf("%d%d%d", &i, &j, &k);

    if (i == j && j == k) {
        sum = 10000 + i * 1000;
    }
    else if (i == j && i != k) {
        sum = 1000 + i * 100;
    }
    else if (j == k && i != j) {
        sum = 1000 + j * 100;
    }
    else if (i == k && j != i) {
        sum = 1000 + k * 100;
    }
    else {
        int max = i;
        if (max < j) {
            max = j;
        }
        if (max < k) {
            max = k;
        }
        sum = max * 100;
    }

    printf("%d", sum);
    return 0;

}