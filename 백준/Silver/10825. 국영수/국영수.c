#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
	char name[11];
	int kor;
	int eng;
	int math;
}student;

int cmp(const void* a, const void* b) {
	student na = *(student*)a;
	student nb = *(student*)b;
	if (na.kor == nb.kor && na.eng == nb.eng && na.math == nb.math)
		return strcmp(na.name, nb.name);
	else if (na.kor == nb.kor && na.eng == nb.eng)
		return (na.math - nb.math) * (-1);
	else if (na.kor == nb.kor)
		return na.eng - nb.eng;
	else
		return (na.kor - nb.kor) * (-1);
}

int main(void) {
	
	int n;
	scanf("%d", &n);

	student* arr = (student*)malloc(sizeof(student) * n);

	for (int i = 0; i < n; i++){
		scanf("%s", arr[i].name);
		scanf("%d", &arr[i].kor);
		scanf("%d", &arr[i].eng);
		scanf("%d", &arr[i].math);
	}

	qsort(arr, n, sizeof(student), cmp);

	for (int i = 0; i < n; i++) 
		printf("%s\n", arr[i].name);

	free(arr);

	return 0;
}