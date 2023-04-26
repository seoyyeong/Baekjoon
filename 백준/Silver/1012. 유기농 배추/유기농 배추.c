#include <stdio.h>
#include <string.h>

int cnt;
int arr[50][50];

void visit(int x, int y)
{
    if (x < 0 || y < 0 || x >= 50 || y >= 50) return;

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

    int t;
    int n;
    int m;
    int k;

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        cnt = 0;
        memset(arr, 0, sizeof(arr));
        scanf("%d %d %d", &n, &m, &k);

        for (int j = 0; j < k; j++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            arr[x][y] = 1;
        }

        for (int a = 0; a < n; a++)
        {
            for (int b = 0; b < m; b++)
            {
                if (arr[a][b] == 1)
                {
                    cnt++;
                    visit(a, b);
                }
            }
        }
        printf("%d\n", cnt);
    }
    
    return 0;
}