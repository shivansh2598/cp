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
    for(lli i=0;i<t;i++)
    { 
        lli sum=0;
        lli n;
        cin>>n;
        int a=1;
        int b=2;
        sum+=b;

        int c=a+b;

        while(c<=n)
        {
            a=b;
            b=c;
            c=a+b;
            if(c%2==0)
            sum+=c;
        }
        
        cout<<sum<<endl;

    }
}