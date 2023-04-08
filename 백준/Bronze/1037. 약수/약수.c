
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c, t, min=1000001, max=0;
    scanf("%d",&c);
    for(int i=0;i<c;i++){
        scanf("%d",&t);
        if(t<min) min=t;
        if(t>max) max=t;
    }
    printf("%d",min*max);
    
}
