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
   lli n;
   cin>>n;
   bool zero=false;
   bool allzero=true;
   if(n==0)
   {
       cout<<"No"<<endl;
       return 0;
   }
   vector<int>arr;

   forn(i,n){
       int x;
       cin>>x;
       if(x==0)
       zero=true;
       arr.pb(x);
   }
   sort(arr.begin(),arr.end());
   string x;
   cin>>x;
//    bool gdbd=false;
   for(int i=0;i<x.length();i++)
   {
       int temp=x[i]-'0';
    //    auto ptr=lower_bound(arr.begin(),arr.end(),temp);
    //    
        if(temp!=arr[0] && temp!=arr[1])
        {
            cout<<"No"<<endl;
            return 0;
        }
        else if(temp!=0)
        allzero=false;

   }
   if(allzero && x.length()>1)
   {
       cout<<"No"<<endl;
       return 0;
   }

   if(zero && x.length()>1)
   {
       if(x[0]=='0')
       {
           cout<<"No"<<endl;
           return 0;
       }

   }

   if(n==1)
   {
       cout<<"Yes"<<endl;
       cout<<x.length()<<endl;
       return 0;
   }

   int a=arr[0];
   int b=arr[1];

    int sum=0;

    for(int i=1;i<x.length();i++)
    {
        if(!zero)
        sum+=pow(2,i);

        else if(i==1)
        {
            sum+=pow(2,i);
        }
        else
        {
            sum+=pow(2,i-1);
        }
    }

    // cout<<sum<<endl;

    for(int i=0;i<x.length();i++)
    {
        int te=x[i]-'0';
        if(te==a)
        continue;

        else if(te==b && a!=0)
        {
            // cout<<"hey"<<endl;
            sum+=pow(2,x.length()-(i+1));
        }
    }

    if(x.length()==1 && zero && x[0]!='0')
    sum+=1;

    cout<<"Yes"<<endl;
    cout<<sum+1<<endl;
}