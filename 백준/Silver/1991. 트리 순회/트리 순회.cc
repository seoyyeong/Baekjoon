#include <iostream>
#include <vector>

using namespace std;

void PreOrder(int n);
void InOrder(int n);
void PostOrder(int n);

struct Node
{
	char _key;
	int _left;
	int _right;
};

vector<Node> v;

int main(void)
{
	int n;
	scanf("%d", &n);
	v.resize(n);

	for (int i = 0; i < n; i++)
	{
		char key;
		char left;
		char right;
		scanf("\n%c %c %c", &key, &left, &right);


		v[(int)key - 'A']._key = key;
		v[(int)key - 'A']._left = (int)left - 'A';
		v[(int)key - 'A']._right = (int)right - 'A';

		if (v[(int)key - 'A']._left == '.' - 'A')
		{
			v[(int)key - 'A']._left = -1;
		}
		if (v[(int)key - 'A']._right == '.' - 'A')
		{
			v[(int)key - 'A']._right = -1;
		}
	}

	PreOrder(0);
	printf("\n");
	InOrder(0);
	printf("\n");
	PostOrder(0);

	return 0;
}

void PreOrder(int n)
{
	if (n == -1)
		return;

	printf("%c", (v[n]._key));
	PreOrder(v[n]._left);
	PreOrder(v[n]._right);
}
void InOrder(int n)
{
	if (n == -1)
		return;

	InOrder(v[n]._left);
	printf("%c", (v[n]._key));
	InOrder(v[n]._right);
}
void PostOrder(int n)
{
	if (n == -1)
		return;

	PostOrder(v[n]._left);
	PostOrder(v[n]._right);
	printf("%c", (v[n]._key));

}