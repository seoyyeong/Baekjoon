#include <stdio.h>

int main(void) {
    int m, n, sum=0, min=10001;
    scanf("%d %d",&m, &n);
    
    int i=1;
    
    while(i*i<m){
        i++;
    }
    min=i*i;
    while(i*i<=n){
        sum+=i*i;
        i++;
    }
    
    if(sum==0) printf("-1");
    else
        printf("%d\n%d",sum,min);
    return 0;
}