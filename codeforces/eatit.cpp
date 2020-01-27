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
        lli n;
        cin>>n;
        vector<lli>vect;
        lli sum=0;
        bool pos=true;
        bool neg=true;
        for(int k=0;k<n;k++)
        {
            int x;
            cin>>x;
            if(x<=0){
            pos=false;
            }
            if(x>0)
            neg=false;
            sum+=x;
            vect.push_back(x);
        }


        if(neg)
        {
            cout<<"NO"<<endl;
            continue;
        }

        if(pos)
        {
            cout<<"YES"<<endl;
            continue;
        }

       

        // for(int i=1;i<n;i++)
        // vect[i]+=vect[i-1];

        // cout<<sum<<endl;

        // lli abtak=0,curr=0;
        // for(int i=0;i<n;i++)
        // {
        //     if(vect[i]>=0)
        //     {
        //         curr+=vect[i];
        //     }

        //     else
        //     {
        //         if(curr>abtak)
        //         {
        //             abtak=curr;
        //             curr+=vect[i];
        //         }

        //         else
        //         {
        //             curr+=vect[i];
        //         }
                
        //     }
        
        // }
        // lli miz=0,maz=INT_MIN,ab=INT_MIN;
        // bool negative=true;
        // for(int i=n-1;i>=0;i--)
        // {
        //     maz=vect[i];

        // }

        lli mz=0,ab=0;
        bool negi=true;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(vect[i]<=0 && negi)
            continue;

            else if(vect[i]>0 && negi)
            {
                negi=false;
                mz+=vect[i];
                count++;
            }

            else if(vect[i] > 0 && !negi)
            {
                mz+=vect[i];
                count++;
            }

            else
            {
                if(mz>ab)
                ab=mz;

                if(mz+vect[i]<=0)
                mz=0;

                else
                {
                    mz+=vect[i];
                    count++;
                }
                
            }
            
        }

        lli fin=max(mz,ab);
        if(fin==ab)
        count--;

        if(count==n)
        cout<<"YES"<<endl;

        else if(fin>=sum)
        cout<<"NO"<<endl;

        else
        {
            cout<<"YES"<<endl;
        }
        

    }
}