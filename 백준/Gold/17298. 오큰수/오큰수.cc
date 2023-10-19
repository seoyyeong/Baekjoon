#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<int> st;
int arr[1000000];
int ans[1000000];

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}


	for (int i = 0; i < n; i++)
	{
		while (st.empty() == false && arr[st.top()] < arr[i])
		{
			ans[st.top()] = arr[i];
			st.pop();
		}
			st.push(i);
	}

	for (int i = 0; i < n; i++)
	{
		if (ans[i] == 0)
		{
			printf("-1 ");
		}
		else
			printf("%d ", ans[i]);
	}

	return 0;
}