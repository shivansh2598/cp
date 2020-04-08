#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

struct job
{
    lli s;
    lli f;
    lli p;
};

vector<struct job>vect;
vector<lli>fin;

bool compare(struct job j1, struct job j2)
{
    if(j1.f==j2.f)
        return j1.s<j2.s;
    
    return j1.f<j2.f;
}

int main()
{
    lli n;
    cin>>n;
   
    for(int i=0;i<n;i++)
    {
        struct job j;
        cin>>j.s>>j.f>>j.p;
        vect.push_back(j);
        fin.push_back(j.f);
    }
    
    sort(vect.begin(),vect.end(),compare);
    sort(fin.begin(),fin.end());
    
    lli dp[1000005];
    
    dp[0]=vect[0].p;
    
    
    for(int i=1;i<n;i++)
    {
        int val=vect[i].s;
        auto ptr=upper_bound(fin.begin(),fin.end(),val);
        int index=ptr-fin.begin();
        index--;
        dp[i]=max(vect[i].p+dp[index], dp[i-1]);
    }
    
    cout<<dp[n-1]<<endl;
    
    return 0;
}