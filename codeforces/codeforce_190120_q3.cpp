#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;

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

lli n, q;

bool isvalid(lli a, lli b)
{
    if ((a > 0 && a < 3) && (b > 0 && b <= n))
        return true;

    return false;
}

struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

int main()
{

    cin >> n >> q;
    unordered_map<pair<lli, lli>, int, hash_pair> m;
    lli count = 0;
    for (lli i = 0; i < q; i++)
    {
        lli x, y;
        cin >> x >> y;
        pair<lli, lli> p = make_pair(x, y);
        if (m.find(p) != m.end())
        {
            lli row = x == 1 ? 2 : 1;
            lli col1 = y;
            lli col2 = y - 1;
            lli col3 = y + 1;

            if (isvalid(row, col1))
            {
                if (m.find(make_pair(row, col1)) != m.end())
                {
                    count -= 2;
                }
            }

            if (isvalid(row, col2))
            {
                if (m.find(make_pair(row, col2)) != m.end())
                {
                    count -= 2;
                }
            }

            if (isvalid(row, col3))
            {
                if (m.find(make_pair(row, col3)) != m.end())
                {
                    count -= 2;
                }
            }

            m.erase(p);
        }
        else
        {
            m.insert({p, 1});
            lli row = x == 1 ? 2 : 1;
            lli col1 = y;
            lli col2 = y - 1;
            lli col3 = y + 1;
            // cout<<row<<" "<<col1<<endl;
            if (isvalid(row, col1))
            {
                if (m.find(make_pair(row, col1)) != m.end())
                {
                    count += 2;
                }
            }

            if (isvalid(row, col2))
            {
                if (m.find(make_pair(row, col2)) != m.end())
                {
                    count += 2;
                }
            }

            if (isvalid(row, col3))
            {
                if (m.find(make_pair(row, col3)) != m.end())
                {
                    count += 2;
                }
            }
        }

        if (count == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}