#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
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

void update(lli segment[], lli lazy[], lli ql, lli qr, lli start, lli end, lli i, lli val)
{
    if (ql > qr)
        return;

    if (lazy[i] != 0)
    {
        segment[i] += (end - start + 1) * lazy[i];
        if (start != end)
        {
            lazy[2 * i] += lazy[i];
            lazy[2 * i + 1] += lazy[i];
        }
        lazy[i] = 0;
    }

    if (start > qr || end < ql)
        return;

    if (start >= ql && end <= qr)
    {

        segment[i] += (end - start + 1) * val;
        if(start!=end)
        {
            lazy[2*i]+=val;
            lazy[2*i+1]+=val;
        }
        return;
    }
    lli mid = (start + end) / 2;
    update(segment, lazy, ql, qr, start, mid, 2 * i, val);
    update(segment, lazy, ql, qr, mid+1, end, 2*i+1, val);
    segment[i]=segment[2*i]+segment[2*i+1];
    return;
}

lli query(lli segment[],lli lazy[], lli ql , lli qr, lli start, lli end, lli i)
{
    if(ql>qr)
    return 0;

    if (lazy[i] != 0)
    {
        segment[i] += (end - start + 1) * lazy[i];
        if (start != end)
        {
            lazy[2 * i] += lazy[i];
            lazy[2 * i + 1] += lazy[i];
        }
        lazy[i] = 0;
    }

    if(ql>end || qr<start)
    return 0;

    if(start>=ql && end<=qr)
    {
        return segment[i];
    }
    lli mid = (start+end)/2;
    lli a=query(segment, lazy,ql, qr, start, mid, 2*i);
    lli b=query(segment, lazy, ql, qr, mid+1, end, 2*i+1);
    return a+b;
}

int main()
{
    lli tc;
    cin >> tc;
    while (tc--)
    {
        lli n, c;
        cin >> n >> c;
        lli segment[4 * n];
        lli lazy[4 * n];
        fr(i, 0, 4 * n)
        {
            segment[i] = 0;
            lazy[i] = 0;
        }
        while (c--)
        {
            lli x;
            cin >> x;
            if (x == 0)
            {
                lli ql, qr, val;
                cin >> ql >> qr >> val;
                update(segment, lazy, ql - 1, qr - 1, 0, n - 1, 1, val);
            }
            else
            {
                lli ql,qr;
                cin>>ql>>qr;
                cout<<query(segment, lazy, ql-1, qr-1, 0, n-1, 1)<<endl;
            }
        }
    }
}