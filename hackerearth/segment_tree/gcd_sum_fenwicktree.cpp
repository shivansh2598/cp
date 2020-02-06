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

int BIT[1000009]={0};
lli mod=pow(10,9)+7;
vector<int>vect;
void update(lli x,lli val,lli n){
    for(;x<=n;x+=x&-x){
        BIT[x]=(BIT[x]%mod+val%mod)%mod;
    }
}

lli query(lli x,lli y){
    x--;
    lli sum1=0;
    for(;x>0;x-=x&-x){
        sum1+=BIT[x];
    }
    lli sum2=0;
    for(;y>0;y-=y&-y)
        sum2+=BIT[y];
    return sum2-sum1;
}

void updz(lli x,lli curr,lli y,lli n){
    for(;x<=n;x+=x&-x){
        BIT[x]=(BIT[x]%mod - curr%mod + mod)%mod;
        BIT[x]=(BIT[x]%mod + y%mod)%mod;
    }
}

int main()
{
   lli n;
   cin>>n;
   vect.pb(-1);
   forn(i,n){
       int x;
       cin>>x;
       lli val=0;
       for1(j,x){
           val=(val%mod+__gcd(j,x)%mod)%mod;
       }
       vect.pb(val);
       update(i+1,val,n);
   }
   lli q;
   cin>>q;
   forn(i,q){
       char s;
       cin>>s;
       if(s=='C'){
           lli x,y;
           cin>>x>>y;
           cout<<query(x,y)<<endl;
       }else{
           int x,y;
           cin>>x>>y;
           lli sumz=0;
           lli curr=vect[x];
           for1(j,y){
            sumz=(sumz%mod+__gcd(j,y)%mod)%mod;
           }
           updz(x,curr,sumz,n);
           vect[x]=sumz;
       }
   }
}   