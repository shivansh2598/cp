#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

void vprint(vector<int>&v)
{  for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<endl;}

void aprint(int *arr,int n)
{  for(int i=0;i<n;i++)cout<<arr[i]<<' ';cout<<endl;}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n,q;
    cin>>n>>q;
    vector<lli>v;
    for(lli w=0;w<n;w++)
    {
        lli x;
        cin>>x;
        v.push_back(x);
    }
    lli incr[n]={0};
    lli decr[n]={0};

    bool inc,dec;

    for(lli i=n-2;i>=0;i--)
    {
        if(i==n-2)
        {
            if(v[i+1]<v[i])
            {
                inc=true;
                dec=false;
                incr[i]=1;
            }

            else
            {
                dec=true;
                inc=false;
                decr[i]=1;
                
            }
            
        }

        else
        {
            if(inc && v[i+1]<v[i])
            {
                continue;
            }

            else if(inc && v[i+1]>v[i])
            {
                inc=false;
                dec=true;
                decr[i]=1;
            }

            else if(dec && v[i+1]>v[i])
            {
                continue;
            }

            else
            {
                dec=false;
                inc=true;
                incr[i]=1;
            }
            
        }
        
    }

    for(lli i=n-2;i>=0;i--){
        incr[i]+=incr[i+1];
        decr[i]+=decr[i+1];
    }

    // for(int i=0;i<n;i++)
    // cout<<incr[i]<<" ";
    // cout<<endl;

    // for(int i=0;i<n;i++)
    // cout<<decr[i]<<" ";
    // cout<<endl;


    for(lli i=0;i<q;i++)
    {
        lli l,r;
        cin>>l>>r;
        l--;
        r--;
        lli x,y;
        x=incr[l]-incr[r];
        y=decr[l]-decr[r];
        
        if(r!=n-1)
        {
            if(v[r]<v[r-1] && v[r]>v[r+1])
            x++;

            else if(v[r]>v[r-1] && v[r]<v[r+1])
            y++;
        }

        if(x==y)
        cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }
        
    }
}