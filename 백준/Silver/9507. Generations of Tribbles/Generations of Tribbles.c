#include <stdio.h>


int main() {
    int t;
    int i;
    long long n;
    long long arr[68];
    scanf("%d", &t);
    arr[0]=1;
    arr[1]=1;
    arr[2]=2;
    arr[3]=4;
    for(i = 4;i<68;i++)
    {
        arr[i]=arr[i-1]+arr[i-2]+arr[i-3]+arr[i-4];
    }
    
    
    for(i=0;i<t;i++)
    {
        scanf("%lld",&n);
        printf("%lld\n",arr[n]);
        
    }
    return 0;
}