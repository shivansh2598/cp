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

lli r,c;
lli dp[1000][1000];

bool check(int i,int j)
{
    if(i>=0 && i<r && j>=0 && j<c)
    return true;

    return false;
}

int findmin(vector<vector<lli>>&vect,lli i,lli j)
{
    if(i==r-1 && j==c-1)
    return vect[i][j];

    if(i>=r || j>=c)
    return -100000;

    if(dp[i][j]!=-1)
    return dp[i][j];

    lli x = findmin(vect,i+1,j);
    lli y = findmin(vect,i,j+1);
    lli z = max(y,x);
    lli k = min(vect[i][j],min(vect[i][j]+z,lli(0)));
    dp[i][j]=k;
    return k;
}

int main()
{
    lli tc;
    cin>>tc;
    while(tc--)
    { 
        memset(dp,-1,sizeof(lli)*1000000);
        cin>>r>>c;
        vector<vector<lli>>vect;
        forn(i,r)
        {
            vector<lli>v;
            forn(j,c){
                lli x;
                cin>>x;
                v.pb(x);
            }
            vect.pb(v);
        }
        int k=findmin(vect,0,0);
        // cout<<k<<endl;
        if(k==0)
        cout<<1<<endl;
        if(k<0)
        {
            cout<<(-k)+1<<endl;
        }
    }
}