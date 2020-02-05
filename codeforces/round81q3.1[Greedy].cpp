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
        string s,t;
        cin>>s>>t;
        int ans=1;
        int p=0;
        vector<int>pos[26];
        forn(i,s.size())
            pos[s[i]-'a'].pb(i);
        forn(i,t.size()){
            int tar=t[i]-'a';
            if(pos[tar].empty()){
                cout<<-1<<endl;
                goto next;
            }
            auto res=lower_bound(pos[tar].begin(),pos[tar].end(),p);
            if(res==pos[tar].end()){
                ans++;
                p=0;
                i--;
            }else{
                p=*res;
                p++;
            }
        }
        cout<<ans<<endl;
        next:;
    }
}