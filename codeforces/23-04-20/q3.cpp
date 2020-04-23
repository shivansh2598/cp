#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
#define fr(i, k, n) for (lli i = k; i < lli(n); ++i)
#define pb push_back
using namespace std;

void vprint(vector<int>&v)
{  for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<endl;}

void aprint(int *arr,int n)
{  for(int i=0;i<n;i++)cout<<arr[i]<<' ';cout<<endl;}


int main()
{
    lli tc;
    cin>>tc;
    while(tc--)
    { 
        lli n;
        cin>>n;
        unordered_map<int, pair<int, bool>> mp;
        vector<int>vect;
        fr(i,0,n)
        {
            int x;
            cin>>x;
            vect.pb(x);
            mp.insert({x,{i, false}});
        }

        bool gdbad = false;

        for(int i=1;i<=n;i++)
        {
            pair<int,bool>temp = mp[i];
            
            if(temp.second)
            continue;
            else
            {
                mp[i].second=true;
            }
            
            // cout<<i<<endl;
            for(int j=temp.first+1; j<n; j++)
            {
                if(vect[j]<i)
                break;

                else
                {
                    if(vect[j]<vect[j-1] || vect[j]-vect[j-1]!=1)
                    {
                        gdbad = true;
                        break;
                    }
                    else
                    {
                        mp[vect[j]].second = true;
                    }
                    
                }
                
            }

            if(gdbad)
            break;

        }

        if(gdbad)
        cout<<"No"<<endl;
        else
        {
            cout<<"Yes"<<endl;
        }
        


    }
}