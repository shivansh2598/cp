#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ld;
#define fr(i, k, n) for (lli i = k; i < lli(n); ++i)
#define pb push_back
using namespace std;
typedef pair<lli, pair<lli, lli>> p;

lli root[100005];
lli in[100005];
lli low[100005];
vector<lli> myvect[100005];
vector<pair<lli, lli>> vect;

priority_queue<p, vector<p>, greater<p>> pq;

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

unordered_map<pair<lli, lli>, int, hash_pair> um;

void unionz(lli a, lli b)
{
    while (a != root[a])
        a = root[a];
    while (b != root[b])
        b = root[b];
    root[b] = a;
}

lli find(lli a)
{
    while (a != root[a])
        a = root[a];
    return a;
}

bool visited[100005];
lli timer;

void dfs(lli root, lli parent)
{
    visited[root] = true;
    in[root] = low[root] = timer;
    timer++;

    for (lli child : myvect[root])
    {
        if (child == parent)
            continue;

        if (visited[child])
        {
            low[root] = min(in[child], low[root]);
            lli a = min(child, root);
            lli b = max(child, root);
            if (um[{a, b}] != 2)
                um[{a, b}] = 1;
        }
        else
        {
            dfs(child, root);
            lli a = min(child, root);
            lli b = max(child, root);
            // cout<<child<<" "<<root<<endl;
            // cout<<low[child]<<" "<<low[root]<<endl;
            if (low[root] < low[child])
            {
                um[{a, b}] = 2;
            }
            else
            {
                low[root] = min(low[root], low[child]);
                if (um[{a, b}] != 2)
                    um[{a, b}] = 1;
            }
        }
    }
}

int main()
{
    lli n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        lli a, b, w, temp;
        cin >> a >> b >> w;
        temp = min(a, b);
        b = max(a, b);
        a = temp;
        pq.push({w, {a, b}});
        vect.pb({a, b});
    }
    fr(i, 0, n + 1)
    {
        root[i] = i;
    }

    while (!pq.empty())
    {
        p temp = pq.top();
        vector<p> tempz;
        pq.pop();
        tempz.pb(temp);
        while (!pq.empty() && pq.top().first == temp.first)
        {
            tempz.pb(pq.top());
            pq.pop();
        }
        for (int i = 0; i < tempz.size(); i++)
        {
            lli t1 = tempz[i].second.first;
            lli t2 = tempz[i].second.second;
            lli v1 = find(t1);
            lli v2 = find(t2);

            if (tempz.size() == 1)
            {
                if (v1 == v2)
                {
                    um[{t1, t2}] = -1;
                }
                else
                {
                    um[{t1, t2}] = 2;
                }
            }

            else if (v1 == v2)
            {
                um[{t1, t2}] = -1;
            }
        }

        for (int i = 0; i < tempz.size(); i++)
        {
            lli t1 = tempz[i].second.first;
            lli t2 = tempz[i].second.second;
            lli v1 = find(t1);
            lli v2 = find(t2);
            if (um[{t1, t2}] != -1)
                unionz(t1, t2);
        }
    }

    for (int i = 0; i < m; i++)
    {
        pair<lli, lli> temp = vect[i];
        lli a = temp.first;
        lli b = temp.second;
        if (um[{a, b}] != -1)
        {
            cout << a << " " << b << endl;
            myvect[a].pb(b);
            myvect[b].pb(a);
        }
    }
    dfs(1, -1);

    fr(i, 0, m)
    {
        pair<lli, lli> temp = vect[i];
        lli a = temp.first;
        lli b = temp.second;
        if (um[{a, b}] == 1)
        {
            cout << "at least one" << endl;
        }
        else if (um[{a, b}] == 2)
        {
            cout << "any" << endl;
        }
        else
        {
            cout << "none" << endl;
        }
    }
}