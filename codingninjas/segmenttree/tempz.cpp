
#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
#define LIMIT -16000
#define fr(i, k, n) for (lli i = k; i < lli(n); ++i)
#define pb push_back
using namespace std;

vector<lli> vect;

// bhai isme 0 aap nhi daaloge..
// isme minimum value -16000 aayegi
// because agr apne 0 likh diya hai
// to agar negative or 0 num compare hoga to
// to ans 0  ayega apka
// isliye sabki value negative lenge
struct data
{
    lli left = 0;
    lli best = 0;
    lli right = 0;
    lli sum = 0;
};

struct data construct(struct data segment[], lli start, lli end, lli i)
{
    if (start == end)
    {
        struct data temp;
        temp.left = vect[start];
        temp.right = vect[start];
        temp.best = vect[start];
        temp.sum = vect[start];
        segment[i] = temp;
        return temp;
    }

    lli mid = (start + end) / 2;

    struct data left = construct(segment, start, mid, 2 * i);

    struct data right = construct(segment, mid + 1, end, 2 * i + 1);

    struct data front;

    front.left = max(left.left, left.sum + right.left);
    front.right = max(right.right, right.sum + left.right);
    front.sum = left.sum + right.sum;
    front.best = max(left.best, max(right.best, max(left.sum + right.left, max(right.sum + left.right, left.right + right.left))));
    segment[i] = front;
    return front;
}

struct data query(struct data segment[], lli start, lli end, lli ql, lli qr, lli i)
{
    // cout<<start<<" "<<end<<endl;
    if(start > qr || end < ql){
        struct data temp;
        return temp;
    }
    if(start >= ql && end <= qr){
        return segment[i];
    }
    lli mid = (start + end) / 2;
    struct data left = query(segment, start, mid, ql, mid, 2 * i);
    struct data right = query(segment, mid + 1, end, mid + 1, qr, 2 * i + 1);
    struct data front;
    front.left = max(left.left, left.sum + right.left);
    front.right = max(right.right, right.sum + left.right);
    front.sum = left.sum + right.sum;
    front.best = max(left.best, max(right.best, max(left.sum + right.left, max(right.sum + left.right, left.right + right.left))));
    return front;
    
}

int main()
{
    lli n, m;
    cin >> n;
    struct data segment[4 * n];
    struct data temp;
    // temp.left = 0, temp.right = 0, temp.best = 0, temp.sum = 0;
    // fr(i, 0, 4 * n)
    //     segment[i] = temp;

    fr(i, 0, n)
    {
        lli x;
        cin >> x;
        vect.pb(x);
    }
    construct(segment, 0, n - 1, 1);
    cin >> m;

    while (m--)
    {
        lli x, y;
        cin >> x >> y;

        struct data data1 = query(segment, 0, n - 1, x - 1, y - 1, 1);
        cout << data1.best << endl;
    }
}