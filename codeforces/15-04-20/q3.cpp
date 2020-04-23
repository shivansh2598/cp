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

vector<lli> vect[200005];
lli level[200005];
vector<lli> fin;
bool visited[200005];

bool compare(pair<lli,lli>p1, pair<lli,lli>p2)
{
    if(p1.first == p2.first)
    {
        return p1.second>p2.second;
    }

    return p1.first<p2.first;
}

int main()
{
    lli n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        lli a, b;
        cin >> a >> b;
        vect[a].push_back(b);
        vect[b].push_back(a);
    }

    for (int i = 0; i <= n; i++)
    {
        visited[i] = false;
        level[i] = 0;
    }

    queue<int> q;
    visited[1] = true;
    // fin.push_back({0, vect[1].size()});
    q.push(1);

    while(!q.empty())
    {
        lli x = q.front();
        q.pop();
        lli count = 0;
        // fin.push_back({level[x], vect[x].size()});
        // visited[x]=true;
        for (int i = 0; i < vect[x].size(); i++)
        {
            if (!visited[vect[x][i]])
            {
                level[vect[x][i]] = level[x] + 1;
                q.push(vect[x][i]);
                visited[vect[x][i]]=true;
                count++;
            }
        }
        fin.push_back(level[x]-count);
    }

    sort(fin.begin(),fin.end());
    lli len = fin.size()-1;
    lli sum=0;
    for(int i=0;i<k;i++)
    {
        sum+=fin[len-i];
    }
    cout<<sum<<endl;
}