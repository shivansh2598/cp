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
        if (n % 4 != 0)
        {
            cout << "NO" << endl;
            continue;
        }
        cout<<"YES"<<endl;
        int k = 2;
        lli sum = 0;
        for (int i = 0; i < n / 2; i++, k += 2)
        {
            cout << k << " ";
            sum += k;
        }

        k = 1;
        lli sum1 = 0;
        for (int i = 0; i < n / 2 - 1; i++, k += 2)
        {
            cout << k << " ";
            sum1 += k;
        }
        cout << sum - sum1 << endl;
    }
}