#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cnt;
int arr[25][25];

int cmp(const void* a, const void* b)
{
    if (*(int*)a > *(int*)b) return 1;
    else return -1;
}

void visit(int x, int y)
{
    if (x < 0 || y < 0 || x >= 25 || y >= 25) return;
    cnt++;
    arr[x][y] = -1;
    if (arr[x][y + 1] == 1)
        visit(x, y + 1);
    if (arr[x + 1][y] == 1)
        visit(x + 1, y);
    if (arr[x - 1][y] == 1)
        visit(x - 1, y);
    if (arr[x][y - 1] == 1)
        visit(x, y - 1);
}

int main(void) {

    int n;
    int total = 0;
    int h[2500];
    cnt = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%1d", &arr[i][j]);


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
            {
                visit(i, j);
                h[total++] = cnt;
                cnt = 0;
            }
        }
    }

    qsort(h, total, sizeof(int), cmp);

    printf("%d\n", total);
    for (int i = 0; i < total; i++)
    {
        printf("%d\n", h[i]);
    }
    
    return 0;
}
