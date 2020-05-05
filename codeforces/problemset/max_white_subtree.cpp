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

struct hash_pair {
template <class T1, class T2> 
size_t operator()(const pair<T1, T2>& p) const {
   auto hash1 = hash<T1>{}(p.first); 
   auto hash2 = hash<T2>{}(p.second);
   return hash1 ^ hash2;}
};

bool color[200005];
vector<int>vect[200005];
int storebest[200005];
bool visited[200005];
int ans[200005];
int parent[200005];

int dfs(int root, int par = -1)
{
  visited[root] = true;
  parent[root] = par;
  int value = 0;
  int count = 0;
  for(int child : vect[root])
  {
    if(!visited[child])
    {
      count++;
      value+=dfs(child, root);
    }
  }  
  storebest[root] = value;
  if(value>0)
  {
    if(color[root] == 1)
    return value+1;
    else
    {
      return value-1;
    }
  }
  else
  {
    return value+color[root];
  }
  
}

void bfs(int root)
{
  queue<int>q;
  q.push(root);
  visited[root] = true;
  while(!q.empty())
  {
    int x = q.front();
    q.pop();
    if(parent[x] == -1)
    {
      ans[x] = storebest[x];
      ans[x]+= color[x] ? 1 : -1;
    }
    else
    {
      int temp = storebest[x];
      temp+=color[x] ? 1:-1;
      if(temp>=0)
      ans[x] = max(temp,ans[parent[x]]);
      else
      {
        ans[x] = temp;
        if(ans[parent[x]]>0)
        ans[x]+=ans[parent[x]];
      }
    }
    for(int child : vect[x])
    {
      if(!visited[child])
      {
        q.push(child);
        visited[child] = true;
      }
    }
  }
}

int main()
{
   lli n;
   cin>>n;
   fr(i,0,n)
   {
     int x;
     cin>>x;
     color[i] = x;
   }
   fr(i,0,n-1)
   {
     int a,b;
     cin>>a>>b;
     a--,b--;
     vect[a].push_back(b);
     vect[b].pb(a);
   }
   dfs(0);
   fr(i,0,n)
   visited[i]=false;
   bfs(0);
   fr(i,0,n)
   cout<<ans[i]<<" ";
   cout<<endl;
}