#include <stdio.h>
#include <string.h>

char cAlpha[8][4] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };

int main(void) {

    int flag=0, cnt=0;
    char input[101] = "";
    scanf("%s", input);
    char* p = input;

    while (*p) {
        for (int j = 0; j < 8; j++) {
            if (!strncmp(p, cAlpha[j], strlen(cAlpha[j]))) {
                cnt++;
                flag = 1;
                p += strlen(cAlpha[j]);
                break;
            }
        }
        if (!flag) {
            cnt += 1;
            p += 1;
        }
        flag = 0;
    }

    printf("%d", cnt);

    return 0;

}