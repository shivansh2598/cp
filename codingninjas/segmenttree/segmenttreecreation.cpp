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

int constructsegment(vector<int> &vect, int segment[], int l, int r, int i)
{
    // cout<<l<<" "<<r<<endl;
    if (l == r)
    {
        segment[i] = vect[l];
        return vect[l];
    }

    int mid = (l + r) / 2;

    int a = constructsegment(vect, segment, l, mid, 2 * i);
    int b = constructsegment(vect, segment, mid + 1, r, 2 * i + 1);

    segment[i] = a + b;
    return a + b;
}

int query(int segment[], int ql, int qr, int start, int end, int i)
{
    if(ql>end || qr<start)
    return 0;

    if(ql==start && qr==end)
    return segment[i];

    int mid=(start+end)/2;

    if(ql>mid)
    {
        return query(segment, ql, qr, mid+1, end, 2*i+1);
    }
    else if(qr<=mid)
    {
        return query(segment, ql, qr, start, mid, 2*i);
    }
    else
    {
        int a = query(segment, ql, mid, start, mid, 2*i);
        int b = query(segment, mid+1, qr, mid+1, end, 2*i+1);
        return a+b;
    }

    return 0;
}

vector<int> vect;


void update(int segment[], int ind, int start, int end, int i, int val)
{
    if(start == end){
        segment[i]=val;
        vect[ind]=val;
        return;
    }

    int mid=(start+end)/2;

    if(ind<=mid && ind>=start)
    {
        update(segment, ind, start, mid, 2*i, val);
    }
    else
    {
        update(segment, ind, mid+1, end, 2*i+1, val);
    }
    segment[i]=segment[2*i]+segment[2*i+1];
}

int main()
{
    int n;
    cin >> n;
    int segment[2 * n + 1];

    for(int i=0;i<2*n+1;i++)
    segment[i]=0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vect.pb(x);
    }

    constructsegment(vect, segment, 0, n - 1, 1);

    //query
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << query(segment, l, r, 0, n - 1, 1) << endl;
        }
        else
        {
            int ind,upd;
            cin>>ind>>upd;
            update(segment, ind, 0, n-1, 1, upd);
        }
        
    }
}