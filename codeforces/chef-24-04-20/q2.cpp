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


int main()
{
    lli tc;
    cin>>tc;
    while(tc--)
    { 
        lli x, r, a, b;
        cin>>x>>r>>a>>b;
        lli diff = abs(b-a);
        lli num = diff*x;
        lli den = max(a,b);
        lli no = num / den;
        if(no==0)
        cout<<no<<endl;
        else if(num % den == 0)
        {
            cout<<no-1<<endl;
        }
        else
        {
            cout<<no<<endl;
        }
        
    }
}