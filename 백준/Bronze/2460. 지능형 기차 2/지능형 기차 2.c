#include <stdio.h>

int main()
{
    int out, in, max=10000, cnt=0, ans=0;
    while(scanf("%d %d",&out, &in)!=EOF){
        cnt-=out;
        if(cnt+in>max) cnt=max;
        else cnt+=in;
        if(ans<cnt) ans=cnt;
    }
    
    printf("%d",ans);
    return 0;
}
