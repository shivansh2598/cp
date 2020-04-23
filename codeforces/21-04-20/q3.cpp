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
    lli tc;
    cin >> tc;
    while (tc--)
    {
        lli n;
        cin >> n;
        vector<lli> vect, fvect;
        fr(i, 0, n)
        {
            lli x;
            cin >> x;
            vect.pb(x);
        }
        lli temp = 0;
        fr(i, 0, n)
        {
            if (i == 0)
                temp = vect[i];

            else
            {
                if (temp < 0)
                {
                    if (vect[i] > 0)
                    {
                        fvect.pb(temp);
                        temp = vect[i];
                    }
                    else
                    {
                        if (vect[i] > temp)
                            temp = vect[i];
                    }
                }
                else
                {
                    if (vect[i] > 0)
                    {
                        if (vect[i] > temp)
                            temp = vect[i];
                    }
                    else
                    {
                        fvect.pb(temp);
                        temp = vect[i];
                    }
                }
            }

            if (i == n - 1)
                fvect.pb(temp);
        }
        lli sum = 0;
        fr(i, 0, fvect.size())
            sum += fvect[i];

        cout << sum << endl;
    }
}