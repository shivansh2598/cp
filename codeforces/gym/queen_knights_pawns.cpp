#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
#define fr(i, k, n) for (lli i = k; i < lli(n); ++i)
#define pb push_back
using namespace std;

void vprint(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;
}

void aprint(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

bool safe[1005][1005];
lli n, m;
bool check(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
        return true;

    return false;
}

void knight(int x, int y)
{
    if (check(x + 2, y + 1))
        safe[x + 2][y + 1] = false;

    if (check(x + 2, y - 1))
        safe[x + 2][y - 1] = false;

    if (check(x - 2, y + 1))
        safe[x - 2][y + 1] = false;

    if (check(x - 2, y - 1))
        safe[x - 2][y - 1] = false;

    if (check(x + 1, y + 2))
        safe[x + 1][y + 2] = false;

    if (check(x - 1, y + 2))
        safe[x - 1][y + 2] = false;

    if (check(x + 1, y - 2))
        safe[x + 1][y - 2] = false;

    if (check(x - 1, y - 2))
        safe[x - 1][y - 2] = false;
}

void queenz(int x, int y)
{

    int j = y - 1;
    while (j >= 0)
    {
        if (!safe[x][j])
            break;
        safe[x][j] = false;
        j--;
    }

    j = y + 1;
    while (j < m)
    {
        if (!safe[x][j])
            break;
        safe[x][j] = false;
        j++;
    }

    int i = x - 1;
    while (i >= 0)
    {
        if (!safe[i][y])
            break;
        safe[i][y] = false;
        i--;
    }
    //bottom
    i = x + 1;
    while (i < n)
    {
        if (!safe[i][y])
            break;
        safe[i][y] = false;
        i++;
    }

    bool lt = true, rt = true, lb = true, rb = true;
    int k = 1;

    while (lt | rt | lb | rb)
    {
        if (lt)
        {
            if (!check(x - k, y - k))
            {
                lt = false;
            }
            else
            {
                if (!safe[x - k][y - k])
                    lt = false;

                else
                {
                    safe[x - k][y - k] = false;
                }
            }
        }
        if (rt)
        {
            if (!check(x + k, y - k))
            {
                rt = false;
            }
            else
            {
                if (!safe[x + k][y - k])
                    rt = false;

                else
                {
                    safe[x + k][y - k] = false;
                }
            }
        }
        if (lb)
        {
            if (!check(x - k, y + k))
            {
                lb = false;
            }
            else
            {
                if (!safe[x - k][y + k])
                    lb = false;

                else
                {
                    safe[x - k][y + k] = false;
                }
            }
        }
        if (rb)
        {
            if (!check(x + k, y + k))
            {
                rb = false;
            }
            else
            {
                if (!safe[x + k][y + k])
                    rb = false;

                else
                {
                    safe[x + k][y + k] = false;
                }
            }
        }
        k++;
    }
}

int main()
{
    int t = 1;
    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                safe[i][j] = 1;
            }
        }

        vector<pair<int, int>> queen, knights;
        int k;

        cin >> k;
        fr(i, 0, k)
        {
            int x, y;
            cin >> x >> y;
            safe[x - 1][y - 1] = false;
            queen.pb({x - 1, y - 1});
        }

        cin >> k;
        fr(i, 0, k)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            safe[x][y] = false;
            knights.pb({x, y});
        }

        cin >> k;
        fr(i, 0, k)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            safe[x][y] = false;
        }

        fr(i, 0, queen.size())
        {
            pair<int, int> p = queen[i];
            queenz(p.first, p.second);
        }

        fr(i, 0, knights.size())
        {
            knight(knights[i].first, knights[i].second);
        }

        lli count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (safe[i][j])
                    count++;
            }
        }
        cout << "Board " << t << " has " << count << " safe squares." << endl;
        t++;
    }
}