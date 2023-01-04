#include <stdio.h>
#include <stdlib.h>

typedef struct member {
    int index;
    int age;
    char name[101];
}member;

int cmp(member *i, member *j) {
    if (i->age == j->age) return i->index - j->index;
    return i->age - j->age;
}


int main(void) {
    
    int n;
    scanf("%d",&n);
    member* arr = (member*)malloc(sizeof(member) * n);

    for (int i = 0; i < n; i++) {
        arr[i].index = i;
        scanf("%d %s", &arr[i].age,arr[i].name);
    }

    qsort(arr, n, sizeof(member), cmp);

    for (int i = 0; i < n; i++)
        printf("%d %s\n", arr[i].age, arr[i].name);

    free(arr);
}