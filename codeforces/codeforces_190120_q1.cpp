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
    lli t;
    cin>>t;
    
    for(lli p=0;p<t;p++)
    {
        lli n,f,c;
        unordered_map<lli,lli>m;
        cin>>n>>f>>c;
        for(lli i=0;i<c;i++)
        {
            lli x;
            cin>>x;
            m.insert({x,1});
        }
        lli j=0;
        bool found=false;
        while(true)
        {
            if((f-j>0)&&m.find(f-j)==m.end())
            {
                found=true;
                break;
            }

            else if(f+j<=n &&m.find(f+j)==m.end())
            {
                found=true;
                break;
            }
            j++;
        }
        if(found)
        cout<<j<<endl;
    }
}