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

int kadane(vector<int> &vect)
{
    int total = 0, cur = 0;
    bool pos = false;
    fr(i, 0, vect.size())
    {
        if (vect[i] > 0)
        {
            pos = true;
            cur += vect[i];
        }

        else if (vect[i] <= 0 && !pos)
        {
        }

        else
        {
            if (cur > total)
                total = cur;

            cur += vect[i];
            if (cur < 0)
                cur = 0;
        }
    }

    return max(total, cur);
}

int main()
{
    lli n, m;
    cin >> n >> m;
    vector<vector<int>> mat;
    fr(i, 0, n)
    {
        vector<int> temp;
        fr(j, 0, m)
        {
            int x;
            cin >> x;
            temp.pb(x);
        }
        mat.pb(temp);
    }

    vector<int> col;

    lli mx = 0;

    fr(i, 0, m - 1)
    {
        fr(j, 0, n)
        {
            col.pb(mat[j][i]);
        }
        fr(j, i+1, m)
        {
            fr(k, 0, n)
            {
                col[k] += mat[k][j];
            }

            lli k = kadane(col);
            if (k > mx)
                mx = k;
        }

        col.clear();
    }

    cout << mx << endl;
}