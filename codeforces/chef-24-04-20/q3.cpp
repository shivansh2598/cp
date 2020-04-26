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

void find(string s, lli arr[])
{
    fr(j, 0, s.length())
    {
        int index = s[j];
        arr[index]++;
    }
}

int main()
{
    lli n;
    cin >> n;
    lli arr[n][128];
    lli prefix[n][128];
    fr(i, 0, n)
    {
        fr(j, 0, 128)
        {
            arr[i][j] = 0;
            prefix[i][j] = 0;
        }
    }
    fr(i, 0, n)
    {
        string s;
        cin >> s;
        fr(j, 0, s.length())
        {
            lli index = s[j];
            arr[i][index]++;
        }
    }
    fr(j, 0, 128)
    {
        prefix[0][j] = arr[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 128; j++)
        {
            prefix[i][j] = arr[i][j] + prefix[i - 1][j];
        }
    }

    lli q;
    cin >> q;
    while (q--)
    {
        string temp;
        cin >> temp;
        lli temp_arr[128];
        memset(temp_arr, 0, sizeof(lli) * 128);
        find(temp, temp_arr);
        bool ispos = true;
        fr(i, 0, 128)
        {
            if (prefix[n - 1][i] < temp_arr[i])
            {
                cout << -1 << endl;
                ispos = false;
                break;
            }
        }
        if (!ispos)
            continue;

        lli i = 0, j = n - 1;
        bool ruko = false;
        lli minz = INT_MAX;
        for (; j >= 0; j--)
        {
            lli value = 0;
            fr(k, 0, 128)
            {
                value = prefix[j][k] - arr[j][k];
                if (value < temp_arr[k])
                {
                    ruko = true;
                }
            }
            if (ruko)
                break;

            for (i = j - 1; i >= 0; i--)
            {
                bool pos = true;
                lli value = 0;
                fr(k, 0, 128)
                {
                    value = prefix[j][k] - prefix[i][k];
                    if (value < temp_arr[k])
                    {
                        pos = false;
                        break;
                    }
                }
                if (pos)
                    break;
            }
            minz = min(minz, j-i);
        }

        cout << minz << endl;
    }
}