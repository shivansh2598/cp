#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

void vprint(vector<int>&v)
{  for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<endl;}

void aprint(int *arr,int n)
{  for(int i=0;i<n;i++)cout<<arr[i]<<' ';cout<<endl;}


int main()
{
    lli t;
    cin>>t;
    for(lli p=0;p<t;p++)
    { 
        lli a, b;
        cin>>a>>b;
        lli sum=a+b;
        lli n=0;
        while(true)
        {  
            sum+=(n*(n+1))/2;
            if(sum%2==0)
            {
                lli temp=sum/2;
                if(temp>=a && temp>=b)
                {
                    break;
                }

            }
            sum-=(n*(n+1))/2;
            n++;
        }

        cout<<n<<endl;
    }
}