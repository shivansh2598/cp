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

bool comp(pair<int,int>a,pair<int,int>b){
    if(b.second==a.second)
    return a.first<b.first;

    return a.second<b.second;
}

int main(){
   lli n;
   cin>>n;
   vector<pair<int,int>>vect;
   forn(i,n){
       pair<int,int>p;
       cin>>p.first>>p.second;
       vect.pb(p);
   }
   sort(vect.begin(),vect.end(),comp);

    int count=0;
    int end=-1;
   forn(i,n){
       if(vect[i].first>end)
       {
           count++;
           end=vect[i].second;
       }
   }

   cout<<count<<endl;
}