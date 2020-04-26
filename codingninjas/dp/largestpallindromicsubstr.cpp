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

bool check(int i, int j, int n)
{
  if (i >= 0 && i < n && j >= 0 && j < n)
    return true;
  return false;
}

int main()
{
  string s;
  cin >> s;
  int maxlen;
  maxlen = 0;
  int n = s.length();
  for (int i = 0; i < n; i++)
  {
    // part1 for odd length pallindrome
    int left, right;
    left = i - 1;
    right = i + 1;
    int count = 0;
    while (check(left, right, n))
    {
      if (s[left] == s[right])
      {
        count += 2;
        left--;
        right++;
      }
      else 
      break;
    }
    count++;
    if (count > maxlen)
      maxlen = count;
    
    //part 2 for even length pallindrome
    left = i;
    right = i + 1;
    count = 0;
    while(check(left, right, n))
    {
      if(s[left] == s[right])
      {
        count+=2;
        left--;
        right++;
      }
    }
    if(count > maxlen)
    maxlen = count;
  }
  cout<<maxlen<<endl;
}