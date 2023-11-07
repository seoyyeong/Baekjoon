#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> P;
queue<P> q;

int s[] = {0,0,1,1,2,2};
int e[] = {1,2,0,2,0,1};
int visited[201][201];
int cnt[3];
bool ans[201];

void BFS(void);

int main(void)
{

	scanf("%d %d %d", &cnt[0], &cnt[1], &cnt[2]);

	ans[cnt[2]] = true;

	BFS();

	for (int i = 0; i < 201; i++)
	{
		if (ans[i] == true)
			printf("%d ", i);
	}

	return 0;
}

void BFS(void)
{
	int num;
	q.push({ 0,0 });
	visited[0][0] = true;
	P n;

	while (q.size() > 0)
	{
		n = q.front();
		q.pop();
		visited[n.first][n.second] = true;
		num = cnt[2] - n.first - n.second;

		for (int i = 0; i < 6; i++)
		{
			int next[] = { n.first, n.second, num };
			next[e[i]] += next[s[i]];
			next[s[i]] = 0;

			if (next[e[i]] > cnt[e[i]])
			{
				next[s[i]] = next[e[i]] - cnt[e[i]];
				next[e[i]] = cnt[e[i]];
			}

			if (visited[next[0]][next[1]] == false)
			{
				visited[next[0]][next[1]] = true;
				q.push({ next[0], next[1] });

				if (next[0] == 0)
				{
					ans[next[2]] = true;
				}
			}

		}
	}

}