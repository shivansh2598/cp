#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

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

vector<lli> factors(lli x)
{
    vector<lli> factor;
    for (int i = 1; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            factor.push_back(i);
            factor.push_back(x / i);
        }
    }

    sort(factor.begin(), factor.end());
    return factor;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lli x;
    cin >> x;
    vector<lli> fac = factors(x);
    lli a = -1, b = -1, maxz = LONG_LONG_MAX;
    for (int i = 0; i < fac.size(); i++)
    {
        for (int j = i + 1; j < fac.size(); j++)
        {
            lli temp = fac[i] * fac[j];
            if (temp > x)
                break;
            lli hcf = __gcd(fac[i], fac[j]);
            if (temp / hcf == x)
            {
                if (max(fac[i], fac[j]) < maxz)
                {
                    a = fac[i];
                    b = fac[j];
                    maxz = max(fac[i], fac[j]);
                }
            }
        }
    }
    cout << min(a, b) << " " << max(a, b) << endl;
}