#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a>b)?a:b)

int main(void) {

    int n, ans = 0;;
    int arr[26] = { 0 };
    char s1[11];
    scanf("%d", &n);
    n--;
    scanf("%s", s1);
    int len_s1 = strlen(s1);

    for (int i = 0; i < len_s1; i++) 
        arr[s1[i] - 'A']++;
    
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        int flag = 0;
        int check[26] = { 0 };
        char s2[11];
        scanf("%s", s2);
        int len_s2 = strlen(s2);

        if (abs(len_s1 - len_s2) > 1) continue;

        for (int j = 0; j < len_s2; j++)
            check[s2[j] - 'A']++;

        int maxlen = max(len_s1, len_s2);

        for (int k = 0; k < 26; k++) {

            if (abs(arr[k] - check[k]) > 1) {
                flag = 1;
                break;
            }
            if (abs(arr[k] - check[k]) == 1)
                cnt++;
        }
        
        if (flag == 0 && cnt < 3) ans++;

    }

    printf("%d", ans);
    
    return 0;
}
