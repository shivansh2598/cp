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
        lli arr[]={0,0,1,7,11,71,111,711,1111,7111,11111,71111,111111,711111,1111111,7111111,11111111,71111111,111111111,711111111,771111111,777111111,911111111,971111111,977111111,977711111,991111111,997111111,997711111,997771111,997777111,998111111,998171111,998177111,998211111,998217111,998241111,998241711,998244111,998244171,998244177,998244311,998244317,998244341,998244351,998244351,998244351,998244353};
        lli n;
        cin>>n;
        string temp="";
        lli len=n/2;
        for(lli i=0;i<len;i++)
        {
            temp+="1";
        }

        if(n%2==0)
        cout<<temp<<endl;

        else
        {
            temp[0]='7';
            cout<<temp<<endl;
        }
        
        

    }
}