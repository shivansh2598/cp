#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define minz 0;

vector<int>vect;
int dp[500][500];

int findways(int n,int m)
{
    if(m<0)
    return minz;
    
    if(n<0)
    return minz;
    
    if(n==0)
    return 1;
    
    if(dp[n][m]!=-1)
    return dp[n][m];
    
    int val1=findways(n,m-1);
    int val2=findways(n-vect[m],m);
    
    if(val1>=0&&val2>=0)
    {
        dp[n][m]=val1+val2;
    }
    
    else if(val1>=0)
    {
        dp[n][m]=val1;
    }
    
    else if (val2>=0)
    dp[n][m]=val2;
    
    else 
    dp[n][m]=0;
    
    
    return dp[n][m];
}


int main()
{
    lli t;
    cin>>t;
    for(int k=0;k<t;k++)
    {
        lli m;
        cin>>m;
        for(int j=0;j<m;j++)
        {
            int f;
            cin>>f;
            vect.push_back(f);
        }
        
        lli n;
        cin>>n;
        for(int s=0;s<=n+1;s++)
        {
            for(int q=0;q<=m+1;q++)
            {
                dp[s][q]=-1;
            }
        }
        cout<<findways(n,m-1)<<endl;
        vect.clear();
    }
    
}
