#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define infinity INT_MAX

int dp[2600][52];

int findmin(vector<int>&vect,int i,int n,int s1,int s2,int miz)
{
    if(i>=n)
    return INT_MAX;
    
    if(i==n-1)
    return abs(s1-s2);
    
    if(dp[s1][i]!=-1)
    return dp[s1][i];
    
    int minz=abs(s1-s2);
    if(minz>miz)
    return INT_MAX;
    
    int left=findmin(vect,i+1,n,s1+vect[i],s2-vect[i],minz);
    int right=findmin(vect,i+1,n,s1,s2,minz);
    
    
    dp[s1][i]=min(minz,min(left,right));
    return dp[s1][i];
    
    
}

int main()
 {
	int t;
	cin>>t;
	for(int z=0;z<t;z++)
	{
	    int n;
	    cin>>n;
	    vector<int>vect;
	    int sum=0;
	    for(int i=0;i<n;i++)
	    {
	        int x;
	        cin>>x;
	        vect.push_back(x);
	        sum+=x;
	    }
	    
	    for(int i=0;i<=sum;i++)
	    {
	        
	            for(int k=0;k<=n;k++)
	            {
	                dp[i][k]=-1;
	            }
	        
	    }
	    
	    int min=findmin(vect,0,n,0,sum,INT_MAX);
	    cout<<min<<endl;
	    
	}
	return 0;
}
