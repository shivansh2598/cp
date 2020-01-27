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
        lli a,b;
        cin>>a>>b;
        lli tempa=min(a,b);
        lli tempb=max(a,b);

        lli diff=tempb-tempa;
        if(diff==0)
        {
            cout<<0<<endl;
            continue;
        }

        int i=1;
        while(i*(i+1)<=2*diff)
        {
            i++;
        }

        if(i*(i+1)==2*diff)
        {
            cout<<i<<endl;
            continue;
        }
        i--;

        lli store=i;
        lli tempa1=tempa+(i*(i+1))/2;
        lli tempa2=tempa+((i+1)*(i+2))/2;
        lli diffz=min((tempb-tempa1),(tempa2-tempb));
        cout<<i+(2*diffz)<<endl;
    }
}