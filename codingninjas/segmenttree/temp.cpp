#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main()
{
 	pair<lli,lli>arr[100005];
    lli n,d;
    cin>>n>>d;
    pair<lli,lli>temp=make_pair(0,0);
    for(int i=0;i<100002;i++)
        arr[i]=temp;
    
    for(int i=0;i<n;i++)
    {
        lli t,x,y;
        cin>>t>>x>>y;
        pair<lli,lli>p=arr[t];
        if(p.first==0 && p.second==0)
            arr[t]=make_pair(x,y);
        else
        {
            if(p.second < y || (p.second == y && p.first>x))
            {
                arr[t]=make_pair(x,y);
            }
        }
    }
    
    for(int i=1;i<100002;i++)
    {
        pair<lli,lli>p1=arr[i-1];
        pair<lli,lli>p2=arr[i];
        if(p1.second>=p2.second )
            arr[i]=arr[i-1];
        
    }
    lli cost=0;
    for(int i=1;i<100002;i++)
    {
         pair<lli,lli>p1=arr[i-1];
         pair<lli,lli>p2=arr[i];
        
        if(d<=0)
            break;
        
        if(p1.first != p2.first || p1.second != p2.second)
        {
            cost+=p2.first;
        }
        d-=p2.second;
        
    }
    
    cout<<cost<<endl;
}