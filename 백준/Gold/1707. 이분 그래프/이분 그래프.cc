#include <iostream>
#include <vector>
#include <memory.h>

#define MAX_SIZE 20'001
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<char> check;
int k;
int v;
int e;
bool ans;

void DFS(int n);


int main(void)
{
	int temp1;
	int temp2;

	scanf("%d", &k);

	for (int i = 0; i < k; i++)
	{
		ans = true;

		scanf("%d %d", &v, &e);
		graph.resize(v + 1);
		visited.resize(v + 1);
		check.resize(v + 1);

		for (int j = 0; j < e; j++)
		{
			scanf("%d %d", &temp1, &temp2);
			graph[temp1].push_back(temp2);
			graph[temp2].push_back(temp1);
		}

		for (int j = 1; j <= v; j++)
		{
			if (ans == false)
				break;

			DFS(j);
		}

		if (ans == true)
			printf("YES\n");
		else
			printf("NO\n");

		for (int i = 0; i <= v; i++)
		{
			graph[i].clear();
		}
		visited.clear();
		check.clear();

	}



	return 0;
}


void DFS(int n)
{
	visited[n] = true;

	for (int i = 0; i < graph[n].size(); i++)
	{
		if (visited[graph[n][i]] == false)
		{
			check[graph[n][i]] = (check[n] + 1) % 2;

			DFS(graph[n][i]);
		}
		else
		{
			if (check[graph[n][i]] == check[n])
				ans = false;
		}
	}
}