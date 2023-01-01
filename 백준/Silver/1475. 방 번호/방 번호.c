#include <stdio.h>

int main(void) {

    char c;
    int arr[10] = { 0 }, max = 0;

    while (1) {
        c = getchar();
        if (c =='\n') break;
        arr[c - '0']++;
    }

    arr[6] = (arr[6] + arr[9]) % 2 == 0 ? (arr[6] + arr[9])/2 : (arr[6] + arr[9]) / 2 + 1;
    arr[9] = arr[6];

    for (int i = 0; i < 10; i++) {
        if (max < arr[i]) max = arr[i];
    }

    printf("%d", max);

    return 0;
}