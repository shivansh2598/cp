#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
#define forn(i, n) for (lli i = 0; i < lli(n); ++i)
#define for1(i, n) for (lli i = 1; i <= lli(n); ++i)
#define fore(i, l, r) for (lli i = lli(l); i <= lli(r); ++i)
#define ford(i, n) for (lli i = lli(n) - 1; i >= 0; --i)
#define pb push_back
#define vectvalue lli x;cin >> x;vect.pb(x)
using namespace std;

void vprint(vector<int>&v)
{  for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<endl;}

void aprint(int *arr,int n)
{  for(int i=0;i<n;i++)cout<<arr[i]<<' ';cout<<endl;}

lli dp[1002][1002];

// Returns the maximum value that can be put in a knapsack of capacity W 
int maxval(int W, vector<int>&wt, vector<int>&val, int n) 
{ 
   int i, w; 
//    int K[n+1][W+1]; 
  
   // Build table K[][] in bottom up manner 
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               dp[i][w] = 0; 
           else if (wt[i-1] <= w) 
                 dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]],  dp[i-1][w]); 
           else
                 dp[i][w] = dp[i-1][w]; 
       } 
   } 
  
   return dp[n][W]; 
} 

bool compare(int a, int b){
    return a>b;
}

int main()
{
   lli n,z;
   cin>>n>>z;
   lli x,y;
   cin>>x>>y;
   vector<int>cost,pages;
   forn(i,n)
   {
       int x;
       cin>>x;
       cost.pb(x);
   }
   forn(i,n)
   {
       int x;
       cin>>x;
       pages.pb(x);
   }

   int valz=maxval(z,cost,pages,n);

//    for(int i=0;i<=n;i++)
//    {
//        for(int j=0;j<=z;j++)
//        cout<<dp[i][j]<<" ";
//        cout<<endl;
//     }
    vector<int>selected;
    int a=n;
    int b=z;
    lli sumz=0;
    while(valz)
    {
        int t1=dp[a-1][z];
        int t2=dp[a-1][z-cost[a-1]]+pages[a-1];
        if(t2>t1)
        {
            selected.pb(pages[a-1]);
            b+=b+cost[a-1];
            sumz+=pages[a-1];
            valz-=pages[a-1];
        }
        a--;
    }
    sort(selected.begin(),selected.end(),compare);
    if(selected.size()==0)
    {
        cout<<0<<endl;
        return 0;
    }

    else if(selected.size()==1)
    {
        cout<<selected[0]*max(x,y)<<endl;
    }
    else
    {
        lli suma=selected[0]+selected[1];
        sumz-=suma;
        suma=selected[0]*max(x,y);
        suma+=selected[1]*min(x,y);
        cout<<sumz+suma<<endl;
    }
    


}