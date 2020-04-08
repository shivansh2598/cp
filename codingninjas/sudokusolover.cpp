#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
#define forn(i, n) for (lli i = 0; i < lli(n); ++i)
#define for1(i, n) for (lli i = 1; i <= lli(n); ++i)
#define fore(i, l, r) for (lli i = lli(l); i <= lli(r); ++i)
#define ford(i, n) for (lli i = lli(n) - 1; i >= 0; --i)
#define pb push_back
#define vectvalue lli x;cin >> x;vect.pb(x)
using namespace std;

void vprint(vector<int>&v)
{  for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<endl;}

void aprint(int *arr,int n)
{  for(int i=0;i<n;i++)cout<<arr[i]<<' ';cout<<endl;}

pair<int,int>findfree(int arr[9][9], int n)
{
    pair<int,int>x=make_pair(-1,-1);
    bool found=false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==0)
            {
                x.first=i;
                x.second=j;
                found=true;
                break;
            }
        }
        if(found)
        break;
    }

    return x;
}

bool check(int arr[9][9],int val,int n,int x,int y){
    
    int a=x%3;
    int b=y%3;

    a=x-a;
    b=y-b;

    for(int i=a;i<a+3;i++)
    {
        for(int j=b;j<b+3;j++)
        {
            if(arr[i][j]==val)
            return false;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(arr[i][y]==val)
        return false;

        if(arr[x][i]==val)
        return false;
    }

    return true;
}

bool solvesudoku(int arr[9][9],int n)
{
    pair<int,int>p=findfree(arr,n);
    if(p.first==-1 && p.second==-1)
    return true;

    for(int i=1;i<=9;i++)
    {
        if(check(arr,i,n,p.first,p.second)){
            arr[p.first][p.second]=i;
            bool y = solvesudoku(arr, n);
            if(y)
            return true;
        }
        arr[p.first][p.second]=0;
    }

    return false;;
}

int main()
{
   int arr[9][9];
   int n=9;
   cout<<"enter the numbers in the sudoku"<<endl;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           cin>>arr[i][j];
       }
   }

   if(solvesudoku(arr,n)){
       cout<<"true"<<endl;
   }
   else
   {
       cout<<"false"<<endl;
   }
   
}