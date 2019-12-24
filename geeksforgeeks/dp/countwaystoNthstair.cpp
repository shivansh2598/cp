#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define infinity INT_MAX

lli dp[1000009];

int main()
 {
	lli t;
	cin>>t;
	for(int z=0;z<t;z++)
	{
	    lli n;
	    cin>>n;
	    for(int i=0;i<=n;i++)
	    {
	        dp[i]=0;
	    }
	    
	    dp[0]=0;
	    dp[1]=1;
	    dp[2]=2;
	    dp[3]=2;
	    dp[4]=3;
	    dp[5]=3;
	    
	    for(int i=6;i<=n;i++)
	    {
	        if(i%2==0)
	            dp[i]=dp[i-1]+1;
	        else
	            dp[i]=dp[i-1];
	    }
	    
	    
	    cout<<dp[n]<<endl;
	}
}
