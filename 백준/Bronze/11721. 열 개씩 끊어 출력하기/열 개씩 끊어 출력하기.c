#include <stdio.h>

int main(void) {

    char c=' ';
    int i = 0;
    while (c != '\n') {
        if (i == 10) {
            printf("\n");
            i = 0;
        }

        printf("%c", c = getchar());
        i++;
    }

    return 0;
}