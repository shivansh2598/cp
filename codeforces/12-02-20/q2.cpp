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
    lli tc;
    cin>>tc;
    while(tc--)
    { 
        lli n,g,b;
        cin>>n>>g>>b;
        if(n<=g)
        {
            cout<<n<<endl;
            continue;
        }
        else if(g>=b)
        {
            cout<<n<<endl;
            continue;
        }
        else
        {
            lli val=0;
            if(n%2!=0)
            val = ((g+b)*ceil(ld(n)/(2*g))-(b));
            else
            {
                lli tt=n-((g+g)*ceil(ld(n)/(2*g))-(g));
                if(b>=g+tt){
                    val = ((g+b)*ceil(ld(n)/(2*g)))-(b);
                }
                else
                {
                    lli diff=(g+tt)-b;
                    val = ((g+b)*ceil(n/2))-(b-diff);
                }
                
            }
            cout<<val<<endl;
            
        }


        
    }
}