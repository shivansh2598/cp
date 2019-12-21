#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

bool ispallindromic(string s,int start,int end)
{
    while(start<end)
    {
        if(s[start]!=s[end])
        return false;

        start++;
        end--;
    }

    return true;
}

void findallpallindrome(string s , int &maxlen,int start,int end)
{   
    if(start>=end)
    {
        // allpart.push_back(curr);
        return;
    }

    for(int i=start;i<end;i++)
    {
        if(ispallindromic(s,start,i))
        {
            // curr.push_back(s.substr(start,i+1-start));
            if(i+1-start>maxlen)
            maxlen=i+1-start;
            
            findallpallindrome(s,maxlen,i+1,end);
            // curr.pop_back();
        }
    }
}

void pallindrome(string s)
{
    // vector<vector<string>>allpart;
    // vector<string>curr;
    int maxlen=0;
    findallpallindrome(s,maxlen,0,s.length());
    // for(int i=0;i<allpart.size();i++)
    // {
    //     for(int j=0;j<allpart[i].size();j++)
    //     {
    //         cout<<allpart[i][j]<<" ";
    //     }

    //     cout<<endl;
    // }
    cout<<maxlen<<endl;
}

int main()
{
    // lli t;
    // cin>>t;
    // for(lli i=0;i<t;i++)
    // { 
        // cout<<"enter a string"<<endl;
        string s;
        cin>>s;
        pallindrome(s);
    // }
}