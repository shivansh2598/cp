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
   lli x;
   cin>>x;
   lli y=sqrt(x);
   lli z=y;


   while(true)
   {
       lli i=0,j=0;
       while(x%(y-i)!=0)
       i--;

       while(x%(z+j)!=0)
       j++;


       lli a=y-i;
       lli b=z+j;

       lli temp=a*b;

       lli gd=__gcd(a,b);

       lli lcm=temp/gd;

       if(lcm==x)
       {
           cout<<max(a,b)<<endl;
           break;
       }

   }
}