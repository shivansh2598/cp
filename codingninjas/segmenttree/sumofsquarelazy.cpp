#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
typedef struct data datas;
#define fr(i, k, n) for (lli i = k; i < lli(n); ++i)
#define pb push_back
using namespace std;

void vprint(vector<int>&v)
{  for(int i=0;i<v.size();i++)cout<<v[i]<<' ';cout<<endl;}

void aprint(int *arr,int n)
{  for(int i=0;i<n;i++)cout<<arr[i]<<' ';cout<<endl;}

struct data {
    lli val;
    lli sum;
    lli upd1;
    lli upd2;
    bool isupd1;
    bool isupd2;
};

vector<lli>vect;

datas construct(datas segment[], lli start, lli end, lli i)
{
    if(start==end)
    {
        datas temp;
        temp.val=vect[start]*vect[start];
        temp.sum=vect[start];
        segment[i]=temp;
        return temp;
    }

    lli mid = (start+end)/2;

    datas left = construct(segment, start, mid, 2*i);
    datas right = construct(segment, mid+1, end, 2*i+1);
    datas main;
    main.val = left.val+right.val;
    main.sum= left.sum+right.sum;
    segment[i]=main;
    return main;
}

datas query(datas segment[], lli ql, lli qr, lli start, lli end, lli i)
{
    if(ql==start && qr==end)
    {
        int ttl= end -start +1;
        datas temp = segment[i];
        if(temp.isupd1 | temp.isupd2 == true)
        {
            if(temp.isupd1)
            {
                temp.isupd1=false;
                lli val = temp.upd1;
                temp.upd1=0;
                temp.val += ttl*pow(val, 2) + 2*val*temp.sum;
                temp.sum += ttl * val;
                segment[i]=temp;
                return temp;
            }
            else{
                temp.isupd2=false;
                lli rep = temp.upd2;
                temp.upd2=0;
                temp.val = ttl * pow(rep, 2);
                temp.sum = ttl * rep;
                segment[i]=temp;
                return temp; 
            }
        }
        else
        {
            return segment[i];
        }
    }

    lli mid = (start + end)/2;

    if(qr<=mid)
    {
        return query
    }

}

datas update()
{

}

int main()
{
    lli tc;
    cin>>tc;
    while(tc--)
    { 
        lli n,q;
        cin>>n>>q;
        datas segment[4*n];
        datas temp;
        temp.isupd1=false, temp.isupd2=false, temp.sum=0, temp.upd1=0, temp.upd2=0, temp.val=0;
        fr(i,0,4*n)
        segment[i]=temp;

        construct(segment, 0, n-1 ,1);

        while(q--)
        {
            int x;
            cin>>x;
            if(x==2)
            {
                lli a, b;
                cin>>a>>b;
                cout<<query(segment,a-1,b-1, 0, n-1, 1 )<<endl;
            }
            else if(x==1)
            {
                lli a, b, inc;
                cin>>a>>b>>inc;
            }
            else
            {
                lli a, b, rep;
                cin>>a>>b>>rep;
            }
            
        }

    }
}