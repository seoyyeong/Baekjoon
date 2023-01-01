#include <stdio.h>

int main(void) {

    while (1) {
        int age, weight;
        char name[11];
        scanf("%s %d %d", name, &age, &weight);
        if (name[0] == '#') return 0;

        printf("%s ", name);
        printf("%s", (age > 17 || weight >= 80) ? "Senior\n" : "Junior\n");
    }
    return 0;
}