#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
#define forn(i, n) for (lli i = 0; i < lli(n); ++i)
#define for1(i, n) for (lli i = 1; i <= lli(n); ++i)
#define fore(i, l, r) for (lli i = lli(l); i <= lli(r); ++i)
#define ford(i, n) for (lli i = lli(n) - 1; i >= 0; --i)
#define pb push_back
#define vectvalue lli x;cin >> x;vect.pb(x)
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
        lli n, p;
        cin >> n >> p;
        vector<lli> vect;
        forn(i, n)
        {
            vectvalue;
        }
        lli minz = INT_MAX;
        bool possible = true,possible1=true;
        vector<lli>factors;
        forn(i, n)
        {
            if (p % vect[i] != 0)
            {
                possible = false;
                if (vect[i] < minz)
                {
                    minz = vect[i];
                }
            }
            else if(p==vect[i])
            continue;

            else if(vect[i]==1)
            continue;

            else
            {
                factors.pb(vect[i]);
            }
        }

        lli a=-1,b=-1;
        if(possible){
        for(lli i=0;i<factors.size();i++)
        {
            for(lli j=i+1;j<factors.size();j++)
            {
                lli vv=__gcd(factors[i],factors[j]);
                if(vv==1 || (vv !=factors[i] && vv !=factors[j]))
                {
                    possible1=false;
                    a=min(factors[i],factors[j]);
                    b=max(factors[j],factors[i]);
                    break;
                }
            }
        }
        }

        if (possible&possible1)
            cout << "NO" << endl;
        else{
            cout<<"YES ";
            if(!possible){
            forn(i,n){
                if(vect[i]==minz)
                {
                    lli temp=p/vect[i];
                    temp++;
                    cout<<temp<<" ";
                }
                else 
                cout<<0<<" ";
            }}
            else{
                p=p-b;
                lli temp=p/a;
                temp++;
                forn(i,n){
                if(vect[i]==a)
                {
                    cout<<temp<<" ";
                }
                else if(vect[i]==b)
                    cout<<1<<" ";
                else 
                cout<<0<<" ";
                }
            }
            cout<<endl;
        }
    }
}