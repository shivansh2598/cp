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

lli n;
vector<lli>vect;

int main()
{
   cin>>n;
   forn(i,n){
       lli x;
       cin>>x;
       vect.pb(x);
   }
   lli dp1[n],dp2[n];
   for(int i=0;i<n;i++)
    {
        dp1[i]=1;
        dp2[i]=1;
    }

   for(int i=1;i<n;i++)
   {
       for(int j=i-1;j>=0;j--)
       {
           if(vect[i]>vect[j]){
                dp1[i]=dp1[j]+1;
                break;
           }
       }
   }
   

   reverse(vect.begin(),vect.end());

   for(int i=1;i<n;i++)
   {
       for(int j=i-1;j>=0;j--)
       {
           if(vect[i]>vect[j]){
                dp2[i]=dp2[j]+1;
                break;
           }
       }
   }

   for(int j=0,k=n-1;j<n/2;j++,k--)
   {
       swap(dp2[j],dp2[k]);
   }

   for(int i=0;i<n;i++)
   {
        cout<<dp1[i]<<" "<<dp2[i]<<endl;   
   }

    lli maxz=INT_MIN;
    forn(i,n){
        int s=dp1[i]+dp2[i]-1;
        if(s>maxz)
        maxz=s;
    }

    cout<<maxz<<endl;
}