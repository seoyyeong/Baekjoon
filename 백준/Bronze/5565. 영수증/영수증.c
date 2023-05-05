#include <stdio.h>

int main(void)
{
    int n;
    int t;
    scanf("%d",&n);
    
    for(int i=0;i<9;i++)
    {
        scanf("%d",&t);
        n-=t;
    }
    
    printf("%d",n);
    return 0;
}