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

string dp[2002][2002];

int ifposs(int j, string s)
{
    if (j == 0)
    {
        int count = 0;
        for (int i = 0; i < 7; i++)
        {
            if (i == 3)
            {
                if (s[i] == '1')
                    return -1;
            }
            else
            {
                if (s[i] == '0')
                    count++;
            }
        }
        return count;
    }
    else if (j == 1)
    {
        int count = 0;
        for (int i = 0; i < 7; i++)
        {
            if (i == 2)
            {
                if (s[i] == '0')
                    count++;
            }
            else if (i == 5)
            {
                if (s[i] == '0')
                    count++;
            }
            else
            {
                if (s[i] == '1')
                    return -1;
            }
        }
        return count;
    }
    else if (j == 2)
    {
        int count = 0;
        for (int i = 0; i < 7; i++)
        {
            if (i == 1)
            {
                if (s[i] == '1')
                    return -1;
            }
            else if (i == 5)
            {
                if (s[i] == '1')
                    return -1;
            }
            else
            {
                if (s[i] == '0')
                    count++;
            }
        }
        return count;
    }
    else if (j == 3)
    {
        int count = 0;
        for (int i = 0; i < 7; i++)
        {
            if (i == 1)
            {
                if (s[i] == '1')
                    return -1;
            }
            else if (i == 4)
            {
                if (s[i] == '1')
                    return -1;
            }
            else
            {
                if (s[i] == '0')
                    count++;
            }
        }
        return count;
    }
    else if (j == 4)
    {
        int count = 0;
        for (int i = 0; i < 7; i++)
        {
            if (i == 0)
            {
                if (s[i] == '1')
                    return -1;
            }
            else if (i == 4)
            {
                if (s[i] == '1')
                    return -1;
            }
            else if (i == 6)
            {
                if (s[i] == '1')
                    return -1;
            }
            else
            {
                if (s[i] == '0')
                    count++;
            }
        }
        return count;
    }
    else if (j == 5)
    {
        int count = 0;
        for (int i = 0; i < 7; i++)
        {
            if (i == 2)
            {
                if (s[i] == '1')
                    return -1;
            }
            else if (i == 4)
            {
                if (s[i] == '1')
                    return -1;
            }
            else
            {
                if (s[i] == '0')
                    count++;
            }
        }
        return count;
    }
    else if (j == 6)
    {
        int count = 0;
        for (int i = 0; i < 7; i++)
        {
            if (i == 2)
            {
                if (s[i] == '1')
                    return -1;
            }
            else
            {
                if (s[i] == '0')
                    count++;
            }
        }
        return count;
    }
    else if (j == 7)
    {
        int count = 0;
        for (int i = 0; i < 7; i++)
        {
            if (i == 2)
            {
                if (s[i] == '0')
                    count++;
            }
            else if (i == 5)
            {
                if (s[i] == '0')
                    count++;
            }
            else if (i == 0)
            {
                if (s[i] == '0')
                    count++;
            }
            else
            {
                if (s[i] == '1')
                    return -1;
            }
        }
        return count;
    }
    else if (j == 8)
    {
        int count = 0;
        for (int i = 0; i < 7; i++)
        {
            if (s[i] == '0')
                count++;
        }
        return count;
    }
    else if (j == 9)
    {
        int count = 0;
        for (int i = 0; i < 7; i++)
        {
            if (i == 4)
            {
                if (s[i] == '1')
                    return -1;
            }
            else
            {
                if (s[i] == '0')
                    count++;
            }
        }
        return count;
    }
}

vector<pair<int, int>> precal[2002];
int minvalue[2002];
int maxvalue[2002];

string findposs(vector<string> vect, lli i, lli n, lli k)
{
    if (i == n && k == 0)
        return "";

    if (i == n)
        return "-1";

    if (k < 0)
        return "-1";

    if (k < minvalue[i])
        return "-1";

    if (k > maxvalue[i])
        return "-1";

    if (dp[i][k] != "")
        return dp[i][k];

    dp[i][k] = "-1";

    for (int j = 0; j < precal[i].size(); j++)
    {
        pair<int, int> p = precal[i][j];
        string temp = findposs(vect, i + 1, n, k - p.second);
        if (temp != "-1")
        {
            dp[i][j] = to_string(p.first) + temp;
            return dp[i][j];
        }
    }

    return dp[i][k];
}

int main()
{
    lli n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = "";
        }
    }
    vector<string> vect;
    fr(i, 0, n)
    {
        minvalue[i] = 0;
        maxvalue[i] = 0;
        string a;
        cin >> a;
        for (int j = 9; j >= 0; j--)
        {
            int x = ifposs(j, a);
            if (x != -1)
            {
                precal[i].push_back({j, x});
            }
        }
        vect.push_back(a);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int minz = INT_MAX;
        int maxz = INT_MIN;
        fr(j, 0, precal[i].size())
        {
            minz = min(minz, precal[i][j].second);
            maxz = max(maxz, precal[i][j].second);
        }
        minvalue[i] = minz;
        maxvalue[i] = maxz;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        minvalue[i] = minvalue[i] + minvalue[i + 1];
        maxvalue[i] = maxvalue[i] + maxvalue[i + 1];
    }

    string ans = findposs(vect, 0, n, k);
    cout << ans << endl;
}