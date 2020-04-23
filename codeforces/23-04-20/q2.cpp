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
        lli n,k;
        cin>>n>>k;
        bool ispeak[n];
        for(int i=0;i<n;i++)
        ispeak[i]=false;
        vector<lli>vect;
        fr(i,0,n)
        {
            lli x;
            cin>>x;
            vect.pb(x);
        }
        fr(i,1,n-1)
        {
            if(vect[i]>vect[i-1] && vect[i]>vect[i+1])
            ispeak[i]=true;
        }

        lli mxval=0;
        lli ans = 1;

        for(int i=0;i<k;i++)
        {
            if(i==0 || i==k-1)
            continue;
            else
            {
                if(ispeak[i])
                    mxval++;
            }
            
        }
        int j=k;
        lli tempz = mxval;
        for(int i=1;j<n;i++,j++)
        {
            if(ispeak[i])
            tempz--;

            if(ispeak[j-1])
            tempz++;

            if(tempz>mxval)
            {
                mxval = tempz;
                ans  = i+1;
            }
        }

        cout<< mxval + 1 << " "<< ans <<endl;
    }
}