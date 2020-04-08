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

lli moduloexpo(lli a, lli n, lli m)
{
    if(n==0)
    return 1;

    else if(n%2==0)
    {
        lli temp=((a%m)*(a%m))%m;
        return moduloexpo(temp,n/2,m);
    }
    else
    {
        lli temp=((a%m)*(a%m))%m;
        return ((a%m)*(moduloexpo(temp,n/2,m))%m)%m;
    }
    
}

int main()
{
   lli n,k,x;
   cin>>n>>k>>x;
   string s = to_string(n);
   cout<<s[0]<<endl;
   lli m=pow(10,9)+7;
   lli temp=moduloexpo(k-1,n-4,m);
   lli tmp=pow((k-2),2)+(k-1);
   lli ans=((temp%m)*(tmp)%m)%m;
    cout<<ans<<endl;
}