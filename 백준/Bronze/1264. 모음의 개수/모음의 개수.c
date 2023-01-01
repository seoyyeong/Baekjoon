#include <stdio.h>


int main(void) {

    int cnt;
    char arr[10] = {'A','E','U','I','O', 'a', 'e', 'i', 'o', 'u'};

    while (1) {
        cnt = 0;
        char s[256];
        int a = 0;
        while (1) {
            scanf("%c", &s[a]);
            if (s[a] == '#') return 0;
            if (s[a] == '\n') break;
            a++;
        }

        for(int i=0;i<a;i++) {
            for (int j = 0; j < 10; j++) {
                if (s[i]==arr[j]) {
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
        
    }
    return 0;
}