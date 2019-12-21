#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define infinity INT_MAX


int main()
 {
    lli t;
    cin >> t;
    for (int i=0;i<t;i++)
    {
        lli n;
        cin>>n;
        vector<int>vect;
        vector<int>dp;
        for(int j=0;j<n;j++)
        {
            lli p;
            cin>>p;
            vect.push_back(p);
            dp.push_back(1);
        }
        
        for(int j=n-2;j>=0;j--)
        {
            for(int k=j+1;k<n;k++)
            {
                if(vect[j]<vect[k])
                {
                    
                    if(dp[j]<dp[k]+1)
                    dp[j]=dp[k]+1;
                }
            }
        }
        
        int max = 0;
        
        for(int j=0;j<n;j++)
        {
            if(dp[j]>max)
            max=dp[j];
        }
        cout<<max<<endl;
    }
	return 0;
}
