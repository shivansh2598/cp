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
        lli n,m;
        cin>>n>>m;
        lli hp=m,lp=m;
        lli tp=0;
        bool poss=true;
        forn(i,n)
        {
            lli tc,lc,hc;
            cin>>tc>>lc>>hc;
            if(!poss)
            continue;
            lli tf=tc;
            lli lf,hf;
            tc=tc-tp;
            lf=lp-tc;
            hf=hp+tc;
            // cout<<"lc "<<lc<<" "<<"hc "<<hc<<endl;
            if(hc<lf || lc>hf)
            {
                poss=false;
            }
            else if(lc<=lf && hc>=hf)
            {
                hp=hf;
                lp=lf;
                tp=tf;
                // cout<<"lp "<<lp<<" "<<"hp "<<hp<<endl;
                continue;
            }
            else if(lc>=lf && hc<=hf)
            {
                hp=hc;
                lp=lc;
                tp=tf;
                // cout<<"lp "<<lp<<" "<<"hp "<<hp<<endl;
                continue;
            }
            else
            {
                hp=min(hc,hf);
                lp=max(lc,lf);
                tp=tf;
                // cout<<"lp "<<lp<<" "<<"hp "<<hp<<endl;
            } 

            
 

        }
        if(poss)
        cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }
        
            continue;
    }
}