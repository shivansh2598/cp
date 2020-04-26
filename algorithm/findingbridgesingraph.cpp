#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
#define fr(i, k, n) for (lli i = k; i < lli(n); ++i)
#define pb push_back
using namespace std;

void vprint(vector<int>&v)
{  for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<endl;}

void aprint(int *arr,int n)
{  for(int i=0;i<n;i++)cout<<arr[i]<<' ';cout<<endl;}


int low[102];
int in[102];
vector<int>vect[102];
bool visited[102];
int timer;

void dfs(int root, int parent)
{
    visited[root]=true;
    in[root]=low[root]=timer;
    timer++;
    for(int child : vect[root])
    {
        if(child == parent)
        continue;

        else if(visited[child])
        {
            low[root] = min(in[child], low[root]);
        }
        else
        {
            dfs(child, root);
            if(low[root]<low[child])
            {
                cout<<"the edge "<<root<<" -> "<<child<<" is a bridge"<<endl;
            }
            else
            {
                low[root] = min(low[root], low[child]);
            }
        }
        
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int a, b;
        cin>>a>>b;
        vect[a].pb(b);
        vect[b].pb(a);
    }

    dfs(1,-1);
}