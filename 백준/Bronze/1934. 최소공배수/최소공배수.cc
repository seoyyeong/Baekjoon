#include <iostream>


using namespace std;

int gcd(int a, int b)
{
    int max;
    int min;
    int temp;
    if (a > b)
    {
        max = a;
        min = b;
    }
    else
    {
        max = b;
        min = a;
    }
    while (1)
    {
        if (max % min == 0)
        {
            return min;
        }
        temp = max % min;
        max = min;
        min = temp;
    }

    return max;
}
int main(void)
{
    int t;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        cout << a*b/gcd(a, b) << '\n';
    }


}