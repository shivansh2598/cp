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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lli tc;
    cin >> tc;
    while (tc--)
    {
        lli m1, y1, m2, y2;
        cin >> m1 >> y1;
        cin >> m2 >> y2;
        if (m1 > 2)
            y1++;
        if (m2 < 2)
            y2--;

        lli temp = (y2 - y1) / 2000;
        lli rem = (y2 - y1) % 2000;
        lli ans = 0;
        ans += temp * 505;
        for (lli i = y1; i <= y1 + rem; i++)
        {
            lli odd = 0;
            lli ee = i;
            ee--;
            ee = ee % 400;
            if (ee >= 300)
            {
                ee = ee % 300;
                odd += 1;
            }
            if (ee >= 200)
            {
                ee = ee % 200;
                odd += 3;
            }
            if (ee >= 100)
            {
                ee = ee % 100;
                odd += 5;
            }

            lli leap = ee / 4;
            lli normal = ee - leap;
            odd += (2 * leap) + normal;
            odd += 32;
            odd = odd % 7;
            if (odd == 6)
            {
                ans++;
            }
            else if (odd == 0)
            {
                if (i % 4 == 0)
                {
                    if (i % 100 == 0)
                    {
                        if (i % 400 == 0)
                        {
                        }
                        else
                        {
                            ans++;
                        }
                    }
                }
                else
                {
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }
}