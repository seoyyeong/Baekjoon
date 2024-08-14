#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

bool check[100001];
stack<int> st;

int main(void)
{
    int n;
    int temp;
    string s;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    st.push(0);

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp > st.top())
        {
            for (int i = st.top() + 1; i <= temp; i++)
            {
                if (check[i] == false)
                {
                    s += '+';
                    s += '\n';
                    check[i] = true;
                    st.push(i);
                }
            }

            s += '-';
            s += '\n';
            st.pop();
        }
        else if (temp == st.top())
        {
            s += '-';
            s += '\n';
            st.pop();
        }
        else
        {
            s = "NO";
            s += '\n';
            break;
        }

    }


    cout << s;

    return 0;
}