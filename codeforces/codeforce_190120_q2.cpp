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
   lli n;
   cin>>n;
   ld sum=0.000000000;
   for(lli i=1;i<=n;i++)
   {
       sum+=(1/ld(i));
   }

   cout<<fixed<<setprecision(8)<<sum<<endl;
}