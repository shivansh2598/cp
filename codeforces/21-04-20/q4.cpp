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

        fr(i, 0, n)
        {
            int x;
            cin >> x;
            vect.pb(x);
        }

        int nochange[2*k+2];
        int singlechange[2*k+2];

        memset(nochange, 0, sizeof(int)*(2*k+2));
        memset(singlechange, 0, sizeof(int)*(2*k+2));

        for(int i=0;i<n/2;i++)
        {
            int sum = vect[i] + vect[n-1-i];
            nochange[sum]++;
        }

        for(int i=0;i<n/2;i++)
        {
            int a = min(vect[i],vect[n-i-1])+1;
            int b = max(vect[i], vect[n-i-1])+k;
            singlechange[a]+=1;
            singlechange[b+1]-=1;
        }

        for(int i=1;i<2*k+2;i++)
        {
            singlechange[i]+=singlechange[i-1];
        }

        int minz = INT_MAX;
        for(int i=2; i<=2*k;i++)
        {
            int doublechange = n/2 - (singlechange[i]);
            int ekchange = singlechange[i]-nochange[i];
            int value = ekchange + doublechange*2;
            minz = min(value, minz);
        }

        cout<<minz<<endl;
    }
}