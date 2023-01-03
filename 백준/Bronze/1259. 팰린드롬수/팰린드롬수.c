#include <stdio.h>
#include <string.h>

void rvs(char a[],char b[]) {
    
    for (int i = 0; i < strlen(a); i++) {
        b[i] = *(a + strlen(a) - i - 1);
    }
    b[strlen(a)] = '\0';
}

int main(void) {
    
    while (1) {
        char arr[6], arr_rvs[6];
        scanf("%s", arr);
        if (arr[0] == '0') break;
        rvs(arr, arr_rvs);

        if (strcmp(arr, arr_rvs) == 0) printf("%s", "yes\n");
        else printf("no\n");
    }

    return 0;
}