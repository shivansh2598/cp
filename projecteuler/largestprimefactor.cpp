#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

void vprint(vector<int>&v)
{  for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<endl;}

void aprint(int *arr,int n)
{  for(int i=0;i<n;i++)cout<<arr[i]<<' ';cout<<endl;}

bool checkprime(lli n)
{
    for(int i=2;i<=sqrt(n)+1;i++)
    {
        if(n%i==0)
        return false;
    }

    return true;
}

int main()
{
    lli t;
    cin>>t;
    for(lli i=0;i<t;i++)
    { 
        lli n;
        cin>>n;
        lli result=0;

        for(int j=2;j<=sqrt(n)+1;j++)
        {
            if(n%j==0)
            {
                lli x=j;
                lli y=n/j;

                if(checkprime(x) && x>result)
                result=x;

                if(checkprime(y) && y>result)
                result=y;

            }
        }

        cout<<result<<endl;
    }
}