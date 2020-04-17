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

int main()
{
    while (true)
    {
        lli n;
        cin >> n;
        if (n == 0)
            break;
        lli e;
        cin >> e;
        unordered_set<int> unset1;
        unordered_set<int> unset2;
        queue<int> pend;
        vector<int> vect[n];
        bool visited[n];
        memset(visited, false, n * sizeof(bool));
        for (int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            vect[a - 1].push_back(b - 1);
            vect[b - 1].push_back(a - 1);
        }
        pend.push(0);
        unset1.insert(0);
        bool ans = true;

        while (!pend.empty())
        {
            int x = pend.front();
            pend.pop();
            visited[x] = true;
            bool inset1 = false, inset2 = false;
            if (unset1.find(x) != unset1.end())
                inset1 = true;
            else
            {
                inset2 = true;
            }

            for (int i = 0; i < vect[x].size(); i++)
            {

                if (inset1)
                {
                    if (unset1.find(vect[x][i]) != unset1.end())
                    {
                        ans = false;
                        break;
                    }
                    else
                    {
                        pend.push(vect[x][i]);
                        unset2.insert(vect[x][i]);
                    }
                }
                else
                {
                    if (unset2.find(vect[x][i]) != unset2.end())
                    {
                        ans = false;
                        break;
                    }
                    else
                    {
                        pend.push(vect[x][i]);
                        unset1.insert(vect[x][i]);
                    }
                }
            }

            if (!ans)
                break;
        }

        if (ans)
            cout << "YES" << endl;
        else
        {
            cout << "NO" << endl;
        }
    }
}