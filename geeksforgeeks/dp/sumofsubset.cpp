#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define infinity INT_MAX

vector<int>vect;
int dp[100005][102];

bool ispossible(lli sum, lli n, lli sum1)
{
    // cout<<"sum1 "<<sum<<" "<<"sum2 "<<sum1<<endl;
    
    if (n<0)
    return false;
    
    if(sum<0)
    return false;
    
    if(sum==sum1)
    return true;
    
    if(dp[sum][n]!=-1)
    return dp[sum][n];
    
    bool x = ispossible(sum,n-1,sum1);
    bool y = ispossible(sum-vect[n],n-1,sum1+vect[n]);
    
    dp[sum][n]=x|y?1:0;
    return dp[sum][n];
}

int main()
 {
	lli t;
	cin>>t;
	for(int k=0;k<t;k++)
	{
	    lli n;
	    cin>>n;
	    
	    lli sum = 0;
	    
	    for(int q=0;q<n;q++)
	    {
	        int f;
	        cin>>f;
	        vect.push_back(f);
	        sum+=f;
	    }
	    
	   // cout<<sum<<endl;
	    
	    for(int q=0;q<=sum;q++)
	    {
	        for(int y=0;y<n;y++)
	        dp[q][y]=-1;
	    }
	    
	    
	    string out;
	    if(sum%2!=0)
	    out="NO";
	    else
	    out = ispossible(sum,n-1,0)?"YES":"NO";
	    cout<<out<<endl;
	    vect.clear();
	}
	return 0;
}
