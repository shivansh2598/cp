#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define for1(i, n) for (int i = 1; i <= int(n); ++i)
#define fore(i, l, r) for (int i = int(l); i <= int(r); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define pb push_back
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

lli n, m;
unordered_map<pair<int, int>, bool, hash_pair> points, pps;

bool check(lli x, lli y)
{
    if ((x >= 1 && x <= n) && (y >= 1 && y <= m))
        return true;

    return false;
}

lli bfs(pair<int, int> p)
{
    queue<pair<int, int>> q;
    q.push(p);
    points[p] = true;
    lli count = 0;
    while (!q.empty())
    {
        pair<int, int> ss = q.front();
        q.pop();
        int i = ss.first;
        int j = ss.second;
        if (check(i - 1, j - 1))
        {
            if (pps.find(make_pair(i - 1, j - 1)) != pps.end())
                pps[make_pair(i - 1, j - 1)] = true;

            else if (points.find(make_pair(i - 1, j - 1)) != points.end() && !points[make_pair(i - 1, j - 1)])
            {
                q.push(make_pair(i - 1, j - 1));
                points[make_pair(i - 1, j - 1)] = true;
                count++;
            }
        }
        if (check(i, j - 1))
        {
            if (pps.find(make_pair(i, j - 1)) != pps.end())
                pps[make_pair(i, j - 1)] = true;

            else if (points.find(make_pair(i, j - 1)) != points.end() && !points[make_pair(i, j - 1)])
            {
                q.push(make_pair(i, j - 1));
                points[make_pair(i, j - 1)] = true;
                count++;
            }
        }
        if (check(i + 1, j - 1) && points.find(make_pair(i + 1, j - 1)) != points.end() && !points[make_pair(i + 1, j - 1)])
        {
            if (pps.find(make_pair(i + 1, j - 1)) != pps.end())
                pps[make_pair(i + 1, j - 1)] = true;

            q.push(make_pair(i + 1, j - 1));
            points[make_pair(i + 1, j - 1)] = true;
            count++;
        }
        if (check(i - 1, j))
        {
            if (pps.find(make_pair(i - 1, j)) != pps.end())
                pps[make_pair(i - 1, j)] = true;
            else if (points.find(make_pair(i - 1, j)) != points.end() && !points[make_pair(i - 1, j)])
            {
                q.push(make_pair(i - 1, j));
                points[make_pair(i - 1, j)] = true;
                count++;
            }
        }
        if (check(i - 1, j + 1))
        {
            if (pps.find(make_pair(i - 1, j + 1)) != pps.end())
                pps[make_pair(i - 1, j + 1)] = true;
            else if (points.find(make_pair(i - 1, j + 1)) != points.end() && !points[make_pair(i - 1, j + 1)])
            {
                q.push(make_pair(i - 1, j + 1));
                points[make_pair(i - 1, j + 1)] = true;
                count++;
            }
        }
        if (check(i, j + 1))
        {
            if (pps.find(make_pair(i, j + 1)) != pps.end())
                pps[make_pair(i, j + 1)] = true;
            else if (points.find(make_pair(i, j + 1)) != points.end() && !points[make_pair(i, j + 1)])
            {
                q.push(make_pair(i, j + 1));
                points[make_pair(i, j + 1)] = true;
                count++;
            }
        }
        if (check(i + 1, j + 1))
        {
            if (pps.find(make_pair(i + 1, j + 1)) != pps.end())
                pps[make_pair(i + 1, j + 1)] = true;
            else if (points.find(make_pair(i + 1, j + 1)) != points.end() && !points[make_pair(i + 1, j + 1)])
            {
                q.push(make_pair(i + 1, j + 1));
                points[make_pair(i + 1, j + 1)] = true;
                count++;
            }
        }
        if (check(i + 1, j))
        {
            if (pps.find(make_pair(i + 1, j)) != pps.end())
                pps[make_pair(i + 1, j)] = true;

            else if (points.find(make_pair(i + 1, j)) != points.end() && !points[make_pair(i + 1, j)])
            {
                q.push(make_pair(i + 1, j));
                points[make_pair(i + 1, j)] = true;
                count++;
            }
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vector<pair<int, int>> vect;
    for1(i, n)
    {
        for1(j, m)
        {
            char x;
            cin >> x;
            if (x == '#')
            {
                pair<int, int> p;
                p = make_pair(i, j);
                pps.insert({p, false});
                vect.pb(p);
            }
        }
    }

    for (int w = 0; w < vect.size(); w++)
    {
        int i = vect[w].first;
        int j = vect[w].second;
        if (check(i - 1, j - 1) && pps.find(make_pair(i - 1, j - 1)) == pps.end())
        {
            pair<int, int> p = make_pair(i - 1, j - 1);
            points.insert({p, false});
        }
        if (check(i, j - 1) && pps.find(make_pair(i, j - 1)) == pps.end())
        {
            pair<int, int> p = make_pair(i, j - 1);
            points.insert({p, false});
        }
        if (check(i + 1, j - 1) && pps.find(make_pair(i + 1, j - 1)) == pps.end())
        {

            pair<int, int> p = make_pair(i + 1, j - 1);
            points.insert({p, false});
        }
        if (check(i - 1, j) && pps.find(make_pair(i - 1, j)) == pps.end())
        {
            pair<int, int> p = make_pair(i - 1, j);
            points.insert({p, false});
        }
        if (check(i - 1, j + 1) && pps.find(make_pair(i - 1, j + 1)) == pps.end())
        {

            pair<int, int> p = make_pair(i - 1, j + 1);
            points.insert({p, false});
        }
        if (check(i, j + 1) && pps.find(make_pair(i, j + 1)) == pps.end())
        {
            pair<int, int> p = make_pair(i, j + 1);
            points.insert({p, false});
        }
        if (check(i + 1, j + 1) && pps.find(make_pair(i + 1, j + 1)) == pps.end())
        {

            pair<int, int> p = make_pair(i + 1, j + 1);
            points.insert({p, false});
        }
        if (check(i + 1, j) && pps.find(make_pair(i + 1, j)) == pps.end())
        {

            pair<int, int> p = make_pair(i + 1, j);
            points.insert({p, false});
        }
    }
    lli maxz = 0;
    forn(i, vect.size())
    {
        if (!pps[vect[i]])
        {
            lli curr = bfs(vect[i]);
            if (curr > maxz)
                maxz = curr;
        }
    }
    cout << maxz << endl;
}