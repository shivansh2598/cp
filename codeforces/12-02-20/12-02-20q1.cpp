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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli tc;
    cin>>tc;
    while(tc--)
    { 
        string s;
        cin>>s;
        bool first=false;
        lli count=0;
        for (int i = s.length()-1;i>=0;i--)
        {
            if(s[i]=='1')
            break;

            count++;
        }

        // cout<<count<<" count"<<endl;
        lli sss=0;
        forn(i,s.length()-count){
            if(!first && s[i]=='0')
            continue;

            else if(!first && s[i]=='1')
            first=true;

            else if(s[i]=='0')
            sss++;

        }
        cout<<sss<<endl;

    }
}