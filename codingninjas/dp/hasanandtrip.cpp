#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli dp[50][25];

int find(int arr[], int n, int i, int di)
{
    // cout<<i<<" "<<di<<endl;
    if(i==n && arr[i]==1)
        return 0;
    
    if(i==n+1 && di==0)
        return 1;
    
    else if(i>n)
        return 0;
    
    if(dp[i][di]!=0)
        return dp[i][di];
    
    int k=arr[i];
    
    int sum=0;
    if(di==0 || k==1)
    {
        	sum=find(arr,n,i+1,di+1);
    }
    else{
        int a=find(arr,n,i+1,di+1);
        int b=find(arr,n,i+1,di-1);
        sum=a+b;
    }
    
    dp[i][di]=sum;
    return sum;
}

int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<50;i++)
        {
            for(int j=0;j<25;j++)
                dp[i][j]=0;
        }
        lli n,k;
        cin>>n>>k;
        cout<<"----------------------------------------"<<endl;
        cout<<n<<" "<<k<<endl;
        int total=2*n;
        int arr[total+2];
        for(int i=0;i<total;i++)
        {
            arr[i]=0;
        }
        bool err=false;
        for(int i=0;i<k;i++)
        {
            int x;
            cin>>x;
            cout<<x<<endl;
            if(x==0)
            {
                cout<<0<<endl;
                err=true;
            }
            x--;
            arr[x]=1;
        }
        if(!err)
        	cout<<find(arr, total-1, 0, 0)<<endl;
        // cout<<"-----------------------------------"<<endl;
    }
    return 0;
}
