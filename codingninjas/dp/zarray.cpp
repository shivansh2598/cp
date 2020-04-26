#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
#define fr(i, k, n) for (lli i = k; i < lli(n); ++i)
#define pb push_back
using namespace std;

void buildz(int z[], string str)
{
  z[0] = 0;
  int right = 0;
  int left = 0;
  int n = str.length();
  for (int i = 1; i < n; i++)
  {
    if (i > right)
    {
      left = i;
      right = i;
      while (right < n && str[right - left] == str[right])
      {
        right++;
      }
      z[i] = right - left;
      right--;
    }
    else
    {
      int k = i - left;
      if (z[k] <= right - i)
      {
        z[i] = z[k];
      }
      else
      {
        left = i;
        while (right < n && str[right] == str[right - left])
        {
          right++;
        }
        z[i] = right - left;
        right--;
      }
    }
  }
}

int main()
{
  string a,b;
  cin>>a>>b;
  string temp = b + '$' + a;
  int length = temp.length();
  int zarray[length];
  fr(i, 0, length) zarray[i] = 0;
  buildz(zarray, temp);
  fr(i, 0, length)
  {
    if (zarray[i] == b.length())
    {
      cout<< i - b.length() - 1 <<endl;
    }
  }
  cout<<-1<<endl;
}
