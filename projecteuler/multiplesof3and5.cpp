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
        int n;
        cin>>n;
        int sum=0;

        for(int j=0;j<n;j++)
        {
            if(j%3==0 || j%5==0)
            sum+=j;
        }

        cout<<sum<<endl;
    }
}