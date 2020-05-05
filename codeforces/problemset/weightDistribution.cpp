#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
#define fr(i, k, n) for (lli i = k; i < lli(n); ++i)
#define pb push_back
using namespace std;
const lli INF = 1e9;

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

vector<lli> vect[200005];

void bfs(lli a, vector<lli> &ds)
{
  ds[a] = 0;
  queue<lli> q;
  q.push(a);
  while (!q.empty())
  {
    lli x = q.front();
    q.pop();
    for (lli child : vect[x])
    {
      if (ds[child] == INF)
      {
        ds[child] = ds[x] + 1;
        q.push(child);
      }
    }
  }
}

int main()
{
  lli tc;
  cin >> tc;
  while (tc--)
  {
    lli n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    a--, b--, c--;
    vector<lli> p;
    
    fr(i, 0, m)
    {
      lli x;
      cin >> x;
      p.pb(x);
    }
    sort(p.begin(), p.end());

    vector<lli> pref(m+1, 0);
    pref.pb(0);

    fr(i, 1, m+1)
        pref[i] = pref[i - 1] + p[i-1];

    fr(i, 0, m)
    {
      lli a, b;
      cin >> a >> b;
      a--,b--;
      vect[a].pb(b);
      vect[b].pb(a);
    }
    vector<lli> da(n, INF), db(n, INF), dc(n, INF);
    bfs(a, da);
    bfs(b, db);
    bfs(c, dc);
    lli minz = 1e16;
    for (int i = 0; i < n; i++)
    {
      if (da[i] + db[i] + dc[i] <= m)
      {
        lli temp = pref[db[i]] + pref[da[i] + db[i] + dc[i]];
        minz = min(minz, temp);
      }
    }
    cout << minz << endl;
    for(int i=0;i<n;i++)
    {
      vect[i].clear();
    }
  }
}