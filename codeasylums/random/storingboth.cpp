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
   for(int q=0;q<t;q++)
   {
       lli n;
       cin>>n;
       vector<int>vect;
       for(lli w=0;w<n;w++)
       {
           int e=0;
           cin>>e;
           vect.push_back(e);
       }

       for(int r=0;r<vect.size();r++)
       {
           vect[vect[r]%vect.size()]=vect[vect[r]%vect.size()]+vect.size()*r;
       }

       for(int r=0;r<vect.size();r++)
       {
           vect[r]=vect[r]/vect.size();
       }

       for(int r=0;r<vect.size();r++)
       cout<<vect[r]<<" ";
       cout<<endl;
   }
}