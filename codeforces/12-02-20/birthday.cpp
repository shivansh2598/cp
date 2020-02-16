#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
#define forn(i, n) for (lli i = 0; i < lli(n); ++i)
#define for1(i, n) for (lli i = 1; i <= lli(n); ++i)
#define fore(i, l, r) for (lli i = lli(l); i <= lli(r); ++i)
#define ford(i, n) for (lli i = lli(n) - 1; i >= 0; --i)
#define pb push_back
#define vectvalue \
    lli x;        \
    cin >> x;     \
    vect.pb(x)
using namespace std;

void vprint(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;
}

void aprint(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main()
{
    lli tc;
    cin >> tc;
    while (tc--)
    {
        lli n;
        cin >> n;
        vector<lli> vect,vect1;
        forn(i, n)
        {
            lli x;
            cin>>x;
            vect.pb(x);
            vect1.pb(x);
        }
        lli mini=LONG_LONG_MAX;
        lli maxi=-1;
        forn(i,n){
            if(vect[i]>=0)
            {
                if((i-1>=0 && vect[i-1]==-1)||(i+1<n && vect[i+1]==-1))
                {
                    if(vect[i]>maxi)
                    maxi=vect[i];

                    if(vect[i]<mini)
                    mini=vect[i];
                }
            }
        }
        lli valz=0,valz1=0;
        lli maxz=-1,maxz1=-1;
        if(maxi!=-1){
        valz=ceil(ld(maxi+mini)/2);
        valz1=floor(ld(maxi+mini)/2);
        }
        forn(i,n)
        {
            if(vect[i]==-1)
            vect[i]=valz;
        }
        forn(i,n-1){
            if(abs(vect[i+1]-vect[i])>maxz)
            maxz=abs(vect[i+1]-vect[i]);
        }
        forn(i,n)
        {
            if(vect1[i]==-1)
            vect1[i]=valz1;
        }
        forn(i,n-1){
            if(abs(vect1[i+1]-vect1[i])>maxz1)
            maxz1=abs(vect1[i+1]-vect1[i]);
        }
        if(min(maxz,maxz1)==maxz){
            cout<<maxz<<" "<<valz<<endl;
        }
        else
        {
            cout<<maxz1<<' '<<valz1<<endl;
        }
    }
}