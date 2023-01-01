#include <stdio.h>

int main(void) {

    char c;
    int cnt=0, arr[10];

    while (1) {
        c = getchar();
        if (c =='\n') break;
        arr[cnt] = c - '0';
        cnt++;
    }

    for (int i = 0; i < cnt; i++) {
        int t = arr[i];
        int j = i;
        while (arr[j - 1] < t && j>0) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = t;


    }

    for (int i = 0; i < cnt; i++) {
        printf("%d", arr[i]);
    }

    return 0;
}