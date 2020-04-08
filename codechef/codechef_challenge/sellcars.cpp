#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
#define fr(i, k, n) for (lli i = k; i < lli(n); ++i)
#define pb push_back
using namespace std;

void vprint(vector<int>&v)
{  for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<endl;}

void aprint(int *arr,int n)
{  for(int i=0;i<n;i++)cout<<arr[i]<<' ';cout<<endl;}

bool compare(lli x, lli y)
{
    return x>y;
}

lli m=pow(10,9)+7;

int main()
{
    lli tc;
    cin>>tc;
    while(tc--)
    { 
        lli n;
        cin>>n;
        vector<lli>vect;
        fr(i,0,n)
        {
            lli x;
            cin>>x;
            vect.pb(x);
        }
        sort(vect.begin(),vect.end(),compare);
        lli sum=0;
        fr(i,0,n)
        {   
            sum=(sum+(max(vect[i]-i,lli(0))))%m;
        }
        cout<<sum<<endl;
    }
}