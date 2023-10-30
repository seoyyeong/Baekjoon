#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define MAX 1001

queue<int> q;
bool arr[MAX][MAX];
bool visited_DFS[1001];
bool visited_BFS[1001];
int n;

void DFS(int idx);
void BFS(void);

int main(void)
{
	int m;
	int v;
	int a;
	int b;
	scanf("%d %d %d", &n, &m, &v);

	for(int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		arr[a][b] = true;
		arr[b][a] = true;
	}


	DFS(v);
	printf("\n");
	q.push(v);
	BFS();


	return 0;

}

void DFS(int idx)
{
	if (visited_DFS[idx] == true)
		return;

	visited_DFS[idx] = true;
	printf("%d ", idx);

	for (int i = 1; i <= n; i++)
	{
		if (visited_DFS[i] == false && arr[idx][i] == true)
			DFS(i);
	}

	return;
}

void BFS(void)
{
	int v;
	while (q.size() > 0)
	{
		v = q.front();
		q.pop();

		if (visited_BFS[v] == false)
		{
			visited_BFS[v] = true;
			printf("%d ", v);

			for (int i = 1; i <= n; i++)
			{
				if (visited_BFS[i] == false && arr[v][i] == true)
				{
					q.push(i);
				}
			}
		}

	}

	return;

}