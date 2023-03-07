#include <stdio.h>


int main(void) {
    long long A, B;
    int N;
    scanf("%lld %lld %d", &A, &B, &N);
    A %= B;
    for (int i = 0; i < N; i++) {
        A *= 10;
        if (i == N - 1) {
            printf("%lld\n", A / B);
            break;
        }
        A %= B;
    }
    return 0;
   }