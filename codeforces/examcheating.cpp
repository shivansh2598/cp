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
        lli a,b;
        cin>>a>>b;
        lli n=abs(b-a);
        lli cnt=0;
        for(int i=1;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                if(i==n/i)
                cnt++;
                else
                {
                    cnt+=2;
                }
                
            }
            
        }

        cout<<cnt<<endl;
    }
}