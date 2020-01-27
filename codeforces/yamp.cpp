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
        lli count=0;
        lli temp=b;
        while(temp!=0)
        {
            temp/=10;
            count++;
        }

        lli x=pow(10,count)-1;
        if(b<x)
        count--;
        
        lli ans=a*count;
        cout<<ans<<endl;

    }
}