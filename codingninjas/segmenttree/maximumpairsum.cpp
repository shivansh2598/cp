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

pair<lli,lli>merge(pair<lli,lli>p1,pair<lli,lli>p2)
{
    pair<lli,lli>p3;
    if(p1.first>p2.first)
    {
        p3.first=p1.first;
        p3.second=max(p1.second, p2.first);
    }
    else if(p2.first>p1.first)
    {
        p3.first=p2.first;
        p3.second=max(p1.first,p2.second);
    }
    else
    {
        p3.first=p1.first;
        p3.second=p2.first;
    }

    return p3;
    
}

pair<lli,lli>construct(pair<lli,lli>segment[], lli start, lli end, lli ind)
{
    if(start==end)
    {
        pair<lli,lli>p=make_pair(vect[start],-1);
        segment[ind]=p;
        return p;
    }

    lli mid=(start+end)/2;
    pair<lli,lli>p1=construct(segment, start, mid, 2*ind);
    pair<lli, lli>p2=construct(segment, mid+1, end, 2*ind+1);

    pair<lli,lli>p3=merge(p1,p2);
    // pair<lli,lli>p3=make_pair(0,0);
    segment[ind]=p3;
    return p3;

}

pair<lli,lli> query(pair<lli,lli>segment[], lli ql,lli  qr,lli start,lli end,lli ind)
{
    if(start==ql && end==qr)
    return segment[ind];

    lli mid=(start+end)/2;
    if(qr<=mid)
    {
        return query(segment, ql, qr, start, mid, 2*ind);
    }
    else if(ql>mid)
    {
        return query(segment, ql, qr, mid+1, end, 2*ind +1);
    }
    else
    {
        pair<lli,lli>p1=query(segment, ql, mid, start, mid, 2*ind);
        pair<lli,lli>p2=query(segment, mid+1, qr, mid+1, end, 2*ind+1);
        pair<lli,lli>p3=merge(p1,p2);
        return p3;
    }
    

}

void update(pair<lli,lli>segment[], lli ind, lli start, lli end, lli i, lli v)
{
    if(start==end)
    {
        segment[i]=make_pair(v,-1);
        vect[ind]=v;
        return;
    }

    lli mid = (start+end)/2;

    if(ind>=start && ind<=mid)
    {
        update(segment, ind , start, mid, 2*i, v);
    }
    else
    {
        update(segment, ind, mid+1, end, 2*i+1, v);
    }

    pair<lli,lli>p1=segment[2*i];
    pair<lli,lli>p2=segment[2*i+1];
    pair<lli,lli>p3=merge(p1,p2);
    segment[i]=p3;
    return;
}

int main()
{
   lli n;
   cin>>n;
   fr(i,0,n)
   {
       lli x;
       cin>>x;
       vect.pb(x);
   }
   pair<lli,lli> segment[4*n];
   pair<lli,lli>p=make_pair(0,0);
   
   fr(i,0,4*n)
   segment[i]=p;

    construct(segment, 0, n-1, 1);

   lli q;
   cin>>q;
   while(q--)
   {
       char c;
       cin>>c;
       if(c=='Q')
       {
           lli x,y;
           cin>>x>>y;
           pair<lli,lli>p4=query(segment, x-1, y-1, 0, n-1, 1);
           cout<<p4.first+p4.second<<endl;
       }
       else
       {
           lli x,y;
           cin>>x>>y;
           update(segment, x-1, 0, n-1, 1, y);
       }
       
   }
}