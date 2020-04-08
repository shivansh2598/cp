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
        lli n;
        cin>>n;
        vector<int>x;
        string p;
        cin>>p;
        forn(i,n)
        {
            x.push_back(p[i]-'0');
        }
        // cout<<"hello"<<endl;
        vector<int>a,b;
        a.push_back(1);
        b.push_back(1);
        bool gdbd=false;
        for(lli i=1;i<n;i++)
        {
            // cout<<"hey"<<endl;
            if(x[i]==0)
            {
                a.push_back(0);
                b.push_back(0);
            }
            else if(gdbd)
            {
                a.push_back(0);
                b.push_back(x[i]);
            }
            else
            {
                if(x[i]==2)
                {
                    a.push_back(1);
                    b.push_back(1);
                }
                else
                {
                    gdbd=true;
                    a.push_back(1);
                    b.push_back(0);
                }
                
            }
            
        }

        forn(i,n)
        cout<<a[i];
        cout<<endl;
        forn(i,n)
        cout<<b[i];
        cout<<endl;
    }
}