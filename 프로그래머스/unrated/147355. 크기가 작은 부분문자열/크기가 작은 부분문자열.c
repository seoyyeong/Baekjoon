#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* t, const char* p) {
    int i = 0, answer = 0;
    int t_len=strlen(t);
    int p_len=strlen(p);
    
    while(i<=t_len-p_len){
        if(strncmp((t+i),p,p_len)<1) answer++;
        i++;
    }
    
    return answer;
}