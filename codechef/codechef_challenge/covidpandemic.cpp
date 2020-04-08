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
        int minz=INT_MAX;
        int a=0;
        int b=0;
        int cnt=0;
        bool doo=false;
        fr(i,0,n)
        {
            int x;
            cin>>x;
            if(x==1 && doo)
            {
                a=b;
                b=i;
                int diff=b-a;
                if(diff<minz)
                minz=diff;
                cnt++;
            }
            else if(x==1 && !doo)
            {
                b=i;
                doo=true;
                cnt++;
            }
        }
        if(cnt==1)
        cout<<"YES"<<endl;
        else
        {
            if(minz<6)
            cout<<"NO"<<endl;
            else
            {
                cout<<"YES"<<endl;
            }
            
        }
        

    }
}