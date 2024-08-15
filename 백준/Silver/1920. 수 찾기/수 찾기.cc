#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int m;
vector<int> v;

int search(int num);

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        cout << search(temp) << '\n';
    }


    return 0;
}

int search(int num)
{
    int mid;
    int left = 0;
    int right = n - 1;

    while (1)
    {
        mid = (left + right) / 2;
        if (left > mid || right < mid)
        {
            return 0;
        }

        if (v[mid] == num)
        {
            return 1;
        }
        if (v[mid] > num)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }

    }

}