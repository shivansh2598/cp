#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

string arr[1000000];
long long int sum=0;
long long int m=pow(10,9)+7;
string z;
int substring(string a)
{
    
   
        for(long j=1;j<=a.length();j++)
        {
            for(long k=0;k<=a.length()-j;k++)
            {
                z="";
                for(long l=0;l<j;l++)
                {
                    z+=a[k+l];
                }
                sum=(sum%m+stoull(z)%m)%m;
            }
            
        }

    return sum;
}

int main()
{
    lli t;
    cin>>t;
    for(lli i=0;i<t;i++)
    { 
        string a;
        cin>>a;
        cout<<substring(a)<<endl;
    }
}