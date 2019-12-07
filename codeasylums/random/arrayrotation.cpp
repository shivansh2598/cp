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
           lli e = 0;
           cin>>e;
           vect.push_back(e);
       }

       lli key;
       cin>>key;

       for ( int r=0 ; r<vect.size(); r++)
       {
           vect[r] = vect[r]%10000 + 10000*(vect[(r+key)%vect.size()]%10000);
       }

       for( int r=0;r<vect.size();r++)
       cout<<vect[r]/10000<<" ";
       cout<<endl;
   }
}