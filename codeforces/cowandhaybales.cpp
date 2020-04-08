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

void vprint(vector<int>&v)
{  for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<endl;}

void aprint(int *arr,int n)
{  for(int i=0;i<n;i++)cout<<arr[i]<<' ';cout<<endl;}


int main()
{
    lli tc;
    cin>>tc;
    while(tc--)
    { 
        lli n,d;
        cin>>n>>d;
        vector<lli>vect;
        forn(i,n){
            lli x;
            cin>>x;
            vect.pb(x);
        }
        if(n==1){
        cout<<vect[0]<<endl;
        continue;
        }
        lli count=0;
        for(lli i=1;i<n;i++)
        {
            if(d-i<0)
            break;

            lli val=vect[i];
            lli reqd=vect[i]*i;
            if(reqd<=d)
            {
                d-=reqd;
                count+=vect[i];
            }
            else
            {
                lli valz=d/i;
                count+=d/i;
                break;
            }
            
        }

        cout<<vect[0]+count<<endl;
    }
}