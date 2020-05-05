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

vector<int> graph[200005];
vector<int> trans[200005];
vector<int> path;
int dist[200005];
bool visited[200005];

void bfs(int root)
{
  dist[root] = 0;
  queue<int> q;
  visited[root] = true;
  q.push(root);
  while (!q.empty())
  {
    int x = q.front();
    q.pop();
    for (int child : trans[x])
    {
      if (!visited[child])
      {
        visited[child] = true;
        dist[child] = dist[x] + 1;
        q.push(child);
      }
    }
  }
}

void initialize()
{
  fr(i, 0, 200004)
      dist[i] = INT_MAX;
}

int main()
{
  lli n, m;
  cin >> n >> m;
  initialize();
  fr(i, 0, m)
  {
    lli u, v;
    cin >> u >> v;
    u--, v--;
    // graph[u].pb(v);
    trans[v].pb(u);
  }
  lli k;
  cin >> k;
  fr(i, 0, k)
  {
    int x;
    cin >> x;
    x--;
    path.pb(x);
  }
  bfs(path[k - 1]);

  vector<int> nout(n, 0);
  for (int v = 0; v < n; v++)
  {
    for (int w : trans[v])
    {
      if (dist[w] == dist[v] + 1)
      {
        nout[w]++;
      }
    }
  }

  int minv = 0;
	int maxv = 0;
	for(int i = 0; i + 1 < k; i++){
		if(dist[path[i+1]] != dist[path[i]] - 1) minv++;
		if(dist[path[i+1]] != dist[path[i]] - 1 || nout[path[i]] != 1) maxv++;
	}
	cout << minv << ' ' << maxv << '\n';
  
  }