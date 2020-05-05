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

int main()
{
   lli n,k;
   cin>>n>>k;
   vector<int>jststore;
  pair<int,int>freq[k+1];
  fr(i,0,k+1)
  {
    pair<int,int>p = {0,0};
    freq[i]=p;
  }
  fr(i,0,n)
  {
    int x;
    cin>>x;
    jststore.pb(x);
    freq[x].first++;
  }
  sort(jststore.begin(), jststore.end());
  fr(i,1,k+1)
  {
    int x;
    cin>>x;
    freq[i].second = x;
  }

  int minz = INT_MIN;
  int val = n;
  fr(i,1,k+1)
  {
    int temp = ceil(float(val)/freq[i].second);
    minz = max(minz, temp);
    val -= freq[i].first;
  }
  cout<<minz<<endl;
  vector<int>print[minz];
  for(int i=0;i<jststore.size();i++)
  {
    int index = i%minz;
    print[index].pb(jststore[i]);
  }
  for(int i=0;i<minz;i++)
  {
    cout<<print[i].size()<<" ";
    fr(j, 0, print[i].size())
    {
      cout<<print[i][j]<<" ";
    }
    cout<<endl;
  }
}