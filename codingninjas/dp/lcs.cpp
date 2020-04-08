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

int dp[1000][1000];

int lcs(string s1,string s2,int i,int j)
{
    if(i>=s1.length() || j>=s2.length())
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];

    if(s1[i]==s2[j])
    {
        dp[i][j]=1+lcs(s1,s2,i+1,j+1);
    }
    else
    {
        dp[i][j]=max(lcs(s1,s2,i,j+1),lcs(s1,s2,i+1,j));
    }
    return dp[i][j];
}

int main()
{
   string s1,s2;
   cin>>s1>>s2;
   cout<<lcs(s1,s2,0,0)<<endl;
}