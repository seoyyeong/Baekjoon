#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int cmp_a(const void *a, const void *b){
    int na=*(int*)a;
    int nb=*(int*)b;
    if(na>nb) return 1;
    else if(na==nb) return 0;
    else return -1;
}
int cmp_b(const void *a, const void *b){
    int na=*(int*)a;
    int nb=*(int*)b;
    if(na>nb) return -1;
    else if(na==nb) return 0;
    else return 1;
}

int solution(int A[], size_t A_len, int B[], size_t B_len) {
    int answer = 0;
    qsort(A,A_len,sizeof(int),cmp_a);
    qsort(B,B_len,sizeof(int),cmp_b);
    
    for(int i=0;i<A_len;i++){
        answer+=(A[i]*B[i]);
    }
    
    return answer;
}