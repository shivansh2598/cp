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
        lli a,b,c,d;
        cin>>a>>b>>c>>d;
        lli maxz=max(a,max(b,c));
        lli sumz=3*maxz-(a+b+c);
        if(sumz>d){
            cout<<"NO"<<endl;
            continue;
        }
        d=d-sumz;
        if(d%3==0)
        cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }
        
    }
}