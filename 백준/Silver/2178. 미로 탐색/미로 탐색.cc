#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define MAX 101

struct s
{
	int x;
	int y;
	int depth;
};

int n;
int m;
char arr[MAX][MAX];
int visited[MAX][MAX];
queue<s> q;

void FindPath(void);

int main(void)
{
	char temp[MAX];

	scanf("%d %d ", &n, &m);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", &arr[i]);
	}

	q.push({0,0,1});
	FindPath();

	printf("%d", visited[n -1][m - 1]);

	return 0;
}

void FindPath(void)
{
	s idx;
	int depth;

	while (q.size() > 0)
	{
		idx = q.front();
		q.pop();

		if (idx.x < 0 || idx.y < 0 || idx.x >= m || idx.y >= n)
			continue;

		if (arr[idx.y][idx.x] == '0')
			continue;

		depth = idx.depth;

		if (visited[idx.y][idx.x] != 0)
		{
			if (depth < visited[idx.y][idx.x])
			{
				visited[idx.y][idx.x] = depth;
			}
		}
		else
		{

			visited[idx.y][idx.x] = depth;

			if (visited[idx.y + 1][idx.x] == false)
			{
				q.push({ idx.x, idx.y + 1 , depth + 1 });
			}

			if (visited[idx.y - 1][idx.x] == false)
			{
				q.push({ idx.x, idx.y - 1, depth + 1 });
			}

			if (visited[idx.y][idx.x + 1] == false)
			{
				q.push({ idx.x + 1, idx.y, depth + 1 });
			}


			if (visited[idx.y][idx.x - 1] == false)
			{
				q.push({ idx.x - 1, idx.y, depth + 1 });
			}
		}
	}
}