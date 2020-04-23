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
        lli n, k;
        cin >> n >> k;
        vector<int> vect;
        int freq[2 * k + 1];
        fr(i, 0, 2 * k + 1)
            freq[i] = 0;

        fr(i, 0, n)
        {
            int x;
            cin >> x;
            vect.pb(x);
        }

        fr(i, 0, n / 2)
        {
            int sum = vect[i] + vect[n - 1 - i];
            freq[sum]++;
        }

        int mxfreq = INT_MIN;
        int mxfreqind = INT_MIN;

        fr(i, 0, 2 * k + 1)
        {
            if (freq[i] >= mxfreq)
            {
                mxfreq = freq[i];
                mxfreqind = i;
            }
        }

        vector<int> v;
        fr(i, 0, 2 * k + 1)
        {
            if (freq[i] == mxfreq)
            {
                v.push_back(i);
            }
        }

        lli fminchanges = INT_MAX;

        for (int j = 0; j < v.size(); j++)
        {
            lli minchanges = 0;
            fr(i, 0, n / 2)
            {
                int sum = vect[i] + vect[n - 1 - i];
                if (sum == v[j])
                    continue;

                if (sum > v[j])
                {
                    if (vect[i] > v[j] - 1 && vect[n - i - 1] > v[j] - 1)
                        minchanges += 2;
                    else
                    {
                        minchanges += 1;
                    }
                }
                else
                {
                    if ((k + vect[i]) < v[j] && (k + vect[n - 1 - i]) < v[j])
                        minchanges += 2;
                    else
                    {
                        minchanges += 1;
                    }
                }
            }
            fminchanges = min(fminchanges,minchanges);
        }

        cout << min(fminchanges, n / 2) << endl;
    }
}