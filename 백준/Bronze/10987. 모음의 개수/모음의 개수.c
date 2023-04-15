#include <stdio.h>
#include <string.h>

int cnt;

int isvowel(char c){
    if(c=='a') return 1;
    if(c=='e') return 1;
    if(c=='i') return 1;
    if(c=='u') return 1;
    if(c=='o') return 1;
    else return 0;
}

int main(){
    
    cnt=0;
    char t[101];
    scanf("%s",t);
    
    for(int i=0;i<strlen(t);i++){
        if(isvowel(t[i])) cnt++;
    }
    
    printf("%d",cnt);
    return 0;
}