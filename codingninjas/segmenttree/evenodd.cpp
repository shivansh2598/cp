#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef struct data datas;
vector<lli>vect;

struct data{
	lli even=0;
    lli odd=0;
};

void construct(datas segment[], lli start, lli end, lli i)
{
    if(start == end)
    {
        if(vect[start]%2==0)
        {
            datas temp;
            temp.even=1;
            segment[i]=temp;
        }
        else
        {
            datas temp;
            temp.odd=1;
            segment[i]=temp;
        }
        return;
    }
    lli mid = (start+end)/2;
    construct(segment, start, mid, 2*i);
    construct(segment, mid+1, end , 2*i+1);
    segment[i].even = segment[2*i].even + segment[2*i+1].even;
    segment[i].odd = segment[2*i].odd + segment[2*i+1].odd;
    return;
}

void update(datas segment[], lli ind, lli start, lli end, lli i, lli val)
{
    if(start==end)
    {
        datas temp;
        if(val%2==0)
            temp.even=1;
        else
            temp.odd=1;
        
        segment[i]=temp;
        vect[start]=val;
        return;
    }
    
    lli mid = (start+end)/2;
    if(ind<=mid)
    update(segment, ind, start, mid, 2*i, val);
    else
        update(segment, ind, mid+1, end, 2*i+1,val);
    segment[i].even = segment[2*i].even + segment[2*i+1].even;
    segment[i].odd = segment[2*i].odd + segment[2*i+1].odd;
    return;
    
}

datas query(datas segment[],lli ql, lli qr, lli start, lli end, lli i)
{
    if(ql>end || qr<start)
    {
        datas temp;
        return temp;
    }
    
    else if(ql<=start && end<= qr)
        return segment[i];
    
    lli mid = (start+end)/2;
    datas left = query(segment, ql, qr, start, mid, 2*i);
    datas right = query(segment, ql, qr, mid+1, end, 2*i+1);
    datas temp;
    temp.odd = left.odd + right.odd;
    temp.even = right.even+left.even;
    return temp;
}

int main() {
	lli n;
    cin>>n;
    datas segment[4*n];
    for(lli i=0;i<n;i++)
    {
        lli x;
        cin>>x;
        vect.push_back(x);
    }
    construct(segment, 0, n-1, 1);
    lli q;
    cin>>q;
    while(q--)
    {
        int ty;
        cin>>ty;
        if(ty==0)
        {
            lli x,y;
            cin>>x>>y;
            update(segment, x-1, 0, n-1, 1, y);
        }
        else{
            lli x,y;
            cin>>x>>y;
            datas temp=query(segment, x-1, y-1, 0, n-1, 1);
            if(ty==1)
            {
                cout<<temp.even<<endl;
            }
            else
                cout<<temp.odd<<endl;
        }
    }
}