#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
#define fr(i, k, n) for (lli i = k; i < lli(n); ++i)
#define pb push_back
using namespace std;

void vprint(vector<int> &v)
{
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << ' ';
  cout << endl;
}

void aprint(int *arr, int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << ' ';
  cout << endl;
}

struct hash_pair
{
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2> &p) const
  {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};

set<int>graph[100005];
set<int>components;

void dfs(int x)
{
  if(components.count(x))
  components.erase(x);

  vector<int>nxts;
  for(int u : components){
    if(graph[x].count(u))
    continue;
    else
    {
      nxts.pb(u);
    }
    
  }
  for(int u: nxts)
  components.erase(u);
  for(int u: nxts)
  dfs(u);
}

int main()
{
  int n, m;
  cin >> n >> m;
  fr(i, 0, m)
  {
    int a, b;
    cin>>a>>b;
    a--, b--;
    graph[a].insert(b);
    graph[b].insert(a);
  }
  fr(i, 0, n)
  {
    components.insert(i);
  }
  int cmpt = 0;
  while(!components.empty())
  {
    cmpt++;
    dfs(*components.begin());
  }
  cout << cmpt-1 << endl;
}