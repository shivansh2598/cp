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
   int n;
   cin>>n;

   vector<int>v;
   ld mult=1;
   ld fsum=0;
   for(int i=0;i<n;i++)
   {
       int x;
       cin>>x;
       v.push_back(x);
       mult*=x;
   }

   if(n==1)
   {
       cout<<v[0]<<endl;
       return 0;
   }

   for(int i=0;i<n;i++)
   {
       fsum+=mult/v[i];
   }

   cout<<mult/fsum<<endl;


}