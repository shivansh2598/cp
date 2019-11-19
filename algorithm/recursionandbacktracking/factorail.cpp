#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

lli fact(int n)
{
    if(n<=1)
    return 1;

    else
    {
        return n*fact(n-1);
    }
    
}

int main()
{
    lli t;
    cin>>t;
    for(lli i=0;i<t;i++)
    { 
        int n;
        cin>>n;
        lli z=fact(n);
        cout<<z<<endl;
    }
}