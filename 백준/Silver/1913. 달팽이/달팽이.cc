#include <iostream>
#define dfMAX_ARR_WH 999

using namespace std;

int arr[dfMAX_ARR_WH][dfMAX_ARR_WH];

int main(void)
{
    int n;
    int find;
    int dist;
    int x;
    int y;
    int num;
    int max;
    
    scanf("%d %d", &n, &find);

    dist = 0;
    num = 1;
    max = n * n;
    x = n / 2;
    y = n / 2;

    arr[y][x] = num++;

    if (max > 1)
    {
        while (1)
        {
            dist++;
            //up
            for (int i = 0; i < dist; i++)
            {
                arr[--y][x] = num++;
                if (num > max)
                {
                    break;
                }
            }
            if (num > max)
            {
                break;
            }

            //right
            for (int i = 0; i < dist; i++)
            {
                arr[y][++x] = num++;
            }
            dist++;
            //down
            for (int i = 0; i < dist; i++)
            {
                arr[++y][x] = num++;
            }
            //left
            for (int i = 0; i < dist; i++)
            {
                arr[y][--x] = num++;
            }
        }
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
            if (arr[i][j] == find)
            {
                y = i;
                x = j;
            }
        }
        printf("\n");
    }

    printf("%d %d", y + 1, x + 1);
    return 0;
}