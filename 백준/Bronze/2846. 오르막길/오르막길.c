#include <stdio.h>

int main(void) {
	int n, t, max=0;
	int arr[1000];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	t=arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]>arr[i-1]){
			if(max<arr[i]-t)
				max=arr[i]-t;
		}else
		t=arr[i];
	}
	printf("%d",max);
	return 0;
}
