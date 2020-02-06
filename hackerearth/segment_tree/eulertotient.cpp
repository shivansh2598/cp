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

lli phi[100006];

void computeTotient(){
    forn(i,100000)
        phi[i]=i;
    for(int i=2;i<100000;i++){
        if(phi[i]!=i)
            continue;
        phi[i]=i-1;
        for(int j=2*i;j<100000;j+=i){
            phi[j]=phi[j]*(i-1);
            phi[j]/=i;
        }
    }
}

int main()
{
   computeTotient();
   int q;
   cin>>q;
   forn(i,q){
       int x;
       cin>>x;
       cout<<phi[x]<<endl;
   }
}