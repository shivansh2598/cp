#include <vector>
#include<bits/stdc++.h>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
    
    pair<bool,int>mark[50005];
    
    for(int i=0;i<50005;i++){
        mark[i].first=false;
        mark[i].second=INT_MAX;
    }
    
    for(int i=0;i<n;i++)
    {
        mark[arr[i]].first=true;
        mark[arr[i]].second=i;
    }
    
    int start=0;
    int maxz=0;
    int curmaxz=0;
    int minz=INT_MAX;
    int fiminz=INT_MAX;
    
    for(int i=0;i<50004;i++)
    {
        if(mark[i].first){
            // if(i==287)
            // cout<<"hurray "<<mark[i].first<<" "<<mark[i].second<<" "<<minz<<endl;
            curmaxz++;
            if(minz==INT_MAX){
                minz=mark[i].second;
                // cout<<"i "<<i<<endl;
                // cout<<"ind "<<mark[i].second<<endl;
            }
        }
        else{
            if(curmaxz>maxz){
                maxz=curmaxz;
                start=i-maxz;
                curmaxz=0;
                fiminz=minz;
                minz=INT_MAX;
            }
            else if(curmaxz==maxz)
            {
                if(minz<fiminz)
                {
                    maxz=curmaxz;
                    start=i-maxz;
                    curmaxz=0;
                    fiminz=minz;
                    minz=INT_MAX;
                }
                else
                {
                    curmaxz=0;
                    minz=INT_MAX;
                }
                
            }
            else{
                curmaxz=0;
                minz=INT_MAX;
            }
        }
    }
    
    vector<int>vect;
    
    for(int i=0;i<maxz;i++)
    {
        vect.push_back(start+i);
    }
    
    return vect;
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int>vect=longestConsecutiveIncreasingSequence(arr,n);
    for(int i=0;i<vect.size();i++)
        cout<<vect[i]<<endl;
}