#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int dp[101][101][101];


int find(string s1,string s2,int k, int i,int j, int len)
{
    if(len==k)
    {
        return 0;
    }
    if(i==s1.length() || j==s2.length())
        return INT_MIN;
    
    if(dp[i][j][len]!=-1)
        return dp[i][j][len];
    
    
    if(s1[i]==s2[j])
    {
        dp[i][j][len]=max(int(s1[i])+find(s1,s2,k,i+1,j+1,len+1),find(s1,s2,k,i+1,j+1,len));
    }
    else
    {
        dp[i][j][len]=max(find(s1,s2,k,i+1,j,len),find(s1,s2,k,i,j+1,len));
    }
    
    return dp[i][j][len];
}


int main()
{
    int t;
    cin>>t;
    while(t--){
        // vector<string>vect;
        for(int i=0;i<101;i++)
        {
            for(int j=0;j<101;j++)
            {
                for(int k=0;k<101;k++)
                dp[i][j][k]=-1;
            }
        }
        string s1,s2;
        cin>>s1>>s2;
        lli k;
        cin>>k;
        find(s1,s2,k,0,0,0);
        int mz=0;
        for(int i=0;i<101;i++)
        {
            for(int j=0;j<101;j++)
            {
                if(dp[i][j][0]>mz)
                mz=dp[i][j][0];
            }
        }

        cout<<mz<<endl;


        // for(int i=0;i<vect.size();i++)
        // {
        //     int k=0;
        //     for(int j=0;i<vect[i].length();j++)
        //     {
        //         k+=vect[i][j];
        //     }
        //     if(k>mz)
        //         mz=k;
        // }
        // cout<<mz<<endl;
    }
    return 0;
}
