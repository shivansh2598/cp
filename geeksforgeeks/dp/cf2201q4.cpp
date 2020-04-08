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

int main()
{
    lli t;
    cin >> t;
    for (lli p = 0; p < t; p++)
    {
        lli n;
        cin >> n;
        lli a = 0, b = 0, c = 0;
        bool ans = false;
        vector<int>fact;
        for (int j = 2; j <= sqrt(n); j++)
        {
            if(n%j==0)
            {
                if(j==n/j)
                fact.push_back(j);
                else
                {
                    fact.push_back(j);
                    fact.push_back(n/j);
                }
                
            }
        }

        sort(fact.begin(),fact.end());

        for(int i=0;i<fact.size();i++)
        {
            a=fact[i];
            for(int j=i+1;j<fact.size();j++)
            {
                b=fact[j];
                for(int k=j+1;k<fact.size();k++)
                {
                    c=fact[k];
                    if(a*b*c==n){
                    ans=true;
                    break;
                    }
                }
                if(ans)
                break;
            }
            if(ans)
            break;
        }

        if (ans)
        {
            cout << "YES" << endl;
            cout << a << " " << b << " " << c << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}