#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
#define fr(i, k, n) for (lli i = k; i < lli(n); ++i)
#define pb push_back
using namespace std;

void vprint(vector<int>&v)
{  for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<endl;}

void aprint(int *arr,int n)
{  for(int i=0;i<n;i++)cout<<arr[i]<<' ';cout<<endl;}


int main()
{
   lli n,k;
   cin>>n>>k;
   vector<int>vect;
   fr(i,0,n){
      int x;
      cin>>x;
      vect.pb(x);
   }
 
   sort(vect.begin(), vect.end());
    lli sum=0;
    vector<lli>temp;
    temp.push_back(0);
    fr(j,1,k)
    {
        sum+=vect[j-1];
        int temz=j*vect[j] - sum;
        int tmp=temz+temp[(j-1)];
        temp.push_back(tmp);
    }
    
    lli oldval=temp[k-1];
    sum+=vect[k-1];
    temp.clear();
    cout<<oldval<<endl;
    lli minz=oldval;
    int j=0;
    for(int i=k;i<n;i++,j++)
    {
        sum-=vect[j];
        lli newval=oldval+((k-1)*(vect[j]))+((k-1)*vect[i])-(2*sum);
        
        cout<<newval<<endl;
        
        if(newval<oldval)
            minz=newval;

        sum+=vect[i];
        oldval=newval;
    }
    
    cout<<minz<<endl;

}