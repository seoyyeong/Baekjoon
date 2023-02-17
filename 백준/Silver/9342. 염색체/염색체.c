#include <stdio.h>

int main(void) {

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int len, j = 0;
        int flag = 0;
        char s[201];
        scanf("%s", s);

        if (s[0]=='B'||s[0]=='D'||s[0]=='E')
            j = 1;

        while (1) {
            if (flag == 0) {
                if (s[j] == 'A') {
                    while (s[j] == 'A')
                        j++;
                    flag = 1;
                }
                else break;
            }if (flag == 1) {
                if (s[j] == 'F') {
                    while (s[j] == 'F')
                        j++;
                    flag = 2;
                }
                else break;
            }if (flag == 2) {
                if (s[j] == 'C') {
                    while (s[j] == 'C')
                        j++;
                    flag = 3;
                }
                else break;
            }if (flag == 3) {
                if (s[j] <= 'F' || s[j] == '\0')
                    flag = 4;
                break;
            }
        }

        if (flag == 4) 
            printf("Infected!\n");
        else 
            printf("Good\n");
    }

    return 0;
}