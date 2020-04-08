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

bool comp(lli a,lli b){
    return a>b;
}

int main()
{
    lli tc;
    cin>>tc;
    while(tc--)
    { 
        lli n,k;
        cin>>n>>k;
        vector<lli>vect;
        lli maxz=0;
        forn(i,n){
            lli x;
            cin>>x;
            if(x>maxz)
            maxz=x;
            vect.pb(x);
        }
        sort(vect.begin(),vect.end(),comp);
        lli l=0;
        lli r=maxz;
        lli ans=0;
        while(l<=r){
            lli mid=(l+r)/2;
            lli t=0;
            bool pos=true;
            forn(i,n){
                lli k1=vect[i]/mid;
                t+=k1;
                if(t>=k)
                break;
            }

            if(t<k)
            pos=false;

            if(pos){
                l=mid+1;
                ans=mid;
            }
            else{
                r=mid-1;
            }
        }

        cout<<ans<<endl;


    }
}