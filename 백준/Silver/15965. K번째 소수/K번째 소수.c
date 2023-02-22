#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10000000

int* arr;

int isprime(int a) {
    if (a == 1) return 2;
    else if (a == 2) return 3;
    int cnt = 2;
    for (int i = 2; i < sqrt(MAX); i++) {
        int t = i * 2;
        while (t < MAX) {
            if (arr[t] == 0) 
                arr[t] = 1;
            t += i;
        }
    }
    for (int i = 5; i < MAX; i++) {
        if (arr[i] == 0) cnt++;
        if (cnt == a) return i;
    }
}

int main(void) {
    int k;
    scanf("%d", &k);
    arr = (int*)calloc(MAX, sizeof(int));
    printf("%d",isprime(k));
    free(arr);
    return 0;
}
