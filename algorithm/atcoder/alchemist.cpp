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
   multimap<double,double>m;
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
       double x;
       cin>>x;
       m.insert({x,0});
   }

   while(m.size()>1)
   {
      int count=0;
      double sum=0;
      for(auto i=m.begin();i!=m.end();i++)
      {
         if(count==2)
         break;
         sum+=i->first;
         count++;
      }

      m.erase(m.begin());
      m.erase(m.begin());

      m.insert({sum/2,0});
   }

   cout<<m.begin()->first<<endl;
}