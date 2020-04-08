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

bool checkprime(lli x)
{
    int cnt=0;
    fr(i,2,sqrt(x)+1)
    {
        if(x%i==0)
        {
            cnt++;
            break;
        }
    }
    if(cnt==0)
    return true;
    else
    return false;

}


lli find(lli x)
{
    lli cnt=0;
    while(x!=1)
    {
        if(checkprime(x))
        {
            cnt++;
            x=1;
        }
        else
        {
            fr(i,2,sqrt(x)+1)
            {
                if(x%i==0)
                {
                    cnt++;
                    x/=i;
                    break;
                }
            }
        }
        
    }

    return cnt;
}

int main()
{
    lli tc;
    cin>>tc;
    while(tc--)
    { 
        lli x,k;
        cin>>x>>k;
        if(k>=30)
        cout<<0<<endl;
        else
        {
            lli cnt=find(x);
            // cout<<cnt<<endl;
            if(cnt>=k)
            cout<<1<<endl;
            else
            {
                cout<<0<<endl;
            }
            
        }

        
    }
}