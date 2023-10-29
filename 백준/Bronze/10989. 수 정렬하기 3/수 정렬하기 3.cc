#include <iostream>

int arr[10001];

int main(void)
{
	int n;
	int temp;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        arr[temp]++;
    }

    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            printf("%d\n", i);
        }

    }

	return 0;
}