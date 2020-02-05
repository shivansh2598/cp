#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

void vprint(vector<int>&v)
{  for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<endl;}

void aprint(int *arr,int n)
{  for(int i=0;i<n;i++)cout<<arr[i]<<' ';cout<<endl;}

bool check(string s,string temp)
{
    lli count=0;
    for(lli i=0;i<s.length();i++)
    {
        if(count==temp.length())
        return true;

        else if(s[i]==temp[count])
        count++;
    }

    if(count==temp.length())
    return true;

    return false;
}

lli dp[100009];

lli findz(string s,string t, lli i)
{
    if(i>t.length())
    return LONG_LONG_MAX;

    if(i==t.length())
    return 0;

    if(dp[i]!=-1)
    return dp[i];

    lli minz=LONG_LONG_MAX;
    string temp="";
    for(int j=i;j<t.length();j++)
    {
        temp+=t[j];
        if(check(s,temp))
        {
            lli tempz=findz(s,t,j+1);
            // cout<<temp<<" "<<tempz<<endl;
            if(tempz==LONG_LONG_MAX)
            continue;
            else
            {
                minz=min(minz,1+tempz);
            }
            
        }
    }
    dp[i]=minz;
    return minz;

}

int main()
{
    lli t;
    cin>>t;
    for(lli p=0;p<t;p++)
    { 
        string s,t;
        cin>>s>>t;
        for(int i=0;i<t.length()+5;i++)
        {
            dp[i]=-1;
        }
        lli temp=findz(s,t,0);
        if(temp==LONG_LONG_MAX)
        cout<<-1<<endl;
        else
        {
            cout<<temp<<endl;
        }
        
    }
}