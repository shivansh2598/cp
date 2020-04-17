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
    lli sum = 0;
};

vector<lli> vect;

datas merge(datas p1, datas p2)
{
    datas p3;
    p3.sum = p1.sum + p2.sum;
    p3.val = p1.val + p2.val;
    return p3;
}

void construct(datas segment[], lli start, lli end, lli i)
{
    if (start == end)
    {
        datas temp;
        temp.val = vect[start] * vect[start];
        temp.sum = vect[start];
        segment[i] = temp;
        return;
    }
    lli mid = (start + end) / 2;
    construct(segment, start, mid, 2 * i);
    construct(segment, mid + 1, end, 2 * i + 1);
    segment[i] = merge(segment[2 * i], segment[2 * i + 1]);
    return;
}

void update(datas segment[], lli lazy1[], lli lazy2[], lli ul, lli ur, lli start, lli end, lli i, lli val, bool upd)
{
    if (ul > ur)
        return;

    if (lazy1[i] != 0)
    {
        datas temp;
        temp.sum = (end - start + 1) * lazy1[i];
        temp.val = (end - start + 1) * (pow(lazy1[i], 2));
        segment[i] = temp;
        if (start != end)
        {
            lazy1[2 * i] = lazy1[i];
            lazy1[2 * i + 1] = lazy1[i];
            lazy2[2 * i] = 0;
            lazy2[2 * i + 1] = 0;
        }
        lazy1[i] = 0;
    }
    if (lazy2[i] != 0)
    {
        datas temp;
        temp.val += (end - start + 1) * (pow(lazy2[i], 2)) + (2 * lazy2[i] * temp.sum);
        temp.sum += (end - start + 1) * lazy2[i];
        segment[i] = temp;
        if (start != end)
        {
            lazy2[2 * i] += lazy2[i];
            lazy2[2 * i + 1] += lazy2[i];
        }
        lazy2[i] = 0;
    }

    if(ul>end || ur<start)
    {
        return;
    }

    if (start >= ul && end <= ur)
    {
        if (upd)
        {
            datas temp;
            temp.sum = (end - start + 1) * val;
            temp.val = (end - start + 1) * (pow(val, 2));
            segment[i] = temp;
            if (start != end)
            {
                lazy1[2 * i] = val;
                lazy1[2 * i + 1] = val;
                lazy2[2 * i] = 0;
                lazy2[2 * i + 1] = 0;
            }
        }
        else
        {
            datas temp = segment[i];
            temp.val += (end - start + 1) * (pow(val, 2)) + (2 * val * temp.sum);
            temp.sum += (end - start + 1) * val;
            segment[i] = temp;
            if (start != end)
            {
                lazy2[2 * i] += val;
                lazy2[2 * i + 1] += val;
            }
        }
        return;
    }

    lli mid = (start+end)/2;
    update(segment, lazy1, lazy2, ul, ur, start, mid, 2*i, val, upd);
    update(segment, lazy1, lazy2, ul, ur, mid+1, end, 2*i+1, val, upd);
    segment[i]=merge(segment[2*i],segment[2*i+1]);
}

datas query(datas segment[], lli lazy1[], lli lazy2[], lli ql, lli qr, lli start, lli end, lli i)
{
    if(ql>qr)
    {
        datas temp;
        return temp;
    }
    if (lazy1[i] != 0)
    {
        datas temp;
        temp.sum = (end - start + 1) * lazy1[i];
        temp.val = (end - start + 1) * (pow(lazy1[i], 2));
        segment[i] = temp;
        if (start != end)
        {
            lazy1[2 * i] = lazy1[i];
            lazy1[2 * i + 1] = lazy1[i];
            lazy2[2 * i] = 0;
            lazy2[2 * i + 1] = 0;
        }
        lazy1[i] = 0;
    }
    if (lazy2[i] != 0)
    {
        datas temp;
        temp.val += (end - start + 1) * (pow(lazy2[i], 2)) + (2 * lazy2[i] * temp.sum);
        temp.sum += (end - start + 1) * lazy2[i];
        segment[i] = temp;
        if (start != end)
        {
            lazy2[2 * i] += lazy2[i];
            lazy2[2 * i + 1] += lazy2[i];
        }
        lazy2[i] = 0;
    }

    if(ql>end || qr<start)
    {
        datas temp;
        return temp;
    }

    if(ql <= start && end <= qr)
    {
        return segment[i];
    }
    lli mid = (start + end)/2;
    datas p1 = query(segment, lazy1, lazy2, ql, qr, start, mid, 2*i);
    datas p2 = query(segment, lazy1,lazy2, ql, qr, mid+1, end, 2*i+1);
    return merge(p1, p2);
}


int main()
{
    lli t;
    cin >> t;
    while (t--)
    {
        lli n, q;
        cin >> n >> q;
        datas segment[4 * n];
        lli lazy1[4 * n]; //swap
        lli lazy2[4 * n]; //add
        datas temp;
        fr(i,0,4*n)
        {
            segment[i]=temp;
            lazy1[i]=0;
            lazy2[i]=0;
        }
        fr(i, 0, n)
        {
            lli x;
            cin>>x;
            vect.pb(x);
        }
        construct(segment, 0, n - 1, 1);
        while (q--)
        {
            lli x;
            cin >> x;
            if (x == 0)
            {
                //set all numbers
                lli ul, ur, val;
                cin >> ul >> ur >> val;
                update(segment, lazy1, lazy2, ul - 1, ur - 1, 0, n - 1, 1, val, true);
            }
            else if (x == 1)
            {
                //add val to all numbers
                lli ul, ur, val;
                cin >> ul >> ur >> val;
                update(segment, lazy1, lazy2, ul - 1, ur - 1, 0, n - 1, 1, val, false);
       
            }
            else
            {
                lli ql, qr;
                cin >> ql >> qr;
                datas temp = query(segment, lazy1, lazy2, ql - 1, qr - 1, 0, n - 1, 1);
                cout << temp.val << endl;
            }
        }

        vect.clear();
    }
}
