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


lli merge(lli arr[],lli l, lli mid, lli r){
    lli i=l,j=mid,k=0;
    lli temp[r-l+1];
    lli sum=0;
    while(i<mid && j<=r)
    {
        if(arr[i]<arr[j])
        {
            temp[k++]=arr[i++];
            sum+=arr[i-1]*(r-j+1);
        }
        else if(arr[j]<arr[i])
        temp[k++]=arr[j++];

        else
        {
            temp[k++]=arr[i++];
            temp[k++]=arr[j++];
        }
        
    }
    while(i<mid)
    temp[k++]=arr[i++];
    while(j<=r)
    temp[k++]=arr[j++];

    k=0;

    for(lli i=l;i<=r;i++)
    {
        arr[i]=temp[k++];
    }

    return sum;
}

lli mergesort(lli arr[],lli l,lli r)
{
    lli sum=0;
    if(l<r){
        lli mid=(l+r)/2;
        lli a=mergesort(arr,l,mid);
        lli b=mergesort(arr,mid+1,r);
        lli c=merge(arr,l,mid+1,r);
        sum=a+b+c;
    }

    return sum;
}

int main()
{
    lli tc;
    cin>>tc;
    while(tc--)
    { 
        lli n;
        cin>>n;
        lli arr[n];
        forn(i,n){
            cin>>arr[i];
        }

        cout<<mergesort(arr,0,n-1)<<endl;
    }
}