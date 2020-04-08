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

bool compare(lli a, lli b)
{
    return a>b;
}

int main()
{
   lli n;
   cin>>n;
   vector<lli>vect;
   lli sum=0;
   forn(i,n)
   {
       lli x;
       cin>>x;
       vect.pb(x);
   }
   sort(vect.begin(),vect.end(),compare);

    // cout<<"hello"<<endl;
   forn(i,n)
   {
       sum+=pow(2,i)*vect[i];
   }

   cout<<sum<<endl;
}