#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
#define forn(i, n) for (lli i = 0; i < lli(n); ++i)
#define for1(i, n) for (lli i = 1; i <= lli(n); ++i)
#define fore(i, l, r) for (lli i = lli(l); i <= lli(r); ++i)
#define ford(i, n) for (lli i = lli(n) - 1; i >= 0; --i)
#define pb push_back
#define vectvalue \
    lli x;        \
    cin >> x;     \
    vect.pb(x)
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

pair<double, double> dp[505][105];

pair<double, double> findmin(vector<pair<double, double>> &vect, int bud, int n, int c, int i)
{
    if (i >= n)
        return make_pair(0, 0);

    if (c > bud)
        return make_pair(0, 0);

    if (dp[c][i].first != -1)
        return dp[c][i];

    double x = 0;
    pair<double, double> p;
    if (c + vect[i].first <= bud)
    {
        p = findmin(vect, bud, n, c + vect[i].first, i + 1);
        p.first += vect[i].first;
        p.second += vect[i].second;
        x = p.second;
    }
    double y = 0;
    pair<double, double> q = findmin(vect, bud, n, c, i + 1);

    if (q.first == 0)
        y = 0;
    else
        y = q.second;

    if (x > y)
    {
        // cout << p.first << " " << p.second << endl;
        dp[c][i] = p;
    }
    else if(x==y)
    {
        if(p.first<q.first)
            dp[c][i]=p;
        else
            dp[c][i]=q;
    }
    else
    {
        // cout << q.first << " " << q.second << endl;
        dp[c][i] = q;
    }

    return dp[c][i];
}

int main()
{
    
    while (true)
    {
        lli bud, n;
        cin >> bud >> n;
        if(bud==0 && n==0)
            return 0;
        
        for (int i = 0; i < 505; i++)
        {
            for (int j = 0; j < 105; j++)
            {
                dp[i][j].first = -1;
                dp[i][j].second = -1;
            }
        }

        vector<pair<double, double>> vect;
        forn(i, n)
        {
            double ecost, fun;
            cin >> ecost >> fun;
            pair<double, double> p = make_pair(ecost, fun);
            vect.pb(p);
        }
        pair<double, double> p = findmin(vect, bud, n, 0, 0);
        cout << p.first << " " << p.second << endl;
    }
}