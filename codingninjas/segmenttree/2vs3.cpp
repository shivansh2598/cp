#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
typedef struct data datas;
#define fr(i, k, n) for (lli i = k; i < lli(n); ++i)
#define pb push_back
using namespace std;

void vprint(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;
}

void aprint(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

struct data
{
    lli val = 0;
    lli one = 0;
    lli len = 0;
};

vector<lli> vect;

datas merge(datas p1, datas p2)
{
    datas p3;
    p3.len = p2.len + p1.len;
    p3.one = p1.one + p2.one;
    p3.val = (p1.val << p2.len) + p2.val;
    return p3;
}

void construct(datas segment[], lli start, lli end, lli i)
{
    if (start == end)
    {
        datas p;
        if (vect[start] == 0)
        {
            p.len = 1;
            p.one = 0;
            p.val = 0;
        }
        else
        {
            p.len = 1;
            p.one = 1;
            p.val = 1;
        }
        segment[i] = p;
        return;
    }

    lli mid = (start + end) / 2;
    construct(segment, start, mid, 2 * i);
    construct(segment, mid + 1, end, 2 * i + 1);
    datas p = merge(segment[2 * i], segment[2 * i + 1]);
    segment[i] = p;
    return;
}

datas query(datas segment[], lli ql, lli qr, lli start, lli end, lli i)
{
    if(start>qr || end <ql)
    {
        datas temp;
        return temp;
    }

    if(ql<=start && end<=qr)
    return segment[i];

    lli mid = (start+end)/2;
    datas p1 = query(segment, ql, qr, start, mid, 2*i);
    datas p2 = query(segment, ql, qr, mid+1, end, 2*i+1);
    return merge(p1,p2);
}

void update(datas segment[], lli ind, lli start, lli end, lli i)
{
    if(start == end)
    {
        if(segment[i].one == 0)
        {
            segment[i].one = 1;
            segment[i].val = 1;
        }
        return;
    }

    lli mid = (start+end)/2;
    if(ind<=mid)
    {
        update(segment, ind, start, mid, 2*i);
    }
    else
    {
        update(segment, ind, mid+1, end, 2*i+1);
    }

    segment[i]=merge(segment[2*i],segment[2*i+1]);
    return ;
    
}

int main()
{
    lli n;
    cin >> n;
    string s;
    cin >> s;
    datas segment[4 * n];
    fr(i, 0, n)
    {
        lli x = s[i] - '0';
        vect.pb(x);
    }
    construct(segment, 0, n - 1, 1);
    lli q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            lli x, y;
            cin>>x>>y;
            datas temp = query(segment, x, y, 0, n-1, 1);
            temp.val = temp.val % 3;
            cout<<temp.val<<endl;
        }
        else
        {
            lli x;
            cin>>x;
            update(segment, x, 0, n-1, 1);
        }
        
    }
}