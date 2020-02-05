#include<bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define for1(i, n) for (int i = 1; i <= int(n); ++i)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define ford(i, n) for (int i = int(n)-1; i >= 0; --i)
#define pb push_back
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

void vprint(vector<int>&v)
{  for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<endl;}

void aprint(int *arr,int n)
{  for(int i=0;i<n;i++)cout<<arr[i]<<' ';cout<<endl;}

lli tree[1000000];
vector<lli>A;

void construct(lli node,lli start,lli end){
    if(start==end){
        tree[node]=A[start];
    }else{
        lli mid=(end+start)/2;
        construct(2*node,start,mid);
        construct(2*node+1,mid+1,end);
        tree[node]=min(tree[2*node+1],tree[2*node]);
    }
}

void update(lli node,lli start, lli end,lli indx,lli val){
    if(start==end){
        A[indx]=val;
        tree[node]=A[start];
    }else{
        lli mid=(start+end)/2;
        if(indx>=start && indx<=mid){
            update(2*node,start,mid,indx,val);
        }else if(indx>mid && indx<=end){
            update(2*node+1,mid+1,end,indx,val);
        }
        tree[node]=min(tree[2*node+1],tree[2*node]);
    }
}

lli query(lli node, lli start, lli end, lli l, lli r){
    if(r<start || l>end)
        return INT_MAX;
    if(start>=l && end<=r)
        return tree[node];
    else
    {
        lli mid=(start+end)/2;
        lli p1=query(2*node,start,mid,l,r);
        lli p2=query(2*node+1,mid+1,end,l,r);
        return min(p1,p2);
    }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   lli n,q;
   cin>>n>>q;
   forn(i,n){
       lli x;
       cin>>x;
       A.pb(x);
   }
   forn(i,(2*n+5)){
       tree[i]=0;
   }
   construct(1,0,n-1);
   forn(i,q){
       char b;
       cin>>b;
       lli x,y;
       cin>>x>>y;
       if(b=='q'){
           cout<<query(1,0,n-1,x-1,y-1)<<endl;
       }else{
           update(1,0,n-1,x-1,y);
       }

   }
}