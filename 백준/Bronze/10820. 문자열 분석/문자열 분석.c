#include <stdio.h>
#include <string.h>

int main(void) {

    char c;

    while(1) {
        int lower = 0, upper = 0, num = 0, space = 0;
        while ((c = getchar()) != '\n') {
            if (c >= 'a' && c <= 'z') lower++;
            else if (c >= 'A' && c <= 'Z') upper++;
            else if (c >= '0' && c <= '9') num++;
            else if (c == ' ') space++;
            else if (c == EOF) return 0;
        }
        printf("%d %d %d %d\n", lower, upper, num, space);
    }

}