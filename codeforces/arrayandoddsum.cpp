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
    lli tc;
    cin>>tc;
    while(tc--)
    { 
        lli n;
        cin>>n;
        vector<int>a;
        bool odd=false,even=false;
        forn(i,n){
            int x;
            cin>>x;
            if(x%2==0)
            even=true;
            else
            odd=true;
            a.pb(x);
        }
        if(even&odd)
        cout<<"YES"<<endl;
        else if(odd && n%2!=0)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
}