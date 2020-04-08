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

struct things{
    lli ti;
    lli xi;
    lli yi;
    double value; 
};

bool comp(things a,things b){
    if(a.ti==b.ti)
    return a.value>b.value;

    return a.ti<b.ti;
}

int main()
{
   lli n,d;
   cin>>n>>d;
   vector<things>vect;
   forn(i,n){
       lli t,x,y;
       cin>>t>>x>>y;
        things thing;
        thing.ti=t;
        thing.xi=x;
        thing.yi=y;
        thing.value=y;
        vect.push_back(thing);
   }

   sort(vect.begin(),vect.end(),comp);
   vector<things>v;
   v.push_back(vect[0]);
    forn(i,n-1){
        if(vect[i+1].ti!=vect[i].ti){
            v.push_back(vect[i+1]);
        }
    }


    lli day=v[0].yi;
    things mst=v[0];
    lli cost=v[0].xi;
    for(int i=1;i<v.size();i++)
    {
        if(day>=d)
        break;

        lli dayz=v[i].ti-(v[i-1].ti+1);
        day+=dayz*v[i-1].yi;

        if(v[i].value>mst.value)
        {
            mst=v[i];
            cost+=mst.xi;
        }

        day+=mst.yi;
        
    }

    cout<<cost<<endl;


  
    

}