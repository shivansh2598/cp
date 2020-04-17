#include<bits/stdc++.h>
using namespace std;
vector<int>vect[5002];
vector<int>trans[5002];
unordered_map<int, int>mp;
stack<int>st;
bool visited[5002];

void dfs(int x)
{
    visited[x]=true;
    
    for(int i=0;i<vect[x].size();i++)
    {
        if(!visited[vect[x][i]])
            dfs(vect[x][i]);
    }
    
    st.push(x);
}

void dfs1(int x, int count)
{
    visited[x]=true;
    mp.insert({x,count});
    
    for(int i=0;i<trans[x].size();i++)
    {
        if(!visited[trans[x][i]])
            dfs1(trans[x][i],count);
    }
}

bool dfs2(int x, int state)
{
    if(mp[x]!=state)
        return false;
    
    visited[x]=true;
    
    bool temp=true;
    for(int i=0;i<vect[x].size();i++)
    {
        if(!visited[vect[x][i]])
        {
            temp=temp&dfs2(vect[x][i],state);
        }
    }
    
    return temp;
}

int main()
{
    while(true){
	int n;
    cin>>n;
    if(n==0)
        break;
    
    int e;
    cin>>e;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        vect[a].push_back(b);
        trans[b].push_back(a);
    }
    
    for(int i=0;i<=n;i++)
        visited[i]=false;
    
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
            dfs(i);
    }
    
    for(int i=0;i<=n;i++)
    {
        visited[i]=false;
    }
    
    int count = 1;
    
    while(!st.empty())
    {
        int x = st.top();
        st.pop();
        if(visited[x])
            continue;
        
        dfs1(x,count);
        
        count++;
    }
    
    bool poss[count+1];
    
    
    for(int i=0;i<=n;i++)
    {
        visited[i]=false;
    }
    
    for(int i=0;i<=count;i++)
        poss[i]=true;
    
    
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            bool temp=dfs2(i, mp[i]);
            poss[mp[i]]=temp;
        }
    }
    // int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(poss[mp[i]])
        {
            cout<<i<<" ";
        }
    }
    
    cout<<endl;
    for(int i=0;i<=n;i++)
    {
        vect[i].clear();
        trans[i].clear();
    }
    
    mp.clear();
    }
    return 0;
    
}
