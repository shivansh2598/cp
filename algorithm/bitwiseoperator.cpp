#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

int main()
{
    lli t;
    cin>>t;
    for(lli i=0;i<t;i++)
    { 
        char a;
        cin>>a;
        a&=~' ';
        cout<<a<<endl;
    }
}