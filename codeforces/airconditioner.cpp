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

struct st{
    lli t;
    lli l;
    lli h;
}

int main()
{
    lli tc;
    cin>>tc;
    while(tc--)
    { 
        lli n,m;
        cin>>n>>m;
        vector<*st>vect;
        forn(i,n)
        {
            lli t,l,h;
            cin>>t>>l>>h;
            st *temp = new st();
            temp->t=t;
            temp->l=l;
            temp->h=h;
            vect.pb(temp);
        }
        lli t1=0,t2=0;
        forn(i,n)
        {
            lli t1=t2;
            t2=*vect[i]->t;
            lli diff=t2-t1;
            lli l=*vect[i]->l;
            lli h=*vect[i]->h;
            if(m>=l )
        }
    }
}