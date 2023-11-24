#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int _parent;
	vector<int> _child;
};

vector<Node> v;
int cnt;

void Order(int a);

int main(void)
{
	int n;
	int d;
	int root;

	scanf("%d", &n);

	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &v[i]._parent);
		if (v[i]._parent != -1)
		{
			v[v[i]._parent]._child.push_back(i);
		}
		else
			root = i;
	}

	scanf("%d", &d);
	if (v[d]._parent == -1)
	{
		printf("0");
		return 0;
	}

	vector<int>::iterator iter;
	for (iter = v[v[d]._parent]._child.begin(); iter != v[v[d]._parent]._child.end(); ++iter)
	{
		if (*iter == d)
		{
			v[v[d]._parent]._child.erase(iter);
			break;
		}
	}

	Order(root);

	printf("%d", cnt);


	return 0;
}

void Order(int a)
{

	if (v[a]._child.size() == 0)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < v[a]._child.size(); i++)
	{
		Order(v[a]._child[i]);
	}

}