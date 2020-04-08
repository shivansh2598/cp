#include<bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define for1(i, n) for (int i = 1; i <= int(n); ++i)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define ford(i, n) for (int i = int(n)-1; i >= 0; --i)
#define pb push_back
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

void vprint(vector<int>&v)
{  for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<endl;}

void aprint(int *arr,int n)
{  for(int i=0;i<n;i++)cout<<arr[i]<<' ';cout<<endl;}


int main()
{
   lli n;
   cin>>n;
   vector<lli>vect1,vect2;
   forn(i,n){
       lli x;
       cin>>x;
       vect1.pb(x);
   }
   forn(i,n){
       lli x;
       cin>>x;
       vect2.pb(x);
   }

   lli count=0;
    lli sum=0;
   for(int i=vect1.size()-1;i>=0;i--)
   {
       vect1[i]+=sum;
       if(vect1[i]==vect2[i])
       continue;

       else if(vect2[i]>vect1[i])
       {
            sum+=(vect2[i]-vect1[i]);
            count+=(vect2[i]-vect1[i])*(i+1);
       }
       else if(vect1[i]%vect2[i]==0)
            continue;
       else{
           lli nz=vect1[i]/vect2[i];
           nz++;
           sum+=((vect2[i]*nz)-vect1[i]);
           count+=((vect2[i]*nz)-vect1[i])*(i+1);
       }
   }
   cout<<count<<endl;
}