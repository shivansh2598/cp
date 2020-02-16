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


int main()
{
   lli n,m;
   cin>>n>>m;
   unordered_map<string,int>mapz;
   vector<string>vect;
   forn(i,n)
   {
       string x;
       cin>>x;
       string rev=x;
       reverse(rev.begin(),rev.end());
       vect.pb(x);
       if(mapz.find(rev)!=mapz.end())
       {
           mapz[rev]=2;
           mapz.insert({x,2});
       }
       else
       {
           mapz.insert({x,1});
       }
   }
   string f1="";
   string f2="";
   string mid="";
   bool found=false;
   lli count=0;
    forn(i,n){
       string str=vect[i];
       string temp=str;
       reverse(temp.begin(),temp.end());
       if(mapz[str]==2){
           mapz[str]=0;
           mapz[temp]=0;
           f1+=str;
           f2=temp+f2;
           count+=2*m;
       }
       else if(mapz[str]==1 && !found){
            if(str==temp)
            {
                count+=m;
                mid=str;
                found=true;
            }
       }
    }

    cout<<count<<endl;
    cout<<f1+mid+f2<<endl;
}