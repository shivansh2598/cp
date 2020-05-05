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

set<int> vect[200005];
vector<int> A;

bool bfs(int root)
{
  queue<int>q;
  q.push(root);
  int i = 0;
  if(root!=A[i])
  return false;
  else
  {
    i++;
  }
  
  while(!q.empty())
  {
    int temp = q.front();
    q.pop();
    while(!vect[temp].empty())
    {
      int match = A[i];
      if(vect[temp].count(match))
      {
        vect[temp].erase(match);
        vect[match].erase(temp);
        q.push(match);
        i++;
      }
      else
      {
        return false;
      }
    }
    
  }
  return true;
}

int main()
{
  lli n;
  cin >> n;
  fr(i,0,n-1)
  {
    int x,y;
    cin>>x>>y;
    vect[x].insert(y);
    vect[y].insert(x);
  }
  fr(i,0,n)
  {
    int x;
    cin>>x;
    A.push_back(x);
  }
  if(bfs(1))
  cout<<"YES"<<endl;
  else
  {
    cout<<"NO"<<endl;
  }
  
}