#include <stdio.h>

int main(void) {

    int arr[8];
    for (int i = 0; i < 8; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i < 8; i++) {
        if (arr[i] - arr[i - 1] != 1 && arr[i-1]-arr[i]!=1) {
            printf("mixed");
            return 0;
        }
    }
    
    printf("%s", (arr[0] == 1) ? "ascending" : "descending");

    return 0;
}