#include <stdio.h>

int main(void) {
	int sum = 0, score[8];
	for (int i = 0; i < 8; i++) {
		scanf("%d", &score[i]);
		sum += score[i];
	}
	
	for (int i = 0; i < 3; i++) {
		int min = 151;
		int minindex = 0;
		for (int j = 0; j < 8; j++) {
			if (min > score[j] && score[j] != -1) {
				min = score[j];
				minindex = j;
			}
		}
		sum -= min;
		score[minindex] = -1;
	}

	printf("%d\n", sum);

	for (int i = 0; i < 8; i++) 
		if (score[i] != -1)
			printf("%d ", i + 1);

	return 0;
}