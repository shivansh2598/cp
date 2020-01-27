#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

void vprint(vector<int>&v)
{  for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<endl;}

void aprint(int *arr,int n)
{  for(int i=0;i<n;i++)cout<<arr[i]<<' ';cout<<endl;}

lli nCrModp(lli n, lli r, lli p) 
{ 

    lli C[r+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; // Top row of Pascal Triangle 
  
    for (lli i = 1; i <= n; i++) 
    { 
       
        for (lli j = min(i, r); j > 0; j--) 
   
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
} 


int main()
{
   lli n,m;
   cin>>n>>m;
   lli p=pow(10,9)+7;
   lli val=nCrModp(n+m-1,m,p);
   lli valz=(val*val)%p;
   lli val1=(n*(n-1))/2;
   val1=val1%p;
   lli ans=(valz-val1+p)%p;
   cout<<ans<<endl;
}