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
        lli n;
        cin>>n;
        lli a,b,c,d;
        cin>>a>>b>>c>>d;
        lli minz = n*(a-b);
        lli maxz = n*(a+b);
        if(maxz<c-d || minz>c+d)
        {
            cout<<"No"<<endl;
        }
        else
        cout<<"Yes"<<endl;

    }
}