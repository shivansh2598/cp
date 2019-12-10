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
        lli key;
       cin>>key;
       lli qr;
       cin>>qr;
       vector<lli>vect;
       for(lli w=0;w<n;w++)
       {
           lli e = 0;
           cin>>e;
           vect.push_back(e);
       }

       for ( int r=vect.size()-1 ; r>=0; r--)
       {
           vect[r] = vect[r]%1000008 + 1000008*(vect[(vect.size()+(r-(key%vect.size())))%vect.size()]%1000008);
       }

       for( int r=0;r<vect.size();r++)
       vect[r]=vect[r]/1000008;

       vector<int>queries;
       for(int y=0;y<qr;y++)
       {
           int yy;
           cin>>yy;
           queries.push_back(yy);
       }

       for(int o=0;o<qr;o++)
       {
           cout<<vect[queries[o]]<<endl;
       }
   
}