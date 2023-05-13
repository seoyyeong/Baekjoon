#include  <stdio.h>

int main(void)
{
    int n;
    int t;
    int sum=0;
    scanf("%d",&n);
    
    for(int i=0;i<5;i++)
    {
        scanf("%d",&t);
        if(t%10==n) sum++;
    }
    
    printf("%d",sum);
    return 0;
}