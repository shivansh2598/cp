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
        lli n,m;
        cin>>n>>m;
        vector<vector<int>>v;
        for(lli i=0;i<n;i++)
        {
            vector<int>vect;
            for(lli j=0;j<m;j++)
            {
                int x;
                cin>>x;
                vect.push_back(x);
            }

            v.push_back(vect);
        }

        lli count=n*m;

        for(lli i=1;i<n-1;i++)
        {
            for(lli j=1;j<m-1;j++)
            {
                lli len1=0,len2=0;
                int top=i-1;
                int bottom=i+1;
                while(top>=0 && bottom<n)
                {
                    if(v[top][j]==v[bottom][j])
                        len1++;
                    else
                    {
                        break;
                    }
                    top--;
                    bottom++;
                }

                int left=j-1;
                int right=j+1;
                while(left>=0 && right<m)
                {
                    if(v[i][left]==v[i][right])
                        len2++;
                    else
                    {
                        break;
                    }

                    left--;
                    right++;
                }

                int mini=min(len1,len2);
                count+=mini;
            }
        }

        cout<<count<<endl;
    }
}