#include <stdio.h>

int main(void){
    int n = 0;
    char c;

    while (c = getchar() != '\n')
        n++;

    printf("%d",n);

    return 0;
}