#include <stdio.h>

int main() {
    int n, cnt=0;
    int arr[5]={500,100,50,10,5};
    scanf("%d",&n);
    n=1000-n;
    for(int i=0;i<5;i++){
        cnt+=(n/arr[i]);
        n%=arr[i];
        
    }
    cnt+=n;
    printf("%d",cnt);
    return 0;
}