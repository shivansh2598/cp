#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

bool modify(vector<vector<int>>&v)
{
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            v[i][j]=1;
        }
    }

    return true;
}

int main()
{
    lli t;
    cin>>t;
    for(lli k=0;k<t;k++)
    { 
        int size;
        cin>>size;

        vector<vector<int>>v;
        for(int i=0;i<size;i++)
        {
            vector<int>temp;
            for(int j=0;j<size;j++)
            {
                temp.push_back(0);
            }
            v.push_back(temp);
        }

        if(modify(v))
        {
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                {
                    cout<<v[i][j]<<" ";
                }

                cout<<endl;
            }
        }
    }
}