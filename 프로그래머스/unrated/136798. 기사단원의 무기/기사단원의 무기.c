#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int number, int limit, int power) {
    int t, answer=0;
    int *arr=(int*)calloc(number+1, sizeof(int));
    for(int i=1;i<=number;i++){
        t=i;
        while(t<=number){
            arr[t]++;
            t+=i;
        }
        if(arr[i]>limit){
            answer+=power;
        }else{
            answer+=arr[i];
        }
    }
    
    free(arr);
    return answer;
}