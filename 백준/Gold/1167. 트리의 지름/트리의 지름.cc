#include <iostream>
#include <vector>

using namespace std;
#define MAX 100001

typedef pair<int, int> P;

vector<vector<P>> tree;

int n;
int leaf;
int ans = 0;

void FindDistance(int node, int prev, int len);

int main(void)
{
	int node;
	int edge;

	scanf("%d", &n);

	tree.resize(n + 1);

	for (int i = 0; i < n; i++)
	{
		int idx;
		scanf("%d", &idx);

		while (1)
		{
			scanf("%d", &node);
			if (node == -1)
			{
				break;
			}
			scanf("%d", &edge);
			tree[idx].push_back({ node, edge });
		}
	}

	FindDistance(1,0,0);
	FindDistance(leaf, 0, 0);

	printf("%d", ans);

	return 0;
}

void FindDistance(int node, int prev, int len)
{
	if (ans < len)
	{
		ans = len;
		leaf = node;
	}

	for (int i = 0; i < tree[node].size(); i++)
	{
		if (tree[node][i].first != prev)
		{
			FindDistance(tree[node][i].first, node, len + tree[node][i].second);
		}
	}

}