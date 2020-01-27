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
   string s;
   cin>>s;
   unordered_map<int,int>m;
   lli i=0;
   lli k=0;
   for(lli j=0;j<s.length();j++)
   {
       if(s[j]=='L')
       i++;
       else
       {
           k--;
       }
   }

   cout<<i-k+1<<endl;
}