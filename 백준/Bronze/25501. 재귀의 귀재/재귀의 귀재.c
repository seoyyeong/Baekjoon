#include <stdio.h>
#include <string.h>

int cnt;

int recursion(const char* s, int l, int r) {
    cnt++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
    return recursion(s, 0, strlen(s) - 1);
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++){
        char s[1000] = "";
        cnt = 0;
        scanf("%s", &s);
        printf("%d ", isPalindrome(s));
        printf("%d\n", cnt);
    }
    
    return 0;
}