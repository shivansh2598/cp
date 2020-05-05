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

vector<int> vect[200005];
bool visited[200005];
vector<int> path;
int min_path[200005];
unordered_map<int, int> mp;

int dfs(int x, int dest)
{
  visited[x] = true;
  int no = 300000;
  // cout << x << endl;
  if (x == dest)
  {
    min_path[x] = 1;
    return 1;
  }
  for (int child : vect[x])
  {

    if (visited[child])
    {
      int val = min_path[child];
      if(mp[x] != child)
      no = min(val, no);
    }
    else
    {
      int val = dfs(child, dest);
      if(mp[x]!=child)
      no = min(val, no);
    }
  }

  if (no == 300000)
  {
    min_path[x] = no;
  }
  else
  {
    min_path[x] = no + 1;
  }
  return min_path[x];
}

int main()
{
  lli n, m;
  cin >> n >> m;
  fr(i, 0, m)
  {
    int a, b;
    cin >> a >> b;
    vect[a].pb(b);
  }
  lli k;
  cin >> k;
  fr(i, 0, k)
  {
    int x;
    cin >> x;
    path.pb(x);
  }
  fr(i, 0, k - 1)
  {
    int a, b;
    a = path[i];
    b = path[i + 1];
    mp[a] = b;
  }
  dfs(path[0], path[k - 1]);
  int minz = 0, maxz = 0;
  fr(i, 0, k-1)
  {
    // cout<<min_path[path[i]] <<" ";
    if(min_path[path[i]]==300000)
    continue;
    else if(min_path[path[i]]<k-i)
    {
      minz++;
      maxz++;
    }
    else if(min_path[path[i]] == k-i)
    maxz++;

  }
  cout << minz << " " << maxz << endl;
}