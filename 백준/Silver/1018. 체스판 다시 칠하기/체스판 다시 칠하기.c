#include <stdio.h>

int main(void) {
    int n, m, min, min1 = 0, min2 = 0;
    char input[51][51];
    char arr1[8][9] = { "WBWBWBWB", "BWBWBWBW","WBWBWBWB", "BWBWBWBW","WBWBWBWB", "BWBWBWBW","WBWBWBWB", "BWBWBWBW" };
    char arr2[8][9] = { "BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB" };
    
    scanf("%d%d", &n, &m);
    min = n * m;

    for (int i = 0; i < n; i++)
         scanf("%s", input[i]);

    for (int i = 0; i < n; i++) {
        if (n-i-7==0) break;
        for (int j = 0; j < m; j++) {
            if (m - j - 7 == 0) break;
            int t = 0;
            for (int k = 0; k < 8; k++) {
                for (int l = 0; l < 8; l++) {
                    if (input[i + k][j + l] != arr1[k][l]) min1++;
                    if (input[i + k][j + l] != arr2[k][l]) min2++;
                }
            }
            t = (min1 < min2) ? min1 : min2;
            min = (min < t) ? min : t;
            min1 = 0;
            min2 = 0;
        }
    }

    printf("%d", min);
    return 0;
}