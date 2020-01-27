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
        long double n,d;
        cin>>n>>d;
        lli temp1=ceil(sqrt(d));
        temp1-=1;
        lli temp2=sqrt(d);
        temp2-=1;
        lli val1=temp1+ceil(float(d)/(temp1+1));
        lli val2=temp2+ceil(float(d)/(temp2+1));
        if(val1<=n || val2<=n)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
}