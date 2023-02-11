#include <stdio.h>
#include <string.h>

int main(void){
    int len;
    char s[101];
    scanf("%s",s);
    len=strlen(s);
    
    for(int i=0;i<len;i++){
        if(s[i]!=s[len-1-i]){
            printf("0");
            return 0;
        }
    }
    printf("1");
    return 0;
}