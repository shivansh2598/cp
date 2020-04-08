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

vector<lli>vect;

lli constructree(lli segment[], lli start, lli end, lli i)
{
    if(start==end)
    {
        segment[i]=vect[start];
        return segment[i];
    }

    lli mid=(start+end)/2;

    lli a = constructree(segment, start, mid, 2*i);
    lli b = constructree(segment,mid+1,end,2*i+1);

    segment[i]=min(a,b);
    return segment[i];
}

void update(lli segment[], lli ind, lli start, lli end, lli i, lli val)
{
    if(start==end)
    {
        vect[ind]=val;
        segment[i]=val;
        return;
    }
    lli mid=(start+end)/2;
    if(ind>=start && ind<=mid)
    {
        update(segment, ind, start, mid, 2*i, val);
    }
    else
    {
        update(segment, ind, mid+1, end, 2*i+1, val);
    }
    segment[i]=min(segment[2*i], segment[2*i+1]);
}

lli query(lli segment[], lli ql, lli qr, lli start, lli end, lli i)
{
    if(start == ql && end == qr)
    return segment[i];

    lli mid=(start+end)/2;

    if(qr<=mid)
    {
        return query(segment, ql, qr, start, mid, 2*i);
    }
    else if(ql>mid)
    return query(segment, ql, qr, mid+1, end, 2*i+1);
    else
    {
        lli a = query(segment, ql, mid, start, mid, 2*i);
        lli b = query(segment, mid+1, qr, mid+1, end, 2*i+1);
        return min(a,b);
    }
    
}

int main()
{
   lli n,q;
   cin>>n>>q;

   lli segment[4*n];

   for(int i=0;i<4*n;i++)
   segment[i]=0;

   fr(i,0,n)
   {
       lli x;
       cin>>x;
       vect.pb(x);
   }
   constructree(segment, 0, n-1, 1);
   while(q--)
   {
       char c;
       cin>>c;
       if(c=='u')
       {
           lli x,y;
           cin>>x>>y;
           update(segment, x-1, 0, n-1, 1, y);

       }
       else
       {
           lli l,r;
           cin>>l>>r;
           cout<<query(segment, l-1, r-1, 0, n-1, 1)<<endl;
       }
   }
   
}