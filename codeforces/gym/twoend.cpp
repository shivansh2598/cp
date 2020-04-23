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

lli dp[1001][1001];

lli recur(vector<int> &vect, int i, int j)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    lli a = vect[i];
    if (vect[i + 1] >= vect[j])
        a += recur(vect, i + 2, j);
    else
        a += recur(vect, i + 1, j - 1);

    lli b = vect[j];
    if (vect[i] >= vect[j - 1])
        b += recur(vect, i + 1, j - 1);
    else
        b += recur(vect, i, j - 2);

    dp[i][j] = max(a, b);
    return dp[i][j];
}

int main()
{
    int t = 1;
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                dp[i][j] = -1;
        }

        vector<int> vect;
        lli sum = 0;
        fr(i, 0, n)
        {
            int x;
            cin >> x;
            sum += x;
            vect.pb(x);
        }
        //dp
        lli sum1 = recur(vect, 0, vect.size() - 1);

        lli sum2 = sum - sum1;
        lli ans = sum1 - sum2;
        cout << "In game " << t << ", the greedy strategy might lose by as many as " << ans << " points." << endl;
        t++;
    }
}