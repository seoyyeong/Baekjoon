#include <stdio.h>
#include <string.h>

int main() {
    int n, flag;
    char s[8];
    scanf("%d",&n);
    for(int i=n;i>=4;i--){
        flag=0;
        sprintf(s, "%d",i);
        for(int i=0;i<strlen(s);i++){
            if(s[i]!='7'&&s[i]!='4'){
                flag=1;
                break;
            }
        }
        if(flag==0){
            printf("%d",i);
            return 0;
        }
    }
}