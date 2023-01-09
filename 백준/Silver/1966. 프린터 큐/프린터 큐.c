#include <stdio.h>
#define MAX 101

typedef struct doc {
	int index;
	int key;
}doc;

doc arr[MAX];
int head, tail;

void init(void) {
	head = 0;
	tail = 0;
}

void deque(doc *a) {
	a[head].key = 0;
	a[head].index = 0;
	head = ++head % MAX;
}

void enque(doc* a) {
	a[tail].key = a[head].key;
	a[tail].index = a[head].index;
	tail = ++tail % MAX;
}

int main(void) {

	int t, n, m;

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d %d", &n, &m);
		init();
		doc arr[MAX] = { 0 };
		int ans = 1;

		for (int j = 0; j < n; j++) {
			arr[j].index = j;
			scanf("%d", &arr[j].key);
			tail++;
		}

		while (1) {
			while (1) {
				int cnt = 0;
				int flag = 0;
				for (int i = 1; i < n; i++)
					if (arr[(head + i) % MAX].key > arr[head].key) {
						flag = 1;
						break;
					}
				if (flag == 1) {
					enque(arr);
					deque(arr);
					cnt++;
				}
				if (cnt == 0) break;
			}
			if (arr[head].index == m) break;
			deque(arr);
			ans++;
		}

		printf("%d\n", ans);

	}

	return 0;
}