#include <iostream>

using namespace std;

int uf[1000001];

void unionfunc(int a, int b);
int findfunc(int a);
bool check(int a, int b);

int main(void)
{
    int n;
    int m;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        uf[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int type;
        int a;
        int b;
        cin >> type >> a >> b;

        if (type == 0)
        {
            unionfunc(a, b);
        }
        else
        {
            if (check(a, b))
            {
                cout << "YES" <<'\n';
            }
            else
            {
                cout << "NO" << '\n';
            }
        }
    }



    return 0;
}

void unionfunc(int a, int b)
{
    a = findfunc(a);
    b = findfunc(b);

    if (a != b)
    {
        uf[b] = a;
    }
}

int findfunc(int a)
{
    if (uf[a] != a)
    {
        return uf[a] = findfunc(uf[a]);
    }

    else
    {
        return a;
    }
}

bool check(int a, int b)
{
    a = findfunc(a);
    b = findfunc(b);

    if (a != b)
    {
        return false;
    }
    return true;
}