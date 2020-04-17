#include <bits/stdc++.h>
using namespace std;
vector<int> vect[100005];
// vector<int>tran[100005];
stack<int> st;
bool visited[100005];

void dfs(int x)
{
    visited[x] = true;

    for (int i = 0; i < vect[x].size(); i++)
    {
        if (!visited[vect[x][i]])
        {
            dfs(vect[x][i]);
        }
    }

    st.push(x);
}

void dfs1(int x)
{
    visited[x] = true;

    for (int i = 0; i < vect[x].size(); i++)
    {
        if (!visited[vect[x][i]])
        {
            dfs1(vect[x][i]);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            vect[a].push_back(b);
            // tran[b].push_back(a);
        }

        for (int i = 0; i <= n; i++)
        {
            visited[i] = false;
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                dfs(i);
            }
        }

        for (int i = 0; i <= n; i++)
        {
            visited[i] = false;
        }
        int count=0;
        while(!st.empty())
        {
            int x = st.top();
            st.pop();
            if(visited[x])
            continue;

            cnt++;
            dfs1(x);
        }

        for (int i = 0; i <= n; i++)
        {
            vect[i].clear();
        }
    }

    return 0;
}
